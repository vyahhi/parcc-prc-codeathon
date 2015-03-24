<?php
/**
 * @file
 * prc_poc_local_node_state.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_state_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_state_node_info() {
  $items = array(
    'state' => array(
      'name' => t('State'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
