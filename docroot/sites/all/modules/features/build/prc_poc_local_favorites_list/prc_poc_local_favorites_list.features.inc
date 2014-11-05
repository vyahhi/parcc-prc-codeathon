<?php
/**
 * @file
 * prc_poc_local_favorites_list.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_favorites_list_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_favorites_list_node_info() {
  $items = array(
    'favorites_list' => array(
      'name' => t('Favorites List'),
      'base' => 'node_content',
      'description' => t('User-created list of Favorite content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
