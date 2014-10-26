<?php
/**
 * @file
 * prc_poc_local_node_digital_library_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function prc_poc_local_node_digital_library_content_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|digital_library_content|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_library_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add more information (Content Properties)',
    'weight' => '13',
    'children' => array(
      0 => 'field_grade_level',
      1 => 'field_subject',
      2 => 'field_genre',
      3 => 'field_media_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Add more information (Content Properties)',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_metadata|node|digital_library_content|form'] = $field_group;

  return $export;
}
