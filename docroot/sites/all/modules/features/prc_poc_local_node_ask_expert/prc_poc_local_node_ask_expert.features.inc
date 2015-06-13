<?php
/**
 * @file
 * prc_poc_local_node_ask_expert.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_node_ask_expert_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function prc_poc_local_node_ask_expert_node_info() {
  $items = array(
    'ask_expert' => array(
      'name' => t('Ask An Expert'),
      'base' => 'node_content',
      'description' => t(' A frequently asked question that can either be created by a content curator or a submitted by a user.'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => t('Make sure you reviewed for similar questions.
Keep questions concise, but feel free to elaborate in the description.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
