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
function prc_workflow_state_render($subtype, $conf, $args, $context){
  $node = $context->data;
  $block = new stdClass();

  $state_machine = state_flow_load_state_machine($node);

  $current_state = $state_machine->get_current_state();

  $block->content = '<div class="prc-workflow-state"><span>Content State:</span> '.ucfirst($current_state).'</div>';

  return $block;
}