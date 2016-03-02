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
  $field_group->identifier = 'group_add_a_thumbnail|node|digital_library_content|form';
  $field_group->group_name = 'group_add_a_thumbnail';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_library_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add a Thumbnail',
    'weight' => '5',
    'children' => array(
      0 => 'field_thumbnail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Add a Thumbnail',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-add-a-thumbnail field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_add_a_thumbnail|node|digital_library_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attach_a_file|node|digital_library_content|form';
  $field_group->group_name = 'group_attach_a_file';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_library_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attach a File',
    'weight' => '4',
    'children' => array(
      0 => 'field_document',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Attach a File',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_attach_a_file|node|digital_library_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_link_to_url|node|digital_library_content|form';
  $field_group->group_name = 'group_link_to_url';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_library_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link to URL',
    'weight' => '6',
    'children' => array(
      0 => 'field_link_to_a_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Link to URL',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-link-to-url field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_link_to_url|node|digital_library_content|form'] = $field_group;

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
    'label' => 'Add More Information (Content Properties)',
    'weight' => '7',
    'children' => array(
      0 => 'field_genre',
      1 => 'field_grade_level_unlimited',
      2 => 'field_media_type',
      3 => 'field_standard',
      4 => 'field_subject',
      5 => 'field_grade_level_unlimited',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Add More Information (Content Properties)',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_metadata|node|digital_library_content|form'] = $field_group;

  return $export;
}
