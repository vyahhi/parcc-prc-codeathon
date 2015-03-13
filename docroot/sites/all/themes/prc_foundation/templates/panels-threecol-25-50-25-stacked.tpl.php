<?php
/**
 * @file
 * Template for a 3 column panel layout.
 *
 * This template provides a three column 25%-50%-25% panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['left']: Content in the left column.
 *   - $content['middle']: Content in the middle column.
 *   - $content['right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="panel-display panel-3col-stacked clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top']): ?>
  <div class="row">
    <div class="columns">
      <div class="inside"><?php print $content['top']; ?></div>
    </div>
  </div>
  <?php endif ?>

  <div class = "row">
    <div class="small-12 large-4 columns">
      <?php print $content['left']; ?>
    </div>

    <div class="small-12 large-4 columns">
      <?php print $content['middle']; ?>
    </div>

    <div class="small-12 large-4 columns">
      <?php print $content['right']; ?>
    </div>
  </div>

  <?php if ($content['bottom']): ?>
    <div class = "row">
      <div class="columns">
        <div class="inside"><?php print $content['bottom']; ?></div>
      </div>
    </div>
  <?php endif ?>
</div>
