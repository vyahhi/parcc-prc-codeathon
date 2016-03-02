<?php
/**
 * @file
 * prc_mail_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_mail_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'invite_default_expiry_time';
  $strongarm->value = 30;
  $export['invite_default_expiry_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'invite_default_mail_body';
  $strongarm->value = 'Congratulations! Parcc Inc. invites you to register and then log into the Partnership Resource Center. In this website, you will find learning and assessment resources, professional learning opportunities and other tools to facilitate the implementation of quality assessments in your classroom, school district, or state.
 
Your invitation is for the following: [invite:role-name]

To become a member of [site:name], click the link below or paste it into the address bar of your browser.

[invite:invite-accept-link]

Welcome to the Parcc community,
The Parcc Inc. Staff';
  $export['invite_default_mail_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'invite_default_mail_subject';
  $strongarm->value = '[invite:inviter:name] has sent you an invite!';
  $export['invite_default_mail_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'invite_default_replace_tokens';
  $strongarm->value = 1;
  $export['invite_default_replace_tokens'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'invite_manual_from';
  $strongarm->value = '';
  $export['invite_manual_from'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'invite_manual_reply_to';
  $strongarm->value = '';
  $export['invite_manual_reply_to'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'invite_message_editable';
  $strongarm->value = 1;
  $export['invite_message_editable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'invite_use_users_email';
  $strongarm->value = '0';
  $export['invite_use_users_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'invite_use_users_email_replyto';
  $strongarm->value = '0';
  $export['invite_use_users_email_replyto'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mail_system';
  $strongarm->value = array(
    'default-system' => 'SmtpMailSystem',
  );
  $export['mail_system'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_allowhtml';
  $strongarm->value = 1;
  $export['smtp_allowhtml'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_debugging';
  $strongarm->value = 0;
  $export['smtp_debugging'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_from';
  $strongarm->value = 'noreply@parcconline.org';
  $export['smtp_from'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_fromname';
  $strongarm->value = '';
  $export['smtp_fromname'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_host';
  $strongarm->value = 'email-smtp.us-east-1.amazonaws.com';
  $export['smtp_host'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_hostbackup';
  $strongarm->value = '';
  $export['smtp_hostbackup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_library';
  $strongarm->value = 'sites/all/modules/contrib/smtp/smtp.module';
  $export['smtp_library'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_on';
  $strongarm->value = '1';
  $export['smtp_on'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_password';
  $strongarm->value = 'AotjnoCDr0s+6vtU04sRJ3OTZZc6cTM7Zav06n4uI4wD';
  $export['smtp_password'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_port';
  $strongarm->value = '587';
  $export['smtp_port'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_protocol';
  $strongarm->value = 'tls';
  $export['smtp_protocol'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smtp_username';
  $strongarm->value = 'AKIAJDLXQHDDOP55FZBQ';
  $export['smtp_username'] = $strongarm;

  return $export;
}
