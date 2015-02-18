<?php

/**
 * @file
 * Views customizations for workflows
 */

/**
 * Implements hook_views_data().
 */
function prc_workflow_views_data_alter(&$data) {
  $data['node_revision_states']['state']['field']['handler'] = 'prc_workflow_handler_field_state';
}