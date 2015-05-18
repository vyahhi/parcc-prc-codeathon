@api @itembank @prc-1037 @prc-1038 @prc-1412
Feature: PRC-1027 Item Bank - Duplicate Interactive choice Item - Form
  As a logged in user,
  I want to be able to duplicate a non-PARCC interactive item from the Item Bank
  so that I can make the changes I want to make.

  Scenario: User is not a PARCC Item Author
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "item-bank"
    And I click "Interactive choice"
    And I fill in "Item Title" with "IC 1"
    And I fill in "Question (Item Stem)" with "Stem 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in "edit-alternatives-0-answer-value" with "One"
    And I fill in "edit-alternatives-1-answer-value" with "Two"
    And I check the box "edit-alternatives-1-correct"
    And I select "1st Grade" from "Grade Level"
    Then I press "Save"
    Then I should see the text "No" in the "IC 1" row
    When I click "Duplicate"
    Then the "Item Title" field should contain "Clone of IC 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I press "Save"
    Then I should see the link "IC 1"
    And I should see the link "Clone of IC 1"

  Scenario: User is a PARCC Item Author and the Make this a PARCC item box is checked
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "item-bank"
    And I click "Interactive choice"
    And I fill in "Item Title" with "IC 1"
    And I fill in "Question (Item Stem)" with "Stem 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in "edit-alternatives-0-answer-value" with "One"
    And I fill in "edit-alternatives-1-answer-value" with "Two"
    And I check the box "edit-alternatives-1-correct"
    And I select "1st Grade" from "Grade Level"
    And I check the box "Make this a PARCC item"
    Then I press "Save"
    Then I should see the text "Yes" in the "IC 1" row
    When I click "Duplicate"
    Then the "Item Title" field should contain "Clone of IC 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And the "Make this a PARCC item" checkbox should be checked
    And I press "Save"
    Then I should see the link "IC 1"
    And I should see the link "Clone of IC 1"
    Then I should see the text "Yes" in the "Clone of IC 1" row

  Scenario: User is a PARCC Item Author and the Make this a PARCC item box is not checked
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "item-bank"
    And I click "Interactive choice"
    And I fill in "Item Title" with "IC 1"
    And I fill in "Question (Item Stem)" with "Stem 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in "edit-alternatives-0-answer-value" with "One"
    And I fill in "edit-alternatives-1-answer-value" with "Two"
    And I check the box "edit-alternatives-1-correct"
    And I select "1st Grade" from "Grade Level"
    And I uncheck the box "Make this a PARCC item"
    Then I press "Save"
    Then I should see the text "No" in the "IC 1" row
    When I click "Duplicate"
    Then the "Item Title" field should contain "Clone of IC 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And the "Make this a PARCC item" checkbox should not be checked
    And I press "Save"
    Then I should see the link "IC 1"
    And I should see the link "Clone of IC 1"
    Then I should see the text "No" in the "Clone of IC 1" row
