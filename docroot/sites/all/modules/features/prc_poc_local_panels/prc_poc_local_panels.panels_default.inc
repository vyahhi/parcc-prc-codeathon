<?php
/**
 * @file
 * prc_poc_local_panels.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function prc_poc_local_panels_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'digital_library_placeholder';
  $mini->category = 'prc';
  $mini->admin_title = 'Digital Library Placeholder';
  $mini->admin_description = 'Temporary Placeholder for Digital Library';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'bd6182c2-3816-40bc-b829-fab2e567ab2b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-22c6a895-09c6-44e4-9d00-66284c30c084';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Placeholder Indicator Text',
      'title' => 'Placeholder',
      'body' => 'This area is just a placeholder.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '22c6a895-09c6-44e4-9d00-66284c30c084';
    $display->content['new-22c6a895-09c6-44e4-9d00-66284c30c084'] = $pane;
    $display->panels['middle'][0] = 'new-22c6a895-09c6-44e4-9d00-66284c30c084';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-22c6a895-09c6-44e4-9d00-66284c30c084';
  $mini->display = $display;
  $export['digital_library_placeholder'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'slideshow_placeholder';
  $mini->category = 'prc';
  $mini->admin_title = 'Slideshow Placeholder';
  $mini->admin_description = 'Slideshow Placeholder';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e287be1c-bec8-4a76-907b-36814ace1d0e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8232da0b-384b-41a5-a139-b835b90f1589';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Slideshow Placeholder Text',
      'title' => 'Slideshow',
      'body' => 'Placeholder for the slideshow.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8232da0b-384b-41a5-a139-b835b90f1589';
    $display->content['new-8232da0b-384b-41a5-a139-b835b90f1589'] = $pane;
    $display->panels['middle'][0] = 'new-8232da0b-384b-41a5-a139-b835b90f1589';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8232da0b-384b-41a5-a139-b835b90f1589';
  $mini->display = $display;
  $export['slideshow_placeholder'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'user_welcome_message';
  $mini->category = 'prc';
  $mini->admin_title = 'User Welcome Message';
  $mini->admin_description = '';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'User',
      'keyword' => 'user',
      'name' => 'user',
      'type' => 'select',
      'uid' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'bc5a11f8-1a3c-4b09-b0cc-1ef53499e6b1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6de4881f-b569-41e3-8892-fd15ac166afb';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Welcome user message',
      'title' => '',
      'body' => 'Welcome, %user:field_first_name %user:field_last_name',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6de4881f-b569-41e3-8892-fd15ac166afb';
    $display->content['new-6de4881f-b569-41e3-8892-fd15ac166afb'] = $pane;
    $display->panels['middle'][0] = 'new-6de4881f-b569-41e3-8892-fd15ac166afb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['user_welcome_message'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'welcome_anonymous';
  $mini->category = 'prc';
  $mini->admin_title = 'Welcome Anonymous';
  $mini->admin_description = 'Welcome description with join link';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Welcome!';
  $display->uuid = '417e1730-423d-4147-87a3-ea107b606bff';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-dfef94fa-f7b8-4af1-9899-b285873548b8';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Welcome Anonymous Text',
      'title' => '',
      'body' => 'Join the discussions. Share tips and experiences. Connect with educators from all around the world.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'dfef94fa-f7b8-4af1-9899-b285873548b8';
    $display->content['new-dfef94fa-f7b8-4af1-9899-b285873548b8'] = $pane;
    $display->panels['middle'][0] = 'new-dfef94fa-f7b8-4af1-9899-b285873548b8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['welcome_anonymous'] = $mini;

  return $export;
}
