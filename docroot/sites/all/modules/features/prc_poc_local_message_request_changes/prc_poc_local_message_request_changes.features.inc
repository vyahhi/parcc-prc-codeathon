<?php
/**
 * @file
 * prc_poc_local_message_request_changes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_message_request_changes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function prc_poc_local_message_request_changes_default_message_type() {
  $items = array();
  $items['request_changes'] = entity_import('message_type', '{
    "name" : "request_changes",
    "description" : "Request Changes",
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
          "value" : "Changes before Approval for [message:field-node:title]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EChanges before Approval for [message:field-node:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "A curator has provided feedback for content you\\u0027ve submitted for approval:\\r\\nContent: \\u003Ca href=\\u0022[message:field-node:edit-url]\\u0022\\u003E\\u0027[message:field-node:title]\\u0027 ([message:field-node:nid])\\u003C\\/a\\u003E\\r\\nDate: [message:timestamp:long]\\r\\nContent Administrator: [message:field-user-ref:field-first-name] [message:field-user-ref:field_last_name] ([message:field-user-ref:mail])\\r\\n\\r\\nComment: [message:field-node:workflow-comments]\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EA curator has provided feedback for content you\\u0027ve submitted for approval:\\u003Cbr \\/\\u003E\\nContent: \\u003Ca href=\\u0022[message:field-node:edit-url]\\u0022\\u003E\\u0027[message:field-node:title]\\u0027 ([message:field-node:nid])\\u003C\\/a\\u003E\\u003Cbr \\/\\u003E\\nDate: [message:timestamp:long]\\u003Cbr \\/\\u003E\\nContent Administrator: [message:field-user-ref:field-first-name] [message:field-user-ref:field_last_name] ([message:field-user-ref:mail])\\u003C\\/p\\u003E\\n\\u003Cp\\u003EComment: [message:field-node:workflow-comments]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
