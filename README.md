PARCC-PRC
=========

PARCC Partnership Resource Center

Installation
============

cd docroot
drush si -y prc_profile
drush fra -y --force
drush mi —-all
drush vocimp ../terms/lr_subjects_hier.csv tree --vocabulary_target=existing --vocabulary_id=10
drush php-eval 'node_access_rebuild();'

Now set your admin password and log in...
drush upwd admin --password="yourpassword"
or...
drush uli

Development Installation
========================

For a development instance, the longer Standards migration can be shortened.
Execute ./dev_setup.sh
Then set an admin password: drush upwd admin --password=admin

Additional Software Requirements
================================

You'll need:
- Composer
- Selenium Server (downloaded here: http://www.seleniumhq.org/download/ )
- Firefox 34 (As of this writing, FF35 does not work correctly with Selenium).
    Turn off automatic updates, otherwise FF will upgrade itself when you start it back up.
- PHP 5.5
- drush

Server Permissions for Tika Execution
=====================================

To ensure that Apache can execute Tika, run the following:
setsebool -P httpd_execmem 1
setsebool -P allow_httpd_mod_auth_pam 1

grant sudo access to sys_ptrace
grant sudo access to netlink_audit_s

Server Permissions for Sending Email
====================================
setsebool –P httpd_can_sendmail 1

When Terms Change
=================

When taxnomy terms change, check the following:

  - Content type: Assessment
    Field: Assessment Type
    Default Value: Custom Assessment

  - Assessments view
    Terms allowed:
      Custom Assessment
      PARCC-Released Practice Assessment

SSO Local Config
====================

Get a PRC instance running locally at http://parcc-prc.dd:8083 (annoying, I know - more info in the comments in config/settings_local.inc)

Copy the 'Enable environment specific integrations settings file' block from default.settings.php and add to your local settings.php

With SSO enabled, you can bypass SSO login using the following path: /user/local-login

SSO Link URL Changes
====================

In the file:
/var/www/simplesamlphp/modules/themeparcc/themes/parcc/core/loginuserpass.php

Change lines 65 and 66 to point the hrefs to the right base PRC url.

REST User For Automated Testing
===============================
The prc_adp module creates a user that is used by behat tests for validating REST functionality.  In order to take
advantage of this, the following line needs to be added to the settings.php file:

    $conf['adp_user_default_pass'] = 'password';

You may change 'password' to whatever you wish.  Also make sure the value in settings.php is the same as for the
behat.yml custom parameter.

Syncing Critical Tables With Production
=======================================
The dev_setup.sh script will require a file called crit-tables.sql.  To create this file, download a copy of the production
database, import into mysql (in the example that follows we use a database called prc_prod), and run the following command
in the PRC repository root directory to export the sql file.

    sudo mysqldump prc_prod role taxonomy_term_data taxonomy_term_hierarchy taxonomy_vocabulary > crit-tables.sql

By doing this we can be sure that references in features to terms and roles will match production.  It is recommended
that the crit-tables.sql file be re-created whenever roles or terms referenced by features are added to production.
