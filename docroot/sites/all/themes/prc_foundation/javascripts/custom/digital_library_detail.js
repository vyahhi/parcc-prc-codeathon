Drupal.behaviors.digitalLibraryDetailBehavior = {
  attach: function (context, settings) {
    (function ($) {
      $('.node-type-digital-library-content').once(function(){
        // Move around fields that can't be easily handled by display suite
        $('.main').children().prependTo('.group-left');
        if ($('.field-name-field-thumbnail').length) {
          //console.log("Thumbnail");
          $('.pane-node-links').insertAfter('.field-name-field-thumbnail');
        }
        else {
          //console.log("No Thumbnail");
          $('.pane-node-links').prependTo('.group-right');
        }
        //$('.pane-node-links').insertAfter('.field-name-field-thumbnail');
        $('.prc_digital_library_comment_email').appendTo('.group-left');
        $('.prc_digital_library_comment_email').wrap('<ul></ul>');
        // Add label for share section
        $('<div class="field-label divider">Share&nbsp;<hr></div>').prependTo('.pane-node-links');
        // Re order node links for display
        var link_ul = $("ul.links");
        var new_ul = $('<ul class="links inline"></ul>');
        link_ul.children("li.prc_digital_library_add_to_favorites").appendTo(new_ul);
        link_ul.children("li.flag-like_content").appendTo(new_ul);
        link_ul.children("li.pinit").appendTo(new_ul);
        link_ul.children("li.sharethis").appendTo(new_ul);
        link_ul.children("li.texttospeech").appendTo(new_ul);
        $("ul.links").replaceWith(new_ul);
        // Remove extra text from flagged links
        if ($('.flag-wrapper a', this).hasClass('unflag-action')) {
          var link_text = $('.flag-wrapper a', this).text();
          link_text = link_text.replace("Undo ", "");
          $('.flag-wrapper a', this).text(link_text);
        }
        if ($('.flag-wrapper a', this).hasClass('flag-action')) {
          var link_text = $('.flag-wrapper a', this).text();
          link_text = link_text.replace("Like ", "");
          $('.flag-wrapper a', this).text(link_text);
        }
      });
      // Remove extra flag link text on ajax calls
      $( ".unflag-action" ).each(function() {
        var link_text = $(this).text();
        link_text = link_text.replace("Undo ", "");
        $(this).text(link_text);
      });
      $( ".flag-action" ).each(function() {
        var link_text = $(this).text();
        link_text = link_text.replace("Like ", "");
        $(this).text(link_text);
      });
    }(jQuery));
  }
};