<?php
/**
 * @file
 * prc_poc_local_flag_file_uploaded.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function prc_poc_local_flag_file_uploaded_flag_default_flags() {
  $flags = array();
  // Exported flag: "File Uploaded".
  $flags['file_uploaded'] = array(
    'entity_type' => 'node',
    'title' => 'File Uploaded',
    'global' => 1,
    'types' => array(
      0 => 'district',
    ),
    'flag_short' => 'Flag this item',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'question' => 0,
      'token' => 0,
      'detail' => 0,
      'front_page_item' => 0,
      'gallery_view' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'prc_poc_local_flag_file_uploaded',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
