<?php
/**
 * @file
 * prc_invite.features.inc
 */

/**
 * Implements hook_default_invite_type().
 */
function prc_invite_default_invite_type() {
  $items = array();
  $items['invite_by_email'] = entity_import('invite_type', '{
    "type" : "invite_by_email",
    "label" : "Invite by e-mail",
    "weight" : 0,
    "argument_keys" : [],
    "argument" : [],
    "invite_sending_controller" : { "invite_by_email" : "invite_by_email" },
    "description" : "Invitation by e-mail.",
    "data" : { "invite_by_email" : { "use_default" : 1, "message_editable" : 0, "replace_tokens" : 0 } },
    "rdf_mapping" : []
  }');
  return $items;
}
