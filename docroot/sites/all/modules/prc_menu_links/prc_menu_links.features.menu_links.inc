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
  // Translatables
  // Included for use with string extractors like potx.
  t('Add content');
  t('Assessments');
  t('Content');
  t('Digital Library');
  t('Home');
  t('Invite New User');
  t('Professional Development');
  t('Users');


  return $menu_links;
}
