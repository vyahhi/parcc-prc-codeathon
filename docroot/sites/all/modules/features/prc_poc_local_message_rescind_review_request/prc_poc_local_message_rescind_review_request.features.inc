<?php
/**
 * @file
 * prc_poc_local_message_rescind_review_request.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_message_rescind_review_request_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function prc_poc_local_message_rescind_review_request_default_message_type() {
  $items = array();
  $items['rescind_review_request'] = entity_import('message_type', '{
    "name" : "rescind_review_request",
    "description" : "Rescind Review Request",
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
          "value" : "[message:field-node:title] Has Been Withdrawn From Review",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:field-node:title] Has Been Withdrawn From Review\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "The following content has been withdrawn from review.\\r\\nContent: \\u003Ca href=\\u0022[message:field-node:edit-url]\\u0022\\u003E\\u0027[message:field-node:title]\\u0027 ([message:field-node:nid])\\u003C\\/a\\u003E\\r\\nDate: [message:timestamp:long]\\r\\nBy: [message:field-node:author:field-first-name] [message:field-node:author:field-last-name] ([message:field-node:author:mail])\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EThe following content has been withdrawn from review.\\u003Cbr \\/\\u003E\\nContent: \\u003Ca href=\\u0022[message:field-node:edit-url]\\u0022\\u003E\\u0027[message:field-node:title]\\u0027 ([message:field-node:nid])\\u003C\\/a\\u003E\\u003Cbr \\/\\u003E\\nDate: [message:timestamp:long]\\u003Cbr \\/\\u003E\\nBy: [message:field-node:author:field-first-name] [message:field-node:author:field-last-name] ([message:field-node:author:mail])\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
