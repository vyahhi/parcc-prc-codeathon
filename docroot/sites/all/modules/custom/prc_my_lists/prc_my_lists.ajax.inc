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
  if ($js) {
    // Get the HTML output of the view.
    $list_output = views_embed_view('digital_library_favorites', 'default', $node->nid);
    ctools_include('ajax');
    $commands = array();
    $commands[] = ajax_command_replace('.digital-library-content-pane > *', $list_output);
    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }
  else {
    // No JS, so redirect to the correct page.
    drupal_goto('digital-library/' . $node->nid);
  }
}