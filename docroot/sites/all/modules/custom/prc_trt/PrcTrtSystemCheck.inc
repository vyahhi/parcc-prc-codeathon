<?php

class PrcTrtSystemCheck {
  const MINIMUM_MONITOR_SIZE = 9.5;
  const MINIMUM_COLOR_DEPTH = 16;
  const MINIMUM_SCREEN_WIDTH = 1024;
  const MINIMUM_SCREEN_HEIGHT = 768;
  const MINIMUM_RAM = 0.5;
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
    $browser = $this->wrapper->field_browser->value();
    $version = $this->wrapper->field_browser_version->value();
    $browser_full = $browser . ' ' . $version;
    $os = $this->wrapper->field_operating_system->value();
    $upgrade_rec_os = array('mac106', 'win7', 'winvista');
    $upgrade_rec_browser = array('safari 5', 'ie 9');
    if (array_search($os, $upgrade_rec_os) !== FALSE && array_search($browser_full, $upgrade_rec_browser) !== FALSE) {
      $browser_pass = -1;
    }
    else {
      $browser_pass = $this->browserOSCompatibilityCheck($browser, $version, $os);
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

  public function jreBrowserCheck($browser, $browser_version, $os, $jre) {
    $result = FALSE;
    if ($jre) {
      $jre_pieces = explode('_', $jre);
      $jre_little_version = intval($jre_pieces[1]);
      $jre_big_version = floatval($jre_pieces[0]);

      if (strpos($os, 'win') !== FALSE) {
        switch ($browser) {
          case 'ie':
            switch ($browser_version) {
              case 9:
                $result = $jre_big_version >= 1.5;
                break;
              case 10:
                $result = $jre_big_version >= 1.6;
                break;
              case 11:
                $result = $jre_big_version >= 1.7;
                break;
            }
            break;
          case 'chrome':
            if ($browser_version > 34 && $browser_version < 40) {
              $result = $jre_big_version >= 1.6;
            }
            break;
          case 'ff':
            if ($browser_version > 27 && $browser_version < 36) {
              $result = $jre_big_version >= 1.6 && $jre_little_version >= 30;
            }
            break;
        }
      }
      elseif (strpos($os, 'mac') !== FALSE) {
        switch ($browser) {
          case 'safari':
            switch ($browser_version) {
              case 5:
                $result = $jre_big_version >= 1.6 && $jre_little_version >= 65;
                break;
              default:
                $result = $jre_big_version >= 1.6;
                break;
            }
          case 'ff':
            if ($browser_version > 27 && $browser_version < 36) {
              $result = $jre_big_version >= 1.6 && $jre_little_version >= 30;
            }
            break;
        }
      }
      elseif (strpos($os, 'fedora') !== FALSE || strpos($os, 'ubuntu') !== FALSE) {
        if ($browser == 'ff' && $browser_version > 27 && $browser_version < 36) {
          $result = $jre_big_version >= 1.7;
        }
      }
    }
    return $result;
  }

  public function browserOSCompatibilityCheck($browser, $browser_version, $os) {
    $result = FALSE;

    $compatibility = array();
    $compatibility['winxpsp3']['chrome']['35'] = TRUE;
    $compatibility['winxpsp3']['chrome']['36'] = TRUE;
    $compatibility['winxpsp3']['chrome']['37'] = TRUE;
    $compatibility['winxpsp3']['chrome']['38'] = TRUE;
    $compatibility['winxpsp3']['chrome']['39'] = TRUE;
    $compatibility['winxpsp3']['ff']['28'] = TRUE;
    $compatibility['winxpsp3']['ff']['29'] = TRUE;
    $compatibility['winxpsp3']['ff']['30'] = TRUE;
    $compatibility['winxpsp3']['ff']['31'] = TRUE;
    $compatibility['winxpsp3']['ff']['32'] = TRUE;
    $compatibility['winxpsp3']['ff']['33'] = TRUE;
    $compatibility['winxpsp3']['ff']['34'] = TRUE;
    $compatibility['winxpsp3']['ff']['35'] = TRUE;

    $compatibility['winvista']['ie']['9'] = TRUE;
    $compatibility['winvista']['chrome']['35'] = TRUE;
    $compatibility['winvista']['chrome']['36'] = TRUE;
    $compatibility['winvista']['chrome']['37'] = TRUE;
    $compatibility['winvista']['chrome']['38'] = TRUE;
    $compatibility['winvista']['chrome']['39'] = TRUE;
    $compatibility['winvista']['ff']['28'] = TRUE;
    $compatibility['winvista']['ff']['29'] = TRUE;
    $compatibility['winvista']['ff']['30'] = TRUE;
    $compatibility['winvista']['ff']['31'] = TRUE;
    $compatibility['winvista']['ff']['32'] = TRUE;
    $compatibility['winvista']['ff']['33'] = TRUE;
    $compatibility['winvista']['ff']['34'] = TRUE;
    $compatibility['winvista']['ff']['35'] = TRUE;

    $compatibility['win7']['ie']['9'] = TRUE;
    $compatibility['win7']['ie']['10'] = TRUE;
    $compatibility['win7']['ie']['11'] = TRUE;
    $compatibility['win7']['chrome']['35'] = TRUE;
    $compatibility['win7']['chrome']['36'] = TRUE;
    $compatibility['win7']['chrome']['37'] = TRUE;
    $compatibility['win7']['chrome']['38'] = TRUE;
    $compatibility['win7']['chrome']['39'] = TRUE;
    $compatibility['win7']['ff']['28'] = TRUE;
    $compatibility['win7']['ff']['29'] = TRUE;
    $compatibility['win7']['ff']['30'] = TRUE;
    $compatibility['win7']['ff']['31'] = TRUE;
    $compatibility['win7']['ff']['32'] = TRUE;
    $compatibility['win7']['ff']['33'] = TRUE;
    $compatibility['win7']['ff']['34'] = TRUE;
    $compatibility['win7']['ff']['35'] = TRUE;

    $compatibility['win8']['ie']['10'] = TRUE;
    $compatibility['win8']['chrome']['35'] = TRUE;
    $compatibility['win8']['chrome']['36'] = TRUE;
    $compatibility['win8']['chrome']['37'] = TRUE;
    $compatibility['win8']['chrome']['38'] = TRUE;
    $compatibility['win8']['chrome']['39'] = TRUE;
    $compatibility['win8']['ff']['28'] = TRUE;
    $compatibility['win8']['ff']['29'] = TRUE;
    $compatibility['win8']['ff']['30'] = TRUE;
    $compatibility['win8']['ff']['31'] = TRUE;
    $compatibility['win8']['ff']['32'] = TRUE;
    $compatibility['win8']['ff']['33'] = TRUE;
    $compatibility['win8']['ff']['34'] = TRUE;
    $compatibility['win8']['ff']['35'] = TRUE;

    $compatibility['win81']['ie']['11'] = TRUE;
    $compatibility['win81']['chrome']['35'] = TRUE;
    $compatibility['win81']['chrome']['36'] = TRUE;
    $compatibility['win81']['chrome']['37'] = TRUE;
    $compatibility['win81']['chrome']['38'] = TRUE;
    $compatibility['win81']['chrome']['39'] = TRUE;
    $compatibility['win81']['ff']['28'] = TRUE;
    $compatibility['win81']['ff']['29'] = TRUE;
    $compatibility['win81']['ff']['30'] = TRUE;
    $compatibility['win81']['ff']['31'] = TRUE;
    $compatibility['win81']['ff']['32'] = TRUE;
    $compatibility['win81']['ff']['33'] = TRUE;
    $compatibility['win81']['ff']['34'] = TRUE;
    $compatibility['win81']['ff']['35'] = TRUE;

    $compatibility['mac106']['safari']['5'] = TRUE;
    $compatibility['mac106']['ff']['28'] = TRUE;
    $compatibility['mac106']['ff']['29'] = TRUE;
    $compatibility['mac106']['ff']['30'] = TRUE;
    $compatibility['mac106']['ff']['31'] = TRUE;
    $compatibility['mac106']['ff']['32'] = TRUE;
    $compatibility['mac106']['ff']['33'] = TRUE;
    $compatibility['mac106']['ff']['34'] = TRUE;
    $compatibility['mac106']['ff']['35'] = TRUE;

    $compatibility['mac107']['safari']['6'] = TRUE;
    $compatibility['mac107']['ff']['28'] = TRUE;
    $compatibility['mac107']['ff']['29'] = TRUE;
    $compatibility['mac107']['ff']['30'] = TRUE;
    $compatibility['mac107']['ff']['31'] = TRUE;
    $compatibility['mac107']['ff']['32'] = TRUE;
    $compatibility['mac107']['ff']['33'] = TRUE;
    $compatibility['mac107']['ff']['34'] = TRUE;
    $compatibility['mac107']['ff']['35'] = TRUE;

    $compatibility['mac108']['safari']['6'] = TRUE;
    $compatibility['mac108']['ff']['28'] = TRUE;
    $compatibility['mac108']['ff']['29'] = TRUE;
    $compatibility['mac108']['ff']['30'] = TRUE;
    $compatibility['mac108']['ff']['31'] = TRUE;
    $compatibility['mac108']['ff']['32'] = TRUE;
    $compatibility['mac108']['ff']['33'] = TRUE;
    $compatibility['mac108']['ff']['34'] = TRUE;
    $compatibility['mac108']['ff']['35'] = TRUE;

    $compatibility['mac109']['safari']['7'] = TRUE;
    $compatibility['mac109']['ff']['28'] = TRUE;
    $compatibility['mac109']['ff']['29'] = TRUE;
    $compatibility['mac109']['ff']['30'] = TRUE;
    $compatibility['mac109']['ff']['31'] = TRUE;
    $compatibility['mac109']['ff']['32'] = TRUE;
    $compatibility['mac109']['ff']['33'] = TRUE;
    $compatibility['mac109']['ff']['34'] = TRUE;
    $compatibility['mac109']['ff']['35'] = TRUE;

    $compatibility['mac1010']['safari']['8'] = TRUE;
    $compatibility['mac1010']['ff']['28'] = TRUE;
    $compatibility['mac1010']['ff']['29'] = TRUE;
    $compatibility['mac1010']['ff']['30'] = TRUE;
    $compatibility['mac1010']['ff']['31'] = TRUE;
    $compatibility['mac1010']['ff']['32'] = TRUE;
    $compatibility['mac1010']['ff']['33'] = TRUE;
    $compatibility['mac1010']['ff']['34'] = TRUE;
    $compatibility['mac1010']['ff']['35'] = TRUE;

    $compatibility['fedora19']['ff']['28'] = TRUE;
    $compatibility['fedora19']['ff']['29'] = TRUE;
    $compatibility['fedora19']['ff']['30'] = TRUE;
    $compatibility['fedora19']['ff']['31'] = TRUE;
    $compatibility['fedora19']['ff']['32'] = TRUE;
    $compatibility['fedora19']['ff']['33'] = TRUE;
    $compatibility['fedora19']['ff']['34'] = TRUE;
    $compatibility['fedora19']['ff']['35'] = TRUE;

    $compatibility['ubuntu12']['ff']['28'] = TRUE;
    $compatibility['ubuntu12']['ff']['29'] = TRUE;
    $compatibility['ubuntu12']['ff']['30'] = TRUE;
    $compatibility['ubuntu12']['ff']['31'] = TRUE;
    $compatibility['ubuntu12']['ff']['32'] = TRUE;
    $compatibility['ubuntu12']['ff']['33'] = TRUE;
    $compatibility['ubuntu12']['ff']['34'] = TRUE;
    $compatibility['ubuntu12']['ff']['35'] = TRUE;

    $result = array_key_exists($os, $compatibility) &&
      array_key_exists($browser, $compatibility[$os]) &&
      array_key_exists($browser_version, $compatibility[$os][$browser]) &&
      $compatibility[$os][$browser][$browser_version];

    $always_allow_os = array('chrome35', 'ios6', 'android_lollipop');

    if (array_search($os, $always_allow_os) !== FALSE) {
      // OSs with no browser requirement
      $result = TRUE;
    }

    return $result;
  }

}