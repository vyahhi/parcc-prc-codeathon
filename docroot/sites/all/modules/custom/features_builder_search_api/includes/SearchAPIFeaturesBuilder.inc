<?php

class SearchAPIFeaturesBuilder extends FeaturesBuilderBase {

  protected $dependencies = array(
    'search_api',
    'search_api_facetapi',
    'search_api_views',
    'search_api_db',
    'search_api_attachments',
    'facetapi',
    'facetapi_bonus',
    'entity',
    'strongarm',
  );
  protected $variables = array(
  );

  public static function listFeatures() {
    return array('search_api' => t('Search API'));
  }
  
  /**
   * {@inheritdoc}
   */
  public function package() {
    return 'Configuration';
  }

  protected function setComponents() {
    $this->setAllComponents('search_api_index');
    $this->setAllComponents('search_api_server');
    $this->setAllComponents('facetapi');
    $this->setAllComponents('current_search');
    $this->setNamedComponents('variable', $this->variables);
    $this->setRegexComponents('variable', '/^facetapi.*/');
    $this->setRegexComponents('variable', '/^search_api.*/');

    // Add in modules utilized by any of the filters.
    if (!empty($this->components['filter'])) {
      foreach ($this->components['filter'] as $format_id => $name) {
        if ($format = filter_format_load($format_id)) {
          $filters = filter_list_format($format->format);
          foreach ($filters as $filter) {
            $this->dependencies[] = $filter->module;
          }
        }
      }
    }

    if (!empty($this->components['wysiwyg'])) {
      $this->dependencies[] = 'wysiwyg';
    }

    if (module_exists('imce')) {
      $this->dependencies[] = 'imce';
      $this->setRegexComponents('variable', '/imce_.+/');
    }

    if (module_exists('linkit')) {
      $this->dependencies[] = 'linkit';
      $this->setAllComponents('linkit_profiles');
    }

    $this->setNamedComponents('dependencies', array_filter($this->dependencies));
  }

}
