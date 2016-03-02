@api @assessment @itembank @shortanswer @prc-1012 @prc-1275
Feature: PRC-1012 Item Bank - Create Non-PARCC Short Answer Item - Form
  As a logged in user,
  I want to be able to create a non-PARCC short answer item from the Item Bank
  so that I can add it to assessments I have created or will create.

  @prc-1594
  Scenario: Form
    Given I am logged in as a user with the "Educator" role
    And I am on "assessments/item-bank"
    When I click "Short answer"
    Then I should see the heading "Create Short Answer Item"
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
    And I should see the text "Specify the answer."
    But I should not see the text "Specify the answer. If this question is manually scored, no answer needs to be supplied."
    And I should not see the text "Provide the answer and the method by which the answer will be evaluated."
    And I should not see the text "Choose how the answer shall be evaluated."
    And I should not see the text "Pick an evaluation method"