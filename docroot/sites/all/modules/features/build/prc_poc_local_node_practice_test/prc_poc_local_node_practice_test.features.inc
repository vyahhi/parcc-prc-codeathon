<?php
/**
 * @file
 * prc_poc_local_node_practice_test.features.inc
 */

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_practice_test_node_info() {
  $items = array(
    'practice_test' => array(
      'name' => t('Practice Test'),
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
