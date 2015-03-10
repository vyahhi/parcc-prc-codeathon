<?php
/**
 * @file
 * prc_poc_local_node_district.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_node_district_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_district';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_district'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_district';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_district'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_district';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_district'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_district';
  $strongarm->value = '0';
  $export['node_preview_district'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_district';
  $strongarm->value = 0;
  $export['node_submitted_district'] = $strongarm;

  return $export;
}
