@api @itembank @directions @prc-1393
Feature: PRC-1393 Create Non-interactive Item (text only) - Form - Required Fields
  As a logged in user, I want to be able to create a non-interactive, text-only item from the Item Bank so that I can add it to assessments I have created or will create.

  Scenario: Validation
    Given I am logged in as a user with the "Educator" role
    And I am on "item-bank"
    When I click "Non-interactive (text only)"
    And I press "Save"
    Then I should see the error message containing "Question field is required."