<?php
/**
 * @file
 * prc_poc_local_node_quiz_directions.features.inc
 */

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_quiz_directions_node_info() {
  $items = array(
    'quiz_directions' => array(
      'name' => t('Exam directions'),
      'base' => 'quiz_question',
      'description' => t('Exam directions allow you to drop in directions anywhere in a quiz. You can also use them to insert a confirmation step at the end of the quiz.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
