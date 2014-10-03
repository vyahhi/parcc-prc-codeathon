<?php

class SiteFeaturesBuilder extends FeaturesBuilderBase {

  protected $variables = array(
    'admin_theme',
    'block_cache',
    'cache',
    'cache_lifetime',
    'clean_url',
    'date_default_timezone',
    'dblog_row_limit',
    'default_nodes_main',
    'error_level',
    'node_admin_theme',
    'page_cache_maximum_age',
    'page_compression',
    'preprocess_css',
    'preprocess_js',
    'site_default_country',
    'site_403',
    'site_404',
    'site_frontpage',
    'site_mail',
    'site_name',
    'site_slogan',
    'theme_default',
    'theme_settings',
    'update_notify_emails',
  );

  public static function listFeatures() {
    return array('site' => t('Site'));
  }

  /**
   * {@inheritdoc}
   */
  public function package() {
    return 'Configuration';
  }

  protected function setComponents() {
    $this->setNamedComponents('variable', $this->variables);
    $this->setRegexComponents('variable', '/^theme_[a-z0-9_]*_settings$/');

    if (module_exists('admin_menu')) {
      $this->setNamedComponents('dependencies', array('admin_menu'));
      $this->setRegexComponents('variable', '/^admin_menu_/');
    }

    if (module_exists('environment_indicator')) {
      $this->setNamedComponents('dependencies', array('environment_indicator'));
      $this->setAllComponents('environment_indicator_environment');
    }

    if (module_exists('googleanalytics')) {
      $this->setNamedComponents('dependencies', array('googleanalytics'));
      $this->setRegexComponents('variable', '/^googleanalytics_/');
    }

    if (module_exists('honeypot')) {
      $this->setNamedComponents('dependencies', array('honeypot'));
      $this->setRegexComponents('variable', '/^honeypot_/');
    }

    if (module_exists('transliteration')) {
      $this->setNamedComponents('dependencies', array('transliteration'));
      $this->setRegexComponents('variable', '/^transliteration_/');
    }

    if (module_exists('webform')) {
      $this->setNamedComponents('dependencies', array('webform'));
      $this->setRegexComponents('variable', '/^webform_/');
    }
  }

}
