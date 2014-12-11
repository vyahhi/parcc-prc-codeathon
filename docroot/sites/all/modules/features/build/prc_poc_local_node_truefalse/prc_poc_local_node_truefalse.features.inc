<?php
/**
 * @file
 * prc_poc_local_node_truefalse.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_truefalse_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_truefalse_node_info() {
  $items = array(
    'truefalse' => array(
      'name' => t('True/false question'),
      'base' => 'quiz_question',
      'description' => t('Quiz questions that allow a user to select "true" or "false" as his response to a statement.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
