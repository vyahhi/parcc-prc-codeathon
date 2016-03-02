Drupal.behaviors.libraryGalleryViewBehavior = {
  attach: function (context, settings) {
    (function ($) {
      $('.filter-panel-toggle-link').once(function(){
        // Move search box to filter panel
        $('input#edit-search-api-views-fulltext').attr('placeholder', 'Search Library');
        // Make filter panel expandable and collapsable
        $( ".filter-panel-toggle-link" ).click(function(event) {
          event.preventDefault();
          $('.filter-panel-toggle').show();
          $('#filter-panel-filters').slideToggle("slow");
          $(this).toggleClass("selected");
        });
        // Wrap the toggleable area of the filter panel for styling
        $('.filter-panel-toggle').wrapAll('<div id="filter-panel-filters">');
        // Check to see if the filter panel should be expanded upon load
        if (queryParamExists("f[0]")) {
          $('.filter-panel-toggle').show();
          $('#filter-panel-filters').show();
          $(".filter-panel-toggle-link").toggleClass('filters-enabled');
        }
        // Turn selected filters into links
        $('input[checked]').parent().wrap('<a>');
        $('input[checked]').parents('a').addClass('filter-selected');
        $('.facetapi-facet-prc-favorites-listings a.facetapi-active').parent().wrap('<a>');
        $('.facetapi-facet-prc-favorites-listings a.facetapi-active').parents('a').addClass('filter-selected');
        // Remove (-) link text for lists on ajax calls
        $('.facetapi-facet-prc-favorites-listings .filter-selected li').each(function() {
          var link_text = $(this).text();
          var invisible_text = $(this).find('span').text();
          link_text.replace("(-) ", "").replace(invisible_text, "");
          // Todo - replace span for accessibility reasons
          $(this).find('a').text('');
        });
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
    }(jQuery));
  }
};
