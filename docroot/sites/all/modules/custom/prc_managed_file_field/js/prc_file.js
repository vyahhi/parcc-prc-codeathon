/**
 * @file
 * Improvements to Drupal core file upload widget.
 */

(function ($) {
  /**
   * Attach behaviors to managed file element upload fields.
   */
  Drupal.behaviors.prcFileValidateAutoAttach = {
    attach: function (context, settings) {
      $('.prc-file-managed', context).once(function () {
        var element_id = this.id;
        var seen_id = element_id.match(/--[0-9]$/);
        if (seen_id) {
          // Bind the Drupal.file change event to this element
          seen_id = seen_id.shift();
          var field_file_id = '#' + element_id.substring((element_id.length - seen_id.length), -(seen_id.length));
          $(this).bind('change', {extensions: Drupal.settings.file.elements[field_file_id]}, Drupal.file.validateExtension);

          // Add class to node form messages so validateExtension can replace it.
          var message_selector = 'form.node-form .messages';
          if ($(message_selector).length > 0) {
            $(message_selector).addClass('file-upload-js-error');
          }
        }
      });
    }
  }
})(jQuery);
