<?php

class PanelsFeaturesBuilder extends FeaturesBuilderBase {

  public static function listFeatures() {
    return array('panels' => t('Panels'));
  }

  /**
   * {@inheritdoc}
   */
  public function package() {
    return 'Ctools';
  }

  protected function setComponents() {
    // Standard Panels.
    $this->setAllComponents('ctools_custom_content');
    $this->setAllComponents('page_manager_handlers');
    $this->setAllComponents('page_manager_pages');
    $this->setAllComponents('panels_renderer_pipeline');
    $this->setNamedComponents('variable', array('default_page_manager_handlers', 'default_page_manager_pages'));
    $this->setRegexComponents('variable', '/page_manager_[a-z0-9_]+_disabled/');

    // Panelizer.
    $this->setAllComponents('panelizer_defaults');
    $this->setRegexComponents('variable', '/panelizer_.+/');
  }

}
