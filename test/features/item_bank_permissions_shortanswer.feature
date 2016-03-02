@api @itembank @shortanswer @prc-1027 @permissions
Feature: PRC-1027 Item Bank - Edit Short Answer Item - Form
  As a logged in user,
  I want to be able to edit a non-PARCC short answer item from the Item Bank
  so that I can make the changes I want to make.

  Scenario: User is not a PARCC Item Author
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    And I click "Short answer"
    And I fill in "Title" with "SA 1"
    And I fill in "Question" with "Stem 1"
    And I fill in "Correct answer" with "Correct"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I check the box "Pre-K"
    And I check the box "1st Grade"
    And I check the box "2nd Grade"
    And I check the box "3rd Grade"
    Then I press "Save"
    Then I should see the text "No" in the "SA 1" row

    # Log out
    Then I am an anonymous user

    # And log in as another user
    Given I am logged in as a user with the "PARCC-Member Educator" role
    And I am on "assessments/item-bank"
    Then I should not see the text "SA 1"

  Scenario: User is a PARCC Item Author
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    And I click "Short answer"
    And I fill in "Title" with "SA 1"
    And I fill in "Question" with "Stem 1"
    And I fill in "Correct answer" with "Correct"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I check the box "Pre-K"
    And I check the box "1st Grade"
    And I check the box "2nd Grade"
    And I check the box "3rd Grade"
    And I check the box "4th Grade"
    And I check the box "Make this a PARCC item"
    Then I press "Save"
    Then I should see the text "Yes" in the "SA 1" row

    # Log out
    Then I am an anonymous user

    # And log in as another user
    Given I am logged in as a user with the "Educator" role
    And I am on "assessments/item-bank"
    Then I should see the text "SA 1"
