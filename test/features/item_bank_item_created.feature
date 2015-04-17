@api @itembank @prc-1009
Feature: PRC-1009 Item Bank - Create New Non-PARCC Item - Item Created
  As a logged in user, I want to see the non-PARCC item I created in the item bank so that I know I have successfully created the item.
  Acceptance Criteria

  Scenario: User is not a PARCC Item Author
    Given I am logged in as a user with the "Educator" role
    And I am on "item-bank"
    And I click "Short answer"
    And I fill in "Title" with "SAT"
    And I fill in "Question" with "Question text"
    And I fill in "Correct answer" with "Right"
    And I select "5th Grade" from "Grade Level"
    And I fill in the hidden field "faux_standard" with "Short Answer Standard"
    And I should not see the text "Make this a PARCC item"
    When I press "Submit"
    Then I should be on "item-bank"
    And I should see the text "No" in the "SAT" row

  Scenario: User is PARCC Item Author
    Given I am logged in as a user with the "PARCC Item Author" role
    And I am on "item-bank"
    And I click "Short answer"
    And I fill in "Title" with "SAT"
    And I fill in "Question" with "Question text"
    And I fill in "Correct answer" with "Right"
    And I select "5th Grade" from "Grade Level"
    And I fill in the hidden field "faux_standard" with "Short Answer Standard"
    And I check the box "Make this a PARCC item"
    When I press "Submit"
    Then I should be on "item-bank"
    And I should see the text "Yes" in the "SAT" row