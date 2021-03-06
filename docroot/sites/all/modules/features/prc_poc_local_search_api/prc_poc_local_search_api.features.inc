<?php
/**
 * @file
 * prc_poc_local_search_api.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_search_api_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function prc_poc_local_search_api_default_search_api_index() {
  $items = array();
  $items['digital_library_content_index'] = entity_import('search_api_index', '{
    "name" : "Digital Library Content Index",
    "machine_name" : "digital_library_content_index",
    "description" : null,
    "server" : "database_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "attachments_field_document" : { "type" : "text" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "favored_by" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "field_author_name" : { "type" : "string" },
        "field_course_objectives" : { "type" : "text" },
        "field_document:file" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" },
        "field_genre" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_media_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_permissions" : { "type" : "string" },
        "field_standard" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_subject" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "digital_library_content" : "digital_library_content",
              "pd_course" : "pd_course",
              "quiz" : "quiz"
            }
          }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv" }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_grade_level_unlimited" : true,
              "field_subject" : true,
              "field_author_name" : true,
              "field_genre" : true,
              "field_tags" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_author_name" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_author_name" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['digital_library_only'] = entity_import('search_api_index', '{
    "name" : "Digital Library Only",
    "machine_name" : "digital_library_only",
    "description" : null,
    "server" : "database_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "attachments_field_document" : { "type" : "text" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "favored_by" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "field_grade_level_unlimited" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_media_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_subject" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "flag_like_content_count" : { "type" : "integer" },
        "prc_favorites_listings" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "digital_library_content" : "digital_library_content" }
          }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv" }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_subject:parents_all" : "field_subject:parents_all" } }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "body:value" : true, "body:summary" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "body:value" : true, "body:summary" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "body:value" : true, "body:summary" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "body:value" : true, "body:summary" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function prc_poc_local_search_api_default_search_api_server() {
  $items = array();
  $items['database_server'] = entity_import('search_api_server', '{
    "name" : "Database server",
    "machine_name" : "database_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : 1,
      "partial_matches" : 0,
      "indexes" : {
        "digital_library_content_index" : {
          "title" : {
            "table" : "search_api_db_digital_library_content_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_subject" : {
            "table" : "search_api_db_digital_library_content_index_field_subject",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_genre" : {
            "table" : "search_api_db_digital_library_content_index",
            "column" : "field_genre",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_author_name" : {
            "table" : "search_api_db_digital_library_content_index",
            "type" : "string",
            "boost" : "1.0",
            "column" : "field_author_name"
          },
          "field_media_type" : {
            "table" : "search_api_db_digital_library_content_index",
            "column" : "field_media_type",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_permissions" : {
            "table" : "search_api_db_digital_library_content_index",
            "column" : "field_permissions",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_standard" : {
            "table" : "search_api_db_digital_library_content_index_field_standard",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_digital_library_content_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_digital_library_content_index",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_digital_library_content_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_digital_library_content_index_search_api_access_",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_digital_library_content_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_digital_library_content_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_tags" : {
            "table" : "search_api_db_digital_library_content_index_field_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_tags:name" : {
            "table" : "search_api_db_digital_library_content_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_digital_library_content_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "body:summary" : {
            "table" : "search_api_db_digital_library_content_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_course_objectives" : {
            "table" : "search_api_db_digital_library_content_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_document:file" : {
            "table" : "search_api_db_digital_library_content_index_field_document_fil",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "attachments_field_document" : {
            "table" : "search_api_db_digital_library_content_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "favored_by" : {
            "table" : "search_api_db_digital_library_content_index_favored_by",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          }
        },
        "digital_library_only" : {
          "field_media_type" : {
            "table" : "search_api_db_digital_library_only",
            "column" : "field_media_type",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_digital_library_only",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_digital_library_only_text",
            "type" : "text",
            "boost" : "1.0",
            "column" : "body_value"
          },
          "body:summary" : {
            "table" : "search_api_db_digital_library_only_text",
            "type" : "text",
            "boost" : "1.0",
            "column" : "body_summary"
          },
          "status" : {
            "table" : "search_api_db_digital_library_only",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_digital_library_only",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_digital_library_only_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "attachments_field_document" : {
            "table" : "search_api_db_digital_library_only_text",
            "type" : "text",
            "boost" : "1.0",
            "column" : "attachments_field_document"
          },
          "field_subject" : {
            "table" : "search_api_db_digital_library_only_field_subject",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_digital_library_only_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_digital_library_only",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "flag_like_content_count" : {
            "table" : "search_api_db_digital_library_only",
            "column" : "flag_like_content_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_grade_level_unlimited" : {
            "table" : "search_api_db_digital_library_only_field_grade_level_unlimited",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_tags:name" : {
            "table" : "search_api_db_digital_library_only_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "prc_favorites_listings" : {
            "table" : "search_api_db_digital_library_only_prc_favorites_listings",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "favored_by" : {
            "table" : "search_api_db_digital_library_only_favored_by",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
