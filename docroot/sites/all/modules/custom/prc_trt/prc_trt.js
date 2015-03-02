(function($) {
    Drupal.prc_trt_system_check = {};
    Drupal.behaviors.check_system = {
        attach : function(context) {
            // If this runs, then we have Javascript support
            $('#edit-faux-javascript').val(true);
            var has_cookies = are_cookies_enabled();
            $('#edit-faux-cookies').val(has_cookies);
            are_images_enabled();
            $('#edit-faux-monitor-color-depth').val(screen.colorDepth);
            $('#edit-faux-screen-resolution-width').val(screen.width);
            $('#edit-faux-screen-resolution-height').val(screen.height);

            function are_cookies_enabled()
            {
                var cookieEnabled = (navigator.cookieEnabled) ? true : false;

                if (typeof navigator.cookieEnabled == "undefined" && !cookieEnabled)
                {
                    document.cookie="testcookie";
                    cookieEnabled = (document.cookie.indexOf("testcookie") != -1) ? true : false;
                }
                return (cookieEnabled);
            }

            function are_images_enabled() {
                var img_src = '/misc/favicon.ico';
                var image = new Image();
                image.onload = function() {
                    if (image.width > 0) {
                        document.documentElement.className += (document.documentElement.className != '') ? ' images-on' : 'images-on';
                        $('#edit-faux-images').val(true);
                    }
                };
                image.src = img_src;
            }

        }
    };
})(jQuery);
