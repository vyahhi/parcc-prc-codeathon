; prc make file for d.o. usage
core = "7.x"
api = "2"

; +++++ Modules +++++

projects[admin_menu][version] = "3.0-rc5"
projects[admin_menu][subdir] = "contrib"

projects[module_filter][version] = "2.0-alpha2"
projects[module_filter][subdir] = "contrib"

projects[ctools][version] = "1.6"
projects[ctools][subdir] = "contrib"

projects[course][version] = "1.4"
projects[course][subdir] = "contrib"

projects[course][version] = "1.4"
projects[course][subdir] = "contrib"

projects[devel][version] = "1.5"
projects[devel][subdir] = "contrib"

projects[profiler_builder][version] = "1.2"
projects[profiler_builder][subdir] = "contrib"

projects[ds][version] = "2.7"
projects[ds][subdir] = "contrib"

projects[eck][version] = "2.0-rc7"
projects[eck][subdir] = "contrib"

projects[features][version] = "2.3"
projects[features][subdir] = "contrib"

projects[features_builder][version] = "1.x-dev"
projects[features_builder][subdir] = "contrib"

projects[uuid_features][version] = "1.0-alpha4"
projects[uuid_features][subdir] = "contrib"

projects[entityreference][version] = "1.1"
projects[entityreference][subdir] = "contrib"

projects[field_group][version] = "1.4"
projects[field_group][subdir] = "contrib"

projects[link][version] = "1.3"
projects[link][subdir] = "contrib"

projects[flag][version] = "3.5"
projects[flag][subdir] = "contrib"

projects[invite][version] = "4.0-beta2"
projects[invite][subdir] = "contrib"

projects[lti_tool_provider][version] = "1.x-dev"
projects[lti_tool_provider][subdir] = "contrib"

projects[mailsystem][version] = "2.34"
projects[mailsystem][subdir] = "contrib"

projects[smtp][version] = "1.2"
projects[smtp][subdir] = "contrib"

projects[message][version] = "1.9"
projects[message][subdir] = "contrib"

projects[message_notify][version] = "2.5"
projects[message_notify][subdir] = "contrib"

projects[message_subscribe][version] = "1.0-rc2"
projects[message_subscribe][subdir] = "contrib"

projects[migrate][version] = "2.6"
projects[migrate][subdir] = "contrib"

projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

projects[elysia_cron][version] = "2.1"
projects[elysia_cron][subdir] = "contrib"

projects[email_registration][version] = "1.2"
projects[email_registration][subdir] = "contrib"

projects[entity][version] = "1.5"
projects[entity][subdir] = "contrib"

projects[environment_indicator][version] = "2.5"
projects[environment_indicator][subdir] = "contrib"

projects[label_help][version] = "1.2"
projects[label_help][subdir] = "contrib"

projects[libraries][version] = "2.2"
projects[libraries][subdir] = "contrib"

projects[menu_token][version] = "1.0-beta5"
projects[menu_token][subdir] = "contrib"

projects[pathauto][version] = "1.2"
projects[pathauto][subdir] = "contrib"

projects[realname][version] = "1.2"
projects[realname][subdir] = "contrib"

projects[shs][version] = "1.6"
projects[shs][subdir] = "contrib"

projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

projects[token][version] = "1.5"
projects[token][subdir] = "contrib"

projects[panels][version] = "3.5"
projects[panels][subdir] = "contrib"

projects[panels_everywhere][version] = "1.0-rc2"
projects[panels_everywhere][subdir] = "contrib"

projects[js][version] = "1.0"
projects[js][subdir] = "contrib"

projects[quiz][version] = "5.0-alpha8"
projects[quiz][subdir] = "contrib"

projects[quiz][version] = "5.0-alpha8"
projects[quiz][subdir] = "contrib"

projects[search_api][version] = "1.14"
projects[search_api][subdir] = "contrib"

projects[search_api_db][version] = "1.4"
projects[search_api_db][subdir] = "contrib"

projects[search_config][version] = "1.1"
projects[search_config][subdir] = "contrib"

projects[facetapi][version] = "1.5"
projects[facetapi][subdir] = "contrib"

projects[facetapi_bonus][version] = "1.x-dev"
projects[facetapi_bonus][subdir] = "contrib"

projects[sharethis][version] = "2.10"
projects[sharethis][subdir] = "contrib"

projects[taxonomy_csv][version] = "5.10"
projects[taxonomy_csv][subdir] = "contrib"

projects[uuid][version] = "1.0-alpha6"
projects[uuid][subdir] = "contrib"

projects[chosen][version] = "2.0-beta4"
projects[chosen][subdir] = "contrib"

projects[views][version] = "3.8"
projects[views][subdir] = "contrib"

projects[views_bulk_operations][version] = "3.2"
projects[views_bulk_operations][subdir] = "contrib"

projects[views_data_export][version] = "3.0-beta8"
projects[views_data_export][subdir] = "contrib"

projects[votingapi][version] = "2.12"
projects[votingapi][subdir] = "contrib"

; +++++ TODO modules without versions +++++

projects[node_edit_protection][version] = "" ; TODO add version
projects[node_edit_protection][subdir] = "contrib"

; +++++ Themes +++++

; radix
projects[radix][type] = "theme"
projects[radix][version] = "3.0-rc1"
projects[radix][subdir] = "contrib"

; responsive_bartik
projects[responsive_bartik][type] = "theme"
projects[responsive_bartik][version] = "1.0"
projects[responsive_bartik][subdir] = "contrib"

; rubik
projects[rubik][type] = "theme"
projects[rubik][version] = "4.1"
projects[rubik][subdir] = "contrib"

; tao
projects[tao][type] = "theme"
projects[tao][version] = "3.1"
projects[tao][subdir] = "contrib"

; +++++ Libraries +++++

; OAuth Drupal fork
libraries[oauth][directory_name] = "oauth"
libraries[oauth][type] = "library"
libraries[oauth][destination] = "libraries"
libraries[oauth][download][type] = "get"
libraries[oauth][download][url] = "https://github.com/juampy72/OAuth-PHP/archive/master.zip"

