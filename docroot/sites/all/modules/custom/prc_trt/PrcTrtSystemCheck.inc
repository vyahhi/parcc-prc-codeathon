<?php

class PrcTrtSystemCheck {
  const MINIMUM_MONITOR_SIZE = 9.5;
  const MINIMUM_COLOR_DEPTH = 16;
  const MINIMUM_SCREEN_WIDTH = 1024;
  const MINIMUM_SCREEN_HEIGHT = 768;
  const MINIMUM_RAM = 1.0;
  const MINIMUM_PROCESSOR_SPEED = 1;

  protected $system_check;
  private $wrapper;

  public function __construct($system_check) {
    $this->system_check = $system_check;
    $this->wrapper = entity_metadata_wrapper('prc_trt', $this->system_check);
  }

  public function operatingSystemPass() {
    $os = $this->wrapper->field_operating_system->value();
    $os_pass = $os != 'other';
    return $os_pass;
  }

  public function monitorSizePass() {
    $size = $this->wrapper->field_monitor_size->value();
    $size_pass = $size >= $this::MINIMUM_MONITOR_SIZE;
    return $size_pass;
  }

  public function colorDepthPass() {
    $depth = $this->wrapper->field_monitor_color_depth->value();
    $depth_pass = $depth >= $this::MINIMUM_COLOR_DEPTH;
    return $depth_pass;
  }

  public function resolutionPass() {
    $resw = $this->wrapper->field_screen_resolution_width->value();
    $resw_pass = $resw >= $this::MINIMUM_SCREEN_WIDTH;
    $resh = $this->wrapper->field_screen_resolution_height->value();
    $resh_pass = $resh >= $this::MINIMUM_SCREEN_HEIGHT;
    $res_pass = $resh_pass && $resw_pass;
    return $res_pass;
  }

  public function processorPass() {
    return t('N/A');
  }

  public function ramPass() {
    $os = $this->wrapper->field_operating_system->value();
    $na_os = array('ios6', 'chrome35');
    if (array_search($os, $na_os) !== FALSE) {
      $ram_pass = -1;
    }
    else {
      $ram = $this->wrapper->field_ram->value();
      $ram_pass = $ram >= $this::MINIMUM_RAM ? 1 : 0;
    }
    return $ram_pass;
  }

  public function ramResult() {
    switch ($this->ramPass()) {
      case -1:
        $ram_pass = t('N/A');
        break;
      case 0:
        $ram_pass = t('Fail');
        break;
      case 1:
        $ram_pass = t('Pass');
        break;
    }
    return $ram_pass;
  }

  public function browserPass() {
    $browser = $this->wrapper->field_browser->value() . ' ' . $this->wrapper->field_browser_version->value();
    $os = $this->wrapper->field_operating_system->value();
    $upgrade_rec_os = array('mac106', 'win7', 'winvista');
    $upgrade_rec_browser = array('safari 5', 'ie 9');
    if (array_search($os, $upgrade_rec_os) !== FALSE && array_search($browser, $upgrade_rec_browser) !== FALSE) {
      $browser_pass = -1;
    }
    else {
      $browser_pass = 1;
    }
    return $browser_pass;
  }

  public function browserResult() {
    switch ($this->browserPass()) {
      case -1:
        $browser_result = t('Upgrade recommended');
        break;
      case 0;
        $browser_result = t('Fail');
        break;
      case 1;
        $browser_result = t('Pass');
        break;
    }
    return $browser_result;
  }

  public function cookiesPass() {
    $cookies_pass = $this->wrapper->field_browser_cookies_enabled->value();
    return $cookies_pass;
  }

  public function jsPass() {
    $js_pass = $this->wrapper->field_browser_javascript_enabled->value();
    return $js_pass;
  }

  public function imagesPass() {
    $images_pass = $this->wrapper->field_browser_images_enabled->value();
    return $images_pass;
  }

  public function overallPass() {
    $os_pass = $this->operatingSystemPass();
    $size_pass = $this->monitorSizePass();
    $depth_pass = $this->colorDepthPass();
    $res_pass = $this->resolutionPass();
    $ram_pass = $this->ramPass() != 0;

    $cookies_pass = $this->cookiesPass();
    $js_pass = $this->jsPass();
    $images_pass = $this->imagesPass();

    $all_pass = $os_pass && $size_pass && $depth_pass && $res_pass && $ram_pass && $cookies_pass && $js_pass && $images_pass;
    return $all_pass ? 1 : 0;
  }
}