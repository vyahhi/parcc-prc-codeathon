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
  $strongarm->name = 'node_options_short_answer';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_short_answer'] = $strongarm;

  return $export;
}
