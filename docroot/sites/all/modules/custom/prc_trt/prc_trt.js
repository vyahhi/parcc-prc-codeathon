(function ($) {
    Drupal.prc_trt_system_check = {};
    Drupal.behaviors.check_system = {
        attach: function (context) {
            // If this runs, then we have Javascript support
            $('input[name="faux_javascript"]').val(true);
            var has_cookies = are_cookies_enabled();
            $('input[name="faux_cookies"]').val(has_cookies);
            are_images_enabled();
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

            function are_images_enabled() {
                var img_src = '/misc/favicon.ico';
                var image = new Image();
                image.onload = function () {
                    if (image.width > 0) {
                        $('input[name="faux_images"]').val(true);
                    }
                };
                image.src = img_src;
            }

        }
    };
})(jQuery);
