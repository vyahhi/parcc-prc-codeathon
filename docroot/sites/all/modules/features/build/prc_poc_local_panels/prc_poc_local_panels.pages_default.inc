<?php
/**
 * @file
 * prc_poc_local_panels.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function prc_poc_local_panels_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Document Edit',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'document' => 'document',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_basic',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'dac59c83-77f2-45fd-9de6-3b74ab6d7024';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ae0a108a-7a09-4036-865a-97d284d394dd';
    $pane->panel = 'center';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_document';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ae0a108a-7a09-4036-865a-97d284d394dd';
    $display->content['new-ae0a108a-7a09-4036-865a-97d284d394dd'] = $pane;
    $display->panels['center'][0] = 'new-ae0a108a-7a09-4036-865a-97d284d394dd';
    $pane = new stdClass();
    $pane->pid = 'new-32cda07f-d20f-4477-a2e5-1d31662407a2';
    $pane->panel = 'center';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '32cda07f-d20f-4477-a2e5-1d31662407a2';
    $display->content['new-32cda07f-d20f-4477-a2e5-1d31662407a2'] = $pane;
    $display->panels['center'][1] = 'new-32cda07f-d20f-4477-a2e5-1d31662407a2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ae0a108a-7a09-4036-865a-97d284d394dd';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_basic';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Sample variant',
    'no_blocks' => 1,
    'css_id' => 'page-wrapper',
    'css' => '/* set a fixed overall width */
  #page-wrapper > .panel-flexible-inside {
    width: 1020px;
    margin-left: auto;
    margin-right: auto;
  }

  /* Add some margin to the main content row. This class was set in the layout designer. */
  #page-wrapper .main-content {
    padding: 0 10px;
  }',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'pipeline' => 'standard',
  );
  $display = new panels_display();
  $display->layout = 'threecol_33_34_33_stacked';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => '',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'content',
          1 => 'sidebar',
        ),
        'parent' => 'main',
        'class' => 'main-content',
      ),
      'content' => array(
        'type' => 'region',
        'title' => 'Content',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      'sidebar' => array(
        'type' => 'region',
        'title' => 'Sidebar',
        'width' => '200',
        'width_type' => 'px',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header',
        ),
        'parent' => 'main',
        'class' => 'header',
      ),
      'header' => array(
        'type' => 'region',
        'title' => 'Header',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
      'sidebar' => NULL,
      'header' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6cf16171-9eed-4715-a06d-bbf810171713';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-79b51686-b758-44d6-960b-22c34502903f';
    $pane->panel = 'bottom';
    $pane->type = 'block';
    $pane->subtype = 'system-navigation';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '79b51686-b758-44d6-960b-22c34502903f';
    $display->content['new-79b51686-b758-44d6-960b-22c34502903f'] = $pane;
    $display->panels['bottom'][0] = 'new-79b51686-b758-44d6-960b-22c34502903f';
    $pane = new stdClass();
    $pane->pid = 'new-cb4d4f5c-ca4a-46be-85e6-8a23aa0923e1';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = 'cb4d4f5c-ca4a-46be-85e6-8a23aa0923e1';
    $display->content['new-cb4d4f5c-ca4a-46be-85e6-8a23aa0923e1'] = $pane;
    $display->panels['left'][0] = 'new-cb4d4f5c-ca4a-46be-85e6-8a23aa0923e1';
    $pane = new stdClass();
    $pane->pid = 'new-4f21f20b-838f-40a8-8f4c-a311b665e83b';
    $pane->panel = 'left';
    $pane->type = 'pane_navigation';
    $pane->subtype = 'pane_navigation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $pane->uuid = '4f21f20b-838f-40a8-8f4c-a311b665e83b';
    $display->content['new-4f21f20b-838f-40a8-8f4c-a311b665e83b'] = $pane;
    $display->panels['left'][1] = 'new-4f21f20b-838f-40a8-8f4c-a311b665e83b';
    $pane = new stdClass();
    $pane->pid = 'new-291c8563-c33a-4eb9-890b-c456895f451c';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'system-navigation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '291c8563-c33a-4eb9-890b-c456895f451c';
    $display->content['new-291c8563-c33a-4eb9-890b-c456895f451c'] = $pane;
    $display->panels['left'][2] = 'new-291c8563-c33a-4eb9-890b-c456895f451c';
    $pane = new stdClass();
    $pane->pid = 'new-1e4b019d-1d0c-4eb6-82b3-603f28cc85bb';
    $pane->panel = 'middle';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '1e4b019d-1d0c-4eb6-82b3-603f28cc85bb';
    $display->content['new-1e4b019d-1d0c-4eb6-82b3-603f28cc85bb'] = $pane;
    $display->panels['middle'][0] = 'new-1e4b019d-1d0c-4eb6-82b3-603f28cc85bb';
    $pane = new stdClass();
    $pane->pid = 'new-eac7ffe9-2df1-4efa-958c-7b1175f1c2fa';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'flag_bookmarks_tab';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 1,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => 'logged-in-user.uid',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'eac7ffe9-2df1-4efa-958c-7b1175f1c2fa';
    $display->content['new-eac7ffe9-2df1-4efa-958c-7b1175f1c2fa'] = $pane;
    $display->panels['right'][0] = 'new-eac7ffe9-2df1-4efa-958c-7b1175f1c2fa';
    $pane = new stdClass();
    $pane->pid = 'new-8772b732-d3cc-4190-ade2-ee6697e8c099';
    $pane->panel = 'top';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '8772b732-d3cc-4190-ade2-ee6697e8c099';
    $display->content['new-8772b732-d3cc-4190-ade2-ee6697e8c099'] = $pane;
    $display->panels['top'][0] = 'new-8772b732-d3cc-4190-ade2-ee6697e8c099';
    $pane = new stdClass();
    $pane->pid = 'new-fe234387-76b2-408c-b3ce-9139f1139fc9';
    $pane->panel = 'top';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $pane->uuid = 'fe234387-76b2-408c-b3ce-9139f1139fc9';
    $display->content['new-fe234387-76b2-408c-b3ce-9139f1139fc9'] = $pane;
    $display->panels['top'][1] = 'new-fe234387-76b2-408c-b3ce-9139f1139fc9';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-1e4b019d-1d0c-4eb6-82b3-603f28cc85bb';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_basic'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function prc_poc_local_panels_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'assessments';
  $page->task = 'page';
  $page->admin_title = 'Assessments';
  $page->admin_description = '';
  $page->path = 'assessments';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Assessments',
    'weight' => '0',
    'name' => 'main-menu',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_assessments_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'assessments';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => FALSE,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Assessments';
  $display->uuid = 'c36879ba-4bc4-4046-a177-b0aa65c02ab5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-33ec2778-1ce4-45b6-84cb-7252cba84429';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Placeholder',
      'title' => 'Placeholder',
      'body' => 'Placeholder',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '33ec2778-1ce4-45b6-84cb-7252cba84429';
    $display->content['new-33ec2778-1ce4-45b6-84cb-7252cba84429'] = $pane;
    $display->panels['center'][0] = 'new-33ec2778-1ce4-45b6-84cb-7252cba84429';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-33ec2778-1ce4-45b6-84cb-7252cba84429';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['assessments'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_administration_page';
  $page->task = 'page';
  $page->admin_title = 'Content Administration Page';
  $page->admin_description = 'PRC Content administration page';
  $page->path = 'admin-content';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 6,
            2 => 5,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_content_administration_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_administration_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Admin Content Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => '',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
    'center' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'PRC Website Content';
  $display->uuid = '6c59397e-f06e-4f8b-8aee-d41104fed820';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1e808230-6c7e-4e77-a023-6f93bde398b7';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-add-content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1e808230-6c7e-4e77-a023-6f93bde398b7';
    $display->content['new-1e808230-6c7e-4e77-a023-6f93bde398b7'] = $pane;
    $display->panels['center'][0] = 'new-1e808230-6c7e-4e77-a023-6f93bde398b7';
    $pane = new stdClass();
    $pane->pid = 'new-46dbc263-aec7-4e18-b8a7-3e061587b2bf';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'digital_library_tree_view-panel_pane_1';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '46dbc263-aec7-4e18-b8a7-3e061587b2bf';
    $display->content['new-46dbc263-aec7-4e18-b8a7-3e061587b2bf'] = $pane;
    $display->panels['center'][1] = 'new-46dbc263-aec7-4e18-b8a7-3e061587b2bf';
    $pane = new stdClass();
    $pane->pid = 'new-3f310bfb-37ee-450f-9a8d-10349fd54ac3';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'admin_content_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3f310bfb-37ee-450f-9a8d-10349fd54ac3';
    $display->content['new-3f310bfb-37ee-450f-9a8d-10349fd54ac3'] = $pane;
    $display->panels['center'][2] = 'new-3f310bfb-37ee-450f-9a8d-10349fd54ac3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_administration_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home_page';
  $page->task = 'page';
  $page->admin_title = 'Home Page';
  $page->admin_description = 'Home Page';
  $page->path = 'front';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'weight' => '0',
    'name' => 'navigation',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => FALSE,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'threecol_25_50_25_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'No Title';
  $display->uuid = '7ddd0fc5-7ade-4b16-b936-828e5483547f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c12ea823-5c49-4670-b44a-05c7807d75a5';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'digital_library_tree_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c12ea823-5c49-4670-b44a-05c7807d75a5';
    $display->content['new-c12ea823-5c49-4670-b44a-05c7807d75a5'] = $pane;
    $display->panels['left'][0] = 'new-c12ea823-5c49-4670-b44a-05c7807d75a5';
    $pane = new stdClass();
    $pane->pid = 'new-3d1f3aec-75cc-4127-a8ac-a4042d5fba3c';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'welcome_anonymous';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3d1f3aec-75cc-4127-a8ac-a4042d5fba3c';
    $display->content['new-3d1f3aec-75cc-4127-a8ac-a4042d5fba3c'] = $pane;
    $display->panels['middle'][0] = 'new-3d1f3aec-75cc-4127-a8ac-a4042d5fba3c';
    $pane = new stdClass();
    $pane->pid = 'new-90507084-c070-42e6-bd8a-6903054c7b6a';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'slideshow_placeholder';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '90507084-c070-42e6-bd8a-6903054c7b6a';
    $display->content['new-90507084-c070-42e6-bd8a-6903054c7b6a'] = $pane;
    $display->panels['middle'][1] = 'new-90507084-c070-42e6-bd8a-6903054c7b6a';
    $pane = new stdClass();
    $pane->pid = 'new-a38223fb-bd9e-4ab5-8e4e-38b154d803de';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a38223fb-bd9e-4ab5-8e4e-38b154d803de';
    $display->content['new-a38223fb-bd9e-4ab5-8e4e-38b154d803de'] = $pane;
    $display->panels['right'][0] = 'new-a38223fb-bd9e-4ab5-8e4e-38b154d803de';
    $pane = new stdClass();
    $pane->pid = 'new-85c92d40-7f61-4212-9faa-03f70e133487';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'favorites_list-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '85c92d40-7f61-4212-9faa-03f70e133487';
    $display->content['new-85c92d40-7f61-4212-9faa-03f70e133487'] = $pane;
    $display->panels['right'][1] = 'new-85c92d40-7f61-4212-9faa-03f70e133487';
    $pane = new stdClass();
    $pane->pid = 'new-2dcda7cb-6604-4301-a7f1-e263104c4691';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'sample_article-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2dcda7cb-6604-4301-a7f1-e263104c4691';
    $display->content['new-2dcda7cb-6604-4301-a7f1-e263104c4691'] = $pane;
    $display->panels['right'][2] = 'new-2dcda7cb-6604-4301-a7f1-e263104c4691';
    $pane = new stdClass();
    $pane->pid = 'new-26ff073d-72f5-436b-a9e1-9f0413618ae8';
    $pane->panel = 'top';
    $pane->type = 'panels_mini';
    $pane->subtype = 'user_welcome_message';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'context_user_1',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => array(
        0 => 'context_user_1',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '26ff073d-72f5-436b-a9e1-9f0413618ae8';
    $display->content['new-26ff073d-72f5-436b-a9e1-9f0413618ae8'] = $pane;
    $display->panels['top'][0] = 'new-26ff073d-72f5-436b-a9e1-9f0413618ae8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-a38223fb-bd9e-4ab5-8e4e-38b154d803de';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'professional_development';
  $page->task = 'page';
  $page->admin_title = 'Professional Development';
  $page->admin_description = 'Professional Development placeholder';
  $page->path = 'professional-development';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Professional Development',
    'weight' => '0',
    'name' => 'main-menu',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_professional_development_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'professional_development';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => FALSE,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Professional Development';
  $display->uuid = '527e0755-07d9-436f-bd38-87d765c2dbfb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-94e1e2e4-d5f1-4c3b-bff0-b07ad7be29cd';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Placeholder',
      'title' => 'Placeholder',
      'body' => 'Placeholder',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '94e1e2e4-d5f1-4c3b-bff0-b07ad7be29cd';
    $display->content['new-94e1e2e4-d5f1-4c3b-bff0-b07ad7be29cd'] = $pane;
    $display->panels['center'][0] = 'new-94e1e2e4-d5f1-4c3b-bff0-b07ad7be29cd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-94e1e2e4-d5f1-4c3b-bff0-b07ad7be29cd';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['professional_development'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'users_administration_page';
  $page->task = 'page';
  $page->admin_title = 'Users Administration Page';
  $page->admin_description = 'PRC Admin user administration page';
  $page->path = 'admin-users';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer users',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_users_administration_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'users_administration_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Admin User Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'PRC Website Users';
  $display->uuid = '6c59397e-f06e-4f8b-8aee-d41104fed820';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2caf0afb-9e59-470d-a493-657e43127b71';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-invite-users';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2caf0afb-9e59-470d-a493-657e43127b71';
    $display->content['new-2caf0afb-9e59-470d-a493-657e43127b71'] = $pane;
    $display->panels['center'][0] = 'new-2caf0afb-9e59-470d-a493-657e43127b71';
    $pane = new stdClass();
    $pane->pid = 'new-199d064b-fff7-404b-acf9-922192423a25';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'admin_user_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '199d064b-fff7-404b-acf9-922192423a25';
    $display->content['new-199d064b-fff7-404b-acf9-922192423a25'] = $pane;
    $display->panels['center'][1] = 'new-199d064b-fff7-404b-acf9-922192423a25';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-199d064b-fff7-404b-acf9-922192423a25';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['users_administration_page'] = $page;

  return $pages;

}
