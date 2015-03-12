<?php

/**
 * @file
 * PRC TRT Uploads batch operation callbacks.
 */

/**
 * Batch operation to parse and validate an upload.
 */
function prc_trt_school_uploads_validation_batch($type, $district_id, &$context) {

  $file = PrcTrtSchoolUploadsFile::getInstance($type);
  $file->district_id = $district_id;
  $data_file = $file->dataFile();

  if (empty($context['sandbox'])) {
    $context['sandbox']['offset'] = 0;
    $context['sandbox']['length'] = filesize($data_file->uri);
    $context['sandbox']['lines'] = 0;
    $context['sandbox']['validate'] = array();
  }

  // If we've already been reading the file, start where we left off. Otherwise,
  // read the first line (header) and ignore it.
  $fh = fopen($data_file->uri, 'r');
  if ($context['sandbox']['offset']) {
    fseek($fh, $context['sandbox']['offset']);
  }
  else {
    fgetcsv($fh);
  }

  // Iterate over the CSV, perform initial processing.
  $count = 0;
  $lines = array();
  while (!feof($fh) && $count++ < $file->batchSize()) {
    $line = fgetcsv($fh);
    $context['sandbox']['lines']++;
    if (!empty($line)) {
      $data = array(
        'line_no' => $context['sandbox']['lines'],
        'line' => $line,
      );
      $lines[] = $data;
    }
  }
  $file->parseLines($lines, $context['sandbox']['validate']);

  // Track where we left off reading the file and close it.
  $context['sandbox']['offset'] = ftell($fh);
  if (!feof($fh)) {
    $context['finished'] = $context['sandbox']['offset'] / $context['sandbox']['length'];
  }
  else {
    // If we're done update the status.
    $file->writeStatus('validate');
  }
  fclose($fh);
}

/**
 * Batch operation for upload entity creation.
 *
 * The term "entity" is used loosely, it may or may not refer to literal Drupal
 * entities.
 */
function prc_trt_school_uploads_creation_batch($type, &$context) {

  $file = PrcTrtSchoolUploadsFile::getInstance($type);

  if (empty($context['sandbox'])) {
    $context['sandbox']['lines'] = $file->recordFiles('valid');
    $context['sandbox']['total'] = count($context['sandbox']['lines']);
    $context['sandbox']['validate'] = array();
  }

  // Process the next batch of records.
  $record_nos = array_splice($context['sandbox']['lines'], 0, $file->batchSize());
  $file->generateEntities($record_nos, $context['sandbox']['validate']);

  $args = array(
    '!count' => $context['sandbox']['total'] - count($context['sandbox']['lines']),
    '!total' => $context['sandbox']['total'],
  );
  $context['message'] = t('Now processing record !count of !total', $args);

  if (count($context['sandbox']['lines'])) {
    $context['finished'] = 1 - (count($context['sandbox']['lines']) / $context['sandbox']['total']);
  }
  else {
    $file->writeStatus('complete');
  }
}
