<?php
/**
 * @file
 * prc_poc_local_node_multichoice.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_node_multichoice_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__multichoice';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'alternatives' => array(
          'weight' => '-4',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__multichoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_multichoice';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_multichoice'] = $strongarm;

  return $export;
}
