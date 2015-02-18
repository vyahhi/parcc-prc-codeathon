<?php

/**
 * @file
 * Views filter handler for the State Flow state.
 */
class prc_workflow_handler_field_state extends views_handler_field {
  function pre_render(&$values){
    //Use the label instead of the raw value
    $states = prc_workflow_get_all_states();
    foreach($values as &$value){
      $value->{$this->field_alias} = $states[$value->{$this->field_alias}]['label'];
    }
  }

}
