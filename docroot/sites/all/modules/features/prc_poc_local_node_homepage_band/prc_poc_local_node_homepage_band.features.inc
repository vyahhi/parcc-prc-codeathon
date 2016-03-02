<?php
/**
 * @file
 * prc_poc_local_node_homepage_band.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_homepage_band_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_homepage_band_node_info() {
  $items = array(
    'homepage_band' => array(
      'name' => t('Homepage Band'),
      'base' => 'node_content',
      'description' => t('The \'bands\' of information currently displayed below the main image on the homepage.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
