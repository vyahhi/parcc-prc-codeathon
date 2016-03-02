<?php

/**
 * Plugin that filters active items.
 */
class PRCFacetapiFilterExcludeByNodeUID extends FacetapiFilter {

  /**
   * Filters facet items by node access.
   */
  public function execute(array $build) {
    // Exclude item if its markup is one of excluded items.
    $filtered_build = array();

    global $user;

    foreach ($build as $key => $item) {
      $node = node_load($key);
      if ($node && $node->uid == $user->uid) {
        $filtered_build[$key] = $item;
      }
    }

    return $filtered_build;
  }
}
