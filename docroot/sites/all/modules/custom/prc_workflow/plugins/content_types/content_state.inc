<?php
/**
 * @file Provide a block to be displayed on node and node edit forms to display
 *   the state of the revision.
 */

$plugin = array(
  'title' => t('Node Workflow State'),
  'content type' => 'prc_workflow_state',
  'render callback' => 'prc_workflow_state_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => array(t('PRC Workflow'), -9),
);

/**
 * Render the block
 *
 * @param $subtype
 * @param $conf
 * @param $args
 * @param $context
 */
function prc_workflow_state_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  $block = new stdClass();
  if (!empty($node->vid)) {

    $state_machine = state_flow_load_state_machine($node);
    // Show state of the revision and not the reported state of the node
    //$reported_state = prc_workflow_reported_state($node->nid); //@todo: remove if this satisfies acs
    $states = $state_machine->get_states_options();
    $label = $states[$state_machine->get_current_state()]['label'];

    $block->content = '<div class="prc-workflow-state"><span>Revision State:</span> ' . ucfirst($label) . '</div>';

    // Provide a link for cancelling a request
    if ($state_machine->get_current_state() == 'ready_for_review') {
      //load the appropriate revision
      $revision = prc_workflow_fetch_latest_node_version_by_state($node->nid, 'ready_for_review');
      $state_machine = state_flow_load_state_machine($revision);

      $event = $state_machine->get_event('rescind_request');
      if ($event->validate()) {
        $url = 'node/' . $node->nid . '/revisions/' . $revision->vid . '/workflow/rescind_request';
        $options = $event->get_options();
        $link = l($options['label'], $url);
        $block->content .= '<div class="prc-workflow-cancel">' . $link . '</div>';
      }
    }

    return $block;
  } else {
    return $block->content = '';
  }
}