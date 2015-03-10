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

  $data['views_entity_node']['workflow_edit_node'] = array(
    'field' => array(
      'title' => t('PRC Workflow: Edit link'),
      'help' => t('Provide a simple link to edit the content.'),
      'handler' => 'prc_workflow_handler_field_node_link_edit',
    ),
  );

  $data['views_entity_node']['workflow_delete_node'] = array(
    'field' => array(
      'title' => t('PRC Workflow: Delete link'),
      'help' => t('Provide a simple link to delete the content.'),
      'handler' => 'prc_workflow_handler_field_node_link_delete',
    ),
  );

  $data['node']['prc_workflow_title'] = array(
    'title' => t('PRC Workflow: Title'), // The item it appears as on the UI,
    'help' => t('The content title of the preferred revision.'), // The help that appears on the UI,
    // Information for displaying a title as a field
    'field' => array(
      'field' => 'title', // the real field. This could be left out since it is the same.
      'group' => t('Content'), // The group it appears in on the UI. Could be left out.
      'handler' => 'prc_workflow_handler_field_node_title',
      'click sortable' => TRUE,
      'link_to_node default' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    // Information for accepting a title as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data().
 */
function prc_workflow_views_data_alter(&$data) {
  $data['node_revision_states']['state']['field']['handler'] = 'prc_workflow_handler_field_state';
}

/**
 * Implements hook_views_pre_execute()
 *
 * @param $view
 */
function prc_workflow_views_pre_execute(&$view){
  if($view->name == 'admin_content_view'){
    //Add columns to the view for a draft_vid and review_vid so we can link to them
    $query = $view->build_info['query'];

    //Add fields for review and draft states
    //Join two subqueries that create a view of the most recent drafts and most recent reviews for each node
    $review_sub = db_select('node_revision_states');
    $review_sub->addExpression('node_revision.vid, node_revision.nid, node_revision.title, node_revision.timestamp, max(node_revision_states.timestamp)');
    $review_sub->condition('node_revision_states.status', 1);
    $review_sub->groupBy('nid');
    $review_sub->leftJoin('node_revision', NULL, 'node_revision_states.vid = node_revision.vid');

    $draft_sub = clone $review_sub;
    $review_sub->condition('state', 'ready_for_review');
    $draft_sub->condition('state', 'draft');

    $review_on = 'node.nid = nrs_review.nid';
    $draft_on = 'node.nid = nrs_draft.nid';

    $query->addJoin('LEFT', $review_sub, 'nrs_review', $review_on);
    $query->addJoin('LEFT', $draft_sub, 'nrs_draft', $draft_on);

    $query->addField('nrs_review', 'vid', 'review_vid');
    $query->addField('nrs_review', 'title', 'review_title');
    $query->addField('nrs_review', 'timestamp', 'review_updated');

    $query->addField('nrs_draft', 'vid', 'draft_vid');
    $query->addField('nrs_draft', 'title', 'draft_title');
    $query->addField('nrs_draft', 'timestamp', 'draft_updated');

    $view->build_info['query'] = $query;
    
  }
}

/**
 * Implements hook_views_post_execute()
 *
 * @param $view
 */
function prc_workflow_views_post_execute(&$view){
  if($view->name == 'admin_content_view') {
    //Swap out the titles and date updated to match the draft we are linking to
    foreach($view->result as &$result){
      if($result->review_vid){
        $result->node_title = $result->review_title;
        $result->node_changed = $result->review_updated;
      }elseif($result->draft_vid){
        $result->node_title = $result->draft_title;
        $result->node_changed = $result->draft_updated;
      }
    }
  }
}