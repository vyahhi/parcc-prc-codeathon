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
  $strongarm->name = 'field_bundle_settings_prc_trt__capacity_check';
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
      'school_readiness' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'devices_required' => array(
          'default' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'school_readiness' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'devices_capacity' => array(
          'default' => array(
            'weight' => '13',
            'visible' => TRUE,
          ),
          'school_readiness' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'bandwidth_capacity' => array(
          'default' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
          'school_readiness' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_prc_trt__capacity_check'] = $strongarm;

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
      'school_readiness' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'operating_system_pass' => array(
          'default' => array(
            'weight' => '5',
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
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'screen_resolution_pass' => array(
          'default' => array(
            'weight' => '22',
            'visible' => TRUE,
          ),
        ),
        'processor_pass' => array(
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
        ),
        'ram_pass' => array(
          'default' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
        ),
        'browser_pass' => array(
          'default' => array(
            'weight' => '13',
            'visible' => TRUE,
          ),
        ),
        'cookies_pass' => array(
          'default' => array(
            'weight' => '15',
            'visible' => TRUE,
          ),
        ),
        'javascript_pass' => array(
          'default' => array(
            'weight' => '17',
            'visible' => TRUE,
          ),
        ),
        'images_pass' => array(
          'default' => array(
            'weight' => '19',
            'visible' => TRUE,
          ),
        ),
        'overall_pass' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_prc_trt__system_check'] = $strongarm;

  return $export;
}
