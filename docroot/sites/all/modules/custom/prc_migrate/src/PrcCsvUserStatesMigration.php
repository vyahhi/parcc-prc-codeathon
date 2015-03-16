<?php

/**
 * @file
 * Contains PrcCsvGenreMigration.
 */

class PrcCsvUserStatesMigration extends Migration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $vocab_name = 'user_states';

    $this->description = t('Migrate @vocab_description terms from CSV to taxonomy terms', array('@vocab_description' => $vocab_name));

    $path = drupal_get_path('module', 'prc_migrate') . '/data/' . $vocab_name . '.csv';
    $columns = array(
      0 => array('id', t('ID')),
      1 => array('name', t('Name')),
      2 => array('field_state_abbreviation', t('State Code')),
      3 => array('weight', t('Weight')),
    );
    $options = array('header_rows' => TRUE);
    $fields = array(
      'id' => array(t('ID')),
      'name' => array(t('Term Name')),
      'field_state_abbreviation' => array(t('Abbreviation')),
      'weight' => array(t('Weight')),
    );

    $this->source = new MigrateSourceCSV($path, $columns, $options, $fields);

    $this->destination = new MigrateDestinationTerm($vocab_name);

    $this->map = new MigrateSQLMap($vocab_name, self::getKeySchema(), $this->destination->getKeySchema());

    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('field_state_abbreviation', 'field_state_abbreviation');
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
