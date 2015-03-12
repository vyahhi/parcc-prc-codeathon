<?php

/**
 * @file
 * Defines Class PrcTrtSchoolUploadsFile.
 */

abstract class PrcTrtSchoolUploadsFile {

  // The base location where a user's files will be saved.
  protected $basePath;

  // URI to a user's uploaded data file.
  protected $dataUri;
  protected $dataDir;

  // URI to a user's errored records file.
  protected $errorUri;
  protected $errorDir;

  // URI to a file we save to signify the upload is complete.
  protected $statusUri;

  // Location where processed record files are stored.
  protected $completeDir;

  // Raw data uploaded from the CSV.
  protected $lines;

  // An array of records read from the CSV.
  protected $records = NULL;

  // The default scheme to use
  protected $scheme;
  protected $target;

  public function __construct() {
    global $user;

    if (empty($this->type)) {
      throw new Exception(t('No file type defined.'));
    }

    $this->scheme = 'private';
    $this->target = 'tap-uploads';
    if (module_exists('amazons3') && variable_get('amazons3_bucket')) {
      $this->scheme = 's3';
      $this->target = variable_get('amazons3_bucket', '') . '/tap-uploads';
    }
    $this->basePath = "{$this->scheme}://{$this->target}/{$user->uid}/{$this->type}";
    $this->dataUri = "{$this->basePath}/data.csv";
    $this->dataDir = "{$this->basePath}/data";
    $this->errorUri = "{$this->basePath}/errors.csv";
    $this->errorDir = "{$this->basePath}/errors";
    $this->statusUri = "{$this->basePath}/status";
    $this->completeDir = "{$this->basePath}/complete";
  }

  /**
   * Reports the status of an upload.
   *
   * @return string
   *   A string representing the current status of the upload process. Possible
   *   values are:
   *
   *     "upload" - Waiting for an upload.
   *     "validate" - User is being prompted with validation information.
   *     "complete" - Creation process complete.
   */
  public function status() {
    if (!is_readable($this->statusUri)) {
      return 'upload';
    }
    return file_get_contents($this->statusUri);
  }

  /**
   * Moves an uploaded file into place.
   *
   * @param stdClass $file
   *   File object that is to be moved into place.
   */
  public function upload($file) {
    // Delete any existing files.
    $this->clear();

    // Prepare the directory to save the file.
    $dir = dirname($this->dataUri);
    file_prepare_directory($dir, FILE_MODIFY_PERMISSIONS || FILE_CREATE_DIRECTORY);

    // Prepare the directories that will hold the data.
    foreach (array(
               $this->dataDir,
               $this->errorDir,
               $this->completeDir
             ) as $dir) {
      file_prepare_directory($dir, FILE_MODIFY_PERMISSIONS || FILE_CREATE_DIRECTORY);
    }

    // Move the new file in.
    file_move($file, $this->dataUri, FILE_EXISTS_REPLACE);
  }

  /**
   * Clear all data files for a the upload.
   */
  public function clear() {
    if ($file = $this->lookupFile($this->dataUri)) {
      file_delete($file);
    }
    if (is_readable($this->dataDir)) {
      file_unmanaged_delete_recursive($this->dataDir);
    }
    if ($file = $this->lookupFile($this->errorUri)) {
      file_delete($file);
    }
    if (is_readable($this->errorDir)) {
      file_unmanaged_delete_recursive($this->errorDir);
    }
    if (is_readable($this->statusUri)) {
      file_unmanaged_delete($this->statusUri);
    }
    if (is_readable($this->completeDir)) {
      file_unmanaged_delete_recursive($this->completeDir);
    }
  }

  /**
   * Provide a user's uploaded data file.
   */
  public function dataFile() {
    return $this->lookupFile($this->dataUri);
  }

  /**
   * Provide a user's errored records file.
   */
  public function errorFile() {
    return $this->lookupFile($this->errorUri);
  }

  /**
   * Parse data read from the CSV upload.
   *
   * This accepts multiple lines, each an array of data with the following info:
   *   - line: An array of CSV data.
   *   - line_no: An integer indicating which line to which it corresponds.
   *
   * @param $lines
   *   An array of uploaded CSV data.
   * @param array $validate
   *   An array available for saving validation data.
   */
  public function parseLines($lines, &$validate) {
    $records = array();
    // Parse and validate individually.
    foreach ($lines as $data) {
      $record = $this->parseLine($data);
      $this->validateRecord($record, $validate);
      $records[$record->lineNo] = $record;
    }
    // Validate the set/subset.
    $this->validateRecords($records, $validate);
    // Save each record.
    foreach ($records as $record) {
      $this->saveRecord($record);
    }
  }

  /**
   * Parse a line as read from CSV into an record object.
   *
   * This is specific to the upload type and is to be implemented by each
   * subclass.
   *
   * @param array $data
   *   A keyed array containing data read from the upload.
   *   - line: An array of CSV data.
   *   - line_no: An integer indicating which line to which it corresponds.
   *
   * @return stdClass
   *   An object representing data read from the uploaded file.
   */
  abstract protected function parseLine($data);

  /**
   * Validates a set of uploaded records.
   *
   * This will be unused except when implemented by a subclass.
   *
   * @param array $records
   *   An array of parsed CSV records.
   * @param array $validate
   *   An array available for saving validation data.
   */
  protected function validateRecords($records, &$validate) {
  }

  /**
   * Validate an uploaded record.
   *
   * This function will perform various checks on the uploaded record and any
   * errors found will be placed into the $record->errors array. The key is a
   * machine name and the value is a textual label visible to the user in the
   * validation and export screens as well as the error CSV.
   *
   * @param stdClass $record
   *   A record parsed from the CSV ready for validation.
   * @param array $validate
   *   An array available for saving validation data.
   */
  abstract protected function validateRecord($record, &$validate);

  /**
   * Generate entities from uploaded record data.
   *
   * @param array $record_nos
   *   Record numbers corresponding to uploaded CSV data.
   * @param array $validate
   *   An array available for saving validation data.
   */
  public function generateEntities($record_nos, &$validate) {

    // Re-parse and re-validate the records.
    $records = array();
    foreach ($record_nos as $record_no) {
      if ($record = $this->loadRecord('valid', $record_no)) {
        $data = array(
          'line_no' => $record->lineNo,
          'line' => $record->line,
        );
        $record = $this->parseLine($data);
        $this->validateRecord($record, $validate);
        $records[] = $record;
      }
    }
    $this->validateRecords($records, $validate);

    // Iterate through the records, attempt to generate and handle errors as
    // needed.
    foreach ($records as $record) {
      // If the record did not validate, move it to errored dir.
      if (!empty($record->errors)) {
        $this->saveRecord($record);
      }
      else {
        try {
          $this->generateEntity($record);
          $this->saveRecord($record, 'complete');
        }
        catch (Exception $e) {
          $this->saveRecord($record, 'error');
        }
      }
    }

  }

  /**
   * Generate an entity from uploaded record data.
   *
   * This is specific to each type of upload, to be implemented by child
   * classes.
   *
   * @param stdClass $record
   *   The record object to be generated into an entity.
   */
  abstract protected function generateEntity($record);

  /**
   * Saves a parsed and validated record to disk.
   * @param $record
   * @param null $dest
   */
  protected function saveRecord($record, $dest = NULL) {
    // Delete existing records.
    foreach (array(
               $this->dataDir,
               $this->errorDir,
               $this->completeDir
             ) as $dir) {
      $filename = "$dir/{$record->lineNo}";
      if (is_readable($filename)) {
        file_unmanaged_delete($filename);
      }
    }

    switch ($dest) {
      case 'valid':
        $dir = $this->dataDir;
        break;

      case 'error':
        $dir = $this->errorDir;
        break;

      case 'complete':
        $dir = $this->completeDir;
        break;

      default:
        $dir = empty($record->errors) ? $this->dataDir : $this->errorDir;
    }

    file_prepare_directory($dir, FILE_MODIFY_PERMISSIONS || FILE_CREATE_DIRECTORY);
    $filename = "$dir/{$record->lineNo}";
    $data = json_encode($record);
    file_unmanaged_save_data($data, $filename);
  }

  /**
   * Writes a data file containing status information.
   * @param null $status
   */
  public function writeStatus($status = NULL) {
    file_put_contents($this->statusUri, $status);
  }

  /**
   * Provides a list of record files.
   *
   * @param string $type
   *   Specifies which type of records to return, "valid",  "error", or
   *   "complete".
   *
   * @return array
   *   An array of records. These are file names which correspond to line
   *   numbers from the original CSV.
   */
  public function recordFiles($type = 'valid') {
    switch ($type) {
      case 'complete':
        $dir = $this->completeDir;
        break;

      case 'error':
        $dir = $this->errorDir;
        break;

      default:
        $dir = $this->dataDir;
    }

    $files = array_diff(scandir($dir), array('.', '..'));
    sort($files, SORT_NUMERIC);

    return $files;
  }

  /**
   * Loads the data file for an uploaded record.
   *
   * @param string $type
   *   Specifies which type of records to return, "valid" or "error".
   * @param int $num
   *   The number of the record. This is the line number from the original CSV.
   *
   * @return stdClass
   *   The loaded record.
   */
  public function loadRecord($type, $num) {
    switch ($type) {
      case 'complete':
        $dir = $this->errorDir;
        break;

      case 'error':
        $dir = $this->errorDir;
        break;

      default:
        $dir = $this->dataDir;
    }
    $uri = "$dir/$num";
    if (is_readable($uri)) {
      return json_decode(file_get_contents($uri));
    }
  }

  /**
   * Writes a CSV containing the upload's errored records.
   *
   * $return string
   *   A string indicating the URI of the exported error file.
   */
  public abstract function writeErrors();

  /**
   * The number of records to process in a single batch iteration.
   *
   * This defaults to 100, but can be set via variables named
   * tap_uploads_[upload_type]_batch_size.
   *
   * @return int
   *   Batch size.
   */
  public function batchSize() {
    $key = "tap_uploads_{$this->type}_batch_size";
    return variable_get($key, 100);
  }

  /**
   * Find a file by URI.
   *
   * @param string $uri
   *   URI of the file to find.
   * @return stdClass
   *   A fully-loaded file object of the file found at the specified URI.
   */
  public static function lookupFile($uri) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'file')
      ->propertyCondition('uri', $uri);
    $result = $query->execute();
    if (!empty($result['file'])) {
      $fid = array_keys($result['file']);
      $fid = reset($fid);
      return file_load($fid);
    }
  }

  public static function getInstance($type) {
    switch ($type) {
      case 'school':
        $file = new PrcTrtSchoolUploadsSchoolFile();
        break;

      default:
        $file = new PrcTrtSchoolUploadsSchoolFile();
    }

    return $file;
  }

}
