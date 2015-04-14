<?php

/**
 * @file
 * Contains PrcCsvPdCourseMigration.
 */
class PrcCsvPdCourseMigration extends Migration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $content_type = 'pd_course';

    $this->description = t('Migrate CSVs to @content_type nodes', array('@content_type' => $content_type));

    $path = drupal_get_path('module', 'prc_migrate') . '/data/' . $content_type . '.csv';
    $columns = array(
      0 => array('id', t('ID')),
      1 => array('title', t('title')),
      2 => array('objectives', t('objectives')),
      3 => array('permissions', t('permissions')),
      4 => array('link title', t('link title')),
      5 => array('link url', t('link url')),
    );
    $options = array('header_rows' => TRUE);
    $fields = array(
      'id' => array(t('ID')),
      'title' => array(t('title')),
      'field_course_objectives' => array(t('Course Objectives')),
      'field_permissions' => array(t('Permissions')),
      'field_link_to_a_url' => array(t('Link to URL: URL')),
      'field_link_to_a_url:title' => array(t('Link to URL: Title')),
    );

    $this->source = new MigrateSourceCSV($path, $columns, $options, $fields);

    $this->destination = new MigrateDestinationNode($content_type, array('text_format' => 'filtered_html'));

    $this->map = new MigrateSQLMap($content_type, self::getKeySchema(), $this->destination->getKeySchema());

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_course_objectives', 'objectives');
    $this->addFieldMapping('field_permissions', 'permissions');
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('status')->defaultValue(1);

    $this->addFieldMapping('field_link_to_a_url', 'link url');
    $this->addFieldMapping('field_link_to_a_url:title', 'link title');
    $this->addFieldMapping('field_link_to_a_url:attributes')->defaultValue(array());
    $this->addFieldMapping('field_link_to_a_url:language', 'language')->defaultValue(LANGUAGE_NONE);

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
