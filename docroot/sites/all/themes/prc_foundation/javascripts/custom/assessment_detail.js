Drupal.behaviors.digitalLibraryDetailBehavior = {
  attach: function (context, settings) {
    (function ($) {
      $('#prc-question-preview-quiz-questions-form input#edit-submit').once().attr('disabled', 'true');

      Drupal.tableDrag.prototype.onDrop = function(){
        $('#prc-question-preview-quiz-questions-form input#edit-submit').removeAttr('disabled');
      }

      $('.form-type-checkbox input').click(function(){
        $('#prc-question-preview-quiz-questions-form input#edit-submit').removeAttr('disabled');
      });

    }(jQuery));
  }
}