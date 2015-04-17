@api @itembank @prc-1027
Feature: PRC-1027 Item Bank - Edit Short Answer Item - Form
  As a logged in user,
  I want to be able to edit a non-PARCC short answer item from the Item Bank
  so that I can make the changes I want to make.

  Scenario: User is not a PARCC Item Author
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Quiz directions" nodes
    And I am on "item-bank"
    And I click "Short answer"
    And I fill in "Title" with "SA 1"
    And I fill in "Question" with "Stem 1"
    And I fill in "Correct answer" with "Correct"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I select "1st Grade" from "Grade Level"
    Then I press "Save"
    Then I should see the text "No" in the "SA 1" row
    When I click "Edit"
    Then the "Title" field should contain "SA 1"
    And the "Question" field should contain "Stem 1"
    But I fill in "Title" with "SA Take Two"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I press "Save"
    Then I should see the text "No" in the "SA Take Two" row

  Scenario: User is a PARCC Item Author
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Quiz directions" nodes
    And I am on "item-bank"
    And I click "Short answer"
    And I fill in "Title" with "SA 1"
    And I fill in "Question" with "Stem 1"
    And I fill in "Correct answer" with "Correct"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I select "1st Grade" from "Grade Level"
    And I check the box "Make this a PARCC item"
    Then I press "Save"
    Then I should see the text "Yes" in the "SA 1" row
    When I click "Edit"
    Then the "Title" field should contain "SA 1"
    And the "Question" field should contain "Stem 1"
    But I fill in "Title" with "SA Take Two"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I uncheck the box "Make this a PARCC item"
    And I press "Save"
    Then I should see the text "No" in the "SA Take Two" row

#  Scenario 2: User is a PARCC Item Author
#    Given I am logged in as a PARCC Item Author
#    And I am on the Item Bank page
#    When I click Edit link / button associated with the short answer item (either PARCC or non-PARCC)
#    Then I see the Edit Short Answer Item page:
#  Differences from Item Bank - Create PARCC Short Answer Item - Form (PRC-1275)
#  Fields are populated with previously submitted changes