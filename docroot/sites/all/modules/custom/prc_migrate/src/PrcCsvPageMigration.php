<?php

/**
 * @file
 * Contains PrcCsvGenreMigration.
 */
class PrcCsvPageMigration extends Migration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $content_type = 'page';

    $this->description = t('Migrate CSVs to @content_type nodes', array('@content_type' => $content_type));

    $path = drupal_get_path('module', 'prc_migrate') . '/data/' . $content_type . '.csv';
    $columns = array(
      0 => array('id', t('ID')),
      1 => array('title', t('title')),
      2 => array('body', t('body')),
    );
    $options = array('header_rows' => TRUE);
    $fields = array(
      'id' => array(t('ID')),
      'title' => array(t('title')),
      'body' => array(t('Body')),
    );

    $this->source = new MigrateSourceCSV($path, $columns, $options, $fields);

    $this->destination = new MigrateDestinationNode($content_type, array('text_format' => 'filtered_html'));

    $this->map = new MigrateSQLMap($content_type, self::getKeySchema(), $this->destination->getKeySchema());

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('uid')->defaultValue(1);
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
