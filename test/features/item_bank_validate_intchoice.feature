@api @itembank @interactivechoice @prc-1008 @multichoice
Feature: PRC-1008 Item Bank - Create / Edit / Duplicate Non-PARCC Interactive Choice Item - Form Validation
  As a logged in user,
  I want to get feedback about any errors that occur when I create, edit or duplicate a non-PARCC interactive choice item
  so that i can fix errors and successfully create or update the item.

  Scenario: Validation
    Given I am logged in as a user with the "Educator" role
    And I am on "assessments/item-bank"
    When I click "Interactive choice"
    And I press "Save"
    Then I should see the error message containing "Grade Level field is required."