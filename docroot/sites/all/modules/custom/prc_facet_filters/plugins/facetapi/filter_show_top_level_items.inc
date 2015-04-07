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

    $this->collectOnlyParents($build);

    return $this->build;
  }

  /**
   * Collect only items that do not have parents.
   */
  protected function collectOnlyParents($items) {
    foreach ($items as $key => $item) {
      // Run recursively on all children.
      if (empty($item['#item_parents'])) {
        $this->build[] = $item;
      }
    }
  }
}
