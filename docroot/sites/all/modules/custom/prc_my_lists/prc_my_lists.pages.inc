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
function modal_add_to_list($type, $js = NULL, $node = NULL) {
  // Fall back if $js is not set.
  $title = t('Add to My Lists');

  if (!$js) {
    $form_state = array(
      'title' => $title,
      'node' => $node,
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
    'node' => $node,
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
function modal_add_a_list($type, $js = NULL, $node = NULL) {
  // Fall back if $js is not set.
  $title = t('Add to My Lists');

  if (!$js) {
    $form_state = array(
      'title' => $title,
      'node' => $node,
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
    'node' => $node,
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
  $ajax = array_key_exists('ajax', $form_state) && $form_state['ajax'];
  $nid = array_key_exists('node', $form_state) ? $form_state['node']->nid : 0;
  $href = "favorites-list/$nid/nojs/create-list";

  if ($ajax) {
    ctools_include('modal');
    $markup = ctools_modal_text_button('Create new', $href, 'Create new favorites list');
  }
  else {
    $markup = l(t('Create new'), $href);
  }
  $form['create_new_list'] = array(
    '#markup' => $markup,
  );

  $lists = _prc_my_lists_current_user_lists();

  $list_titles = array();
  foreach ($lists as $key => $list) {
    $list_titles[$key] = $list->title;
  }

  $form['select_list'] = array(
    '#type' => 'select',
    '#title' => t('List'),
    '#options' => $list_titles,
    '#chosen' => TRUE,
    '#theme_options' => array(
      'description at top' => t('Select the list you would like to use to categorize this content.'),
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add to List'),
  );


  $form['#submit'] = array(
    'prc_my_lists_view_lists_form_submit',
  );


  return $form;
}

function _prc_my_lists_current_user_lists() {
  global $user;
  $uid = $user->uid;

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'favorites_list')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->propertyCondition('uid', $uid);

  $result = $query->execute();

  if (isset($result['node'])) {
    $list_nids = array_keys($result['node']);
    $lists = entity_load('node', $list_nids);
  } else {
    $lists = array();
  }

  return $lists;
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

  $nid = array_key_exists('node', $form_state) ? $form_state['node']->nid : 0;
  $cancel_href = "favorites-list/$nid/nojs/add-to-list";
  $ajax = array_key_exists('ajax', $form_state) && $form_state['ajax'];
  if ($ajax) {
    ctools_include('modal');
    $markup = ctools_modal_text_button('Cancel', $cancel_href, 'Cancel');
  }
  else {
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

  $nid = array_key_exists('node', $form_state) ? $form_state['node']->nid : 0;
  $ajax = array_key_exists('ajax', $form_state) && $form_state['ajax'];
  if ($ajax) {
    // We're already AJAX here so we know we can just put this in.
    // Letting it do its thing with nojs doesn't work for the submit redirect.
    $next_href = "favorites-list/$nid/ajax/add-to-list";
  }
  else {
    $next_href = "favorites-list/$nid/nojs/add-to-list";
  }
  // Go back to the add to list page
  drupal_goto($next_href);
}

function prc_my_lists_view_lists_form_submit(&$form, &$form_state) {
  $nid = array_key_exists('node', $form_state) ? $form_state['node']->nid : 0;

  if (is_array($form_state) && array_key_exists('values', $form_state)
    && array_key_exists('node', $form_state)
    && array_key_exists('select_list', $form_state['values'])) {
    $list_nid = $form_state['values']['select_list'];
    $list_node = node_load($list_nid);
    if ($list_node && $list_node->type == 'favorites_list') {

      $list_wrapper = entity_metadata_wrapper('node', $list_node);

      $favorited_nodes = $list_wrapper->field_favorite_content->value();
      $found = FALSE;
      foreach($favorited_nodes as $favorited_node) {
        $favorited_nid = $favorited_node->nid;
        if ($favorited_nid == $nid) {
          $found = TRUE;
          break;
        }
      }
      if (!$found) {
        $list_wrapper->field_favorite_content[] = $nid;
        $list_wrapper->save();

        $list_name = $list_node->title;

        drupal_set_message("Added item to \"$list_name\" list.\n");
      }
    }

  }

  $ajax = array_key_exists('ajax', $form_state) && $form_state['ajax'];
  if ($ajax) {
    // We're already AJAX here so we know we can just put this in.
    // Letting it do its thing with nojs doesn't work for the submit redirect.
    $next_href = "favorites-list/$nid/ajax/add-to-list";
  }
  else {
    $next_href = "favorites-list/$nid/nojs/add-to-list";
  }
  // Go back to the add to list page
  drupal_goto($next_href);
}