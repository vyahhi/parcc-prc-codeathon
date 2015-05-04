<?php
/**
 * @file
 * prc_poc_local_node_speaking_and_listening_resource.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_speaking_and_listening_resource_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_speaking_and_listening_resource_node_info() {
  $items = array(
    'speaking_and_listening_resource' => array(
      'name' => t('Speaking and Listening Resource'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Resource name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
