(function($) {
  Drupal.test_assembly_edit_protection = {};
  var click = false; // Allow Submit/Edit button
  var edit = false; // Dirty form flag
  Drupal.behaviors.testAssemblyEditProtection = {
    attach : function(context) {
      var form_id = '#prc-question-preview-quiz-questions-form';

      // If they leave an input field, assume they changed it.
      $(form_id + " :input").each(function() {
        $(this).blur(function() {
          edit = true;
        });
        $(this).focus(function() {
          edit = true;
        });
        $(this).change(function() {
          edit = true;
        });
      });

      // Change the table row drag drop
      Drupal.theme.prototype.tableDragChangedWarning = function() {
        edit = true;
        return '<div class="tabledrag-changed-warning messages warning">' + Drupal.theme('tableDragChangedMarker') + ' ' + Drupal.t('Changes made in this table will not be saved until the form is submitted.') + '</div>';
      };

      // Let all form submit buttons through
      $(form_id + " input[type='submit']").each(function() {
        $(this).addClass('edit-protection-processed');
        $(this).click(function() {
          click = true;
        });
      });

      // Catch all links and buttons EXCEPT for "#" links
      $("a, button, input[type='submit']:not(.edit-protection-processed)")
          .each(function() {
            $(this).click(function() {
              // return when a "#" link is clicked so as to skip the
              // window.onbeforeunload function
              if (edit && $(this).attr("href") != "#") {
                return 0;
              }
            });
          });

      // Handle backbutton, exit etc.
      window.onbeforeunload = function() {
        // Add CKEditor support
        if (typeof (CKEDITOR) != 'undefined' && typeof (CKEDITOR.instances) != 'undefined') {
          for ( var i in CKEDITOR.instances) {
            if (CKEDITOR.instances[i].checkDirty()) {
              edit = true;
              break;
            }
          }
        }
        if (edit && !click) {
          click = false;
          return (Drupal.t("You will lose all unsaved work."));
        }
      }
    }
  };
})(jQuery);
