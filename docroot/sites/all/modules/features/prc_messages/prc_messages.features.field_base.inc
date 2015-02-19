<?php
/**
 * @file
 * prc_messages.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function prc_messages_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_version_id'
  $field_bases['field_version_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_version_id',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
