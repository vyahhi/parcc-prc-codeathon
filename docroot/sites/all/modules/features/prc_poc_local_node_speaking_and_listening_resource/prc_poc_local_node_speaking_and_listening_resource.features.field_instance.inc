<?php
/**
 * @file
 * prc_poc_local_node_speaking_and_listening_resource.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function prc_poc_local_node_speaking_and_listening_resource_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-speaking_and_listening_resource-field_file_single'
  $field_instances['node-speaking_and_listening_resource-field_file_single'] = array(
    'bundle' => 'speaking_and_listening_resource',
    'deleted' => 0,
    'description' => 'File requirements go here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_file_single',
    'label' => 'File',
    'required' => 0,
    'settings' => array(
      'course_enrollment' => FALSE,
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'doc docx mp4 pdf xls xlsx',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'label_help_description' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('File');
  t('File requirements go here.');

  return $field_instances;
}
