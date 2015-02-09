<?php
/**
 * @file
 * prc_poc_local_eck_ccss.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function prc_poc_local_eck_ccss_eck_bundle_info() {
  $items = array(
    'ccss_ccss_cluster' => array(
      'machine_name' => 'ccss_ccss_cluster',
      'entity_type' => 'ccss',
      'name' => 'ccss_cluster',
      'label' => 'CCSS Cluster',
    ),
    'ccss_ccss_domain' => array(
      'machine_name' => 'ccss_ccss_domain',
      'entity_type' => 'ccss',
      'name' => 'ccss_domain',
      'label' => 'CCSS Domain',
    ),
    'ccss_ccss_standard' => array(
      'machine_name' => 'ccss_ccss_standard',
      'entity_type' => 'ccss',
      'name' => 'ccss_standard',
      'label' => 'CCSS Standard',
    ),
    'ccss_ccss_superdomain' => array(
      'machine_name' => 'ccss_ccss_superdomain',
      'entity_type' => 'ccss',
      'name' => 'ccss_superdomain',
      'label' => 'CCSS Superdomain',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function prc_poc_local_eck_ccss_eck_entity_type_info() {
  $items = array(
    'ccss' => array(
      'name' => 'ccss',
      'label' => 'ccss',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'language' => array(
          'label' => 'Entity language',
          'type' => 'language',
          'behavior' => 'language',
        ),
      ),
    ),
  );
  return $items;
}
