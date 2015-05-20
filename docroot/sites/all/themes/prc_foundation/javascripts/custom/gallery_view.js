Drupal.behaviors.galleryViewBehavior = {
  attach: function (context, settings) {
    (function ($) {
      $('.filter-panel-toggle-link').once(function(){
        // Move search box to filter panel
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
          $('.filter-panel-toggle').show();
          $('#filter-panel-filters').slideToggle("slow");
          $(this).toggleClass("selected");
        });
        // Wrap the toggleable area of the filter panel for styling
        $('.filter-panel-toggle').wrapAll('<div id="filter-panel-filters">');
        // Check to see if the filter panel should be expanded upon load
        if(document.location.search.length) {
          // TODO - for completeness, it would also be nice to confirm that the query parameter is f[]
          $('.filter-panel-toggle').show();
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
        // Trigger sorting when sort controls are clicked
        $('#library-date-sort').click(function() {
          if ($('#library-date-sort').hasClass('active')) {
            if ($(this).hasClass('desc')) {
              $('#edit-sort-order option').filter(function() {
                return ($(this).text() == 'Asc');
              }).prop('selected', true).trigger('change');
            }
            else {
              $('#edit-sort-order option').filter(function() {
                return ($(this).text() == 'Desc');
              }).prop('selected', true).trigger('change');
            }
            $('#library-popularity-sort').removeClass('active');
            $(this).toggleClass('desc');
            $(this).toggleClass('asc');
          }
          else {
            $('#library-popularity-sort').removeClass('active asc desc')
            $(this).addClass('active desc');
            $('#edit-sort-by option').filter(function() {
              return ($(this).text() == 'Date');
            }).prop('selected', true);
            $('#edit-sort-order option').filter(function() {
              return ($(this).text() == 'Desc');
            }).prop('selected', true).trigger('change');
          }
        });
        $('#library-popularity-sort').click(function() {
          if ($('#library-popularity-sort').hasClass('active')) {
            if ($(this).hasClass('desc')) {
              $('#edit-sort-order option').filter(function() {
                return ($(this).text() == 'Asc');
              }).prop('selected', true).trigger('change');
            }
            else {
              $('#edit-sort-order option').filter(function() {
                return ($(this).text() == 'Desc');
              }).prop('selected', true).trigger('change');
            }
            $('#library-date-sort').removeClass('active');
            $(this).toggleClass('desc');
            $(this).toggleClass('asc');
          }
          else {
            $('#library-date-sort').removeClass('active asc desc')
            $(this).addClass('active desc');
            $('#edit-sort-by option').filter(function() {
              return ($(this).text() == 'Popularity');
            }).prop('selected', true);
            $('#edit-sort-order option').filter(function() {
              return ($(this).text() == 'Desc');
            }).prop('selected', true).trigger('change');
          }
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