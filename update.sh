cd docroot
drush fra -y --force
drush php-eval 'node_access_rebuild();'
