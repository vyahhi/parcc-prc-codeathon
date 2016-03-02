Drupal.behaviors.resourceTableBehavior = {
  attach: function (context, settings) {
    (function ($) {
      // Resolve reset button AJAX bug as outlined in:
      // https://www.drupal.org/node/1109980#comment-8613897
        $(document).delegate('.views-reset-button .form-submit', 'click', function (event) {
          $('form').each(function () {
            $('form select option').removeAttr('selected');
            $('form input[type=text]').attr('value', '');
            this.reset();
          });
          window.location = window.location.href.split('?')[0];
          return false;
        });
    }(jQuery));
  }
};