<?php
/**
 * @file
 * prc_poc_local_node_test_item.features.inc
 */

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
