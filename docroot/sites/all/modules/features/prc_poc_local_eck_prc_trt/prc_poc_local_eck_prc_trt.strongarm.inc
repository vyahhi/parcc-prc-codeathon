<?php
/**
 * @file
 * prc_poc_local_eck_prc_trt.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_poc_local_eck_prc_trt_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_prc_trt__system_check';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'operating_system_pass' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'monitor_size_pass' => array(
          'default' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
        ),
        'monitor_color_depth_pass' => array(
          'default' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
        ),
        'screen_resolution_pass' => array(
          'default' => array(
            'weight' => '23',
            'visible' => TRUE,
          ),
        ),
        'processor_pass' => array(
          'default' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
        ),
        'ram_pass' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'browser_pass' => array(
          'default' => array(
            'weight' => '14',
            'visible' => TRUE,
          ),
        ),
        'cookies_pass' => array(
          'default' => array(
            'weight' => '16',
            'visible' => TRUE,
          ),
        ),
        'javascript_pass' => array(
          'default' => array(
            'weight' => '18',
            'visible' => TRUE,
          ),
        ),
        'images_pass' => array(
          'default' => array(
            'weight' => '20',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_prc_trt__system_check'] = $strongarm;

  return $export;
}
