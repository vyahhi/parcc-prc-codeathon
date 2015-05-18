<?php
/**
 * @file
 * prc_poc_local_node_formative_instructional_task.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_formative_instructional_task_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_formative_instructional_task_node_info() {
  $items = array(
    'formative_instructional_task' => array(
      'name' => t('Formative Instructional Task'),
      'base' => 'node_content',
      'description' => t('Formative Instructional Task'),
      'has_title' => '1',
      'title_label' => t('Resource name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
