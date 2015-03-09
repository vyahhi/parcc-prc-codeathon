<?php

/**
 * @file
 * Views handler for providing a count of the course objects in the current course.
 */
class prc_trt_views_handler_system_check_result extends views_handler_field {

  public function render($values) {
    $entity = $values->_field_data['id']['entity'];
    $result = _prc_trt_field_overall_results($entity);
    return $result ? 'Pass' : 'Fail';
  }
}