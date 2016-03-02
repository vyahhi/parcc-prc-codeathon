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
  $gallery_view_paths = array(
    'library',
    'assessments',
    'professional-learning'
  );
  if (in_array(request_path(), $gallery_view_paths)) {
    drupal_add_js(path_to_theme() .'/javascripts/vendor/packery.pkgd.min.js');
    drupal_add_js(path_to_theme() .'/javascripts/custom/gallery_view.js');
  }
  if (request_path() == 'library') {
    drupal_add_js(path_to_theme() .'/javascripts/custom/library_gallery_view.js');
    drupal_add_js(path_to_theme() .'/javascripts/custom/prc_utilities.js');
  }
  if (arg(0) == 'search-content') {
    drupal_add_js(path_to_theme() .'/javascripts/custom/search_content.js');
    drupal_add_js(path_to_theme() .'/javascripts/custom/prc_utilities.js');
  }
  $resource_table_paths = array(
    'instructional-tools/formative-instructional-tasks',
    'instructional-tools/speaking-listening',
    'assessments/parcc-released-items'
  );
  if (in_array(request_path(), $resource_table_paths)) {
    drupal_add_js(path_to_theme() .'/javascripts/custom/resource_table.js');
  }
  //Add the .page-node-edit class to the revision edit pages
  if(in_array('page-node-revisions-edit', $variables['classes_array'])){
    $variables['classes_array'][] = 'page-node-edit';
  }
}

/**
 * Implements hook_preprocess_menu_tree()
 */
function prc_foundation_preprocess_menu_tree(&$variables, $hook) {
  // If we are only showing four links, adjust column widths accordingly
  if (substr_count($variables['tree'], 'large-3') == 3) {
    $variables['tree'] = str_replace('small-12 medium-6 large-3', 'small-12 medium-4', $variables['tree']);
  }
}

function prc_foundation_preprocess_page(&$vars, $hook) {
  // We know I hate leaving commented code in here...
  // But soon enough we'll need to put an equation editor in, and we'll need this.
  //  if (true) {
  //    drupal_add_js('http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML', 'external');
  //    $vars['scripts'] = drupal_get_js(); // necessary in D7?
  //  }
  if (isset($vars['node']->type) && $vars['node']->type == 'digital_library_content' && arg(2) != 'edit' && arg(4) != 'edit' && arg(2) != 'prc_revisions' ){
    $vars['theme_hook_suggestions'][] = 'page__ds_2_col';
    drupal_add_js(path_to_theme() .'/javascripts/custom/digital_library_detail.js');
  }

  if (isset($vars['node']->type) && $vars['node']->type == 'pd_course' && arg(2) != 'edit' ){
    drupal_add_js(path_to_theme() .'/javascripts/custom/pd_course_detail.js');
  }

  //Add a class to node pages to indicate whether we are viewing or editing
  if(isset($vars['node']) && arg(2) != 'edit'){
    $vars['classes_array'][] = 'node-view';

    //don't display tabs on assessment view page
    if($vars['node']->type == 'quiz'){
      unset($vars['tabs']);
      if(arg(2) != 'edit'){
        drupal_add_js(path_to_theme().'/javascripts/custom/assessment_detail.js');
      }
    }
  }
  //pages in the assessment path that should not get the page--assessments gallery template
  $not_gallery = array('assessments', 'assessments/diagnostics');
  $path = request_path();
  if(in_array($path, $not_gallery)){
    foreach($vars['theme_hook_suggestions'] as $key => $suggestion){
      if($suggestion === 'page__assessments'){
        unset($vars['theme_hook_suggestions'][$key]);
      }
    }
  }

  //allow for overriding the page template depending on the node content type
  if (isset($vars['node']->type) && arg(2) != 'edit') {
    $nodetype = $vars['node']->type;
    $vars['theme_hook_suggestions'][] = 'page__node__' . $nodetype;
  }
}

function prc_foundation_menu_local_tasks_alter(&$data, $router_item, $root_path){
  if(isset($router_item['page_arguments'][0])){
    $node = $router_item['page_arguments'][0];

    if(isset($node->type) && $node->type === 'quiz'){
      foreach($data['tabs'][0]['output'] as $key => &$tab){
        $link_title = $tab['#link']['title'];
        // tabs hidden on all pages
        $hide = array('Quiz', 'Take', 'My results');
        //If we are viewing then hide view as well.
        if($root_path == 'node/%') {
          $hide[] = 'View';
          if(in_array($link_title, $hide)){
            unset($data['tabs'][0]['output'][$key]);
          }
        }else{
          if(in_array($link_title, $hide)){
            unset($data['tabs'][0]['output'][$key]);
          }
        }
      }
    }
  }
}

/**
 * Implements hook_preprocess_node()
 */
function prc_foundation_preprocess_node(&$vars, $hook) {
  // Add classes for library gallery tiles
  if ($vars['type'] == 'digital_library_content' && isset($vars['field_media_type']['und'][0]['tid'])) {
    $media_type = taxonomy_term_load($vars['field_media_type']['und'][0]['tid']);
    if (isset($media_type->name)) {
      $vars['classes_array'][] = 'media-type-' . strtolower($media_type->name);
    }
  }
  else {
    $vars['classes_array'][] = 'media-type-none';
  }
  // Change 'read more' link and add classes for assessment gallery tiles
  if ($vars['type'] == 'quiz' && isset($vars['field_quiz_type']['und'][0]['tid']) && $vars['view_mode'] == 'teaser') {
    $vars['content']['links']['node']['#links']['node-readmore']['title'] = str_replace('Read more', 'View/Modify', $vars['content']['links']['node']['#links']['node-readmore']['title']);
    $quiz_type = taxonomy_term_load($vars['field_quiz_type']['und'][0]['tid']);
    if (isset($quiz_type->name) && $quiz_type->name == 'PARCC-Released Practice Assessment') {
      $vars['classes_array'][] = 'parcc-assessment';
    }
  }
  if($vars['type'] == 'quiz'){
    $prc_date = format_date($vars['node']->created, 'prc_custom_modules_date_only');
    $vars['submitted'] = "<div class='prc-publish-date'>$prc_date</div>";
  }
}

function prc_foundation_process_node(&$vars, $hook){
  $x = 1;
}

/**
 * Implements hook_preprocess_field()
 */
function prc_foundation_preprocess_field(&$vars, $hook) {
  // Change label for Author Name in digital library full display mode.
  if (isset($vars['element']['#bundle']) && $vars['element']['#bundle'] == 'digital_library_content') {
    if (isset($vars['element']['#field_name']) && $vars['element']['#field_name'] == 'field_author_name' && isset($vars['element']['#view_mode']) && $vars['element']['#view_mode'] == 'full') {
      $vars['label'] = t('By');
    }
  }
}

/**
 * Implements hook_preprocess_taxonomy_term()
 */
function prc_foundation_preprocess_taxonomy_term(&$vars, $hook) {
  if (isset($vars['vocabulary_machine_name']) && $vars['vocabulary_machine_name'] == 'standard') {
    // Link taxonomy term description.
    $vars['content']['description']['#markup'] = '<a href ="' . $vars['term_url'] . '">' . $vars['content']['description']['#markup'] . '</a>';
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


function prc_foundation_menu_tree__menu_assessment($variables){
  return '<div class="menu">' . $variables['tree'] . '</div>';
}

/**
 * Implements theme_links() targeting the assessment menu
 * Formats links for Top Bar http://foundation.zurb.com/docs/components/top-bar.html
 */
function prc_foundation_menu_link__menu_assessment($variables){
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $description = $element['#localized_options']['attributes']['title'];
  unset($element['#localized_options']['attributes']['title']);

  $output = '<ul class="menu">';
  $link= l($element['#title'], $element['#href'], $element['#localized_options']);
  $output .= '<li' . drupal_attributes($element['#attributes']) . '>' . $link . $sub_menu . "</li>\n";
  $output .= '</ul>';

  return $output . '<p class="menu-item-description">'.$description.'</p>';
}

/**
 * Implements theme_links() targeting the main menu specifically.
 * Formats links for Top Bar http://foundation.zurb.com/docs/components/top-bar.html
 */

function prc_foundation_links__system_main_menu($links)
{
  // Get all the main menu links
  $menu_links = menu_tree_output(menu_tree_all_data('main-menu'));

  // Initialize some variables to prevent errors
  $output = '';
  $sub_menu = '';

  foreach ($menu_links as $key => $link) {

    // Add special class needed for Foundation dropdown menu to work
    !empty($link['#below']) ? $link['#attributes']['class'][] = 'has-dropdown' : '';

    // Render top level and make sure we have an actual link
    if (!empty($link['#href'])) {
      $output .= '<li' . drupal_attributes($link['#attributes']) . '>' . l($link['#title'], $link['#href']);
      // Get sub navigation links if they exist
      foreach ($link['#below'] as $key => $sub_link) {
        $external_link = FALSE;
        if (!empty($sub_link['#href'])) {
          //prc-1763  link to seraph should open in a new tab
          if($sub_link ['#href'] === 'formative-external'){
             $external_link = true;
          }
          //PRC-1763 : link to seraph should open in a new tab
          $options = $external_link ? array('attributes' => array('target' => '_blank')) : array();

          $sub_menu .= '<li class="dropdown-item">' . l($sub_link['#title'], $sub_link['#href'], $options) . '</li>';
        }
      }
      $output .= !empty($link['#below']) ? '<ul class="dropdown">' . $sub_menu . '</ul>' : '';

      // Reset dropdown to prevent duplicates
      unset($sub_menu);
      $sub_menu = '';

      $output .= '</li>';
    }
  }
  return $output;
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
      $row =  _prc_question_preview_quiz_get_question_row($form, $id);
      $ids = explode('-', $id);
      $row['class'][] = 'quiz-item-'.$ids[0];
      $rows[] = $row;
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
 * Implements theme_menu_tree() for homepage_menu
 */
function prc_foundation_menu_tree__menu_homepage_menu($variables) {
  return '<ul class="homepage-menu">' . $variables ['tree'] . '</ul>';
}

/**
 * Implements theme_menu_link()
 */
function prc_foundation_menu_link(array $variables) {
  $element = $variables ['element'];
  $sub_menu = '';

  if ($element ['#below']) {
    $sub_menu = drupal_render($element ['#below']);
  }
  // Add foundation classes for homepage menu
  if ($element['#theme'] == 'menu_link__menu_homepage_menu') {
    $element['#attributes']['class'][] = 'columns';
    $element['#attributes']['class'][] = 'small-12';
    $element['#attributes']['class'][] = 'medium-6';
    $element['#attributes']['class'][] = 'large-3';
  }

  $external = false;

  //prc-1763  link to seraph should open in a new tab
  if($element['#href'] === 'http://formative.parcconline.org/dashboard'){
    $external = true;
  }
  $options = $external ? array('attributes' => array('target' => '_blank')) : array();

  $options += $element ['#localized_options'];

  $output = l($element ['#title'], $element ['#href'], $options);
  return '<li' . drupal_attributes($element ['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
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

/**
 * Implements theme_field()
 */
function prc_foundation_field($variables) {
  $output = '';
  $diglib_divider_labels = array("field_link_to_a_url",
    "field_document",
    "field_tags",
    "field_grade_level_unlimited",
    "field_subject",
    "field_genre",
    "field_standard"
  );

  if (isset($variables['element']['#bundle']) && $variables['element']['#bundle'] == 'digital_library_content') {
    if (isset($variables['element']['#field_name']) && in_array($variables['element']['#field_name'], $diglib_divider_labels) && isset($variables['element']['#view_mode']) && $variables['element']['#view_mode'] == 'full') {
      // Render the label with divider, if it's not hidden.
      if (!$variables['label_hidden']) {
        $output .= '<div class="field-label divider"' . $variables['title_attributes'] . '>' . $variables['label'] . '&nbsp;<hr /></div>';
      }
    }
    else {
      // Render the label, if it's not hidden.
      if (!$variables['label_hidden']) {
        $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
      }
    }
  }
  else {
    // Render the label, if it's not hidden.
    if (!$variables['label_hidden']) {
      $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
    }
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * Override theme_checkbox() so that we can use foundation checkbox stylings
 */
function prc_foundation_checkbox($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'checkbox';
  element_set_attributes($element, array('id', 'name', '#return_value' => 'value'));

  // Unchecked checkbox has #value of integer 0.
  if (!empty($element['#checked'])) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, array('form-checkbox'));

  $custom_box = '<span class="prc-checkbox"></span>';

  return '<input' . drupal_attributes($element['#attributes']) . ' />'.$custom_box;
}

function modal_js_settings(){
  drupal_add_js(array(
    'zurb-modal-style' => array(
      // Set modalSize to scale. Not sure if the modal resizes with the window change yet?
      'modalSize' => array(
        'type' => 'scale',
        'width' => 0.7,
        'contentRight' => 0,
        'height' => 'auto',
      ),
      'modalOptions' => array('opacity' => .55, 'background' => '#333'),
      'animation' => 'fadeIn',
      'animationSpeed' => 'slow',
    ),
  ), 'setting');
}

/**
 * Implements hook_process_hook()
 *
 * @param $vars
 */
function prc_foundation_process_flag(&$vars){
  if($vars['flag']->name == 'like_content'){
    $vars['link_text'] = str_replace('Like', '', $vars['link_text']);
    $vars['link_text'] = str_replace('Undo', '', $vars['link_text']);
  }
}

function prc_foundation_theme($existing, $type, $theme, $path){
  return array(
    'foundation_dropdown_menu' => array(
      'path' => drupal_get_path('theme', 'prc_foundation').'/templates/',
      'template' => 'foundation-dropdown-menu'
    )
  );
}