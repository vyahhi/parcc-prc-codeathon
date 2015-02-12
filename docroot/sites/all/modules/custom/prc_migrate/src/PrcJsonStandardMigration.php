<?php

/**
 * @file
 * Contains PrcCsvGenreMigration.
 */

class PrcJsonStandardMigration extends Migration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->description = t('Migrate Standard terms from JSON file to taxonomy terms');

    $this->source = new MigrateSourceList(new PrcJsonStandardMigrateList(), new PrcJsonStandardMigrateItem());

    $this->destination = new MigrateDestinationTerm('standard');

    $this->map = new MigrateSQLMap(__CLASS__, PrcJsonStandardMigrateList::getKeySchema(), $this->destination->getKeySchema());

    $this->addFieldMapping('name', 'id');
    $this->addFieldMapping('description', 'title');
    $this->addFieldMapping('parent_name', 'parent_id');
  }
}
