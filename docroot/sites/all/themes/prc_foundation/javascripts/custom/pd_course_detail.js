Drupal.behaviors.pdCourseBehavior = {
  attach: function (context, settings) {
    (function ($) {
      $('.node-type-pd-course').once(function() {
        var link_ul = $("ul.links");
        var new_ul = $('<ul class="links inline"></ul>');
        link_ul.children("li.prc_pd_course_add_to_favorites").appendTo(new_ul);
        link_ul.children("li.flag-like_content").appendTo(new_ul);
        link_ul.children("li.pinit").appendTo(new_ul);
        link_ul.children("li.sharethis").appendTo(new_ul);
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