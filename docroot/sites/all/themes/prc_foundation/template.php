<?php

/**
 * Implements hook_html_head_alter().
 */
function prc_foundation_html_head_alter(&$head_elements) {
  // HTML5 charset declaration.
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8',
  );

  // Optimize mobile viewport.
  $head_elements['mobile_viewport'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, maximum-scale = 1.0',
    ),
  );
}

/**
 * Implements hook_preprocess_html()
 */
function prc_foundation_preprocess_html(&$variables) {
  drupal_add_css('//fonts.googleapis.com/css?family=Open+Sans|Open+Sans+Condensed:700', array('type' => 'external'));
  if (request_path() == 'digital-library') {
    drupal_add_js(path_to_theme() .'/javascripts/vendor/packery.pkgd.min.js');
    drupal_add_js(path_to_theme() .'/javascripts/custom/gallery_view.js');
  }
}

/**
 * Implements hook_preprocess_breadcrumb()
 */
function prc_foundation_preprocess_breadcrumb(&$variables) {
  // This is a one off example to support theming, but we should probably
  // solve for breadcrumbs more broadly at some point.
  if (request_path() == 'digital-library') {
    $variables['breadcrumb'][] = l('Home', '<front>');
    $variables['breadcrumb'][] = drupal_get_title();
  }
}

function prc_foundation_preprocess_page(&$vars, $hook) {
  if (true) {
    drupal_add_js('http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML', 'external');
    $vars['scripts'] = drupal_get_js(); // necessary in D7?
  }
}

/**
 * Implements hook_preprocess_node()
 */
function prc_foundation_preprocess_node(&$vars, $hook) {
  if ($vars['type'] == 'digital_library_content' && isset($vars['field_media_type']['und'][0]['tid'])) {
    $media_type = taxonomy_term_load($vars['field_media_type']['und'][0]['tid']);
    $vars['classes_array'][] = 'media-type-' . strtolower($media_type->name);
  }
}

/**
 * Implements hook_menu()
 */
function prc_foundation_menu() {
  // Only show Log in link for unauthenticated users
  $items['user/login'] = array(
    'title' => 'Log in',
    'access callback' => 'user_is_anonymous',
    'type' => MENU_DEFAULT_LOCAL_TASK,
  );

  return $items;
}

function prc_foundation_ds_search_page($build) {
  if (isset($build['theme_hook_original'])) {
    unset($build['theme_hook_original']);
  }
  return $build;
}

function prc_foundation_course_outline_item($variables) {
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
function prc_foundation_question_selection_table($variables) {
  $form = $variables['form'];
  drupal_add_tabledrag('question-list', 'match', 'parent', 'qnr-pid', 'qnr-pid', 'qnr-id', TRUE, 1);
  drupal_add_tabledrag('question-list', 'order', 'sibling', 'question-list-weight');

  // Building headers
  $headers = array(t('Preview'), t('Item Type'), t('Actions'), t('Item Standard'), t('PARCC Item?'), t('Delete'));
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
    unset($form['max_scores'], $form['auto_update_max_scores'], $form['revision'], $form['weights'], $form['titles'], $form['compulsories'], $form['qnr_ids'], $form['qnr_pids'], $form['item_standards'], $form['parcc_item']);
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

/**
 * Implements hook_preprocess_entity()
 */
function prc_foundation_preprocess_entity(&$variables) {
  if ($variables['entity_type'] == 'prc_trt' && $variables['view_mode'] == 'full') {
    if ($variables['elements']['#bundle'] == 'system_check') {
      // Adjust display for fields displayed before table.
      $variables['content']['field_ref_school']['#label_display'] = "inline";
      $variables['content']['field_result']['#label_display'] = "hidden";
      $variables['content']['field_result'][0]['#markup'] = "<h2>" . $variables['content']['field_result'][0]['#markup'] . "</h2>";
      $variables['content']['field_name']['#label_display'] = "inline";
      $variables['content']['field_number_of_devices']['#label_display'] = "inline";
      // Build table
      $headers = array(t('Area'), t('System Details'), t('Results'));
      $rows[] = array(
        $variables['content']['field_device_type']['#title'],
        $variables['content']['field_device_type'][0]['#markup'],
        t('N/A'),
      );
      $rows[] = array(
        $variables['content']['field_operating_system']['#title'],
        $variables['content']['field_operating_system'][0]['#markup'],
        $variables['content']['operating_system_pass']['#markup'],
      );
      $rows[] = array(
        $variables['content']['field_monitor_size']['#title'],
        $variables['content']['field_monitor_size'][0]['#markup'],
        $variables['content']['monitor_size_pass']['#markup'],
      );
      $rows[] = array(
        $variables['content']['field_monitor_color_depth']['#title'],
        $variables['content']['field_monitor_color_depth'][0]['#markup'],
        $variables['content']['monitor_color_depth_pass']['#markup'],
      );
      $rows[] = array(
        t('Screen resolution'),
        $variables['content']['field_screen_resolution_width'][0]['#markup'] . ' X ' . $variables['content']['field_screen_resolution_height'][0]['#markup'],
        $variables['content']['screen_resolution_pass']['#markup'],
      );
      $rows[] = array(
        $variables['content']['field_processor_speed']['#title'],
        $variables['content']['field_processor_speed'][0]['#markup'],
        $variables['content']['processor_pass']['#markup'],
      );
      $rows[] = array(
        $variables['content']['field_ram']['#title'],
        $variables['content']['field_ram'][0]['#markup'],
        $variables['content']['ram_pass']['#markup'],
      );
      $rows[] = array(
        $variables['content']['field_browser']['#title'],
        $variables['content']['field_browser'][0]['#markup'] . ' ' . $variables['content']['field_browser_version'][0]['#markup'],
        $variables['content']['browser_pass']['#markup'],
      );
      $rows[] = array(
        $variables['content']['field_browser_cookies_enabled']['#title'],
        $variables['content']['field_browser_cookies_enabled']['#items'][0]['value'] ? 'Yes' : 'No',
        $variables['content']['cookies_pass']['#markup'],
      );
      $rows[] = array(
        $variables['content']['field_browser_javascript_enabled']['#title'],
        $variables['content']['field_browser_javascript_enabled']['#items'][0]['value'] ? 'Yes' : 'No',
        $variables['content']['javascript_pass']['#markup'],
      );
      $rows[] = array(
        $variables['content']['field_browser_images_enabled']['#title'],
        $variables['content']['field_browser_images_enabled']['#items'][0]['value'] ? 'Yes' : 'No',
        $variables['content']['images_pass']['#markup'],
      );
      if (isset($variables['content']['field_jre_version']['#title']) && isset($variables['content']['field_jre_version']['#items'][0]['value'])) {
        $rows[] = array(
          $variables['content']['field_jre_version']['#title'],
          $variables['content']['field_jre_version']['#items'][0]['value'],
          $variables['content']['jre_version_pass']['#markup'],
        );
      }
      else {
        $rows[] = array(
          t('Browser: Java runtime plugin version'),
          t('None'),
          $variables['content']['jre_version_pass']['#markup'],
        );
      }
      $variables['table'] = theme('table', array(
        'header' => $headers,
        'rows' => $rows
      ));
    }
    else if ($variables['elements']['#bundle'] == 'capacity_check') {
      // Adjust display for capacity check results page.
      $variables['content']['field_ref_school']['#label_display'] = "inline";
      $variables['content']['device_capacity_results']['devices_required_passfail']['#title'] = "<h2>".$variables['content']['device_capacity_results']['devices_required_passfail']['#title']."</h2>";
      $variables['content']['device_capacity_results']['devices_required_passfail']['#markup'] = "<h3>".$variables['content']['device_capacity_results']['devices_required_passfail']['#markup']."</h3>";
      $variables['content']['field_number_of_devices']['#label_display'] = "inline";
      $variables['content']['field_number_of_students']['#label_display'] = "inline";
      $variables['content']['field_number_testing_days']['#label_display'] = "inline";
      $variables['content']['field_number_of_sessions']['#label_display'] = "inline";
      $variables['content']['field_sittings_per_student']['#label_display'] = "inline";
      $variables['content']['bandwidth_capacity_results']['bandwidth_status']['#title'] = "<h2>".$variables['content']['bandwidth_capacity_results']['bandwidth_status']['#title']."</h2>";
      $variables['content']['bandwidth_capacity_results']['bandwidth_status']['#markup'] = "<h3>".$variables['content']['bandwidth_capacity_results']['bandwidth_status']['#markup']."</h3>";
      $variables['content']['field_network_connection_type']['#label_display'] = "inline";
      $variables['content']['field_wired_connection_speed']['#label_display'] = "inline";
      $variables['content']['field_wireless_connection_speed']['#label_display'] = "inline";
      $variables['content']['field_number_of_access_points']['#label_display'] = "inline";
      $variables['content']['field_number_of_students']['#label_display'] = "inline";
      $variables['content']['field_speed_of_connection']['#label_display'] = "inline";
    }
  }
}

/**
 * Implements theme_pager()
 */
function prc_foundation_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2><div class="pagination-centered">' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pagination')),
    )) . '</div>';
  }
}