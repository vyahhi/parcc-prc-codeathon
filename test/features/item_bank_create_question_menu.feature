@api @itembank @prc-1010
Feature: PRC-1010 Item Bank - Create New Item menu
  As a logged in user,
  I want to be able to create a new, non-PARCC item from the Item Bank so that I can add it to assessments I have created or will create.

  Scenario: Add new item menu
    Given I am logged in as a user with the "educator" role
    And I am on "item-bank"
    Then I should see the link "Non-interactive (text only)"
    And I should see the link "Interactive choice"
    And I should see the link "Short answer"