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
class prc_workflow_handler_field_link_review extends views_handler_field_node_link {

  /**
   * Renders the link.
   */
  function render_link($node, $values) {
    if (!user_access('approve prc content')) {
      return;
    }

    $pending_review = db_query("
        select vid from node_revision_states
        where nid = :nid and status = 1 and state = 'ready_for_review'",
      array(':nid' => $node->nid))->fetchField();
    $text = '';
    if($pending_review) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "node/$node->nid/revisions/$pending_review/edit";
      $this->options['alter']['query'] = drupal_get_destination();

      $text = !empty($this->options['text']) ? $this->options['text'] : t('pending review');
    }
    return $text;
  }
}
