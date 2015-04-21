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

