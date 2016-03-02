cd docroot
drush si -y prc_profile
drush fra -y --force
drush en -y prc_poc_local_search_api
drush mi --group=prc_taxonomy
drush mi --group=prc_standard --limit="100 items"
drush vocimp ../terms/lr_subjects_hier.csv tree --vocabulary_target=existing --vocabulary_id=subject
drush mi --group=prc_content
drush php-eval 'node_access_rebuild();'
# drush pftr
