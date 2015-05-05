<?php
/**
 * @file
 * prc_poc_local_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function prc_poc_local_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: devel.
  $menus['devel'] = array(
    'menu_name' => 'devel',
    'title' => 'Development',
    'description' => 'Development link',
  );
  // Exported menu: features.
  $menus['features'] = array(
    'menu_name' => 'features',
    'title' => 'Features',
    'description' => 'Menu items for any enabled features.',
  );
  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
  );
  // Exported menu: menu-add-content.
  $menus['menu-add-content'] = array(
    'menu_name' => 'menu-add-content',
    'title' => 'Add content',
    'description' => '',
  );
  // Exported menu: menu-add-course.
  $menus['menu-add-course'] = array(
    'menu_name' => 'menu-add-course',
    'title' => 'Add Course',
    'description' => '',
  );
  // Exported menu: menu-add-quiz.
  $menus['menu-add-quiz'] = array(
    'menu_name' => 'menu-add-quiz',
    'title' => 'Add Quiz',
    'description' => 'Menu for Assessments page to let users add quizzes',
  );
  // Exported menu: menu-assessment-left-nav.
  $menus['menu-assessment-left-nav'] = array(
    'menu_name' => 'menu-assessment-left-nav',
    'title' => 'Assessment Left Nav',
    'description' => '',
  );
  // Exported menu: menu-digital-library-left-nav.
  $menus['menu-digital-library-left-nav'] = array(
    'menu_name' => 'menu-digital-library-left-nav',
    'title' => 'Digital Library Left Nav',
    'description' => '',
  );
  // Exported menu: menu-instruction-menu.
  $menus['menu-instruction-menu'] = array(
    'menu_name' => 'menu-instruction-menu',
    'title' => 'Instruction Menu',
    'description' => 'Menu to display on Instruction page',
  );
  // Exported menu: menu-invite-users.
  $menus['menu-invite-users'] = array(
    'menu_name' => 'menu-invite-users',
    'title' => 'Invite Users',
    'description' => '',
  );
  // Exported menu: menu-item-bank-add-questions.
  $menus['menu-item-bank-add-questions'] = array(
    'menu_name' => 'menu-item-bank-add-questions',
    'title' => 'Item Bank Add Questions',
    'description' => 'Add question types menu for use in the item bank',
  );
  // Exported menu: menu-professional-development-le.
  $menus['menu-professional-development-le'] = array(
    'menu_name' => 'menu-professional-development-le',
    'title' => 'Professional Development Left Nav',
    'description' => 'Navigation menu for Professional Development view',
  );
  // Exported menu: menu-trt-district-add.
  $menus['menu-trt-district-add'] = array(
    'menu_name' => 'menu-trt-district-add',
    'title' => 'TRT District Add',
    'description' => '',
  );
  // Exported menu: menu-trt-district-export.
  $menus['menu-trt-district-export'] = array(
    'menu_name' => 'menu-trt-district-export',
    'title' => 'TRT District Export',
    'description' => 'Links to export system and capacity checks for a district, from the district readiness page',
  );
  // Exported menu: menu-trt-manage-schools.
  $menus['menu-trt-manage-schools'] = array(
    'menu_name' => 'menu-trt-manage-schools',
    'title' => 'TRT Manage Schools',
    'description' => '',
  );
  // Exported menu: menu-trt-manage-schools-add-form.
  $menus['menu-trt-manage-schools-add-form'] = array(
    'menu_name' => 'menu-trt-manage-schools-add-form',
    'title' => 'TRT Manage Schools Add School Form',
    'description' => '',
  );
  // Exported menu: menu-trt-parcc-readiness.
  $menus['menu-trt-parcc-readiness'] = array(
    'menu_name' => 'menu-trt-parcc-readiness',
    'title' => 'TRT PARCC Readiness',
    'description' => '',
  );
  // Exported menu: menu-trt-school-readiness-capaci.
  $menus['menu-trt-school-readiness-capaci'] = array(
    'menu_name' => 'menu-trt-school-readiness-capaci',
    'title' => 'TRT School Readiness Capacity Check',
    'description' => '',
  );
  // Exported menu: menu-trt-school-readiness-system.
  $menus['menu-trt-school-readiness-system'] = array(
    'menu_name' => 'menu-trt-school-readiness-system',
    'title' => 'TRT School Readiness System Check',
    'description' => '',
  );
  // Exported menu: menu-trt-state-check-export.
  $menus['menu-trt-state-check-export'] = array(
    'menu_name' => 'menu-trt-state-check-export',
    'title' => 'TRT State Check Export',
    'description' => '',
  );
  // Exported menu: menu-trt-system-check.
  $menus['menu-trt-system-check'] = array(
    'menu_name' => 'menu-trt-system-check',
    'title' => 'TRT System Check',
    'description' => '',
  );
  // Exported menu: menu-trt-testing-capacity-check.
  $menus['menu-trt-testing-capacity-check'] = array(
    'menu_name' => 'menu-trt-testing-capacity-check',
    'title' => 'TRT Testing Capacity Check',
    'description' => '',
  );
  // Exported menu: navigation.
  $menus['navigation'] = array(
    'menu_name' => 'navigation',
    'title' => 'Navigation',
    'description' => 'The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Course');
  t('Add Quiz');
  t('Add content');
  t('Add question types menu for use in the item bank');
  t('Assessment Left Nav');
  t('Development');
  t('Development link');
  t('Digital Library Left Nav');
  t('Features');
  t('Instruction Menu');
  t('Invite Users');
  t('Item Bank Add Questions');
  t('Links to export system and capacity checks for a district, from the district readiness page');
  t('Main menu');
  t('Management');
  t('Menu for Assessments page to let users add quizzes');
  t('Menu items for any enabled features.');
  t('Menu to display on Instruction page');
  t('Navigation');
  t('Navigation menu for Professional Development view');
  t('Professional Development Left Nav');
  t('TRT District Add');
  t('TRT District Export');
  t('TRT Manage Schools');
  t('TRT Manage Schools Add School Form');
  t('TRT PARCC Readiness');
  t('TRT School Readiness Capacity Check');
  t('TRT School Readiness System Check');
  t('TRT State Check Export');
  t('TRT System Check');
  t('TRT Testing Capacity Check');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('The <em>Management</em> menu contains links for administrative tasks.');
  t('The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User menu');


  return $menus;
}
