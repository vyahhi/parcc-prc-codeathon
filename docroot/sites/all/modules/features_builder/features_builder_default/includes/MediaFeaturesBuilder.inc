<?php

class MediaFeaturesBuilder extends FeaturesBuilderBase {

  protected $dependencies = array(
    'ctools',
    'features',
    'filter',
    'image',
    'strongarm',
  );
  protected $variables = array(
    'file_default_scheme',
    'filter_fallback_format',
    'image_jpeg_quality',
    'image_toolkit',
  );

  public static function listFeatures() {
    return array('media' => t('Media'));
  }
  
  /**
   * {@inheritdoc}
   */
  public function package() {
    return 'Configuration';
  }

  protected function setComponents() {
    $this->setNamedComponents('dependencies', $this->dependencies);
    $this->setAllComponents('filter');
    $this->setAllComponents('image');
    $this->setNamedComponents('variable', $this->variables);
    $this->setAllComponents('wysiwyg');

    if (!empty($this->components['wysiwyg'])) {
      $this->setNamedComponents('dependencies', array('wysiwyg'));
    }

    if (module_exists('imce')) {
      $this->setNamedComponents('dependencies', array('imce'));
      $this->setRegexComponents('variable', '/imce_.+/');
    }

    if (module_exists('linkit')) {
      $this->setNamedComponents('dependencies', array('linkit'));
      $this->setAllComponents('linkit_profiles');
    }
  }

}
