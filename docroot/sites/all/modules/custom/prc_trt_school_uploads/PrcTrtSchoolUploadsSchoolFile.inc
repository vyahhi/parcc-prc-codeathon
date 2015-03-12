<?php
/**
 * @file
 * Class definition of PrcTrtSchoolUploadsStudentFile
 */

class PrcTrtSchoolUploadsSchoolFile extends PrcTrtSchoolUploadsFile {

  // Declare the upload type.
  protected $type = 'school';
  public $district_id = NULL;

  /**
   * @inherit
   */
  protected function parseLine($data) {

    // Ensure array has exactly 2 elements.
    $data['line'] = array_pad($data['line'], 2, '');
    $data['line'] = array_slice($data['line'], 0, 2);

    $record = new stdClass();
    $record->line = $data['line'];
    $record->lineNo = $data['line_no'];

    $record->school_name = trim($data['line'][0]);
    $record->school_email = trim($data['line'][1]);

    return $record;
  }

  /**
   * @inherit
   */
  protected function validateRecord($record, &$validate) {
    if (empty($record->school_name)) {
      $record->errors['school_name'] = t('School Name: Required');
    }

    if (empty($record->school_email)) {
      $record->errors['school_email'] = t('Contact E-mail: Required');

    } elseif (!valid_email_address($record->school_email)) {
      $record->errors['school_email'] = t('Contact E-mail: Invalid');
    }
  }

  /**
   * @inherit
   */
  protected function validateRecords($records, &$validate) {

    // No errors aside from individual record errors - nothing to do.
    if (empty($response['errors'])) {
      return;
    }

  }

  /**
   * Build a School node object from an uploaded record.
   */
  protected function buildSchool($record) {

    $values = array(
      'type' => 'school',
      'uid' => 0,
      'status' => 1,
      'comment' => 0,
      'promote' => 0,
    );
    $entity = entity_create('node', $values);
    $w = entity_metadata_wrapper('node', $entity);
    $w->title->set($record->school_name);
    $w->field_contact_email->set($record->school_email);
    if ($this->district_id) {
      $w->field_ref_district->set($this->district_id);
    }
    $w->save();
    return $w;
  }

  /**
   * @inherit
   */
  public function generateEntities($record_nos, &$validate) {

    // Re-parse and re-validate the records.
    $data = array();
    $records = array();
    foreach ($record_nos as $record_no) {
      if ($record = $this->loadRecord('valid', $record_no)) {
        $records[$record_no] = $record;
        $data[$record_no] = $this->buildSchool($record);
        $this->saveRecord($record, 'complete');
      }
    }

    $flag = flag_get_flag('file_uploaded');
    $flag->flag('flag', $this->district_id, NULL, TRUE);

  }

  /**
   * @inherit
   */
  public function generateEntity($record) {
    // Need only because method is declared abstract.
  }

  /**
   * @inherit
   */
  public function writeErrors() {
    global $user;

    // Load or create a new file entity.
    if ($file = $this->errorFile()) {
      return $file->uri;
    }

    $file = new stdClass();
    $file->uid = $user->uid;
    $file->uri = $this->errorUri;

    // Write the CSV.
    $fh = fopen($this->errorUri, 'w');
    $header = array(
      t('School Name'),
      t('Contact E-mail'),
      t('Error Message'),
    );
    fputcsv($fh, $header);

    $errors = $this->recordFiles('error');

    foreach ($errors as $line_no) {
      $record = $this->loadRecord('error', $line_no);
      $line = $record->line;
      $line[] = implode(', ', (array) $record->errors);
      fputcsv($fh, $line);
    }
    fclose($fh);

    // Insert/update the db record.
    file_save($file);

    return $file->uri;
  }


}
