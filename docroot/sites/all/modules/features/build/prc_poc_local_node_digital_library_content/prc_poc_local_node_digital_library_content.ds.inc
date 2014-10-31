<?php
/**
 * @file
 * prc_poc_local_node_digital_library_content.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function prc_poc_local_node_digital_library_content_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'submitted_by_author_name';
  $ds_field->label = 'Submitted by Author Name';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => 'Created [node:created] by [node:field_author_name]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['submitted_by_author_name'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function prc_poc_local_node_digital_library_content_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_library_content|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_library_content';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'submitted_by_author_name',
      ),
      'left' => array(
        2 => 'field_thumbnail',
      ),
      'right' => array(
        3 => 'body',
      ),
      'footer' => array(
        4 => 'sharethis',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'submitted_by_author_name' => 'header',
      'field_thumbnail' => 'left',
      'body' => 'right',
      'sharethis' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|digital_library_content|teaser'] = $ds_layout;

  return $export;
}
