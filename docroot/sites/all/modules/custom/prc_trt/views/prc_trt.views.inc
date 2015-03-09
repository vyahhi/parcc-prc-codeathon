<?php

/**
 * @file
 * PARCC PRC TRT Views Handlers integration code.
 */

/**
 * Implements hook_views_data_alter().
 */
function prc_trt_views_data_alter(&$data) {
  $data['eck_prc_trt']['view_overall_result'] = array(
    'real field' => 'id',
    'field' => array(
      'title' => t('Results'),
      'help' => t('The overall results of the system check.'),
      'handler' => 'prc_trt_views_handler_system_check_result',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
}
