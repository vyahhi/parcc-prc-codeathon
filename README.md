PARCC-PRC
=========

PARCC Partnership Resource Center

Installation
============
cd docroot
drush si -y prc
drush fra -y --force
drush mi —-all
drush php-eval 'node_access_rebuild();'
drush vocimp ../terms/lr_subjects_hier.csv tree --vocabulary_target=existing --vocabulary_id=10
drush vocimp ../terms/lr_standards_by_id_hier.csv tree --vocabulary_target=existing --vocabulary_id=9
drush vocimp ../terms/lr_standards_fields.csv fields --fields_format=name,description --vocabulary_target=existing --vocabulary_id=9

Now get your admin password and log in:
drush uli

