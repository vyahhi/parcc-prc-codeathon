Drupal.behaviors.galleryViewBehavior = {
  attach: function (context, settings) {
    (function ($) {
      $('.filter-panel-toggle-link').once(function(){
        // Move search box to filter panel
        $('.view-filters').appendTo('.filter-panel-search');
        $('input#edit-search-api-views-fulltext').attr('placeholder', 'Search Library');
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
          $('#filter-panel-filters').slideToggle("slow");
          $(this).toggleClass("selected");
        });
        // Wrap the toggleable area of the filter panel for styling
        $('.filter-panel-toggle').wrapAll('<div id="filter-panel-filters" class="arrow-box">');
        // Check to see if the filter panel should be expanded upon load
        if(document.location.search.length) {
          // TODO - for completeness, it would also be nice to confirm that the query parameter is f[]
          $('#filter-panel-filters').show();
          $(".filter-panel-toggle-link").toggleClass('filters-enabled');
        }
        // Turn selected filters into links
        $('input[checked]').parent().wrap('<a>');
        $('input[checked]').parents('a').addClass('filter-selected');
        $('.filter-selected').click(function() {
          Drupal.facetapi.disableFacet($(this).parents('ul.facetapi-facetapi-checkbox-links'));
          href = $(this).find('a').attr('href'),
            redirect = new Drupal.facetapi.Redirect(href);
          redirect.gotoHref();
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