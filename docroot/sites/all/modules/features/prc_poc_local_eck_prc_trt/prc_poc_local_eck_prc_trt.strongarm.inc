<?php
/**
 * @file
 * prc_poc_local_eck_prc_trt.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_eck_prc_trt_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_prc_trt__system_check';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_prc_trt__system_check'] = $strongarm;

  return $export;
}
