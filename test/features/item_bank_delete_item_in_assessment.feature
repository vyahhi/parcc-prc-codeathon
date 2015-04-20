@api @itembank @parcc-item @prc-1041
Feature: PRC-1041 Item Bank - Delete Item - Item Deleted from Assessments
  As a logged in user,
  I want to be able to delete an item I previously created and remove it from any assessment that contained it
  so that I can finally be free of its tyranny.

  Given I am logged in
  And I am on the Are you sure? page
  When I click the Delete button
  Then the assessments that used to include the item no longer display it
  (See existing functionality for display of individual assessment)
  Note: Applies to all PARCC and non-PARCC item types:
  Non-Interactive Item
  Interactive Choice Item and
  Short Answer Item

  Scenario: Non-Interactive Item
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Quiz directions" nodes
    And I am on "assessments"
    And I click "Create New Assessment"
    And I fill in "Title" with "Quiz Title"
    And I fill in "Objectives" with "Objectives"
    And I select "1st Grade" from "Grade Level"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I press "Save Draft"

    When I click "Non-interactive Item (text only)"
    And I fill in "Title" with "NII T"
    And I fill in "Question" with "NII Question"
    And I check "Make this a PARCC item"
    And I press "Save"

    Then I am on "item-bank"
    When I click "Edit"
    And I press "Delete"
    And I press "Delete"
    Then I am on "assessments"
    And I click "Quiz Title"
    Then I should not see the link "NII T"