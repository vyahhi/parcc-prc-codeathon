<?php
/**
 * @file
 * prc_poc_local_node_short_answer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_short_answer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_short_answer_node_info() {
  $items = array(
    'short_answer' => array(
      'name' => t('Short answer question'),
      'base' => 'quiz_question',
      'description' => t('Quiz questions that allow a user to enter a line of text.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
