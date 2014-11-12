<?php
/**
 * @file
 * prc_poc_local_views.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function prc_poc_local_views_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add to my lists'.
  $permissions['add to my lists'] = array(
    'name' => 'add to my lists',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'prc_my_lists',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  return $permissions;
}
