<?php

/**
 * @file
 * Default simple view template to display a rows in a grid.
 *
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)) : ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<div class="gallery-tiles">
<?php foreach ($rows as $row_number => $columns): ?>
  <div <?php if ($row_classes[$row_number]) { print 'class="row ' . $row_classes[$row_number] .'"';  } ?>>
  <?php foreach ($columns as $column_number => $item): ?>
    <div <?php if ($column_classes[$row_number][$column_number]) { print 'class="small-12 medium-6 large-4 columns ' . $column_classes[$row_number][$column_number] .'"';  } ?>>
      <?php print $item; ?>
    </div>
  <?php endforeach; ?>
  </div>
<?php endforeach; ?>
</div>
