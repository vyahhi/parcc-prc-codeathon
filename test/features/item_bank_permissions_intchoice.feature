@api @itembank @prc-1025 @multichoice @permissions
Feature: PRC-1027 Item Bank - Edit Interactive choice Item - Form
  As a logged in user,
  I want to be able to edit a non-PARCC interactive item from the Item Bank
  so that I can make the changes I want to make.

  Scenario: User is not a PARCC Item Author
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    And I click "Interactive choice"
    And I fill in "Item Title" with "IC 1"
    And I fill in "Question (Item Stem)" with "Stem 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in "edit-alternatives-0-answer-value" with "One"
    And I fill in "edit-alternatives-1-answer-value" with "Two"
    And I check the box "edit-alternatives-1-correct"
    And I check the box "Pre-K"
    And I check the box "1st Grade"
    And I check the box "2nd Grade"
    And I check the box "3rd Grade"
    And I check the box "4th Grade"
    And I check the box "5th Grade"
    And I check the box "6th Grade"
    And I check the box "7th Grade"
    And I check the box "8th Grade"
    And I check the box "9th Grade"
    And I check the box "10th Grade"
    And I check the box "11th Grade"
    And I check the box "12th Grade"
    Then I press "Save"
    Then I should see the text "No" in the "IC 1" row

    # Log out
    Then I am an anonymous user
    # And log in as another user
    Given I am logged in as a user with the "PARCC-Member Educator" role
    And I am on "assessments/item-bank"
    Then I should not see the text "IC 1"

  Scenario: User is a PARCC Item Author
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    And I click "Interactive choice"
    And I fill in "Item Title" with "IC 1"
    And I fill in "Question (Item Stem)" with "Stem 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in "edit-alternatives-0-answer-value" with "One"
    And I fill in "edit-alternatives-1-answer-value" with "Two"
    And I check the box "edit-alternatives-1-correct"
    And I check the box "Pre-K"
    And I check the box "1st Grade"
    And I check the box "2nd Grade"
    And I check the box "3rd Grade"
    And I check the box "4th Grade"
    And I check the box "5th Grade"
    And I check the box "6th Grade"
    And I check the box "7th Grade"
    And I check the box "8th Grade"
    And I check the box "9th Grade"
    And I check the box "10th Grade"
    And I check the box "11th Grade"
    And I check the box "12th Grade"
    And I check the box "Make this a PARCC item"
    Then I press "Save"
    Then I should see the text "Yes" in the "IC 1" row

      # Log out
    Then I am an anonymous user

    # And log in as another user
    Given I am logged in as a user with the "Educator" role
    And I am on "assessments/item-bank"
    Then I should see the text "IC 1"