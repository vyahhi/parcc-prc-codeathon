Drupal.behaviors.digitalLibraryDetailBehavior = {
  attach: function (context, settings) {
    (function ($) {
      $('.node-type-digital-library-content').once(function(){
        // Move around fields that can't be easily handled by display suite
        $('.main').children().prependTo('.group-left');
        $('.pane-node-links').appendTo('.group-right');
        $('.prc_digital_library_comment_email').appendTo('.group-left');
        $('.prc_digital_library_comment_email').wrap('<ul></ul>');
      });
    }(jQuery));
  }
};