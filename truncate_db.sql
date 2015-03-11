#!/bin/bash
mysqldump -u$1 -p$2 --add-drop-table --no-data $3 | grep ^DROP | mysql -u$1 -p$2 $3

