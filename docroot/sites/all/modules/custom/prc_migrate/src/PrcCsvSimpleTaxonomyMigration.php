<?php

/**
 * @file
 * Contains PrcCsvGenreMigration.
 */

class PrcCsvSimpleTaxonomyMigration extends Migration {

  protected $vocab_name;

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->vocab_name = $arguments['vocab_name'];

    $this->description = t('Migrate @vocab_description terms from CSV to taxonomy terms', array('@vocab_description' => $this->vocab_name));

    $path = drupal_get_path('module', 'prc_migrate') . '/data/' . $this->vocab_name . '.csv';
    $columns = array(
      0 => array('id', t('ID')),
      1 => array('name', t('Name')),
      2 => array('weight', t('Weight')),
    );
    $options = array('header_rows' => TRUE);
    $fields = array(
      'id' => array(t('ID')),
      'name' => array(t('Term Name')),
      'weight' => array(t('Weight')),
    );

    $this->source = new MigrateSourceCSV($path, $columns, $options, $fields);

    $this->destination = new MigrateDestinationTerm($this->vocab_name);

    $this->map = new MigrateSQLMap($this->vocab_name, self::getKeySchema(), $this->destination->getKeySchema());

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
