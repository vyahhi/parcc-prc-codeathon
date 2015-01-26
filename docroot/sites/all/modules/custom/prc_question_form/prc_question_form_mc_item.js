(function ($) {
    Drupal.behaviors.prc_question_mc_remove_item = {
        attach: function (context) {
            $('.item-mc-remove').click(function () {

                var my_row = $(this).parent().parent();
                my_row.find('textarea').val('');
                my_row.hide();
                event.stopPropagation();
                return false;
            });
        }
    };
})(jQuery);
