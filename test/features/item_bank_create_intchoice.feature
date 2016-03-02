@api @itembank @interactivechoice @prc-1011 @multichoice
Feature: PRC-1011 Item Bank - Create Non-PARCC Interactive Choice Item - Form
  As a logged in user,
  I want to be able to create a non-PARCC interactive choice item from the Item Bank
  so that I can add it to assessments I have created or will create.

  Scenario: Form
    Given I am logged in as a user with the "Educator" role
    And I am on "assessments/item-bank"
    When I click "Interactive choice"
    Then I should see the heading "Create Interactive Choice Item"
    And I should see a "Save" button
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
    And I should see the text "Item Standard"