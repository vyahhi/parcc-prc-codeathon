(function ($) {
    Drupal.prc_trt_system_check = {};
    Drupal.behaviors.check_system = {
        attach: function (context) {
            // If this runs, then we have Javascript support
            $('input[name="faux_javascript"]').val(true);
            var has_cookies = are_cookies_enabled();
            $('input[name="faux_cookies"]').val(has_cookies);

            // This will occasionally not return the right value on a first run but always seems to be correct on the second.
            imagesOn = (function () {
                var i = new Image();
                i.setAttribute('onload', "window.hasImages = true;window.setHasImageValue();");
                i.setAttribute('onerror', "window.hasImages = false;window.setHasImageValue();");
                i.src = '/sites/all/themes/prc_foundation/logo.png';
                return !!i.width
            })();

            $('input[name="faux_monitor_color_depth"]').val(screen.colorDepth);
            $('input[name="faux_screen_resolution_width"]').val(screen.width);
            $('input[name="faux_screen_resolution_height"]').val(screen.height);

            function are_cookies_enabled() {
                var cookieEnabled = (navigator.cookieEnabled) ? true : false;

                if (typeof navigator.cookieEnabled == "undefined" && !cookieEnabled) {
                    document.cookie = "testcookie";
                    cookieEnabled = (document.cookie.indexOf("testcookie") != -1) ? true : false;
                }
                return (cookieEnabled);
            }
        }
    };
})(jQuery);
window.setHasImageValue = function() {
    var setVal = !!window.hasImages;
    (jQuery)('input[name="faux_images"]').val(setVal);
}