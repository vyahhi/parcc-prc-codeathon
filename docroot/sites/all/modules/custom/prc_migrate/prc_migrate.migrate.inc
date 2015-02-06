<?php
/**
 * @file
 * Migrate API
 */

/**
 * Implements hook_migrate_api().
 */
function prc_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'prc_taxonomy' => array(
        'title' => t('Migrate Taxonomy Terms'),
      ),
    ),
    'migrations' => array(
      'PrcCsvGenre' => array(
        'class_name' => 'PrcCsvGenreMigration',
        'group_name' => 'prc_taxonomy',
      ),
      'PrcCsvGradeLevel' => array(
        'class_name' => 'PrcCsvGradeLevelMigration',
        'group_name' => 'prc_taxonomy',
      ),
      'PrcCsvMediaType' => array(
        'class_name' => 'PrcCsvMediaTypeMigration',
        'group_name' => 'prc_taxonomy',
      ),
      'PrcCsvQuizType' => array(
        'class_name' => 'PrcCsvQuizTypeMigration',
        'group_name' => 'prc_taxonomy',
      ),
    ),

  );
  return $api;
}
