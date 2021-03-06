<?php
/**
 * @file
 * prc_custom_modules.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_custom_modules_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_menu_links';
  $strongarm->value = '0';
  $export['clone_menu_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_method';
  $strongarm->value = 'prepopulate';
  $export['clone_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_nodes_without_confirm';
  $strongarm->value = '0';
  $export['clone_nodes_without_confirm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_omitted';
  $strongarm->value = array(
    'quiz' => 'quiz',
    'course' => 'course',
    'digital_library_content' => 'digital_library_content',
    'district' => 'district',
    'favorites_list' => 'favorites_list',
    'pd_course' => 'pd_course',
    'pd_module' => 'pd_module',
    'page' => 'page',
    'panel' => 'panel',
    'school' => 'school',
    'state' => 'state',
    'quiz_directions' => 0,
    'multichoice' => 0,
    'short_answer' => 0,
  );
  $export['clone_omitted'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_course';
  $strongarm->value = 0;
  $export['clone_reset_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_digital_library_content';
  $strongarm->value = 0;
  $export['clone_reset_digital_library_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_district';
  $strongarm->value = 0;
  $export['clone_reset_district'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_favorites_list';
  $strongarm->value = 0;
  $export['clone_reset_favorites_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_multichoice';
  $strongarm->value = 0;
  $export['clone_reset_multichoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_page';
  $strongarm->value = 0;
  $export['clone_reset_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_panel';
  $strongarm->value = 0;
  $export['clone_reset_panel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_pd_course';
  $strongarm->value = 0;
  $export['clone_reset_pd_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_pd_module';
  $strongarm->value = 0;
  $export['clone_reset_pd_module'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_quiz';
  $strongarm->value = 0;
  $export['clone_reset_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_quiz_directions';
  $strongarm->value = 0;
  $export['clone_reset_quiz_directions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_school';
  $strongarm->value = 0;
  $export['clone_reset_school'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_short_answer';
  $strongarm->value = 0;
  $export['clone_reset_short_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_state';
  $strongarm->value = 0;
  $export['clone_reset_state'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_use_node_type_name';
  $strongarm->value = 0;
  $export['clone_use_node_type_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'course_content_use_pd_course';
  $strongarm->value = 0;
  $export['course_content_use_pd_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'course_content_use_pd_module';
  $strongarm->value = 1;
  $export['course_content_use_pd_module'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'course_content_use_quiz';
  $strongarm->value = 0;
  $export['course_content_use_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'course_default_enrollment_type';
  $strongarm->value = 'course_enrollment';
  $export['course_default_enrollment_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'course_disable_regions';
  $strongarm->value = array(
    'header' => 0,
    'help' => 0,
    'page_top' => 0,
    'page_bottom' => 0,
    'highlighted' => 0,
    'featured' => 0,
    'content' => 0,
    'sidebar_first' => 0,
    'sidebar_second' => 0,
    'triptych_first' => 0,
    'triptych_middle' => 0,
    'triptych_last' => 0,
    'footer_firstcolumn' => 0,
    'footer_secondcolumn' => 0,
    'footer_thirdcolumn' => 0,
    'footer_fourthcolumn' => 0,
    'footer' => 0,
    'dashboard_main' => 0,
    'dashboard_sidebar' => 0,
    'dashboard_inactive' => 0,
  );
  $export['course_disable_regions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'course_takecourse_tab_display';
  $strongarm->value = 0;
  $export['course_takecourse_tab_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'course_take_course_button_show';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
  );
  $export['course_take_course_button_show'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'course_use_course';
  $strongarm->value = 1;
  $export['course_use_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'course_use_pd_course';
  $strongarm->value = 1;
  $export['course_use_pd_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'course_use_pd_module';
  $strongarm->value = 0;
  $export['course_use_pd_module'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'course_use_quiz';
  $strongarm->value = 0;
  $export['course_use_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_private_path';
  $strongarm->value = '../private_files';
  $export['file_private_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_public_path';
  $strongarm->value = 'sites/default/files';
  $export['file_public_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_temporary_path';
  $strongarm->value = '/tmp';
  $export['file_temporary_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pinit_default_description';
  $strongarm->value = '';
  $export['pinit_default_description'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pinit_default_img';
  $strongarm->value = 'http://www.jaguar.com/resources/images/jaguar-logo.png';
  $export['pinit_default_img'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pinit_default_pincount';
  $strongarm->value = 'none';
  $export['pinit_default_pincount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pinit_source';
  $strongarm->value = 'title';
  $export['pinit_source'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pinit_types_enabled';
  $strongarm->value = array(
    'digital_library_content' => 'digital_library_content',
    'pd_course' => 'pd_course',
    'course' => 0,
    'favorites_list' => 0,
    'multichoice' => 0,
    'panel' => 0,
    'pd_module' => 0,
    'quiz' => 0,
    'quiz_directions' => 0,
    'short_answer' => 0,
  );
  $export['pinit_types_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_autotitle_length';
  $strongarm->value = '50';
  $export['quiz_autotitle_length'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_auto_revisioning';
  $strongarm->value = 1;
  $export['quiz_auto_revisioning'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_default_close';
  $strongarm->value = '30';
  $export['quiz_default_close'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_durod';
  $strongarm->value = 0;
  $export['quiz_durod'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_email_results';
  $strongarm->value = 0;
  $export['quiz_email_results'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_email_results_body';
  $strongarm->value = 'Dear !author

!taker attended the Quiz !title on !date
Test Description : !desc
!taker got !correct out of !total points in !minutes minutes. Score given in percentage is !percentage
You can access the result here !url
';
  $export['quiz_email_results_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_email_results_body_taker';
  $strongarm->value = 'Dear !taker

You attended the Quiz !title on !date
Test Description : !desc
You got !correct out of !total points in !minutes minutes. Score given in percentage is !percentage
You can access the result here !url
';
  $export['quiz_email_results_body_taker'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_email_results_subject';
  $strongarm->value = '!title Results Notice from !sitename';
  $export['quiz_email_results_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_email_results_subject_taker';
  $strongarm->value = '!title Results Notice from !sitename';
  $export['quiz_email_results_subject_taker'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_has_timer';
  $strongarm->value = 0;
  $export['quiz_has_timer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_has_userpoints';
  $strongarm->value = 0;
  $export['quiz_has_userpoints'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_index_questions';
  $strongarm->value = 1;
  $export['quiz_index_questions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_max_result_options';
  $strongarm->value = '5';
  $export['quiz_max_result_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_name';
  $strongarm->value = 'Assessment';
  $export['quiz_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_pager_siblings';
  $strongarm->value = '5';
  $export['quiz_pager_siblings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_pager_start';
  $strongarm->value = '100';
  $export['quiz_pager_start'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_remove_partial_quiz_record';
  $strongarm->value = '0';
  $export['quiz_remove_partial_quiz_record'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_results_to_quiz_author';
  $strongarm->value = 0;
  $export['quiz_results_to_quiz_author'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'quiz_use_passfail';
  $strongarm->value = 1;
  $export['quiz_use_passfail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'realname_pattern';
  $strongarm->value = '[user:field-first-name] [user:field-last-name]';
  $export['realname_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_digital_library_content_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'search_index' => 0,
    'search_result' => 0,
    'question' => 0,
    'token' => 0,
    'detail' => 0,
    'front_page_item' => 0,
    'gallery_view' => 0,
    'revision' => 0,
  );
  $export['sharethis_digital_library_content_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_document_options';
  $strongarm->value = array(
    'full' => 0,
    'teaser' => 0,
    'rss' => 0,
    'search_index' => 0,
    'search_result' => 0,
    'diff_standard' => 0,
    'token' => 0,
    'front_page_item' => 0,
    'revision' => 0,
  );
  $export['sharethis_document_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_location';
  $strongarm->value = 'links';
  $export['sharethis_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_node_types';
  $strongarm->value = array(
    'digital_library_content' => 'digital_library_content',
    'pd_course' => 'pd_course',
    'quiz' => 0,
    'quiz_directions' => 0,
    'course' => 0,
    'district' => 0,
    'favorites_list' => 0,
    'formative_instructional_task' => 0,
    'homepage_band' => 0,
    'multichoice' => 0,
    'pd_module' => 0,
    'page' => 0,
    'panel' => 0,
    'school' => 0,
    'short_answer' => 0,
    'speaking_and_listening_resource' => 0,
    'state' => 0,
  );
  $export['sharethis_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras';
  $strongarm->value = array(
    'Google Plus One:plusone' => 0,
    'Facebook Like:fblike' => 0,
  );
  $export['sharethis_option_extras'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_neworzero';
  $strongarm->value = 0;
  $export['sharethis_option_neworzero'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_onhover';
  $strongarm->value = 0;
  $export['sharethis_option_onhover'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_shorten';
  $strongarm->value = 1;
  $export['sharethis_option_shorten'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_pd_course_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'search_index' => 0,
    'search_result' => 0,
    'question' => 0,
    'token' => 0,
    'detail' => 0,
    'front_page_item' => 0,
    'gallery_view' => 0,
    'revision' => 0,
  );
  $export['sharethis_pd_course_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_service_option';
  $strongarm->value = '"Email:email","Facebook:facebook","Edmodo:edmodo"';
  $export['sharethis_service_option'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_weight';
  $strongarm->value = '10';
  $export['sharethis_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_widget_option';
  $strongarm->value = 'st_direct';
  $export['sharethis_widget_option'] = $strongarm;

  return $export;
}
