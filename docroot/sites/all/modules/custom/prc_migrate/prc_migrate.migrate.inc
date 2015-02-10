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
        'class_name' => 'PrcCsvSimpleTaxonomyMigration',
        'group_name' => 'prc_taxonomy',
        'vocab_name' => 'genre',
      ),
      'PrcCsvGradeLevel' => array(
        'class_name' => 'PrcCsvSimpleTaxonomyMigration',
        'group_name' => 'prc_taxonomy',
        'vocab_name' => 'grade_level',
      ),
      'PrcCsvMediaType' => array(
        'class_name' => 'PrcCsvSimpleTaxonomyMigration',
        'group_name' => 'prc_taxonomy',
        'vocab_name' => 'media_type',
      ),
      'PrcCsvQuizType' => array(
        'class_name' => 'PrcCsvSimpleTaxonomyMigration',
        'group_name' => 'prc_taxonomy',
        'vocab_name' => 'quiz_type',
      ),
      'PrcCsvMemberState' => array(
        'class_name' => 'PrcCsvMemberStateMigration',
        'group_name' => 'prc_taxonomy',
      ),
    ),

  );
  return $api;
}
