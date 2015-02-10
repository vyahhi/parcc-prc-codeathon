<?php

class PrcJsonStandardMigrateList extends MigrateList {

  function __toString() {
    return __CLASS__;
  }

  function computeCount() {
    return count($this->getIdList());
  }

  function getIdList() {
    return array_keys(prc_migrate_standards());
  }

  static function getKeySchema() {
    return array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
  }
}
