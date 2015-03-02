<?php

/**
 * Implements hook_html_head_alter().
 */
function prc_foundation_html_head_alter(&$head_elements) {
  // HTML5 charset declaration.
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8',
  );

  // Optimize mobile viewport.
  $head_elements['mobile_viewport'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, maximum-scale = 1.0',
    ),
  );
}

/**
 * Implements hook_preprocess_html()
 */
function prc_foundation_preprocess_html(&$variables) {
  drupal_add_css('http://fonts.googleapis.com/css?family=Open+Sans:400,700', array('type' => 'external'));
}

function prc_foundation_preprocess_page(&$vars, $hook) {
  if (true) {
    drupal_add_js('http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML', 'external');
    $vars['scripts'] = drupal_get_js(); // necessary in D7?
  }
}

function prc_foundation_ds_search_page($build) {
  if (isset($build['theme_hook_original'])) {
    unset($build['theme_hook_original']);
  }
  return $build;
}

function prc_foundation_course_outline_item($variables) {
  $output = '';
  $step = $variables['step'];
  $img = $variables['img'];
  $object = $variables['object'];
  $status = $step['status'] ? $step['status'] : t('Not started');
  $node = $object->getNode();
  $w = entity_metadata_wrapper('node', $node);

  if ($node->type == 'pd_module') {
    $length = $w->field_length->value() ?
      '<span>' . '(' . $w->field_length->value() . ')</span><br/>' :
      '';
    $objectives = $w->field_course_objectives->value() ? '<span>' . t('Module Objectives') . ': ' . $w->field_course_objectives->value() . '</span><br/>' : '';
    if (empty($step['link'])) {
      $output = $object->getTitle() . '<br/>' .
        $length .
        $objectives .
        '<span class="course-outline-status">' . $status . '</span>';
    }
    else {
      $output = $img . ' ' .
        l("{$object->getTitle()}<br/>", $step['link'], array('html' => TRUE)) .
        $length .
        $objectives .
        '<span class="course-outline-status">' . $step['status'] . '</span>';
    }
  } else {
    if ($status == 'Complete' || empty($step['link'])) {
      $output = $object->getTitle();
    }
    else {
      $output = l("{$object->getTitle()}", $step['link'], array('html' => TRUE));
    }
  }


  return $output;
}

/**
 * Theme a question selection table, adding drag and drop support.
 */
function prc_foundation_question_selection_table($variables) {
  $form = $variables['form'];
  drupal_add_tabledrag('question-list', 'match', 'parent', 'qnr-pid', 'qnr-pid', 'qnr-id', TRUE, 1);
  drupal_add_tabledrag('question-list', 'order', 'sibling', 'question-list-weight');

  // Building headers
  $headers = array(t('Preview'), t('Item Type'), t('Actions'), t('Item Order'), t('Item Standard'), t('Delete'));
  if (isset($form['compulsories'])) {
    $headers[] = t('Compulsory');
  }
  $headers[] = t('Weight');
  $headers[] = t('Parent ID');
  $headers[] = array(
    'data' => t('ID'),
    'class' => array('tabledrag-hide'),
  );

  // Building table body
  $rows = array();
  if (!empty($form['titles'])) {
    foreach (element_children($form['titles']) as $id) {
      $form['weights'][$id]['#attributes']['class'] = array('question-list-weight');
      $form['qnr_ids'][$id]['#attributes']['class'] = array('qnr-id');
      $form['qnr_pids'][$id]['#attributes']['class'] = array('qnr-pid');
      $rows[] = _prc_question_preview_quiz_get_question_row($form, $id);
    }
    // Make sure the same fields aren't rendered twice
    unset($form['types'], $form['view_links'], $form['remove_links'], $form['stayers']);
    unset($form['max_scores'], $form['auto_update_max_scores'], $form['revision'], $form['weights'], $form['titles'], $form['compulsories'], $form['qnr_ids'], $form['qnr_pids'], $form['item_orders'], $form['item_standards']);
  }
  $html_attr = array('id' => 'question-list');

  // We hide the table if no questions have been added so that jQuery can show it the moment the first question is being added.
  if (isset($form['no_questions'])) {
    $html_attr['style'] = "display:none;";
  }

  $table = theme('table', array('header' => $headers, 'rows' => $rows, 'attributes' => $html_attr));

  return drupal_render($form['random_settings'])
  . $table
  . drupal_render_children($form);
}

