<?php
/**
 * @file
 * prc_panels_extras.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_panels_extras_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}
