@api @itembank @prc-1001
Feature: PRC-1001 Item Bank
  As a logged in user,
  I want to be able to access PARCC items and the items I created
  so that I can view them; use them in assessments; or edit, duplicate or delete items that I created.

#  Create New Item [fancy dropdown]

  Scenario: Item Bank Page
    Given I am logged in as a user with the "Educator" role
    When I am on "item-bank"
    Then I should see the heading "Item Bank"
    And I should see the text "Overview / instructional copy goes here. Consider explaining importance of testing prior to assessment to increase chances of successful assessment."

  Scenario: No items
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    When I am on "item-bank"
    Then I should see the text "No items found."
    But I should not see the text "Scoring note: All interactive choice and short answer questions are machine scored."

  Scenario: Has items
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes

    And I am on "node/add/quiz-directions"
    And I fill in "Title" with "QD"
    And I fill in "Question" with "QD"
    And I press "Save"

    When I am on "item-bank"
    Then I should not see the text "No items found."
    And I should see the text "Scoring note: All interactive choice and short answer questions are machine scored."
    And I should see the text "Assessment directions" in the "QD" row
    And I should see the text "Title"
    And I should see the text "Type"
    And I should see the text "Last Updated"
    And I should see the text "PARCC Item?"
    And I should not see the text "Author"