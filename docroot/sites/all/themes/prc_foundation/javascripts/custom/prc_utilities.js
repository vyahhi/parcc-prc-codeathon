/**
 * Determine if a specific parameter exists in the query string
 */
function queryParamExists(variable)
{
  var query = window.location.search.substring(1);
  var vars = query.split("&");
  for (var i=0;i<vars.length;i++) {
    var pair = vars[i].split("=");
    if(pair[0] == variable) {
      return(true);
    }
  }
  return(false);
}

jQuery( document ).ready(function() {
  jQuery('.collapsible tr:last-child').toggle();
  jQuery('.collapsible th').prepend('<span>&#9654;</span><span>&#9660;</span>&nbsp;');
  jQuery('.collapsible th span:last-child').toggle();
  jQuery('.collapsible tr:first-child').click(function() {
    jQuery(this).parent().find('tr:last-child').toggle();
    jQuery(this).parent().find('th span').toggle();
  })
});

