<?php
/**
 * @file
 * prc_poc_local_node_course.features.inc
 */

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_course_node_info() {
  $items = array(
    'course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('A <em>course</em> containing Drupal learning objects.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
