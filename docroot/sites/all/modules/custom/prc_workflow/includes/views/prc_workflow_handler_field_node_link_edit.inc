<?php

/**
 * @file
 * Definition of views_handler_field_node_link_edit.
 */

/**
 * Field handler to present a link node edit.
 *
 * @ingroup views_field_handlers
 */
class prc_workflow_handler_field_node_link_edit extends views_handler_field_node_link {

  /**
   * Renders the link.
   */
  function render_link($node, $values) {
    // Ensure user has access to edit this node.
    if(($node->type == 'digital_library_content' && !prc_workflow_access('update', $node)) || !node_access('update', $node)) {
        return;
    }

    //Use the added fields from prc_workflow_views_pre_execute() to build an edit
    //link to the revision we want.  Prefer the review revision if one exists.
    if(!empty($values->review_vid)){
      $vid = $values->review_vid;
    }elseif(!empty($values->draft_vid)){
      $vid = $values->draft_vid;
    }

    $this->options['alter']['make_link'] = TRUE;
    if(isset($vid)){
      $this->options['alter']['path'] = "node/$node->nid/revisions/$vid/edit";
    }else {
      $this->options['alter']['path'] = "node/$node->nid/edit";
    }
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    return $text;
  }
}
