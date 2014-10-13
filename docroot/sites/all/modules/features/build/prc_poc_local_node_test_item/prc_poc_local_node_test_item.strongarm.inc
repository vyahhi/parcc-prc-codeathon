<?php
/**
 * @file
 * prc_poc_local_node_test_item.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_node_test_item_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_test_item';
  $strongarm->value = array();
  $export['menu_options_test_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_test_item';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_test_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_test_item';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_test_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_test_item';
  $strongarm->value = 1;
  $export['node_submitted_test_item'] = $strongarm;

  return $export;
}
