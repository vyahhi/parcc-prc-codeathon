<?php

/**
 * The main classes for the PRC-specific multichoice question type.
 *
 * These inherit or implement code found in quiz_question.classes.inc.
 *
 * @file
 * Question type, enabling the creation of multiple choice and multiple answer questions.
 */

/**
 * Extension of MultichoiceQuestion.
 */
class PRCMultichoiceQuestion extends MultichoiceQuestion {
  const PRC_MINIMUM_DISTRACTORS = 2;

  public function saveNodeProperties($is_new = FALSE) {
    $only_arrays = array();
    foreach($this->node->alternatives as $alt) {
      if (is_array($alt)) {
        $only_arrays[] = $alt;
      }
    }

    $this->node->alternatives = $only_arrays;

    for ($i = 0; isset($this->node->alternatives[$i]); $i++) {
      $this->node->alternatives[$i]['score_if_chosen'] = $this->node->alternatives[$i]['correct'] ? 1 : 0;
    }

    parent::saveNodeProperties($is_new);
  }


  public function getCreationForm(array &$form_state = NULL) {
    $form = array();
    $type = node_type_get_type($this->node);
    // We add #action to the form because of the use of ajax
    $options = array();
    $get = $_GET;
    unset($get['q']);
    if (!empty($get)) {
      $options['query'] = $get;
    }

    $action = url('node/add/' . $type->type, $options);
    if (isset($this->node->nid)) {
      $action = url('node/' . $this->node->nid . '/edit', $options);
    }
    $form['#action'] = $action;

    drupal_add_tabledrag('multichoice-alternatives-table', 'order', 'sibling', 'multichoice-alternative-weight');

    $form['alternatives'] = array(
      '#type' => 'fieldset',
      '#title' => t('Answer'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -4,
      '#tree' => TRUE,
    );

    $form['alternatives']['settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -10,
    );
    $form['alternatives']['settings']['choice_multi'] = array(
      '#type' => 'checkbox',
      '#title' => t('Multiple correct answers'),
      '#description' => t('Allow any number of correct answers (checkboxes are used). If this box is not checked, one, and only one answer is allowed (radiobuttons are used).'),
      '#default_value' => 0,
      '#parents' => array('choice_multi'),
    );
    $form['alternatives']['settings']['choice_random'] = array(
      '#type' => 'checkbox',
      '#title' => t('Random order'),
      '#description' => t('Present alternatives in random order when @quiz is being taken.', array('@quiz' => QUIZ_NAME)),
      '#default_value' => 0,
      '#parents' => array('choice_random'),
    );
    $form['alternatives']['settings']['choice_boolean'] = array(
      '#type' => 'checkbox',
      '#title' => t('Simple scoring'),
      '#description' => t('Give max score if everything is correct. Zero points otherwise.'),
      '#default_value' => 0,
      '#parents' => array('choice_boolean'),
    );

    $form['alternatives']['#theme'][] = 'multichoice_creation_form';

    // choice_count might be stored in the form_state after an ajax callback
    if (isset($form_state['values']['add-alternative']) && $form_state['values']['add-alternative']) {
      $form_state['choice_count']++;
    }
    elseif (isset($form_state['triggering_element']) && strpos($form_state['triggering_element']['#name'], 'remove-alternative') !== FALSE) {
      $trigger = $form_state['triggering_element'];
      $alt = $trigger['#alternative'];
      $this->node->alternatives[$alt]['deleted'] = TRUE;
    }
    else {
      $form_state['choice_count'] = max(variable_get('multichoice_def_num_of_alts', 2), isset($this->node->alternatives) ? count($this->node->alternatives) : 0);
    }

    $form['alternatives']['#prefix'] = '<div class="clear-block" id="multichoice-alternatives-wrapper">';
    $form['alternatives']['#suffix'] = '</div>';
    $form['alternatives']['#theme'] = array('multichoice_alternative_creation_table');
    for ($i = 0; $i < $form_state['choice_count']; $i++) {
      $short = isset($this->node->alternatives[$i]) ? $this->node->alternatives[$i] : NULL;
      if ($short && isset($short['deleted']) && $short['deleted']) {
        // This answer has been deleted, so don't draw it
        continue;
      }

      $form['alternatives'][$i] = array(
        '#type' => 'container',
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        // - The two first alternatives won't be collapsed.
        // - Populated alternatives won't be collapsed
      );

      if (is_array($short)) {
        if ($short['score_if_chosen'] == $short['score_if_not_chosen']) {
          $correct_default = isset($short['correct']) ? $short['correct'] : FALSE;
        }
        else {
          $correct_default = $short['score_if_chosen'] > $short['score_if_not_chosen'];
        }
      }
      else {
        $correct_default = FALSE;
      }
      $form['alternatives'][$i]['correct'] = array(
        '#type' => 'checkbox',
        '#default_value' => $correct_default,
        '#attributes' => array('onchange' => 'Multichoice.refreshScores(this, ' . variable_get('multichoice_def_scoring', 0) . ')'),
      );

      $form['alternatives'][$i]['remove'] = array(
        '#type' => 'button',
        '#value' => t('Remove'),
        '#limit_validation_errors' => array(),
        '#name' => 'remove-alternative-' . $i,
        '#alternative' => $i,
        '#ajax' => array(
          'method' => 'replace',
          'wrapper' => 'multichoice-alternatives-wrapper',
          'callback' => 'prc_multichoice_remove_alternative_ajax_callback',
        ),
        '#weight' => 20,
      );

      // We add id to be able to update the correct alternatives if the node is updated, without destroying
      // existing answer reports
      $form['alternatives'][$i]['id'] = array(
        '#type' => 'value',
        '#value' => $short['id'],
      );

      $form['alternatives'][$i]['answer'] = array(
        '#type' => 'text_format',
        '#default_value' => $short['answer']['value'],
        '#required' => $i < 2,
        '#format' => isset($short['answer']['format']) ? $short['answer']['format'] : NULL,
        '#rows' => 3,
      );

      $form['alternatives'][$i]['advanced'] = array(
        '#type' => 'fieldset',
        '#title' => t('Advanced options'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['alternatives'][$i]['advanced']['feedback_if_chosen'] = array(
        '#type' => 'text_format',
        '#title' => t('Feedback if chosen'),
        '#description' => t('This feedback is given to users who chooses this alternative.'),
        '#parents' => array('alternatives', $i, 'feedback_if_chosen'),
        '#default_value' => $short['feedback_if_chosen']['value'],
        '#format' => isset($short['feedback_if_chosen']['format']) ? $short['feedback_if_chosen']['format'] : NULL,
        '#rows' => 3,
      );
      // We add 'helper' to trick the current version of the wysiwyg module to add an editor to several
      // textareas in the same fieldset
      $form['alternatives'][$i]['advanced']['helper']['feedback_if_not_chosen'] = array(
        '#type' => 'text_format',
        '#title' => t('Feedback if not chosen'),
        '#description' => t('This feedback is given to users who doesn\'t choose this alternative.'),
        '#parents' => array('alternatives', $i, 'feedback_if_not_chosen'),
        '#default_value' => $short['feedback_if_not_chosen']['value'],
        '#format' => isset($short['feedback_if_not_chosen']['format']) ? $short['feedback_if_not_chosen']['format'] : NULL,
        '#rows' => 3,
      );
      $default_value = isset($this->node->alternatives[$i]['score_if_chosen']) ? $this->node->alternatives[$i]['score_if_chosen'] : 0;
      $form['alternatives'][$i]['advanced']['score_if_chosen'] = array(
        '#type' => 'textfield',
        '#title' => t('Score if chosen'),
        '#size' => 4,
        '#maxlength' => 4,
        '#default_value' => $default_value,
        '#description' => t("This score is added to the user's total score if the user chooses this alternative."),
        '#attributes' => array(
          'onkeypress' => 'Multichoice.refreshCorrect(this)',
          'onkeyup' => 'Multichoice.refreshCorrect(this)',
          'onchange' => 'Multichoice.refreshCorrect(this)'
        ),
        '#parents' => array('alternatives', $i, 'score_if_chosen')
      );

      $default_value = $short['score_if_not_chosen'];
      if (!isset($default_value)) {
        $default_value = '0';
      }
      $form['alternatives'][$i]['advanced']['score_if_not_chosen'] = array(
        '#type' => 'textfield',
        '#title' => t('Score if not chosen'),
        '#size' => 4,
        '#maxlength' => 4,
        '#default_value' => $default_value,
        '#description' => t("This score is added to the user's total score if the user doesn't choose this alternative. Only used if multiple answers are allowed."),
        '#attributes' => array(
          'onkeypress' => 'Multichoice.refreshCorrect(this)',
          'onkeyup' => 'Multichoice.refreshCorrect(this)',
          'onchange' => 'Multichoice.refreshCorrect(this)'
        ),
        '#parents' => array('alternatives', $i, 'score_if_not_chosen')
      );
      $form['alternatives'][$i]['weight'] = array(
        '#type' => 'textfield',
        '#size' => 2,
        '#attributes' => array('class' => array('multichoice-alternative-weight')),
        '#default_value' => isset($this->node->alternatives[$i]['weight']) ? $this->node->alternatives[$i]['weight'] : $i,
      );
    }

    $form['alternatives']['multichoice_add_alternative'] = array(
      '#type' => 'button',
      '#value' => t('ADD'),
      '#limit_validation_errors' => array(),
      '#name' => 'add-alternative',
      '#ajax' => array(
        'method' => 'replace',
        'wrapper' => 'multichoice-alternatives-wrapper',
        'callback' => 'multichoice_add_alternative_ajax_callback',
      ),
      '#weight' => 20,
    );

    $form['#attached']['js'] = array(
      drupal_get_path('module', 'multichoice') . '/multichoice.js',
    );

    return $form;
  }

  /**
   * Implementation of validate
   *
   * QuizQuestion#validate()
   */
  public function validateNode(array &$form) {
    if ($this->node->choice_multi == 0) {
      $num_correct = 0;
      $filled_in = 0;
      $answer_weight = array();
      foreach($this->node->alternatives as $index => $short) {
        if (is_array($short)) {
          $weight = $short['weight'];
          if (drupal_strlen($this->checkMarkup($short, 'answer')) < 1) {
            $answer_weight[$weight] = '';
            continue;
          }
          $answer_weight[$weight] = $short['answer']['value'];
          $filled_in++;
          if ($short['correct'] == 1) {
            $num_correct++;
          }
        }
      }

      krsort($answer_weight);
      $has_answer_after = FALSE;

      foreach($answer_weight as $weight => $answer) {
        if ($answer) {
          $has_answer_after = TRUE;
        }
        if ($has_answer_after && !$answer) {
          form_set_error('alternatives', t('All answer choices (distractors) require an Answer. Please enter an Answer or click the Remove button to remove the answer choice (distractor).'));
        }
      }

      if (!$num_correct) {
        form_set_error('choice_multi', t('One correct answer must be selected. If all answer choices (distractors) are incorrect, check the Multiple correct answers box.'));
      }
      else if ($num_correct > 1 && $this->node->choice_multi == 0) {
        form_set_error('choice_multi', t('One correct answer must be selected. To select multiple correct answers, check the Multiple correct answers box.'));
      }
      if ($filled_in < self::PRC_MINIMUM_DISTRACTORS) {
        form_set_error('alternatives', t('At least two answer choices (distractors) are required.'));
      }
    }
  }

  /**
   * Run check_markup() on the field of the specified choice alternative
   * @param $alternativeIndex
   *  The index of the alternative in the alternatives array.
   * @param $field
   *  The name of the field we want to check markup on
   * @param $check_user_access
   *  Whether or not to check for user access to the filter we're trying to apply
   * @return HTML markup
   */
  private function checkMarkup($alternative, $field, $check_user_access = FALSE) {
    return check_markup($alternative[$field]['value'], $alternative[$field]['format']);
  }

  public function delete($only_this_version = FALSE) {
    // This is (hopefully) a temporary solution.
    // The multichoice object in this version of quiz can't delete itself
    // because it doesn't have a question_nid or question_vid column on
    // the results, and it tries to delete it based on that.
    $delete_properties = db_delete('quiz_multichoice_properties')->condition('nid', $this->node->nid);
    $delete_answers = db_delete('quiz_multichoice_answers')->condition('question_nid', $this->node->nid);

    if ($only_this_version) {
      $delete_properties->condition('vid', $this->node->vid);
      $delete_answers->condition('question_vid', $this->node->vid);
    }

    $delete_properties->execute();
    $delete_answers->execute();
  }


}
