@api @assessment
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
    | name  |
    | subj1 |
    | subj2 |
    And "Grade Level" terms:
    | name      |
    | Grade 490 |
    And "Quiz" nodes:
    | title        | field_subject | field_grade_level | field_quiz_type            | uid |
    | PRC-490 View | subj1, subj2  | Grade 490         | PRC Released Practice Test | 1   |
    When I visit the last node created
    Then I should see the heading "PRC-490 View" in the "content" region
    And I should see the link "subj1"
    And I should see the link "subj2"
    And I should see the text "subj1, subj2"
    And I should see the link "Grade 490"

  Scenario: AC2 A list of items (may be thumbnails or rows) along with the following components for each item:
    Given "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Grade Level" terms:
      | name      |
      | Grade 490 |
    And "Quiz" nodes:
      | title        | field_subject | field_grade_level | field_quiz_type            |
      | PRC-490 View | subj1, subj2  | Grade 490         | PRC Released Practice Test |
    # That standard already exists, and I hate it, but I am getting an error
    # creating a Standard term is giving me an error.
    # We're cheating and using one that exists already.
    And I am logged in as a user with the "PRC Admin" role
    When I visit the last node created
    And I click "Quiz"
    Then I click "Manage questions"
    Then I click "Exam directions"
    And I fill in "edit-body-und-0-value" with "PRC-490 Directions 1"
    And I fill in "Title" with "PRC-490 Directions 1"
    And I fill in "Item Order" with "D1"
    And I press "Save"
    Then I click "Multiple choice question"
    And I fill in "edit-body-und-0-value" with "PRC-490 Directions 2"
    And I fill in "Title" with "PRC-490 Directions 2"
    And I fill in "edit-alternatives-0-answer-value" with "Answer 1"
    And I fill in "edit-alternatives-1-answer-value" with "Answer 2"
    And I check the box "edit-alternatives-1-correct"
    And I fill in "Item Order" with "Q1"
    And I press "Save"
    Then I visit the last node created
    And I should see the text "Item Order"
    And I should see the text "Item Type"
    # Standard requires manual testing because it's all javascript
    # and questions don't scaffold correctly.