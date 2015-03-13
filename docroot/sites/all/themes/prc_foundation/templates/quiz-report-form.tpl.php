<?php
/**
 * @file
 * Themes the question report
 *
 */
/*
 * Available variables:
 * $form - FAPI array
 *
 * All questions are in form[x] where x is an integer.
 * Useful values:
 * $form[x]['question'] - the question as a FAPI array(usually a form field of type "markup")
 * $form[x]['score'] - the users score on the current question.(FAPI array usually of type "markup" or "textfield")
 * $form[x]['max_score'] - the max score for the current question.(FAPI array of type "value")
 * $form[x]['response'] - the users response, usually a FAPI array of type markup.
 */
?>
<div class="quiz-report">

  Score: <?php print $form[0]['score']['#value'] ?>.<br/>

  <?php if ((int)$form[0]['score']['#value'] >= (int)$form[0]['passing_grade']['#value']) : ?>
    Congratulations! You successfully passed the <?php print $form[0]['quiz_title']['#value'] ?> exam.
  <?php else: ?>
    Sorry. You did not reach the required score to pass the <?php print $form[0]['quiz_title']['#value'] ?> exam. Please try again later.<br/>
    You may revisit the course modules and retake the course exam when ready.
  <?php endif; ?>

  <br/>

  <?php print drupal_render($form['go_back']); ?>

</div>
