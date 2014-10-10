<?php
/**
 * @file
 * prc_poc_local_node_commentable.features.inc
 */

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_commentable_node_info() {
  $items = array(
    'commentable' => array(
      'name' => t('Commentable'),
      'base' => 'node_content',
      'description' => t('Just content to add comments to'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
