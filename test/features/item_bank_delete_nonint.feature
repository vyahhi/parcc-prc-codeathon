@api @itembank @directions @prc-1023 @prc-1040 @prc-1042
Feature: PRC-1039 Item Bank - Delete Item - Are you sure?
  As a logged in user,
  I want to be able to delete from the Item Bank an item I previously created
  so that I don't have to look at it anymore.

  Given I am logged in
  And I am on the Edit Item page
  When I click the Delete button
  Then I see the Are you sure? page that has:
  Are you sure you want to delete <Item Title>?
  This action cannot be undone.
  Delete button
  Cancel link
  Note: Applies to all PARCC and non-PARCC item types:
  Non-Interactive Item
  Interactive Choice Item and
  Short Answer Item

  Scenario: Delete directions
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "NII T"
    And I fill in "Question" with "NII Question"
    And I press "Save"
    And I click "Edit"
    Then I press "Delete"
    Then I should see the heading "Are you sure you want to delete NII T?"
    And I should see the text "This action cannot be undone."

  Scenario: PRC-1042 - Cancel
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "NII T"
    And I fill in "Question" with "NII Question"
    And I press "Save"
    And I click "Edit"
    Then I press "Delete"
    When I click "Cancel"
    Then I am on "assessments/item-bank"

  Scenario: PRC-1040 - Item deleted
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "NII T"
    And I fill in "Question" with "NII Question"
    And I press "Save"
    And I should see the link "NII T"
    And I click "Edit"
    Then I press "Delete"
    Then I press "Delete"
    Then I am on "assessments/item-bank"
    And I should not see the link "NII T"