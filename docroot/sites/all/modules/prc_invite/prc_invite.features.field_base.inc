<?php
/**
 * @file
 * prc_invite.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function prc_invite_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_member_state'
  $field_bases['field_member_state'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_member_state',
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
        'AR' => 'Arkansas',
        'CO' => 'Colorado',
        'DC' => 'District of Columbia',
        'IL' => 'Illinois',
        'LA' => 'Louisiana',
        'MD' => 'Maryland',
        'MA' => 'Massachusetts',
        'MI' => 'Mississippi',
        'NJ' => 'New Jersey',
        'NM' => 'New Mexico',
        'NY' => 'New York',
        'OH' => 'Ohio',
        'RI' => 'Rhode Island',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
