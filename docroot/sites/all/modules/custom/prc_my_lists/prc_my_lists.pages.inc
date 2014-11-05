<?php
/**
 * @file
 * Handles modal node form operations.
 */

/**
 * Callback to present the node add form in ctools modal.
 *
 * @param string $type
 *   Node type being created.
 *
 * @param null $js
 *   If Javascript is not support, $js is NULL.
 */
function modal_add_to_list($type, $js = NULL) {
  // Fall back if $js is not set.
  $title = t('Add to My Lists');

  if (!$js) {
    $form_state = array(
      'title' => $title,
      'build_info' => array(
        'args' => array(),
      ),
    );
    return drupal_build_form('prc_my_lists_view_lists_form', $form_state);
  }


  // Fall back if $js is not set.
  if (!$js) {
    return node_add($type);
  }

  ctools_include('modal');
  ctools_include('ajax');

  $form_state = array(
    'title' => $title,
    'ajax' => TRUE,
    'build_info' => array(
      'args' => array(),
    ),
  );

  ctools_form_include_file($form_state, drupal_get_path('module', 'node') . '/node.pages.inc');
  $output = ctools_modal_form_wrapper('prc_my_lists_view_lists_form', $form_state);

  if (!empty($form_state['executed'])) {
    $output = array();
    $output[] = ctools_ajax_command_reload();
  }
  print ajax_render($output);
  drupal_exit();
}

/**
 * Callback to present the node add form in ctools modal.
 *
 * @param string $type
 *   Node type being created.
 *
 * @param null $js
 *   If Javascript is not support, $js is NULL.
 */
function modal_add_a_list($type, $js = NULL) {
  // Fall back if $js is not set.
  $title = t('Add to My Lists');

  if (!$js) {
    $form_state = array(
      'title' => $title,
      'build_info' => array(
        'args' => array(),
      ),
    );
    return drupal_build_form('prc_my_lists_create_list_form', $form_state);
  }

  ctools_include('modal');
  ctools_include('ajax');

  $form_state = array(
    'title' => $title,
    'ajax' => TRUE,
    'build_info' => array(
      'args' => array(),
    ),
  );

  ctools_form_include_file($form_state, drupal_get_path('module', 'node') . '/node.pages.inc');
  $output = ctools_modal_form_wrapper('prc_my_lists_create_list_form', $form_state);

  if (!empty($form_state['executed'])) {
    $output = array();
    $output[] = ctools_ajax_command_reload();
  }
  print ajax_render($output);
  drupal_exit();
}

function prc_my_lists_view_lists_form($form, &$form_state) {
  $href = 'favorites-list/nojs/create-list';
  $ajax = array_key_exists('ajax', $form_state) && $form_state['ajax'];
  if ($ajax) {
    ctools_include('modal');
    $markup = ctools_modal_text_button('Create new', $href, 'Create new favorites list');
  } else {
    $markup = l(t('Create new'), $href);
  }
  $form['create_new_list'] = array(
    '#markup' => $markup,
  );

  return $form;
}

function prc_my_lists_create_list_form($form, &$form_state) {
  $form['list_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Please enter a new list name'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create'),
  );

  $cancel_href = 'favorites-list/nojs/add-to-list';
  $ajax = array_key_exists('ajax', $form_state) && $form_state['ajax'];
  if ($ajax) {
    ctools_include('modal');
    $markup = ctools_modal_text_button('Cancel', $cancel_href, 'Cancel');
  } else {
    $markup = l(t('Cancel'), $cancel_href);
  }

  $form['cancel'] = array(
    '#markup' => $markup,
  );

  $form['#submit'] = array(
    'prc_my_lists_create_list_form_submit',
  );

  return $form;
}

function prc_my_lists_create_list_form_submit(&$form, &$form_state) {
  // Go back to the add to list page
  $next_href = 'favorites-list/nojs/add-to-list';

  if (is_array($form_state) && array_key_exists('values', $form_state) && array_key_exists('list_name', $form_state['values'])) {
    $list_name = $form_state['values']['list_name'];
    if ($list_name) {
      // We have a valid list name. Create the new list node.
      global $user;

      $node = new stdClass();
      $node->title = $list_name;
      $node->type = 'favorites_list';
      node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
      $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled
      $node->uid = $user->uid;
      $node->status = 1; //(1 or 0): published or not
      $node = node_submit($node); // Prepare node for saving
      node_save($node);

      drupal_set_message("Created new \"$list_name\" list.\n");
    }
  }
  drupal_goto($next_href);
}