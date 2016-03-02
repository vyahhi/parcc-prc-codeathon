Drupal.behaviors.searchContentBehavior = {
  attach: function (context, settings) {
    (function ($) {
      $('.filter-panel-toggle-link').once(function() {
        // Add a wrapper around the filter categories so we can expand/collapse them
        $('.panel-col-first .panel-pane.pane-block').wrapAll('<div id="filters"></div>');
        // On mobile or tablet collapse the filters by default if no filters have been applied.
        var width = $(window).width();
        $('#filters').once(function() {
          if (width < 1025 && !queryParamExists("f[0]")) {
            $('#filters').hide();
            $(".filter-panel-toggle-link").toggleClass('filters-enabled');
          }
        });
        // Add expand/collapse to the filter sidebar content
        $('.panel-col-first .filter-panel-toggle-link').click(function(event) {
          event.preventDefault();
          $('#filters').slideToggle("slow");
          $(this).toggleClass('expanded');
          $(".filter-panel-toggle-link").toggleClass('filters-enabled');
        });
        // Turn selected filters into links
        $('.facetapi-active').parent().wrap('<a>');
        $('.facetapi-active').parents('a').addClass('filter-selected');
        $('.filter-selected').click(function() {
          Drupal.facetapi.disableFacet($(this).parents('ul.facetapi-facetapi-links'));
          href = $(this).find('a').attr('href'),
            redirect = new Drupal.facetapi.Redirect(href);
          redirect.gotoHref();
        });
        // Trigger sorting when sort controls are clicked
        $('#search-date-sort').click(function() {
          if ($('#search-date-sort').hasClass('active')) {
            console.log("Clicked");
            if ($(this).hasClass('desc')) {
              console.log("Desc");
              $('#edit-sort-order option').filter(function() {
                return ($(this).text() == 'Asc');
              }).prop('selected', true).trigger('change');
            }
            else {
              $('#edit-sort-order option').filter(function() {
                return ($(this).text() == 'Desc');
              }).prop('selected', true).trigger('change');
            }
            $(this).toggleClass('desc');
            $(this).toggleClass('asc');
          }
        });
      });
    }(jQuery));
  }
};