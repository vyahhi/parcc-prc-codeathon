<?php
/**
 * @file
 * prc_poc_local_node_document.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function prc_poc_local_node_document_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|front_page_item';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'front_page_item';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|document|front_page_item'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function prc_poc_local_node_document_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_document',
        2 => 'field_rating',
        3 => 'field_tags',
        4 => 'sharethis',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_document' => 'ds_content',
      'field_rating' => 'ds_content',
      'field_tags' => 'ds_content',
      'sharethis' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|document|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|front_page_item';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'front_page_item';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'node_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|document|front_page_item'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function prc_poc_local_node_document_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'front_page_item';
  $ds_view_mode->label = 'Front Page Item';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['front_page_item'] = $ds_view_mode;

  return $export;
}
