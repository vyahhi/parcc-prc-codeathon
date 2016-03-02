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

  // Exported menu link: main-menu_admin:prc/admin.
  $menu_links['main-menu_admin:prc/admin'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'prc/admin',
    'router_path' => 'prc/admin',
    'link_title' => 'Admin',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_admin:prc/admin',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_assessment:assessments.
  $menu_links['main-menu_assessment:assessments'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'assessments',
    'router_path' => 'assessments',
    'link_title' => 'Assessment',
    'options' => array(
      'identifier' => 'main-menu_assessment:assessments',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_assessments:assessments/practice-assessments.
  $menu_links['main-menu_assessments:assessments/practice-assessments'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'assessments/practice-assessments',
    'router_path' => 'assessments',
    'link_title' => 'Assessments',
    'options' => array(
      'identifier' => 'main-menu_assessments:assessments/practice-assessments',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_assessment:assessments',
  );
  // Exported menu link: main-menu_content:prc/admin/admin-content.
  $menu_links['main-menu_content:prc/admin/admin-content'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'prc/admin/admin-content',
    'router_path' => 'prc/admin/admin-content',
    'link_title' => 'Content',
    'options' => array(
      'identifier' => 'main-menu_content:prc/admin/admin-content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_admin:prc/admin',
  );
  // Exported menu link: main-menu_course-management:prc/admin/admin-course.
  $menu_links['main-menu_course-management:prc/admin/admin-course'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'prc/admin/admin-course',
    'router_path' => 'prc/admin/admin-course',
    'link_title' => 'Course Management',
    'options' => array(
      'identifier' => 'main-menu_course-management:prc/admin/admin-course',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_admin:prc/admin',
  );
  // Exported menu link: main-menu_formative-instructional-tasks:instructional-tools/formative-instructional-tasks.
  $menu_links['main-menu_formative-instructional-tasks:instructional-tools/formative-instructional-tasks'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'instructional-tools/formative-instructional-tasks',
    'router_path' => 'instructional-tools/formative-instructional-tasks',
    'link_title' => 'Formative Instructional Tasks',
    'options' => array(
      'identifier' => 'main-menu_formative-instructional-tasks:instructional-tools/formative-instructional-tasks',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_instructional-tools:instructional-tools',
  );
  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_instructional-tools:instructional-tools.
  $menu_links['main-menu_instructional-tools:instructional-tools'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'instructional-tools',
    'router_path' => 'instructional-tools',
    'link_title' => 'Instructional Tools',
    'options' => array(
      'identifier' => 'main-menu_instructional-tools:instructional-tools',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_item-bank:assessments/item-bank.
  $menu_links['main-menu_item-bank:assessments/item-bank'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'assessments/item-bank',
    'router_path' => 'assessments/item-bank',
    'link_title' => 'Item Bank',
    'options' => array(
      'identifier' => 'main-menu_item-bank:assessments/item-bank',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_assessment:assessments',
  );
  // Exported menu link: main-menu_library:library.
  $menu_links['main-menu_library:library'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'library',
    'router_path' => 'library',
    'link_title' => 'Library',
    'options' => array(
      'identifier' => 'main-menu_library:library',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_parcc-released-items:assessments/parcc-released-items.
  $menu_links['main-menu_parcc-released-items:assessments/parcc-released-items'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'assessments/parcc-released-items',
    'router_path' => 'assessments/parcc-released-items',
    'link_title' => 'PARCC Released Items',
    'options' => array(
      'identifier' => 'main-menu_parcc-released-items:assessments/parcc-released-items',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_assessment:assessments',
  );
  // Exported menu link: main-menu_professional-learning:professional-learning.
  $menu_links['main-menu_professional-learning:professional-learning'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'professional-learning',
    'router_path' => 'professional-learning',
    'link_title' => 'Professional Learning',
    'options' => array(
      'identifier' => 'main-menu_professional-learning:professional-learning',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_speaking-and-listening:instructional-tools/speaking-listening.
  $menu_links['main-menu_speaking-and-listening:instructional-tools/speaking-listening'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'instructional-tools/speaking-listening',
    'router_path' => 'instructional-tools/speaking-listening',
    'link_title' => 'Speaking and Listening',
    'options' => array(
      'identifier' => 'main-menu_speaking-and-listening:instructional-tools/speaking-listening',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_instructional-tools:instructional-tools',
  );
  // Exported menu link: main-menu_technology-readiness:assessments/technology-readiness.
  $menu_links['main-menu_technology-readiness:assessments/technology-readiness'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'assessments/technology-readiness',
    'router_path' => 'assessments/technology-readiness',
    'link_title' => 'Technology Readiness',
    'options' => array(
      'identifier' => 'main-menu_technology-readiness:assessments/technology-readiness',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_assessment:assessments',
  );
  // Exported menu link: main-menu_users:prc/admin/admin-users.
  $menu_links['main-menu_users:prc/admin/admin-users'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'prc/admin/admin-users',
    'router_path' => 'prc/admin/admin-users',
    'link_title' => 'Users',
    'options' => array(
      'identifier' => 'main-menu_users:prc/admin/admin-users',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_admin:prc/admin',
  );
  // Exported menu link: menu-add-content_add-content:node/add/digital-library-content.
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
  // Exported menu link: menu-add-course_add-course:node/add/pd-course.
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
  // Exported menu link: menu-add-quiz_create-new-assessment:node/add/quiz.
  $menu_links['menu-add-quiz_create-new-assessment:node/add/quiz'] = array(
    'menu_name' => 'menu-add-quiz',
    'link_path' => 'node/add/quiz',
    'router_path' => 'node/add/quiz',
    'link_title' => 'Create New Assessment',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-add-quiz_create-new-assessment:node/add/quiz',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-assessment-left-nav_all-available-assessments:assessments/practice-assessments.
  $menu_links['menu-assessment-left-nav_all-available-assessments:assessments/practice-assessments'] = array(
    'menu_name' => 'menu-assessment-left-nav',
    'link_path' => 'assessments/practice-assessments',
    'router_path' => 'assessments',
    'link_title' => 'All Available Assessments',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-assessment-left-nav_all-available-assessments:assessments/practice-assessments',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-assessment_assessments:assessments/practice-assessments.
  $menu_links['menu-assessment_assessments:assessments/practice-assessments'] = array(
    'menu_name' => 'menu-assessment',
    'link_path' => 'assessments/practice-assessments',
    'router_path' => 'assessments/practice-assessments',
    'link_title' => 'Assessments',
    'options' => array(
      'attributes' => array(
        'title' => 'From here, you can view available assessments. After registering and logging in, you can create your own assessments from your own items. ',
      ),
      'identifier' => 'menu-assessment_assessments:assessments/practice-assessments',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-assessment_diagnostic-tools:assessments/diagnostics.
  $menu_links['menu-assessment_diagnostic-tools:assessments/diagnostics'] = array(
    'menu_name' => 'menu-assessment',
    'link_path' => 'assessments/diagnostics',
    'router_path' => 'assessments/diagnostics',
    'link_title' => 'Diagnostic Tools',
    'options' => array(
      'attributes' => array(
        'title' => 'The PARCC Diagnostic Tools are designed to provide evidence of student performance and progress with respect to key content and skills tied to the standards which can then be used to inform instruction. There are 5 tools for ELA and 2 for mathematics.',
      ),
      'identifier' => 'menu-assessment_diagnostic-tools:assessments/diagnostics',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-assessment_item-bank:assessments/item-bank.
  $menu_links['menu-assessment_item-bank:assessments/item-bank'] = array(
    'menu_name' => 'menu-assessment',
    'link_path' => 'assessments/item-bank',
    'router_path' => 'assessments/item-bank',
    'link_title' => 'Item Bank',
    'options' => array(
      'attributes' => array(
        'title' => 'View PARCC released and practice items. After registering and then logging in, you can create your own items and build assessments from your items and PARCC items.',
      ),
      'identifier' => 'menu-assessment_item-bank:assessments/item-bank',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  // Exported menu link: menu-assessment_parcc-released-items:assessments/parcc-released-items.
  $menu_links['menu-assessment_parcc-released-items:assessments/parcc-released-items'] = array(
    'menu_name' => 'menu-assessment',
    'link_path' => 'assessments/parcc-released-items',
    'router_path' => 'assessments/parcc-released-items',
    'link_title' => 'PARCC Released Items',
    'options' => array(
      'attributes' => array(
        'title' => 'The states that make up the PARCC consortium are taking the exceptional step of releasing test items from this year’s PARCC assessment to give teachers a powerful tool to inform and improve classroom teaching and learning. The test items were built with robust mathematics problems and authentic reading passages selected and reviewed extensively by dozens of educators from PARCC states. The catalog includes scoring rubrics and guides to the scoring, as well as released item sets, answer keys, standards alignment, and sample student responses – scored and annotated.',
      ),
      'identifier' => 'menu-assessment_parcc-released-items:assessments/parcc-released-items',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
  );
  // Exported menu link: menu-assessment_technology-readiness:assessments/technology-readiness.
  $menu_links['menu-assessment_technology-readiness:assessments/technology-readiness'] = array(
    'menu_name' => 'menu-assessment',
    'link_path' => 'assessments/technology-readiness',
    'router_path' => 'assessments/technology-readiness',
    'link_title' => 'Technology Readiness',
    'options' => array(
      'attributes' => array(
        'title' => 'This tool will help you gauge the overall readiness of the platform(s) and network for the number of students and number of testing sessions.',
      ),
      'identifier' => 'menu-assessment_technology-readiness:assessments/technology-readiness',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 8,
    'customized' => 1,
  );
  // Exported menu link: menu-digital-library-left-nav_view-all:library.
  $menu_links['menu-digital-library-left-nav_view-all:library'] = array(
    'menu_name' => 'menu-digital-library-left-nav',
    'link_path' => 'library',
    'router_path' => 'library',
    'link_title' => 'View All',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-digital-library-left-nav_view-all:library',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-fit-technology-enhanced-men_formative-instructional-tasks-technology-enhanced:http://formative.parcconline.org/dashboard.
  $menu_links['menu-fit-technology-enhanced-men_formative-instructional-tasks-technology-enhanced:http://formative.parcconline.org/dashboard'] = array(
    'menu_name' => 'menu-fit-technology-enhanced-men',
    'link_path' => 'http://formative.parcconline.org/dashboard',
    'router_path' => '',
    'link_title' => 'Formative Instructional Tasks (Technology Enhanced)',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-fit-technology-enhanced-men_formative-instructional-tasks-technology-enhanced:http://formative.parcconline.org/dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-formative-instructional-tas_add-resource:node/add/formative-instructional-task.
  $menu_links['menu-formative-instructional-tas_add-resource:node/add/formative-instructional-task'] = array(
    'menu_name' => 'menu-formative-instructional-tas',
    'link_path' => 'node/add/formative-instructional-task',
    'router_path' => 'node/add/formative-instructional-task',
    'link_title' => 'Add Resource',
    'options' => array(
      'query' => array(
        'destination' => 'instructional-tools/formative-instructional-tasks',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-formative-instructional-tas_add-resource:node/add/formative-instructional-task',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-homepage-menu_assessment:assessments.
  $menu_links['menu-homepage-menu_assessment:assessments'] = array(
    'menu_name' => 'menu-homepage-menu',
    'link_path' => 'assessments',
    'router_path' => 'assessments',
    'link_title' => 'Assessment',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-homepage-menu_assessment:assessments',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-homepage-menu_instructional-tools:instructional-tools.
  $menu_links['menu-homepage-menu_instructional-tools:instructional-tools'] = array(
    'menu_name' => 'menu-homepage-menu',
    'link_path' => 'instructional-tools',
    'router_path' => 'instructional-tools',
    'link_title' => 'Instructional Tools',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-homepage-menu_instructional-tools:instructional-tools',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-homepage-menu_library:library.
  $menu_links['menu-homepage-menu_library:library'] = array(
    'menu_name' => 'menu-homepage-menu',
    'link_path' => 'library',
    'router_path' => 'library',
    'link_title' => 'Library',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-homepage-menu_library:library',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-homepage-menu_professional-learning:professional-learning.
  $menu_links['menu-homepage-menu_professional-learning:professional-learning'] = array(
    'menu_name' => 'menu-homepage-menu',
    'link_path' => 'professional-learning',
    'router_path' => 'professional-learning',
    'link_title' => 'Professional Learning',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-homepage-menu_professional-learning:professional-learning',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-instructional-formative_formative-instructional-tasks:instructional-tools/formative-instructional-tasks.
  $menu_links['menu-instructional-formative_formative-instructional-tasks:instructional-tools/formative-instructional-tasks'] = array(
    'menu_name' => 'menu-instructional-formative',
    'link_path' => 'instructional-tools/formative-instructional-tasks',
    'router_path' => 'instructional-tools/formative-instructional-tasks',
    'link_title' => 'Formative Instructional Tasks',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-instructional-formative_formative-instructional-tasks:instructional-tools/formative-instructional-tasks',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-instructional-speaking_speaking-and-listening:instructional-tools/speaking-listening.
  $menu_links['menu-instructional-speaking_speaking-and-listening:instructional-tools/speaking-listening'] = array(
    'menu_name' => 'menu-instructional-speaking',
    'link_path' => 'instructional-tools/speaking-listening',
    'router_path' => 'instructional-tools/speaking-listening',
    'link_title' => 'Speaking and Listening',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-instructional-speaking_speaking-and-listening:instructional-tools/speaking-listening',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-invite-users_export-all-users-to-csv:prc/admin/admin-users/export.csv.
  $menu_links['menu-invite-users_export-all-users-to-csv:prc/admin/admin-users/export.csv'] = array(
    'menu_name' => 'menu-invite-users',
    'link_path' => 'prc/admin/admin-users/export.csv',
    'router_path' => 'prc/admin/admin-users/export.csv',
    'link_title' => 'Export all users to .csv',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-invite-users_export-all-users-to-csv:prc/admin/admin-users/export.csv',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 50,
    'customized' => 1,
  );
  // Exported menu link: menu-invite-users_invite-new-user:invite/add/invite_by_email.
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
  // Exported menu link: menu-item-bank-add-questions_interactive-choice:node/add/multichoice.
  $menu_links['menu-item-bank-add-questions_interactive-choice:node/add/multichoice'] = array(
    'menu_name' => 'menu-item-bank-add-questions',
    'link_path' => 'node/add/multichoice',
    'router_path' => 'node/add/multichoice',
    'link_title' => 'Interactive choice',
    'options' => array(
      'query' => array(
        'destination' => 'assessments/item-bank',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-item-bank-add-questions_interactive-choice:node/add/multichoice',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-item-bank-add-questions_non-interactive-text-only:node/add/quiz-directions.
  $menu_links['menu-item-bank-add-questions_non-interactive-text-only:node/add/quiz-directions'] = array(
    'menu_name' => 'menu-item-bank-add-questions',
    'link_path' => 'node/add/quiz-directions',
    'router_path' => 'node/add/quiz-directions',
    'link_title' => 'Non-interactive (text only)',
    'options' => array(
      'query' => array(
        'destination' => 'assessments/item-bank',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-item-bank-add-questions_non-interactive-text-only:node/add/quiz-directions',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-item-bank-add-questions_short-answer:node/add/short-answer.
  $menu_links['menu-item-bank-add-questions_short-answer:node/add/short-answer'] = array(
    'menu_name' => 'menu-item-bank-add-questions',
    'link_path' => 'node/add/short-answer',
    'router_path' => 'node/add/short-answer',
    'link_title' => 'Short answer',
    'options' => array(
      'query' => array(
        'destination' => 'assessments/item-bank',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-item-bank-add-questions_short-answer:node/add/short-answer',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-parcc-released-items-menu_add-resource:node/add/parcc-released-item.
  $menu_links['menu-parcc-released-items-menu_add-resource:node/add/parcc-released-item'] = array(
    'menu_name' => 'menu-parcc-released-items-menu',
    'link_path' => 'node/add/parcc-released-item',
    'router_path' => 'node/add/parcc-released-item',
    'link_title' => 'Add Resource',
    'options' => array(
      'query' => array(
        'destination' => 'assessments/parcc-released-items',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-parcc-released-items-menu_add-resource:node/add/parcc-released-item',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-professional-development-le_all-available-courses:professional-learning.
  $menu_links['menu-professional-development-le_all-available-courses:professional-learning'] = array(
    'menu_name' => 'menu-professional-development-le',
    'link_path' => 'professional-learning',
    'router_path' => 'professional-learning',
    'link_title' => 'All Available Courses',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-professional-development-le_all-available-courses:professional-learning',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-speaking-and-listening-page_add-resource:node/add/speaking-and-listening-resource.
  $menu_links['menu-speaking-and-listening-page_add-resource:node/add/speaking-and-listening-resource'] = array(
    'menu_name' => 'menu-speaking-and-listening-page',
    'link_path' => 'node/add/speaking-and-listening-resource',
    'router_path' => 'node/add/speaking-and-listening-resource',
    'link_title' => 'Add Resource',
    'options' => array(
      'query' => array(
        'destination' => 'instructional-tools/speaking-listening',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-speaking-and-listening-page_add-resource:node/add/speaking-and-listening-resource',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-district-add_add-district:node/add/district.
  $menu_links['menu-trt-district-add_add-district:node/add/district'] = array(
    'menu_name' => 'menu-trt-district-add',
    'link_path' => 'node/add/district',
    'router_path' => 'node/add/district',
    'link_title' => 'Add District',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-trt-district-add_add-district:node/add/district',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-district-export_export-all-system-checks-data-to-csv:menutoken/551dc2bb07596.
  $menu_links['menu-trt-district-export_export-all-system-checks-data-to-csv:menutoken/551dc2bb07596'] = array(
    'menu_name' => 'menu-trt-district-export',
    'link_path' => 'menutoken/551dc2bb07596',
    'router_path' => 'menutoken/%',
    'link_title' => 'Export all system checks data to .csv',
    'options' => array(
      'menu_token_link_path' => 'trt/system-check/export/[node:content-type]/[node:nid]',
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
      'identifier' => 'menu-trt-district-export_export-all-system-checks-data-to-csv:menutoken/551dc2bb07596',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-district-export_export-all-testing-capacity-checks-data-to-csv:menutoken/551dc75e69db7.
  $menu_links['menu-trt-district-export_export-all-testing-capacity-checks-data-to-csv:menutoken/551dc75e69db7'] = array(
    'menu_name' => 'menu-trt-district-export',
    'link_path' => 'menutoken/551dc75e69db7',
    'router_path' => 'menutoken/%',
    'link_title' => 'Export all testing capacity checks data to .csv',
    'options' => array(
      'menu_token_link_path' => 'trt/capacity-check/export/[node:content-type]/[node:nid]',
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
      'identifier' => 'menu-trt-district-export_export-all-testing-capacity-checks-data-to-csv:menutoken/551dc75e69db7',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-manage-schools-add-form_add-school---form:menutoken/54ff7195d7a73.
  $menu_links['menu-trt-manage-schools-add-form_add-school---form:menutoken/54ff7195d7a73'] = array(
    'menu_name' => 'menu-trt-manage-schools-add-form',
    'link_path' => 'menutoken/54ff7195d7a73',
    'router_path' => 'menutoken/%',
    'link_title' => 'Add School - form',
    'options' => array(
      'menu_token_link_path' => 'node/add/school?field_ref_district=[node:nid]',
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
      'identifier' => 'menu-trt-manage-schools-add-form_add-school---form:menutoken/54ff7195d7a73',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-manage-schools-add-form_add-schools---upload-csv-file:menutoken/5501ce6a77c95.
  $menu_links['menu-trt-manage-schools-add-form_add-schools---upload-csv-file:menutoken/5501ce6a77c95'] = array(
    'menu_name' => 'menu-trt-manage-schools-add-form',
    'link_path' => 'menutoken/5501ce6a77c95',
    'router_path' => 'menutoken/%',
    'link_title' => 'Add School(s) - upload csv file',
    'options' => array(
      'menu_token_link_path' => 'district/[node:nid]/upload-schools',
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
      'identifier' => 'menu-trt-manage-schools-add-form_add-schools---upload-csv-file:menutoken/5501ce6a77c95',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-manage-schools_manage-schools:menutoken/54ff6e2b2a473.
  $menu_links['menu-trt-manage-schools_manage-schools:menutoken/54ff6e2b2a473'] = array(
    'menu_name' => 'menu-trt-manage-schools',
    'link_path' => 'menutoken/54ff6e2b2a473',
    'router_path' => 'menutoken/%',
    'link_title' => 'Manage Schools',
    'options' => array(
      'menu_token_link_path' => 'node/[node:nid]/manage-schools',
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
        'title' => 'add schools and request readiness checks',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-trt-manage-schools_manage-schools:menutoken/54ff6e2b2a473',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-parcc-readiness_parcc-readiness:assessments/technology-readiness/parcc.
  $menu_links['menu-trt-parcc-readiness_parcc-readiness:assessments/technology-readiness/parcc'] = array(
    'menu_name' => 'menu-trt-parcc-readiness',
    'link_path' => 'assessments/technology-readiness/parcc',
    'router_path' => 'assessments/technology-readiness/parcc',
    'link_title' => 'PARCC Readiness',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-trt-parcc-readiness_parcc-readiness:assessments/technology-readiness/parcc',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-school-readiness-capaci_run-testing-capacity-check:admin/structure/entity-type/prc_trt/capacity_check/add.
  $menu_links['menu-trt-school-readiness-capaci_run-testing-capacity-check:admin/structure/entity-type/prc_trt/capacity_check/add'] = array(
    'menu_name' => 'menu-trt-school-readiness-capaci',
    'link_path' => 'admin/structure/entity-type/prc_trt/capacity_check/add',
    'router_path' => 'admin/structure/entity-type/prc_trt/capacity_check/add',
    'link_title' => 'run testing capacity check',
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
      'identifier' => 'menu-trt-school-readiness-capaci_run-testing-capacity-check:admin/structure/entity-type/prc_trt/capacity_check/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-school-readiness-system_run-system-check:menutoken/54f9f897def7d.
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
  // Exported menu link: menu-trt-state-check-export_export-all-system-checks-data-to-csv:assessments/technology-readiness.
  $menu_links['menu-trt-state-check-export_export-all-system-checks-data-to-csv:assessments/technology-readiness'] = array(
    'menu_name' => 'menu-trt-state-check-export',
    'link_path' => 'assessments/technology-readiness',
    'router_path' => 'assessments/technology-readiness',
    'link_title' => 'Export all system checks data to .csv',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-trt-state-check-export_export-all-system-checks-data-to-csv:assessments/technology-readiness',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-state-check-export_export-all-testing-capacity-checks-data-to-csv:assessments/technology-readiness.
  $menu_links['menu-trt-state-check-export_export-all-testing-capacity-checks-data-to-csv:assessments/technology-readiness'] = array(
    'menu_name' => 'menu-trt-state-check-export',
    'link_path' => 'assessments/technology-readiness',
    'router_path' => 'assessments/technology-readiness',
    'link_title' => 'Export all testing capacity checks data to .csv',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-trt-state-check-export_export-all-testing-capacity-checks-data-to-csv:assessments/technology-readiness',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-trt-system-check_system-check:admin/structure/entity-type/prc_trt/system_check/add.
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
  // Exported menu link: menu-trt-testing-capacity-check_testing-capacity-check:admin/structure/entity-type/prc_trt/capacity_check/add.
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
  // Exported menu link: user-menu_create-account:user/register.
  $menu_links['user-menu_create-account:user/register'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Create account',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_create-account:user/register',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: user-menu_user-account:user.
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add District');
  t('Add Resource');
  t('Add School - form');
  t('Add School(s) - upload csv file');
  t('Add content');
  t('Add course');
  t('Admin');
  t('All Available Assessments');
  t('All Available Courses');
  t('Assessment');
  t('Assessments');
  t('Content');
  t('Course Management');
  t('Create New Assessment');
  t('Create account');
  t('Diagnostic Tools');
  t('Export all system checks data to .csv');
  t('Export all testing capacity checks data to .csv');
  t('Export all users to .csv');
  t('Formative Instructional Tasks');
  t('Formative Instructional Tasks (Technology Enhanced)');
  t('Home');
  t('Instructional Tools');
  t('Interactive choice');
  t('Invite New User');
  t('Item Bank');
  t('Library');
  t('Log out');
  t('Manage Schools');
  t('Non-interactive (text only)');
  t('PARCC Readiness');
  t('PARCC Released Items');
  t('Professional Learning');
  t('Short answer');
  t('Speaking and Listening');
  t('System Check');
  t('Technology Readiness');
  t('Testing Capacity Check');
  t('User account');
  t('Users');
  t('View All');
  t('run system check');
  t('run testing capacity check');

  return $menu_links;
}
