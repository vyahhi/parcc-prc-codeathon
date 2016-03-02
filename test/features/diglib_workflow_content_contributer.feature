@api @diglib @workflow
Feature: As a Content Contributor, I need to have specific access to the Digital Library
  content that I have created so I can develop the content that I have a deep understanding [of] (PRC-629).

  Background:
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "My Content"
    And I click "Edit"
    And I select the radio button "Public"
    And I press the "Save" button

  Scenario: Can view and edit draft whens state is draft
    Given the last node created's state is "draft"
    When I visit the last node created
    And I should see the text "My Content"
    And I click "Edit"
    And I press the "Save" button
    Then I should see the success message containing "Digital Library Content My Content has been updated."

  Scenario: Can View draft when state is Approval Requested, but cannot edit
    Given I visit the last node created
    And I click "Edit"
    And I press the "Request Approval" button
    And press the "Update state" button
    When I visit the last node created
    Then I should not see the link "Edit"

  Scenario: Can View and edit content when state is published
    Given the last node created's state is set to "published"
    When I visit the last node created
    And I should see the text "My Content"
    Then I click "Edit"
    And I press the "Save" button
    And I should see the success message containing "Digital Library Content My Content has been updated."

  Scenario: Contributor can request approval (prc-47)
    Given I visit the last node created
    And I click "Edit"
    When I press the "Request Approval" button
    And I press the "Update state" button
    Then I should see the message containing "My Content transitioned to the ready_for_review state."

  Scenario: Contributor can cancel approval request (prc-602)
    Given I visit the last node created
    And I click "Edit"
    And I press the "Request Approval" button
    And press the "Update state" button
    And I visit the last node created
    When I click "Rescind Request"
    And I press the "Update state" button
    Then I should see the message containing "My Content transitioned to the draft state."

  @javascript @styleguide
  Scenario: prc-1653 padding on revision state message
    Given I visit the last node created
    And I click "Edit"
    And I press the "Request Approval" button
    And press the "Update state" button
    And I visit the last node created
    When I click "Rescind Request"
    And "#state-flow-events-revision" should have a "padding-bottom" css value of "48px"
    And "#state-flow-events-revision" should have a "padding-left" css value of "32px"
    And "form#state-flow-events-revision input#edit-submit" should have a "margin-right" css value of "16px"
    And I press the "Update state" button
    And I click "My Content"
    And ".prc-workflow-state" should have a "padding-top" css value of "16px"

