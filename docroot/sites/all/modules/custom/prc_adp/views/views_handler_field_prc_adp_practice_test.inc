<?php

class views_handler_field_prc_adp_practice_test extends views_handler_field_node_link{
  function render_link($node, $values){
    if(prc_adp_is_adp_test($node)) {
      $data['node'] = $node;
      return theme('test_launch_form_link', $data);
    }else{
      return '';
    }
  }
}
