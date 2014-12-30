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
function prc_question_preview_menu_item_preview($js = FALSE, $node) {
  $question_form = drupal_get_form('prc_question_view_question_preview_form', $node, 15);
  // Get the HTML output of the form.
  $form_html = drupal_render($question_form);

  if ($js) {

    ctools_include('ajax');
    $commands = array();
    $commands[] = ajax_command_replace('.item-preview-pane > *', $form_html);
    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }
  else {
    print $form_html;
  }
}