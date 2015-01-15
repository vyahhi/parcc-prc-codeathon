@api
Feature: PRC-27 Dynamic Text to Speech & Highlighting
  As an educator, I want the system to highlight and read the displayed content when I turn the Text-to-Speech feature on for a selected content.

  Acceptance Criteria
  AC1 A new link "Text to Speech" shall be available in the Content Detail page (once a content is selected by the end user) for all content types in Digital Library (Added on 12/19/14 based on QA feedback).
  AC2 At click, the Text to Speech toolbar appears. The user can move the toolbar around within his screen.
  This feature is available to all user roles
  AC3 Once the toolbar is visible, the Text to Speech button/link label shall be switched to Hide Text to Speech Toolbar .
  AC4 At click, it makes the toolbar disappear. (Corrected: -Unhide_ to Hide on 12/19/14 based on QA feedback)
  AC5 Toolbar loads with the default SpeechStream format

  @javascript
  Scenario: PRC-404 Subject select triggers leave confirmation
    Given I am logged in as a user with the "Authenticated User" role
    And I am viewing my "Digital Library Content" node with the title "PRC-29 Subject"
    Then I should see the link "Text to Speech"
    Then I click "Text to Speech"
    Then I wait for AJAX to finish
    Then I click "Text to Speech"
    And I should see "

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