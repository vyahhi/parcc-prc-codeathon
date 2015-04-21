<?php
/**
 * @file
 * prc_poc_local_node_quiz.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_quiz_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_quiz_node_info() {
  $items = array(
    'quiz' => array(
      'name' => t('Assessment'),
      'base' => 'quiz',
      'description' => t('Create interactive quizzes for site visitors'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
