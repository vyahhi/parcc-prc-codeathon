<?php
/**
 * @file
 * prc_poc_local_node_multichoice.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_multichoice_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_multichoice_node_info() {
  $items = array(
    'multichoice' => array(
      'name' => t('Multiple choice question'),
      'base' => 'quiz_question',
      'description' => t('This provides multiple choice questions for use by the Quiz module.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
