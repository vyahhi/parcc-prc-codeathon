<?php
/**
 * @file
 * prc_poc_local_panels.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_poc_local_panels_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels" && $api == "pipelines") {
    return array("version" => "1");
  }
}
