cd docroot
drush si -y prc_profile
drush en -y prc_poc_local_search_api
drush mi --group=prc_taxonomy
drush mi --group=prc_standard --limit="100 items"
drush vocimp ../terms/lr_subjects_hier.csv tree --vocabulary_target=existing --vocabulary_id=subject
drush mi --group=prc_content
# If you have problems with this next command make sure the db user has the appropriate permissions
# Check the read me for information on creating the crit-tables file
drush sql-cli < ../crit-tables.sql
drush fra -y --force
drush php-eval 'node_access_rebuild();'
drush cc all
# drush pftr
