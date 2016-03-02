@api @itembank @prc-1536
Feature: PRC-1536 Item Bank- Pressing Reset button takes user back to different screen
  Item Bank- Pressing Reset button takes user back to home page

  @javascript
  Scenario: Reset button
    Given I am logged in as a user with the "Educator" role
    And I am on "assessments/item-bank"
    When I select "Short answer question" from "Question type"
    And I press "Reset"
    Then the url should match "assessments/item-bank"