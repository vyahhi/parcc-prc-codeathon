<?php

/**
 * @file
 * Contains PrcCsvGenreMigration.
 */

class PrcCsvGradeLevelMigration extends Migration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->description = t('Migrate grade level terms from Csv to taxonomy terms');

    $path = drupal_get_path('module', 'prc_migrate') . '/data/grade_level.csv';
    $columns = array(
      0 => array('id', t('ID')),
      1 => array('name', t('Name')),
      2 => array('weight', t('Weight')),
    );
    $options = array('header_rows' => TRUE);
    $fields = array(
      'id' => array(t('ID')),
      'name' => array(t('Genre Name')),
      'weight' => array(t('Weight')),
    );

    $this->source = new MigrateSourceCSV($path, $columns, $options, $fields);

    $this->destination = new MigrateDestinationTerm('grade_level');

    $this->map = new MigrateSQLMap(__CLASS__, self::getKeySchema(), $this->destination->getKeySchema());

    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('weight', 'weight');
  }

  public static function getKeySchema() {
    return array(
      'id' => array(
        'type' => 'int',
        'not null' => TRUE,
      ),
    );
  }

}
