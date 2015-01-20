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
        $orig_markup = $value['#markup'];
        $new_markup = l($question_node->title, 'question-preview/nojs/' . $nid, array('attributes' => array('class' => 'use-ajax')));
        $form['question_list']['titles'][$key]['#markup'] = $new_markup;
      }
    }
  }
//  $form['additional_questions']['#access'] = FALSE;

  $block = new stdClass();
  $block->title = '';
  $block->content = drupal_render($form);

  // The item list has AJAXy links so we need ajax!
  drupal_add_library('system', 'drupal.ajax');

  return $block;
}