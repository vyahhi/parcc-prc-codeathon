<?php
/**
 * @file
 * prc_poc_local_node_practice_test.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_node_practice_test_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_practice_test';
  $strongarm->value = array();
  $export['menu_options_practice_test'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_practice_test';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_practice_test'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_practice_test';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_practice_test'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_practice_test';
  $strongarm->value = 1;
  $export['node_submitted_practice_test'] = $strongarm;

  return $export;
}
