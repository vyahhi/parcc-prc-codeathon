<?php

/**
 * @file
 * Contains the basic 'node' field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a node.
 * Definition terms:
 * - link_to_node default: Should this field have the checkbox "link to node" enabled by default.
 *
 * @ingroup views_field_handlers
 */
class prc_workflow_handler_field_node_title extends views_handler_field_node {

  /**
   * Render whatever the data is as a link to the node.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_node']) && !empty($this->additional_fields['nid'])) {
      if ($data !== NULL && $data !== '') {
        $this->options['alter']['make_link'] = TRUE;

        //Link to the preferred revision if one exists, or link to the node
        if(!empty($values->review_vid)){
          $this->options['alter']['path'] = "node/" . $this->get_value($values, 'nid').'/revisions/'.$values->review_vid.'/edit';
        }elseif(!empty($values->draft_vid)){
          $this->options['alter']['path'] = "node/" . $this->get_value($values, 'nid').'/revisions/'.$values->draft_vid.'/edit';
        }else{
          $this->options['alter']['path'] = "node/" . $this->get_value($values, 'nid').'/edit';
        }

        if (isset($this->aliases['language'])) {
          $languages = language_list();
          $language = $this->get_value($values, 'language');
          if (isset($languages[$language])) {
            $this->options['alter']['language'] = $languages[$language];
          }
          else {
            unset($this->options['alter']['language']);
          }
        }
      }
      else {
        $this->options['alter']['make_link'] = FALSE;
      }
    }
    return $data;
  }

  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}
