<?php
/**
 * @file
 * Migrate API
 */

/**
 * Implements hook_migrate_api().
 */
function prc_migrate_migrate_api() {

  $common_arguments = array(
    'source_connection' => 'prc_to_prc',
    'source_version' => 7,
    'group_name' => 'prc_to_prc',
  );

  $api = array(
    'api' => 2,
    'groups' => array(
      'prc_taxonomy' => array(
        'title' => t('Migrate Taxonomy Terms'),
      ),
      'prc_standard' => array(
        'title' => t('Migrate Standards Terms'),
      ),
      'prc_content' => array(
        'title' => t('Migrate Content'),
      ),
      'prc_to_prc' => array(
        'title' => t('Migrate from another PRC'),
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
      'PrcCsvUserStates' => array(
        'class_name' => 'PrcCsvUserStatesMigration',
        'group_name' => 'prc_taxonomy',
      ),
      'PrcJsonStandardMigration' => array(
        'class_name' => 'PrcJsonStandardMigration',
        'group_name' => 'prc_standard',
      ),
      'PrcCsvPage' => array(
        'class_name' => 'PrcCsvPageMigration',
        'group_name' => 'prc_content',
      ),
      'PrcCsvPdCourseMigration' => array(
        'class_name' => 'PrcCsvPdCourseMigration',
        'group_name' => 'prc_content',
      ),
      'PrcToPrcUser' => $common_arguments + array(
          'description' => t('Migration of users from another PRC'),
          'class_name' => 'DrupalUser7Migration',
      ),
    ),

  );
  return $api;
}
