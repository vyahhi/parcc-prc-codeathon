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
    | title        | field_subject | field_grade_level |
    | PRC-490 View | subj1, subj2  | Grade 490         |
    When I am on "content/prc-490-view"
    Then I should see the heading "PRC-490 View" in the "content" region
    And I should see the link "subj1"
    And I should see the link "subj2"
    And I should see the text "subj1, subj2"
    And I should see the link "Grade 490"
  #  A list of items (may be thumbnails or rows) along with the following components for each item:
  #    Item order
  #    Item Type
  #    Item Standard