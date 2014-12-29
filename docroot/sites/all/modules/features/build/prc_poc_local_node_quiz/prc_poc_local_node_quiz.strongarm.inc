<?php
/**
 * @file
 * prc_poc_local_node_quiz.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_node_quiz_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__quiz';
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
        'custom_settings' => FALSE,
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
      'gallery_view' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'detail' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'taking' => array(
          'weight' => '0',
        ),
        'quiz_availability' => array(
          'weight' => '0',
        ),
        'summaryoptions' => array(
          'weight' => '0',
        ),
        'resultoptions' => array(
          'weight' => '0',
        ),
        'remember_settings' => array(
          'weight' => '0',
        ),
        'remember_global' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'take' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'detail' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
        ),
        'stats' => array(
          'default' => array(
            'weight' => '9',
            'visible' => TRUE,
          ),
          'detail' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
        ),
        'sharethis' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'detail' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_quiz';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_quiz';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_quiz';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_quiz';
  $strongarm->value = '1';
  $export['node_preview_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_quiz';
  $strongarm->value = 1;
  $export['node_submitted_quiz'] = $strongarm;

  return $export;
}
