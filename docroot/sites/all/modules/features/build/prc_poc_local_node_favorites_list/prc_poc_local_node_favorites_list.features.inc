<?php
/**
 * @file
 * prc_poc_local_node_favorites_list.features.inc
 */

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_favorites_list_node_info() {
  $items = array(
    'favorites_list' => array(
      'name' => t('Favorites List'),
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
