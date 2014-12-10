<?php
/**
 * @file
 * prc_poc_local_pd_module.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function prc_poc_local_pd_module_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_length|node|pd_module|form';
  $field_group->group_name = 'group_course_length';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pd_module';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Course Length',
    'weight' => '40',
    'children' => array(
      0 => 'field_length_unit',
      1 => 'field_length_quantity',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-length field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_course_length|node|pd_module|form'] = $field_group;

  return $export;
}
