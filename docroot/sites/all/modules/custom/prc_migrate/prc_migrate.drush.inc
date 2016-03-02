<?php

/**
 * Implements hook_drush_command()
 *
 * @return mixed
 */
function prc_migrate_drush_command() {
  $items['prc-fix-tax-refs'] = array(
    'description' => 'Fix references to terms in fields, views, etc',
    'aliases' => array('pftr')
  );

  return $items;
}

/**
 * Drush command to fix references in fields and views
 */
function drush_prc_migrate_prc_fix_tax_refs() {
  // Get the term and vocab info
  $custom = array_pop(taxonomy_get_term_by_name('Custom Assessment', 'quiz_type'));
  $parcc = array_pop(taxonomy_get_term_by_name('PARCC-Released Practice Assessment', 'quiz_type'));

  // Fix tid references for the assessment view
  $values = array(
    $custom->tid => $custom->tid,
    $parcc->tid => $parcc->tid
  );

  $view = views_get_view('assessments', TRUE);
  $view->display['default']->display_options['filters']['tid']['value'] = $values;
  views_save_view($view);

  // Fix tid references for the default assessment type
  $instance = field_info_instance('node', 'field_quiz_type', 'quiz');
  $instance['default_value'][0]['tid'] = $custom->tid;
  field_update_instance($instance);

  drush_print('Taxonomy references in PRC features have been re-pointed.');
}