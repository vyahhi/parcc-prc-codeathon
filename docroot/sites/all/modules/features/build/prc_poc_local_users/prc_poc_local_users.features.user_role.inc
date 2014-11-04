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

  // Exported role: Content Contributor.
  $roles['Content Contributor'] = array(
    'name' => 'Content Contributor',
    'weight' => 5,
  );

  // Exported role: Educator.
  $roles['Educator'] = array(
    'name' => 'Educator',
    'weight' => 3,
  );

  // Exported role: PARCC-Member Educator.
  $roles['PARCC-Member Educator'] = array(
    'name' => 'PARCC-Member Educator',
    'weight' => 4,
  );

  // Exported role: PRC Admin.
  $roles['PRC Admin'] = array(
    'name' => 'PRC Admin',
    'weight' => 6,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
