<?php
/**
 * @file
 * prc_poc_local_node_quiz_directions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_quiz_directions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_quiz_directions_node_info() {
  $items = array(
    'quiz_directions' => array(
      'name' => t('Non-interactive Item (text only)'),
      'base' => 'quiz_question',
      'description' => t('Quiz directions allow you to drop in directions anywhere in a quiz. You can also use them to insert a confirmation step at the end of the quiz.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
