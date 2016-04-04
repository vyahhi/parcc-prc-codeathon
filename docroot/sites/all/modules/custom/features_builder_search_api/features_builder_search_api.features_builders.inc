<?php

/**
 * @file
 * Features Builder definitions.
 */


/**
 * Implements features_builders_info_alter()
 *
 * Use our version of the search api builder rather than the one included by FB
 *
 * @param $builders
 */
function features_builder_search_api_features_builders_info_alter(&$builders) {
  $builders['features_builder_search_api']['class'] = 'SearchAPIFeaturesBuilder';
}
