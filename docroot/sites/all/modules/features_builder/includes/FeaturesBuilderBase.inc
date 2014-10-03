<?php

/**
 * Base class for a Features Builder.
 */
abstract class FeaturesBuilderBase implements FeaturesBuilderInterface {

  static $NOT_EXIST = 0;
  static $DISABLED = 1;
  static $DEFAULT = 2;
  static $OVERRIDDEN = 3;
  protected $name;
  protected $components;
  protected $dependencies;
  public $moduleName;
  public $moduleLabel;
  public $prefix;

  public function __construct($name) {
    $this->name = $name;
    $this->prefix = variable_get('features_builder_prefix_name');
    $this->moduleName = $this->prefix . '_' . $name;
    $features = $this->listFeatures();
    $this->moduleLabel = variable_get('features_builder_prefix_label') . ' ' . $features[$name];
  }

  /**
   * List components included for a named Features module.
   */
  abstract protected function setComponents();

  /**
   * Lists the components included in this build.
   */
  public function components() {
    if ($this->components === NULL) {
      $this->setComponents();
      if ($this->components === NULL) {
        $this->components = array();
      }
      drupal_alter('features_builder_components_' . $this->name, $this->components);
      ksort($this->components);
    }
    return $this->components;
  }

  /**
   * Set components as defined in $components parameter.
   * 
   * @param string $component
   *   Component type of the exportables to analyze.
   * @param array $components
   *   An array of exportable component names.
   */
  protected function setNamedComponents($component, $components) {
    if (empty($this->components[$component]) || !is_array($this->components[$component])) {
      $this->components[$component] = array();
    }
    $matches = array_intersect_key(features_builder_get_exportables($component), array_flip($components));
    if ($matches) {
      $this->components[$component] += $matches;
    }
  }

  /**
   * Set variable type components by matching a regex.
   * 
   * @param string $component
   *   Component type of the exportables to analyze.
   * @param string $regex
   *   A regex used to match variable names.
   */
  protected function setRegexComponents($component, $regex) {
    $components = features_builder_get_exportables($component);
    foreach ($components as $name => $value) {
      if (preg_match($regex, $name) > 0) {
        $this->components[$component][$name] = $value;
      }
    }
  }

  /**
   * Set all components of a specified type.
   * 
   * @param string $component
   *   Component type of the exportables to analyze.
   */
  protected function setAllComponents($component) {
    $this->components[$component] = features_builder_get_exportables($component);
  }

  /**
   * Returns the status of the feature.
   */
  public function status() {

    $module_name = variable_get('features_builder_prefix_name') . '_' . $this->name;

    if (module_exists($module_name)) {
      // @todo: add check to see if components ares overridden.
      if (TRUE) {
        return self::$DEFAULT;
      }
      else {
        return self::$OVERRIDDEN;
      }
    }
    else {
      if (in_array($module_name, system_rebuild_module_data())) {
        return self::$DISABLED;
      }
      else {
        return self::$NOT_EXIST;
      }
    }
  }

  /**
   * Returns the status of the feature.
   */
  public function statusLabel() {
    switch ($this->status()) {
      case self::$NOT_EXIST:
        return t('Not present');
        break;
      case self::$DISABLED:
        return t('Disabled');
        break;
      case self::$DEFAULT:
        return t('Default');
        break;
      case self::$OVERRIDDEN:
        return t('Overridden');
        break;
    }
  }

  /**
   * 
   */
  public function export($directory = NULL) {
    // Determine if a directory was specified.
    if (!$directory) {
      $directory = $this->featureDir();
    }
    else {
      $directory .= '/' . $this->moduleName;
    }

    $this->writeFeature($this->buildExport(), $directory);
  }

  /**
   * Build the export array representing a Feature.
   */
  public function buildExport() {
    // Build the export array needed for features_export_render().
    $export = array(
      'features' => array(),
      'dependencies' => array('features'),
      'conflicts' => array(),
      'name' => $this->moduleLabel,
      'package' => $this->package(),
    );

    // Add in the feature components.
    foreach ($this->components() as $type => $components) {
      foreach (array_keys($components) as $component) {
        // Dependencies handled a bit different.
        if ($type == 'dependencies') {
          $export['dependencies'][$component] = $component;
        }
        else {
          $export['features'][$type][$component] = $component;
        }
      }
    }

    if (empty($export['features'])) {
      return;
    }

    $export['features']['features_api']['api:2'] = 'api:2';

    // Last-minute adjustments to the export array.
    $this->alterExport($export);
    drupal_alter("features_builder_export_{$this->name}", $export);
    $export['dependencies'] = array_unique($export['dependencies']);
    sort($export['dependencies']);

    return $export;
  }

  /**
   * Method to isolate changes to the export array.
   * 
   * A few things in Features are required but not handled via the normal 
   * Features components so we add them in here. Extending classes may make
   * additional adjustments here as well.
   */
  protected function alterExport(&$export) {
    // @todo: make these aware of the version they're declaring.
    if (!empty($export['features']['context'])) {
      $export['features']['ctools'][] = 'context:context:3';
      $export['dependencies'][] = 'context';
      $export['dependencies'][] = 'ctools';
    }
    if (!empty($export['features']['ctools_custom_content'])) {
      $export['features']['ctools'][] = 'ctools_custom_content:ctools_content:1';
      $export['dependencies'][] = 'ctools';
    }
    if (!empty($export['features']['environment_indicator_environment'])) {
      $export['features']['ctools'][] = 'environment_indicator:default_environment_indicator_environments:1';
      $export['dependencies'][] = 'environment_indicator';
      $export['dependencies'][] = 'ctools';
    }
    if (!empty($export['features']['field_group'])) {
      $export['features']['ctools'][] = 'field_group:field_group:1';
      $export['dependencies'][] = 'field_group';
      $export['dependencies'][] = 'ctools';
    }
    if (!empty($export['features']['linkit_profiles'])) {
      $export['features']['ctools'][] = 'linkit:linkit_profiles:1';
      $export['dependencies'][] = 'linkit';
      $export['dependencies'][] = 'ctools';
    }
    if (!empty($export['features']['page_manager_handlers'])) {
      $export['features']['ctools'][] = 'page_manager:pages_default:1';
      $export['dependencies'][] = 'page_manager';
      $export['dependencies'][] = 'ctools';
    }
    if (!empty($export['features']['panelizer_defaults'])) {
      $export['features']['ctools'][] = 'panelizer:panelizer:1';
      $export['dependencies'][] = 'panelizer';
      $export['dependencies'][] = 'ctools';
    }
    if (!empty($export['features']['panels_renderer_pipeline'])) {
      $export['features']['ctools'][] = 'panels:pipelines:1';
      $export['dependencies'][] = 'panels';
      $export['dependencies'][] = 'ctools';
    }
    if (!empty($export['features']['variable'])) {
      $export['features']['ctools'][] = 'strongarm:strongarm:1';
      $export['dependencies'][] = 'strongarm';
      $export['dependencies'][] = 'ctools';
    }
    if (!empty($export['features']['views_view'])) {
      $export['features']['ctools'][] = 'views:views_default:3.0';
      $export['dependencies'][] = 'views';
      $export['dependencies'][] = 'ctools';
    }
  }

  /**
   * Determine where this Feature will be written.
   */
  public function featureDir() {
    if (!$directory = drupal_get_path('module', $this->moduleName)) {
      $directory = variable_get('features_builder_base_dir') . '/' . $this->moduleName;
    }
    return $directory;
  }

  /**
   * Writes the Feature's files.
   * 
   * This code is borrowed heavily from features_export_build_form_submit().
   */
  protected function writeFeature($export, $directory) {
    // Export may be NULL in the case that it had no componets.
    if (!$export) {
      return;
    }

    file_prepare_directory($directory, FILE_CREATE_DIRECTORY || FILE_MODIFY_PERMISSIONS);
    module_load_include('inc', 'features', 'features.export');
    $files = features_export_render($export, $this->moduleName);
    foreach ($files as $extension => $file_contents) {
      if (!in_array($extension, array('module', 'info'))) {
        $extension .= '.inc';
      }
      file_put_contents("{$directory}/{$this->moduleName}.$extension", $file_contents);
    }
  }

  /**
   * Determine which package the feature belongs to.
   */
  public function package() {
    return 'Features';
  }

}
