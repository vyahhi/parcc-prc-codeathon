<?php
/**
 * @file
 * prc_poc_local_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function prc_poc_local_users_user_default_roles() {
  $roles = array();

  // Exported role: Content Author.
  $roles['Content Author'] = array(
    'name' => 'Content Author',
    'weight' => 5,
  );

  // Exported role: Educator.
  $roles['Educator'] = array(
    'name' => 'Educator',
    'weight' => 3,
  );

  // Exported role: PRC Admin.
  $roles['PRC Admin'] = array(
    'name' => 'PRC Admin',
    'weight' => 4,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
