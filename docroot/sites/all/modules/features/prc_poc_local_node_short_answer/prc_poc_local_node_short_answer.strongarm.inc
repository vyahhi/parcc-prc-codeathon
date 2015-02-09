<?php
/**
 * @file
 * prc_poc_local_node_short_answer.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_node_short_answer_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_short_answer';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_short_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_short_answer';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_short_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_short_answer';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_short_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_short_answer';
  $strongarm->value = '1';
  $export['node_preview_short_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_short_answer';
  $strongarm->value = 1;
  $export['node_submitted_short_answer'] = $strongarm;

  return $export;
}
