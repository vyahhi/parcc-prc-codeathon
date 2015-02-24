<?php

/**
 * @file
 * Features Builder definitions.
 */

/**
 * Implements hook_features_builders_info().
 */
function features_builder_message_features_builders_info() {
  $builders = array(
    'features_builder_message' => array(
      'label' => t('Message'),
      'class' => 'MessageFeaturesBuilder',
    ),
  );
  return $builders;
}
