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

  // Exported permission: 'access all course reports'.
  $permissions['access all course reports'] = array(
    'name' => 'access all course reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'course',
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

  // Exported permission: 'access course'.
  $permissions['access course'] = array(
    'name' => 'access course',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'course',
  );

  // Exported permission: 'access course reports'.
  $permissions['access course reports'] = array(
    'name' => 'access course reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'course',
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

  // Exported permission: 'access lti_tool_provider_consumer entities'.
  $permissions['access lti_tool_provider_consumer entities'] = array(
    'name' => 'access lti_tool_provider_consumer entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'lti_tool_provider',
  );

  // Exported permission: 'access members-only content'.
  $permissions['access members-only content'] = array(
    'name' => 'access members-only content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'Content Contributor' => 'Content Contributor',
      'PARCC-Member Educator' => 'PARCC-Member Educator',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'prc_digital_library_permissions',
  );

  // Exported permission: 'access quiz'.
  $permissions['access quiz'] = array(
    'name' => 'access quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'quiz',
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

  // Exported permission: 'access trt'.
  $permissions['access trt'] = array(
    'name' => 'access trt',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'prc_trt',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add to my lists'.
  $permissions['add to my lists'] = array(
    'name' => 'add to my lists',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'prc_my_lists',
  );

  // Exported permission: 'admin node search exlusions'.
  $permissions['admin node search exlusions'] = array(
    'name' => 'admin node search exlusions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
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

  // Exported permission: 'administer course'.
  $permissions['administer course'] = array(
    'name' => 'administer course',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'course',
  );

  // Exported permission: 'administer elysia_cron'.
  $permissions['administer elysia_cron'] = array(
    'name' => 'administer elysia_cron',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'elysia_cron',
  );

  // Exported permission: 'administer environment indicator settings'.
  $permissions['administer environment indicator settings'] = array(
    'name' => 'administer environment indicator settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
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

  // Exported permission: 'administer js'.
  $permissions['administer js'] = array(
    'name' => 'administer js',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'js',
  );

  // Exported permission: 'administer lti_tool_provider module'.
  $permissions['administer lti_tool_provider module'] = array(
    'name' => 'administer lti_tool_provider module',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'lti_tool_provider',
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

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
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

  // Exported permission: 'administer quiz configuration'.
  $permissions['administer quiz configuration'] = array(
    'name' => 'administer quiz configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
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

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
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

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
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

  // Exported permission: 'create course content'.
  $permissions['create course content'] = array(
    'name' => 'create course content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create digital_library_content content'.
  $permissions['create digital_library_content content'] = array(
    'name' => 'create digital_library_content content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'Content Contributor' => 'Content Contributor',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create favorites_list content'.
  $permissions['create favorites_list content'] = array(
    'name' => 'create favorites_list content',
    'roles' => array(
      'Content Contributor' => 'Content Contributor',
      'Educator' => 'Educator',
      'PARCC-Member Educator' => 'PARCC-Member Educator',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'create multichoice content'.
  $permissions['create multichoice content'] = array(
    'name' => 'create multichoice content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'create pd_course content'.
  $permissions['create pd_course content'] = array(
    'name' => 'create pd_course content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create pd_module content'.
  $permissions['create pd_module content'] = array(
    'name' => 'create pd_module content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create practice_test content'.
  $permissions['create practice_test content'] = array(
    'name' => 'create practice_test content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create quiz content'.
  $permissions['create quiz content'] = array(
    'name' => 'create quiz content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create quiz_directions content'.
  $permissions['create quiz_directions content'] = array(
    'name' => 'create quiz_directions content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create short_answer content'.
  $permissions['create short_answer content'] = array(
    'name' => 'create short_answer content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
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

  // Exported permission: 'delete any course content'.
  $permissions['delete any course content'] = array(
    'name' => 'delete any course content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any digital_library_content content'.
  $permissions['delete any digital_library_content content'] = array(
    'name' => 'delete any digital_library_content content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any favorites_list content'.
  $permissions['delete any favorites_list content'] = array(
    'name' => 'delete any favorites_list content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any multichoice content'.
  $permissions['delete any multichoice content'] = array(
    'name' => 'delete any multichoice content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
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

  // Exported permission: 'delete any pd_course content'.
  $permissions['delete any pd_course content'] = array(
    'name' => 'delete any pd_course content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any pd_module content'.
  $permissions['delete any pd_module content'] = array(
    'name' => 'delete any pd_module content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any practice_test content'.
  $permissions['delete any practice_test content'] = array(
    'name' => 'delete any practice_test content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any quiz content'.
  $permissions['delete any quiz content'] = array(
    'name' => 'delete any quiz content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any quiz results'.
  $permissions['delete any quiz results'] = array(
    'name' => 'delete any quiz results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'delete any quiz_directions content'.
  $permissions['delete any quiz_directions content'] = array(
    'name' => 'delete any quiz_directions content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any short_answer content'.
  $permissions['delete any short_answer content'] = array(
    'name' => 'delete any short_answer content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any test_item content'.
  $permissions['delete any test_item content'] = array(
    'name' => 'delete any test_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own course content'.
  $permissions['delete own course content'] = array(
    'name' => 'delete own course content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own digital_library_content content'.
  $permissions['delete own digital_library_content content'] = array(
    'name' => 'delete own digital_library_content content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'Content Contributor' => 'Content Contributor',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own favorites_list content'.
  $permissions['delete own favorites_list content'] = array(
    'name' => 'delete own favorites_list content',
    'roles' => array(
      'Content Contributor' => 'Content Contributor',
      'Educator' => 'Educator',
      'PARCC-Member Educator' => 'PARCC-Member Educator',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own multichoice content'.
  $permissions['delete own multichoice content'] = array(
    'name' => 'delete own multichoice content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'delete own pd_course content'.
  $permissions['delete own pd_course content'] = array(
    'name' => 'delete own pd_course content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own pd_module content'.
  $permissions['delete own pd_module content'] = array(
    'name' => 'delete own pd_module content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own practice_test content'.
  $permissions['delete own practice_test content'] = array(
    'name' => 'delete own practice_test content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own quiz content'.
  $permissions['delete own quiz content'] = array(
    'name' => 'delete own quiz content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own quiz_directions content'.
  $permissions['delete own quiz_directions content'] = array(
    'name' => 'delete own quiz_directions content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own short_answer content'.
  $permissions['delete own short_answer content'] = array(
    'name' => 'delete own short_answer content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own test_item content'.
  $permissions['delete own test_item content'] = array(
    'name' => 'delete own test_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete results for own quiz'.
  $permissions['delete results for own quiz'] = array(
    'name' => 'delete results for own quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'quiz',
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

  // Exported permission: 'delete terms in member_state'.
  $permissions['delete terms in member_state'] = array(
    'name' => 'delete terms in member_state',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in module_type'.
  $permissions['delete terms in module_type'] = array(
    'name' => 'delete terms in module_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in quiz_type'.
  $permissions['delete terms in quiz_type'] = array(
    'name' => 'delete terms in quiz_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in standard'.
  $permissions['delete terms in standard'] = array(
    'name' => 'delete terms in standard',
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

  // Exported permission: 'edit any course content'.
  $permissions['edit any course content'] = array(
    'name' => 'edit any course content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any digital_library_content content'.
  $permissions['edit any digital_library_content content'] = array(
    'name' => 'edit any digital_library_content content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any favorites_list content'.
  $permissions['edit any favorites_list content'] = array(
    'name' => 'edit any favorites_list content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
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

  // Exported permission: 'edit any multichoice content'.
  $permissions['edit any multichoice content'] = array(
    'name' => 'edit any multichoice content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
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

  // Exported permission: 'edit any pd_course content'.
  $permissions['edit any pd_course content'] = array(
    'name' => 'edit any pd_course content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any pd_module content'.
  $permissions['edit any pd_module content'] = array(
    'name' => 'edit any pd_module content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any practice_test content'.
  $permissions['edit any practice_test content'] = array(
    'name' => 'edit any practice_test content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any quiz content'.
  $permissions['edit any quiz content'] = array(
    'name' => 'edit any quiz content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any quiz_directions content'.
  $permissions['edit any quiz_directions content'] = array(
    'name' => 'edit any quiz_directions content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any short_answer content'.
  $permissions['edit any short_answer content'] = array(
    'name' => 'edit any short_answer content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any test_item content'.
  $permissions['edit any test_item content'] = array(
    'name' => 'edit any test_item content',
    'roles' => array(),
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

  // Exported permission: 'edit own course content'.
  $permissions['edit own course content'] = array(
    'name' => 'edit own course content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own digital_library_content content'.
  $permissions['edit own digital_library_content content'] = array(
    'name' => 'edit own digital_library_content content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'Content Contributor' => 'Content Contributor',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own favorites_list content'.
  $permissions['edit own favorites_list content'] = array(
    'name' => 'edit own favorites_list content',
    'roles' => array(
      'Content Contributor' => 'Content Contributor',
      'Educator' => 'Educator',
      'PARCC-Member Educator' => 'PARCC-Member Educator',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'edit own multichoice content'.
  $permissions['edit own multichoice content'] = array(
    'name' => 'edit own multichoice content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'edit own pd_course content'.
  $permissions['edit own pd_course content'] = array(
    'name' => 'edit own pd_course content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own pd_module content'.
  $permissions['edit own pd_module content'] = array(
    'name' => 'edit own pd_module content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own practice_test content'.
  $permissions['edit own practice_test content'] = array(
    'name' => 'edit own practice_test content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own quiz content'.
  $permissions['edit own quiz content'] = array(
    'name' => 'edit own quiz content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own quiz_directions content'.
  $permissions['edit own quiz_directions content'] = array(
    'name' => 'edit own quiz_directions content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own short_answer content'.
  $permissions['edit own short_answer content'] = array(
    'name' => 'edit own short_answer content',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own test_item content'.
  $permissions['edit own test_item content'] = array(
    'name' => 'edit own test_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit question titles'.
  $permissions['edit question titles'] = array(
    'name' => 'edit question titles',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'quiz',
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

  // Exported permission: 'edit terms in member_state'.
  $permissions['edit terms in member_state'] = array(
    'name' => 'edit terms in member_state',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in module_type'.
  $permissions['edit terms in module_type'] = array(
    'name' => 'edit terms in module_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in quiz_type'.
  $permissions['edit terms in quiz_type'] = array(
    'name' => 'edit terms in quiz_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in standard'.
  $permissions['edit terms in standard'] = array(
    'name' => 'edit terms in standard',
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

  // Exported permission: 'flag like_content'.
  $permissions['flag like_content'] = array(
    'name' => 'flag like_content',
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

  // Exported permission: 'manual quiz revisioning'.
  $permissions['manual quiz revisioning'] = array(
    'name' => 'manual quiz revisioning',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
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

  // Exported permission: 'score any quiz'.
  $permissions['score any quiz'] = array(
    'name' => 'score any quiz',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'score own quiz'.
  $permissions['score own quiz'] = array(
    'name' => 'score own quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'score taken quiz answer'.
  $permissions['score taken quiz answer'] = array(
    'name' => 'score taken quiz answer',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'search all content'.
  $permissions['search all content'] = array(
    'name' => 'search all content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search all excluded entities'.
  $permissions['search all excluded entities'] = array(
    'name' => 'search all excluded entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'search course content'.
  $permissions['search course content'] = array(
    'name' => 'search course content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search digital_library_content content'.
  $permissions['search digital_library_content content'] = array(
    'name' => 'search digital_library_content content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search favorites_list content'.
  $permissions['search favorites_list content'] = array(
    'name' => 'search favorites_list content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search multichoice content'.
  $permissions['search multichoice content'] = array(
    'name' => 'search multichoice content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search panel content'.
  $permissions['search panel content'] = array(
    'name' => 'search panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search pd_course content'.
  $permissions['search pd_course content'] = array(
    'name' => 'search pd_course content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search pd_module content'.
  $permissions['search pd_module content'] = array(
    'name' => 'search pd_module content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search practice_test content'.
  $permissions['search practice_test content'] = array(
    'name' => 'search practice_test content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search quiz content'.
  $permissions['search quiz content'] = array(
    'name' => 'search quiz content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search quiz_directions content'.
  $permissions['search quiz_directions content'] = array(
    'name' => 'search quiz_directions content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search short_answer content'.
  $permissions['search short_answer content'] = array(
    'name' => 'search short_answer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
  );

  // Exported permission: 'search test_item content'.
  $permissions['search test_item content'] = array(
    'name' => 'search test_item content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_config',
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

  // Exported permission: 'unflag like_content'.
  $permissions['unflag like_content'] = array(
    'name' => 'unflag like_content',
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

  // Exported permission: 'use regex for short answer'.
  $permissions['use regex for short answer'] = array(
    'name' => 'use regex for short answer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'short_answer',
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

  // Exported permission: 'view any quiz question correct response'.
  $permissions['view any quiz question correct response'] = array(
    'name' => 'view any quiz question correct response',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'view any quiz results'.
  $permissions['view any quiz results'] = array(
    'name' => 'view any quiz results',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'view lti info'.
  $permissions['view lti info'] = array(
    'name' => 'view lti info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'lti_tool_provider',
  );

  // Exported permission: 'view own quiz results'.
  $permissions['view own quiz results'] = array(
    'name' => 'view own quiz results',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'Content Contributor' => 'Content Contributor',
      'PRC Admin' => 'PRC Admin',
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

  // Exported permission: 'view quiz question outside of a quiz'.
  $permissions['view quiz question outside of a quiz'] = array(
    'name' => 'view quiz question outside of a quiz',
    'roles' => array(
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'quiz',
  );

  // Exported permission: 'view results for own quiz'.
  $permissions['view results for own quiz'] = array(
    'name' => 'view results for own quiz',
    'roles' => array(
      'Content Administrator (Curator)' => 'Content Administrator (Curator)',
      'PRC Admin' => 'PRC Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'quiz',
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
