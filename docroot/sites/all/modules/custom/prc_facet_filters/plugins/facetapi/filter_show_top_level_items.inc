<?php

/**
 * Plugin that removes all items that are not top-level items.
 */
class FacetapiFilterShowTopLevelItems extends FacetapiFilter {

  // Filtered build.
  protected $build;

  /**
   * Filters items.
   */
  public function execute(array $build) {
    $this->build = array();
    $new_build = array();
    foreach ($build as $key => $item) {
      // If this item has children, remove them.
      if (count($item['#item_children'])) {
        $new_item = $item;
        $new_item['#item_children'] = array();
        $new_build[$key] = $new_item;
      } else {
        $new_build[$key] = $item;
      }
    }

    return $new_build;
  }
}
