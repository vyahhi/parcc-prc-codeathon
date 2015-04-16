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

  // Exported role: Content Administrator (Curator).
  $roles['Content Administrator (Curator)'] = array(
    'name' => 'Content Administrator (Curator)',
    'weight' => 6,
  );

  // Exported role: Content Contributor.
  $roles['Content Contributor'] = array(
    'name' => 'Content Contributor',
    'weight' => 5,
  );

  // Exported role: District Admin.
  $roles['District Admin'] = array(
    'name' => 'District Admin',
    'weight' => 9,
  );

  // Exported role: Educator.
  $roles['Educator'] = array(
    'name' => 'Educator',
    'weight' => 3,
  );

  // Exported role: PARCC Item Author.
  $roles['PARCC Item Author'] = array(
    'name' => 'PARCC Item Author',
    'weight' => 11,
  );

  // Exported role: PARCC-Member Educator.
  $roles['PARCC-Member Educator'] = array(
    'name' => 'PARCC-Member Educator',
    'weight' => 4,
  );

  // Exported role: PRC Admin.
  $roles['PRC Admin'] = array(
    'name' => 'PRC Admin',
    'weight' => 7,
  );

  // Exported role: School Admin.
  $roles['School Admin'] = array(
    'name' => 'School Admin',
    'weight' => 8,
  );

  // Exported role: State Admin.
  $roles['State Admin'] = array(
    'name' => 'State Admin',
    'weight' => 10,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
