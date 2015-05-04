<?php
/**
 * @file
 * prc_custom_modules.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function prc_custom_modules_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|assessment|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'assessment';
  $ds_fieldsetting->view_mode = 'teaser';
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
    'changed_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|assessment|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_library_content|gallery_view';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_library_content';
  $ds_fieldsetting->view_mode = 'gallery_view';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
    'links' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_prc_custom_modules_date_only',
    ),
  );
  $export['node|digital_library_content|gallery_view'] = $ds_fieldsetting;

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
  $ds_fieldsetting->id = 'node|digital_library_content|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_library_content';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'formatted_author_and_date' => array(
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
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'search_snippet' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|digital_library_content|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digital_library_content|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digital_library_content';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'formatted_author_and_date' => array(
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
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|digital_library_content|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|pd_course|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'pd_course';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'formatted_course_length' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|pd_course|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|pd_course|search_index';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'pd_course';
  $ds_fieldsetting->view_mode = 'search_index';
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
  $export['node|pd_course|search_index'] = $ds_fieldsetting;

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

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|quiz|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'quiz';
  $ds_fieldsetting->view_mode = 'teaser';
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
    'links' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'changed_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|quiz|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function prc_custom_modules_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'formatted_author_and_date';
  $ds_field->label = 'Formatted Author And Date';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => 'Created [node:created:long] [node:by_author]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['formatted_author_and_date'] = $ds_field;

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
function prc_custom_modules_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|assessment|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'assessment';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'changed_date',
        2 => 'body',
        3 => 'field_grade_level',
        4 => 'field_subject',
        5 => 'sharethis',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'changed_date' => 'ds_content',
      'body' => 'ds_content',
      'field_grade_level' => 'ds_content',
      'field_subject' => 'ds_content',
      'sharethis' => 'ds_content',
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
  $export['node|assessment|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_library_content|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_library_content';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_author_name',
        1 => 'post_date',
        2 => 'body',
      ),
      'right' => array(
        3 => 'field_thumbnail',
        4 => 'field_link_to_a_url',
        5 => 'field_document',
        6 => 'field_tags',
        7 => 'field_grade_level',
        8 => 'field_subject',
        9 => 'field_genre',
        10 => 'field_media_type',
        11 => 'field_standard',
      ),
    ),
    'fields' => array(
      'field_author_name' => 'left',
      'post_date' => 'left',
      'body' => 'left',
      'field_thumbnail' => 'right',
      'field_link_to_a_url' => 'right',
      'field_document' => 'right',
      'field_tags' => 'right',
      'field_grade_level' => 'right',
      'field_subject' => 'right',
      'field_genre' => 'right',
      'field_media_type' => 'right',
      'field_standard' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|digital_library_content|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_library_content|gallery_view';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_library_content';
  $ds_layout->view_mode = 'gallery_view';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_thumbnail',
        1 => 'title',
        2 => 'post_date',
        3 => 'body',
        4 => 'links',
        5 => 'field_tags',
      ),
    ),
    'fields' => array(
      'field_thumbnail' => 'ds_content',
      'title' => 'ds_content',
      'post_date' => 'ds_content',
      'body' => 'ds_content',
      'links' => 'ds_content',
      'field_tags' => 'ds_content',
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
  $export['node|digital_library_content|gallery_view'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_library_content|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_library_content';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'formatted_author_and_date',
      ),
      'left' => array(
        2 => 'field_thumbnail',
      ),
      'right' => array(
        3 => 'body',
        6 => 'field_document',
      ),
      'footer' => array(
        4 => 'links',
        5 => 'sharethis',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'formatted_author_and_date' => 'header',
      'field_thumbnail' => 'left',
      'body' => 'right',
      'links' => 'footer',
      'sharethis' => 'footer',
      'field_document' => 'right',
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
        0 => 'formatted_course_length',
        1 => 'field_thumbnail',
        2 => 'field_course_objectives',
        3 => 'course',
        4 => 'links',
      ),
    ),
    'fields' => array(
      'formatted_course_length' => 'ds_content',
      'field_thumbnail' => 'ds_content',
      'field_course_objectives' => 'ds_content',
      'course' => 'ds_content',
      'links' => 'ds_content',
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|quiz|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'quiz';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'changed_date',
        2 => 'body',
        3 => 'field_grade_level',
        4 => 'field_subject',
        5 => 'links',
        6 => 'sharethis',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'changed_date' => 'ds_content',
      'body' => 'ds_content',
      'field_grade_level' => 'ds_content',
      'field_subject' => 'ds_content',
      'links' => 'ds_content',
      'sharethis' => 'ds_content',
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
  $export['node|quiz|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function prc_custom_modules_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'detail';
  $ds_view_mode->label = 'Detail';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['detail'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'front_page_item';
  $ds_view_mode->label = 'Front Page Item';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['front_page_item'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'gallery_view';
  $ds_view_mode->label = 'Gallery View';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['gallery_view'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'school_readiness';
  $ds_view_mode->label = 'School Readiness';
  $ds_view_mode->entities = array(
    'prc_trt' => 'prc_trt',
  );
  $export['school_readiness'] = $ds_view_mode;

  return $export;
}
