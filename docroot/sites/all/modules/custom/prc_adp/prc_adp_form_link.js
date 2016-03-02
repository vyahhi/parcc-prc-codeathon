
//

Drupal.behaviors.prc_adp = {
  attach : function(context, settings){
    (function ($) {
      $('.prc-adp-launch-test-link').click(
        function(event){
          event.preventDefault();
          $(event.target).closest('form').submit();
        });
    }(jQuery));
  }
}