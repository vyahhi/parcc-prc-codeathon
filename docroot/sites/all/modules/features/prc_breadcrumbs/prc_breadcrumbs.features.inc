<?php
/**
 * @file
 * prc_breadcrumbs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prc_breadcrumbs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_custom_breadcrumb_features_default_settings().
 */
function prc_breadcrumbs_custom_breadcrumb_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: assessment_content.
  $custom_breadcrumbs['assessment_content'] = array(
    'name' => 'Assessment Content',
    'titles' => 'Assessment',
    'paths' => 'assessments',
    'visibility_php' => '',
    'node_type' => 'quiz',
    'language' => '',
    'machine_name' => 'assessment_content',
  );

  // Exported custom breadcrumb: assessment_directions.
  $custom_breadcrumbs['assessment_directions'] = array(
    'name' => 'Assessment Directions',
    'titles' => 'Assessment
Item Bank',
    'paths' => 'assessments
assessments/item-bank',
    'visibility_php' => '',
    'node_type' => 'quiz_directions',
    'language' => '',
    'machine_name' => 'assessment_directions',
  );

  // Exported custom breadcrumb: digital_library_content.
  $custom_breadcrumbs['digital_library_content'] = array(
    'name' => 'Digital Library Content',
    'titles' => 'Library',
    'paths' => 'library',
    'visibility_php' => '',
    'node_type' => 'digital_library_content',
    'language' => '',
    'machine_name' => 'digital_library_content',
  );

  // Exported custom breadcrumb: formative_instructional_tasks_content.
  $custom_breadcrumbs['formative_instructional_tasks_content'] = array(
    'name' => 'Formative Instructional Tasks Content',
    'titles' => 'Instructional Tools
Formative Instructional Tasks',
    'paths' => 'instructional-tools
instructional-tools/formative-instructional-tasks',
    'visibility_php' => '',
    'node_type' => 'formative_instructional_task',
    'language' => '',
    'machine_name' => 'formative_instructional_tasks_content',
  );

  // Exported custom breadcrumb: multiple_choice_node.
  $custom_breadcrumbs['multiple_choice_node'] = array(
    'name' => 'Multiple Choice Node',
    'titles' => 'Assessment
Item Bank',
    'paths' => 'assessments
assessments/item-bank',
    'visibility_php' => '',
    'node_type' => 'multichoice',
    'language' => '',
    'machine_name' => 'multiple_choice_node',
  );

  // Exported custom breadcrumb: parcc_released_items.
  $custom_breadcrumbs['parcc_released_items'] = array(
    'name' => 'PARCC Released Items',
    'titles' => 'Assessment
PARCC Released Items',
    'paths' => 'assessments
assessments/parcc-released-items',
    'visibility_php' => '',
    'node_type' => 'parcc_released_item',
    'language' => '',
    'machine_name' => 'parcc_released_items',
  );

  // Exported custom breadcrumb: pd_course_node.
  $custom_breadcrumbs['pd_course_node'] = array(
    'name' => 'PD Course Node',
    'titles' => 'Professional Learning',
    'paths' => 'professional-learning',
    'visibility_php' => '',
    'node_type' => 'pd_course',
    'language' => '',
    'machine_name' => 'pd_course_node',
  );

  // Exported custom breadcrumb: pd_module_node.
  $custom_breadcrumbs['pd_module_node'] = array(
    'name' => 'PD Module Node',
    'titles' => 'Professional Learning',
    'paths' => 'professional-learning',
    'visibility_php' => '',
    'node_type' => 'pd_module',
    'language' => '',
    'machine_name' => 'pd_module_node',
  );

  // Exported custom breadcrumb: short_answer_content.
  $custom_breadcrumbs['short_answer_content'] = array(
    'name' => 'Short Answer Content',
    'titles' => 'Assessment
Item Bank',
    'paths' => 'assessments
assessments/item-bank',
    'visibility_php' => '',
    'node_type' => 'short_answer',
    'language' => '',
    'machine_name' => 'short_answer_content',
  );

  // Exported custom breadcrumb: speaking_and_listening_content.
  $custom_breadcrumbs['speaking_and_listening_content'] = array(
    'name' => 'Speaking and Listening Content',
    'titles' => 'Instructional Tools
Speaking and Listening',
    'paths' => 'instructional-tools
instructional-tools/speaking-listening',
    'visibility_php' => '',
    'node_type' => 'speaking_and_listening_resource',
    'language' => '',
    'machine_name' => 'speaking_and_listening_content',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_custom_breadcrumbs_paths_features_default_settings().
 */
function prc_breadcrumbs_custom_breadcrumbs_paths_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: admin.
  $custom_breadcrumbs['admin'] = array(
    'name' => 'Admin',
    'titles' => 'PRC',
    'paths' => '[site:url:absolute]',
    'visibility_php' => '',
    'specific_path' => 'prc/admin',
    'language' => '',
    'machine_name' => 'admin',
  );

  // Exported custom breadcrumb: admin_content.
  $custom_breadcrumbs['admin_content'] = array(
    'name' => 'Admin Content',
    'titles' => 'PRC
Admin',
    'paths' => '[site:url:absolute]
prc/admin',
    'visibility_php' => '',
    'specific_path' => 'prc/admin/admin-content',
    'language' => '',
    'machine_name' => 'admin_content',
  );

  // Exported custom breadcrumb: admin_course.
  $custom_breadcrumbs['admin_course'] = array(
    'name' => 'Admin Course',
    'titles' => 'PRC
Admin',
    'paths' => '[site:url:absolute]
prc/admin',
    'visibility_php' => '',
    'specific_path' => 'prc/admin/admin-course',
    'language' => '',
    'machine_name' => 'admin_course',
  );

  // Exported custom breadcrumb: admin_users.
  $custom_breadcrumbs['admin_users'] = array(
    'name' => 'Admin Users',
    'titles' => 'PRC
Admin',
    'paths' => '[site:url:absolute]
prc/admin',
    'visibility_php' => '',
    'specific_path' => 'prc/admin/admin-users',
    'language' => '',
    'machine_name' => 'admin_users',
  );

  // Exported custom breadcrumb: assessment.
  $custom_breadcrumbs['assessment'] = array(
    'name' => 'Assessment',
    'titles' => 'PRC',
    'paths' => '[site:url:absolute]',
    'visibility_php' => '',
    'specific_path' => 'assessments',
    'language' => '',
    'machine_name' => 'assessment',
  );

  // Exported custom breadcrumb: assessments.
  $custom_breadcrumbs['assessments'] = array(
    'name' => 'Assessments',
    'titles' => 'PRC
Assessment',
    'paths' => '/
assessments',
    'visibility_php' => '',
    'specific_path' => 'assessments/practice-assessments',
    'language' => '',
    'machine_name' => 'assessments',
  );

  // Exported custom breadcrumb: course_enrollments.
  $custom_breadcrumbs['course_enrollments'] = array(
    'name' => 'PRC Course Enrollments',
    'titles' => 'PRC
Professional Learning
[node:title]',
    'paths' => '[site:url:absolute]
professional-learning
<none>',
    'visibility_php' => '',
    'specific_path' => 'node/*/course-enrollments/*',
    'language' => '',
    'machine_name' => 'course_enrollments',
  );

  // Exported custom breadcrumb: diagnostics.
  $custom_breadcrumbs['diagnostics'] = array(
    'name' => 'Diagnostics',
    'titles' => 'PRC
Assessment',
    'paths' => '/
assessments',
    'visibility_php' => '',
    'specific_path' => 'assessments/diagnostics',
    'language' => '',
    'machine_name' => 'diagnostics',
  );

  // Exported custom breadcrumb: formative_instructional_tasks.
  $custom_breadcrumbs['formative_instructional_tasks'] = array(
    'name' => 'Formative Instructional Tasks',
    'titles' => 'PRC
Instructional Tools',
    'paths' => '[site:url:absolute]
instructional-tools',
    'visibility_php' => '',
    'specific_path' => 'instructional-tools/formative-instructional-tasks',
    'language' => '',
    'machine_name' => 'formative_instructional_tasks',
  );

  // Exported custom breadcrumb: instruction_page.
  $custom_breadcrumbs['instruction_page'] = array(
    'name' => 'Instruction Page',
    'titles' => 'PRC',
    'paths' => '[site:url:absolute]',
    'visibility_php' => '',
    'specific_path' => 'instructional-tools',
    'language' => '',
    'machine_name' => 'instruction_page',
  );

  // Exported custom breadcrumb: invite_new_user.
  $custom_breadcrumbs['invite_new_user'] = array(
    'name' => 'Invite New User',
    'titles' => 'PRC
Admin
PRC Website Users',
    'paths' => '[site:url:absolute]
prc/admin
prc/admin/admin-users',
    'visibility_php' => '',
    'specific_path' => 'invite/add/*',
    'language' => '',
    'machine_name' => 'invite_new_user',
  );

  // Exported custom breadcrumb: item_bank.
  $custom_breadcrumbs['item_bank'] = array(
    'name' => 'Item Bank',
    'titles' => 'PRC
Assessment',
    'paths' => '[site:url:absolute]
assessments',
    'visibility_php' => '',
    'specific_path' => 'assessments/item-bank',
    'language' => '',
    'machine_name' => 'item_bank',
  );

  // Exported custom breadcrumb: library.
  $custom_breadcrumbs['library'] = array(
    'name' => 'Library',
    'titles' => 'PRC',
    'paths' => '[site:url:absolute]',
    'visibility_php' => '',
    'specific_path' => 'library',
    'language' => '',
    'machine_name' => 'library',
  );

  // Exported custom breadcrumb: node_add_assessment.
  $custom_breadcrumbs['node_add_assessment'] = array(
    'name' => 'Node Add Assessment',
    'titles' => 'PRC
Assessment
[node:content-type]',
    'paths' => '[site:url:absolute]
assessments
[node:content-type]',
    'visibility_php' => '',
    'specific_path' => 'node/add/quiz',
    'language' => '',
    'machine_name' => 'node_add_assessment',
  );

  // Exported custom breadcrumb: node_add_digital_library_content.
  $custom_breadcrumbs['node_add_digital_library_content'] = array(
    'name' => 'Node Add Digital Library Content',
    'titles' => 'PRC
Admin
PRC Website Content',
    'paths' => '[site:url:absolute]
prc/admin
prc/admin/admin-content',
    'visibility_php' => '',
    'specific_path' => 'node/add/digital-library-content',
    'language' => '',
    'machine_name' => 'node_add_digital_library_content',
  );

  // Exported custom breadcrumb: node_add_formative_instructional_task.
  $custom_breadcrumbs['node_add_formative_instructional_task'] = array(
    'name' => 'Node Add Formative Instructional Task',
    'titles' => 'PRC
Instructional Tools
Formative Instructional Tasks',
    'paths' => '[site:url:absolute]
instructional-tools
instructional-tools/formative-instructional-tasks',
    'visibility_php' => '',
    'specific_path' => 'node/add/formative-instructional-task',
    'language' => '',
    'machine_name' => 'node_add_formative_instructional_task',
  );

  // Exported custom breadcrumb: node_add_multichoice.
  $custom_breadcrumbs['node_add_multichoice'] = array(
    'name' => 'Node Add Multichoice',
    'titles' => 'PRC
Assessment
Item Bank
[node:content-type]',
    'paths' => '[site:url:absolute]
assessments
assessments/item-bank
[node:content-type]',
    'visibility_php' => '',
    'specific_path' => 'node/add/multichoice',
    'language' => '',
    'machine_name' => 'node_add_multichoice',
  );

  // Exported custom breadcrumb: node_add_non_interactive_text_only_.
  $custom_breadcrumbs['node_add_non_interactive_text_only_'] = array(
    'name' => 'Node Add Non-interactive (text only)',
    'titles' => 'PRC
Assessment
Item Bank
[node:content-type]',
    'paths' => '[site:url:absolute]
assessments
assessments/item-bank
[node:content-type]',
    'visibility_php' => '',
    'specific_path' => 'node/add/quiz-directions',
    'language' => '',
    'machine_name' => 'node_add_non_interactive_text_only_',
  );

  // Exported custom breadcrumb: node_add_parcc_released_item.
  $custom_breadcrumbs['node_add_parcc_released_item'] = array(
    'name' => 'Node Add PARCC Released Item',
    'titles' => 'PRC
Assessment
PARCC Released Items',
    'paths' => '[site:url:absolute]
assessments
assessments/parcc-released-items',
    'visibility_php' => '',
    'specific_path' => 'node/add/parcc-released-item*',
    'language' => '',
    'machine_name' => 'node_add_parcc_released_item',
  );

  // Exported custom breadcrumb: node_add_pd_course.
  $custom_breadcrumbs['node_add_pd_course'] = array(
    'name' => 'Node Add PD-Course',
    'titles' => 'PRC
Admin
Course Management',
    'paths' => '[site:url:absolute]
prc/admin
prc/admin/admin-course',
    'visibility_php' => '',
    'specific_path' => 'node/add/pd-course',
    'language' => '',
    'machine_name' => 'node_add_pd_course',
  );

  // Exported custom breadcrumb: node_add_short_answer.
  $custom_breadcrumbs['node_add_short_answer'] = array(
    'name' => 'Node Add Short-answer',
    'titles' => 'PRC
Assessment
Item Bank
[node:content-type]',
    'paths' => '[site:url:absolute]
assessments
assessments/item-bank
[node:content-type]',
    'visibility_php' => '',
    'specific_path' => 'node/add/short-answer',
    'language' => '',
    'machine_name' => 'node_add_short_answer',
  );

  // Exported custom breadcrumb: node_add_speaking_and_listening.
  $custom_breadcrumbs['node_add_speaking_and_listening'] = array(
    'name' => 'Node Add Speaking and Listening',
    'titles' => 'PRC
Instructional Tools
Speaking and Listening',
    'paths' => '[site:url:absolute]
instructional-tools
instructional-tools/speaking-listening',
    'visibility_php' => '',
    'specific_path' => 'node/add/speaking-and-listening-resource',
    'language' => '',
    'machine_name' => 'node_add_speaking_and_listening',
  );

  // Exported custom breadcrumb: parcc_released_items.
  $custom_breadcrumbs['parcc_released_items'] = array(
    'name' => 'PARCC Released Items',
    'titles' => 'PRC
Assessment',
    'paths' => '[site:url:absolute]
assessments',
    'visibility_php' => '',
    'specific_path' => 'assessments/parcc-released-items',
    'language' => '',
    'machine_name' => 'parcc_released_items',
  );

  // Exported custom breadcrumb: prc_course_audience.
  $custom_breadcrumbs['prc_course_audience'] = array(
    'name' => 'PRC Course Audience',
    'titles' => 'PRC
Professional Learning',
    'paths' => '[site:url:absolute]
professional-learning',
    'visibility_php' => '',
    'specific_path' => 'node/*/courseaudience',
    'language' => '',
    'machine_name' => 'prc_course_audience',
  );

  // Exported custom breadcrumb: prc_course_outline.
  $custom_breadcrumbs['prc_course_outline'] = array(
    'name' => 'PRC Course Outline',
    'titles' => 'PRC
Professional Learning',
    'paths' => '[site:url:absolute]
professional-learning',
    'visibility_php' => '',
    'specific_path' => 'node/*/course-outline',
    'language' => '',
    'machine_name' => 'prc_course_outline',
  );

  // Exported custom breadcrumb: prc_course_report.
  $custom_breadcrumbs['prc_course_report'] = array(
    'name' => 'PRC Course Report',
    'titles' => 'PRC
Professional Learning',
    'paths' => '[site:url:absolute]
professional-learning',
    'visibility_php' => '',
    'specific_path' => 'node/*/course-reports*',
    'language' => '',
    'machine_name' => 'prc_course_report',
  );

  // Exported custom breadcrumb: professional_learning.
  $custom_breadcrumbs['professional_learning'] = array(
    'name' => 'Professional Learning',
    'titles' => 'PRC',
    'paths' => '[site:url:absolute]',
    'visibility_php' => '',
    'specific_path' => 'professional-learning',
    'language' => '',
    'machine_name' => 'professional_learning',
  );

  // Exported custom breadcrumb: quiz_results.
  $custom_breadcrumbs['quiz_results'] = array(
    'name' => 'Quiz Results',
    'titles' => 'PRC
Assessment
[node:title]',
    'paths' => '[site:url:absolute]
assessments
<none>',
    'visibility_php' => '',
    'specific_path' => 'node/*/quiz',
    'language' => '',
    'machine_name' => 'quiz_results',
  );

  // Exported custom breadcrumb: revisions.
  $custom_breadcrumbs['revisions'] = array(
    'name' => 'Revisions',
    'titles' => 'PRC
Admin
PRC Website Content
[node:title]',
    'paths' => '[site:url:absolute]
prc/admin
prc/admin/admin-content
[node:url:relative]',
    'visibility_php' => '',
    'specific_path' => 'node/*/revisions*',
    'language' => '',
    'machine_name' => 'revisions',
  );

  // Exported custom breadcrumb: revisions_view.
  $custom_breadcrumbs['revisions_view'] = array(
    'name' => 'Revisions view',
    'titles' => 'PRC
Assessment
Item Bank',
    'paths' => '[site:url:absolute]
assessments
assessments/item-bank',
    'visibility_php' => '',
    'specific_path' => 'node/*/prc_revisions',
    'language' => '',
    'machine_name' => 'revisions_view',
  );

  // Exported custom breadcrumb: speaking_and_listening.
  $custom_breadcrumbs['speaking_and_listening'] = array(
    'name' => 'Speaking and Listening',
    'titles' => 'PRC
Instructional Tools',
    'paths' => '[site:url:absolute]
instructional-tools',
    'visibility_php' => '',
    'specific_path' => 'instructional-tools/speaking-listening',
    'language' => '',
    'machine_name' => 'speaking_and_listening',
  );

  return $custom_breadcrumbs;
}
