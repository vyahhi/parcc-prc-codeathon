<?php

class PrcJsonStandardMigrateItem extends MigrateItem {

  function getItem($id) {
    $standards = prc_migrate_standards();
    return array_key_exists($id, $standards) ? $standards[$id] : NULL;
  }

}
