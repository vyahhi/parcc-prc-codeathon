<?php
/**
 * @file
 * prc_poc_local_taxonomy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_taxonomy_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
