<?php
/**
 * @file
 * prc_menu_links.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function prc_menu_links_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_assessments:assessments
  $menu_links['main-menu_assessments:assessments'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'assessments',
    'router_path' => 'assessments',
    'link_title' => 'Assessments',
    'options' => array(
      'identifier' => 'main-menu_assessments:assessments',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_content:admin-content
  $menu_links['main-menu_content:admin-content'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin-content',
    'router_path' => 'admin-content',
    'link_title' => 'Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_content:admin-content',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_course-management:admin-course
  $menu_links['main-menu_course-management:admin-course'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin-course',
    'router_path' => 'admin-course',
    'link_title' => 'Course Management',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_course-management:admin-course',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_digital-library:digital-library
  $menu_links['main-menu_digital-library:digital-library'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'digital-library',
    'router_path' => 'digital-library',
    'link_title' => 'Digital Library',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_digital-library:digital-library',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_professional-development:professional-development
  $menu_links['main-menu_professional-development:professional-development'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'professional-development',
    'router_path' => 'professional-development',
    'link_title' => 'Professional Development',
    'options' => array(
      'identifier' => 'main-menu_professional-development:professional-development',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_technology-readiness:technology-readiness
  $menu_links['main-menu_technology-readiness:technology-readiness'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'technology-readiness',
    'router_path' => 'technology-readiness',
    'link_title' => 'Technology Readiness',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_technology-readiness:technology-readiness',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_users:admin-users
  $menu_links['main-menu_users:admin-users'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin-users',
    'router_path' => 'admin-users',
    'link_title' => 'Users',
    'options' => array(
      'identifier' => 'main-menu_users:admin-users',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-add-content_add-content:node/add/digital-library-content
  $menu_links['menu-add-content_add-content:node/add/digital-library-content'] = array(
    'menu_name' => 'menu-add-content',
    'link_path' => 'node/add/digital-library-content',
    'router_path' => 'node/add/digital-library-content',
    'link_title' => 'Add content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-add-content_add-content:node/add/digital-library-content',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-add-course_add-course:node/add/pd-course
  $menu_links['menu-add-course_add-course:node/add/pd-course'] = array(
    'menu_name' => 'menu-add-course',
    'link_path' => 'node/add/pd-course',
    'router_path' => 'node/add/pd-course',
    'link_title' => 'Add course',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-add-course_add-course:node/add/pd-course',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-add-quiz_create-new-quiz:node/add/quiz
  $menu_links['menu-add-quiz_create-new-quiz:node/add/quiz'] = array(
    'menu_name' => 'menu-add-quiz',
    'link_path' => 'node/add/quiz',
    'router_path' => 'node/add/quiz',
    'link_title' => 'Create New Quiz',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-add-quiz_create-new-quiz:node/add/quiz',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-assessment-left-nav_all-available-assessments:assessments
  $menu_links['menu-assessment-left-nav_all-available-assessments:assessments'] = array(
    'menu_name' => 'menu-assessment-left-nav',
    'link_path' => 'assessments',
    'router_path' => 'assessments',
    'link_title' => 'All Available Assessments',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-assessment-left-nav_all-available-assessments:assessments',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-digital-library-left-nav_view-all:digital-library
  $menu_links['menu-digital-library-left-nav_view-all:digital-library'] = array(
    'menu_name' => 'menu-digital-library-left-nav',
    'link_path' => 'digital-library',
    'router_path' => 'digital-library',
    'link_title' => 'View All',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-digital-library-left-nav_view-all:digital-library',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-invite-users_invite-new-user:invite/add/invite_by_email
  $menu_links['menu-invite-users_invite-new-user:invite/add/invite_by_email'] = array(
    'menu_name' => 'menu-invite-users',
    'link_path' => 'invite/add/invite_by_email',
    'router_path' => 'invite/add/invite_by_email',
    'link_title' => 'Invite New User',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-invite-users_invite-new-user:invite/add/invite_by_email',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-professional-development-le_all-available-courses:professional-development
  $menu_links['menu-professional-development-le_all-available-courses:professional-development'] = array(
    'menu_name' => 'menu-professional-development-le',
    'link_path' => 'professional-development',
    'router_path' => 'professional-development',
    'link_title' => 'All Available Courses',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-professional-development-le_all-available-courses:professional-development',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-school-readiness-capaci_run-capacity-check:admin/structure/entity-type/prc_trt/capacity_check/add
  $menu_links['menu-trt-school-readiness-capaci_run-capacity-check:admin/structure/entity-type/prc_trt/capacity_check/add'] = array(
    'menu_name' => 'menu-trt-school-readiness-capaci',
    'link_path' => 'admin/structure/entity-type/prc_trt/capacity_check/add',
    'router_path' => 'admin/structure/entity-type/prc_trt/capacity_check/add',
    'link_title' => 'run capacity check',
    'options' => array(
      'menu_token_link_path' => 'admin/structure/entity-type/prc_trt/capacity_check/add?field_ref_school=[node:nid]',
      'menu_token_data' => array(
        'node' => array(
          'type' => 'node',
          'plugin' => 'node_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'query' => array(
        'field_ref_school' => '[node:nid]',
      ),
      'identifier' => 'menu-trt-school-readiness-capaci_run-capacity-check:admin/structure/entity-type/prc_trt/capacity_check/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-school-readiness-system_run-system-check:menutoken/54f9f897def7d
  $menu_links['menu-trt-school-readiness-system_run-system-check:menutoken/54f9f897def7d'] = array(
    'menu_name' => 'menu-trt-school-readiness-system',
    'link_path' => 'menutoken/54f9f897def7d',
    'router_path' => 'menutoken/%',
    'link_title' => 'run system check',
    'options' => array(
      'menu_token_link_path' => 'admin/structure/entity-type/prc_trt/system_check/add?field_ref_school=[node:nid]',
      'menu_token_data' => array(
        'node' => array(
          'type' => 'node',
          'plugin' => 'node_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-trt-school-readiness-system_run-system-check:menutoken/54f9f897def7d',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-system-check_system-check:admin/structure/entity-type/prc_trt/system_check/add
  $menu_links['menu-trt-system-check_system-check:admin/structure/entity-type/prc_trt/system_check/add'] = array(
    'menu_name' => 'menu-trt-system-check',
    'link_path' => 'admin/structure/entity-type/prc_trt/system_check/add',
    'router_path' => 'admin/structure/entity-type/prc_trt/system_check/add',
    'link_title' => 'System Check',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-trt-system-check_system-check:admin/structure/entity-type/prc_trt/system_check/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-testing-capacity-check_testing-capacity-check:admin/structure/entity-type/prc_trt/capacity_check/add
  $menu_links['menu-trt-testing-capacity-check_testing-capacity-check:admin/structure/entity-type/prc_trt/capacity_check/add'] = array(
    'menu_name' => 'menu-trt-testing-capacity-check',
    'link_path' => 'admin/structure/entity-type/prc_trt/capacity_check/add',
    'router_path' => 'admin/structure/entity-type/prc_trt/capacity_check/add',
    'link_title' => 'Testing Capacity Check',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-trt-testing-capacity-check_testing-capacity-check:admin/structure/entity-type/prc_trt/capacity_check/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add content');
  t('Add course');
  t('All Available Assessments');
  t('All Available Courses');
  t('Assessments');
  t('Content');
  t('Course Management');
  t('Create New Quiz');
  t('Digital Library');
  t('Home');
  t('Invite New User');
  t('Professional Development');
  t('System Check');
  t('Technology Readiness');
  t('Testing Capacity Check');
  t('Users');
  t('View All');
  t('run capacity check');
  t('run system check');


  return $menu_links;
}
