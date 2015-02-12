<?php
/**
 * @file
 * prc_poc_local_flag_like_content.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function prc_poc_local_flag_like_content_flag_default_flags() {
  $flags = array();
  // Exported flag: "Like Content".
  $flags['like_content'] = array(
    'entity_type' => 'node',
    'title' => 'Like Content',
    'global' => 0,
    'types' => array(
      0 => 'digital_library_content',
    ),
    'flag_short' => 'Like ([node:flag-like-content-count])',
    'flag_long' => 'Like this item',
    'flag_message' => 'You like this content.',
    'unflag_short' => 'Undo ([node:flag-like-content-count])',
    'unflag_long' => 'Unlike this item',
    'unflag_message' => 'You have unliked this content.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'gallery_view' => 'gallery_view',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'question' => 0,
      'token' => 0,
      'detail' => 0,
      'front_page_item' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'prc_poc_local_flag_like_content',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
