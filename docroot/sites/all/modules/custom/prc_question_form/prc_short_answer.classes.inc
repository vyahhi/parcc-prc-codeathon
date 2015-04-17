<?php

/**
 * The main classes for the PRC-specific short answer question type.
 *
 * These inherit or implement code found in quiz_question.classes.inc.
 *
 * @file
 * Question type, enabling the creation of multiple choice and multiple answer questions.
 */

/**
 * Extension of MultichoiceQuestion.
 */
class PRCShortAnswerQuestion extends ShortAnswerQuestion {

  /**
   * Implementation of delete
   *
   * @see QuizQuestion#delete($only_this_version)
   */
  public function delete($only_this_version = FALSE) {
    $delete_node = db_delete('quiz_short_answer_node_properties');
    $delete_node->condition('nid', $this->node->nid);

    if ($only_this_version) {
      $delete_node->condition('vid', $this->node->vid);
    }

    $delete_node->execute();
  }

}