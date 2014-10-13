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

  // Exported menu link: main-menu_content:node/add
  $menu_links['main-menu_content:node/add'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_content:node/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_digital-library:digital-library-tree-view
  $menu_links['main-menu_digital-library:digital-library-tree-view'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'digital-library-tree-view',
    'router_path' => 'digital-library-tree-view',
    'link_title' => 'Digital Library',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_digital-library:digital-library-tree-view',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
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
    'weight' => -48,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Digital Library');
  t('Home');
  t('Users');


  return $menu_links;
}
