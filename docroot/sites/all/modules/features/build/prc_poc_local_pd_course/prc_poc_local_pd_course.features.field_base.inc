<?php
/**
 * @file
 * prc_poc_local_pd_course.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function prc_poc_local_pd_course_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_audience'
  $field_bases['field_audience'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_audience',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'all' => 'All PARCC Members',
        'state' => 'Select By State',
        'roster' => 'Select By Rostering',
      ),
      'allowed_values_function' => '',
      'course_enrollment' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
