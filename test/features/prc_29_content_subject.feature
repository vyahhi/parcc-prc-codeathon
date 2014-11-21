@api
Feature: PRC-29 Content Categorization - Subject
  As a Content Contributor,
  I want to do a more specialized categorization for content,
  so that end users can leverage the advanced content search.

  Acceptance Criteria
  AC1 A new Advanced link will be added by the Subject dropdown menu in the content metadata.
  AC2 At click, the system will provide a "Subject" overlay.
  AC3 For Subject overlay, a table allows a hierarchical drill down selection where each selection provides the user with the following options:
  associate content to the selected level.
  drill down to a lower level for a more specified selection (until reaching the leaf level).
  AC4 A user will select these Subject options by clicking the label name displayed in the table.
  AC5 A user may associate one or more subjects to content, and it can be different level.
  AC6 The system will ignore any duplicate selection.
  AC7 The content will come from the Learning Registry data (decision about the level of testing?)
  AC8 A breadcrumb on top of the table allows for returning to previous level.
  AC9 A Save button allows the user to save the categorization.
  AC10 A Cancel button allows the user to go back to the edit content page with no change.
  AC11 If a user attempts to navigate away without saving changes, the system prompts the user to confirm.

  This is being changed to support Simple Hierarchy Select instead of an Advanced popup.

  @javascript
  Scenario: PRC-404 Subject select triggers leave confirmation
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-29 Subject"
    Then I click "Edit"
    And I click "Show Add More Information (Content Properties)"
    When I click on the element with css selector "#edit-field-subject-und-0-tid-select-1"
    When I click on the element with css selector "#edit-title"
    Then I move backward one page, confirming the dialog

  @javascript
  Scenario: I can see the Subject field
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-29 Subject"
    Then I click "Edit"
    And I click "Show Add More Information (Content Properties)"
    Then I should see 1 "#edit-field-subject-und-0-tid-select-1" elements

  @javascript
  Scenario: I can drill hierarchically through the Subject field
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-29 Subject"
    Then I click "Edit"
    And I click "Show Add More Information (Content Properties)"
    Then I select "Educational Leadership" from "edit-field-subject-und-0-tid-select-1"
    Then I wait for AJAX to finish
    Then I select "Facilities Planning and Management" from "edit-field-subject-und-0-tid-select-2"
    Then I wait for AJAX to finish
    Then I select "Creating Instructional Environments" from "edit-field-subject-und-0-tid-select-3"
    Then I wait for AJAX to finish

  @javascript
  Scenario: I can select multiple Subjects
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-29 Subject"
    Then I click "Edit"
    And I click "Show Add More Information (Content Properties)"
    Then I select "Educational Leadership" from "edit-field-subject-und-0-tid-select-1"
    Then I wait for AJAX to finish
    Then I press "Add another item"
    Then I select "Math" from "edit-field-subject-und-1-tid-select-1"
    Then I wait for AJAX to finish
    Then I select "Algebra" from "edit-field-subject-und-1-tid-select-2"
    Then I wait for AJAX to finish
    Then I select "Equations and Inequalities" from "edit-field-subject-und-1-tid-select-3"
    Then I wait for AJAX to finish
    Then I select "Creating Equations" from "edit-field-subject-und-1-tid-select-4"
    Then I wait for AJAX to finish

  @javascript
  Scenario: I can save a node with a subject
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-29 Subject"
    Then I click "Edit"
    And I select the radio button "Public"
    And I click "Show Add More Information (Content Properties)"
    Then I select "Educational Leadership" from "edit-field-subject-und-0-tid-select-1"
    Then I wait for AJAX to finish
    Then I press "Save"
    Then I should see the link "Educational Leadership"