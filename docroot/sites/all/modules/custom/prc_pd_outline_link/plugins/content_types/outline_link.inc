<?php
/**
 * @file Provide a block to be displayed on node and node edit forms to display
 *   the state of the revision.
 */

$plugin = array(
  'title' => t('Course Outline LInk'),
  'content type' => 'outline_link',
  'render callback' => 'outline_link_render',
  //'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => array(t('PRC Course'), -9),
);

/**
 * Render the block
 *
 * @param $subtype
 * @param $conf
 * @param $args
 * @param $context
 */
function outline_link_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  $block->content = '';

  if($context = course_get_context()){
    $block->content = l('Return to Course Outline', 'node/'.$context->nid.'/outline');
  }

  return $block;
}