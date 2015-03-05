<?php

/**
 * @file Classes derived from state_flow module & state machine bass classes
 */
class prcWorkflow extends StateFlow {
  public function init() {

    //define states
    $this->create_state('draft',
      array(
        'label' => t('Draft')
      )
    );

    $this->create_state('ready_for_review',
      array(
        'label' => t('Approval Requested')
      )
    );

    $this->create_state('published',
      array(
        'label' => t('Published'),
        'on_enter' => array($this, 'on_enter_published'),
      )
    );

    //unpublished isn't actually a real state, but we need the label for things to work
    $this->create_state('unpublished',
      array(
        'label' => t('Unpublished'),
      )
    );

    //define events
    $this->create_event('approval_requested',
      array(
        'label' => t('Request Approval'),
        'origin' => 'draft',
        'target' => 'ready_for_review',
        'permissions' => array('request approval of prc content'),
        'guard' => 'prc_workflow_user_owns_node',
      )
    );
/*
    $this->create_event('approval_requested_published',
      array(
        'label' => t('Request Approval'),
        'origin' => 'published',
        'target' => 'ready_for_review',
        'permissions' => array('request approval of prc content'),
        'guard' => 'prc_workflow_user_owns_node',
        'actual_event' => 'approval_requested',
      )
    );*/

    $this->create_event('rescind_request',
      array(
        'label' => t('Rescind Request'),
        'origin' => 'ready_for_review',
        'target' => 'draft',
        'permissions' => array('request approval of prc content'),
        'guard' => 'prc_workflow_user_owns_node'
      )
    );

    $this->create_event('approved',
      array(
        'label' => t('Publish'),
        'origin' => 'ready_for_review',
        'target' => 'published',
        'permissions' => array('approve prc content'),
      )
    );

    $this->create_event('republish',
      array(
        'label' => t('Publish'),
        'origin' => 'draft',
        'target' => 'published',
        'permissions' => array('approve prc content'),
      )
    );

    $this->create_event('update_published',
      array(
        'label' => t('Save and Publish'),
        'origin' => 'published',
        'target' => 'published',
        'permissions' => array('approve prc content'),
        'actual_event' => 'republish',
      )
    );

    $this->create_event('denied',
      array(
        'label' => t('Request Change'),
        'origin' => 'ready_for_review',
        'target' => 'draft',
        'permissions' => array('deny prc content'),
      )
    );

    $this->create_event('unpublish',
      array(
        'label' => t('Unpublish'),
        'origin' => 'published',
        'target' => 'draft',
        'permissions' => array('unpublish prc content'),
      )
    );

    $this->set_initial_state('draft');
  }

  /**
   * Extending fire_event() from state_machine's base.inc to add uid and log
   * arguments.
   */
  public function fire_event($key, $uid = NULL, $log = '') {
    $event = $this->get_event($key);

    if ($event && ($new_state = $event->execute())) {
      // Allow the previous state to run its 'on_exit' callbacks.
      $this->get_state($this->get_current_state())->on_exit();

      // Set and save the new state.
      $this->set_current_state($new_state);
      $this->persist();

      // Write a history record for this state change.
      if (empty($uid)) {
        global $user;
        $uid = $user->uid;
      }
      $this->write_history($uid, $log);

      // Allow the new state to run its 'on_enter' callbacks.
      $this->get_state($this->get_current_state())->on_enter();

      // Allow the event to "finish".
      $event->finish();

      //Get the new version of our object
      $this->update_object($new_state);

      // Allow state_flow to provide other hooks or event triggers.
      state_flow_invoke_event_handlers($this, $key, $uid, $log);
    }
    else {
      $this->on_event_fail($event);
      return FALSE;
    }
  }

  function update_object($new_state){
    $this->object = prc_workflow_fetch_latest_node_version_by_state($this->object->nid, $new_state);
  }

  /**
   * Force a particular state skipping validation and triggered actions.
   * Useful for testing purposes, and for creating a draft with the same
   * state as the previous version.
   *
   * @param $state
   */
  public function force_state($state){
    // Set and save the new state.
    $this->set_current_state($state);
    $this->persist();
  }
}