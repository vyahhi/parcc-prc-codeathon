<?php

/**
 * @file
 * TAP Uploads theme implementations.
 */

/**
 * Theme implementation for prc_trt_school_uploads_upload_form.
 */
function theme_prc_trt_school_uploads_upload_form(&$variables) {
  $form = $variables['form'];

  $contents = array();

  // Do some custom rendering of the form's "content" element, whose children
  // are the guts of the upload form.
  foreach ($form['contents'] as $key => &$element) {
    if (substr($key, 0, 1) != '#') {
      $row = '<div class="form-content-row clearfix">';
      $row .= '<div class="form-content-col form-content-label">';

      if (!empty($element['#label'])) {
        $row .= check_plain($element['#label']);
        $element['#title'] = NULL;
        if (!empty($element['#required'])) {
          $row .= ' <span class="form-required">*</span>';
        }
      }

      $row .= '</div>';
      $row .= '<div class="form-content-col form-content-element">';
      $row .= render($element);
      $row .= '</div>';
      $row .= '</div>';
      $contents[] = $row;
    }
  }

  // Replace contents with the array we built above.
  $form['contents']['#markup'] = implode('', $contents);
  $form['contents']['#prefix'] = '<div class="form-contents">';
  $form['contents']['#suffix'] = '</div>';

  $output = drupal_render_children($form);

  return $output;
}
