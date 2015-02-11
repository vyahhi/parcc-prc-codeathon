@api @assessment
Feature: PRC-528 Delete Item in Test Customization
  As an educator,
  I want to remove an item from a test,
  so that it fits my classroom needs.

  Acceptance Criteria
  In the _Assessment Details page where items are displayed (implemented in PRC-490), in addition to the edit functionality, removing an item from the assessment shall be also available. Note that a user cannot modify the original PARCC Released Tests. They can however create a duplicate where their changes are stored as a new user-created test.
  AC1 Provide a link or button to each of the displayed items for the user to remove an item from the assessment. At click, the system shall remove that item from the list of items displayed (not saved yet).
  AC2 The Save Draft functionality is the same as described in PRC-525, AC copied below:
  If the original test is a PARCC Released Test: The system prompts the user to provide a new test name, labeled as New Quiz Title --Required, String(255)
  If the original test is a user-created test, the system prompts the user to define whether to create a new test, or to override the existing one. For the former, the system prompts the user to provide a new test name, labeled as New Quiz Title --Required, String(255)
  AC3 For the New Quiz Title textbox, populate the original test name concatenated with -copy (example below)
  Algebra Grade 8 - copy
  AC4 Once above information is provided, the system stores the changes associated to that user as the new or existing user-created quiz.
  AC5 If a user navigates away from the page without saving the changes, the system prompts the user to confirm.
  AC6 Permissions: All the above features are available to all roles, except for anonymous users (separated anonymous users into PRC-526)
  AC7 A user cannot save draft of a test with no item. At least, one item should remain in the quiz before it is saved.

  @javascript
  Scenario: Delete an item in a Custom Assessment, no copy
    Given I am logged in as a user with the "PRC Admin" role
    And "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Quiz" nodes:
      | title          | field_subject | field_quiz_type   | uid         |
      | PRC-528 Delete | subj1, subj2  | Custom Assessment | @currentuid |
    And I am on "assessments"
    Then I click "PRC-528 Delete"
    And I click "Quiz"
    Then I click "Manage questions"
    Then I click "Create new question"
    Then I click "Quiz directions"
    And I fill in "edit-body-und-0-value" with "PRC-528 Directions 1 And these are the Body Body Directions Directions"
    And I fill in "Title" with "PRC-528 Directions 1"
    And I fill in "Item Order" with "D1"
    And I press "Save"
    Then I click "Create new question"
    Then I click "Multiple choice question"
    And I fill in "edit-body-und-0-value" with "PRC-528 Multi Multi Question Question"
    And I fill in "Item Order" with "Q2"
    And I fill in "Title" with "PRC-528 Multi"
    And I select "Common Core Mathematics" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "edit-alternatives-0-answer-value" with "Answer 1"
    And I fill in "edit-alternatives-1-answer-value" with "Answer 2"
    And I check the box "edit-alternatives-1-correct"
    And I press "Save"
    Then I click "View"
    Then I should see the heading "PRC-528 Delete" in the "content" region
    Then I should see the link "PRC-528 Directions 1"
    Then I check the element with xpath selector "//*[starts-with(@id, 'edit-stayers')]"
    And I press "Save Draft"
    Then I should not see the link "PRC-528 Directions 1"
    Then I should not see the text "PRC-528 Delete - copy"
    But I should see the heading "PRC-528 Delete" in the "content" region

  @javascript
  Scenario: Delete an item in a PRC Assessment, copy
    Given I am logged in as a user with the "PRC Admin" role
    And "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Quiz" nodes:
      | title          | field_subject | field_quiz_type            | author      |
      | PRC-528 Delete | subj1, subj2  | PRC Released Practice Test | @currentuid |
    And I am on "assessments"
    Then I click "PRC-528 Delete"
    And I click "Quiz"
    Then I click "Manage questions"
    Then I click "Create new question"
    Then I click "Quiz directions"
    And I fill in "edit-body-und-0-value" with "PRC-528 Directions 1 And these are the Body Body Directions Directions"
    And I fill in "Title" with "PRC-528 Directions 1"
    And I fill in "Item Order" with "D1"
    And I press "Save"
    Then I click "Create new question"
    Then I click "Multiple choice question"
    And I fill in "edit-body-und-0-value" with "PRC-528 Multi Multi Question Question"
    And I fill in "Item Order" with "Q2"
    And I fill in "Title" with "PRC-528 Multi"
    And I select "Common Core Mathematics" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "edit-alternatives-0-answer-value" with "Answer 1"
    And I fill in "edit-alternatives-1-answer-value" with "Answer 2"
    And I check the box "edit-alternatives-1-correct"
    And I press "Save"
    Then I click "View"
    Then I should see the heading "PRC-528 Delete" in the "content" region
    Then I should see the link "PRC-528 Directions 1"
    Then I check the element with xpath selector "//*[starts-with(@id, 'edit-stayers')]"
    And I press "Save Draft"
    Then I should not see the link "PRC-528 Directions 1"
    But I should see the heading "PRC-528 Delete - copy" in the "content" region

  @javascript
  Scenario: User can't delete all questions
    Given I am logged in as a user with the "PRC Admin" role
    And "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Quiz" nodes:
      | title          | field_subject | field_quiz_type            | author      |
      | PRC-528 Delete | subj1, subj2  | PRC Released Practice Test | @currentuid |
    And I am on "assessments"
    Then I click "PRC-528 Delete"
    And I click "Quiz"
    Then I click "Manage questions"
    Then I click "Create new question"
    Then I click "Multiple choice question"
    And I fill in "edit-body-und-0-value" with "PRC-528 Multi Multi Question Question"
    And I fill in "Item Order" with "Q2"
    And I fill in "Title" with "PRC-528 Multi"
    And I select "Common Core Mathematics" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "edit-alternatives-0-answer-value" with "Answer 1"
    And I fill in "edit-alternatives-1-answer-value" with "Answer 2"
    And I check the box "edit-alternatives-1-correct"
    And I press "Save"
    Then I click "View"
    Then I should see the heading "PRC-528 Delete" in the "content" region
    Then I check the element with xpath selector "//*[starts-with(@id, 'edit-stayers')]"
    And I press "Save Draft"
    Then I should see the error message containing "You may not delete every question in your quiz."