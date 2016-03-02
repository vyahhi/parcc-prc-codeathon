<?php
/**
 * @file
 * Handles modal node form operations.
 */

/**
 * Callback to present the comment email form in ctools modal.
 *
 * @param string $type
 *   Node type being created.
 *
 * @param null $js
 *   If Javascript is not support, $js is NULL.
 */
function modal_comment_email($type, $js = NULL, $node = NULL) {
  // Fall back if $js is not set.
  $title = t('Send Comment to the Content Contributor');

  if (!$js) {
    $form_state = array(
      'title' => $title,
      'node' => $node,
      'build_info' => array(
        'args' => array(),
      ),
    );
    return drupal_build_form('prc_comment_email_form', $form_state);
  }

  ctools_include('modal');
  ctools_include('ajax');

  $form_state = array(
    'title' => $title,
    'node' => $node,
    'ajax' => TRUE,
    'build_info' => array(
      'args' => array(),
    ),
  );

  ctools_form_include_file($form_state, drupal_get_path('module', 'node') . '/node.pages.inc');
  $output = ctools_modal_form_wrapper('prc_comment_email_form', $form_state);

  if (!empty($form_state['executed'])) {
    $output = array();
    $output[] = ctools_ajax_command_reload();
  }

  $output[] = array('command' => 'prcResizeModal');

  print ajax_render($output);
  drupal_exit();
}



function prc_comment_email_form($form, &$form_state) {

  $form['title'] = array(
    '#type' => 'container',
    'message' => array(
      '#type' => 'item',
      '#markup' => t('Send Comment to the Content Contributor'),
    ),
  );

  $form['instructions'] = array(
    '#type' => 'container',
    'message' => array(
      '#type' => 'item',
      '#markup' => t('Instructions: (to be added)'),
    ),
  );

  $form['comment'] = array(
    '#type' => 'textarea',
    '#title' => t('Comment'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#prefix' => '<div class="prc-modal-submit-wrapper">',
    '#suffix' => '</div>'
  );

  $form['#submit'] = array(
    'prc_comment_email_form_submit',
  );

  return $form;
}

function prc_comment_email_form_submit(&$form, &$form_state) {
  if (is_array($form_state) && array_key_exists('values', $form_state) && array_key_exists('comment', $form_state['values'])) {
    $comment = $form_state['values']['comment'];
    global $user;
    $node = $form_state['node'];
    $nid = $node->nid;
    if ($comment) {
      drupal_set_message(t('Comment has been submitted.'));
      _prc_comment_email_message_create($user, $comment, $node);
      $next_href = "node/$nid";
    }
  } else {
    $next_href = "/";
  }

  $ajax = array_key_exists('ajax', $form_state) && $form_state['ajax'];
  if ($ajax) {
    // We're already AJAX here so we know we can just put this in.
    // Dismiss the modal.
    $commands = array();

    $commands[] = ctools_ajax_command_reload();
    print ajax_render($commands);
    exit();
  }
  else {
    // Go back to the node view page
    drupal_goto($next_href);
  }
}

