<?php
/**
 * @file
 * Handles AJAX view operations.
 */


/**
 * Callback to show the contents of the selected item
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
    //Remove the active class from any rows that have it
    $selector = '.view-prc-item-bank tr, #question-list tr';
    $method = "removeClass";
    $commands[] = ajax_command_invoke($selector, $method, array('active'));

    //Add the active class to the row that was just clicked
    $selector = '.quiz-item-'.$node->nid;
    $method = "addClass";
    $commands[] = ajax_command_invoke($selector, $method, array('active'));
    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }  else {
    print $form_html;
  }
}

/**
 * Callback to close the contents of the selected item
 * @param bool $js
 * TRUE if Javascript enabled
 * @param $node
 * The favorites list node
 */
function prc_question_preview_close_menu_item_preview($js = FALSE) {
  $form_html = '<p class="preview-select-question">Select A Question</p>';
  if ($js) {
    ctools_include('ajax');
    $commands = array();
    $commands[] = ajax_command_replace('.item-preview-pane > *', $form_html);

    //Remove the active class from any rows that have it
    $selector = '.view-prc-item-bank tr, , #question-list tr';
    $method = "removeClass";
    $commands[] = ajax_command_invoke($selector, $method, array('active'));

    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }
  else {
    drupal_goto('item-bank');
  }
}