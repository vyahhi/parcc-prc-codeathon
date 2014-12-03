<?php

/**
 * @file
 * Views handler for providing a count of the course objects in the current course.
 */
class prc_course_views_views_handler_field_node_course_object_count extends views_handler_field {

  public function render($values) {
    $nid = $this->get_value($values);
    $node = node_load($nid);
    $course = course_get_course($node);
    // And it's okay even if this isn't a Course - it'll come back 0
    $num_objects = count($course->getObjects());
    return $num_objects;
  }
}