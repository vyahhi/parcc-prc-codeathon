<?php
/**
 * @file
 * prc_invite.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function prc_invite_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'invite-invite_by_email-field_invitation_email_address'
  $field_instances['invite-invite_by_email-field_invitation_email_address'] = array(
    'bundle' => 'invite_by_email',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Type e-mail address of person you wish invite.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'invite',
    'field_name' => 'field_invitation_email_address',
    'label' => 'E-mail',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'invite-invite_by_email-field_invitation_email_body'
  $field_instances['invite-invite_by_email-field_invitation_email_body'] = array(
    'bundle' => 'invite_by_email',
    'default_value' => array(
      0 => array(
        'value' => '[invite:inviter:name] has invited you to join [site:name] at [site:url].

To become a member of [site:name], click the link below or paste it into the address bar of your browser.

[invite:invite-accept-link]',
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter e-mail body.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 30,
      ),
    ),
    'entity_type' => 'invite',
    'field_name' => 'field_invitation_email_body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'invite-invite_by_email-field_invitation_email_subject'
  $field_instances['invite-invite_by_email-field_invitation_email_subject'] = array(
    'bundle' => 'invite_by_email',
    'default_value' => array(
      0 => array(
        'value' => '[invite:inviter:name] has sent you an invite!',
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter e-mail subject.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'invite',
    'field_name' => 'field_invitation_email_subject',
    'label' => 'Subject',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'invite-invite_by_email-field_member_state'
  $field_instances['invite-invite_by_email-field_member_state'] = array(
    'bundle' => 'invite_by_email',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 32,
      ),
    ),
    'entity_type' => 'invite',
    'field_name' => 'field_member_state',
    'label' => 'Member State',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'label_help_description' => '',
      ),
      'type' => 'options_select',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'invite-invite_by_email-field_role_id'
  $field_instances['invite-invite_by_email-field_role_id'] = array(
    'bundle' => 'invite_by_email',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'invite',
    'field_name' => 'field_role_id',
    'label' => 'Role ID',
    'required' => FALSE,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'invite-invite_by_email-field_user_state'
  $field_instances['invite-invite_by_email-field_user_state'] = array(
    'bundle' => 'invite_by_email',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 33,
      ),
    ),
    'entity_type' => 'invite',
    'field_name' => 'field_user_state',
    'label' => 'State Where You Teach',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 34,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('E-mail');
  t('Enter e-mail body.');
  t('Enter e-mail subject.');
  t('Member State');
  t('Role ID');
  t('State Where You Teach');
  t('Subject');
  t('Type e-mail address of person you wish invite.');

  return $field_instances;
}
