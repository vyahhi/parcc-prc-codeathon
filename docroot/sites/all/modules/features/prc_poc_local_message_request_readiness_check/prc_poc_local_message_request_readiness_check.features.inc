<?php
/**
 * @file
 * prc_poc_local_message_request_readiness_check.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_message_request_readiness_check_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function prc_poc_local_message_request_readiness_check_default_message_type() {
  $items = array();
  $items['request_readiness_check'] = entity_import('message_type', '{
    "name" : "request_readiness_check",
    "description" : "Request Readiness Check",
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
          "value" : "Subject goes here. For example: [message:field-node:title]: Please run readiness checks.",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003ESubject goes here. For example: [message:field-node:title]: Please run readiness checks.\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Message goes here explaining importance of running checks and how to run them, emphasizing that it is important that admins run the checks from the provided link or results won\\u0027t be saved or reported to District.\\r\\n[message:field-comment]\\r\\n[message:field-node:url]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EMessage goes here explaining importance of running checks and how to run them, emphasizing that it is important that admins run the checks from the provided link or results won\\u0027t be saved or reported to District.\\u003Cbr \\/\\u003E\\n[message:field-comment]\\u003Cbr \\/\\u003E\\n[message:field-node:url]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
