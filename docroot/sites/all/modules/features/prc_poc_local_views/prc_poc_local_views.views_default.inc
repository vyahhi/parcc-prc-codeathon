<?php
/**
 * @file
 * prc_poc_local_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function prc_poc_local_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_content_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Admin Content View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'created' => 'created',
    'type' => 'type',
    'changed' => 'changed',
    'field_author_name' => 'field_author_name',
    'field_document' => 'field_document',
    'state' => 'state',
    'workflow_delete_node' => 'workflow_delete_node',
    'workflow_edit_node' => 'workflow_delete_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_document' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'workflow_delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'workflow_edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: PRC Workflow: Title */
  $handler->display->display_options['fields']['prc_workflow_title']['id'] = 'prc_workflow_title';
  $handler->display->display_options['fields']['prc_workflow_title']['table'] = 'node';
  $handler->display->display_options['fields']['prc_workflow_title']['field'] = 'prc_workflow_title';
  $handler->display->display_options['fields']['prc_workflow_title']['label'] = 'Title';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted On';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Author Name */
  $handler->display->display_options['fields']['field_author_name']['id'] = 'field_author_name';
  $handler->display->display_options['fields']['field_author_name']['table'] = 'field_data_field_author_name';
  $handler->display->display_options['fields']['field_author_name']['field'] = 'field_author_name';
  /* Field: Content: Attach a File */
  $handler->display->display_options['fields']['field_document']['id'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['table'] = 'field_data_field_document';
  $handler->display->display_options['fields']['field_document']['field'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['label'] = 'Attached Files';
  $handler->display->display_options['fields']['field_document']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document']['delta_offset'] = '0';
  /* Field: State Flow: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'node_revision_states';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  /* Field: Content: PRC Workflow: Delete link */
  $handler->display->display_options['fields']['workflow_delete_node']['id'] = 'workflow_delete_node';
  $handler->display->display_options['fields']['workflow_delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['workflow_delete_node']['field'] = 'workflow_delete_node';
  $handler->display->display_options['fields']['workflow_delete_node']['label'] = 'Actions';
  /* Field: Content: PRC Workflow: Edit link */
  $handler->display->display_options['fields']['workflow_edit_node']['id'] = 'workflow_edit_node';
  $handler->display->display_options['fields']['workflow_edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['workflow_edit_node']['field'] = 'workflow_edit_node';
  $handler->display->display_options['fields']['workflow_edit_node']['label'] = 'Edit link';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'digital_library_content' => 'digital_library_content',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Filter all columns';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'nid' => 'nid',
    'prc_workflow_title' => 'prc_workflow_title',
    'created' => 'created',
    'type' => 'type',
    'changed' => 'changed',
    'field_author_name' => 'field_author_name',
    'field_document' => 'field_document',
    'state' => 'state',
  );

  /* Display: Author's Content pane */
  $handler = $view->new_display('panel_pane', 'Author\'s Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'prc_workflow_title' => 'prc_workflow_title',
    'created' => 'created',
    'type' => 'type',
    'changed' => 'changed',
    'field_author_name' => 'field_author_name',
    'field_document' => 'field_document',
    'state' => 'state',
    'workflow_delete_node' => 'workflow_delete_node',
    'workflow_edit_node' => 'workflow_delete_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'prc_workflow_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_document' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'workflow_delete_node' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'workflow_edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: PRC Workflow: Title */
  $handler->display->display_options['fields']['prc_workflow_title']['id'] = 'prc_workflow_title';
  $handler->display->display_options['fields']['prc_workflow_title']['table'] = 'node';
  $handler->display->display_options['fields']['prc_workflow_title']['field'] = 'prc_workflow_title';
  $handler->display->display_options['fields']['prc_workflow_title']['label'] = 'Title';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted On';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Author Name */
  $handler->display->display_options['fields']['field_author_name']['id'] = 'field_author_name';
  $handler->display->display_options['fields']['field_author_name']['table'] = 'field_data_field_author_name';
  $handler->display->display_options['fields']['field_author_name']['field'] = 'field_author_name';
  /* Field: Content: Attach a File */
  $handler->display->display_options['fields']['field_document']['id'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['table'] = 'field_data_field_document';
  $handler->display->display_options['fields']['field_document']['field'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['label'] = 'Attached Files';
  $handler->display->display_options['fields']['field_document']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document']['delta_offset'] = '0';
  /* Field: State Flow: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'node_revision_states';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  /* Field: Content: PRC Workflow: Delete link */
  $handler->display->display_options['fields']['workflow_delete_node']['id'] = 'workflow_delete_node';
  $handler->display->display_options['fields']['workflow_delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['workflow_delete_node']['field'] = 'workflow_delete_node';
  $handler->display->display_options['fields']['workflow_delete_node']['label'] = 'Actions';
  /* Field: Content: PRC Workflow: Edit link */
  $handler->display->display_options['fields']['workflow_edit_node']['id'] = 'workflow_edit_node';
  $handler->display->display_options['fields']['workflow_edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['workflow_edit_node']['field'] = 'workflow_edit_node';
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['arguments']['uid_1']['table'] = 'users';
  $handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'User: Uid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: All Digital Library Content */
  $handler = $view->new_display('panel_pane', 'All Digital Library Content', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'prc_workflow_title' => 'prc_workflow_title',
    'created' => 'created',
    'type' => 'type',
    'changed' => 'changed',
    'field_author_name' => 'field_author_name',
    'field_document' => 'field_document',
    'state' => 'state',
    'workflow_delete_node' => 'workflow_delete_node',
    'workflow_edit_node' => 'workflow_delete_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'prc_workflow_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_document' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'workflow_delete_node' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'workflow_edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: PRC Workflow: Title */
  $handler->display->display_options['fields']['prc_workflow_title']['id'] = 'prc_workflow_title';
  $handler->display->display_options['fields']['prc_workflow_title']['table'] = 'node';
  $handler->display->display_options['fields']['prc_workflow_title']['field'] = 'prc_workflow_title';
  $handler->display->display_options['fields']['prc_workflow_title']['label'] = 'Title';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted On';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Author Name */
  $handler->display->display_options['fields']['field_author_name']['id'] = 'field_author_name';
  $handler->display->display_options['fields']['field_author_name']['table'] = 'field_data_field_author_name';
  $handler->display->display_options['fields']['field_author_name']['field'] = 'field_author_name';
  /* Field: Content: Attach a File */
  $handler->display->display_options['fields']['field_document']['id'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['table'] = 'field_data_field_document';
  $handler->display->display_options['fields']['field_document']['field'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['label'] = 'Attached Files';
  $handler->display->display_options['fields']['field_document']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document']['delta_offset'] = '0';
  /* Field: State Flow: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'node_revision_states';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  /* Field: Content: PRC Workflow: Delete link */
  $handler->display->display_options['fields']['workflow_delete_node']['id'] = 'workflow_delete_node';
  $handler->display->display_options['fields']['workflow_delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['workflow_delete_node']['field'] = 'workflow_delete_node';
  $handler->display->display_options['fields']['workflow_delete_node']['label'] = 'Actions';
  /* Field: Content: PRC Workflow: Edit link */
  $handler->display->display_options['fields']['workflow_edit_node']['id'] = 'workflow_edit_node';
  $handler->display->display_options['fields']['workflow_edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['workflow_edit_node']['field'] = 'workflow_edit_node';
  $handler->display->display_options['fields']['workflow_edit_node']['label'] = 'Edit link';
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $export['admin_content_view'] = $view;

  $view = new view();
  $view->name = 'admin_user_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Admin User View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'PRC Website Users';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'mail' => 'mail',
    'field_member_state' => 'field_member_state',
    'rid' => 'rid',
    'field_profession' => 'field_profession',
    'status' => 'status',
    'login_1' => 'login_1',
    'created_1' => 'created_1',
  );
  $handler->display->display_options['style_options']['default'] = 'uid';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_member_state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profession' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'login_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'User ID';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[uid]';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'user/[uid]/edit';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'E-mail Address';
  /* Field: Field: Member State */
  $handler->display->display_options['fields']['field_member_state']['id'] = 'field_member_state';
  $handler->display->display_options['fields']['field_member_state']['table'] = 'field_data_field_member_state';
  $handler->display->display_options['fields']['field_member_state']['field'] = 'field_member_state';
  $handler->display->display_options['fields']['field_member_state']['label'] = 'State';
  $handler->display->display_options['fields']['field_member_state']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: Profession */
  $handler->display->display_options['fields']['field_profession']['id'] = 'field_profession';
  $handler->display->display_options['fields']['field_profession']['table'] = 'field_data_field_profession';
  $handler->display->display_options['fields']['field_profession']['field'] = 'field_profession';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login_1']['id'] = 'login_1';
  $handler->display->display_options['fields']['login_1']['table'] = 'users';
  $handler->display->display_options['fields']['login_1']['field'] = 'login';
  $handler->display->display_options['fields']['login_1']['label'] = 'Last Logged on';
  $handler->display->display_options['fields']['login_1']['date_format'] = 'short';
  $handler->display->display_options['fields']['login_1']['second_date_format'] = 'long';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'users';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = 'Member Since';
  $handler->display->display_options['fields']['created_1']['date_format'] = 'short';
  $handler->display->display_options['fields']['created_1']['second_date_format'] = 'long';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
    7 => '7',
    4 => '4',
    3 => '3',
    8 => '8',
    9 => '9',
    5 => '5',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'mail' => 'mail',
    'rid' => 'rid',
    'field_profession' => 'field_profession',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['admin_user_view'] = $view;

  $view = new view();
  $view->name = 'archive';
  $view->description = 'Display a list of months that link to content for that month.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Archive';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Monthly archive';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Created year + month */
  $handler->display->display_options['arguments']['created_year_month']['id'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['table'] = 'node';
  $handler->display->display_options['arguments']['created_year_month']['field'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['created_year_month']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['created_year_month']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['created_year_month']['title'] = '%1';
  $handler->display->display_options['arguments']['created_year_month']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['created_year_month']['summary']['sort_order'] = 'desc';
  $handler->display->display_options['arguments']['created_year_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['override'] = TRUE;
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['items_per_page'] = '30';
  $handler->display->display_options['arguments']['created_year_month']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'archive';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Created year + month */
  $handler->display->display_options['arguments']['created_year_month']['id'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['table'] = 'node';
  $handler->display->display_options['arguments']['created_year_month']['field'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['created_year_month']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['created_year_month']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['created_year_month']['title'] = '%1';
  $handler->display->display_options['arguments']['created_year_month']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['created_year_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['items_per_page'] = '30';
  $handler->display->display_options['arguments']['created_year_month']['specify_validation'] = TRUE;
  $export['archive'] = $view;

  $view = new view();
  $view->name = 'assessment_item_list';
  $view->description = 'Item List for Assessment Detail Page';
  $view->tag = 'default';
  $view->base_table = 'quiz_node_relationship';
  $view->human_name = 'Assessment Item List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Quiz question relationship: Child_nid */
  $handler->display->display_options['relationships']['child_nid']['id'] = 'child_nid';
  $handler->display->display_options['relationships']['child_nid']['table'] = 'quiz_node_relationship';
  $handler->display->display_options['relationships']['child_nid']['field'] = 'child_nid';
  $handler->display->display_options['relationships']['child_nid']['label'] = 'Question';
  $handler->display->display_options['relationships']['child_nid']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'child_nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'child_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Preview';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'question-preview/nojs/[nid]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'use-ajax';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'child_nid';
  $handler->display->display_options['fields']['type']['label'] = 'Item Type';
  /* Contextual filter: Quiz question relationship: Parent_vid */
  $handler->display->display_options['arguments']['parent_vid']['id'] = 'parent_vid';
  $handler->display->display_options['arguments']['parent_vid']['table'] = 'quiz_node_relationship';
  $handler->display->display_options['arguments']['parent_vid']['field'] = 'parent_vid';
  $handler->display->display_options['arguments']['parent_vid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['parent_vid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['parent_vid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['parent_vid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['parent_vid']['summary_options']['items_per_page'] = '25';

  /* Display: Item List */
  $handler = $view->new_display('panel_pane', 'Item List', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'PRC View panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'parent_vid' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Quiz question relationship: Parent_vid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['assessment_item_list'] = $view;

  $view = new view();
  $view->name = 'assessments';
  $view->description = 'Assessments tab view';
  $view->tag = 'PRC';
  $view->base_table = 'node';
  $view->human_name = 'Assessments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'oldest on top';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'most recent on top';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Date';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quiz' => 'quiz',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    34 => '34',
    36 => '36',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'quiz_type';

  /* Display: Assessments View All */
  $handler = $view->new_display('panel_pane', 'Assessments View All', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'PRC View panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['assessments'] = $view;

  $view = new view();
  $view->name = 'assessments_filtered_by_favorites';
  $view->description = 'Assessments tab view';
  $view->tag = 'PRC';
  $view->base_table = 'node';
  $view->human_name = 'Assessments Filtered by Favorites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'oldest on top';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'most recent on top';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['id'] = 'reverse_field_favorite_content_node';
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['field'] = 'reverse_field_favorite_content_node';
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Date';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_favorite_content_node';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quiz' => 'quiz',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    34 => '34',
    36 => '36',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'quiz_type';

  /* Display: Assessments Favorites */
  $handler = $view->new_display('panel_pane', 'Assessments Favorites', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'PRC View panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['assessments_filtered_by_favorites'] = $view;

  $view = new view();
  $view->name = 'backlinks';
  $view->description = 'Displays a list of nodes that link to the node, using the search backlinks table.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Backlinks';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 30;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'No backlinks found.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Contextual filter: Search: Links to */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'search_node_links_to';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Pages that link to %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/backlinks';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'What links here';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: What links here */
  $handler = $view->new_display('block', 'What links here', 'block');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Search: Links to */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'search_node_links_to';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'What links here';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $export['backlinks'] = $view;

  $view = new view();
  $view->name = 'commentable_teasers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Commentable Teasers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Commentable Teasers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commentable' => 'commentable',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'commentable-teasers';
  $export['commentable_teasers'] = $view;

  $view = new view();
  $view->name = 'comments_recent';
  $view->description = 'Contains a block and a page to list recent comments; the block will automatically link to the page, which displays the comment body as well as a link to the node.';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'Recent comments';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent comments';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = 5;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Comment: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: Comment: Title */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  /* Field: Comment: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'comment';
  $handler->display->display_options['fields']['timestamp']['field'] = 'changed';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Sort criterion: Comment: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'comment';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'changed';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['row_options']['separator'] = '&nbsp;';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Reply to';
  /* Field: Comment: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'comment';
  $handler->display->display_options['fields']['timestamp']['field'] = 'changed';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: Comment: Title */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  /* Field: Comment: Comment */
  $handler->display->display_options['fields']['comment']['id'] = 'comment';
  $handler->display->display_options['fields']['comment']['table'] = 'field_data_comment_body';
  $handler->display->display_options['fields']['comment']['field'] = 'comment_body';
  $handler->display->display_options['fields']['comment']['label'] = '';
  $handler->display->display_options['path'] = 'comments/recent';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['comments_recent'] = $view;

  $view = new view();
  $view->name = 'course_enrollment_search_add';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'users';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = '%1: Search and Enroll';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'mail' => 'mail',
    'views_bulk_operations' => 'views_bulk_operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::system_block_ip_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::user_block_user_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::course_add_enrollment_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Enroll user',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['null']['validate']['type'] = 'course';
  $handler->display->display_options['arguments']['null']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['null']['validate_options']['access_op'] = 'update';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
  );
  $handler->display->display_options['filters']['uid']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'User: Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'User: E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/course-enrollments/search-add';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Search and Enroll';
  $handler->display->display_options['menu']['weight'] = '0';
  $export['course_enrollment_search_add'] = $view;

  $view = new view();
  $view->name = 'course_enrollment_vbo_admin';
  $view->description = 'Per-node signup administration interface with checkboxes for bulk operations.';
  $view->tag = 'Signup';
  $view->base_table = 'course_enrollment';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'timestamp' => 'timestamp',
    'enroll_end' => 'enroll_end',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'enroll_end' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Course enrollment: Nid */
  $handler->display->display_options['relationships']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['relationships']['nid_1']['table'] = 'course_enrollment';
  $handler->display->display_options['relationships']['nid_1']['field'] = 'nid';
  /* Relationship: Course enrollment: Uid */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'course_enrollment';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  /* Field: Bulk operations: Course enrollment */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'course_enrollment';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::course_edit_enrollment_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::course_remove_enrollment_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid_1';
  /* Field: Course enrollment: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'course_enrollment';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'course_enrollment';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Enroll start';
  /* Field: Course enrollment: Enroll_end */
  $handler->display->display_options['fields']['enroll_end']['id'] = 'enroll_end';
  $handler->display->display_options['fields']['enroll_end']['table'] = 'course_enrollment';
  $handler->display->display_options['fields']['enroll_end']['field'] = 'enroll_end';
  $handler->display->display_options['fields']['enroll_end']['relationship'] = 'course_enrollment';
  $handler->display->display_options['fields']['enroll_end']['label'] = 'Enroll End';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid_1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'course';
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate_options']['access_op'] = 'update';
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid_1';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'User: Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['relationship'] = 'uid_1';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'User: E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/course-enrollments/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Enrollments';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['course_enrollment_vbo_admin'] = $view;

  $view = new view();
  $view->name = 'course_management';
  $view->description = 'List of Courses for Course Management';
  $view->tag = 'PRC';
  $view->base_table = 'node';
  $view->human_name = 'Course Management';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'created' => 'created',
    'changed' => 'changed',
    'field_permissions' => 'field_permissions',
    'status' => 'status',
    'course_object_count' => 'course_object_count',
    'edit_node' => 'edit_node',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'nid';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_permissions' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'course_object_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created On';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Permissions */
  $handler->display->display_options['fields']['field_permissions']['id'] = 'field_permissions';
  $handler->display->display_options['fields']['field_permissions']['table'] = 'field_data_field_permissions';
  $handler->display->display_options['fields']['field_permissions']['field'] = 'field_permissions';
  $handler->display->display_options['fields']['field_permissions']['label'] = 'Permission';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Number of Modules/Quizzes */
  $handler->display->display_options['fields']['course_object_count']['id'] = 'course_object_count';
  $handler->display->display_options['fields']['course_object_count']['table'] = 'node';
  $handler->display->display_options['fields']['course_object_count']['field'] = 'course_object_count';
  $handler->display->display_options['fields']['course_object_count']['label'] = '# of Modules/Quizzes';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Export';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'admin-course/lti/[nid]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_permissions';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Public';
  $handler->display->display_options['fields']['views_conditional']['then'] = '| [nothing_1]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [views_conditional] ';
  /* Sort criterion: Content revision: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pd_course' => 'pd_course',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Filter all columns';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'created' => 'created',
    'changed' => 'changed',
    'field_permissions' => 'field_permissions',
    'status' => 'status',
  );

  /* Display: Course Management List */
  $handler = $view->new_display('panel_pane', 'Course Management List', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'List of Courses for the Course Management page';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['course_management'] = $view;

  $view = new view();
  $view->name = 'course_object_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'course_outline_fulfillment';
  $view->human_name = 'course object report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Object report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no attempts on this object.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Course object fulfillment: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'course_outline_fulfillment';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Course object fulfillment: Date_started */
  $handler->display->display_options['fields']['date_started']['id'] = 'date_started';
  $handler->display->display_options['fields']['date_started']['table'] = 'course_outline_fulfillment';
  $handler->display->display_options['fields']['date_started']['field'] = 'date_started';
  $handler->display->display_options['fields']['date_started']['label'] = 'Date Started';
  $handler->display->display_options['fields']['date_started']['date_format'] = 'short';
  $handler->display->display_options['fields']['date_started']['second_date_format'] = 'long';
  /* Field: Course object fulfillment: Date_completed */
  $handler->display->display_options['fields']['date_completed']['id'] = 'date_completed';
  $handler->display->display_options['fields']['date_completed']['table'] = 'course_outline_fulfillment';
  $handler->display->display_options['fields']['date_completed']['field'] = 'date_completed';
  $handler->display->display_options['fields']['date_completed']['label'] = 'Date Completed';
  $handler->display->display_options['fields']['date_completed']['date_format'] = 'short';
  $handler->display->display_options['fields']['date_completed']['second_date_format'] = 'long';
  /* Field: Course object fulfillment: Grade_result */
  $handler->display->display_options['fields']['grade_result']['id'] = 'grade_result';
  $handler->display->display_options['fields']['grade_result']['table'] = 'course_outline_fulfillment';
  $handler->display->display_options['fields']['grade_result']['field'] = 'grade_result';
  $handler->display->display_options['fields']['grade_result']['label'] = 'Grade';
  $handler->display->display_options['fields']['grade_result']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['grade_result']['separator'] = '';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['null']['validate']['type'] = 'course';
  $handler->display->display_options['arguments']['null']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['null']['validate_options']['access_op'] = 'update';
  /* Contextual filter: Course object fulfillment: Coid */
  $handler->display->display_options['arguments']['coid']['id'] = 'coid';
  $handler->display->display_options['arguments']['coid']['table'] = 'course_outline_fulfillment';
  $handler->display->display_options['arguments']['coid']['field'] = 'coid';
  $handler->display->display_options['arguments']['coid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['coid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['coid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['coid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/course-reports/objects/%/overview';
  $export['course_object_report'] = $view;

  $view = new view();
  $view->name = 'course_report';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'course_report';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Course Report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access all course reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 50;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'uid' => 'uid',
    'name' => 'name',
    'timestamp' => 'timestamp',
    'date_completed' => 'date_completed',
    'section_name' => 'section_name',
    'mail' => 'mail',
  );
  $handler->display->display_options['style_options']['default'] = 'date_completed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'date_completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'section_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, there is no course data to report on. Please check that both date fields are filled in with valid dates.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Course report: Nid */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'course_report';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Course report: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'course_report';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Course User';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Course report: Course enrollment */
  $handler->display->display_options['relationships']['course_enrollment']['id'] = 'course_enrollment';
  $handler->display->display_options['relationships']['course_enrollment']['table'] = 'course_report';
  $handler->display->display_options['relationships']['course_enrollment']['field'] = 'course_enrollment';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Course';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'User ID';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Course enrollment: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'course_enrollment';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'course_enrollment';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Date Started';
  /* Field: Course report: Date_completed */
  $handler->display->display_options['fields']['date_completed']['id'] = 'date_completed';
  $handler->display->display_options['fields']['date_completed']['table'] = 'course_report';
  $handler->display->display_options['fields']['date_completed']['field'] = 'date_completed';
  $handler->display->display_options['fields']['date_completed']['label'] = 'Date Completed';
  /* Field: Course report: Section_name */
  $handler->display->display_options['fields']['section_name']['id'] = 'section_name';
  $handler->display->display_options['fields']['section_name']['table'] = 'course_report';
  $handler->display->display_options['fields']['section_name']['field'] = 'section_name';
  $handler->display->display_options['fields']['section_name']['label'] = 'Status';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = '%1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'course';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Course report: Date_completed */
  $handler->display->display_options['filters']['date_completed']['id'] = 'date_completed';
  $handler->display->display_options['filters']['date_completed']['table'] = 'course_report';
  $handler->display->display_options['filters']['date_completed']['field'] = 'date_completed';
  $handler->display->display_options['filters']['date_completed']['operator'] = 'between';
  $handler->display->display_options['filters']['date_completed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_completed']['expose']['operator_id'] = 'date_completed_op';
  $handler->display->display_options['filters']['date_completed']['expose']['label'] = 'Completed between';
  $handler->display->display_options['filters']['date_completed']['expose']['operator'] = 'date_completed_op';
  $handler->display->display_options['filters']['date_completed']['expose']['identifier'] = 'date_completed';
  /* Filter criterion: Content: Is a course */
  $handler->display->display_options['filters']['course']['id'] = 'course';
  $handler->display->display_options['filters']['course']['table'] = 'node';
  $handler->display->display_options['filters']['course']['field'] = 'course';
  $handler->display->display_options['filters']['course']['relationship'] = 'nid';
  $handler->display->display_options['filters']['course']['value'] = '1';

  /* Display: Course report */
  $handler = $view->new_display('page', 'Course report', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = '%1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'course';
  $handler->display->display_options['path'] = 'node/%/course-reports/overview';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Overview';
  $handler->display->display_options['menu']['weight'] = '-1';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Reporting';
  $handler->display->display_options['tab_options']['weight'] = '1';

  /* Display: Global course report */
  $handler = $view->new_display('page', 'Global course report', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All courses';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/reports/course/overview/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'All courses';
  $handler->display->display_options['menu']['description'] = 'View or download a report of all courses.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'All courses';
  $handler->display->display_options['tab_options']['description'] = 'View and download course information.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Global export */
  $handler = $view->new_display('views_data_export', 'Global export', 'views_data_export_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Global feed';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'admin/reports/course/overview/csv';
  $handler->display->display_options['displays'] = array(
    'page_2' => 'page_2',
    'default' => 0,
    'page_1' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Export */
  $handler = $view->new_display('views_data_export', 'Export', 'views_data_export_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'course-report-%1-title.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'node/%/report/csv';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page_2' => 0,
  );
  $export['course_report'] = $view;

  $view = new view();
  $view->name = 'course_report_select';
  $view->description = 'A view of courses, to allow the user to select which courses appear in a final course report.';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Select courses';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Select courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access all course reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations_1']['id'] = 'views_bulk_operations_1';
  $handler->display->display_options['fields']['views_bulk_operations_1']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations_1']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations_1']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Filter',
      'settings' => array(
        'url' => 'admin/reports/course/overview',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Course node ID';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Course title';
  /* Filter criterion: Content: Is a course */
  $handler->display->display_options['filters']['course']['id'] = 'course';
  $handler->display->display_options['filters']['course']['table'] = 'node';
  $handler->display->display_options['filters']['course']['field'] = 'course';
  $handler->display->display_options['filters']['course']['value'] = '1';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Course title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/reports/course/overview/select';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Select';
  $handler->display->display_options['menu']['weight'] = '0';
  $export['course_report_select'] = $view;

  $view = new view();
  $view->name = 'digital_library_favorites';
  $view->description = 'Digital Library view filtered by a Favorites List';
  $view->tag = 'PRC';
  $view->base_table = 'node';
  $view->human_name = 'Digital Library Favorites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['id'] = 'reverse_field_favorite_content_node';
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['field'] = 'reverse_field_favorite_content_node';
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['label'] = 'Favorites List';
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_favorite_content_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'digital_library_content' => 'digital_library_content',
  );

  /* Display: Digital Library Favorites Content */
  $handler = $view->new_display('panel_pane', 'Digital Library Favorites Content', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Favorites List: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['digital_library_favorites'] = $view;

  $view = new view();
  $view->name = 'digital_library_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_digital_library_only';
  $view->human_name = 'Digital Library Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '21';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'gallery_view';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results to display. Please change the search or filter selections and try again.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_digital_library_only';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Indexed Node: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_digital_library_only';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Date';
  /* Sort criterion: Indexed Node: Like Content Flag Count */
  $handler->display->display_options['sorts']['flag_like_content_count']['id'] = 'flag_like_content_count';
  $handler->display->display_options['sorts']['flag_like_content_count']['table'] = 'search_api_index_digital_library_only';
  $handler->display->display_options['sorts']['flag_like_content_count']['field'] = 'flag_like_content_count';
  $handler->display->display_options['sorts']['flag_like_content_count']['order'] = 'DESC';
  $handler->display->display_options['sorts']['flag_like_content_count']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['flag_like_content_count']['expose']['label'] = 'Popularity';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_digital_library_only';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    12 => 0,
    6 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
    9 => 0,
    10 => 0,
    5 => 0,
    11 => 0,
  );

  /* Display: Digital Library Search View */
  $handler = $view->new_display('panel_pane', 'Digital Library Search View', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'PRC Digital Library';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['digital_library_gallery'] = $view;

  $view = new view();
  $view->name = 'digital_library_tree_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Digital Library Tree View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Digital Library';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'digital_library_content' => 'digital_library_content',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['digital_library_tree_view'] = $view;

  $view = new view();
  $view->name = 'digital_library_view';
  $view->description = '';
  $view->tag = 'PRC';
  $view->base_table = 'node';
  $view->human_name = 'Digital Library View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'oldest on top';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'most recent on top';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
    'field_author_name' => 'field_author_name',
    'body' => 'body',
    'field_thumbnail' => 'field_thumbnail',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_thumbnail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted On';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Author Name */
  $handler->display->display_options['fields']['field_author_name']['id'] = 'field_author_name';
  $handler->display->display_options['fields']['field_author_name']['table'] = 'field_data_field_author_name';
  $handler->display->display_options['fields']['field_author_name']['field'] = 'field_author_name';
  /* Field: Content: Attach a File */
  $handler->display->display_options['fields']['field_document']['id'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['table'] = 'field_data_field_document';
  $handler->display->display_options['fields']['field_document']['field'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document']['delta_offset'] = '0';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Action';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Date';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'digital_library_content' => 'digital_library_content',
  );

  /* Display: Digital Library Pane */
  $handler = $view->new_display('panel_pane', 'Digital Library Pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'oldest on top';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'most recent on top';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted On';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Author Name */
  $handler->display->display_options['fields']['field_author_name']['id'] = 'field_author_name';
  $handler->display->display_options['fields']['field_author_name']['table'] = 'field_data_field_author_name';
  $handler->display->display_options['fields']['field_author_name']['field'] = 'field_author_name';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Summary';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Add a Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = 'Thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'User: Uid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Digital Library Gallery View Pane */
  $handler = $view->new_display('panel_pane', 'Digital Library Gallery View Pane', 'panel_pane_2');
  $handler->display->display_options['display_description'] = 'Pane for Gallery View of Digital Library';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'gallery_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['digital_library_view'] = $view;

  $view = new view();
  $view->name = 'favorites_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Favorites List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Favorites List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'title_1' => 'title_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title_1']['label'] = 'List';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'favorites-list';

  /* Display: Favorited Digital Library Content */
  $handler = $view->new_display('panel_pane', 'Favorited Digital Library Content', 'digital_library_content');
  $handler->display->display_options['display_description'] = 'Digital Library Content items that have been added to user\'s lists';
  $export['favorites_list'] = $view;

  $view = new view();
  $view->name = 'flag_bookmarks';
  $view->description = 'A page listing the current user\'s bookmarks at /bookmarks.';
  $view->tag = 'flag';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'My bookmarks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'flag bookmarks';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'type' => 'type',
    'title' => 'title',
    'name' => 'name',
    'comment_count' => 'comment_count',
    'last_comment_timestamp' => 'last_comment_timestamp',
    'ops' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = 'last_comment_timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'type' => array(
      'sortable' => TRUE,
    ),
    'title' => array(
      'sortable' => TRUE,
    ),
    'name' => array(
      'sortable' => TRUE,
    ),
    'comment_count' => array(
      'sortable' => TRUE,
    ),
    'last_comment_timestamp' => array(
      'sortable' => TRUE,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['order'] = 'desc';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'You have not yet bookmarked any content. Click the "Bookmark this" link when viewing a piece of content to add it to this list.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Relationship: Flags: bookmarks */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'bookmarks';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'bookmarks';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid_1';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Replies';
  /* Field: Content: Last comment time */
  $handler->display->display_options['fields']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
  $handler->display->display_options['fields']['last_comment_timestamp']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
  $handler->display->display_options['fields']['last_comment_timestamp']['label'] = 'Last Post';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Ops';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'bookmarks';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My bookmarks';
  $handler->display->display_options['menu']['weight'] = '0';
  $export['flag_bookmarks'] = $view;

  $view = new view();
  $view->name = 'flag_bookmarks_tab';
  $view->description = 'Provides a tab on all users\' profile pages containing bookmarks for that user.';
  $view->tag = 'flag';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'User bookmarks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'flag bookmarks';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'type' => 'type',
    'title' => 'title',
    'name' => 'name',
    'comment_count' => 'comment_count',
    'last_comment_timestamp' => 'last_comment_timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'last_comment_timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'type' => array(
      'sortable' => TRUE,
    ),
    'title' => array(
      'sortable' => TRUE,
    ),
    'name' => array(
      'sortable' => TRUE,
    ),
    'comment_count' => array(
      'sortable' => TRUE,
    ),
    'last_comment_timestamp' => array(
      'sortable' => TRUE,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['order'] = 'desc';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'This user has not yet bookmarked any content.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Relationship: Flags: bookmarks */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'bookmarks';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'bookmarks';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  /* Relationship: Flags: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'flagging';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['uid']['label'] = 'bookmarks_user';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid_1';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Replies';
  /* Field: Content: Last comment time */
  $handler->display->display_options['fields']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
  $handler->display->display_options['fields']['last_comment_timestamp']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
  $handler->display->display_options['fields']['last_comment_timestamp']['label'] = 'Last Post';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid']['title'] = '%1\'s bookmarks';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/bookmarks';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Bookmarks';
  $handler->display->display_options['menu']['weight'] = '0';
  $export['flag_bookmarks_tab'] = $view;

  $view = new view();
  $view->name = 'formative_instructional_tasks';
  $view->description = '';
  $view->tag = 'PRC';
  $view->base_table = 'node';
  $view->human_name = 'Formative Instructional Tasks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_file_single' => 'field_file_single',
    'title' => 'title',
    'field_subject' => 'field_subject',
    'field_grade_level' => 'field_grade_level',
    'field_resource_type' => 'field_resource_type',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_file_single' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_subject' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_grade_level' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resource_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Field: Content: File */
  $handler->display->display_options['fields']['field_file_single']['id'] = 'field_file_single';
  $handler->display->display_options['fields']['field_file_single']['table'] = 'field_data_field_file_single';
  $handler->display->display_options['fields']['field_file_single']['field'] = 'field_file_single';
  $handler->display->display_options['fields']['field_file_single']['label'] = '';
  $handler->display->display_options['fields']['field_file_single']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file_single']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_single']['type'] = 'file_url_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Resource Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_file_single]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  /* Field: Content: Grade Level */
  $handler->display->display_options['fields']['field_grade_level_unlimited']['id'] = 'field_grade_level_unlimited';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['table'] = 'field_data_field_grade_level_unlimited';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['field'] = 'field_grade_level_unlimited';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['delta_offset'] = '0';
  /* Field: Content: Resource Type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'URL for Seraph';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = TRUE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'formative_instructional_task' => 'formative_instructional_task',
  );

  /* Display: PRC Formative Instructional Tasks Admin View */
  $handler = $view->new_display('panel_pane', 'PRC Formative Instructional Tasks Admin View', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'PRC Instruction';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: PRC Formative Instructional Tasks Regular View */
  $handler = $view->new_display('panel_pane', 'PRC Formative Instructional Tasks Regular View', 'panel_pane_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: File */
  $handler->display->display_options['fields']['field_file_single']['id'] = 'field_file_single';
  $handler->display->display_options['fields']['field_file_single']['table'] = 'field_data_field_file_single';
  $handler->display->display_options['fields']['field_file_single']['field'] = 'field_file_single';
  $handler->display->display_options['fields']['field_file_single']['label'] = '';
  $handler->display->display_options['fields']['field_file_single']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file_single']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_single']['type'] = 'file_url_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Resource Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_file_single]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  /* Field: Content: Grade Level */
  $handler->display->display_options['fields']['field_grade_level_unlimited']['id'] = 'field_grade_level_unlimited';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['table'] = 'field_data_field_grade_level_unlimited';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['field'] = 'field_grade_level_unlimited';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['delta_offset'] = '0';
  /* Field: Content: Resource Type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'URL for Seraph';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'PRC Instruction';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $export['formative_instructional_tasks'] = $view;

  $view = new view();
  $view->name = 'frontpage';
  $view->description = 'Emulates the default Drupal front page; you may set the default home page path to this view to make it your front page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Front page';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'frontpage';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Front page feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'rss.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['sitename_title'] = '1';
  $export['frontpage'] = $view;

  $view = new view();
  $view->name = 'glossary';
  $view->description = 'A list of all content, by letter.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Glossary';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 36;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'name' => 'name',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'changed' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'large';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'default';
  $handler->display->display_options['arguments']['title']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_options']['argument'] = 'a';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'lower';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'glossary';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Glossary';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['title']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_options']['argument'] = 'a';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['summary_options']['inline'] = TRUE;
  $handler->display->display_options['arguments']['title']['summary_options']['separator'] = ' | ';
  $handler->display->display_options['arguments']['title']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'lower';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $export['glossary'] = $view;

  $view = new view();
  $view->name = 'invite';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'invite';
  $view->human_name = 'Invite';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Invite';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any invite entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['invitee_user']['id'] = 'invitee_user';
  $handler->display->display_options['relationships']['invitee_user']['table'] = 'invite';
  $handler->display->display_options['relationships']['invitee_user']['field'] = 'invitee_user';
  $handler->display->display_options['relationships']['invitee_user']['ui_name'] = 'Invitee';
  $handler->display->display_options['relationships']['invitee_user']['label'] = 'Invitee';
  /* Field: Invite: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'invite';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Invite: Invite action link: accept */
  $handler->display->display_options['fields']['invite_accept_link']['id'] = 'invite_accept_link';
  $handler->display->display_options['fields']['invite_accept_link']['table'] = 'views_entity_invite';
  $handler->display->display_options['fields']['invite_accept_link']['field'] = 'invite_accept_link';
  $handler->display->display_options['fields']['invite_accept_link']['label'] = 'Invite accept link URL';
  $handler->display->display_options['fields']['invite_accept_link']['link_to_entity'] = 0;
  /* Field: Invite: Joined */
  $handler->display->display_options['fields']['joined']['id'] = 'joined';
  $handler->display->display_options['fields']['joined']['table'] = 'invite';
  $handler->display->display_options['fields']['joined']['field'] = 'joined';
  $handler->display->display_options['fields']['joined']['date_format'] = 'long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'invitee_user';
  /* Field: Invite: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'views_entity_invite';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['link_to_entity'] = 0;
  /* Contextual filter: Invite: Inviter uid */
  $handler->display->display_options['arguments']['inviter']['id'] = 'inviter';
  $handler->display->display_options['arguments']['inviter']['table'] = 'invite';
  $handler->display->display_options['arguments']['inviter']['field'] = 'inviter';
  $handler->display->display_options['arguments']['inviter']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['inviter']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['inviter']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['inviter']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['inviter']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'user/%/invites';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Invites';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['invite'] = $view;

  $view = new view();
  $view->name = 'message';
  $view->description = 'Show all existing messages.';
  $view->tag = 'Message';
  $view->base_table = 'message';
  $view->human_name = 'Message';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer message types';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'message_render' => 'message_render',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'message_render' => array(
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No messages created yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  /* Field: Message: Render message (Get text) */
  $handler->display->display_options['fields']['message_render']['id'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['table'] = 'message';
  $handler->display->display_options['fields']['message_render']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['label'] = 'Text';
  $handler->display->display_options['fields']['message_render']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render']['hide_alter_empty'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Message type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/content/message';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Messages';
  $handler->display->display_options['menu']['description'] = 'A list of all messages.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['message'] = $view;

  $view = new view();
  $view->name = 'my_lists';
  $view->description = 'List of Favorites Lists for the current user for DLC and PD';
  $view->tag = 'PRC';
  $view->base_table = 'node';
  $view->human_name = 'My Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Lists';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'digital_library_favorites_list/nojs/[nid]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'use-ajax';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Content Type (field_content_type) */
  $handler->display->display_options['arguments']['field_content_type_value']['id'] = 'field_content_type_value';
  $handler->display->display_options['arguments']['field_content_type_value']['table'] = 'field_data_field_content_type';
  $handler->display->display_options['arguments']['field_content_type_value']['field'] = 'field_content_type_value';
  $handler->display->display_options['arguments']['field_content_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_content_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_content_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_content_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_content_type_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'favorites_list' => 'favorites_list',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'none',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Author uid',
    ),
    'field_content_type_value' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Content Type (field_content_type)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['my_lists'] = $view;

  $view = new view();
  $view->name = 'prc_item_bank';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PRC Item Bank';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'field_parcc_item' => 'field_parcc_item',
    'edit_node' => 'edit_node',
    'clone_node' => 'clone_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parcc_item' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clone_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Scoring note: All interactive choice and short answer questions are machine scored.
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No items found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'question-preview/nojs/[nid]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'use-ajax';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Make this a PARCC item */
  $handler->display->display_options['fields']['field_parcc_item']['id'] = 'field_parcc_item';
  $handler->display->display_options['fields']['field_parcc_item']['table'] = 'field_data_field_parcc_item';
  $handler->display->display_options['fields']['field_parcc_item']['field'] = 'field_parcc_item';
  $handler->display->display_options['fields']['field_parcc_item']['label'] = 'PARCC Item?';
  $handler->display->display_options['fields']['field_parcc_item']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_parcc_item']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['field_parcc_item']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_parcc_item']['empty'] = 'No';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Clone link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['label'] = '';
  $handler->display->display_options['fields']['clone_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['clone_node']['text'] = 'Duplicate';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Question title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Question type */
  $handler->display->display_options['filters']['quiz_question_type']['id'] = 'quiz_question_type';
  $handler->display->display_options['filters']['quiz_question_type']['table'] = 'node';
  $handler->display->display_options['filters']['quiz_question_type']['field'] = 'quiz_question_type';
  $handler->display->display_options['filters']['quiz_question_type']['group'] = 1;
  $handler->display->display_options['filters']['quiz_question_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['quiz_question_type']['expose']['operator_id'] = 'quiz_question_type_op';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['label'] = 'Question type';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['operator'] = 'quiz_question_type_op';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['identifier'] = 'quiz_question_type';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Quiz question */
  $handler->display->display_options['filters']['quiz_question']['id'] = 'quiz_question';
  $handler->display->display_options['filters']['quiz_question']['table'] = 'node';
  $handler->display->display_options['filters']['quiz_question']['field'] = 'quiz_question';
  $handler->display->display_options['filters']['quiz_question']['value'] = '1';
  $handler->display->display_options['filters']['quiz_question']['group'] = 1;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'PRC Item Bank';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['prc_item_bank'] = $view;

  $view = new view();
  $view->name = 'prc_quiz_question_bank';
  $view->description = 'PRC customized Item Bank view to be used to add questions to a quiz';
  $view->tag = 'prc';
  $view->base_table = 'node';
  $view->human_name = 'PRC Quiz Question Bank';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Question bank';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Scoring note: All interactive choice and short answer questions are machine scored.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No questions found using the given criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::quiz_add_question_to_quiz' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Make this a PARCC item */
  $handler->display->display_options['fields']['field_parcc_item']['id'] = 'field_parcc_item';
  $handler->display->display_options['fields']['field_parcc_item']['table'] = 'field_data_field_parcc_item';
  $handler->display->display_options['fields']['field_parcc_item']['field'] = 'field_parcc_item';
  $handler->display->display_options['fields']['field_parcc_item']['label'] = 'PARCC Item?';
  $handler->display->display_options['fields']['field_parcc_item']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_parcc_item']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['field_parcc_item']['empty'] = 'No';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Question title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Question type */
  $handler->display->display_options['filters']['quiz_question_type']['id'] = 'quiz_question_type';
  $handler->display->display_options['filters']['quiz_question_type']['table'] = 'node';
  $handler->display->display_options['filters']['quiz_question_type']['field'] = 'quiz_question_type';
  $handler->display->display_options['filters']['quiz_question_type']['group'] = 1;
  $handler->display->display_options['filters']['quiz_question_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['quiz_question_type']['expose']['operator_id'] = 'quiz_question_type_op';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['label'] = 'Question type';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['operator'] = 'quiz_question_type_op';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['identifier'] = 'quiz_question_type';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Quiz question */
  $handler->display->display_options['filters']['quiz_question']['id'] = 'quiz_question';
  $handler->display->display_options['filters']['quiz_question']['table'] = 'node';
  $handler->display->display_options['filters']['quiz_question']['field'] = 'quiz_question';
  $handler->display->display_options['filters']['quiz_question']['value'] = '1';
  $handler->display->display_options['filters']['quiz_question']['group'] = 1;

  /* Display: PRC Quiz Question Bank */
  $handler = $view->new_display('panel_pane', 'PRC Quiz Question Bank', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Question Bank used to add questions to quiz';
  $handler->display->display_options['pane_category']['name'] = 'PRC Quiz';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $export['prc_quiz_question_bank'] = $view;

  $view = new view();
  $view->name = 'professional_development_favorites';
  $view->description = 'Professional Development content filtered by Favorites List';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Professional Development Favorites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['id'] = 'reverse_field_favorite_content_node';
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['field'] = 'reverse_field_favorite_content_node';
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['label'] = 'Favorites List';
  $handler->display->display_options['relationships']['reverse_field_favorite_content_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_favorite_content_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pd_course' => 'pd_course',
  );

  /* Display: Professional Development Favorites */
  $handler = $view->new_display('panel_pane', 'Professional Development Favorites', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Professional Development view filtered by Favorites List';
  $handler->display->display_options['pane_category']['name'] = 'PRC View panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Favorites List: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['professional_development_favorites'] = $view;

  $view = new view();
  $view->name = 'professional_development_view';
  $view->description = 'The educator view of Professional Development Courses';
  $view->tag = 'PRC';
  $view->base_table = 'node';
  $view->human_name = 'Professional Development View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'oldest on top';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'most recent on top';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Welcome to PRC Professional Development page. There are no courses available to your account. Please contact your school/district to benefit from PARCC Professional Development courses exported to your district learning management system.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pd_course' => 'pd_course',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Date';
  $handler->display->display_options['pane_category']['name'] = 'PRC View panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['professional_development_view'] = $view;

  $view = new view();
  $view->name = 'quiz_question_bank';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'quiz_question_bank';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Question bank';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No questions found using the given criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::quiz_add_question_to_quiz' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Question title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Question type */
  $handler->display->display_options['filters']['quiz_question_type']['id'] = 'quiz_question_type';
  $handler->display->display_options['filters']['quiz_question_type']['table'] = 'node';
  $handler->display->display_options['filters']['quiz_question_type']['field'] = 'quiz_question_type';
  $handler->display->display_options['filters']['quiz_question_type']['group'] = 1;
  $handler->display->display_options['filters']['quiz_question_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['quiz_question_type']['expose']['operator_id'] = 'quiz_question_type_op';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['label'] = 'Question type';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['operator'] = 'quiz_question_type_op';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['identifier'] = 'quiz_question_type';
  $handler->display->display_options['filters']['quiz_question_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Quiz question */
  $handler->display->display_options['filters']['quiz_question']['id'] = 'quiz_question';
  $handler->display->display_options['filters']['quiz_question']['table'] = 'node';
  $handler->display->display_options['filters']['quiz_question']['field'] = 'quiz_question';
  $handler->display->display_options['filters']['quiz_question']['value'] = '1';
  $handler->display->display_options['filters']['quiz_question']['group'] = 1;
  $export['quiz_question_bank'] = $view;

  $view = new view();
  $view->name = 'quiz_results';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'quiz_node_results';
  $view->human_name = 'quiz_results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Quiz results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no attempts on this Quiz yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Quiz result: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'quiz_node_results';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Quiz result */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Quiz result: Date started */
  $handler->display->display_options['fields']['time_start']['id'] = 'time_start';
  $handler->display->display_options['fields']['time_start']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['time_start']['field'] = 'time_start';
  $handler->display->display_options['fields']['time_start']['date_format'] = 'short';
  /* Field: Quiz result: Date finished */
  $handler->display->display_options['fields']['time_end']['id'] = 'time_end';
  $handler->display->display_options['fields']['time_end']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['time_end']['field'] = 'time_end';
  $handler->display->display_options['fields']['time_end']['date_format'] = 'short';
  /* Field: Quiz result: Score */
  $handler->display->display_options['fields']['score']['id'] = 'score';
  $handler->display->display_options['fields']['score']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['score']['field'] = 'score';
  /* Field: Quiz result: Evaluated */
  $handler->display->display_options['fields']['is_evaluated']['id'] = 'is_evaluated';
  $handler->display->display_options['fields']['is_evaluated']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['is_evaluated']['field'] = 'is_evaluated';
  $handler->display->display_options['fields']['is_evaluated']['not'] = 0;
  /* Field: Quiz result: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Quiz result: Quiz result ID */
  $handler->display->display_options['fields']['result_id']['id'] = 'result_id';
  $handler->display->display_options['fields']['result_id']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['result_id']['field'] = 'result_id';
  $handler->display->display_options['fields']['result_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['result_id']['separator'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]/quiz/results/[result_id]/view';
  /* Contextual filter: Quiz result: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'quiz_node_results';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'quiz' => 'quiz',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate_options']['access_op'] = 'update';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/quiz/results';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Results';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Quiz';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['quiz_results'] = $view;

  $view = new view();
  $view->name = 'quiz_user_results';
  $view->description = '';
  $view->tag = 'quiz';
  $view->base_table = 'quiz_node_results';
  $view->human_name = 'Quiz user results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own quiz results';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no attempts on this Quiz yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Quiz result: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'quiz_node_results';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Quiz result: Date started */
  $handler->display->display_options['fields']['time_start']['id'] = 'time_start';
  $handler->display->display_options['fields']['time_start']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['time_start']['field'] = 'time_start';
  $handler->display->display_options['fields']['time_start']['date_format'] = 'short';
  /* Field: Quiz result: Date finished */
  $handler->display->display_options['fields']['time_end']['id'] = 'time_end';
  $handler->display->display_options['fields']['time_end']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['time_end']['field'] = 'time_end';
  $handler->display->display_options['fields']['time_end']['date_format'] = 'short';
  /* Field: Quiz result: Score */
  $handler->display->display_options['fields']['score']['id'] = 'score';
  $handler->display->display_options['fields']['score']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['score']['field'] = 'score';
  /* Field: Quiz result: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Quiz result: Quiz result ID */
  $handler->display->display_options['fields']['result_id']['id'] = 'result_id';
  $handler->display->display_options['fields']['result_id']['table'] = 'quiz_node_results';
  $handler->display->display_options['fields']['result_id']['field'] = 'result_id';
  $handler->display->display_options['fields']['result_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['result_id']['separator'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]/quiz-results/[result_id]/view';
  /* Contextual filter: Quiz result: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'quiz_node_results';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'quiz' => 'quiz',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
  /* Contextual filter: Quiz result: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'quiz_node_results';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  /* Filter criterion: Quiz result: Evaluated */
  $handler->display->display_options['filters']['is_evaluated']['id'] = 'is_evaluated';
  $handler->display->display_options['filters']['is_evaluated']['table'] = 'quiz_node_results';
  $handler->display->display_options['filters']['is_evaluated']['field'] = 'is_evaluated';
  $handler->display->display_options['filters']['is_evaluated']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/quiz-results';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'My results';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Quiz';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Quiz result: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'quiz_node_results';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['path'] = 'user/%/quiz-results';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'My results';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['quiz_user_results'] = $view;

  $view = new view();
  $view->name = 'sample_article';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sample Article';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sample Article';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'front_page_item';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'sample-article';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $export['sample_article'] = $view;

  $view = new view();
  $view->name = 'school_readiness_last_capacity_check_result';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_prc_trt';
  $view->human_name = 'School Readiness Last Capacity Check Result';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'school_readiness';
  /* Field: Prc_trt: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Sort criterion: Prc_trt: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'eck_prc_trt';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: prc_trt: School (field_ref_school) */
  $handler->display->display_options['arguments']['field_ref_school_target_id']['id'] = 'field_ref_school_target_id';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['table'] = 'field_data_field_ref_school';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['field'] = 'field_ref_school_target_id';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Prc_trt: prc_trt type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_prc_trt';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'capacity_check' => 'capacity_check',
  );

  /* Display: Most recent school capacity check */
  $handler = $view->new_display('panel_pane', 'Most recent school capacity check', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'PRC TRT';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_ref_school_target_id' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'prc_trt: School (field_ref_school)',
    ),
  );

  /* Display: School Readiness Page Cap Students */
  $handler = $view->new_display('panel_pane', 'School Readiness Page Cap Students', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Prc_trt: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Field: Number of students */
  $handler->display->display_options['fields']['field_number_of_students']['id'] = 'field_number_of_students';
  $handler->display->display_options['fields']['field_number_of_students']['table'] = 'field_data_field_number_of_students';
  $handler->display->display_options['fields']['field_number_of_students']['field'] = 'field_number_of_students';
  $handler->display->display_options['fields']['field_number_of_students']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['pane_category']['name'] = 'PRC TRT';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_ref_school_target_id' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'prc_trt: School (field_ref_school)',
    ),
  );
  $export['school_readiness_last_capacity_check_result'] = $view;

  $view = new view();
  $view->name = 'school_readiness_system_checks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_prc_trt';
  $view->human_name = 'School Readiness System Checks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_name' => 'field_name',
    'created' => 'created',
    'field_number_of_devices' => 'field_number_of_devices',
    'field_result' => 'field_result',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_number_of_devices' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_result' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'no system checks have been run. 
message explaining what the check does and the importance of running it.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Prc_trt: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: prc_trt: System check name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = 'System Check';
  $handler->display->display_options['fields']['field_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'prc_trt/system_check/[id]';
  /* Field: Prc_trt: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date & Time';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: prc_trt: Number of devices */
  $handler->display->display_options['fields']['field_number_of_devices']['id'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['table'] = 'field_data_field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['field'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['label'] = 'Number of Devices';
  $handler->display->display_options['fields']['field_number_of_devices']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Result */
  $handler->display->display_options['fields']['field_result']['id'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['table'] = 'field_data_field_result';
  $handler->display->display_options['fields']['field_result']['field'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['label'] = 'Results';
  /* Contextual filter: prc_trt: School (field_ref_school) */
  $handler->display->display_options['arguments']['field_ref_school_target_id']['id'] = 'field_ref_school_target_id';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['table'] = 'field_data_field_ref_school';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['field'] = 'field_ref_school_target_id';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ref_school_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Prc_trt: prc_trt type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_prc_trt';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'system_check' => 'system_check',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'PRC TRT';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_ref_school_target_id' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'prc_trt: School (field_ref_school)',
    ),
  );
  $export['school_readiness_system_checks'] = $view;

  $view = new view();
  $view->name = 'schools';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Schools';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Readiness';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[edit_node]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Summary of what user can do here view readiness by school, run readiness checks, view readiness check results.';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: State contact&#039;s email address (field_contact_email) */
  $handler->display->display_options['arguments']['field_contact_email_value']['id'] = 'field_contact_email_value';
  $handler->display->display_options['arguments']['field_contact_email_value']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['arguments']['field_contact_email_value']['field'] = 'field_contact_email_value';
  $handler->display->display_options['arguments']['field_contact_email_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_contact_email_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_contact_email_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_contact_email_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_contact_email_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_contact_email_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'school' => 'school',
  );

  /* Display: School Readiness Links */
  $handler = $view->new_display('panel_pane', 'School Readiness Links', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'TRT School Readiness Links';
  $handler->display->display_options['pane_category']['name'] = 'PRC TRT';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_contact_email_value' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: School contact&#039;s email address (field_contact_email)',
    ),
  );
  $export['schools'] = $view;

  $view = new view();
  $view->name = 'speaking_and_listening';
  $view->description = '';
  $view->tag = 'PRC';
  $view->base_table = 'node';
  $view->human_name = 'Speaking and Listening';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_file_single' => 'field_file_single',
    'title' => 'title',
    'field_subject' => 'field_subject',
    'field_grade_level' => 'field_grade_level',
    'field_resource_type' => 'field_resource_type',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_file_single' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_subject' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_grade_level' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resource_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Field: Content: File */
  $handler->display->display_options['fields']['field_file_single']['id'] = 'field_file_single';
  $handler->display->display_options['fields']['field_file_single']['table'] = 'field_data_field_file_single';
  $handler->display->display_options['fields']['field_file_single']['field'] = 'field_file_single';
  $handler->display->display_options['fields']['field_file_single']['label'] = '';
  $handler->display->display_options['fields']['field_file_single']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file_single']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_single']['type'] = 'file_url_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Resource Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_file_single]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  /* Field: Content: Grade Level */
  $handler->display->display_options['fields']['field_grade_level_unlimited']['id'] = 'field_grade_level_unlimited';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['table'] = 'field_data_field_grade_level_unlimited';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['field'] = 'field_grade_level_unlimited';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_grade_level_unlimited']['delta_offset'] = '0';
  /* Field: Content: Resource Type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = TRUE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'speaking_and_listening_resource' => 'speaking_and_listening_resource',
  );

  /* Display: PRC Speaking and Listening */
  $handler = $view->new_display('panel_pane', 'PRC Speaking and Listening', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'PRC Instruction';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $export['speaking_and_listening'] = $view;

  $view = new view();
  $view->name = 'system_check_export';
  $view->description = 'TRT Export System Check';
  $view->tag = 'PRC,TRT';
  $view->base_table = 'eck_prc_trt';
  $view->human_name = 'System Check Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Prc_trt: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Filter criterion: Prc_trt: prc_trt type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_prc_trt';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'system_check' => 'system_check',
  );
  $export['system_check_export'] = $view;

  $view = new view();
  $view->name = 'taxonomy_term';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Taxonomy term';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 15;
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['taxonomy_term'] = $view;

  $view = new view();
  $view->name = 'test_search_two';
  $view->description = '';
  $view->tag = 'PRC,search';
  $view->base_table = 'search_api_index_digital_library_content_index';
  $view->human_name = 'Test Search Two';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'oldest on top';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'most recent on top';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results to display. Please change the search keywords and try again.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_digital_library_content_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Indexed Node: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_digital_library_content_index';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Date changed';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_digital_library_content_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Enter your keywords';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
    5 => 0,
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['test_search_two'] = $view;

  $view = new view();
  $view->name = 'top_content';
  $view->description = 'Top rated content';
  $view->tag = 'votingapi';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Top rated content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'title' => 'title',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['order'] = 'desc';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created']['custom_date_format'] = '1';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Fivestar */
  $handler = $view->new_display('page', 'Fivestar', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'title' => 'title',
    'created' => 'created',
    'value' => 'value',
  );
  $handler->display->display_options['style_options']['default'] = 'value';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['order'] = 'desc';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['content'] = 'This page is a demonstration of VotingAPI\'s integration with the Views module. It\'s set up to display nodes sorted by percentage ratings, the style used by Fivestar module.';
  $handler->display->display_options['header']['text']['format'] = '1';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Voting results';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => 'vote',
    'function' => 'average',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created']['custom_date_format'] = '1';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Rating';
  $handler->display->display_options['fields']['value']['appearance'] = 'fivestar_views_value_display_handler';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'top-rated-percent';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Top content (Fivestar)';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Plus1 */
  $handler = $view->new_display('page', 'Plus1', 'page_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'title' => 'title',
    'created' => 'created',
    'value' => 'value',
  );
  $handler->display->display_options['style_options']['default'] = 'value';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['order'] = 'desc';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['content'] = 'This page is a demonstration of VotingAPI\'s integration with the Views module. It\'s set up to display nodes sorted by point ratings, the style used by the Plus1 and VoteUpDown modules.';
  $handler->display->display_options['header']['text']['format'] = '1';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Voting results';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote',
    'function' => 'sum',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created']['custom_date_format'] = '1';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Rating';
  $handler->display->display_options['fields']['value']['suffix'] = ' points';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'top-rated-points';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Top content (Plus1)';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Current user */
  $handler = $view->new_display('page', 'Current user', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Your votes';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'value_type' => 'value_type',
    'value' => 'value',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value_type' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'timestamp' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['order'] = 'desc';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['label'] = 'Individual votes';
  $handler->display->display_options['relationships']['votingapi_vote']['required'] = TRUE;
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Votes: Value type */
  $handler->display->display_options['fields']['value_type']['id'] = 'value_type';
  $handler->display->display_options['fields']['value_type']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value_type']['field'] = 'value_type';
  $handler->display->display_options['fields']['value_type']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value_type']['label'] = 'Vote type';
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  /* Field: Votes: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = '1';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Votes: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'votingapi_vote';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Votes: User */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Everyone';
  $handler->display->display_options['arguments']['uid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid']['title'] = '%1\'s votes';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Votes: Value */
  $handler->display->display_options['filters']['value']['id'] = 'value';
  $handler->display->display_options['filters']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['filters']['value']['field'] = 'value';
  $handler->display->display_options['filters']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['filters']['value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['value']['group'] = '0';
  $handler->display->display_options['filters']['value']['expose']['operator'] = FALSE;
  $handler->display->display_options['path'] = 'your-votes';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Your votes';
  $handler->display->display_options['menu']['weight'] = '0';
  $export['top_content'] = $view;

  $view = new view();
  $view->name = 'tracker';
  $view->description = 'Shows all new activity on system.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Tracker';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent posts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'type' => 'type',
    'title' => 'title',
    'name' => 'name',
    'comment_count' => 'comment_count',
    'last_comment_timestamp' => 'last_comment_timestamp',
    'timestamp' => 'title',
    'new_comments' => 'comment_count',
  );
  $handler->display->display_options['style_options']['default'] = 'last_comment_timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'type' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'separator' => '&nbsp;',
    ),
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'comment_count' => array(
      'sortable' => 1,
      'separator' => '<br />',
    ),
    'last_comment_timestamp' => array(
      'sortable' => 1,
      'separator' => '&nbsp;',
    ),
    'timestamp' => array(
      'separator' => '',
    ),
    'new_comments' => array(
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['order'] = 'desc';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Replies';
  /* Field: Content: Last comment time */
  $handler->display->display_options['fields']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
  $handler->display->display_options['fields']['last_comment_timestamp']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
  $handler->display->display_options['fields']['last_comment_timestamp']['label'] = 'Last Post';
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['comments'] = TRUE;
  /* Field: Content: New comments */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['label'] = '';
  $handler->display->display_options['fields']['new_comments']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['new_comments']['suffix'] = ' new';
  /* Sort criterion: Content: Last comment time */
  $handler->display->display_options['sorts']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
  $handler->display->display_options['sorts']['last_comment_timestamp']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
  /* Contextual filter: Content: User posted or commented */
  $handler->display->display_options['arguments']['uid_touch']['id'] = 'uid_touch';
  $handler->display->display_options['arguments']['uid_touch']['table'] = 'node';
  $handler->display->display_options['arguments']['uid_touch']['field'] = 'uid_touch';
  $handler->display->display_options['arguments']['uid_touch']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid_touch']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid_touch']['title'] = 'Recent posts for %1';
  $handler->display->display_options['arguments']['uid_touch']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid_touch']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_touch']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'tracker';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Recent posts';
  $export['tracker'] = $view;

  $view = new view();
  $view->name = 'transcript';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'course_report';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Completed Activities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'timestamp' => 'timestamp',
    'date_completed' => 'date_completed',
    'section_name' => 'section_name',
  );
  $handler->display->display_options['style_options']['default'] = 'date_completed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'date_completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'section_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'You don\'t have any completed activities.';
  $handler->display->display_options['empty']['text']['format'] = '2';
  /* Relationship: Course report: Nid */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'course_report';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Course report: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'course_report';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Course report: Course enrollment */
  $handler->display->display_options['relationships']['course_enrollment']['id'] = 'course_enrollment';
  $handler->display->display_options['relationships']['course_enrollment']['table'] = 'course_report';
  $handler->display->display_options['relationships']['course_enrollment']['field'] = 'course_enrollment';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  /* Field: Course enrollment: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'course_enrollment';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'course_enrollment';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Date enrolled';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'm/d/Y';
  /* Field: Course report: Section_name */
  $handler->display->display_options['fields']['section_name']['id'] = 'section_name';
  $handler->display->display_options['fields']['section_name']['table'] = 'course_report';
  $handler->display->display_options['fields']['section_name']['field'] = 'section_name';
  $handler->display->display_options['fields']['section_name']['label'] = 'Status';
  /* Field: Course report: Date_completed */
  $handler->display->display_options['fields']['date_completed']['id'] = 'date_completed';
  $handler->display->display_options['fields']['date_completed']['table'] = 'course_report';
  $handler->display->display_options['fields']['date_completed']['field'] = 'date_completed';
  $handler->display->display_options['fields']['date_completed']['label'] = 'Date completed';
  $handler->display->display_options['fields']['date_completed']['date_format'] = 'short';
  $handler->display->display_options['fields']['date_completed']['custom_date_format'] = 'm/d/Y';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  /* Filter criterion: Course report: Complete */
  $handler->display->display_options['filters']['complete']['id'] = 'complete';
  $handler->display->display_options['filters']['complete']['table'] = 'course_report';
  $handler->display->display_options['filters']['complete']['field'] = 'complete';
  $handler->display->display_options['filters']['complete']['value']['min'] = '1';
  $handler->display->display_options['filters']['complete']['value']['max'] = '1';
  $handler->display->display_options['filters']['complete']['value']['value'] = '1';
  $handler->display->display_options['filters']['complete']['expose']['operator'] = FALSE;

  /* Display: Pending */
  $handler = $view->new_display('page', 'Pending', 'pending');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Courses in progress';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = TRUE;
  $handler->display->display_options['empty']['text']['content'] = 'You don\'t have any courses in progress.';
  $handler->display->display_options['empty']['text']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  /* Field: Course enrollment: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'course_enrollment';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'course_enrollment';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Date enrolled';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'd/m/Y';
  /* Field: Course report: Section_name */
  $handler->display->display_options['fields']['section_name']['id'] = 'section_name';
  $handler->display->display_options['fields']['section_name']['table'] = 'course_report';
  $handler->display->display_options['fields']['section_name']['field'] = 'section_name';
  $handler->display->display_options['fields']['section_name']['label'] = 'Status';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Course report: Complete */
  $handler->display->display_options['filters']['complete']['id'] = 'complete';
  $handler->display->display_options['filters']['complete']['table'] = 'course_report';
  $handler->display->display_options['filters']['complete']['field'] = 'complete';
  $handler->display->display_options['path'] = 'user/%/courses/pending';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'In progress';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Completed */
  $handler = $view->new_display('page', 'Completed', 'completed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Completed courses';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = TRUE;
  $handler->display->display_options['empty']['text']['content'] = 'You don\'t have any completed courses.';
  $handler->display->display_options['empty']['text']['format'] = 'filtered_html';
  $handler->display->display_options['path'] = 'user/%/courses/completed';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Completed';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Courses';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $export['transcript'] = $view;

  $view = new view();
  $view->name = 'trt_capacity_check_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_prc_trt';
  $view->human_name = 'TRT Capacity Check Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_ref_district_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'District';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'School';
  /* Field: Content: State contact's email address */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['fields']['field_contact_email']['label'] = 'School Contact Email Address';
  /* Field: prc_trt: Devices Capacity */
  $handler->display->display_options['fields']['field_devices_capacity']['id'] = 'field_devices_capacity';
  $handler->display->display_options['fields']['field_devices_capacity']['table'] = 'field_data_field_devices_capacity';
  $handler->display->display_options['fields']['field_devices_capacity']['field'] = 'field_devices_capacity';
  $handler->display->display_options['fields']['field_devices_capacity']['empty'] = '-';
  $handler->display->display_options['fields']['field_devices_capacity']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Devices Capacity Results */
  $handler->display->display_options['fields']['field_devices_capacity_results']['id'] = 'field_devices_capacity_results';
  $handler->display->display_options['fields']['field_devices_capacity_results']['table'] = 'field_data_field_devices_capacity_results';
  $handler->display->display_options['fields']['field_devices_capacity_results']['field'] = 'field_devices_capacity_results';
  $handler->display->display_options['fields']['field_devices_capacity_results']['label'] = 'Devices Capacity results';
  /* Field: prc_trt: Bandwidth Capacity */
  $handler->display->display_options['fields']['field_bandwidth_capacity']['id'] = 'field_bandwidth_capacity';
  $handler->display->display_options['fields']['field_bandwidth_capacity']['table'] = 'field_data_field_bandwidth_capacity';
  $handler->display->display_options['fields']['field_bandwidth_capacity']['field'] = 'field_bandwidth_capacity';
  $handler->display->display_options['fields']['field_bandwidth_capacity']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Bandwidth Capacity Results */
  $handler->display->display_options['fields']['field_bandwidth_capacity_results']['id'] = 'field_bandwidth_capacity_results';
  $handler->display->display_options['fields']['field_bandwidth_capacity_results']['table'] = 'field_data_field_bandwidth_capacity_results';
  $handler->display->display_options['fields']['field_bandwidth_capacity_results']['field'] = 'field_bandwidth_capacity_results';
  $handler->display->display_options['fields']['field_bandwidth_capacity_results']['label'] = 'Bandwidth Capacity results';
  /* Field: prc_trt: Number of devices */
  $handler->display->display_options['fields']['field_number_of_devices']['id'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['table'] = 'field_data_field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['field'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['label'] = 'Number of devices ready for assessment';
  $handler->display->display_options['fields']['field_number_of_devices']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Number of students */
  $handler->display->display_options['fields']['field_number_of_students']['id'] = 'field_number_of_students';
  $handler->display->display_options['fields']['field_number_of_students']['table'] = 'field_data_field_number_of_students';
  $handler->display->display_options['fields']['field_number_of_students']['field'] = 'field_number_of_students';
  $handler->display->display_options['fields']['field_number_of_students']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Number of days of testing */
  $handler->display->display_options['fields']['field_number_testing_days']['id'] = 'field_number_testing_days';
  $handler->display->display_options['fields']['field_number_testing_days']['table'] = 'field_data_field_number_testing_days';
  $handler->display->display_options['fields']['field_number_testing_days']['field'] = 'field_number_testing_days';
  $handler->display->display_options['fields']['field_number_testing_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Number of test sessions per day */
  $handler->display->display_options['fields']['field_number_of_sessions']['id'] = 'field_number_of_sessions';
  $handler->display->display_options['fields']['field_number_of_sessions']['table'] = 'field_data_field_number_of_sessions';
  $handler->display->display_options['fields']['field_number_of_sessions']['field'] = 'field_number_of_sessions';
  $handler->display->display_options['fields']['field_number_of_sessions']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Number of sittings per student */
  $handler->display->display_options['fields']['field_sittings_per_student']['id'] = 'field_sittings_per_student';
  $handler->display->display_options['fields']['field_sittings_per_student']['table'] = 'field_data_field_sittings_per_student';
  $handler->display->display_options['fields']['field_sittings_per_student']['field'] = 'field_sittings_per_student';
  $handler->display->display_options['fields']['field_sittings_per_student']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Number of devices required */
  $handler->display->display_options['fields']['devices_required']['id'] = 'devices_required';
  $handler->display->display_options['fields']['devices_required']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['devices_required']['field'] = 'devices_required';
  $handler->display->display_options['fields']['devices_required']['label'] = 'Number of devices required';
  /* Field: prc_trt: Speed of connection (in Mbps) */
  $handler->display->display_options['fields']['field_speed_of_connection']['id'] = 'field_speed_of_connection';
  $handler->display->display_options['fields']['field_speed_of_connection']['table'] = 'field_data_field_speed_of_connection';
  $handler->display->display_options['fields']['field_speed_of_connection']['field'] = 'field_speed_of_connection';
  $handler->display->display_options['fields']['field_speed_of_connection']['label'] = 'Speed of connection';
  $handler->display->display_options['fields']['field_speed_of_connection']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Network connection */
  $handler->display->display_options['fields']['field_network_connection_type']['id'] = 'field_network_connection_type';
  $handler->display->display_options['fields']['field_network_connection_type']['table'] = 'field_data_field_network_connection_type';
  $handler->display->display_options['fields']['field_network_connection_type']['field'] = 'field_network_connection_type';
  $handler->display->display_options['fields']['field_network_connection_type']['empty'] = '-';
  /* Field: prc_trt: Wired connection speed */
  $handler->display->display_options['fields']['field_wired_connection_speed']['id'] = 'field_wired_connection_speed';
  $handler->display->display_options['fields']['field_wired_connection_speed']['table'] = 'field_data_field_wired_connection_speed';
  $handler->display->display_options['fields']['field_wired_connection_speed']['field'] = 'field_wired_connection_speed';
  $handler->display->display_options['fields']['field_wired_connection_speed']['empty'] = '-';
  /* Field: prc_trt: Wireless connection speed */
  $handler->display->display_options['fields']['field_wireless_connection_speed']['id'] = 'field_wireless_connection_speed';
  $handler->display->display_options['fields']['field_wireless_connection_speed']['table'] = 'field_data_field_wireless_connection_speed';
  $handler->display->display_options['fields']['field_wireless_connection_speed']['field'] = 'field_wireless_connection_speed';
  $handler->display->display_options['fields']['field_wireless_connection_speed']['empty'] = '-';
  /* Field: prc_trt: Number of access points */
  $handler->display->display_options['fields']['field_number_of_access_points']['id'] = 'field_number_of_access_points';
  $handler->display->display_options['fields']['field_number_of_access_points']['table'] = 'field_data_field_number_of_access_points';
  $handler->display->display_options['fields']['field_number_of_access_points']['field'] = 'field_number_of_access_points';
  $handler->display->display_options['fields']['field_number_of_access_points']['empty'] = '-';
  $handler->display->display_options['fields']['field_number_of_access_points']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_ref_district_target_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_1']['id'] = 'title_1';
  $handler->display->display_options['sorts']['title_1']['table'] = 'node';
  $handler->display->display_options['sorts']['title_1']['field'] = 'title';
  $handler->display->display_options['sorts']['title_1']['relationship'] = 'field_ref_school_target_id';
  /* Filter criterion: Prc_trt: prc_trt type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_prc_trt';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'capacity_check' => 'capacity_check',
  );

  /* Display: District Capacity Check Export */
  $handler = $view->new_display('views_data_export', 'District Capacity Check Export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_school_target_id']['id'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['table'] = 'field_data_field_ref_school';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['field'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_district_target_id']['id'] = 'field_ref_district_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['table'] = 'field_data_field_ref_district';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['field'] = 'field_ref_district_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_ref_district_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'trt/capacity-check/export/district/%';

  /* Display: State Capacity Check Export */
  $handler = $view->new_display('views_data_export', 'State Capacity Check Export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_school_target_id']['id'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['table'] = 'field_data_field_ref_school';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['field'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_district_target_id']['id'] = 'field_ref_district_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['table'] = 'field_data_field_ref_district';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['field'] = 'field_ref_district_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_trt_state_target_id']['id'] = 'field_ref_trt_state_target_id';
  $handler->display->display_options['relationships']['field_ref_trt_state_target_id']['table'] = 'field_data_field_ref_trt_state';
  $handler->display->display_options['relationships']['field_ref_trt_state_target_id']['field'] = 'field_ref_trt_state_target_id';
  $handler->display->display_options['relationships']['field_ref_trt_state_target_id']['relationship'] = 'field_ref_district_target_id';
  $handler->display->display_options['relationships']['field_ref_trt_state_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_ref_trt_state_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'trt/capacity-check/export/state/%';
  $export['trt_capacity_check_export'] = $view;

  $view = new view();
  $view->name = 'trt_district_readiness_schools';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'TRT District Readiness Schools';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_number_of_students' => 'field_number_of_students',
    'field_devices_capacity' => 'field_devices_capacity',
    'field_devices_capacity_results' => 'field_devices_capacity_results',
    'field_bandwidth_capacity' => 'field_bandwidth_capacity',
    'field_bandwidth_capacity_results' => 'field_bandwidth_capacity_results',
    'id' => 'id',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_number_of_students' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_devices_capacity' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_devices_capacity_results' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_bandwidth_capacity' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_bandwidth_capacity_results' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_ref_school_prc_trt']['id'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['relationships']['reverse_field_ref_school_prc_trt']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_ref_school_prc_trt']['field'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['relationships']['reverse_field_ref_school_prc_trt']['label'] = 'Capacity Check referencing School';
  $handler->display->display_options['relationships']['reverse_field_ref_school_prc_trt']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'School Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Number of students */
  $handler->display->display_options['fields']['field_number_of_students']['id'] = 'field_number_of_students';
  $handler->display->display_options['fields']['field_number_of_students']['table'] = 'field_data_field_number_of_students';
  $handler->display->display_options['fields']['field_number_of_students']['field'] = 'field_number_of_students';
  $handler->display->display_options['fields']['field_number_of_students']['relationship'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['fields']['field_number_of_students']['label'] = 'No. of Students';
  $handler->display->display_options['fields']['field_number_of_students']['empty'] = '—';
  $handler->display->display_options['fields']['field_number_of_students']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: MAX(prc_trt: Devices Capacity) */
  $handler->display->display_options['fields']['field_devices_capacity']['id'] = 'field_devices_capacity';
  $handler->display->display_options['fields']['field_devices_capacity']['table'] = 'field_data_field_devices_capacity';
  $handler->display->display_options['fields']['field_devices_capacity']['field'] = 'field_devices_capacity';
  $handler->display->display_options['fields']['field_devices_capacity']['relationship'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['fields']['field_devices_capacity']['group_type'] = 'max';
  $handler->display->display_options['fields']['field_devices_capacity']['empty'] = '—';
  $handler->display->display_options['fields']['field_devices_capacity']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_devices_capacity']['group_column'] = 'entity_id';
  /* Field: MAX(prc_trt: Devices Capacity Results) */
  $handler->display->display_options['fields']['field_devices_capacity_results']['id'] = 'field_devices_capacity_results';
  $handler->display->display_options['fields']['field_devices_capacity_results']['table'] = 'field_data_field_devices_capacity_results';
  $handler->display->display_options['fields']['field_devices_capacity_results']['field'] = 'field_devices_capacity_results';
  $handler->display->display_options['fields']['field_devices_capacity_results']['relationship'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['fields']['field_devices_capacity_results']['group_type'] = 'max';
  $handler->display->display_options['fields']['field_devices_capacity_results']['empty'] = '—';
  $handler->display->display_options['fields']['field_devices_capacity_results']['group_column'] = 'entity_id';
  /* Field: MAX(prc_trt: Bandwidth Capacity) */
  $handler->display->display_options['fields']['field_bandwidth_capacity']['id'] = 'field_bandwidth_capacity';
  $handler->display->display_options['fields']['field_bandwidth_capacity']['table'] = 'field_data_field_bandwidth_capacity';
  $handler->display->display_options['fields']['field_bandwidth_capacity']['field'] = 'field_bandwidth_capacity';
  $handler->display->display_options['fields']['field_bandwidth_capacity']['relationship'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['fields']['field_bandwidth_capacity']['group_type'] = 'max';
  $handler->display->display_options['fields']['field_bandwidth_capacity']['empty'] = '—';
  $handler->display->display_options['fields']['field_bandwidth_capacity']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_bandwidth_capacity']['group_column'] = 'entity_id';
  /* Field: MAX(prc_trt: Bandwidth Capacity Results) */
  $handler->display->display_options['fields']['field_bandwidth_capacity_results']['id'] = 'field_bandwidth_capacity_results';
  $handler->display->display_options['fields']['field_bandwidth_capacity_results']['table'] = 'field_data_field_bandwidth_capacity_results';
  $handler->display->display_options['fields']['field_bandwidth_capacity_results']['field'] = 'field_bandwidth_capacity_results';
  $handler->display->display_options['fields']['field_bandwidth_capacity_results']['relationship'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['fields']['field_bandwidth_capacity_results']['group_type'] = 'max';
  $handler->display->display_options['fields']['field_bandwidth_capacity_results']['empty'] = '—';
  $handler->display->display_options['fields']['field_bandwidth_capacity_results']['group_column'] = 'entity_id';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: District (field_ref_district) */
  $handler->display->display_options['arguments']['field_ref_district_target_id']['id'] = 'field_ref_district_target_id';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['table'] = 'field_data_field_ref_district';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['field'] = 'field_ref_district_target_id';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'school' => 'school',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Prc_trt: prc_trt type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'eck_prc_trt';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'system_check' => 'system_check',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  /* Filter criterion: prc_trt: Devices Capacity (field_devices_capacity) */
  $handler->display->display_options['filters']['field_devices_capacity_value']['id'] = 'field_devices_capacity_value';
  $handler->display->display_options['filters']['field_devices_capacity_value']['table'] = 'field_data_field_devices_capacity';
  $handler->display->display_options['filters']['field_devices_capacity_value']['field'] = 'field_devices_capacity_value';
  $handler->display->display_options['filters']['field_devices_capacity_value']['relationship'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['filters']['field_devices_capacity_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_devices_capacity_value']['group'] = 2;

  /* Display: TRT District Readiness Schools */
  $handler = $view->new_display('panel_pane', 'TRT District Readiness Schools', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'TRT District Readiness';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_ref_district_target_id' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: District (field_ref_district)',
    ),
  );
  $export['trt_district_readiness_schools'] = $view;

  $view = new view();
  $view->name = 'trt_district_schools';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'TRT District Schools';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No schools have been added to your district. Please click one of the Add School links above to add schools.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_ref_school_prc_trt']['id'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['relationships']['reverse_field_ref_school_prc_trt']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_ref_school_prc_trt']['field'] = 'reverse_field_ref_school_prc_trt';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::quiz_add_question_to_quiz' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::prc_trt_delete_schools' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::prc_trt_request_readiness_checks' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'School Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]/edit';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: State contact's email address */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['label'] = 'School Contact Email Address';
  /* Field: COUNT(DISTINCT Prc_trt: Id) */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['relationship'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['fields']['id']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['id']['label'] = 'Readiness Checks Run?';
  $handler->display->display_options['fields']['id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['id']['empty'] = 'No';
  $handler->display->display_options['fields']['id']['empty_zero'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: District (field_ref_district) */
  $handler->display->display_options['arguments']['field_ref_district_target_id']['id'] = 'field_ref_district_target_id';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['table'] = 'field_data_field_ref_district';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['field'] = 'field_ref_district_target_id';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ref_district_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'school' => 'school',
  );
  /* Filter criterion: COUNT(DISTINCT Prc_trt: Id) */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'eck_prc_trt';
  $handler->display->display_options['filters']['id']['field'] = 'id';
  $handler->display->display_options['filters']['id']['relationship'] = 'reverse_field_ref_school_prc_trt';
  $handler->display->display_options['filters']['id']['group_type'] = 'count_distinct';
  $handler->display->display_options['filters']['id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['id']['expose']['operator_id'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['label'] = 'Id';
  $handler->display->display_options['filters']['id']['expose']['operator'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['identifier'] = 'id';
  $handler->display->display_options['filters']['id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['id']['group_info']['label'] = 'Readiness Checks Run?';
  $handler->display->display_options['filters']['id']['group_info']['identifier'] = 'id';
  $handler->display->display_options['filters']['id']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['id']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Yes',
      'operator' => '!=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'No',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: TRT District Schools List */
  $handler = $view->new_display('panel_pane', 'TRT District Schools List', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'PRC TRT';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_ref_district_target_id' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: District (field_ref_district)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['trt_district_schools'] = $view;

  $view = new view();
  $view->name = 'trt_districts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'TRT Districts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Instructions to District Admin to add district, which will allow results generate by School Admin to be reported to the district.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Readiness';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Summary of what user can do here: add schools, request school admins to run checks, view readiness by schools in district.';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'district' => 'district',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'PRC TRT';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: State Readiness District List */
  $handler = $view->new_display('panel_pane', 'State Readiness District List', 'panel_pane_2');
  $handler->display->display_options['display_description'] = 'District List filtered by State';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No districts in your state have been created';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Readiness';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Summary of what user can do here: add schools, request school admins to run checks, view readiness by schools in district.';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: State (field_ref_trt_state) */
  $handler->display->display_options['arguments']['field_ref_trt_state_target_id']['id'] = 'field_ref_trt_state_target_id';
  $handler->display->display_options['arguments']['field_ref_trt_state_target_id']['table'] = 'field_data_field_ref_trt_state';
  $handler->display->display_options['arguments']['field_ref_trt_state_target_id']['field'] = 'field_ref_trt_state_target_id';
  $handler->display->display_options['arguments']['field_ref_trt_state_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_ref_trt_state_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ref_trt_state_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ref_trt_state_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ref_trt_state_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'TRT State Readiness';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_ref_trt_state_target_id' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: State (field_ref_trt_state)',
    ),
  );
  $export['trt_districts'] = $view;

  $view = new view();
  $view->name = 'trt_states';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'TRT States';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'States';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No states have been created.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Readiness';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Summary of what user can do here: export state readiness check data, view readiness by district, export district readiness checks data view school readiness data.';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: State contact&#039;s email address (field_contact_email) */
  $handler->display->display_options['arguments']['field_contact_email_value']['id'] = 'field_contact_email_value';
  $handler->display->display_options['arguments']['field_contact_email_value']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['arguments']['field_contact_email_value']['field'] = 'field_contact_email_value';
  $handler->display->display_options['arguments']['field_contact_email_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_contact_email_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_contact_email_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_contact_email_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_contact_email_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_contact_email_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'state' => 'state',
  );

  /* Display: TRT Readiness Page State List */
  $handler = $view->new_display('panel_pane', 'TRT Readiness Page State List', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'TRT Readiness';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_contact_email_value' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: School contact&#039;s email address (field_contact_email)',
    ),
  );

  /* Display: All TRT States */
  $handler = $view->new_display('panel_pane', 'All TRT States', 'panel_pane_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Member State */
  $handler->display->display_options['fields']['field_member_state']['id'] = 'field_member_state';
  $handler->display->display_options['fields']['field_member_state']['table'] = 'field_data_field_member_state';
  $handler->display->display_options['fields']['field_member_state']['field'] = 'field_member_state';
  $handler->display->display_options['fields']['field_member_state']['label'] = 'Member State1';
  $handler->display->display_options['fields']['field_member_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_member_state']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_member_state']['alter']['text'] = '- PARCC Member';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [field_member_state]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'TRT PARCC Readiness';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $export['trt_states'] = $view;

  $view = new view();
  $view->name = 'trt_system_check_export';
  $view->description = '';
  $view->tag = 'PRC,TRT';
  $view->base_table = 'eck_prc_trt';
  $view->human_name = 'TRT System Check Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: prc_trt: System check name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['empty'] = '-';
  /* Field: Prc_trt: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date & Time System Check Run';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: prc_trt: Number of devices */
  $handler->display->display_options['fields']['field_number_of_devices']['id'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['table'] = 'field_data_field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['field'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['label'] = 'Number of devices ready for assessment';
  $handler->display->display_options['fields']['field_number_of_devices']['empty'] = '-';
  $handler->display->display_options['fields']['field_number_of_devices']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Result */
  $handler->display->display_options['fields']['field_result']['id'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['table'] = 'field_data_field_result';
  $handler->display->display_options['fields']['field_result']['field'] = 'field_result';
  /* Field: prc_trt: Device type */
  $handler->display->display_options['fields']['field_device_type']['id'] = 'field_device_type';
  $handler->display->display_options['fields']['field_device_type']['table'] = 'field_data_field_device_type';
  $handler->display->display_options['fields']['field_device_type']['field'] = 'field_device_type';
  $handler->display->display_options['fields']['field_device_type']['empty'] = '-';
  $handler->display->display_options['fields']['field_device_type']['empty_zero'] = TRUE;
  /* Field: prc_trt: Operating system */
  $handler->display->display_options['fields']['field_operating_system']['id'] = 'field_operating_system';
  $handler->display->display_options['fields']['field_operating_system']['table'] = 'field_data_field_operating_system';
  $handler->display->display_options['fields']['field_operating_system']['field'] = 'field_operating_system';
  $handler->display->display_options['fields']['field_operating_system']['empty'] = '-';
  $handler->display->display_options['fields']['field_operating_system']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Operating system: Results */
  $handler->display->display_options['fields']['operating_system_pass']['id'] = 'operating_system_pass';
  $handler->display->display_options['fields']['operating_system_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['operating_system_pass']['field'] = 'operating_system_pass';
  $handler->display->display_options['fields']['operating_system_pass']['label'] = 'Operating System results';
  $handler->display->display_options['fields']['operating_system_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['operating_system_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['operating_system_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['operating_system_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Monitor size (in inches) */
  $handler->display->display_options['fields']['field_monitor_size']['id'] = 'field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['table'] = 'field_data_field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['field'] = 'field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['empty'] = '-';
  $handler->display->display_options['fields']['field_monitor_size']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_monitor_size']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Monitor size: Results */
  $handler->display->display_options['fields']['monitor_size_pass']['id'] = 'monitor_size_pass';
  $handler->display->display_options['fields']['monitor_size_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['monitor_size_pass']['field'] = 'monitor_size_pass';
  $handler->display->display_options['fields']['monitor_size_pass']['label'] = 'Monitor Size results';
  $handler->display->display_options['fields']['monitor_size_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['monitor_size_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['monitor_size_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['monitor_size_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Monitor color depth */
  $handler->display->display_options['fields']['field_monitor_color_depth']['id'] = 'field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['table'] = 'field_data_field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['field'] = 'field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['empty'] = '-';
  $handler->display->display_options['fields']['field_monitor_color_depth']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Monitor color depth: Results */
  $handler->display->display_options['fields']['monitor_color_depth_pass']['id'] = 'monitor_color_depth_pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['field'] = 'monitor_color_depth_pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['label'] = 'Monitor color depth results';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['monitor_color_depth_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Screen Resolution Width */
  $handler->display->display_options['fields']['field_screen_resolution_width']['id'] = 'field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['table'] = 'field_data_field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['field'] = 'field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_width']['empty'] = '-';
  $handler->display->display_options['fields']['field_screen_resolution_width']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_width']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Screen Resolution Height */
  $handler->display->display_options['fields']['field_screen_resolution_height']['id'] = 'field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['table'] = 'field_data_field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['field'] = 'field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_height']['alter']['text'] = '[field_screen_resolution_width] x [field_screen_resolution_height]';
  $handler->display->display_options['fields']['field_screen_resolution_height']['empty'] = '-';
  $handler->display->display_options['fields']['field_screen_resolution_height']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_height']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Screen resolution: Results */
  $handler->display->display_options['fields']['screen_resolution_pass']['id'] = 'screen_resolution_pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['screen_resolution_pass']['field'] = 'screen_resolution_pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['label'] = 'Screen resolution results';
  $handler->display->display_options['fields']['screen_resolution_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['screen_resolution_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['screen_resolution_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Processor speed */
  $handler->display->display_options['fields']['field_processor_speed']['id'] = 'field_processor_speed';
  $handler->display->display_options['fields']['field_processor_speed']['table'] = 'field_data_field_processor_speed';
  $handler->display->display_options['fields']['field_processor_speed']['field'] = 'field_processor_speed';
  /* Field: Prc_trt: Extrafield Processor speed: Results */
  $handler->display->display_options['fields']['processor_pass']['id'] = 'processor_pass';
  $handler->display->display_options['fields']['processor_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['processor_pass']['field'] = 'processor_pass';
  $handler->display->display_options['fields']['processor_pass']['label'] = 'Processor speed results';
  /* Field: prc_trt: RAM */
  $handler->display->display_options['fields']['field_ram']['id'] = 'field_ram';
  $handler->display->display_options['fields']['field_ram']['table'] = 'field_data_field_ram';
  $handler->display->display_options['fields']['field_ram']['field'] = 'field_ram';
  $handler->display->display_options['fields']['field_ram']['empty'] = '-';
  $handler->display->display_options['fields']['field_ram']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield RAM: Results */
  $handler->display->display_options['fields']['ram_pass']['id'] = 'ram_pass';
  $handler->display->display_options['fields']['ram_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['ram_pass']['field'] = 'ram_pass';
  $handler->display->display_options['fields']['ram_pass']['label'] = 'RAM results';
  $handler->display->display_options['fields']['ram_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ram_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['ram_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['ram_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser */
  $handler->display->display_options['fields']['field_browser']['id'] = 'field_browser';
  $handler->display->display_options['fields']['field_browser']['table'] = 'field_data_field_browser';
  $handler->display->display_options['fields']['field_browser']['field'] = 'field_browser';
  $handler->display->display_options['fields']['field_browser']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser Version */
  $handler->display->display_options['fields']['field_browser_version']['id'] = 'field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['table'] = 'field_data_field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['field'] = 'field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_version']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_browser_version']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Browser: Results */
  $handler->display->display_options['fields']['browser_pass']['id'] = 'browser_pass';
  $handler->display->display_options['fields']['browser_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['browser_pass']['field'] = 'browser_pass';
  $handler->display->display_options['fields']['browser_pass']['label'] = 'Browser results';
  /* Field: prc_trt: Browser: Cookies enabled */
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['id'] = 'field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['table'] = 'field_data_field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['field'] = 'field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Cookies: Results */
  $handler->display->display_options['fields']['cookies_pass']['id'] = 'cookies_pass';
  $handler->display->display_options['fields']['cookies_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['cookies_pass']['field'] = 'cookies_pass';
  $handler->display->display_options['fields']['cookies_pass']['label'] = 'Cookies enabled results';
  $handler->display->display_options['fields']['cookies_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['cookies_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['cookies_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['cookies_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: JavaScript enabled */
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['id'] = 'field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['table'] = 'field_data_field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['field'] = 'field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Javascript: Results */
  $handler->display->display_options['fields']['javascript_pass']['id'] = 'javascript_pass';
  $handler->display->display_options['fields']['javascript_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['javascript_pass']['field'] = 'javascript_pass';
  $handler->display->display_options['fields']['javascript_pass']['label'] = 'JavaScript enabled results';
  $handler->display->display_options['fields']['javascript_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['javascript_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['javascript_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['javascript_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: Images enabled */
  $handler->display->display_options['fields']['field_browser_images_enabled']['id'] = 'field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['table'] = 'field_data_field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['field'] = 'field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_images_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Images: Results */
  $handler->display->display_options['fields']['images_pass']['id'] = 'images_pass';
  $handler->display->display_options['fields']['images_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['images_pass']['field'] = 'images_pass';
  $handler->display->display_options['fields']['images_pass']['label'] = 'Images enabled results';
  $handler->display->display_options['fields']['images_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['images_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['images_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['images_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: Java runtime plugin version */
  $handler->display->display_options['fields']['field_jre_version']['id'] = 'field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['table'] = 'field_data_field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['field'] = 'field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['empty'] = '-';
  $handler->display->display_options['fields']['field_jre_version']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Java: Results */
  $handler->display->display_options['fields']['jre_version_pass']['id'] = 'jre_version_pass';
  $handler->display->display_options['fields']['jre_version_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['jre_version_pass']['field'] = 'jre_version_pass';
  $handler->display->display_options['fields']['jre_version_pass']['label'] = 'Java plugin results';
  $handler->display->display_options['fields']['jre_version_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['jre_version_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['jre_version_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['jre_version_pass']['empty_zero'] = TRUE;
  /* Sort criterion: Prc_trt: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'eck_prc_trt';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Prc_trt: prc_trt type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_prc_trt';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'system_check' => 'system_check',
  );

  /* Display: Raw Data export */
  $handler = $view->new_display('views_data_export', 'Raw Data export', 'views_data_export_1');
  $handler->display->display_options['display_description'] = 'No School, district, state';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'trt/system-check/export';

  /* Display: School Data export */
  $handler = $view->new_display('views_data_export', 'School Data export', 'views_data_export_2');
  $handler->display->display_options['display_description'] = 'System check export by School';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_school_target_id']['id'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['table'] = 'field_data_field_ref_school';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['field'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'School';
  /* Field: Content: State contact's email address */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['fields']['field_contact_email']['label'] = 'School Contact Email Address';
  /* Field: prc_trt: System check name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  /* Field: Prc_trt: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date & Time System Check Run';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: prc_trt: Number of devices */
  $handler->display->display_options['fields']['field_number_of_devices']['id'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['table'] = 'field_data_field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['field'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['label'] = 'Number of devices ready for assessment';
  $handler->display->display_options['fields']['field_number_of_devices']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Result */
  $handler->display->display_options['fields']['field_result']['id'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['table'] = 'field_data_field_result';
  $handler->display->display_options['fields']['field_result']['field'] = 'field_result';
  /* Field: prc_trt: Device type */
  $handler->display->display_options['fields']['field_device_type']['id'] = 'field_device_type';
  $handler->display->display_options['fields']['field_device_type']['table'] = 'field_data_field_device_type';
  $handler->display->display_options['fields']['field_device_type']['field'] = 'field_device_type';
  /* Field: prc_trt: Operating system */
  $handler->display->display_options['fields']['field_operating_system']['id'] = 'field_operating_system';
  $handler->display->display_options['fields']['field_operating_system']['table'] = 'field_data_field_operating_system';
  $handler->display->display_options['fields']['field_operating_system']['field'] = 'field_operating_system';
  /* Field: Prc_trt: Extrafield Operating system: Results */
  $handler->display->display_options['fields']['operating_system_pass']['id'] = 'operating_system_pass';
  $handler->display->display_options['fields']['operating_system_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['operating_system_pass']['field'] = 'operating_system_pass';
  $handler->display->display_options['fields']['operating_system_pass']['label'] = 'Operating System results';
  $handler->display->display_options['fields']['operating_system_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['operating_system_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['operating_system_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['operating_system_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Monitor size (in inches) */
  $handler->display->display_options['fields']['field_monitor_size']['id'] = 'field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['table'] = 'field_data_field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['field'] = 'field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Monitor size: Results */
  $handler->display->display_options['fields']['monitor_size_pass']['id'] = 'monitor_size_pass';
  $handler->display->display_options['fields']['monitor_size_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['monitor_size_pass']['field'] = 'monitor_size_pass';
  $handler->display->display_options['fields']['monitor_size_pass']['label'] = 'Monitor Size results';
  $handler->display->display_options['fields']['monitor_size_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['monitor_size_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['monitor_size_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['monitor_size_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Monitor color depth */
  $handler->display->display_options['fields']['field_monitor_color_depth']['id'] = 'field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['table'] = 'field_data_field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['field'] = 'field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['empty'] = '-';
  $handler->display->display_options['fields']['field_monitor_color_depth']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Monitor color depth: Results */
  $handler->display->display_options['fields']['monitor_color_depth_pass']['id'] = 'monitor_color_depth_pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['field'] = 'monitor_color_depth_pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['label'] = 'Monitor color depth results';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['monitor_color_depth_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Screen Resolution Width */
  $handler->display->display_options['fields']['field_screen_resolution_width']['id'] = 'field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['table'] = 'field_data_field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['field'] = 'field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_width']['empty'] = '-';
  $handler->display->display_options['fields']['field_screen_resolution_width']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_width']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Screen Resolution Height */
  $handler->display->display_options['fields']['field_screen_resolution_height']['id'] = 'field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['table'] = 'field_data_field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['field'] = 'field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_height']['alter']['text'] = '[field_screen_resolution_width] x [field_screen_resolution_height]';
  $handler->display->display_options['fields']['field_screen_resolution_height']['empty'] = '-';
  $handler->display->display_options['fields']['field_screen_resolution_height']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_height']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Screen resolution: Results */
  $handler->display->display_options['fields']['screen_resolution_pass']['id'] = 'screen_resolution_pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['screen_resolution_pass']['field'] = 'screen_resolution_pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['label'] = 'Screen resolution results';
  $handler->display->display_options['fields']['screen_resolution_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['screen_resolution_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['screen_resolution_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Processor speed */
  $handler->display->display_options['fields']['field_processor_speed']['id'] = 'field_processor_speed';
  $handler->display->display_options['fields']['field_processor_speed']['table'] = 'field_data_field_processor_speed';
  $handler->display->display_options['fields']['field_processor_speed']['field'] = 'field_processor_speed';
  /* Field: Prc_trt: Extrafield Processor speed: Results */
  $handler->display->display_options['fields']['processor_pass']['id'] = 'processor_pass';
  $handler->display->display_options['fields']['processor_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['processor_pass']['field'] = 'processor_pass';
  $handler->display->display_options['fields']['processor_pass']['label'] = 'Processor speed results';
  /* Field: prc_trt: RAM */
  $handler->display->display_options['fields']['field_ram']['id'] = 'field_ram';
  $handler->display->display_options['fields']['field_ram']['table'] = 'field_data_field_ram';
  $handler->display->display_options['fields']['field_ram']['field'] = 'field_ram';
  /* Field: Prc_trt: Extrafield RAM: Results */
  $handler->display->display_options['fields']['ram_pass']['id'] = 'ram_pass';
  $handler->display->display_options['fields']['ram_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['ram_pass']['field'] = 'ram_pass';
  $handler->display->display_options['fields']['ram_pass']['label'] = 'RAM results';
  $handler->display->display_options['fields']['ram_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ram_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['ram_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['ram_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser */
  $handler->display->display_options['fields']['field_browser']['id'] = 'field_browser';
  $handler->display->display_options['fields']['field_browser']['table'] = 'field_data_field_browser';
  $handler->display->display_options['fields']['field_browser']['field'] = 'field_browser';
  $handler->display->display_options['fields']['field_browser']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser Version */
  $handler->display->display_options['fields']['field_browser_version']['id'] = 'field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['table'] = 'field_data_field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['field'] = 'field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_version']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_browser_version']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Browser: Results */
  $handler->display->display_options['fields']['browser_pass']['id'] = 'browser_pass';
  $handler->display->display_options['fields']['browser_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['browser_pass']['field'] = 'browser_pass';
  $handler->display->display_options['fields']['browser_pass']['label'] = 'Browser results';
  /* Field: prc_trt: Browser: Cookies enabled */
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['id'] = 'field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['table'] = 'field_data_field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['field'] = 'field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Cookies: Results */
  $handler->display->display_options['fields']['cookies_pass']['id'] = 'cookies_pass';
  $handler->display->display_options['fields']['cookies_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['cookies_pass']['field'] = 'cookies_pass';
  $handler->display->display_options['fields']['cookies_pass']['label'] = 'Cookies enabled results';
  $handler->display->display_options['fields']['cookies_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['cookies_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['cookies_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['cookies_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: JavaScript enabled */
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['id'] = 'field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['table'] = 'field_data_field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['field'] = 'field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Javascript: Results */
  $handler->display->display_options['fields']['javascript_pass']['id'] = 'javascript_pass';
  $handler->display->display_options['fields']['javascript_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['javascript_pass']['field'] = 'javascript_pass';
  $handler->display->display_options['fields']['javascript_pass']['label'] = 'JavaScript enabled results';
  $handler->display->display_options['fields']['javascript_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['javascript_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['javascript_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['javascript_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: Images enabled */
  $handler->display->display_options['fields']['field_browser_images_enabled']['id'] = 'field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['table'] = 'field_data_field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['field'] = 'field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_images_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Images: Results */
  $handler->display->display_options['fields']['images_pass']['id'] = 'images_pass';
  $handler->display->display_options['fields']['images_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['images_pass']['field'] = 'images_pass';
  $handler->display->display_options['fields']['images_pass']['label'] = 'Images enabled results';
  $handler->display->display_options['fields']['images_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['images_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['images_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['images_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: Java runtime plugin version */
  $handler->display->display_options['fields']['field_jre_version']['id'] = 'field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['table'] = 'field_data_field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['field'] = 'field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['empty'] = '-';
  $handler->display->display_options['fields']['field_jre_version']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Java: Results */
  $handler->display->display_options['fields']['jre_version_pass']['id'] = 'jre_version_pass';
  $handler->display->display_options['fields']['jre_version_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['jre_version_pass']['field'] = 'jre_version_pass';
  $handler->display->display_options['fields']['jre_version_pass']['label'] = 'Java plugin results';
  $handler->display->display_options['fields']['jre_version_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['jre_version_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['jre_version_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['jre_version_pass']['empty_zero'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'trt/system-check/export/school/%';

  /* Display: District Data export */
  $handler = $view->new_display('views_data_export', 'District Data export', 'views_data_export_3');
  $handler->display->display_options['display_description'] = 'Data export by district';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_school_target_id']['id'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['table'] = 'field_data_field_ref_school';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['field'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_district_target_id']['id'] = 'field_ref_district_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['table'] = 'field_data_field_ref_district';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['field'] = 'field_ref_district_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_ref_district_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'District';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'School';
  /* Field: Content: State contact's email address */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['fields']['field_contact_email']['label'] = 'School Contact Email Address';
  /* Field: prc_trt: System check name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = 'System Check Name';
  /* Field: Prc_trt: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date & Time System Check Run';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: prc_trt: Number of devices */
  $handler->display->display_options['fields']['field_number_of_devices']['id'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['table'] = 'field_data_field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['field'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['label'] = 'Number of Devices in system check';
  $handler->display->display_options['fields']['field_number_of_devices']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Result */
  $handler->display->display_options['fields']['field_result']['id'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['table'] = 'field_data_field_result';
  $handler->display->display_options['fields']['field_result']['field'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['label'] = 'System Check Results';
  /* Field: prc_trt: Device type */
  $handler->display->display_options['fields']['field_device_type']['id'] = 'field_device_type';
  $handler->display->display_options['fields']['field_device_type']['table'] = 'field_data_field_device_type';
  $handler->display->display_options['fields']['field_device_type']['field'] = 'field_device_type';
  $handler->display->display_options['fields']['field_device_type']['label'] = 'Device Type';
  /* Field: prc_trt: Operating system */
  $handler->display->display_options['fields']['field_operating_system']['id'] = 'field_operating_system';
  $handler->display->display_options['fields']['field_operating_system']['table'] = 'field_data_field_operating_system';
  $handler->display->display_options['fields']['field_operating_system']['field'] = 'field_operating_system';
  $handler->display->display_options['fields']['field_operating_system']['label'] = 'Operating System name';
  /* Field: Prc_trt: Extrafield Operating system: Results */
  $handler->display->display_options['fields']['operating_system_pass']['id'] = 'operating_system_pass';
  $handler->display->display_options['fields']['operating_system_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['operating_system_pass']['field'] = 'operating_system_pass';
  $handler->display->display_options['fields']['operating_system_pass']['label'] = 'Operating System results';
  $handler->display->display_options['fields']['operating_system_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['operating_system_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['operating_system_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['operating_system_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Monitor size (in inches) */
  $handler->display->display_options['fields']['field_monitor_size']['id'] = 'field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['table'] = 'field_data_field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['field'] = 'field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['label'] = 'Monitor Size';
  $handler->display->display_options['fields']['field_monitor_size']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Monitor size: Results */
  $handler->display->display_options['fields']['monitor_size_pass']['id'] = 'monitor_size_pass';
  $handler->display->display_options['fields']['monitor_size_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['monitor_size_pass']['field'] = 'monitor_size_pass';
  $handler->display->display_options['fields']['monitor_size_pass']['label'] = 'Monitor Size results';
  $handler->display->display_options['fields']['monitor_size_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['monitor_size_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['monitor_size_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['monitor_size_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Monitor color depth */
  $handler->display->display_options['fields']['field_monitor_color_depth']['id'] = 'field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['table'] = 'field_data_field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['field'] = 'field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['empty'] = '-';
  $handler->display->display_options['fields']['field_monitor_color_depth']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Monitor color depth: Results */
  $handler->display->display_options['fields']['monitor_color_depth_pass']['id'] = 'monitor_color_depth_pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['field'] = 'monitor_color_depth_pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['label'] = 'Monitor color depth results';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['monitor_color_depth_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Screen Resolution Width */
  $handler->display->display_options['fields']['field_screen_resolution_width']['id'] = 'field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['table'] = 'field_data_field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['field'] = 'field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_width']['empty'] = '-';
  $handler->display->display_options['fields']['field_screen_resolution_width']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_width']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Screen Resolution Height */
  $handler->display->display_options['fields']['field_screen_resolution_height']['id'] = 'field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['table'] = 'field_data_field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['field'] = 'field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['label'] = 'Screen resolution';
  $handler->display->display_options['fields']['field_screen_resolution_height']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_height']['alter']['text'] = '[field_screen_resolution_width] x [field_screen_resolution_height]';
  $handler->display->display_options['fields']['field_screen_resolution_height']['empty'] = '-';
  $handler->display->display_options['fields']['field_screen_resolution_height']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_height']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Screen resolution: Results */
  $handler->display->display_options['fields']['screen_resolution_pass']['id'] = 'screen_resolution_pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['screen_resolution_pass']['field'] = 'screen_resolution_pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['label'] = 'Screen resolution results';
  $handler->display->display_options['fields']['screen_resolution_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['screen_resolution_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['screen_resolution_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Processor speed */
  $handler->display->display_options['fields']['field_processor_speed']['id'] = 'field_processor_speed';
  $handler->display->display_options['fields']['field_processor_speed']['table'] = 'field_data_field_processor_speed';
  $handler->display->display_options['fields']['field_processor_speed']['field'] = 'field_processor_speed';
  /* Field: Prc_trt: Extrafield Processor speed: Results */
  $handler->display->display_options['fields']['processor_pass']['id'] = 'processor_pass';
  $handler->display->display_options['fields']['processor_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['processor_pass']['field'] = 'processor_pass';
  $handler->display->display_options['fields']['processor_pass']['label'] = 'Processor speed results';
  /* Field: prc_trt: RAM */
  $handler->display->display_options['fields']['field_ram']['id'] = 'field_ram';
  $handler->display->display_options['fields']['field_ram']['table'] = 'field_data_field_ram';
  $handler->display->display_options['fields']['field_ram']['field'] = 'field_ram';
  /* Field: Prc_trt: Extrafield RAM: Results */
  $handler->display->display_options['fields']['ram_pass']['id'] = 'ram_pass';
  $handler->display->display_options['fields']['ram_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['ram_pass']['field'] = 'ram_pass';
  $handler->display->display_options['fields']['ram_pass']['label'] = 'RAM results';
  $handler->display->display_options['fields']['ram_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ram_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['ram_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['ram_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser */
  $handler->display->display_options['fields']['field_browser']['id'] = 'field_browser';
  $handler->display->display_options['fields']['field_browser']['table'] = 'field_data_field_browser';
  $handler->display->display_options['fields']['field_browser']['field'] = 'field_browser';
  $handler->display->display_options['fields']['field_browser']['label'] = 'Browser name';
  $handler->display->display_options['fields']['field_browser']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser Version */
  $handler->display->display_options['fields']['field_browser_version']['id'] = 'field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['table'] = 'field_data_field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['field'] = 'field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_version']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_browser_version']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Browser: Results */
  $handler->display->display_options['fields']['browser_pass']['id'] = 'browser_pass';
  $handler->display->display_options['fields']['browser_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['browser_pass']['field'] = 'browser_pass';
  $handler->display->display_options['fields']['browser_pass']['label'] = 'Browser results';
  /* Field: prc_trt: Browser: Cookies enabled */
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['id'] = 'field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['table'] = 'field_data_field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['field'] = 'field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Cookies: Results */
  $handler->display->display_options['fields']['cookies_pass']['id'] = 'cookies_pass';
  $handler->display->display_options['fields']['cookies_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['cookies_pass']['field'] = 'cookies_pass';
  $handler->display->display_options['fields']['cookies_pass']['label'] = 'Cookies enabled results';
  $handler->display->display_options['fields']['cookies_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['cookies_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['cookies_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['cookies_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: JavaScript enabled */
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['id'] = 'field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['table'] = 'field_data_field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['field'] = 'field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Javascript: Results */
  $handler->display->display_options['fields']['javascript_pass']['id'] = 'javascript_pass';
  $handler->display->display_options['fields']['javascript_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['javascript_pass']['field'] = 'javascript_pass';
  $handler->display->display_options['fields']['javascript_pass']['label'] = 'JavaScript enabled results';
  $handler->display->display_options['fields']['javascript_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['javascript_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['javascript_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['javascript_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: Images enabled */
  $handler->display->display_options['fields']['field_browser_images_enabled']['id'] = 'field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['table'] = 'field_data_field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['field'] = 'field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_images_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Images: Results */
  $handler->display->display_options['fields']['images_pass']['id'] = 'images_pass';
  $handler->display->display_options['fields']['images_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['images_pass']['field'] = 'images_pass';
  $handler->display->display_options['fields']['images_pass']['label'] = 'Images enabled results';
  $handler->display->display_options['fields']['images_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['images_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['images_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['images_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: Java runtime plugin version */
  $handler->display->display_options['fields']['field_jre_version']['id'] = 'field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['table'] = 'field_data_field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['field'] = 'field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['label'] = 'Java plugin version';
  $handler->display->display_options['fields']['field_jre_version']['empty'] = '-';
  $handler->display->display_options['fields']['field_jre_version']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Java: Results */
  $handler->display->display_options['fields']['jre_version_pass']['id'] = 'jre_version_pass';
  $handler->display->display_options['fields']['jre_version_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['jre_version_pass']['field'] = 'jre_version_pass';
  $handler->display->display_options['fields']['jre_version_pass']['label'] = 'Java plugin results';
  $handler->display->display_options['fields']['jre_version_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['jre_version_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['jre_version_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['jre_version_pass']['empty_zero'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_ref_district_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'trt/system-check/export/district/%';

  /* Display: State Data export */
  $handler = $view->new_display('views_data_export', 'State Data export', 'views_data_export_4');
  $handler->display->display_options['display_description'] = 'State export for system checks';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_school_target_id']['id'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['table'] = 'field_data_field_ref_school';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['field'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_school_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_district_target_id']['id'] = 'field_ref_district_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['table'] = 'field_data_field_ref_district';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['field'] = 'field_ref_district_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['relationships']['field_ref_district_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_trt_state_target_id']['id'] = 'field_ref_trt_state_target_id';
  $handler->display->display_options['relationships']['field_ref_trt_state_target_id']['table'] = 'field_data_field_ref_trt_state';
  $handler->display->display_options['relationships']['field_ref_trt_state_target_id']['field'] = 'field_ref_trt_state_target_id';
  $handler->display->display_options['relationships']['field_ref_trt_state_target_id']['relationship'] = 'field_ref_district_target_id';
  $handler->display->display_options['relationships']['field_ref_trt_state_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_ref_district_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'District';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'School';
  /* Field: Content: State contact's email address */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['relationship'] = 'field_ref_school_target_id';
  $handler->display->display_options['fields']['field_contact_email']['label'] = 'School Contact Email Address';
  /* Field: prc_trt: System check name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = 'System Check Name';
  /* Field: Prc_trt: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date & Time System Check Run';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: prc_trt: Number of devices */
  $handler->display->display_options['fields']['field_number_of_devices']['id'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['table'] = 'field_data_field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['field'] = 'field_number_of_devices';
  $handler->display->display_options['fields']['field_number_of_devices']['label'] = 'Number of Devices in system check';
  $handler->display->display_options['fields']['field_number_of_devices']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Result */
  $handler->display->display_options['fields']['field_result']['id'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['table'] = 'field_data_field_result';
  $handler->display->display_options['fields']['field_result']['field'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['label'] = 'System Check Results';
  /* Field: prc_trt: Device type */
  $handler->display->display_options['fields']['field_device_type']['id'] = 'field_device_type';
  $handler->display->display_options['fields']['field_device_type']['table'] = 'field_data_field_device_type';
  $handler->display->display_options['fields']['field_device_type']['field'] = 'field_device_type';
  $handler->display->display_options['fields']['field_device_type']['label'] = 'Device Type';
  /* Field: prc_trt: Operating system */
  $handler->display->display_options['fields']['field_operating_system']['id'] = 'field_operating_system';
  $handler->display->display_options['fields']['field_operating_system']['table'] = 'field_data_field_operating_system';
  $handler->display->display_options['fields']['field_operating_system']['field'] = 'field_operating_system';
  $handler->display->display_options['fields']['field_operating_system']['label'] = 'Operating System name';
  /* Field: Prc_trt: Extrafield Operating system: Results */
  $handler->display->display_options['fields']['operating_system_pass']['id'] = 'operating_system_pass';
  $handler->display->display_options['fields']['operating_system_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['operating_system_pass']['field'] = 'operating_system_pass';
  $handler->display->display_options['fields']['operating_system_pass']['label'] = 'Operating System results';
  $handler->display->display_options['fields']['operating_system_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['operating_system_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['operating_system_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['operating_system_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Monitor size (in inches) */
  $handler->display->display_options['fields']['field_monitor_size']['id'] = 'field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['table'] = 'field_data_field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['field'] = 'field_monitor_size';
  $handler->display->display_options['fields']['field_monitor_size']['label'] = 'Monitor Size';
  $handler->display->display_options['fields']['field_monitor_size']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Monitor size: Results */
  $handler->display->display_options['fields']['monitor_size_pass']['id'] = 'monitor_size_pass';
  $handler->display->display_options['fields']['monitor_size_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['monitor_size_pass']['field'] = 'monitor_size_pass';
  $handler->display->display_options['fields']['monitor_size_pass']['label'] = 'Monitor Size results';
  $handler->display->display_options['fields']['monitor_size_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['monitor_size_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['monitor_size_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['monitor_size_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Monitor color depth */
  $handler->display->display_options['fields']['field_monitor_color_depth']['id'] = 'field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['table'] = 'field_data_field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['field'] = 'field_monitor_color_depth';
  $handler->display->display_options['fields']['field_monitor_color_depth']['empty'] = '-';
  $handler->display->display_options['fields']['field_monitor_color_depth']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Monitor color depth: Results */
  $handler->display->display_options['fields']['monitor_color_depth_pass']['id'] = 'monitor_color_depth_pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['field'] = 'monitor_color_depth_pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['label'] = 'Monitor color depth results';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['monitor_color_depth_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['monitor_color_depth_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Screen Resolution Width */
  $handler->display->display_options['fields']['field_screen_resolution_width']['id'] = 'field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['table'] = 'field_data_field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['field'] = 'field_screen_resolution_width';
  $handler->display->display_options['fields']['field_screen_resolution_width']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_width']['empty'] = '-';
  $handler->display->display_options['fields']['field_screen_resolution_width']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_width']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: prc_trt: Screen Resolution Height */
  $handler->display->display_options['fields']['field_screen_resolution_height']['id'] = 'field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['table'] = 'field_data_field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['field'] = 'field_screen_resolution_height';
  $handler->display->display_options['fields']['field_screen_resolution_height']['label'] = 'Screen resolution';
  $handler->display->display_options['fields']['field_screen_resolution_height']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_height']['alter']['text'] = '[field_screen_resolution_width] x [field_screen_resolution_height]';
  $handler->display->display_options['fields']['field_screen_resolution_height']['empty'] = '-';
  $handler->display->display_options['fields']['field_screen_resolution_height']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_screen_resolution_height']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Screen resolution: Results */
  $handler->display->display_options['fields']['screen_resolution_pass']['id'] = 'screen_resolution_pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['screen_resolution_pass']['field'] = 'screen_resolution_pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['label'] = 'Screen resolution results';
  $handler->display->display_options['fields']['screen_resolution_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['screen_resolution_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['screen_resolution_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['screen_resolution_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Processor speed */
  $handler->display->display_options['fields']['field_processor_speed']['id'] = 'field_processor_speed';
  $handler->display->display_options['fields']['field_processor_speed']['table'] = 'field_data_field_processor_speed';
  $handler->display->display_options['fields']['field_processor_speed']['field'] = 'field_processor_speed';
  /* Field: Prc_trt: Extrafield Processor speed: Results */
  $handler->display->display_options['fields']['processor_pass']['id'] = 'processor_pass';
  $handler->display->display_options['fields']['processor_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['processor_pass']['field'] = 'processor_pass';
  $handler->display->display_options['fields']['processor_pass']['label'] = 'Processor speed results';
  /* Field: prc_trt: RAM */
  $handler->display->display_options['fields']['field_ram']['id'] = 'field_ram';
  $handler->display->display_options['fields']['field_ram']['table'] = 'field_data_field_ram';
  $handler->display->display_options['fields']['field_ram']['field'] = 'field_ram';
  /* Field: Prc_trt: Extrafield RAM: Results */
  $handler->display->display_options['fields']['ram_pass']['id'] = 'ram_pass';
  $handler->display->display_options['fields']['ram_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['ram_pass']['field'] = 'ram_pass';
  $handler->display->display_options['fields']['ram_pass']['label'] = 'RAM results';
  $handler->display->display_options['fields']['ram_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ram_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['ram_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['ram_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser */
  $handler->display->display_options['fields']['field_browser']['id'] = 'field_browser';
  $handler->display->display_options['fields']['field_browser']['table'] = 'field_data_field_browser';
  $handler->display->display_options['fields']['field_browser']['field'] = 'field_browser';
  $handler->display->display_options['fields']['field_browser']['label'] = 'Browser name';
  $handler->display->display_options['fields']['field_browser']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser Version */
  $handler->display->display_options['fields']['field_browser_version']['id'] = 'field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['table'] = 'field_data_field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['field'] = 'field_browser_version';
  $handler->display->display_options['fields']['field_browser_version']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_version']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_browser_version']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Prc_trt: Extrafield Browser: Results */
  $handler->display->display_options['fields']['browser_pass']['id'] = 'browser_pass';
  $handler->display->display_options['fields']['browser_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['browser_pass']['field'] = 'browser_pass';
  $handler->display->display_options['fields']['browser_pass']['label'] = 'Browser results';
  /* Field: prc_trt: Browser: Cookies enabled */
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['id'] = 'field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['table'] = 'field_data_field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['field'] = 'field_browser_cookies_enabled';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_cookies_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Cookies: Results */
  $handler->display->display_options['fields']['cookies_pass']['id'] = 'cookies_pass';
  $handler->display->display_options['fields']['cookies_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['cookies_pass']['field'] = 'cookies_pass';
  $handler->display->display_options['fields']['cookies_pass']['label'] = 'Cookies enabled results';
  $handler->display->display_options['fields']['cookies_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['cookies_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['cookies_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['cookies_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: JavaScript enabled */
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['id'] = 'field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['table'] = 'field_data_field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['field'] = 'field_browser_javascript_enabled';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_javascript_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Javascript: Results */
  $handler->display->display_options['fields']['javascript_pass']['id'] = 'javascript_pass';
  $handler->display->display_options['fields']['javascript_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['javascript_pass']['field'] = 'javascript_pass';
  $handler->display->display_options['fields']['javascript_pass']['label'] = 'JavaScript enabled results';
  $handler->display->display_options['fields']['javascript_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['javascript_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['javascript_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['javascript_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: Images enabled */
  $handler->display->display_options['fields']['field_browser_images_enabled']['id'] = 'field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['table'] = 'field_data_field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['field'] = 'field_browser_images_enabled';
  $handler->display->display_options['fields']['field_browser_images_enabled']['empty'] = '-';
  $handler->display->display_options['fields']['field_browser_images_enabled']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Images: Results */
  $handler->display->display_options['fields']['images_pass']['id'] = 'images_pass';
  $handler->display->display_options['fields']['images_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['images_pass']['field'] = 'images_pass';
  $handler->display->display_options['fields']['images_pass']['label'] = 'Images enabled results';
  $handler->display->display_options['fields']['images_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['images_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['images_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['images_pass']['empty_zero'] = TRUE;
  /* Field: prc_trt: Browser: Java runtime plugin version */
  $handler->display->display_options['fields']['field_jre_version']['id'] = 'field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['table'] = 'field_data_field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['field'] = 'field_jre_version';
  $handler->display->display_options['fields']['field_jre_version']['label'] = 'Java plugin version';
  $handler->display->display_options['fields']['field_jre_version']['empty'] = '-';
  $handler->display->display_options['fields']['field_jre_version']['empty_zero'] = TRUE;
  /* Field: Prc_trt: Extrafield Java: Results */
  $handler->display->display_options['fields']['jre_version_pass']['id'] = 'jre_version_pass';
  $handler->display->display_options['fields']['jre_version_pass']['table'] = 'eck_prc_trt';
  $handler->display->display_options['fields']['jre_version_pass']['field'] = 'jre_version_pass';
  $handler->display->display_options['fields']['jre_version_pass']['label'] = 'Java plugin results';
  $handler->display->display_options['fields']['jre_version_pass']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['jre_version_pass']['alter']['text'] = 'Pass';
  $handler->display->display_options['fields']['jre_version_pass']['empty'] = 'Fail';
  $handler->display->display_options['fields']['jre_version_pass']['empty_zero'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_ref_district_target_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_1']['id'] = 'title_1';
  $handler->display->display_options['sorts']['title_1']['table'] = 'node';
  $handler->display->display_options['sorts']['title_1']['field'] = 'title';
  $handler->display->display_options['sorts']['title_1']['relationship'] = 'field_ref_school_target_id';
  /* Sort criterion: Prc_trt: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'eck_prc_trt';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'trt/system-check/export/state/%';
  $export['trt_system_check_export'] = $view;

  return $export;
}
