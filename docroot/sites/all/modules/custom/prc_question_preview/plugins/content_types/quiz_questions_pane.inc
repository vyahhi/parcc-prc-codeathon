<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Quiz Questions Pane'),
  'description' => t('Custom quiz pane with questions form.'),
  'category' => t('PRC Custom panes'),
  'render callback' => 'quiz_questions_pane_render',
  'all contexts' => TRUE,
);

function quiz_questions_pane_render($subtype, $conf, $args, $contexts) {

  $node = $contexts['argument_entity_id:node_1']->data;

  module_load_include('inc', 'quiz', 'quiz.admin');
  $form = drupal_get_form('prc_question_preview_quiz_questions_form', $node);
  if (array_key_exists('titles', $form['question_list'])) {
    foreach ($form['question_list']['titles'] as $key => $value) {
      if (strpos($key, '-')) {
        $vals = explode('-', $key);
        $nid = $vals[0];
        $question_node = node_load($nid);
        $new_markup = l($question_node->title, 'question-preview/nojs/' . $nid, array('attributes' => array('class' => 'use-ajax')));
        $form['question_list']['titles'][$key]['#markup'] = $new_markup;
      }
    }
  }

  unset($form['question_list']['#type']);
  unset($form['question_list']['#collapsible']);
  unset($form['question_list']['#collapsed']);
  unset($form['question_list']['#theme_wrappers']);

  $links = array();
  $query_string['query'] = array(
    'destination' => 'node/' . $node->nid,
    'quiz_nid' => $node->nid,
    'quiz_vid' => $node->vid,
  );

  $links['dropdown_text'] = t('Add Item');

  $links['items'][] = l(t('Add Existing Item'), 'node/' . $node->nid . '/itembank');
  $links['items'][] = l(t('Non-interactive Item (text only)'), 'node/add/quiz-directions', $query_string);
  $links['items'][] = l(t('Interactive Choice'), 'node/add/multichoice', $query_string);
  $links['items'][] = l(t('Short Answer'), 'node/add/short-answer', $query_string);

  unset($form['additional_questions']);
  $new_links = theme('foundation_dropdown_menu', $links);

  $block = new stdClass();
  $block->title = '';
  $block->content['form'] = $form;
  $block->content['create_links'] = $new_links;

  // The item list has AJAXy links so we need ajax!
  drupal_add_library('system', 'drupal.ajax');

  return $block;
}