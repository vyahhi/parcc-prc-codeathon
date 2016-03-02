<?php
/**
 * @file
 * prc_poc_local_node_pd_course.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_node_pd_course_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__pd_course';
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
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'question' => array(
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
      'gallery_view' => array(
        'custom_settings' => FALSE,
      ),
      'detail' => array(
        'custom_settings' => FALSE,
      ),
      'external_course' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'course' => array(
          'weight' => '9',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(
        'course' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'search_index' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'external_course' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'course_messages' => array(
          'default' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'search_index' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'external_course' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
        ),
        'sharethis' => array(
          'default' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'search_index' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'external_course' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__pd_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_pd_course';
  $strongarm->value = array();
  $export['menu_options_pd_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_pd_course';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_pd_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_pd_course';
  $strongarm->value = array();
  $export['node_options_pd_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_pd_course';
  $strongarm->value = '0';
  $export['node_preview_pd_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_pd_course';
  $strongarm->value = 0;
  $export['node_submitted_pd_course'] = $strongarm;

  return $export;
}
