<?php
/**
 * @file
 * prc_poc_local_pd_course.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_pd_course_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_pd_course_node_info() {
  $items = array(
    'pd_course' => array(
      'name' => t('PD Course'),
      'base' => 'node_content',
      'description' => t('PRC Professional Development Course'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
