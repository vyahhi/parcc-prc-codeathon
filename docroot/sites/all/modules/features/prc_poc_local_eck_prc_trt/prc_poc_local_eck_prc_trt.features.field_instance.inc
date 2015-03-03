<?php
/**
 * @file
 * prc_poc_local_eck_prc_trt.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function prc_poc_local_eck_prc_trt_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'prc_trt-system_check-field_browser'
  $field_instances['prc_trt-system_check-field_browser'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_browser',
    'label' => 'Browser',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_browser_cookies_enabled'
  $field_instances['prc_trt-system_check-field_browser_cookies_enabled'] = array(
    'bundle' => 'system_check',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_browser_cookies_enabled',
    'label' => 'Browser: Cookies enabled',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
        'label_help_description' => '',
      ),
      'type' => 'options_onoff',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_browser_images_enabled'
  $field_instances['prc_trt-system_check-field_browser_images_enabled'] = array(
    'bundle' => 'system_check',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_browser_images_enabled',
    'label' => 'Browser: Images enabled',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
        'label_help_description' => '',
      ),
      'type' => 'options_onoff',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_browser_javascript_enabled'
  $field_instances['prc_trt-system_check-field_browser_javascript_enabled'] = array(
    'bundle' => 'system_check',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_browser_javascript_enabled',
    'label' => 'Browser: JavaScript enabled',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
        'label_help_description' => '',
      ),
      'type' => 'options_onoff',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_browser_version'
  $field_instances['prc_trt-system_check-field_browser_version'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_browser_version',
    'label' => 'Browser Version',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'label_help_description' => '',
      ),
      'type' => 'number',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_device_type'
  $field_instances['prc_trt-system_check-field_device_type'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_device_type',
    'label' => 'Device type',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'label_help_description' => '',
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_monitor_color_depth'
  $field_instances['prc_trt-system_check-field_monitor_color_depth'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_monitor_color_depth',
    'label' => 'Monitor color depth',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_monitor_size'
  $field_instances['prc_trt-system_check-field_monitor_size'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_monitor_size',
    'label' => 'Monitor size (in inches)',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_name'
  $field_instances['prc_trt-system_check-field_name'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a name to describe the lab or device(s) you are testing.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_name',
    'label' => 'System check name',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_number_of_devices'
  $field_instances['prc_trt-system_check-field_number_of_devices'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the number of devices with the same configuration to include in test results.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_number_of_devices',
    'label' => 'Number of devices',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'label_help_description' => '',
      ),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_operating_system'
  $field_instances['prc_trt-system_check-field_operating_system'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_operating_system',
    'label' => 'Operating system',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'label_help_description' => '',
      ),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_processor_speed'
  $field_instances['prc_trt-system_check-field_processor_speed'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_processor_speed',
    'label' => 'Processor speed',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_ram'
  $field_instances['prc_trt-system_check-field_ram'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_ram',
    'label' => 'RAM',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_screen_resolution_height'
  $field_instances['prc_trt-system_check-field_screen_resolution_height'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_screen_resolution_height',
    'label' => 'Screen Resolution Height',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'label_help_description' => '',
      ),
      'type' => 'number',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_screen_resolution_width'
  $field_instances['prc_trt-system_check-field_screen_resolution_width'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_screen_resolution_width',
    'label' => 'Screen Resolution Width',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'label_help_description' => '',
      ),
      'type' => 'number',
      'weight' => 13,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Browser');
  t('Browser Version');
  t('Browser: Cookies enabled');
  t('Browser: Images enabled');
  t('Browser: JavaScript enabled');
  t('Device type');
  t('Enter a name to describe the lab or device(s) you are testing.');
  t('Enter the number of devices with the same configuration to include in test results.');
  t('Monitor color depth');
  t('Monitor size (in inches)');
  t('Number of devices');
  t('Operating system');
  t('Processor speed');
  t('RAM');
  t('Screen Resolution Height');
  t('Screen Resolution Width');
  t('System check name');

  return $field_instances;
}
