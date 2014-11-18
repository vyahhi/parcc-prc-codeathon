<?php
/**
 * @file
 * prc_poc_local_taxonomy.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function prc_poc_local_taxonomy_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_state_code'
  $field_bases['field_state_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_state_code',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
