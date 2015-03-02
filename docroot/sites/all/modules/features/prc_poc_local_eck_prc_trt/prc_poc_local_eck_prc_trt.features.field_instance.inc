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
      'weight' => 3,
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
      'weight' => 1,
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
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
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
      'weight' => 2,
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
        'weight' => 5,
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Device type');
  t('Enter a name to describe the lab or device(s) you are testing.');
  t('Enter the number of devices with the same configuration to include in test results.');
  t('Monitor size (in inches)');
  t('Number of devices');
  t('Processor speed');
  t('RAM');
  t('System check name');

  return $field_instances;
}
