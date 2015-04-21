@api @assessment @itembank @shortanswer @prc-1012 @prc-1275
Feature: PRC-1012 Item Bank - Create Non-PARCC Short Answer Item - Form
  As a logged in user,
  I want to be able to create a non-PARCC short answer item from the Item Bank
  so that I can add it to assessments I have created or will create.

  Scenario: Form
    Given I am logged in as a user with the "Educator" role
    And I am on "item-bank"
    When I click "Short answer"
    Then I should see the heading "Create Short Answer Item"
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
    And I should see the text "Specify the answer."
    But I should not see the text "Specify the answer. If this question is manually scored, no answer needs to be supplied."
    And I should not see the text "Provide the answer and the method by which the answer will be evaluated."
    And I should not see the text "Choose how the answer shall be evaluated."
    And I should not see the text "Pick an evaluation method"