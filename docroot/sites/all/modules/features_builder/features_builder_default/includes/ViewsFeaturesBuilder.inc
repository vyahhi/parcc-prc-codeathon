<?php

class ViewsFeaturesBuilder extends FeaturesBuilderBase {

  public static function listFeatures() {
    return array('views' => t('Views'));
  }

  public function package() {
    return 'CTools';
  }

  protected function setComponents() {
    $this->setAllComponents('views_view');
  }

}
