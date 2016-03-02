<?php

/**
 * @file
 * Extending of DrupalUserMigration for PRC sources.
 */
class PrcToPrcUserMigration extends DrupalUser7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $mappings = array(
      'field_first_name',
      'field_last_name',
      'field_profession',
    );
    foreach ($mappings as $mapping) {
      $this->addFieldMapping($mapping, $mapping);
    }
    $this->addFieldMapping('field_member_state', 'field_member_state')
      ->callbacks(array($this, 'sourceTermName'));
    $this->addFieldMapping('field_user_state', 'field_user_state')
      ->callbacks(array($this, 'sourceTermName'));

  }

  public function sourceTermName($value) {
    $term_name =
      Database::getConnection('default', $this->sourceConnection)
      ->select('taxonomy_term_data', 't')
      ->fields('t', array('name'))
      ->condition('tid', $value)
      ->execute()
      ->fetchField();

    return $term_name;
  }

}