#Patches

Patch documentation should be in the following format:

* module name
  * brief description
    * issue link (if exists)
    * patch file location

Example:

* views
  * Add CSS class to read-more link on trimmed text field
    * http://drupal.org/node/1557926
    * http://drupal.org/files/views-more_link_class-1557926.patch

---

* elysia_cron
    * Can't install Elysia Cron via an install profile
      * http://drupal.org/node/1204488
      * https://www.drupal.org/files/elysia_cron_install_profile_fail-1204488-14.patch

* drupal
    * Wrong file extension message hidden after upload has been attempted
      * https://www.drupal.org/node/1074214
      * https://www.drupal.org/files/issues/file_behaviors_once_D7-1074214-13.patch
    * Client side file extension validation for managed files fails on Internet Explorer 11
      * https://www.drupal.org/node/2301527
      * https://www.drupal.org/files/issues/core-js-file-extension-validate-2301527-13.patch
    * Support X-Forwarded-* HTTP headers alternates
      * https://www.drupal.org/node/313145
      * https://www.drupal.org/files/issues/support-x_forwarded_proto-313145-111.patch

* eck
    * Warning: array_keys() expects parameter 1 to be array, null given
      in drupal_schema_fields_sql() during profile install.
      * https://www.drupal.org/node/2289241
      * https://www.drupal.org/files/issues/eck-array_keys_error-2289241-15.patch

