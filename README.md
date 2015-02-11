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

Now set your admin password and log in...
drush upwd admin --password="yourpassword"
or...
drush uli

