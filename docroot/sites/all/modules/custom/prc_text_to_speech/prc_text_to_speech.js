// (function ($) {
// Drupal.behaviors.interact = {
//   attach: function (context) {

      var TexthelpSpeechStream = new function () {};

      // Adding toolbar to the page
      TexthelpSpeechStream.g_bAdded = false;
      TexthelpSpeechStream.g_strDomain = "customerdemo.speechstream.net";

      TexthelpSpeechStream.addToolbar = function () {
        if (!TexthelpSpeechStream.g_bAdded) {
          var elem = document.createElement("script");
          elem.type = "text/javascript";
          elem.src = "//" + TexthelpSpeechStream.g_strDomain + "/SpeechStream/v195/texthelpMain.js";
          document.body.appendChild(elem);
          TexthelpSpeechStream.g_bAdded = true;
        }
      };

      /* Texthelp Systems, Inc. SpeechStream Toolbar Parameters */
      function $rw_userParameters() {
        try {
          /* +++ User customizable parameters start here. +++ */

          /*****************HIDE THE TOOLBAR***********************/
          // eba_no_display_icons = play_icon + clicktospeak_icon;  // This makes the features callable in a programmatic way without displaying a toolbar.
          // eba_icons = no_bar;                                    // Do not display a toolbar – uses public methods to control speech
          // eba_hidden_bar = true;
          // eba_hover_flag = true;
          //eba_initial_speech_on = true;                              // This determines if the toolbar is initially hidden when page loaded


          // eba_bubble_mode = true;
          // eba_bubble_freeze_on_shift_flag = true;
          // eba_continuous_reading = false;


          /*****************END HIDE THE TOOLBAR***********************/
          eba_icons = main_icons + selectspeed_icon + pause_icon;  // Display the icons
          eba_server = TexthelpSpeechStream.g_strDomain;
          eba_speech_server = "customerdemo.speechstream.net";
          eba_login_name = "breakthroughtechnologies";
          eba_cust_id = 2410;
          eba_use_html5 = true;
          eba_ssl_flag = window.location.protocol == "https:";
          eba_voice = "Vocalizer Expressive Ava Premium High 22kHz";
          eba_math = true;
          /////////////////////////////////////////
          //eba_initial_speech_on = true;
          //eba_hover_flag = true;
          //eba_translate_source = "English";
          //eba_translate_target = "French";

          //eba_bubble_mode = true;
          //eba_bubble_freeze_on_shift_flag = true;
          //eba_continuous_reading = false;
          /* +++ End of user customizable parameters section. +++ */
        }
        catch (err) {
        }
      }
//if (context.hasClass('texttospeech')) {
  TexthelpSpeechStream.addToolbar();
//}
//   }
//  }
//})(jQuery);

