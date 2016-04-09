<?php
/**
 * @file
 * prc_poc_local_eck_prc_trt.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_eck_prc_trt_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function prc_poc_local_eck_prc_trt_eck_bundle_info() {
  $items = array(
    'prc_trt_capacity_check' => array(
      'machine_name' => 'prc_trt_capacity_check',
      'entity_type' => 'prc_trt',
      'name' => 'capacity_check',
      'label' => 'capacity_check',
      'config' => array(),
    ),
    'prc_trt_system_check' => array(
      'machine_name' => 'prc_trt_system_check',
      'entity_type' => 'prc_trt',
      'name' => 'system_check',
      'label' => 'system_check',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function prc_poc_local_eck_prc_trt_eck_entity_type_info() {
  $items = array(
    'prc_trt' => array(
      'name' => 'prc_trt',
      'label' => 'prc_trt',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'uuid' => array(
          'label' => 'UUID',
          'type' => 'text',
          'behavior' => 'uuid',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
      ),
    ),
  );
  return $items;
}
