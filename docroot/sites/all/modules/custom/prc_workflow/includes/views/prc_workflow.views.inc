<?php

/**
 * @file
 * Views customizations for workflows
 */


function prc_workflow_views_data(){

  $data['node_revision_states']['review_link'] = array(
    'real field' => 'nid',
    'field' => array(
      'title' => t('Review Digital Library Content'),
      'help' => t('Provide a simple link to review the content.'),
      'handler' => 'prc_workflow_handler_field_link_review',
    ),
  );
  return $data;
}


/**
 * Implements hook_views_data().
 */
function prc_workflow_views_data_alter(&$data) {

  $data['node_revision_states']['state']['field']['handler'] = 'prc_workflow_handler_field_state';

  //@todo: Realizing that these changes might complicate using them in other spots
  //@todo: Either move these to a prc_views (or prc_access, or...?) module, or define them in the hook_views_data instead and edit the views
  $data['views_entity_node']['edit_node']['field']['handler'] = 'prc_workflow_handler_field_node_link_edit';
  $data['views_entity_node']['delete_node']['field']['handler'] = 'prc_workflow_handler_field_node_link_delete';

}