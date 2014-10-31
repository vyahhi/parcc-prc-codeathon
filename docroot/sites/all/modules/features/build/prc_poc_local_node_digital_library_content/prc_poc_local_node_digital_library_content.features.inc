<?php
/**
 * @file
 * prc_poc_local_node_digital_library_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_digital_library_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
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
function prc_poc_local_node_digital_library_content_node_info() {
  $items = array(
    'digital_library_content' => array(
      'name' => t('Digital Library Content'),
      'base' => 'node_content',
      'description' => t('Use this content type for the content you wish to add to the digital library, like news, articles, press releases or blog post'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
