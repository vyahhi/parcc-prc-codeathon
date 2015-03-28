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
  $handler->name = 'node_edit__digital_library_content';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Digital Library Content',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'digital_library_content',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'digital_library_content' => 'digital_library_content',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '54108e3d-b2da-4bf5-9254-4894ecb18e63';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e2ba232d-8eb4-4adb-b8fa-ad50abbfb114';
    $pane->panel = 'middle';
    $pane->type = 'content_state';
    $pane->subtype = 'content_state';
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
    $pane->uuid = 'e2ba232d-8eb4-4adb-b8fa-ad50abbfb114';
    $display->content['new-e2ba232d-8eb4-4adb-b8fa-ad50abbfb114'] = $pane;
    $display->panels['middle'][0] = 'new-e2ba232d-8eb4-4adb-b8fa-ad50abbfb114';
    $pane = new stdClass();
    $pane->pid = 'new-eb175b77-54e5-48f3-9c3c-d9fc718f224a';
    $pane->panel = 'middle';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '%title',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'eb175b77-54e5-48f3-9c3c-d9fc718f224a';
    $display->content['new-eb175b77-54e5-48f3-9c3c-d9fc718f224a'] = $pane;
    $display->panels['middle'][1] = 'new-eb175b77-54e5-48f3-9c3c-d9fc718f224a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-eb175b77-54e5-48f3-9c3c-d9fc718f224a';
  $handler->conf['display'] = $display;
  $export['node_edit__digital_library_content'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__digital_library_content';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Digital Library Content',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'digital_library_content',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'digital_library_content' => 'digital_library_content',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->uuid = '10881e28-3118-4e8e-a307-be105abdf622';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-29e82e9c-3e03-4cbf-8264-0c32d5a6f549';
    $pane->panel = 'center';
    $pane->type = 'content_state';
    $pane->subtype = 'content_state';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
              1 => 3,
              2 => 7,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '29e82e9c-3e03-4cbf-8264-0c32d5a6f549';
    $display->content['new-29e82e9c-3e03-4cbf-8264-0c32d5a6f549'] = $pane;
    $display->panels['center'][0] = 'new-29e82e9c-3e03-4cbf-8264-0c32d5a6f549';
    $pane = new stdClass();
    $pane->pid = 'new-5df9dfc2-b0f4-4599-8f53-02c1dc60cccc';
    $pane->panel = 'center';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title_heading' => 'span',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5df9dfc2-b0f4-4599-8f53-02c1dc60cccc';
    $display->content['new-5df9dfc2-b0f4-4599-8f53-02c1dc60cccc'] = $pane;
    $display->panels['center'][1] = 'new-5df9dfc2-b0f4-4599-8f53-02c1dc60cccc';
    $pane = new stdClass();
    $pane->pid = 'new-e6129095-5010-4b84-9d6f-2ffb6c19aba8';
    $pane->panel = 'center';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'build_mode' => 'full',
      'identifier' => '',
      'link' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e6129095-5010-4b84-9d6f-2ffb6c19aba8';
    $display->content['new-e6129095-5010-4b84-9d6f-2ffb6c19aba8'] = $pane;
    $display->panels['center'][2] = 'new-e6129095-5010-4b84-9d6f-2ffb6c19aba8';
    $pane = new stdClass();
    $pane->pid = 'new-b68743b8-2b20-429b-89ad-27f947e6d6c0';
    $pane->panel = 'center';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:sharethis';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b68743b8-2b20-429b-89ad-27f947e6d6c0';
    $display->content['new-b68743b8-2b20-429b-89ad-27f947e6d6c0'] = $pane;
    $display->panels['center'][3] = 'new-b68743b8-2b20-429b-89ad-27f947e6d6c0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__digital_library_content'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__trt_district';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'TRT District Readiness View',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'trt_district',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'district' => 'district',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title Readiness';
  $display->uuid = '9c20f60a-ca12-4dd9-a3ee-224aef3dd623';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f5ef389a-e533-489b-9108-2672744fd18e';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'District Readiness Overview',
      'title' => '',
      'body' => 'Overview / instructional copy goes here (click on school name to see admin can add / edit school, request that readiness checks be run, view results of technology checks by school and export all test results data to csv).',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f5ef389a-e533-489b-9108-2672744fd18e';
    $display->content['new-f5ef389a-e533-489b-9108-2672744fd18e'] = $pane;
    $display->panels['middle'][0] = 'new-f5ef389a-e533-489b-9108-2672744fd18e';
    $pane = new stdClass();
    $pane->pid = 'new-1c3fd6c5-df35-4f35-9d5b-503e5d8ab2e2';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<a href="%node:edit-url">Edit district name</a>',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1c3fd6c5-df35-4f35-9d5b-503e5d8ab2e2';
    $display->content['new-1c3fd6c5-df35-4f35-9d5b-503e5d8ab2e2'] = $pane;
    $display->panels['middle'][1] = 'new-1c3fd6c5-df35-4f35-9d5b-503e5d8ab2e2';
    $pane = new stdClass();
    $pane->pid = 'new-e024b3f1-6eca-4e5c-a326-5a882312cffc';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-trt-manage-schools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e024b3f1-6eca-4e5c-a326-5a882312cffc';
    $display->content['new-e024b3f1-6eca-4e5c-a326-5a882312cffc'] = $pane;
    $display->panels['middle'][2] = 'new-e024b3f1-6eca-4e5c-a326-5a882312cffc';
    $pane = new stdClass();
    $pane->pid = 'new-48e2fd47-665f-49f1-a263-b9fe56f1093c';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Manage schools description',
      'title' => '',
      'body' => 'add schools and request readiness checks',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '48e2fd47-665f-49f1-a263-b9fe56f1093c';
    $display->content['new-48e2fd47-665f-49f1-a263-b9fe56f1093c'] = $pane;
    $display->panels['middle'][3] = 'new-48e2fd47-665f-49f1-a263-b9fe56f1093c';
    $pane = new stdClass();
    $pane->pid = 'new-f101267e-aa69-4019-b48c-d011f1d51c9d';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'trt_district_readiness_schools-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_ref_district_target_id' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'f101267e-aa69-4019-b48c-d011f1d51c9d';
    $display->content['new-f101267e-aa69-4019-b48c-d011f1d51c9d'] = $pane;
    $display->panels['middle'][4] = 'new-f101267e-aa69-4019-b48c-d011f1d51c9d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__trt_district'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__trt_school_readiness_view';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'TRT School Readiness View',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'trt_school_readiness_view',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'school' => 'school',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title Readiness';
  $display->uuid = '41927865-41af-4132-ad7c-66a71ae067f2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e09235d5-f9b8-47be-b599-5e5dd15cc764';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'school_readiness_last_capacity_check_result-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_ref_school_target_id' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e09235d5-f9b8-47be-b599-5e5dd15cc764';
    $display->content['new-e09235d5-f9b8-47be-b599-5e5dd15cc764'] = $pane;
    $display->panels['middle'][0] = 'new-e09235d5-f9b8-47be-b599-5e5dd15cc764';
    $pane = new stdClass();
    $pane->pid = 'new-347e0309-14bb-4070-89bd-843879688491';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'admin_title' => 'School Readiness Testing Capacity Check Heading',
      'title' => '',
      'body' => '<h2>Testing capacity checks</h2>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '347e0309-14bb-4070-89bd-843879688491';
    $display->content['new-347e0309-14bb-4070-89bd-843879688491'] = $pane;
    $display->panels['middle'][1] = 'new-347e0309-14bb-4070-89bd-843879688491';
    $pane = new stdClass();
    $pane->pid = 'new-562620d6-c79a-4e2e-922e-515396305ea9';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'school_readiness_last_capacity_check_result-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_ref_school_target_id' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '562620d6-c79a-4e2e-922e-515396305ea9';
    $display->content['new-562620d6-c79a-4e2e-922e-515396305ea9'] = $pane;
    $display->panels['middle'][2] = 'new-562620d6-c79a-4e2e-922e-515396305ea9';
    $pane = new stdClass();
    $pane->pid = 'new-716b17e6-2505-403c-a307-1f0544ce8c2b';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-trt-school-readiness-capaci';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 9,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '716b17e6-2505-403c-a307-1f0544ce8c2b';
    $display->content['new-716b17e6-2505-403c-a307-1f0544ce8c2b'] = $pane;
    $display->panels['middle'][3] = 'new-716b17e6-2505-403c-a307-1f0544ce8c2b';
    $pane = new stdClass();
    $pane->pid = 'new-c2068615-7c35-4855-8a58-df9ac5e9053d';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-trt-school-readiness-system';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 9,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'System checks',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'c2068615-7c35-4855-8a58-df9ac5e9053d';
    $display->content['new-c2068615-7c35-4855-8a58-df9ac5e9053d'] = $pane;
    $display->panels['middle'][4] = 'new-c2068615-7c35-4855-8a58-df9ac5e9053d';
    $pane = new stdClass();
    $pane->pid = 'new-04e25c5c-97dc-4c6d-bc1c-4f50428042ac';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'school_readiness_system_checks-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_ref_school_target_id' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '04e25c5c-97dc-4c6d-bc1c-4f50428042ac';
    $display->content['new-04e25c5c-97dc-4c6d-bc1c-4f50428042ac'] = $pane;
    $display->panels['middle'][5] = 'new-04e25c5c-97dc-4c6d-bc1c-4f50428042ac';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__trt_school_readiness_view'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__trt_state_readiness_view';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'TRT State Readiness View',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'trt_state_readiness_view',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'state' => 'state',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title Readiness';
  $display->uuid = '41927865-41af-4132-ad7c-66a71ae067f2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6e5ea1dd-72ca-4647-a6b6-df46b52c297d';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'State Readiness Overview Copy',
      'title' => '',
      'body' => 'Overview / instructional copy goes here (admin can export all test results data for state to csv or click district name to view results of technology checks by school).',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6e5ea1dd-72ca-4647-a6b6-df46b52c297d';
    $display->content['new-6e5ea1dd-72ca-4647-a6b6-df46b52c297d'] = $pane;
    $display->panels['middle'][0] = 'new-6e5ea1dd-72ca-4647-a6b6-df46b52c297d';
    $pane = new stdClass();
    $pane->pid = 'new-1991df92-3c85-441c-ba76-931b6f73ba4d';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'trt_districts-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_ref_trt_state_target_id' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1991df92-3c85-441c-ba76-931b6f73ba4d';
    $display->content['new-1991df92-3c85-441c-ba76-931b6f73ba4d'] = $pane;
    $display->panels['middle'][1] = 'new-1991df92-3c85-441c-ba76-931b6f73ba4d';
    $pane = new stdClass();
    $pane->pid = 'new-357a0309-ed14-4166-9bb3-fdbee82bb75c';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-trt-state-check-export';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '357a0309-ed14-4166-9bb3-fdbee82bb75c';
    $display->content['new-357a0309-ed14-4166-9bb3-fdbee82bb75c'] = $pane;
    $display->panels['middle'][2] = 'new-357a0309-ed14-4166-9bb3-fdbee82bb75c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__trt_state_readiness_view'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'PD Course',
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
              'pd_course' => 'pd_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '838f0aaa-517c-4b8d-ba67-e396b6c7d3ad';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-eaefe678-6bd2-4bd7-bdd0-12ed5c6db557';
    $pane->panel = 'left';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = 'eaefe678-6bd2-4bd7-bdd0-12ed5c6db557';
    $display->content['new-eaefe678-6bd2-4bd7-bdd0-12ed5c6db557'] = $pane;
    $display->panels['left'][0] = 'new-eaefe678-6bd2-4bd7-bdd0-12ed5c6db557';
    $pane = new stdClass();
    $pane->pid = 'new-b1bfb32b-1b18-4ffe-bc6e-a36d885d3a2d';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'course-outline';
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
    $pane->uuid = 'b1bfb32b-1b18-4ffe-bc6e-a36d885d3a2d';
    $display->content['new-b1bfb32b-1b18-4ffe-bc6e-a36d885d3a2d'] = $pane;
    $display->panels['left'][1] = 'new-b1bfb32b-1b18-4ffe-bc6e-a36d885d3a2d';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Exam',
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
              'quiz' => 'quiz',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6694516f-5b2c-4c89-804f-1748ae9da048';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-173ef7c8-627c-4ffb-82c7-517f83c7974d';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '173ef7c8-627c-4ffb-82c7-517f83c7974d';
    $display->content['new-173ef7c8-627c-4ffb-82c7-517f83c7974d'] = $pane;
    $display->panels['middle'][0] = 'new-173ef7c8-627c-4ffb-82c7-517f83c7974d';
    $pane = new stdClass();
    $pane->pid = 'new-a388be83-6d77-470c-adf3-d79ecc3563d7';
    $pane->panel = 'middle';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'build_mode' => 'full',
      'identifier' => '',
      'link' => 0,
      'context' => 'argument_entity_id:node_1',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a388be83-6d77-470c-adf3-d79ecc3563d7';
    $display->content['new-a388be83-6d77-470c-adf3-d79ecc3563d7'] = $pane;
    $display->panels['middle'][1] = 'new-a388be83-6d77-470c-adf3-d79ecc3563d7';
    $pane = new stdClass();
    $pane->pid = 'new-e10bdac5-cc69-4cb5-abb9-98443716479a';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'assessment_item_list-panel_pane_1';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'parent_vid' => '%node:vid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e10bdac5-cc69-4cb5-abb9-98443716479a';
    $display->content['new-e10bdac5-cc69-4cb5-abb9-98443716479a'] = $pane;
    $display->panels['middle'][2] = 'new-e10bdac5-cc69-4cb5-abb9-98443716479a';
    $pane = new stdClass();
    $pane->pid = 'new-5191f8c4-630f-4d52-a599-a94e80c3cfa6';
    $pane->panel = 'middle';
    $pane->type = 'quiz_questions_pane';
    $pane->subtype = 'quiz_questions_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '5191f8c4-630f-4d52-a599-a94e80c3cfa6';
    $display->content['new-5191f8c4-630f-4d52-a599-a94e80c3cfa6'] = $pane;
    $display->panels['middle'][3] = 'new-5191f8c4-630f-4d52-a599-a94e80c3cfa6';
    $pane = new stdClass();
    $pane->pid = 'new-9d75fce3-4c32-4075-b0c5-6bb1a621dc5b';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Empty Placeholder for Item Preview',
      'title' => '',
      'body' => '&nbsp;',
      'format' => 'filtered_html',
      'substitute' => 0,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'item-preview-pane',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '9d75fce3-4c32-4075-b0c5-6bb1a621dc5b';
    $display->content['new-9d75fce3-4c32-4075-b0c5-6bb1a621dc5b'] = $pane;
    $display->panels['middle'][4] = 'new-9d75fce3-4c32-4075-b0c5-6bb1a621dc5b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-173ef7c8-627c-4ffb-82c7-517f83c7974d';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_add_system_check__add_system_check';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'add_system_check';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Add System Check',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'add_system_check',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'System Check';
  $display->uuid = 'ec48d5bf-92e1-4e5d-8756-dcf648f0f696';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4389404f-d9a1-4b47-a3a4-1a3770d6b0ea';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Overview/ Instructional copy:',
      'body' => 'Overview and instructional copy goes here. Consider explaining importance of running system check and how to do it: To prepare school for successful assessment, user can run system check to make sure device or devices meet PARCC minimum requirements. Include instructions that user can run test for on single device and apply the results to multiple devices with same configuration.',
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
    $pane->uuid = '4389404f-d9a1-4b47-a3a4-1a3770d6b0ea';
    $display->content['new-4389404f-d9a1-4b47-a3a4-1a3770d6b0ea'] = $pane;
    $display->panels['middle'][0] = 'new-4389404f-d9a1-4b47-a3a4-1a3770d6b0ea';
    $pane = new stdClass();
    $pane->pid = 'new-15933d22-2acb-46d5-8e97-7729714051ee';
    $pane->panel = 'middle';
    $pane->type = 'pm_existing_pages';
    $pane->subtype = 'pm_existing_pages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      0 => 'task_id',
      'task_id' => 'add_system_check',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '15933d22-2acb-46d5-8e97-7729714051ee';
    $display->content['new-15933d22-2acb-46d5-8e97-7729714051ee'] = $pane;
    $display->panels['middle'][1] = 'new-15933d22-2acb-46d5-8e97-7729714051ee';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-15933d22-2acb-46d5-8e97-7729714051ee';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_add_system_check__add_system_check'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_dlc_revisions_edit__panel_context_b0dcd66b-57c8-4827-8acb-8549c0d89624';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'dlc_revisions_edit';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node edit form from node',
        'keyword' => 'node_form',
        'name' => 'node_edit_form_from_node',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '54d3eb57-c6ae-4cc6-837a-1f1d97177d7b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4a7875d1-827a-4c80-adbc-d392f0d95647';
    $pane->panel = 'middle';
    $pane->type = 'content_state';
    $pane->subtype = 'content_state';
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
    $pane->uuid = '4a7875d1-827a-4c80-adbc-d392f0d95647';
    $display->content['new-4a7875d1-827a-4c80-adbc-d392f0d95647'] = $pane;
    $display->panels['middle'][0] = 'new-4a7875d1-827a-4c80-adbc-d392f0d95647';
    $pane = new stdClass();
    $pane->pid = 'new-e2112264-823b-4879-8856-12671e7c4839';
    $pane->panel = 'middle';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_edit_form_from_node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e2112264-823b-4879-8856-12671e7c4839';
    $display->content['new-e2112264-823b-4879-8856-12671e7c4839'] = $pane;
    $display->panels['middle'][1] = 'new-e2112264-823b-4879-8856-12671e7c4839';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4a7875d1-827a-4c80-adbc-d392f0d95647';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_dlc_revisions_edit__panel_context_b0dcd66b-57c8-4827-8acb-8549c0d89624'] = $handler;

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
  $page->name = 'access_denied';
  $page->task = 'page';
  $page->admin_title = 'Access Denied';
  $page->admin_description = '';
  $page->path = 'access-denied';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_access_denied__panel_context_549693e6-8c91-4544-99f1-605af455af8d';
  $handler->task = 'page';
  $handler->subtask = 'access_denied';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
  $display->title = 'Access Denied';
  $display->uuid = '4ca9815d-5bbc-41c9-abf9-b004b15fd18e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d4b0d67d-80f7-4b1b-a80d-a3ed34d4f278';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
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
      'admin_title' => 'Anonymous Users Access Denied',
      'title' => '',
      'body' => 'If you have a site account, <a href="/user">log in</a> and try to access the page again.',
      'format' => 'full_html',
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
    $pane->uuid = 'd4b0d67d-80f7-4b1b-a80d-a3ed34d4f278';
    $display->content['new-d4b0d67d-80f7-4b1b-a80d-a3ed34d4f278'] = $pane;
    $display->panels['center'][0] = 'new-d4b0d67d-80f7-4b1b-a80d-a3ed34d4f278';
    $pane = new stdClass();
    $pane->pid = 'new-e1d6b045-870d-4635-8735-ca37bee5be68';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Authenticated Access Denied',
      'title' => '',
      'body' => 'You are not allowed to view this content.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e1d6b045-870d-4635-8735-ca37bee5be68';
    $display->content['new-e1d6b045-870d-4635-8735-ca37bee5be68'] = $pane;
    $display->panels['center'][1] = 'new-e1d6b045-870d-4635-8735-ca37bee5be68';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d4b0d67d-80f7-4b1b-a80d-a3ed34d4f278';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['access_denied'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'assessment_detail';
  $page->task = 'page';
  $page->admin_title = 'Assessment Detail';
  $page->admin_description = '';
  $page->path = 'assessment/%node';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_assessment_detail_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'assessment_detail';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
              'quiz' => 'quiz',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ffe8d8e1-421f-40e2-b345-60727fcc4495';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f49effc7-af16-4c26-a6d0-58bc154fd144';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'detail',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f49effc7-af16-4c26-a6d0-58bc154fd144';
    $display->content['new-f49effc7-af16-4c26-a6d0-58bc154fd144'] = $pane;
    $display->panels['middle'][0] = 'new-f49effc7-af16-4c26-a6d0-58bc154fd144';
    $pane = new stdClass();
    $pane->pid = 'new-187ccba2-3aa0-465a-86b4-f72d78b151c3';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'assessment_item_list-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'parent_vid' => '%node:vid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '187ccba2-3aa0-465a-86b4-f72d78b151c3';
    $display->content['new-187ccba2-3aa0-465a-86b4-f72d78b151c3'] = $pane;
    $display->panels['middle'][1] = 'new-187ccba2-3aa0-465a-86b4-f72d78b151c3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f49effc7-af16-4c26-a6d0-58bc154fd144';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['assessment_detail'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'assessments';
  $page->task = 'page';
  $page->admin_title = 'Assessments';
  $page->admin_description = '';
  $page->path = 'assessments/!nid';
  $page->access = array(
    'plugins' => array(),
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
  $page->arguments = array(
    'nid' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_assessments__assessments';
  $handler->task = 'page';
  $handler->subtask = 'assessments';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Assessments',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'assessments',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'assessments',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '73f0dde9-506d-465c-b204-910117771872';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a544d903-fcca-45fb-80e3-d3d66fdee207';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-assessment-left-nav';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a544d903-fcca-45fb-80e3-d3d66fdee207';
    $display->content['new-a544d903-fcca-45fb-80e3-d3d66fdee207'] = $pane;
    $display->panels['left'][0] = 'new-a544d903-fcca-45fb-80e3-d3d66fdee207';
    $pane = new stdClass();
    $pane->pid = 'new-40b1d071-1a00-4d88-87dd-140bbe28eda6';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_lists-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_content_type_value' => 'quiz',
      ),
      'override_title' => 1,
      'override_title_text' => 'My Quiz Lists',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '40b1d071-1a00-4d88-87dd-140bbe28eda6';
    $display->content['new-40b1d071-1a00-4d88-87dd-140bbe28eda6'] = $pane;
    $display->panels['left'][1] = 'new-40b1d071-1a00-4d88-87dd-140bbe28eda6';
    $pane = new stdClass();
    $pane->pid = 'new-5ca788a1-d895-445f-ba1a-7ce3619d6d96';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'assessments-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'digital-library-content-pane',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5ca788a1-d895-445f-ba1a-7ce3619d6d96';
    $display->content['new-5ca788a1-d895-445f-ba1a-7ce3619d6d96'] = $pane;
    $display->panels['right'][0] = 'new-5ca788a1-d895-445f-ba1a-7ce3619d6d96';
    $pane = new stdClass();
    $pane->pid = 'new-1718c304-c930-4da3-b981-ee976bebef32';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-add-quiz';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1718c304-c930-4da3-b981-ee976bebef32';
    $display->content['new-1718c304-c930-4da3-b981-ee976bebef32'] = $pane;
    $display->panels['top'][0] = 'new-1718c304-c930-4da3-b981-ee976bebef32';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5ca788a1-d895-445f-ba1a-7ce3619d6d96';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_assessments__panel_context_f13d6f43-aa94-4c05-953f-f960637462ef';
  $handler->task = 'page';
  $handler->subtask = 'assessments';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Assessments Favorites',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'assessments/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Assessments';
  $display->uuid = 'c36879ba-4bc4-4046-a177-b0aa65c02ab5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c58283c1-07f3-4169-a6e0-fe21d95ba7d4';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-assessment-left-nav';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c58283c1-07f3-4169-a6e0-fe21d95ba7d4';
    $display->content['new-c58283c1-07f3-4169-a6e0-fe21d95ba7d4'] = $pane;
    $display->panels['left'][0] = 'new-c58283c1-07f3-4169-a6e0-fe21d95ba7d4';
    $pane = new stdClass();
    $pane->pid = 'new-27c00858-8dbb-468b-b5e7-5e3bdec13f45';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'assessments_filtered_by_favorites-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'nid' => '%nid:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '27c00858-8dbb-468b-b5e7-5e3bdec13f45';
    $display->content['new-27c00858-8dbb-468b-b5e7-5e3bdec13f45'] = $pane;
    $display->panels['right'][0] = 'new-27c00858-8dbb-468b-b5e7-5e3bdec13f45';
    $pane = new stdClass();
    $pane->pid = 'new-24cadd88-1bc8-413e-aec2-65f3645d9c0c';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-add-quiz';
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
    $pane->uuid = '24cadd88-1bc8-413e-aec2-65f3645d9c0c';
    $display->content['new-24cadd88-1bc8-413e-aec2-65f3645d9c0c'] = $pane;
    $display->panels['top'][0] = 'new-24cadd88-1bc8-413e-aec2-65f3645d9c0c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
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
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'create digital_library_content content',
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
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3f310bfb-37ee-450f-9a8d-10349fd54ac3';
    $display->content['new-3f310bfb-37ee-450f-9a8d-10349fd54ac3'] = $pane;
    $display->panels['center'][2] = 'new-3f310bfb-37ee-450f-9a8d-10349fd54ac3';
    $pane = new stdClass();
    $pane->pid = 'new-d31702e5-6d20-48de-b836-e3bf6507a118';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'admin_content_view-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 8,
              1 => 3,
              2 => 7,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'd31702e5-6d20-48de-b836-e3bf6507a118';
    $display->content['new-d31702e5-6d20-48de-b836-e3bf6507a118'] = $pane;
    $display->panels['center'][3] = 'new-d31702e5-6d20-48de-b836-e3bf6507a118';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_administration_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'course_management';
  $page->task = 'page';
  $page->admin_title = 'Course Management';
  $page->admin_description = 'List of courses for course managers. Not for end-users.';
  $page->path = 'admin-course';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer course',
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
  $handler->name = 'page_course_management_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'course_management';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
  $display->title = 'PRC Courses';
  $display->uuid = 'bff662e2-112a-4fe0-8fd6-22043e23f452';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-018fbe71-12ea-4e52-a5ba-d792d2e7b24c';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-add-course';
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
    $pane->uuid = '018fbe71-12ea-4e52-a5ba-d792d2e7b24c';
    $display->content['new-018fbe71-12ea-4e52-a5ba-d792d2e7b24c'] = $pane;
    $display->panels['center'][0] = 'new-018fbe71-12ea-4e52-a5ba-d792d2e7b24c';
    $pane = new stdClass();
    $pane->pid = 'new-2bb05a6e-517a-4e52-a106-1c21bc834663';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'course_management-panel_pane_1';
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
    $pane->locks = array();
    $pane->uuid = '2bb05a6e-517a-4e52-a106-1c21bc834663';
    $display->content['new-2bb05a6e-517a-4e52-a106-1c21bc834663'] = $pane;
    $display->panels['center'][1] = 'new-2bb05a6e-517a-4e52-a106-1c21bc834663';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['course_management'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'digital_library';
  $page->task = 'page';
  $page->admin_title = 'Digital Library';
  $page->admin_description = 'This is the public view of our digital library content';
  $page->path = 'digital-library/!nid';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Digital Library',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'nid' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_digital_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'digital_library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Digital Library',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'digital-library',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Digital Library';
  $display->uuid = 'be6de706-bbff-4426-b19e-ffa4338520c8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-08e6f7ea-0373-432a-b119-96f1386c68f3';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-digital-library-left-nav';
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
    $pane->uuid = '08e6f7ea-0373-432a-b119-96f1386c68f3';
    $display->content['new-08e6f7ea-0373-432a-b119-96f1386c68f3'] = $pane;
    $display->panels['middle'][0] = 'new-08e6f7ea-0373-432a-b119-96f1386c68f3';
    $pane = new stdClass();
    $pane->pid = 'new-a5f8bc52-9761-4119-b636-2c90f803f7c3';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_lists-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_content_type_value' => 'digital_library_content',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a5f8bc52-9761-4119-b636-2c90f803f7c3';
    $display->content['new-a5f8bc52-9761-4119-b636-2c90f803f7c3'] = $pane;
    $display->panels['middle'][1] = 'new-a5f8bc52-9761-4119-b636-2c90f803f7c3';
    $pane = new stdClass();
    $pane->pid = 'new-0f8bd040-cca5-45f5-8792-16699005790b';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'digital_library_view-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'digital-library-content-pane',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0f8bd040-cca5-45f5-8792-16699005790b';
    $display->content['new-0f8bd040-cca5-45f5-8792-16699005790b'] = $pane;
    $display->panels['middle'][2] = 'new-0f8bd040-cca5-45f5-8792-16699005790b';
    $pane = new stdClass();
    $pane->pid = 'new-30e765e5-3410-4e05-9d69-0dc872428ade';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'digital_library_view-panel_pane_1';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'digital-library-content-pane',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '30e765e5-3410-4e05-9d69-0dc872428ade';
    $display->content['new-30e765e5-3410-4e05-9d69-0dc872428ade'] = $pane;
    $display->panels['middle'][3] = 'new-30e765e5-3410-4e05-9d69-0dc872428ade';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_digital_library_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'digital_library';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Digital Library Favorites',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'digital-library/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4b9ee756-15ad-410b-bb48-64f625a1b4ca';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b826acdb-e697-4466-83c8-3ca602bdec79';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-digital-library-left-nav';
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
    $pane->uuid = 'b826acdb-e697-4466-83c8-3ca602bdec79';
    $display->content['new-b826acdb-e697-4466-83c8-3ca602bdec79'] = $pane;
    $display->panels['left'][0] = 'new-b826acdb-e697-4466-83c8-3ca602bdec79';
    $pane = new stdClass();
    $pane->pid = 'new-52852f34-a1e9-4b6c-98ed-42c4874eedaf';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_lists-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_content_type_value' => 'digital_library_content',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '52852f34-a1e9-4b6c-98ed-42c4874eedaf';
    $display->content['new-52852f34-a1e9-4b6c-98ed-42c4874eedaf'] = $pane;
    $display->panels['left'][1] = 'new-52852f34-a1e9-4b6c-98ed-42c4874eedaf';
    $pane = new stdClass();
    $pane->pid = 'new-a88f9625-5618-4bd4-bca6-9d2944e43c06';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'digital_library_favorites-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'nid' => '%nid:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a88f9625-5618-4bd4-bca6-9d2944e43c06';
    $display->content['new-a88f9625-5618-4bd4-bca6-9d2944e43c06'] = $pane;
    $display->panels['right'][0] = 'new-a88f9625-5618-4bd4-bca6-9d2944e43c06';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b826acdb-e697-4466-83c8-3ca602bdec79';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['digital_library'] = $page;

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
  $page->path = 'professional-development/!nid';
  $page->access = array(
    'plugins' => array(),
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
  $page->arguments = array(
    'nid' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
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
    'title' => 'Professional Development',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'professional-development',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Professional Development';
  $display->uuid = '527e0755-07d9-436f-bd38-87d765c2dbfb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1c34a962-b726-4457-a670-21564e8399e3';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-professional-development-le';
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
    $pane->uuid = '1c34a962-b726-4457-a670-21564e8399e3';
    $display->content['new-1c34a962-b726-4457-a670-21564e8399e3'] = $pane;
    $display->panels['left'][0] = 'new-1c34a962-b726-4457-a670-21564e8399e3';
    $pane = new stdClass();
    $pane->pid = 'new-29252795-aee5-41ca-a70f-a7b137977ba6';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_lists-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_content_type_value' => 'pd_course',
      ),
      'override_title' => 1,
      'override_title_text' => 'My PD Lists',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '29252795-aee5-41ca-a70f-a7b137977ba6';
    $display->content['new-29252795-aee5-41ca-a70f-a7b137977ba6'] = $pane;
    $display->panels['left'][1] = 'new-29252795-aee5-41ca-a70f-a7b137977ba6';
    $pane = new stdClass();
    $pane->pid = 'new-45f1600e-7e23-47e8-bf89-dbf7817fa882';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'professional_development_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'digital-library-content-pane',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '45f1600e-7e23-47e8-bf89-dbf7817fa882';
    $display->content['new-45f1600e-7e23-47e8-bf89-dbf7817fa882'] = $pane;
    $display->panels['right'][0] = 'new-45f1600e-7e23-47e8-bf89-dbf7817fa882';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_professional_development_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'professional_development';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Professional Development Favorites',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'professional-development/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Professional Development Favorites';
  $display->uuid = '16e9b363-4da6-4914-bb34-05186e577184';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-96916d0f-f201-4613-9211-d203959fbb4b';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-professional-development-le';
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
    $pane->uuid = '96916d0f-f201-4613-9211-d203959fbb4b';
    $display->content['new-96916d0f-f201-4613-9211-d203959fbb4b'] = $pane;
    $display->panels['left'][0] = 'new-96916d0f-f201-4613-9211-d203959fbb4b';
    $pane = new stdClass();
    $pane->pid = 'new-3fa14771-425a-4491-a80d-e09baa64bb35';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_lists-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_content_type_value' => 'pd_course',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3fa14771-425a-4491-a80d-e09baa64bb35';
    $display->content['new-3fa14771-425a-4491-a80d-e09baa64bb35'] = $pane;
    $display->panels['left'][1] = 'new-3fa14771-425a-4491-a80d-e09baa64bb35';
    $pane = new stdClass();
    $pane->pid = 'new-93fcb318-4639-4227-88ba-8fc9a6601c33';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'professional_development_favorites-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'nid' => '%nid:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '93fcb318-4639-4227-88ba-8fc9a6601c33';
    $display->content['new-93fcb318-4639-4227-88ba-8fc9a6601c33'] = $pane;
    $display->panels['right'][0] = 'new-93fcb318-4639-4227-88ba-8fc9a6601c33';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3fa14771-425a-4491-a80d-e09baa64bb35';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['professional_development'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'technology_readiness_tool';
  $page->task = 'page';
  $page->admin_title = 'Technology Readiness Tool';
  $page->admin_description = '';
  $page->path = 'technology-readiness';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_technology_readiness_tool__panel_context_077a561a-98b2-475e-851a-802074898ef2';
  $handler->task = 'page';
  $handler->subtask = 'technology_readiness_tool';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '82a3d58f-0d47-47e6-aa20-39a5cc5c58b3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2a28fb63-8db2-4815-aaec-20c85b328e10';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'TRT Overview',
      'title' => '',
      'body' => 'Overview / instructional copy goes here. Consider explaining importance of testing prior to assessment to increase chances of successful assessment.',
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
    $pane->uuid = '2a28fb63-8db2-4815-aaec-20c85b328e10';
    $display->content['new-2a28fb63-8db2-4815-aaec-20c85b328e10'] = $pane;
    $display->panels['middle'][0] = 'new-2a28fb63-8db2-4815-aaec-20c85b328e10';
    $pane = new stdClass();
    $pane->pid = 'new-6290ccc4-0d21-41b0-863c-6be058d16720';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'schools-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_contact_email_value' => '%user:mail',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6290ccc4-0d21-41b0-863c-6be058d16720';
    $display->content['new-6290ccc4-0d21-41b0-863c-6be058d16720'] = $pane;
    $display->panels['middle'][1] = 'new-6290ccc4-0d21-41b0-863c-6be058d16720';
    $pane = new stdClass();
    $pane->pid = 'new-11d0e2fe-0a95-46a8-a465-d09687a7a2ec';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => 'Important: If you are a school administrator, please run these checks from your school readiness page. Contact your District Administrator to have the link to that page emailed to you.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '11d0e2fe-0a95-46a8-a465-d09687a7a2ec';
    $display->content['new-11d0e2fe-0a95-46a8-a465-d09687a7a2ec'] = $pane;
    $display->panels['middle'][2] = 'new-11d0e2fe-0a95-46a8-a465-d09687a7a2ec';
    $pane = new stdClass();
    $pane->pid = 'new-d56b281a-9e13-428d-851e-44cae81b83fa';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-trt-system-check';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'd56b281a-9e13-428d-851e-44cae81b83fa';
    $display->content['new-d56b281a-9e13-428d-851e-44cae81b83fa'] = $pane;
    $display->panels['middle'][3] = 'new-d56b281a-9e13-428d-851e-44cae81b83fa';
    $pane = new stdClass();
    $pane->pid = 'new-28e21aeb-70fe-4bd0-8053-410e0a2cb71f';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'TRT Page System Check section',
      'title' => '',
      'body' => 'Description of test and importance of running it: The system check assesses whether a device or similar configuration of devices meets the PARCC minimum requirements.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '28e21aeb-70fe-4bd0-8053-410e0a2cb71f';
    $display->content['new-28e21aeb-70fe-4bd0-8053-410e0a2cb71f'] = $pane;
    $display->panels['middle'][4] = 'new-28e21aeb-70fe-4bd0-8053-410e0a2cb71f';
    $pane = new stdClass();
    $pane->pid = 'new-f5dbc452-0fe3-47b0-9755-d74d578ee08b';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-trt-testing-capacity-check';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'f5dbc452-0fe3-47b0-9755-d74d578ee08b';
    $display->content['new-f5dbc452-0fe3-47b0-9755-d74d578ee08b'] = $pane;
    $display->panels['middle'][5] = 'new-f5dbc452-0fe3-47b0-9755-d74d578ee08b';
    $pane = new stdClass();
    $pane->pid = 'new-528f3dd8-81b2-4af6-a5c5-df57a5b4e82c';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'TRT Page Capacity Check',
      'title' => '',
      'body' => 'Description of test and importance of running it: The testing capacity check assesses whether your school has sufficient bandwidth and a sufficient number of devices that meet PARCC minimum requirement in order to run a successful assessment.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '528f3dd8-81b2-4af6-a5c5-df57a5b4e82c';
    $display->content['new-528f3dd8-81b2-4af6-a5c5-df57a5b4e82c'] = $pane;
    $display->panels['middle'][6] = 'new-528f3dd8-81b2-4af6-a5c5-df57a5b4e82c';
    $pane = new stdClass();
    $pane->pid = 'new-fbfa2a96-5352-4251-a9a9-c5ec64b3b763';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-trt-district-add';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'fbfa2a96-5352-4251-a9a9-c5ec64b3b763';
    $display->content['new-fbfa2a96-5352-4251-a9a9-c5ec64b3b763'] = $pane;
    $display->panels['middle'][7] = 'new-fbfa2a96-5352-4251-a9a9-c5ec64b3b763';
    $pane = new stdClass();
    $pane->pid = 'new-2639295c-be52-4569-a027-c64a045a7a1e';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'trt_districts-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '2639295c-be52-4569-a027-c64a045a7a1e';
    $display->content['new-2639295c-be52-4569-a027-c64a045a7a1e'] = $pane;
    $display->panels['middle'][8] = 'new-2639295c-be52-4569-a027-c64a045a7a1e';
    $pane = new stdClass();
    $pane->pid = 'new-e9c22381-16b2-4fbc-91a5-2adcd2a58b2b';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'trt_states-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_contact_email_value' => '%user:mail',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = 'e9c22381-16b2-4fbc-91a5-2adcd2a58b2b';
    $display->content['new-e9c22381-16b2-4fbc-91a5-2adcd2a58b2b'] = $pane;
    $display->panels['middle'][9] = 'new-e9c22381-16b2-4fbc-91a5-2adcd2a58b2b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['technology_readiness_tool'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'test_search';
  $page->task = 'page';
  $page->admin_title = 'PRC Search';
  $page->admin_description = '';
  $page->path = 'search-content';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_test_search_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'test_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cbe3f39c-e3ca-43c5-8a0b-8ab1dbfc54e1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8fbd3cbf-b5a6-4ee2-ba15-1e61fd355222';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Filters section title',
      'title' => 'Filters',
      'body' => '&nbsp;',
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
    $pane->uuid = '8fbd3cbf-b5a6-4ee2-ba15-1e61fd355222';
    $display->content['new-8fbd3cbf-b5a6-4ee2-ba15-1e61fd355222'] = $pane;
    $display->panels['left'][0] = 'new-8fbd3cbf-b5a6-4ee2-ba15-1e61fd355222';
    $pane = new stdClass();
    $pane->pid = 'new-17342757-dda5-4c9e-954b-a2f4e53fa5b3';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'current_search-digital_library_content_index_cu';
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
    $pane->uuid = '17342757-dda5-4c9e-954b-a2f4e53fa5b3';
    $display->content['new-17342757-dda5-4c9e-954b-a2f4e53fa5b3'] = $pane;
    $display->panels['left'][1] = 'new-17342757-dda5-4c9e-954b-a2f4e53fa5b3';
    $pane = new stdClass();
    $pane->pid = 'new-79a95d1a-c69f-4374-9c2d-d9416423d811';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-qljCvPrFwz2lsoYkRV80eIR1ZCZPkn9a';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'By Content Type',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '79a95d1a-c69f-4374-9c2d-d9416423d811';
    $display->content['new-79a95d1a-c69f-4374-9c2d-d9416423d811'] = $pane;
    $display->panels['left'][2] = 'new-79a95d1a-c69f-4374-9c2d-d9416423d811';
    $pane = new stdClass();
    $pane->pid = 'new-204f7688-9bb4-4866-99ca-e1d027cba677';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-8YD0ORXnf15RmHjc1kuMcDzadV4UCNUv';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'By Author',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '204f7688-9bb4-4866-99ca-e1d027cba677';
    $display->content['new-204f7688-9bb4-4866-99ca-e1d027cba677'] = $pane;
    $display->panels['left'][3] = 'new-204f7688-9bb4-4866-99ca-e1d027cba677';
    $pane = new stdClass();
    $pane->pid = 'new-6d11915b-1b1b-46d0-ad04-f5b9e769ad9d';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-pWAc1pbg0SoUyiffCBHQqBEHqxhbPVrr';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'By Media Type',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '6d11915b-1b1b-46d0-ad04-f5b9e769ad9d';
    $display->content['new-6d11915b-1b1b-46d0-ad04-f5b9e769ad9d'] = $pane;
    $display->panels['left'][4] = 'new-6d11915b-1b1b-46d0-ad04-f5b9e769ad9d';
    $pane = new stdClass();
    $pane->pid = 'new-c06a32e0-0f7d-4f70-be63-114448113865';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-splzrEBHlMTSpO0ED8EA2VdZ1nxq9IVW';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'By Subject',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'c06a32e0-0f7d-4f70-be63-114448113865';
    $display->content['new-c06a32e0-0f7d-4f70-be63-114448113865'] = $pane;
    $display->panels['left'][5] = 'new-c06a32e0-0f7d-4f70-be63-114448113865';
    $pane = new stdClass();
    $pane->pid = 'new-704c8214-55a3-48c8-9627-388e7d0d2fd0';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-8ufqk1w5dk6qQWaOPPhG7ofNMvx1f8po';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'By Standard',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '704c8214-55a3-48c8-9627-388e7d0d2fd0';
    $display->content['new-704c8214-55a3-48c8-9627-388e7d0d2fd0'] = $pane;
    $display->panels['left'][6] = 'new-704c8214-55a3-48c8-9627-388e7d0d2fd0';
    $pane = new stdClass();
    $pane->pid = 'new-7ba89190-8c89-4efb-a73d-0fda4fc0d5b7';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'test_search_two-panel_pane_1';
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
    $pane->uuid = '7ba89190-8c89-4efb-a73d-0fda4fc0d5b7';
    $display->content['new-7ba89190-8c89-4efb-a73d-0fda4fc0d5b7'] = $pane;
    $display->panels['right'][0] = 'new-7ba89190-8c89-4efb-a73d-0fda4fc0d5b7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['test_search'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'trt_district_manage_schools';
  $page->task = 'page';
  $page->admin_title = 'TRT District Manage Schools';
  $page->admin_description = '';
  $page->path = 'node/%node/manage-schools';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'create school content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'edit any school content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_trt_district_manage_schools__panel_context_e6b777e2-2cc7-4bb3-9779-a08b94593dbc';
  $handler->task = 'page';
  $handler->subtask = 'trt_district_manage_schools';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'District Manage Schools',
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
              'district' => 'district',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Is VBO',
            'php' => 'return array_key_exists(\'op\', $_POST);',
          ),
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Manage Schools';
  $display->uuid = 'e7f4ed18-2b40-41cb-8c17-6cf861c34fae';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-801bfd73-9449-4c56-ae6e-27716d1ab447';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Manage Schools Overview',
      'title' => '',
      'body' => 'Overview / instructional copy goes here: user can add/edit school information and request readiness checks. Consider describing information needed for each school (school name and email address of person responsible for running readiness checks at each school).',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '801bfd73-9449-4c56-ae6e-27716d1ab447';
    $display->content['new-801bfd73-9449-4c56-ae6e-27716d1ab447'] = $pane;
    $display->panels['middle'][0] = 'new-801bfd73-9449-4c56-ae6e-27716d1ab447';
    $pane = new stdClass();
    $pane->pid = 'new-efcc0d5a-8652-4a19-be2a-a2ccf029eacc';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-trt-manage-schools-add-form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'efcc0d5a-8652-4a19-be2a-a2ccf029eacc';
    $display->content['new-efcc0d5a-8652-4a19-be2a-a2ccf029eacc'] = $pane;
    $display->panels['middle'][1] = 'new-efcc0d5a-8652-4a19-be2a-a2ccf029eacc';
    $pane = new stdClass();
    $pane->pid = 'new-e19f6de6-b37f-4d05-b4d3-1c286300e87e';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'trt_district_schools-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_ref_district_target_id' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e19f6de6-b37f-4d05-b4d3-1c286300e87e';
    $display->content['new-e19f6de6-b37f-4d05-b4d3-1c286300e87e'] = $pane;
    $display->panels['middle'][2] = 'new-e19f6de6-b37f-4d05-b4d3-1c286300e87e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_trt_district_manage_schools__panel_context_6d1a332a-1fcd-42e3-b192-0d7271483c7c';
  $handler->task = 'page';
  $handler->subtask = 'trt_district_manage_schools';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'District Request Readiness Checks',
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
              'district' => 'district',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Is VBO',
            'php' => 'return array_key_exists(\'op\', $_POST);',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Request Readiness Checks';
  $display->uuid = 'e7f4ed18-2b40-41cb-8c17-6cf861c34fae';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e19f6de6-b37f-4d05-b4d3-1c286300e87e';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'trt_district_schools-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_ref_district_target_id' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e19f6de6-b37f-4d05-b4d3-1c286300e87e';
    $display->content['new-e19f6de6-b37f-4d05-b4d3-1c286300e87e'] = $pane;
    $display->panels['middle'][0] = 'new-e19f6de6-b37f-4d05-b4d3-1c286300e87e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['trt_district_manage_schools'] = $page;

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
