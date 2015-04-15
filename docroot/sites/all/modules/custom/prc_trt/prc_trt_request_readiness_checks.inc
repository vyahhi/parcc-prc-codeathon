<?php

/**
 * and... action!
 * @param $settings
 * @return array
 */
function prc_trt_request_readiness_checks_form($settings) {
  $form = array();

  drupal_set_title(t('Request Readiness Checks'));

  $message_name = 'request_readiness_check';
  $mt = message_type_load($message_name);

  $subject = $mt->message_text[LANGUAGE_NONE][0]['safe_value'];
  //TODO: Replace these with something more elegant
  $subject = str_replace('[message:field-node:title]', '&lt;School Name&gt;', $mt->message_text[LANGUAGE_NONE][0]['safe_value']);
  $body = str_replace('[message:field-comment]', '', $mt->message_text[LANGUAGE_NONE][1]['safe_value']);
  $body = str_replace('[message:field-node:url]', '', $body);

  $to_schools = array();
  foreach ($settings['view']->result as $id => $result) {
    $school_nid = $result->nid;
    foreach($_POST['views_bulk_operations'] as $index => $nid) {
      if ($nid == $school_nid) {
        $to_schools[] = $result->node_title;
      }
    }
  }

  $to_schools_text = implode(', ', $to_schools);

  $form['to_schools'] = array(
    '#type' => 'item',
    '#title' => 'To:',
    '#markup' => $to_schools_text,
  );

  $form['subject'] = array(
    '#type' => 'item',
    '#title' => 'Subject:',
    '#markup' => $subject,
  );

  $form['body'] = array(
    '#type' => 'item',
    '#title' => 'Message:',
    '#markup' => $body,
  );

  $form['comment'] = array(
    '#description' => t(''),
    '#weight' => '1',
    '#type' => 'textarea',
    '#title' => t('Additional Comments (optional):'),
  );

  return $form;
}

function prc_trt_request_readiness_checks_validate($form, &$form_state) {
  // This one is pretty easy. There really is nothing to validate.
}

function prc_trt_request_readiness_checks_submit($form, &$form_state) {
  return array(
    'values' => $form_state['values'],
  );

}

function prc_trt_request_readiness_checks(&$node, $context) {
  global $user;
  $message = message_create('request_readiness_check', array('uid' => $user->uid));
  $comment = $context['values']['comment'];
  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_comment->set($comment);
  $wrapper->field_node->set($node);
  $wrapper->save();

  // This message type is associated with roles in prc_emails.
  _prc_emails_message_create($message, $node);
}
