<?php
/**
 * @file
 * prc_poc_local_users.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function prc_poc_local_users_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_first_name'.
  $field_instances['user-user-field_first_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_first_name',
    'label' => 'First Name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'user-user-field_last_name'.
  $field_instances['user-user-field_last_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_last_name',
    'label' => 'Last Name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'user-user-field_member_state'.
  $field_instances['user-user-field_member_state'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_member_state',
    'label' => 'Member State',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'label_help_description' => '',
      ),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'user-user-field_profession'.
  $field_instances['user-user-field_profession'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_profession',
    'label' => 'Profession',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'user-user-field_user_state'.
  $field_instances['user-user-field_user_state'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_user_state',
    'label' => 'State Where I Teach',
    'required' => 1,
    'settings' => array(
      'course_enrollment' => FALSE,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'label_help_description' => '',
      ),
      'type' => 'options_select',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'user-user-ldap_user_current_dn'.
  $field_instances['user-user-ldap_user_current_dn'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'default_value_function' => 'ldap_user_dn_default',
    'deleted' => 0,
    'description' => 'May change when user\'s DN changes. This field should not be edited.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'ldap_user_current_dn',
    'label' => 'User LDAP DN',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'ldap_user',
      'settings' => array(),
      'type' => 'ldap_user_hidden',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'user-user-ldap_user_last_checked'.
  $field_instances['user-user-ldap_user_last_checked'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field should not be edited.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'ldap_user_last_checked',
    'label' => 'Unix timestamp of when Drupal user was compard to ldap entry.  This could be for purposes of synching, deleteing drupal account, etc.',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'ldap_user',
      'settings' => array(),
      'type' => 'ldap_user_hidden',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'user-user-ldap_user_ldap_exclude'.
  $field_instances['user-user-ldap_user_ldap_exclude'] = array(
    'bundle' => 'user',
    'default_value' => 0,
    'deleted' => 0,
    'description' => 'This field should not be edited.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'ldap_user_ldap_exclude',
    'label' => 'Whether to exclude the user from LDAP functionality',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'ldap_user',
      'settings' => array(),
      'type' => 'ldap_user_hidden',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'user-user-ldap_user_prov_entries'.
  $field_instances['user-user-ldap_user_prov_entries'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field should not be edited.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'ldap_user_prov_entries',
    'label' => 'LDAP Entries that have been provisioned from this Drupal user.',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'ldap_user',
      'settings' => array(),
      'type' => 'ldap_user_hidden',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'user-user-ldap_user_puid'.
  $field_instances['user-user-ldap_user_puid'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'default_value_function' => 'ldap_user_puid_default',
    'deleted' => 0,
    'description' => 'This field should not be edited.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'ldap_user_puid',
    'label' => 'Value of user\'s permanent unique id.  This should never change for a given ldap identified user.',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'ldap_user',
      'settings' => array(),
      'type' => 'ldap_user_hidden',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'user-user-ldap_user_puid_property'.
  $field_instances['user-user-ldap_user_puid_property'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'default_value_function' => 'ldap_user_puid_property_default',
    'deleted' => 0,
    'description' => 'This field should not be edited.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'ldap_user_puid_property',
    'label' => 'Property specified as user\'s puid.',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'ldap_user',
      'settings' => array(),
      'type' => 'ldap_user_hidden',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'user-user-ldap_user_puid_sid'.
  $field_instances['user-user-ldap_user_puid_sid'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'default_value_function' => 'ldap_user_provisioned_sid_default',
    'deleted' => 0,
    'description' => 'This field should not be edited.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'ldap_user_puid_sid',
    'label' => 'LDAP Server ID that puid was derived from.  NULL if puid is independent of server configuration instance.',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'ldap_user',
      'settings' => array(),
      'type' => 'ldap_user_hidden',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('First Name');
  t('LDAP Entries that have been provisioned from this Drupal user.');
  t('LDAP Server ID that puid was derived from.  NULL if puid is independent of server configuration instance.');
  t('Last Name');
  t('May change when user\'s DN changes. This field should not be edited.');
  t('Member State');
  t('Profession');
  t('Property specified as user\'s puid.');
  t('State Where I Teach');
  t('This field should not be edited.');
  t('Unix timestamp of when Drupal user was compard to ldap entry.  This could be for purposes of synching, deleteing drupal account, etc.');
  t('User LDAP DN');
  t('Value of user\'s permanent unique id.  This should never change for a given ldap identified user.');
  t('Whether to exclude the user from LDAP functionality');

  return $field_instances;
}
