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
  if(!empty($node->vid)) {

    $state_machine = state_flow_load_state_machine($node);

    $current_state = $state_machine->get_current_state();
    $label = $state_machine->get_label_for_current_state();

    $block->content = '<div class="prc-workflow-state"><span>Content State:</span> ' . ucfirst($label) . '</div>';

    //Provide a link for cancelling a request
    if ($current_state == 'ready_for_review') {
      $event = $state_machine->get_event('rescind_request');
      if ($event->validate()) {
        //@todo: do we need to figure out the vid of the page they are currently viewing?
        $url = 'node/' . $node->nid . '/revisions/' . $node->vid . '/workflow/rescind_request';
        $options = $event->get_options();
        $link = l($options['label'], $url);
        $block->content .= '<div class="prc-workflow-cancel">' . $link . '</div>';
      }
    }

    return $block;
  }else{
    return $block->content = '';
  }
}