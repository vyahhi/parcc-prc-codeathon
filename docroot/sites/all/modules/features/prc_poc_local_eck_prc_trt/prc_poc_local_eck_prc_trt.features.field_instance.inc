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

  // Exported field_instance: 'prc_trt-capacity_check-field_network_connection_type'
  $field_instances['prc_trt-capacity_check-field_network_connection_type'] = array(
    'bundle' => 'capacity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
      'school_readiness' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_network_connection_type',
    'label' => 'Network connection',
    'required' => 0,
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'prc_trt-capacity_check-field_number_of_access_points'
  $field_instances['prc_trt-capacity_check-field_number_of_access_points'] = array(
    'bundle' => 'capacity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the number of access points to the network.',
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
        'weight' => 9,
      ),
      'school_readiness' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_number_of_access_points',
    'label' => 'Number of access points',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'max' => 32676,
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

  // Exported field_instance: 'prc_trt-capacity_check-field_number_of_devices'
  $field_instances['prc_trt-capacity_check-field_number_of_devices'] = array(
    'bundle' => 'capacity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the number of devices that meet PARCC\'s minimum requirements.',
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
      'school_readiness' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_number_of_devices',
    'label' => 'Number of devices ready for assessment',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'max' => 32676,
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

  // Exported field_instance: 'prc_trt-capacity_check-field_number_of_sessions'
  $field_instances['prc_trt-capacity_check-field_number_of_sessions'] = array(
    'bundle' => 'capacity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the number of test sessions for each day of testing at your school.',
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
        'weight' => 4,
      ),
      'school_readiness' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_number_of_sessions',
    'label' => 'Number of test sessions per day',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'max' => 32676,
      'min' => 1,
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'prc_trt-capacity_check-field_number_of_students'
  $field_instances['prc_trt-capacity_check-field_number_of_students'] = array(
    'bundle' => 'capacity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the number of test-eligible students at your school.',
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
        'weight' => 1,
      ),
      'school_readiness' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_number_of_students',
    'label' => 'Number of students',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'max' => '',
      'min' => 1,
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'prc_trt-capacity_check-field_number_testing_days'
  $field_instances['prc_trt-capacity_check-field_number_testing_days'] = array(
    'bundle' => 'capacity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the number of days over which the assessment testing will take place.',
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
        'weight' => 3,
      ),
      'school_readiness' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_number_testing_days',
    'label' => 'Number of days of testing',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'max' => 32676,
      'min' => 1,
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'prc_trt-capacity_check-field_ref_school'
  $field_instances['prc_trt-capacity_check-field_ref_school'] = array(
    'bundle' => 'capacity_check',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'school_readiness' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_ref_school',
    'label' => 'School',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'action' => 'none',
          'action_on_edit' => 0,
          'fallback' => 'none',
          'providers' => array(
            'og_context' => FALSE,
            'url' => 1,
          ),
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
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
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'prc_trt-capacity_check-field_sittings_per_student'
  $field_instances['prc_trt-capacity_check-field_sittings_per_student'] = array(
    'bundle' => 'capacity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the number of sittings for each student at your school.',
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
        'weight' => 10,
      ),
      'school_readiness' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_sittings_per_student',
    'label' => 'Number of sittings per student',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'max' => 32676,
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'prc_trt-capacity_check-field_speed_of_connection'
  $field_instances['prc_trt-capacity_check-field_speed_of_connection'] = array(
    'bundle' => 'capacity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the speed of your school\'s connection to the network.',
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
        'weight' => 5,
      ),
      'school_readiness' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_speed_of_connection',
    'label' => 'Speed of connection (in Mbps)',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'max' => 32676,
      'min' => '',
      'prefix' => '',
      'suffix' => 'Mbps',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'label_help_description' => '',
      ),
      'type' => 'number',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'prc_trt-capacity_check-field_wired_connection_speed'
  $field_instances['prc_trt-capacity_check-field_wired_connection_speed'] = array(
    'bundle' => 'capacity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the speed of your school\'s wired connection.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'school_readiness' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_wired_connection_speed',
    'label' => 'Wired connection speed',
    'required' => 0,
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
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'prc_trt-capacity_check-field_wireless_connection_speed'
  $field_instances['prc_trt-capacity_check-field_wireless_connection_speed'] = array(
    'bundle' => 'capacity_check',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the speed of your school\'s wireless connection.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'school_readiness' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_wireless_connection_speed',
    'label' => 'Wireless connection speed',
    'required' => 0,
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
      'weight' => 8,
    ),
  );

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
        'weight' => 11,
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
        'weight' => 18,
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
        'weight' => 16,
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
        'weight' => 9,
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
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 25,
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
      'max' => 32676,
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
      'max' => 32676,
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
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'field_name' => 'field_processor_speed',
    'label' => 'Processor speed',
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
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'field_name' => 'field_ram',
    'label' => 'RAM',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_ref_school'
  $field_instances['prc_trt-system_check-field_ref_school'] = array(
    'bundle' => 'system_check',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_ref_school',
    'label' => 'School',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'action' => 'none',
          'action_on_edit' => 0,
          'fallback' => 'none',
          'providers' => array(
            'og_context' => FALSE,
            'url' => 1,
          ),
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
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
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'prc_trt-system_check-field_result'
  $field_instances['prc_trt-system_check-field_result'] = array(
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
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'prc_trt',
    'field_name' => 'field_result',
    'label' => 'Result',
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
      'weight' => 16,
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
        'weight' => 20,
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
  t('Enter the number of access points to the network.');
  t('Enter the number of days over which the assessment testing will take place.');
  t('Enter the number of devices that meet PARCC\'s minimum requirements.');
  t('Enter the number of devices with the same configuration to include in test results.');
  t('Enter the number of sittings for each student at your school.');
  t('Enter the number of test sessions for each day of testing at your school.');
  t('Enter the number of test-eligible students at your school.');
  t('Enter the speed of your school\'s connection to the network.');
  t('Enter the speed of your school\'s wired connection.');
  t('Enter the speed of your school\'s wireless connection.');
  t('Monitor color depth');
  t('Monitor size (in inches)');
  t('Network connection');
  t('Number of access points');
  t('Number of days of testing');
  t('Number of devices');
  t('Number of devices ready for assessment');
  t('Number of sittings per student');
  t('Number of students');
  t('Number of test sessions per day');
  t('Operating system');
  t('Processor speed');
  t('RAM');
  t('Result');
  t('School');
  t('Screen Resolution Height');
  t('Screen Resolution Width');
  t('Speed of connection (in Mbps)');
  t('System check name');
  t('Wired connection speed');
  t('Wireless connection speed');

  return $field_instances;
}
