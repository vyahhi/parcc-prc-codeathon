<?php

abstract class EntityFeaturesBuilder extends FeaturesBuilderBase {

  /**
   * {@inheritdoc}
   */
  public function package() {
    return 'Entity';
  }

  protected function setFields($entity_type, $bundle) {
    $this->setRegexComponents('field_instance', "/^{$entity_type}-{$bundle}-/");
    $this->setNamedComponents('variable', array("field_bundle_settings_{$entity_type}__{$bundle}"));
    $info = field_info_instances($entity_type);
    foreach ($info[$bundle] as $bundleInfo) {
      $dependencies[] = $bundleInfo['widget']['module'];
      foreach ($bundleInfo['display'] as $display) {
        $dependencies[] = !empty($display['module']) ? $display['module'] : NULL;
      }
    }
    $this->setFieldGroups($entity_type, $bundle);
  }

  protected function setFieldGroups($entity_type, $bundle) {
    $this->setRegexComponents('field_group', "/^group_[a-z0-9_]*\|$entity_type\|$bundle\|/");
    if (!empty($this->components['field_group'])) {
      $this->setNamedComponents('dependencies', array('field_group'));
    }
  }

}
