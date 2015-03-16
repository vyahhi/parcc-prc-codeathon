<?php
/**
 * @file
 * prc_poc_local_panels.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function prc_poc_local_panels_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'add_system_check';
  $pm_existing_page->label = 'Add System Check';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'admin/structure/entity-type/prc_trt/system_check/add';
  $export['add_system_check'] = $pm_existing_page;

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'dlc_revisions_edit';
  $pm_existing_page->label = 'DLC Revisions Edit';
  $pm_existing_page->context = 'entity|node|nid';
  $pm_existing_page->paths = 'node/%node/revisions/%/edit';
  $export['dlc_revisions_edit'] = $pm_existing_page;

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'node_overview';
  $pm_existing_page->label = 'Node overview';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'node';
  $export['node_overview'] = $pm_existing_page;

  return $export;
}
