<?php
/**
 * @file
 * prc_poc_local_search_api.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_search_api_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@digital_library_content_index';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@digital_library_content_index'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@digital_library_only';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@digital_library_only'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@standards_flipbook';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@standards_flipbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_extracting_servlet_path';
  $strongarm->value = 'update/extract';
  $export['search_api_attachments_extracting_servlet_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_extract_using';
  $strongarm->value = 'tika';
  $export['search_api_attachments_extract_using'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_tika_jar';
  $strongarm->value = 'tika-app-1.7.jar';
  $export['search_api_attachments_tika_jar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_attachments_tika_path';
  $strongarm->value = 'sites/all/libraries/tika';
  $export['search_api_attachments_tika_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_facets_search_ids';
  $strongarm->value = array(
    'digital_library_content_index' => array(
      'search_api_views:search_digital_library_content:panel_pane_1' => 'search_api_views:search_digital_library_content:panel_pane_1',
      'search_api_views:search_digital_library_content:default' => 'search_api_views:search_digital_library_content:default',
      'search_api_views:search_digital_library_content:page' => 'search_api_views:search_digital_library_content:page',
      'search_api_views:test_search_two:default' => 'search_api_views:test_search_two:default',
      'search_api_views:test_search_two:panel_pane_1' => 'search_api_views:test_search_two:panel_pane_1',
    ),
    'digital_library_only' => array(
      'search_api_views:digital_library_gallery:default' => 'search_api_views:digital_library_gallery:default',
      'search_api_views:digital_library_gallery:panel_pane_1' => 'search_api_views:digital_library_gallery:panel_pane_1',
      'search_api_views:lesson_plan_gallery:panel_pane_1' => 'search_api_views:lesson_plan_gallery:panel_pane_1',
    ),
    'standards_flipbook' => array(
      'search_api_views:standards_flipbook_results:default' => 'search_api_views:standards_flipbook_results:default',
      'search_api_views:standards_flipbook_results:panel_pane_1' => 'search_api_views:standards_flipbook_results:panel_pane_1',
      'search_api_views:standards_flipbook_standard_detail:default' => 'search_api_views:standards_flipbook_standard_detail:default',
      'search_api_views:standards_flipbook_standard_detail:panel_pane_1' => 'search_api_views:standards_flipbook_standard_detail:panel_pane_1',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  return $export;
}
