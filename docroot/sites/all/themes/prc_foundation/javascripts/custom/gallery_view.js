Drupal.behaviors.galleryViewBehavior = {
  attach: function (context, settings) {
    (function ($) {
      // Enable cascading grid
      var $container = $('.view-content');
      $container.packery({
        itemSelector: '.columns'
      });
    }(jQuery));
  }
};