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

  $form['additional_questions']['#title'] = t('Add Item');

  $form['additional_questions']['multichoice']['#markup'] = str_replace(t('Multiple choice question'), t('Interactive Choice'), $form['additional_questions']['multichoice']['#markup']);
  $form['additional_questions']['quiz_directions']['#markup'] = str_replace(t('Exam directions'), t('Non-interactive Item (text only)'), $form['additional_questions']['quiz_directions']['#markup']);
  $form['additional_questions']['short_answer']['#markup'] = str_replace(t('Short answer question'), t('Short Answer'), $form['additional_questions']['short_answer']['#markup']);

  // Ugly ugly ugly, but it doesn't respond to #weight, so we have to re-order the array.
  $form['additional_questions']['quiz_directions']['#weight'] = 0;
  $form['additional_questions']['multichoice']['#weight'] = 1;
  $form['additional_questions']['short_answer']['#weight'] = 2;

  $form['additional_questions']['fake_quiz_directions'] = $form['additional_questions']['quiz_directions'];
  $form['additional_questions']['fake_multichoice'] = $form['additional_questions']['multichoice'];
  $form['additional_questions']['fake_short_answer'] = $form['additional_questions']['short_answer'];

  unset($form['additional_questions']['quiz_directions']);
  unset($form['additional_questions']['multichoice']);
  unset($form['additional_questions']['short_answer']);

  $form['additional_questions']['quiz_directions'] = $form['additional_questions']['fake_quiz_directions'];
  $form['additional_questions']['multichoice'] = $form['additional_questions']['fake_multichoice'];
  $form['additional_questions']['short_answer'] = $form['additional_questions']['fake_short_answer'];

  unset($form['additional_questions']['fake_quiz_directions']);
  unset($form['additional_questions']['fake_multichoice']);
  unset($form['additional_questions']['fake_short_answer']);

  $block = new stdClass();
  $block->title = '';
  $block->content = drupal_render($form);

  // The item list has AJAXy links so we need ajax!
  drupal_add_library('system', 'drupal.ajax');

  return $block;
}