Drupal.behaviors.galleryViewBehavior = {
  attach: function (context, settings) {
    (function ($) {
      // Initialize flexible grid
      var $container = $('.view-content .gallery-tiles');
      $container.packery({
        itemSelector: '.columns'
      });
      // Only reliable way to prevent tiles from overlapping appears to be
      // delaying enabling flexible grid until images have loaded
      // Refresh grid when all images have been loaded.
      $(window).load(function() {
        $container.packery();
      });
      // Refresh grid for every AJAX request (especially sort)
      $container.packery();
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