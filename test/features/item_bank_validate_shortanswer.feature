@api @itembank @shortanswer @validation @prc-1022
Feature: PRC-1022 Item Bank - Create / Edit / Duplicate Non-PARCC Short Answer Item - Form Validation
  As a logged in user,
  I want to get feedback about any errors that occur when I create, edit or duplicate a non-PARCC short answer item
  so that i can fix errors and successfully create or update the item.

  Scenario: Validation
    Given I am logged in as a user with the "Educator" role
    And I am on "item-bank"
    And I click "Short answer"
    When I press "Save"
    Then I should see the error message containing "Grade Level field is required."
    Then I should see the error message containing "At least one Item Standard is required."
