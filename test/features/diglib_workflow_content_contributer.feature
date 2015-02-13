@api
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
    And I should see the text "My Content"
    When I click "Edit"
    And I press the "Request Approval" button
    And I visit the last node created
    And the last node created's state is "ready_for_review"
    Then I should not see the link "Edit"

  Scenario: Can View and edit content when state is published
    Given the last node created's state is set to "published"
    When I visit the last node created
    And I should see the text "My Content"
    Then I click "Edit"
    And I press the "Save" button
    And I should see the success message containing "Digital Library Content My Content has been updated."
