<?php

/**
 * @file Classes derived from state_flow module & state machine bass classes
 */
class prcWorkflow extends StateFlow {
  public function init() {

    //define states
    $this->create_state('draft',
      array(
        'label' => t('Private Draft')
      )
    );

    $this->create_state('ready_for_review',
      array(
        'label' => t('Waiting for Review')
      )
    );

    $this->create_state('published',
      array(
        'label' => t('Published')
      )
    );

    //define events
    $this->create_event('approval_requested',
      array(
        'label' => t('Request Approval'),
        'origin' => 'draft',
        'target' => 'ready_for_review',
        'permissions' => array('request approval of prc content'),
        'guard' => 'prc_workflow_user_owns_node'
      )
    );

    $this->create_event('rescind_request',
      array(
        'label' => 'Cancel Review Request',
        'origin' => 'ready_for_review',
        'target' => 'draft',
        'permissions' => array('request approval of prc content'),
        'guard' => 'prc_workflow_user_owns_node'
      )
    );

    $this->create_event('approved',
      array(
        'label' => t('Approve'),
        'origin' => 'ready_for_review',
        'target' => 'published',
        'permissions' => array('approve prc content'),
        'on_enter' => array($this, 'on_enter_published'),
      )
    );

    $this->create_event('denied',
      array(
        'label' => t('Deny'),
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
}