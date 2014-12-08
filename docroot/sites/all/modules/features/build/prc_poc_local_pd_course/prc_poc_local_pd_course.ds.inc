<?php
/**
 * @file
 * prc_poc_local_pd_course.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function prc_poc_local_pd_course_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_library_content|search_index';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_library_content';
  $ds_fieldsetting->view_mode = 'search_index';
  $ds_fieldsetting->settings = array(
    'submitted_by_author_name' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|digital_library_content|search_index'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|pd_course|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'pd_course';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'formatted_course_length' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|pd_course|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|pd_course|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'pd_course';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'formatted_course_length' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|pd_course|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|pd_course|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'pd_course';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'formatted_course_length' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
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
    'links' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|pd_course|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function prc_poc_local_pd_course_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'formatted_course_length';
  $ds_field->label = 'Formatted Course Length';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field_length_formatted]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['formatted_course_length'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function prc_poc_local_pd_course_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_library_content|search_index';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_library_content';
  $ds_layout->view_mode = 'search_index';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'footer' => array(
        0 => 'links',
        5 => 'sharethis',
      ),
      'header' => array(
        1 => 'title',
        2 => 'submitted_by_author_name',
      ),
      'left' => array(
        3 => 'field_thumbnail',
      ),
      'right' => array(
        4 => 'body',
      ),
    ),
    'fields' => array(
      'links' => 'footer',
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
  $export['node|digital_library_content|search_index'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|pd_course|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'pd_course';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_course_objectives',
        1 => 'formatted_course_length',
        2 => 'course',
      ),
    ),
    'fields' => array(
      'field_course_objectives' => 'ds_content',
      'formatted_course_length' => 'ds_content',
      'course' => 'ds_content',
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
  $export['node|pd_course|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|pd_course|search_index';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'pd_course';
  $ds_layout->view_mode = 'search_index';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_thumbnail',
      ),
      'header' => array(
        1 => 'title',
        2 => 'formatted_course_length',
      ),
      'right' => array(
        3 => 'field_course_objectives',
      ),
      'footer' => array(
        4 => 'course',
        5 => 'sharethis',
      ),
    ),
    'fields' => array(
      'field_thumbnail' => 'left',
      'title' => 'header',
      'formatted_course_length' => 'header',
      'field_course_objectives' => 'right',
      'course' => 'footer',
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
  $export['node|pd_course|search_index'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|pd_course|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'pd_course';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'formatted_course_length',
      ),
      'left' => array(
        2 => 'field_thumbnail',
      ),
      'right' => array(
        3 => 'field_course_objectives',
      ),
      'footer' => array(
        4 => 'course',
        5 => 'sharethis',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'formatted_course_length' => 'header',
      'field_thumbnail' => 'left',
      'field_course_objectives' => 'right',
      'course' => 'footer',
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
  $export['node|pd_course|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|pd_course|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'pd_course';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'formatted_course_length',
      ),
      'left' => array(
        2 => 'field_thumbnail',
      ),
      'right' => array(
        3 => 'field_course_objectives',
      ),
      'footer' => array(
        4 => 'course',
        5 => 'links',
        6 => 'sharethis',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'formatted_course_length' => 'header',
      'field_thumbnail' => 'left',
      'field_course_objectives' => 'right',
      'course' => 'footer',
      'links' => 'footer',
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
  $export['node|pd_course|teaser'] = $ds_layout;

  return $export;
}
