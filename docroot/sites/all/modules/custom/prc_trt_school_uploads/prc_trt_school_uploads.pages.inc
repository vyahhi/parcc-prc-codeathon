<?php

/**
 * @file
 * PRC TRT School Uploads page callbacks.
 */

/**
 * Page callback for uploading school data.
 */
function prc_trt_school_uploads_upload_page($district, $type) {

  $file = PrcTrtSchoolUploadsFile::getInstance($type);
  $file->district_id = $district->nid;
  switch ($file->status()) {
    case 'validate':
      drupal_set_title(t('File Import Status'));
      return drupal_get_form('prc_trt_school_uploads_upload_validate_form', $file, $type, $district);

    case 'complete':
      // We skip completion and automatically go to Manage Schools.
      return drupal_get_form('prc_trt_school_uploads_upload_form', $type, $district);
  }

  // Waiting for a file upload.
  return drupal_get_form('prc_trt_school_uploads_upload_form', $type, $district);
}

/**
 * Form for uploading schools.
 */
function prc_trt_school_uploads_upload_form($form, &$form_state, $type, $district) {

  $form['#org'] = $district;
  $form['#file_type'] = $type;

  $form['overview'] = array(
    '#type' => 'item',
    '#markup' => '<p>' . t('Use this upload tool to bulk enter school information.') . '</p><br>',
  );
  $form['note'] = array(
    '#type' => 'item',
    '#markup' => '<p>' . t('To upload multiple schools, use Excel or another spreadsheet program and create a two-column .csv file. There must be two columns: the first for the school name and the second for the school contact email address; the first row of the spreadsheet is treated as a header and its contents are ignored. Make sure to save the file as a .csv. Lastly, upload your schools using this interface.') . '</p><p>' . t('You also might be able to have your school’s student information system generate the .csv file for you and save even more time.') . '</p><p>' . t('Note: School names must be unique within a district, and once submitted, a school with data cannot be deleted. The data will be checked by the TRT before being accepted.')  . '</p>',
  );
  $form['required_message'] = array(
    '#type' => 'item',
    '#markup' => '* indicates required field',
  );

  $form['contents']['file'] = array(
    '#label' => t('File Name'),
    '#description' => t('File must have .csv extension and have two columns in this order: School Name, School Contact\'s Email Address. The first row is treated as a header and its contents are ignored, and the naming of the columns is ignored.'),
    '#title' => t('File Name'),
    '#type' => 'managed_file',
    '#required' => TRUE,
    '#upload_validators' => array(
      'file_validate_extensions' => array('csv'),
    ),
    '#hide_button' => TRUE,
  );

  $form['actions'] = array(
    '#type' => 'actions',
    '#weight' => 100,
  );

  $form['actions']['upload'] = array(
    '#type' => 'submit',
    '#value' => t('Upload'),
    '#submit' => array('prc_trt_school_uploads_upload_form_upload'),
  );

  $form['#attached']['css'][] = drupal_get_path('module', 'prc_trt_school_uploads') . '/prc_trt_school_uploads.css';

  return $form;
}

/**
 * Submit callback for Upload button on prc_trt_school_uploads_upload_form.
 */
function prc_trt_school_uploads_upload_form_upload($form, &$form_state) {
  $upload = file_load($form_state['values']['file']);
  $file = PrcTrtSchoolUploadsFile::getInstance($form['#file_type']);
  $file->upload($upload);

  $distrinct_nid = $form_state['build_info']['args'][1]->nid;

  $batch = array(
    'title' => t('Processing Upload'),
    'operations' => array(
      array('prc_trt_school_uploads_validation_batch', array($form['#file_type'], $distrinct_nid)),
    ),
    'progress_message' => t('@elapsed elapsed, @estimate remaining.'),
    'file' => drupal_get_path('module', 'prc_trt_school_uploads') . '/prc_trt_school_uploads.batch.inc',
  );

  batch_set($batch);
}

/**
 * Validation form for uploaded files.
 */
function prc_trt_school_uploads_upload_validate_form($form, &$form_state, $file, $type, $org) {

  $form['#file'] = $file;
  $form['#org'] = $org;
  $form['#file_type'] = $type;

  $upload = $file->dataFile();
  $valid_count = count($file->recordFiles('valid'));
  $error_count = count($file->recordFiles('error'));
  $red = '';

  if ($error_count != 0) {
    $red = 'red';
    $form['preheader'] = array(
      '#prefix' => '<div class="row pre-header">',
      '#suffix' => '</div>',
    );
    $form['preheader']['text'] = array(
      '#prefix' => '<div class="medium-12 large-12 columns">',
      '#suffix' => '</div>',
    );
    $form['preheader']['text'][] = array(
      '#markup' => t('Some records could not be uploaded. Please select one of the actions below.'),
      '#prefix' => '<h5 class="red">',
      '#suffix' => '</h5>',
    );

  }
  $form['header'] = array(
    '#prefix' => '<div class="row header">',
    '#suffix' => '</div>',
  );
  $form['header']['text'] = array(
    '#prefix' => '<div class="medium-12 large-12 columns">',
    '#suffix' => '</div>',
  );
  $form['header']['text'][] = array(
    '#markup' => t('Upload @type_of_file File "@file"', array(
      '@type_of_file' => t('Schools'),
      '@file' => $upload->filename,
    )),
    '#prefix' => '<h3>',
    '#suffix' => '</h3>',
  );
  $form['header']['text'][] = array(
    '#markup' => t('Total records in file: !count', array('!count' => $valid_count + $error_count)),
    '#prefix' => '<h4>',
    '#suffix' => '</h4>',
  );

  $form['results'] = array(
    '#prefix' => '<div class="row results">',
    '#suffix' => '</div>',
  );

  $form['results']['valid'] = array(
    '#prefix' => '<div class="medium-6 large-6 columns valid">',
    '#suffix' => '</div>',
    'text' => array(),
  );
  $form['results']['valid']['text'][] = array(
    '#markup' => t('Accepted Records: !count', array('!count' => $valid_count)),
    '#prefix' => '<h4>',
    '#suffix' => '</h4>',
  );
  $form['results']['valid']['text'][] = array(
    '#markup' => t('The Accepted records are the data rows in your file that meet the validation step, and are ready to be created in the System.'),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );
  if ($valid_count && !$error_count) {
    $text = $type == t('School Records');
    $args = array(
      ':text' => $text,
      '!count' => $valid_count,
    );
    $form['results']['valid']['text'][] = array(
      '#markup' => t('Please select Create :text to create the "!count" records that passed the data validation criteria.', $args),
      '#prefix' => '<h5>',
      '#suffix' => '</h5>',
    );

    $text = t('Create School Records');
    $form['results']['valid']['start'] = array(
      '#type' => 'submit',
      '#value' => $text,
      '#html' => TRUE,
      '#disabled' => !$valid_count,
      '#submit' => array('prc_trt_school_uploads_upload_validate_form_start'),
      '#attributes' => array(
        'class' => array('standout'),
      ),
    );
  }

  $form['results']['invalid'] = array(
    '#prefix' => '<div class="medium-6 large-6 columns invalid">',
    '#suffix' => '</div>',
    'text' => array(),
  );
  $form['results']['invalid']['text'][] = array(
    '#markup' => t('Rejected Records: !count', array('!count' => '<span class="' . $red . '">' . $error_count . '</span>')),
    '#prefix' => '<h4>',
    '#suffix' => '</h4>',
  );
  $form['results']['invalid']['text'][] = array(
    '#markup' => t('Rejected records are the ones that could not be created due to a data error.'),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );

  if ($error_count) {
    $args = array(
      ':text' => t('View Errors'),
      '!count' => $error_count,
    );
    $form['results']['invalid']['text'][] = array(
      '#markup' => t('Please select :text to view the "!count" records that could not be uploaded.', $args),
      '#prefix' => '<h5>',
      '#suffix' => '</h5>',
    );

    $arg = 'schools';
    $form['results']['invalid']['errors'] = array(
      '#theme' => 'link',
      '#text' => t('View Errors'),
      '#path' => "district/{$org->nid}/upload-$arg/error",
    );
    $form['results']['invalid']['errors']['#options']['attributes']['class'][] = 'button secondary';
    $form['results']['invalid']['errors']['#options']['html'] = FALSE;
  }

  $form['results']['cancel'] = array(
    '#prefix' => '<div class="medium-12 large-12 columns cancel">',
    '#suffix' => '</div>',
  );
  $form['results']['cancel']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Back to Re-upload'),
    '#html' => TRUE,
    '#submit' => array('prc_trt_school_uploads_upload_validate_form_cancel'),
  );

  $form['#attached']['css'][] = drupal_get_path('module', 'prc_trt_school_uploads') . '/prc_trt_school_uploads.css';

  return $form;
}

/**
 * Submit callback for Cancel button on prc_trt_school_uploads_upload_validate_form.
 */
function prc_trt_school_uploads_upload_validate_form_cancel(&$form, &$form_state) {
  $file = $form['#file'];
  $file->clear();
}

/**
 * Submit callback for start button on file validation form.
 */
function prc_trt_school_uploads_upload_validate_form_start(&$form, &$form_state) {
  $distrinct_nid = $form_state['build_info']['args'][2]->nid;

  $batch = array(
    'title' => t('Processing Upload'),
    'operations' => array(
      array('prc_trt_school_uploads_creation_batch', array($form['#file_type'], $distrinct_nid)),
    ),
    'progress_message' => t('@elapsed elapsed, @estimate remaining.'),
    'finished' => 'prc_trt_school_uploads_creation_batch_complete',
    'file' => drupal_get_path('module', 'prc_trt_school_uploads') . '/prc_trt_school_uploads.batch.inc',
  );

  batch_set($batch);
}

/**
 * Generates content for the upload confirmation page.
 */
function prc_trt_school_uploads_complete_form($form, &$form_state, $file, $type, $district) {

  $form['#file'] = $file;
  $form['#district'] = $district;

  $complete = $file->recordFiles('complete');
  $errors = $file->recordFiles('error');

  // Slightly different copy based on upload type.
  if ($type == 'school') {
    $args = array('!count' => count($file->recordFiles('complete')));
    $form['sub'] = array(
      '#markup' => t('"!count" school records were created successfully.', $args),
      '#prefix' => '<h2>',
      '#suffix' => '</h2>',
    );
    $form['list'] = array(
      '#theme' => 'item_list',
    );
    $form['list']['#items'][] = t('New schools have been created.');
  }


  if ($errors) {
    $args = array(
      '!invalid' => count($errors),
      '!total' => count($errors) + count($complete),
      '!link' => l(t('export rejected records'), file_create_url($file->writeErrors())),
    );
    $form['errors'][] = array(
      '#markup' => t('Note that "!invalid" out of "!total" rejected records were not created in the System. You can !link to correct and re-upload them later. Beyond this page, the system will not keep track of them.', $args),
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
  }

  // Action buttons.
  $form['actions'] = array(
    '#type' => 'actions',
    '#weight' => 100,
  );

  // Back button.
  $text = t('Manage Schools');
  $form['actions']['back'] = array(
    '#type' => 'submit',
    '#value' => t('Go to !text Page', array('!text' => $text)),
    '#submit' => array('prc_trt_school_uploads_complete_form_back'),
  );

  // Conditionally displayed view errors button/link.
  if ($file->recordFiles('error')) {
    $arg = 'schools';
    $district_id = $district->nid;
    $form['actions']['errors'] = array(
      '#theme' => 'link',
      '#text' => t('View Rejected Records'),
      '#path' => "organization/$district_id/upload/$arg/error",
    );
    $form['actions']['errors']['#options']['attributes']['class'] = 'button';
    $form['actions']['errors']['#options']['html'] = FALSE;
  }

  return $form;
}

/**
 * Submit callback for "back" button on prc_trt_school_uploads_complete_form.
 */
function prc_trt_school_uploads_complete_form_back(&$form, &$form_state) {
  $form['#file']->clear();
  $nid = $form_state['build_info']['args'][2]->nid;
//  $form['#redirect'] = 'node/' . $nid . '/manage-schools';
  $form_state['redirect'] = 'node/' . $nid . '/manage-schools';
}

/**
 * Form for handling upload file errors.
 */
function prc_trt_school_uploads_upload_error_form($form, &$form_state, $district, $type) {

  $file = PrcTrtSchoolUploadsFile::getInstance($type);

  $form['#file'] = $file;
  $form['#district'] = $district;
  $form['#type'] = $type;

  $errors = $file->recordFiles('error');

  $args['!count'] = count($errors);

  $form['text'] = array(
    '#markup' => t('There are "!count" rejected records. Please correct the data and re-upload later.', $args),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );

  switch ($type) {
    case 'school':
    default:
      $form['table'] = prc_trt_school_uploads_upload_error_schools($file);
  }

  $form['top_actions'] = array(
    '#type' => 'actions',
    '#weight' => -100,
  );

  $form['actions'] = array(
    '#type' => 'actions',
    '#weight' => 100,
  );

  $arg = 'schools';
  $action_array['cancel'] = array(
    '#theme' => 'link',
    '#text' => t('Back'),
    '#path' => "district/{$district->nid}/upload-$arg",
  );
  $action_array['cancel']['#options']['attributes']['class'][] = 'button secondary';
  $action_array['cancel']['#options']['html'] = FALSE;

  foreach ($action_array as $action_key => $item) {
    $form['top_actions']["top_$action_key"] = $item;
    $form['actions'][$action_key] = $item;
  }

  return $form;
}

/**
 * Generates the table data for erroneous schools.
 */
function prc_trt_school_uploads_upload_error_schools($file) {
  $error_records = $file->recordFiles('error');

  $header = array(
    t('School Name'),
    t('School Contact E-mail'),
    t('Error Message'),
  );

  $rows = array();
  foreach ($error_records as $record) {
    $record = $file->loadRecord('error', $record);
    $row = array();
    foreach ($record->line as $cell) {
      $row[] = check_plain($cell);
    }
    $errors = implode(', ', (array) $record->errors);
    $errors = "<span class=\"error\">$errors</span>";
    $row[] = $errors;

    $rows[] = $row;
  }

  return array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('There are no rejected records to display.'),
  );
}

/**
 * Submit callback for export button on prc_trt_school_uploads_upload_error_form.
 */
function prc_trt_school_uploads_upload_error_form_export($form, &$form_state) {
  // Generate the CSV of erroneous records and redirect user to that file.
  $file = $form['#file'];
  $form_state['redirect'] = file_create_url($file->writeErrors());
}
