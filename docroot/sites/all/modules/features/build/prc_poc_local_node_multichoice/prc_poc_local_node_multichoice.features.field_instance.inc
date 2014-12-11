<?php
/**
 * @file
 * prc_poc_local_node_multichoice.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function prc_poc_local_node_multichoice_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-multichoice-body'
  $field_instances['node-multichoice-body'] = array(
    'bundle' => 'multichoice',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Question',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 6,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => -10,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Question');

  return $field_instances;
}
