<?php
/**
 * @file
 * prc_poc_local_users.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function prc_poc_local_users_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access environment indicator'.
  $permissions['access environment indicator'] = array(
    'name' => 'access environment indicator',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator default_environment'.
  $permissions['access environment indicator default_environment'] = array(
    'name' => 'access environment indicator default_environment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator overwritten_environment'.
  $permissions['access environment indicator overwritten_environment'] = array(
    'name' => 'access environment indicator overwritten_environment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'admin_classes'.
  $permissions['admin_classes'] = array(
    'name' => 'admin_classes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'admin_fields'.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_view_modes'.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer environment indicator settings'.
  $permissions['administer environment indicator settings'] = array(
    'name' => 'administer environment indicator settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer invitations'.
  $permissions['administer invitations'] = array(
    'name' => 'administer invitations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'administer invite types'.
  $permissions['administer invite types'] = array(
    'name' => 'administer invite types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mailsystem',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu_token'.
  $permissions['administer menu_token'] = array(
    'name' => 'administer menu_token',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_token',
  );

  // Exported permission: 'administer mini panels'.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panel-nodes'.
  $permissions['administer panel-nodes'] = array(
    'name' => 'administer panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer realname'.
  $permissions['administer realname'] = array(
    'name' => 'administer realname',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'realname',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer sharethis'.
  $permissions['administer sharethis'] = array(
    'name' => 'administer sharethis',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'sharethis',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer smtp module'.
  $permissions['administer smtp module'] = array(
    'name' => 'administer smtp module',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'smtp',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer voting api'.
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'votingapi',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create any invite entities'.
  $permissions['create any invite entities'] = array(
    'name' => 'create any invite entities',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create digital_library_content content'.
  $permissions['create digital_library_content content'] = array(
    'name' => 'create digital_library_content content',
    'roles' => array(
      'Content Author' => 'Content Author',
      'PRC Admin' => 'PRC Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create favorites_list content'.
  $permissions['create favorites_list content'] = array(
    'name' => 'create favorites_list content',
    'roles' => array(
      'Content Author' => 'Content Author',
      'Educator' => 'Educator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create invite_by_email entity'.
  $permissions['create invite_by_email entity'] = array(
    'name' => 'create invite_by_email entity',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'create mini panels'.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create panel content'.
  $permissions['create panel content'] = array(
    'name' => 'create panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create panel-nodes'.
  $permissions['create panel-nodes'] = array(
    'name' => 'create panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'create practice_test content'.
  $permissions['create practice_test content'] = array(
    'name' => 'create practice_test content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create test_item content'.
  $permissions['create test_item content'] = array(
    'name' => 'create test_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any digital_library_content content'.
  $permissions['delete any digital_library_content content'] = array(
    'name' => 'delete any digital_library_content content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any favorites_list content'.
  $permissions['delete any favorites_list content'] = array(
    'name' => 'delete any favorites_list content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any panel content'.
  $permissions['delete any panel content'] = array(
    'name' => 'delete any panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any panel-nodes'.
  $permissions['delete any panel-nodes'] = array(
    'name' => 'delete any panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'delete any practice_test content'.
  $permissions['delete any practice_test content'] = array(
    'name' => 'delete any practice_test content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any test_item content'.
  $permissions['delete any test_item content'] = array(
    'name' => 'delete any test_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own digital_library_content content'.
  $permissions['delete own digital_library_content content'] = array(
    'name' => 'delete own digital_library_content content',
    'roles' => array(
      'Content Author' => 'Content Author',
      'PRC Admin' => 'PRC Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own favorites_list content'.
  $permissions['delete own favorites_list content'] = array(
    'name' => 'delete own favorites_list content',
    'roles' => array(
      'Content Author' => 'Content Author',
      'Educator' => 'Educator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own panel content'.
  $permissions['delete own panel content'] = array(
    'name' => 'delete own panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own panel-nodes'.
  $permissions['delete own panel-nodes'] = array(
    'name' => 'delete own panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'delete own practice_test content'.
  $permissions['delete own practice_test content'] = array(
    'name' => 'delete own practice_test content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own test_item content'.
  $permissions['delete own test_item content'] = array(
    'name' => 'delete own test_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in ccss_grade'.
  $permissions['delete terms in ccss_grade'] = array(
    'name' => 'delete terms in ccss_grade',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in genre'.
  $permissions['delete terms in genre'] = array(
    'name' => 'delete terms in genre',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in grade_level'.
  $permissions['delete terms in grade_level'] = array(
    'name' => 'delete terms in grade_level',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in hierarchy'.
  $permissions['delete terms in hierarchy'] = array(
    'name' => 'delete terms in hierarchy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in media_type'.
  $permissions['delete terms in media_type'] = array(
    'name' => 'delete terms in media_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in subject'.
  $permissions['delete terms in subject'] = array(
    'name' => 'delete terms in subject',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'eck add bundles'.
  $permissions['eck add bundles'] = array(
    'name' => 'eck add bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add ccss bundles'.
  $permissions['eck add ccss bundles'] = array(
    'name' => 'eck add ccss bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add ccss ccss_cluster entities'.
  $permissions['eck add ccss ccss_cluster entities'] = array(
    'name' => 'eck add ccss ccss_cluster entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add ccss ccss_domain entities'.
  $permissions['eck add ccss ccss_domain entities'] = array(
    'name' => 'eck add ccss ccss_domain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add ccss ccss_standard entities'.
  $permissions['eck add ccss ccss_standard entities'] = array(
    'name' => 'eck add ccss ccss_standard entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add ccss ccss_superdomain entities'.
  $permissions['eck add ccss ccss_superdomain entities'] = array(
    'name' => 'eck add ccss ccss_superdomain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add entities'.
  $permissions['eck add entities'] = array(
    'name' => 'eck add entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add entity types'.
  $permissions['eck add entity types'] = array(
    'name' => 'eck add entity types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer bundles'.
  $permissions['eck administer bundles'] = array(
    'name' => 'eck administer bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer ccss bundles'.
  $permissions['eck administer ccss bundles'] = array(
    'name' => 'eck administer ccss bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer ccss ccss_cluster entities'.
  $permissions['eck administer ccss ccss_cluster entities'] = array(
    'name' => 'eck administer ccss ccss_cluster entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer ccss ccss_domain entities'.
  $permissions['eck administer ccss ccss_domain entities'] = array(
    'name' => 'eck administer ccss ccss_domain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer ccss ccss_standard entities'.
  $permissions['eck administer ccss ccss_standard entities'] = array(
    'name' => 'eck administer ccss ccss_standard entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer ccss ccss_superdomain entities'.
  $permissions['eck administer ccss ccss_superdomain entities'] = array(
    'name' => 'eck administer ccss ccss_superdomain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer entities'.
  $permissions['eck administer entities'] = array(
    'name' => 'eck administer entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer entity types'.
  $permissions['eck administer entity types'] = array(
    'name' => 'eck administer entity types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete bundles'.
  $permissions['eck delete bundles'] = array(
    'name' => 'eck delete bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete ccss bundles'.
  $permissions['eck delete ccss bundles'] = array(
    'name' => 'eck delete ccss bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete ccss ccss_cluster entities'.
  $permissions['eck delete ccss ccss_cluster entities'] = array(
    'name' => 'eck delete ccss ccss_cluster entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete ccss ccss_domain entities'.
  $permissions['eck delete ccss ccss_domain entities'] = array(
    'name' => 'eck delete ccss ccss_domain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete ccss ccss_standard entities'.
  $permissions['eck delete ccss ccss_standard entities'] = array(
    'name' => 'eck delete ccss ccss_standard entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete ccss ccss_superdomain entities'.
  $permissions['eck delete ccss ccss_superdomain entities'] = array(
    'name' => 'eck delete ccss ccss_superdomain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete entities'.
  $permissions['eck delete entities'] = array(
    'name' => 'eck delete entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete entity types'.
  $permissions['eck delete entity types'] = array(
    'name' => 'eck delete entity types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit bundles'.
  $permissions['eck edit bundles'] = array(
    'name' => 'eck edit bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit ccss bundles'.
  $permissions['eck edit ccss bundles'] = array(
    'name' => 'eck edit ccss bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit ccss ccss_cluster entities'.
  $permissions['eck edit ccss ccss_cluster entities'] = array(
    'name' => 'eck edit ccss ccss_cluster entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit ccss ccss_domain entities'.
  $permissions['eck edit ccss ccss_domain entities'] = array(
    'name' => 'eck edit ccss ccss_domain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit ccss ccss_standard entities'.
  $permissions['eck edit ccss ccss_standard entities'] = array(
    'name' => 'eck edit ccss ccss_standard entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit ccss ccss_superdomain entities'.
  $permissions['eck edit ccss ccss_superdomain entities'] = array(
    'name' => 'eck edit ccss ccss_superdomain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit entities'.
  $permissions['eck edit entities'] = array(
    'name' => 'eck edit entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit entity types'.
  $permissions['eck edit entity types'] = array(
    'name' => 'eck edit entity types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list bundles'.
  $permissions['eck list bundles'] = array(
    'name' => 'eck list bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list ccss bundles'.
  $permissions['eck list ccss bundles'] = array(
    'name' => 'eck list ccss bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list ccss ccss_cluster entities'.
  $permissions['eck list ccss ccss_cluster entities'] = array(
    'name' => 'eck list ccss ccss_cluster entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list ccss ccss_domain entities'.
  $permissions['eck list ccss ccss_domain entities'] = array(
    'name' => 'eck list ccss ccss_domain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list ccss ccss_standard entities'.
  $permissions['eck list ccss ccss_standard entities'] = array(
    'name' => 'eck list ccss ccss_standard entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list ccss ccss_superdomain entities'.
  $permissions['eck list ccss ccss_superdomain entities'] = array(
    'name' => 'eck list ccss ccss_superdomain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list entities'.
  $permissions['eck list entities'] = array(
    'name' => 'eck list entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list entity types'.
  $permissions['eck list entity types'] = array(
    'name' => 'eck list entity types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view ccss bundles'.
  $permissions['eck view ccss bundles'] = array(
    'name' => 'eck view ccss bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view ccss ccss_cluster entities'.
  $permissions['eck view ccss ccss_cluster entities'] = array(
    'name' => 'eck view ccss ccss_cluster entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view ccss ccss_domain entities'.
  $permissions['eck view ccss ccss_domain entities'] = array(
    'name' => 'eck view ccss ccss_domain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view ccss ccss_standard entities'.
  $permissions['eck view ccss ccss_standard entities'] = array(
    'name' => 'eck view ccss ccss_standard entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view ccss ccss_superdomain entities'.
  $permissions['eck view ccss ccss_superdomain entities'] = array(
    'name' => 'eck view ccss ccss_superdomain entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view entities'.
  $permissions['eck view entities'] = array(
    'name' => 'eck view entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any digital_library_content content'.
  $permissions['edit any digital_library_content content'] = array(
    'name' => 'edit any digital_library_content content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any favorites_list content'.
  $permissions['edit any favorites_list content'] = array(
    'name' => 'edit any favorites_list content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any invite entities'.
  $permissions['edit any invite entities'] = array(
    'name' => 'edit any invite entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any panel content'.
  $permissions['edit any panel content'] = array(
    'name' => 'edit any panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any panel-nodes'.
  $permissions['edit any panel-nodes'] = array(
    'name' => 'edit any panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'edit any practice_test content'.
  $permissions['edit any practice_test content'] = array(
    'name' => 'edit any practice_test content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any test_item content'.
  $permissions['edit any test_item content'] = array(
    'name' => 'edit any test_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own digital_library_content content'.
  $permissions['edit own digital_library_content content'] = array(
    'name' => 'edit own digital_library_content content',
    'roles' => array(
      'Content Author' => 'Content Author',
      'PRC Admin' => 'PRC Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own favorites_list content'.
  $permissions['edit own favorites_list content'] = array(
    'name' => 'edit own favorites_list content',
    'roles' => array(
      'Content Author' => 'Content Author',
      'Educator' => 'Educator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own invite entities'.
  $permissions['edit own invite entities'] = array(
    'name' => 'edit own invite entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own panel content'.
  $permissions['edit own panel content'] = array(
    'name' => 'edit own panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own panel-nodes'.
  $permissions['edit own panel-nodes'] = array(
    'name' => 'edit own panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'edit own practice_test content'.
  $permissions['edit own practice_test content'] = array(
    'name' => 'edit own practice_test content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own test_item content'.
  $permissions['edit own test_item content'] = array(
    'name' => 'edit own test_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in ccss_grade'.
  $permissions['edit terms in ccss_grade'] = array(
    'name' => 'edit terms in ccss_grade',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in genre'.
  $permissions['edit terms in genre'] = array(
    'name' => 'edit terms in genre',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in grade_level'.
  $permissions['edit terms in grade_level'] = array(
    'name' => 'edit terms in grade_level',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in hierarchy'.
  $permissions['edit terms in hierarchy'] = array(
    'name' => 'edit terms in hierarchy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in media_type'.
  $permissions['edit terms in media_type'] = array(
    'name' => 'edit terms in media_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in subject'.
  $permissions['edit terms in subject'] = array(
    'name' => 'edit terms in subject',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'export taxonomy by csv'.
  $permissions['export taxonomy by csv'] = array(
    'name' => 'export taxonomy by csv',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_csv',
  );

  // Exported permission: 'flag bookmarks'.
  $permissions['flag bookmarks'] = array(
    'name' => 'flag bookmarks',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'import taxonomy by csv'.
  $permissions['import taxonomy by csv'] = array(
    'name' => 'import taxonomy by csv',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_csv',
  );

  // Exported permission: 'manage ccss properties'.
  $permissions['manage ccss properties'] = array(
    'name' => 'manage ccss properties',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fivestar',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'unflag bookmarks'.
  $permissions['unflag bookmarks'] = array(
    'name' => 'unflag bookmarks',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view any invite entities'.
  $permissions['view any invite entities'] = array(
    'name' => 'view any invite entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'withdraw own accepted invitations'.
  $permissions['withdraw own accepted invitations'] = array(
    'name' => 'withdraw own accepted invitations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'withdraw own invitations'.
  $permissions['withdraw own invitations'] = array(
    'name' => 'withdraw own invitations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'invite',
  );

  return $permissions;
}
