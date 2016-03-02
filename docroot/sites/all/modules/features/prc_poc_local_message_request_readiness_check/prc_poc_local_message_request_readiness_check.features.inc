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
          "value" : "PARCC Assessments Technology Readiness Tool",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EPARCC Assessments Technology Readiness Tool\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Your PRC district admin has requested that you run system and\\/or testing capacity checks for your school. Please login to the PRC and run new or update your school testing capacity and\\/or system checks for this school year. \\r\\n\\r\\nThank you.\\r\\n[message:field-comment]\\r\\n[message:field-node:url]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EYour PRC district admin has requested that you run system and\\/or testing capacity checks for your school. Please login to the PRC and run new or update your school testing capacity and\\/or system checks for this school year. \\u003C\\/p\\u003E\\n\\u003Cp\\u003EThank you.\\u003Cbr \\/\\u003E\\n[message:field-comment]\\u003Cbr \\/\\u003E\\n[message:field-node:url]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
