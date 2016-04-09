<?php
/**
 * @file
 * prc_poc_local_eck_practice_test.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function prc_poc_local_eck_practice_test_eck_bundle_info() {
  $items = array(
    'practice_test_practice_test' => array(
      'machine_name' => 'practice_test_practice_test',
      'entity_type' => 'practice_test',
      'name' => 'practice_test',
      'label' => 'Practice Test',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function prc_poc_local_eck_practice_test_eck_entity_type_info() {
  $items = array(
    'practice_test' => array(
      'name' => 'practice_test',
      'label' => 'Practice Test',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'test_key' => array(
          'label' => 'Test Key',
          'type' => 'text',
          'behavior' => '',
        ),
      ),
    ),
  );
  return $items;
}
