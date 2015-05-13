Drupal.behaviors.galleryViewBehavior = {
  attach: function (context, settings) {
    (function ($) {
      $('.filter-panel-toggle-link').once(function(){
        // Move search box to filter panel
        $('.view-filters').appendTo('.filter-panel-search');
        // Remove extra text from flagged links
        $('.view-content .gallery-tiles .columns').each(function( index ) {
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
        // Make filter panel expandable and collapsable
        $( ".filter-panel-toggle-link" ).click(function() {
          // TODO - adjust this to toggle the parent so the animation can be smoother.
          $('.filter-panel-toggle').toggle("slow");
        });
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
      // Enable cascading grid
      var $container = $('.view-content .gallery-tiles');
      $container.packery({
        itemSelector: '.columns'
      });
    }(jQuery));
  }
};