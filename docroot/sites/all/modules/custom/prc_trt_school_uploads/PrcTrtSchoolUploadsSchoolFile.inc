<?php
/**
 * @file
 * Class definition of TapUploadsStudentFile
 */

class PrcTrtSchoolUploadsSchoolFile extends PrcTrtSchoolUploadsFile {

  // Declare the upload type.
  protected $type = 'student';

  /**
   * @inherit
   */
  protected function parseLine($data) {
    // Ensure array has exactly 25 elements.
    $data['line'] = array_pad($data['line'], 25, '');
    $data['line'] = array_slice($data['line'], 0, 25);

    $record = new stdClass();
    $record->line = $data['line'];
    $record->lineNo = $data['line_no'];

    $record->org_id = trim($data['line'][0]);
    $record->org_name = trim($data['line'][1]);

    $record->id = trim($data['line'][2]);
    $record->first = trim($data['line'][3]);
    $record->middle = trim($data['line'][4]);
    $record->last = trim($data['line'][5]);

    // Demographics.
    $record->grade = trim($data['line'][6]);
    $record->dob = trim($data['line'][7]);
    $record->gender = trim(strtoupper($data['line'][8]));

    // Race data.
    $record->ethnicity = array();
    $record->ethnicity['ethnicityHispanicLatino'] = $this->processBoolCol($data['line'][9]);
    $record->race = array();
    $record->race['ethnicityIndian'] = $this->processBoolCol($data['line'][10]);
    $record->race['ethnicityAsian'] = $this->processBoolCol($data['line'][11]);
    $record->race['ethnicityAfricanAmerican'] = $this->processBoolCol($data['line'][12]);
    $record->race['ethnicityHawaiian'] = $this->processBoolCol($data['line'][13]);
    $record->race['ethnicityWhite'] = $this->processBoolCol($data['line'][14]);

    // LCI data.
    $record->pri_disability = $this->processNumericCol($data['line'][15], array_keys(TapStudent::primaryDisabilityOpts()));
    $record->classroom = $this->processNumericCol($data['line'][16], array_keys(TapStudent::classroomSettingOpts()));
    $record->lci_rec = $this->processNumericCol($data['line'][17], array_keys(TapStudent::receptiveLanguageOpts()));
    $record->lci_expr = $this->processNumericCol($data['line'][18], array_keys(TapStudent::expressiveCommunicationOpts()));

    // Language data.
    $record->el_status = $this->processBoolCol($data['line'][19]);
    // Default to English if it is indicated as the primary language.
    if ($record->el_status) {
      $record->language = $this->processLangCol($data['line'][20]);
    }
    else {
      $record->language = 'eng';
    }

    $record->vision = $this->processBoolCol($data['line'][21]);
    $record->hearing = $this->processBoolCol($data['line'][22]);
    $record->braille = $this->processBoolCol($data['line'][23]);
    $record->oralSpeech = $this->processBoolCol($data['line'][24]);

    return $record;
  }

  /**
   * @inherit
   */
  protected function validateRecord($record, &$validate) {

    // Org checks.
    if (empty($record->org_id)) {
      $record->errors['org_id'] = t('Org ID: Required');
    }
    elseif (!$org = tap_org_load($record->org_id)) {
      $record->errors['org_id'] = t('Org ID: Invalid value specified.');
    }
    elseif (!tap_org_access($record->org_id)) {
      $record->errors['org_id'] = t('Org ID: Not within user\'s access.');
    }
    if (empty($record->org_name)) {
      $record->errors['org_name'] = t('Org Name: Required');
    }
    elseif ($org && strtolower($record->org_name) != strtolower($org['name'])) {
      $record->errors['org_name'] = t('Org Name: Organization name and ID do not match.');
    }

    // Unique student identifier per state.
    if ($org && ($state = tap_org_parents($org, ORG_LEVEL_STATE))) {
      if (!empty($validate['student_identifiers'][$state['org_id']][$record->id])) {
        $record->errors['student_id'] = t('Student Identifier: Duplicate student identifier in upload.');
      }
      $validate['student_identifiers'][$state['org_id']][$record->id] = TRUE;
    }

    if ($org && $org['level'] < ORG_LEVEL_SCHOOL) {
      $record->errors['org_level'] = t('Org Level: Students may not be assigned to states or districts.');
    }

    if (!strtotime($record->dob)) {
      $record->errors['dob_invalid'] = t('DOB: Invalid value.');
    }

    if (!empty($record->gender) && !in_array($record->gender, array('M', 'F'))) {
      $record->errors['dob_invalid'] = t('Gender: Invalid value.');
    }

    if (!in_array($record->grade, array(3, 4, 5, 6, 7, 8, 11))) {
      $record->errors['grade_invalid'] = t('Grade: Invalid value, accepted grades are 3, 4, 5, 6, 7, 8, 11.');
    }

    if (empty($record->pri_disability) && !empty($record->line[15])) {
      $record->errors['pri_disability'] = t('Primary disability type: Invalid value specified.');
    }

    if (empty($record->classroom) && !empty($record->line[16])) {
      $record->errors['classroom'] = t('Classroom setting: Invalid value specified.');
    }

    if (empty($record->lci_rec) && !empty($record->line[17])) {
      $record->errors['lci_rec'] = t('Receptive communication: Invalid value specified.');
    }

    if (empty($record->lci_expr) && !empty($record->line[18])) {
      $record->errors['lci_expr'] = t('Expressive communication: Invalid value specified.');
    }

    if (!empty($record->el_status) && empty($record->line[20])) {
      $record->errors['language_pri'] = t('Language: Primary language not specified.');
    }

    if (empty($record->language) && !empty($record->line[20])) {
      $record->errors['language'] = t('Language: Invalid value specified.');
    }

    if ($record->vision === NULL && $record->line[21] != '') {
      $record->errors['vision'] = t('Vision: Invalid value specified.');
    }

    if ($record->hearing === NULL && $record->line[22] != '') {
      $record->errors['hearing'] = t('Hearing: Invalid value specified.');
    }

    if ($record->braille === NULL && $record->line[23] != '') {
      $record->errors['braille'] = t('Braille: Invalid value specified.');
    }

    if ($record->oralSpeech === NULL && $record->line[24] != '') {
      $record->errors['oralSpeech'] = t('Oral Speech: Invalid value specified.');
    }

  }

  /**
   * @inherit
   */
  protected function validateRecords($records, &$validate) {

    // Add in all of the student records.
    $data = array();
    foreach ($records as $record) {
      $data[$record->lineNo] = $this->buildStudent($record);
    }
    $data = array_filter($data);
    $response = TapStudent::AddSet($data, TRUE);

    // No errors, nothing to do.
    if (empty($response['errors'])) {
      return;
    }

    // If we encountered errors, append them to the records.
    foreach ($response['errors'] as $id => $error) {
      $records[$id]->errors['ldr_' . $error['code']] = check_plain($error['detail']);
    }

    // @todo: Unset LDR errors we're already aware of.

  }

  /**
   * Build a TapStudent object from an uploaded record.
   */
  protected function buildStudent($record) {
    $student = new TapStudent();

    $student->studentIdentifier = $record->id;
    $student->organizationId = $record->org_id;

    $student->firstName = $record->first;
    $student->middleName = $record->middle;
    $student->lastName = $record->last;

    $student->ethnicity = (array) $record->ethnicity;
    $student->race = (array) $record->race;

    if (!empty($record->grade)) {
      $student->grade = $record->grade;
    }
    if (!empty($record->gender)) {
      $student->gender = $record->gender;
    }
    if (!empty($record->dob)) {
      $student->dateOfBirth = $record->dob;
    }

    $student->grade = !empty($record->grade) ? $record->grade : NULL;
    $student->dateOfBirth = !empty($record->dob) ? $record->dob : NULL;

    if (!empty($record->pri_disability)) {
      $student->primaryDisability = $record->pri_disability;
    }
    if (!empty($record->classroom)) {
      $student->classroomSetting = $record->classroom;
    }
    if (!empty($record->lci_rec)) {
      $student->receptiveLanguage = $record->lci_rec;
    }
    if (!empty($record->lci_expr)) {
      $student->expressiveCommunication = $record->lci_expr;
    }

    // Language handling.
    if ($record->el_status !== NULL) {
      $student->elStatus = (int) $record->el_status + 1;
    }
    if ($record->language) {
      $student->primaryLanguage = $record->language;
    }

    $student->vision = !empty($record->vision) ? 4 : NULL;
    $student->hearing = !empty($record->hearing) ? 4 : NULL;

    if ($record->braille !== NULL) {
      $student->usesBraille = $record->braille + 1;
    }
    if ($record->oralSpeech !== NULL) {
      $student->usesOralSpeech = $record->oralSpeech + 1;
    }

    return $student;
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
        $data[$record_no] = $this->buildStudent($record);
      }
    }

    $response = TapStudent::AddSet($data);

    // Analyze the response and set each record to complete or errored.
    foreach ($records as $record) {
      if (empty($response['errors'][$record->lineNo])) {
        $this->saveRecord($record, 'complete');
      }
      else {
        $error = $response['errors'][$record->lineNo];
        $record->errors['ldr_' . $error['code']] = $error['detail'];
        $this->saveRecord($record, 'error');
      }
    }

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
      t('Org Id'),
      t('Org Name'),
      t('Student ID'),
      t('Student First Name'),
      t('Student Middle Name'),
      t('Student Last Name'),
      t('Current Grade'),
      t('DOB'),
      '',
      '',
      '',
      '',
      '',
      '',
      '',
      '',
      '',
      '',
      '',
      '',
      '',
      '',
      '',
      '',
      '',
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

  /**
   * Converts a Yes/No column into a usable value.
   *
   * @param string $value
   *   Case insensitive 'yes', 'y', 'no', or 'n' value, or empty string.
   *
   * @return bool|null
   *   Boolean representation for the value, TRUE/FALSE/NULL.
   */
  protected static function processBoolCol($value) {
    switch (strtolower(trim($value))) {
      case 'yes':
      case 'y':
        return TRUE;

      case 'no':
      case 'n':
        return FALSE;

    }
    return NULL;
  }

  /**
   * Cleans up numeric input.
   *
   * @param int $value
   *   The value read from the uploaded CSV.
   * @param array $allowed
   *   An optional array of allowed values.
   *
   * @return int|null
   *   The resulting value, or NULL.
   */
  protected function processNumericCol($value, $allowed = NULL) {
    $value = trim($value);

    if ($value == '') {
      return NULL;
    }

    // If an allowed array was passed in, filter.
    if ($allowed) {
      if (!in_array($value, $allowed)) {
        return NULL;
      }
    }

    return (int) $value;
  }

  /**
   * Ensures a language value matches a valid language option.
   *
   * @param string $lang
   *  A raw language value as read from CSV upload.
   *
   * @return null|string
   *  The LDR acceptable language value.
   */
  protected static function processLangCol($lang) {
    $allowed = array_keys(TapStudent::primaryLanguageOpts());
    $lang = strtolower(trim($lang));
    $exclude_langs = array('oth' => 'other');
    $langs = array_diff_key(TapStudent::primaryLanguageOpts(), $exclude_langs);
    return (in_array($lang, array_keys($langs))) ? $lang : NULL;
  }

}
