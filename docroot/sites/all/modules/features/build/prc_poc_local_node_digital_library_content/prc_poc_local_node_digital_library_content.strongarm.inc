<?php
/**
 * @file
 * prc_poc_local_node_digital_library_content.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_node_digital_library_content_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__digital_library_content';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'front_page_item' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'digital_library_item' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'sharethis' => array(
          'default' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
          'digital_library_item' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
        ),
        'field_author_name' => array(
          'teaser' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'search_result' => NULL,
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__digital_library_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_digital_library_content';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_digital_library_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_digital_library_content';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_digital_library_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_digital_library_content';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_digital_library_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_digital_library_content';
  $strongarm->value = '1';
  $export['node_preview_digital_library_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_digital_library_content';
  $strongarm->value = 1;
  $export['node_submitted_digital_library_content'] = $strongarm;

  return $export;
}
