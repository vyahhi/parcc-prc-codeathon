<?php

/**
 * @file
 * Features Builder definitions.
 */

/**
 * Implements hook_features_builders_info().
 */
function features_builder_search_api_features_builders_info() {
  $builders = array(
    'features_builder_search_api' => array(
      'label' => t('Search API'),
      'class' => 'SearchAPIFeaturesBuilder',
    ),
  );
  return $builders;
}
