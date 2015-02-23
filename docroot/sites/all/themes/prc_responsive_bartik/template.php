<?php

function prc_responsive_bartik_preprocess_html(&$variables)
{
  // Add variables for path to theme.
  $variables['base_path'] = base_path();
  $variables['path_to_resbartik'] = drupal_get_path('theme', 'responsive_bartik');

  // Add local.css stylesheet
  if (file_exists(drupal_get_path('theme', 'prc_responsive_bartik') . '/css/local.css')) {
    drupal_add_css(drupal_get_path('theme', 'prc_responsive_bartik') . '/css/local.css',
      array('group' => CSS_THEME, 'every_page' => TRUE));
  }

  // Add body classes if certain regions have content.
  if (!empty($variables['page']['featured'])) {
    $variables['classes_array'][] = 'featured';
  }

  if (!empty($variables['page']['triptych_first'])
    || !empty($variables['page']['triptych_middle'])
    || !empty($variables['page']['triptych_last'])
  ) {
    $variables['classes_array'][] = 'triptych';
  }

  if (!empty($variables['page']['footer_firstcolumn'])
    || !empty($variables['page']['footer_secondcolumn'])
    || !empty($variables['page']['footer_thirdcolumn'])
    || !empty($variables['page']['footer_fourthcolumn'])
  ) {
    $variables['classes_array'][] = 'footer-columns';
  }
}

/**
 * Override or insert variables into the page template for HTML output.
 */
function prc_responsive_bartik_process_html(&$variables)
{
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($variables);
  }
}

/**
 * Override or insert variables into the page template.
 */
function prc_responsive_bartik_process_page(&$variables)
{
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $variables['hide_site_name'] = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($variables['title_suffix']['add_or_remove_shortcut']) && $variables['title']) {
    // Add a wrapper div using the title_prefix and title_suffix render elements.
    $variables['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $variables['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $variables['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }
}

/**
 * Implements hook_preprocess_maintenance_page().
 */
function prc_responsive_bartik_preprocess_maintenance_page(&$variables)
{
  // By default, site_name is set to Drupal if no db connection is available
  // or during site installation. Setting site_name to an empty string makes
  // the site and update pages look cleaner.
  // @see template_preprocess_maintenance_page
  if (!$variables['db_is_active']) {
    $variables['site_name'] = '';
  }
  drupal_add_css(drupal_get_path('theme', 'responsive_bartik') . '/css/maintenance-page.css');
}

/**
 * Override or insert variables into the maintenance page template.
 */
function prc_responsive_bartik_process_maintenance_page(&$variables)
{
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $variables['hide_site_name'] = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
}

function prc_responsive_bartik_preprocess_page(&$vars, $hook) {
  if (true) {
    drupal_add_js('http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML', 'external');
    $vars['scripts'] = drupal_get_js(); // necessary in D7?
  }
}

/**
 * Override or insert variables into the node template.
 */
function prc_responsive_bartik_preprocess_node(&$variables)
{
  if ($variables['view_mode'] == 'full' && node_is_page($variables['node'])) {
    $variables['classes_array'][] = 'node-full';
  }
}

/**
 * Override or insert variables into the block template.
 */
function prc_responsive_bartik_preprocess_block(&$variables)
{
  // In the header region visually hide block titles.
  if ($variables['block']->region == 'header') {
    $variables['title_attributes_array']['class'][] = 'element-invisible';
  }
}

/**
 * Implements theme_menu_tree().
 */
function prc_responsive_bartik_menu_tree($variables)
{
  return '<ul class="menu clearfix">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_field__field_type().
 */
function prc_responsive_bartik_field__taxonomy_term_reference($variables)
{
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<h3 class="field-label">' . $variables['label'] . ': </h3>';
  }

  // Render the items.
  $output .= ($variables['element']['#label_display'] == 'inline') ? '<ul class="links inline">' : '<ul class="links">';
  foreach ($variables['items'] as $delta => $item) {
    $output .= '<li class="taxonomy-term-reference-' . $delta . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
  }
  $output .= '</ul>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . (!in_array('clearfix', $variables['classes_array']) ? ' clearfix' : '') . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

function prc_responsive_bartik_ds_search_page($build) {
  if (isset($build['theme_hook_original'])) {
    unset($build['theme_hook_original']);
  }
  return $build;
}

function prc_responsive_bartik_course_outline_item($variables) {
  $output = '';
  $step = $variables['step'];
  $img = $variables['img'];
  $object = $variables['object'];
  $status = $step['status'] ? $step['status'] : t('Not started');
  $node = $object->getNode();
  $w = entity_metadata_wrapper('node', $node);

  if ($node->type == 'pd_module') {
    $length = $w->field_length->value() ?
      '<span>' . '(' . $w->field_length->value() . ')</span><br/>' :
      '';
    $objectives = $w->field_course_objectives->value() ? '<span>' . t('Module Objectives') . ': ' . $w->field_course_objectives->value() . '</span><br/>' : '';
    if (empty($step['link'])) {
      $output = $object->getTitle() . '<br/>' .
        $length .
        $objectives .
        '<span class="course-outline-status">' . $status . '</span>';
    }
    else {
      $output = $img . ' ' .
        l("{$object->getTitle()}<br/>", $step['link'], array('html' => TRUE)) .
        $length .
        $objectives .
        '<span class="course-outline-status">' . $step['status'] . '</span>';
    }
  } else {
    if ($status == 'Complete' || empty($step['link'])) {
      $output = $object->getTitle();
    }
    else {
      $output = l("{$object->getTitle()}", $step['link'], array('html' => TRUE));
    }
  }


  return $output;
}

/**
 * Theme a question selection table, adding drag and drop support.
 */
function prc_responsive_bartik_question_selection_table($variables) {
  $form = $variables['form'];
  drupal_add_tabledrag('question-list', 'match', 'parent', 'qnr-pid', 'qnr-pid', 'qnr-id', TRUE, 1);
  drupal_add_tabledrag('question-list', 'order', 'sibling', 'question-list-weight');

  // Building headers
  $headers = array(t('Preview'), t('Item Type'), t('Actions'), t('Item Order'), t('Item Standard'), t('Delete'));
  if (isset($form['compulsories'])) {
    $headers[] = t('Compulsory');
  }
  $headers[] = t('Weight');
  $headers[] = t('Parent ID');
  $headers[] = array(
    'data' => t('ID'),
    'class' => array('tabledrag-hide'),
  );

  // Building table body
  $rows = array();
  if (!empty($form['titles'])) {
    foreach (element_children($form['titles']) as $id) {
      $form['weights'][$id]['#attributes']['class'] = array('question-list-weight');
      $form['qnr_ids'][$id]['#attributes']['class'] = array('qnr-id');
      $form['qnr_pids'][$id]['#attributes']['class'] = array('qnr-pid');
      $rows[] = _prc_question_preview_quiz_get_question_row($form, $id);
    }
    // Make sure the same fields aren't rendered twice
    unset($form['types'], $form['view_links'], $form['remove_links'], $form['stayers']);
    unset($form['max_scores'], $form['auto_update_max_scores'], $form['revision'], $form['weights'], $form['titles'], $form['compulsories'], $form['qnr_ids'], $form['qnr_pids'], $form['item_orders'], $form['item_standards']);
  }
  $html_attr = array('id' => 'question-list');

  // We hide the table if no questions have been added so that jQuery can show it the moment the first question is being added.
  if (isset($form['no_questions'])) {
    $html_attr['style'] = "display:none;";
  }

  $table = theme('table', array('header' => $headers, 'rows' => $rows, 'attributes' => $html_attr));

  return drupal_render($form['random_settings'])
  . $table
  . drupal_render_children($form);
}

