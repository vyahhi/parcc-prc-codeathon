<?php
/**
 * @file
 * prc_lti_components.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prc_lti_components_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lti_tool_provider_global_role_array';
  $strongarm->value = array(
    'Learner' => 1,
    'Instructor' => 1,
    'ContentDeveloper' => 1,
    'Member' => 1,
    'Manager' => 1,
    'Mentor' => 1,
    'Administrator' => 1,
    'TeachingAssistant' => 1,
  );
  $export['lti_tool_provider_global_role_array'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lti_tool_provider_user_attribute_mapping';
  $strongarm->value = array(
    'lis_person_name_given' => 'none',
    'lis_person_name_family' => 'none',
    'lis_person_name_full' => 'none',
  );
  $export['lti_tool_provider_user_attribute_mapping'] = $strongarm;

  return $export;
}
