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

    $this->setNamedComponents('dependencies', array_filter($this->dependencies));
  }

}
