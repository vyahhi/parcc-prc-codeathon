#!/bin/sh
# This script drops and creates database and user.
# Usage ./db.sh dbname=name user=user pwd=password mysqlrootpwd=password host=host
# dbname is database name
# user is database user
# pwd is database user password
# mysqlrootpwd is password for root user on MySQL
# host is host connecting to database

LOGFILE=db.sh.log
echo `date` >$LOGFILE
DBNAME=
MYSQLROOTPWD=
USER=
PWD=
HOST=

log() {
	COLOR=
	if [ $# -gt 1 ];then
		case "$2" in
			error)
				COLOR="31"
				;;

			warn)
				COLOR="33"
				;;
					
			ok)
				COLOR="32"
				;;
		esac
	fi

	local MSG=
	if [ -z "$COLOR" ];then
		MSG="$1"
	else
		MSG="\\E[0;""$COLOR""m""$1""\\E[0m"
	fi

	echo -e "$MSG" | tee -a "$LOGFILE"
}

if [ $# -gt 0 ];then
	for (( i=1; i<=$#; i++ ));do
		IFS='=' read -ra ARR <<< "${@:i:1}"
		case "${ARR[0]}" in
			dbname)
				DBNAME="${ARR[1]}"
				;;

			user)
				USER="${ARR[1]}"
				;;

			pwd)
				PWD="${ARR[1]}"
				;;

			mysqlrootpwd)
				MYSQLROOTPWD="${ARR[1]}"
				;;
				
			host)
				HOST="${ARR[1]}"
				;;
		esac
	done
fi

if [ -z "$DBNAME" ];then
	log "Database name is required." error
	exit 1
fi

if [ -z "$USER" ];then
	log "Database user name is required." error
	exit 1
fi

if [ -z "$PWD" ];then
	log "Database user password is required." error
	exit 1
fi

if [ -z "$MYSQLROOTPWD" ];then
	log "MySQL root password is required." error
	exit 1
fi

if [ -z "$HOST" ];then
	log "Host is required." error
	exit 1
fi

execcmd() {
	log "$1"
	local ERR=$((eval $1 >>$LOGFILE) 2>&1)
	if [ $? -gt 0 ];then
		log "$ERR" error
		exit 1
	fi
}

dbexists() {
	local RESULT=$($MYSQL "SELECT SCHEMA_NAME FROM INFORMATION_SCHEMA.SCHEMATA WHERE SCHEMA_NAME = '$DBNAME'")
	if [ -z "$RESULT" ];then
		echo false
	else
		echo true
	fi
}

dbuserexists() {
	local RESULT=$($MYSQL "SELECT User FROM mysql.user WHERE User='$USER' AND Host='$HOST'")
	if [ -z "$RESULT" ];then
		echo false
	else
		echo true
	fi
}

MYSQL="mysql -u root -p$MYSQLROOTPWD -s -N -e"
log "Begin drop database"
RESULT=$(dbexists)
if [ "$RESULT" = true ];then
	PROCESSLIST=`$MYSQL 'SELECT Id FROM INFORMATION_SCHEMA.PROCESSLIST'`
	for PROCESS in ${PROCESSLIST[@]};do
		execcmd "$MYSQL 'KILL $PROCESS'"
	done
	
	execcmd "$MYSQL 'DROP DATABASE $DBNAME'"
	RESULT=$(dbexists)
	if [ "$RESULT" = true ];then
		log "Failed to drop database $DBNAME." error
		exit 1
	else
		log "Database $DBNAME dropped!" ok
	fi
else
	log "Database $DBNAME not found. Nothing to drop!" warn
fi
log "End drop database"

log "Begin drop user"
RESULT=$(dbuserexists)
if [ "$RESULT" = true ];then
	execcmd "$MYSQL 'DROP USER '\\''$USER'\\''@'\\''$HOST'\\'"
	RESULT=$(dbuserexists)
	if [ "$RESULT" = true ];then
		log "Failed to drop user $USER@$HOST." error
		exit 1
	else
		log "Database user $USER@$HOST dropped!" ok
	fi
else
	log "Database user $USER@$HOST not found. Nothing to drop!" warn
fi
log "End drop user"

log "Begin create database"
RESULT=$(dbexists)
if [ "$RESULT" = true ];then
	log "Not expected to find database $DBNAME." error
	exit 1
else
	execcmd "$MYSQL 'CREATE DATABASE $DBNAME'"
	RESULT=$(dbexists)
	if [ "$RESULT" = true ];then
		log "Database $DBNAME created!" ok
	else
		log "Failed to create database $DBNAME." error
		exit 1
	fi
fi
log "End create database"

log "Begin create user"
RESULT=$(dbuserexists)
if [ "$RESULT" = true ];then
	log "Not expected to find database user $USER@$HOST." error
	exit 1
else
	execcmd "$MYSQL 'CREATE USER '\\''$USER'\\''@'\\''$HOST'\\'"
	execcmd "$MYSQL 'SET PASSWORD FOR '\\''$USER'\''@'\\''$HOST'\\'' = PASSWORD('\\''$PWD'\\'')'"
	RESULT=$(dbuserexists)
	if [ "$RESULT" = true ];then
		log "Database user $USER@$HOST created!" ok
	else
		log "Failed to create user $USER@$HOST." error
		exit 1
	fi
fi
log "End create user"

log "Begin grant permissions"
execcmd "$MYSQL 'GRANT ALL ON $DBNAME.* TO '\\''$USER'\\''@'\\''$HOST'\\'"
log "Granted permissions for $USER@$HOST on $DBNAME!" ok
log "End grant permissions"

log "Complete!" ok
exit 0