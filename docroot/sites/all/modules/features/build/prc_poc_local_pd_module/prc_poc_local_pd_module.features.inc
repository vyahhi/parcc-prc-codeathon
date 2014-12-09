<?php
/**
 * @file
 * prc_poc_local_pd_module.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_pd_module_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_pd_module_node_info() {
  $items = array(
    'pd_module' => array(
      'name' => t('PD Module'),
      'base' => 'node_content',
      'description' => t('Professional Development Module'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
