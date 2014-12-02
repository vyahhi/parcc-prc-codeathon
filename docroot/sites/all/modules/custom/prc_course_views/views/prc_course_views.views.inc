<?php

/**
 * @file
 * PARCC PRC Course Views Handlers integration code.
 */

/**
 * Implements hook_views_data_alter().
 */
function prc_course_views_views_data_alter(&$data) {

  // Provide a count of the course node's objects
  if (module_exists('course')) {
    $data['node']['course_object_count'] = array(
      'real field' => 'nid',
      'field' => array(
        'title' => t('Number of Modules/Quizzes'),
        'help' => t('Provide a count of the course objects in the current course.'),
        'handler' => 'prc_course_views_views_handler_field_node_course_object_count',
        'click sortable' => TRUE,
      ),
    );
  }
}
