<?php
/**
 * @file
 * Handles AJAX view operations.
 */


/**
 * Callback to show the contents of the selected Favorites List
 * @param bool $js
 * TRUE if Javascript enabled
 * @param $node
 * The favorites list node
 */
function prc_ajax_show_digital_library_favorites_list($js = FALSE, $node) {
  $list_type = $node->field_content_type['und'][0]['value'];
  if ($js) {
    // Get the HTML output of the view.
    $type_view_name = array(
      'digital_library_content' => 'digital_library_favorites',
      'pd_course' => 'professional_development_favorites'
    );
    $view_name = $type_view_name[$list_type];
    $list_output = views_embed_view($view_name, 'default', $node->nid);
    ctools_include('ajax');
    $commands = array();
    $commands[] = ajax_command_replace('.digital-library-content-pane > *', $list_output);
    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }
  else {
    // No JS, so redirect to the correct page.
    $type_view_name = array(
      'digital_library_content' => 'digital-library',
      'pd_course' => 'professional-development'
    );
    $view_name = $type_view_name[$list_type];
    drupal_goto($view_name . '/' . $node->nid);
  }
}