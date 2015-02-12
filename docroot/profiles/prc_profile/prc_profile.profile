<?php

/**
 * @file
 * PRC website installation profile.
 */

/**
 * Implements hook_form_alter().
 */
function prc_profile_form_install_configure_form_alter(&$form) {
  $form['site_information']['#access'] = FALSE;
  $form['site_information']['site_name']['#default_value'] = variable_get('site_name');
  $form['site_information']['site_mail']['#default_value'] = variable_get('site_mail');
  $form['admin_account']['account']['mail']['#default_value'] = variable_get('site_mail');
  $form['server_settings']['#access'] = FALSE;
  $form['server_settings']['site_default_country']['#default_value'] = variable_get('site_default_country');
  $form['server_settings']['date_default_timezone']['#default_value'] = variable_get('date_default_timezone');
  $form['server_settings']['clean_url']['#default_value'] = variable_get('clean_url');
  $form['update_notifications']['#access'] = FALSE;
}
