<?php

function prc_adp_views_data(){
  $data = array();

  $data['views_entity_node']['prc_adp_practice_test_link'] = array(
    'field' => array(
      'title' => t('PRC Practice Test Link'),
      'help' => t('Create a link to launch a practice test.'),
      'handler' => 'views_handler_field_prc_adp_practice_test',
    ),
  );

  return $data;
}
