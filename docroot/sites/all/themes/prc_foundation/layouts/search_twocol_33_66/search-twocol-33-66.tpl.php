<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * each column roughly equal in width.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 */
?>
<div class="panel-display panel-twocol-33-66 clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class = "row">
    <div class="panel-panel panel-col-first small-12 large-4 columns">
      <div class="inside">
        <div id="filter-panel" class="center">
          <ul class="inline">
            <li class="filter-panel-search">
              <?php
              $block = module_invoke('views', 'block_view', '-exp-test_search_two-panel_pane_1');
              print render($block['content']);
              ?>
            </li>
            <li><a href="#" class="filter-panel-toggle-link filters-enabled">Filters</a></li>
            <li><a href="/search-content" class="filter-panel-all-link">Reset</a></li>
          </ul>
        </div>
        <?php print $content['left']; ?>
      </div>
    </div>

    <div class="panel-panel panel-col-last small-12 large-8 columns">
      <div class="inside"><?php print $content['right']; ?></div>
    </div>
  </div>
</div>
