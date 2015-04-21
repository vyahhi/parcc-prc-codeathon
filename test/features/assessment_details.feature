@api @assessment @prc-490 @prc-1353
Feature: PRC-490 View Test Details
  As an educator,
  I want to view a practice test details,
  so that I will know what items are in the test.

#BACKGROUND: This story is a portion of PRC-65 and includes all the functionality that PRC team can implement without integration point. Once this is implemented, the original story will just add the integration point. In the meantime, Dev team will provide dummy tests instead.
#This story has been broken down to the following:
#1. View only (this story)
#2. Preview Item (PRC-527)
#3. Edit Test: Move items around or remove item (PRC-525)
#4. Anonymous users (PRC-526)

#Acceptance Criteria
#PRE_REQUISITE: Dev team, please create a couple assessments for testing.


  Scenario: AC1 Clicking an assessment name in the assessments page opens a new Assessment Details page opens, where the assessment's information is displayed at the top of the page:
    Given "Subject" terms:
      | name      |
      | subj490-1 |
      | subj490-2 |
    And "Grade Level" terms:
      | name      |
      | Grade 490 |
    And "Assessment" nodes:
      | title        | field_subject        | field_grade_level | field_quiz_type                    | uid |
      | PRC-490 View | subj490-1, subj490-2 | Grade 490         | PARCC-Released Practice Assessment | 1   |
    When I visit the last node created
    Then I should see the heading "PRC-490 View" in the "content" region
    And I should see the link "subj490-1"
    And I should see the link "subj490-2"
    And I should see the text "subj490-1, subj490-2"
    And I should see the link "Grade 490"

  Scenario: AC2 A list of items (may be thumbnails or rows) along with the following components for each item:
    Given "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Grade Level" terms:
      | name      |
      | Grade 490 |
    And "Assessment" nodes:
      | title        | field_subject | field_grade_level | field_quiz_type                    |
      | PRC-490 View | subj1, subj2  | Grade 490         | PARCC-Released Practice Assessment |
    # That standard already exists, and I hate it, but I am getting an error
    # creating a Standard term is giving me an error.
    # We're cheating and using one that exists already.
    And I am logged in as a user with the "PRC Admin" role
    When I visit the last node created
    And I click "Quiz"
    Then I click "Manage questions"
    Then I click "Assessment directions"
    And I fill in "edit-body-und-0-value" with "PRC-490 Directions 1"
    And I fill in "Title" with "PRC-490 Directions 1"
    And I press "Save"
    Then I click "Multiple choice question"
    And I fill in "edit-body-und-0-value" with "PRC-490 Directions 2"
    And I fill in "Title" with "PRC-490 Directions 2"
    And I fill in "edit-alternatives-0-answer-value" with "Answer 1"
    And I fill in "edit-alternatives-1-answer-value" with "Answer 2"
    And I check the box "edit-alternatives-1-correct"
    And I press "Save"
    Then I visit the last node created
    And I should see the text "Item Type"
    # Standard requires manual testing because it's all javascript
    # and questions don't scaffold correctly.

  Scenario: Anonymous user can't copy
    Given "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Grade Level" terms:
      | name      |
      | Grade 490 |
    And "Assessment" nodes:
      | title        | field_subject | field_grade_level | field_quiz_type                    | uid |
      | PRC-490 Copy | subj1, subj2  | Grade 490         | PARCC-Released Practice Assessment | 1   |
    When I visit the last node created
    And I press "Save Draft"
    And I should see the error message containing "You must be logged in to save an assessment."

  Scenario: Save empty PARCC-Released Practice Assessment
    Given "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Grade Level" terms:
      | name      |
      | Grade 490 |
    And "Assessment" nodes:
      | title        | field_subject | field_grade_level | field_quiz_type                    | uid |
      | PRC-490 Copy | subj1, subj2  | Grade 490         | PARCC-Released Practice Assessment | 1   |
    And I am logged in as a user with the "Educator" role
    When I visit the last node created
    And I press "Save Draft"
    Then I should see the text "PRC-490 Copy - copy"
    And I should not see the error message containing "prc"

  Scenario: PRC-1353 Common page elements
    Given I am logged in as a user with the "PRC Admin" role
    And "Grade Level" terms:
      | name          |
      | Middle School |
    And "Subject" terms:
      | name                   |
      | Educational Leadership |
      | Math                   |
    And "Assessment" nodes:
      | title                      | body   | field_grade_level | field_subject                | field_quiz_type                    | uid         |
      | PRC-534 Assessment Title 1 | Body 1 | Middle School     | Educational Leadership, Math | PARCC-Released Practice Assessment | @currentuid |
      | PRC-534 Assessment Title 2 | Body 2 | Middle School     | Educational Leadership, Math | Custom Assessment                  | @currentuid |
      | PRC-534 Assessment Title 3 | Body 3 | Middle School     | Educational Leadership, Math | Custom Assessment                  | @currentuid |
    And I click "Assessments"
    When I click "PRC-534 Assessment Title 2"
    Then I should see the text "Assessment Type"
    But I should not see the text "Quiz Type"
    And I should see the text "Create New Item"
    But I should not see the text "Add Item"
    And I should see the link "Add Existing Item"

  Scenario: PRC-1353 PARCC item?
    Given I am logged in as a user with the "PARCC Item Author" role
    And "Grade Level" terms:
      | name          |
      | Middle School |
    And "Subject" terms:
      | name                   |
      | Educational Leadership |
      | Math                   |
    And "Assessment" nodes:
      | title           | body   | field_grade_level | field_subject                | field_quiz_type                    | uid         |
      | 1353 PARCC Item | Body 1 | Middle School     | Educational Leadership, Math | PARCC-Released Practice Assessment | @currentuid |
    And I click "Assessments"
    And I click "1353 PARCC Item"
    And I click "Non-interactive Item (text only)"
    And I fill in "My Title" for "Title"
    And I fill in "My Question" for "Question"
    And I check the box "Make this a PARCC item"
    And I press "Save"
    Then I should see the text "Yes" in the "My Title" row
    And I should see the text "PARCC Item?"