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
cd docroot
drush si -y prc_profile
drush fra -y --force
drush mi --group=prc_taxonomy
drush mi --group=prc_standard --limit="100 items"
drush vocimp ../terms/lr_subjects_hier.csv tree --vocabulary_target=existing --vocabulary_id=10
drush php-eval 'node_access_rebuild();'
