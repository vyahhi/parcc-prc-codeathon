<?php

/**
 * @file
 * Default theme implementation for entities.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>>
      <?php if ($url): ?>
        <a href="<?php print $url; ?>"><?php print $title; ?></a>
      <?php else: ?>
        <?php print $title; ?>
      <?php endif; ?>
    </h2>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      print render($content['field_ref_school']);
      print render($content['device_capacity_results']);
      print render($content['field_number_of_devices']);
      print render($content['field_number_of_students']);
      print render($content['field_number_testing_days']);
      print render($content['field_number_of_sessions']);
      print render($content['field_sittings_per_student']);
      print "<hr />";
      print render($content['field_number_of_devices']);
      print render($content['devices_required']);
    ?>
    <hr />
    <?php
      print render($content['devices_capacity']);
      print render($content['bandwidth_capacity_results']);
      print render($content['field_network_connection_type']);
      print render($content['field_wired_connection_speed']);
      print render($content['field_wireless_connection_speed']);
      print render($content['field_number_of_access_points']);
      print "<hr />";
      print render($content['field_number_of_students']);
      print render($content['field_speed_of_connection']);
    ?>
  </div>
</div>
