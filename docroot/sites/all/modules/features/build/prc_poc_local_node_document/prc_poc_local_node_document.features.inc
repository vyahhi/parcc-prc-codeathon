<?php
/**
 * @file
 * prc_poc_local_node_document.features.inc
 */

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_document_node_info() {
  $items = array(
    'document' => array(
      'name' => t('Document'),
      'base' => 'node_content',
      'description' => t('Upload a document'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
