<?php
/**
 * @file
 * prc_poc_local_node_truefalse.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_node_truefalse_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_truefalse';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_truefalse'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_truefalse';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_truefalse'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_truefalse';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_truefalse'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_truefalse';
  $strongarm->value = '1';
  $export['node_preview_truefalse'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_truefalse';
  $strongarm->value = 1;
  $export['node_submitted_truefalse'] = $strongarm;

  return $export;
}
