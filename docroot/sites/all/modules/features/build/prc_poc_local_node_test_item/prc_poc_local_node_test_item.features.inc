<?php
/**
 * @file
 * prc_poc_local_node_test_item.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_test_item_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_test_item_node_info() {
  $items = array(
    'test_item' => array(
      'name' => t('Test Item'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
