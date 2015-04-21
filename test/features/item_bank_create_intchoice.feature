@api @itembank @interactivechoice @prc-1011
Feature: PRC-1011 Item Bank - Create Non-PARCC Interactive Choice Item - Form
  As a logged in user,
  I want to be able to create a non-PARCC interactive choice item from the Item Bank
  so that I can add it to assessments I have created or will create.

  Scenario: Form
    Given I am logged in as a user with the "Educator" role
    And I am on "item-bank"
    When I click "Interactive choice"
    Then I should see the heading "Create Interactive Choice Item"
    And I should see a "Save" button
    And I select "Pre-K" from "Grade Level"
    And I select "1st Grade" from "Grade Level"
    And I select "2nd Grade" from "Grade Level"
    And I select "3rd Grade" from "Grade Level"
    And I select "4th Grade" from "Grade Level"
    And I select "5th Grade" from "Grade Level"
    And I select "6th Grade" from "Grade Level"
    And I select "7th Grade" from "Grade Level"
    And I select "8th Grade" from "Grade Level"
    And I select "9th Grade" from "Grade Level"
    And I select "10th Grade" from "Grade Level"
    And I select "11th Grade" from "Grade Level"
    And I select "12th Grade" from "Grade Level"
    And I should see the text "Item Standard"