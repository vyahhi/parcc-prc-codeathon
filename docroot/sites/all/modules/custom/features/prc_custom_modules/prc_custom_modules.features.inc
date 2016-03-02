<?php
/**
 * @file
 * prc_custom_modules.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_custom_modules_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function prc_custom_modules_eck_bundle_info() {
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
function prc_custom_modules_eck_entity_type_info() {
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

/**
 * Implements hook_weight_features_default_settings().
 */
function prc_custom_modules_weight_features_default_settings() {
  $settings = array();

  $settings['homepage_band'] = array(
    'enabled' => 1,
    'range' => 10,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
