<?php
/**
 * @file
 * prc_custom_modules.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function prc_custom_modules_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer realname'.
  $permissions['administer realname'] = array(
    'name' => 'administer realname',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'realname',
  );

  return $permissions;
}
