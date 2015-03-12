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

  switch ($file->status()) {
    case 'validate':
      drupal_set_title(t('Checking Data Status'));
      return drupal_get_form('prc_trt_school_uploads_upload_validate_form', $file, $type, $district);

    case 'complete':
      $text = ($type == 'student') ? t('Create Students Confirmation') : t('Create User Accounts Confirmation');
      drupal_set_title($text);
      return drupal_get_form('prc_trt_school_uploads_complete_form', $file, $type);
  }

  // Waiting for a file upload.
  return drupal_get_form('prc_trt_school_uploads_upload_form', $type, $district);
}

/**
 * Form for uploading students and users.
 */
function prc_trt_school_uploads_upload_form($form, &$form_state, $type, $district) {

  $form['#org'] = $district;
  $form['#file_type'] = $type;

  $form['overview'] = array(
    '#type' => 'item',
    '#markup' => 'Overview / instructional copy. Consider explaining that for each school, there must be two columns: one for school name and one for school contact email address and that file must be .csv.',
  );
  $form['note'] = array(
    '#type' => 'item',
    '#markup' => 'Note that user will be allowed only one upload per school.',
  );
  $form['required_message'] = array(
    '#type' => 'item',
    '#markup' => '* indicates required field',
  );

  $form['contents']['file'] = array(
    '#label' => t('File Name'),
    '#description' => t('File must have .csv extension and have the following columns in this order: School Name, School Contact\'s Email Address'),
    '#title' => NULL,
    '#type' => 'file',
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

  $batch = array(
    'title' => t('Processing Upload'),
    'operations' => array(
      array('prc_trt_school_uploads_validation_batch', array($form['#file_type'])),
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
      '@type_of_file' => ($type == 'student') ? t('Enrollment') : t('Users'),
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
  if ($valid_count) {
    $text = $type == 'student' ? t('Student Records') : t('User Accounts');
    $args = array(
      ':text' => $text,
      '!count' => $valid_count,
    );
    $form['results']['valid']['text'][] = array(
      '#markup' => t('Please select Create :text to create the "!count" records that passed the data validation criteria.', $args),
      '#prefix' => '<h5>',
      '#suffix' => '</h5>',
    );
  }
  $text = ($type == 'student')
    ? t('<strong>Create Student Records</strong>')
    : t('<strong>Create User Accounts</strong>');
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
  }

  if ($error_count) {
    $arg = $type == 'student' ? 'enrollment' : 'users';
    $form['results']['invalid']['errors'] = array(
      '#theme' => 'link',
      '#text' => t('View Errors'),
      '#path' => "organization/{$org['org_id']}/upload/$arg/error",
    );
    $form['results']['invalid']['errors']['#options']['attributes']['class'][] = 'button secondary';
    $form['results']['invalid']['errors']['#options']['html'] = FALSE;
  }
  else {
    $form['results']['invalid']['errors'] = array(
      '#markup' => t('View Errors'),
      '#prefix' => '<div class="button disabled">',
      '#suffix' => '</div>',
    );
  }

  $form['results']['cancel'] = array(
    '#prefix' => '<div class="medium-12 large-12 columns cancel">',
    '#suffix' => '</div>',
  );
  $form['results']['cancel']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('<strong>Cancel</strong><br />Back to Re-upload'),
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
  $batch = array(
    'title' => t('Processing Upload'),
    'operations' => array(
      array('prc_trt_school_uploads_creation_batch', array($form['#file_type'])),
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
function prc_trt_school_uploads_complete_form($form, &$form_state, $file, $type) {

  $form['#file'] = $file;

  $complete = $file->recordFiles('complete');
  $errors = $file->recordFiles('error');

  // Slightly different copy based on upload type.
  if ($type == 'student') {
    $args = array('!count' => count($file->recordFiles('complete')));
    $form['sub'] = array(
      '#markup' => t('"!count" student records were created successfully.', $args),
      '#prefix' => '<h2>',
      '#suffix' => '</h2>',
    );
    $form['list'] = array(
      '#theme' => 'item_list',
    );
    $form['list']['#items'][] = t('You can access the new student records and complete their profile.');
  }
  else {
    $args = array('!count' => count($file->recordFiles('complete')));
    $form['sub'] = array(
      '#markup' => t('"!count" user accounts were created successfully.', $args),
      '#prefix' => '<h2>',
      '#suffix' => '</h2>',
    );
    $form['list'] = array(
      '#theme' => 'item_list',
    );
    $form['list']['#items'][] = t('The new users just received an email to their email addresses.');
    $form['list']['#items'][] = t('New users are provided with a temporary URL where they can set up their own passwords in the System.');
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
  $text = $type == 'student' ? t('Enrollment') : t('Users');
  $form['actions']['back'] = array(
    '#type' => 'submit',
    '#value' => t('Go to !text Page', array('!text' => $text)),
    '#submit' => array('prc_trt_school_uploads_complete_form_back'),
  );

  // Conditionally displayed view errors button/link.
  if ($file->recordFiles('error')) {
    $arg = $type == 'student' ? 'enrollment' : 'users';
    $form['actions']['errors'] = array(
      '#theme' => 'link',
      '#text' => t('View Rejected Records'),
      '#path' => "organization/1/upload/$arg/error",
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
}

/**
 * Form for handling upload file errors.
 */
function prc_trt_school_uploads_upload_error_form($form, &$form_state, $org, $type) {

  $file = PrcTrtSchoolUploadsFile::getInstance($type);

  $form['#file'] = $file;
  $form['#org'] = $org;
  $form['#type'] = $type;

  $errors = $file->recordFiles('error');

  $args['!count'] = count($errors);

  $form['text'] = array(
    '#markup' => t('There are "!count" rejected records. Please correct the data and re-upload later.', $args),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );

  switch ($type) {
    case 'student':
      $form['table'] = prc_trt_school_uploads_upload_error_enroll($file);
      break;

    default:
      $form['table'] = prc_trt_school_uploads_upload_error_users($file);
  }

  /* NCSCCTB-2329 AC#3, Export/Cancel action buttons appear above and below table */
  $form['top_actions'] = array(
    '#type' => 'actions',
    '#weight' => -100,
  );

  $form['actions'] = array(
    '#type' => 'actions',
    '#weight' => 100,
  );

  $action_array = array(
    'export' => array(
      '#type' => 'submit',
      '#value' => t('Export'),
      '#submit' => array('prc_trt_school_uploads_upload_error_form_export'),
    ),
  );
  $arg = $type == 'student' ? 'enrollment' : 'users';
  $action_array['cancel'] = array(
    '#theme' => 'link',
    '#text' => t('Cancel'),
    '#path' => "organization/{$org['org_id']}/upload/$arg",
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
 * Generates the table data for erroneous users.
 */
function prc_trt_school_uploads_upload_error_users($file) {
  $error_records = $file->recordFiles('error');

  $header = array(
    t('Org ID'),
    t('Org Name'),
    t('Role'),
    t('First Name'),
    t('Last Name'),
    t('Title'),
    t('Email'),
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
 * Generates the table data for erroneous enrollment records.
 */
function prc_trt_school_uploads_upload_error_enroll($file) {
  $error_records = $file->recordFiles('error');

  $header = array(
    t('Org Id'),
    t('Org Name'),
    t('Student ID'),
    t('Student First Name'),
    t('Student Last Name'),
    t('Current Grade'),
    t('Error Message'),
  );

  $rows = array();
  foreach ($error_records as $record) {
    $record = $file->loadRecord('error', $record);
    $row = array();
    foreach ($record->line as $key => $cell) {
      // Only use specific columns in this display.
      if (!in_array($key, array(
        4,
        7,
        8,
        9,
        10,
        11,
        12,
        13,
        14,
        15,
        16,
        17,
        18,
        19,
        20,
        21,
        22,
        23,
        24,
      ))
      ) {
        $row[] = check_plain($cell);
      }
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
