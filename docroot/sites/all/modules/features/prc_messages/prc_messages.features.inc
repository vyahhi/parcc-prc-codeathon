<?php
/**
 * @file
 * prc_messages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_messages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function prc_messages_default_message_type() {
  $items = array();
  $items['comment_email'] = entity_import('message_type', '{
    "name" : "comment_email",
    "description" : "Comment Email",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "User\\u0027s Comment to Content \\u0027[message:field-node:title]\\u0027",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EUser\\u0027s Comment to Content \\u0027[message:field-node:title]\\u0027\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "A user commented on a content you provided (or updated).\\r\\nContent: \\u0027[message:field-node:title]\\u0027 ([message:field-node:nid])\\r\\nComment Date: [message:timestamp:long]\\r\\nComment By: [message:field-user-ref:field-first-name] [message:field-user-ref:field-last-name] ([message:field-user-ref:mail])\\r\\nComment: \\u0027[message:field-comment]\\u0027",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EA user commented on a content you provided (or updated).\\u003Cbr \\/\\u003E\\nContent: \\u0027[message:field-node:title]\\u0027 ([message:field-node:nid])\\u003Cbr \\/\\u003E\\nComment Date: [message:timestamp:long]\\u003Cbr \\/\\u003E\\nComment By: [message:field-user-ref:field-first-name] [message:field-user-ref:field-last-name] ([message:field-user-ref:mail])\\u003Cbr \\/\\u003E\\nComment: \\u0027[message:field-comment]\\u0027\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
