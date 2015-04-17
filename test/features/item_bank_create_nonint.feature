@api @itembank @assessment @directions @prc-1007
Feature: PRC-1007 Item Bank - Create Non-PARCC Non-interactive Item (text only) - Form
  As a logged in user,
  I want to be able to create a non-PARCC, non-interactive, text-only item from the Item Bank
  so that I can add it to assessments I have created or will create.

  Scenario: Form
    Given I am logged in as a user with the "Educator" role
    And I am on "item-bank"
    When I click "Non-interactive (text only)"
    Then I should see the heading "Create Non-interactive Item (text only)"
    And I should see a "Save" button