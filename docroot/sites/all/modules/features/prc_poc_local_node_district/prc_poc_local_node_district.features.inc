<?php
/**
 * @file
 * prc_poc_local_node_district.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_district_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_district_node_info() {
  $items = array(
    'district' => array(
      'name' => t('District'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('District Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
