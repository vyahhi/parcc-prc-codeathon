<?php
/**
 * @file
 * prc_poc_local_node_parcc_released_item.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_parcc_released_item_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_parcc_released_item_node_info() {
  $items = array(
    'parcc_released_item' => array(
      'name' => t('PARCC Released Item'),
      'base' => 'node_content',
      'description' => t('PARCC Released Item'),
      'has_title' => '1',
      'title_label' => t('Resource name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
