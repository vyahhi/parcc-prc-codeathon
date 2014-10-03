<?php

/**
 * @file
 * Features Builder Drush integration.
 */

/**
 * Implements hook_drush_command().
 */
function features_builder_drush_command() {
  $commands['features-build'] = array(
    'description' => dt('Build Features from current config.'),
    'aliases' => array('fb'),
  );

  return $commands;
}

/**
 * Drush command to build Features.
 */
function drush_features_builder_features_build() {
  if (!drush_confirm(dt('Are you sure you want to build your features?'))) {
    return drush_user_abort();
  }

  features_builder_build();
  drush_print(t('Features build.'));
}
