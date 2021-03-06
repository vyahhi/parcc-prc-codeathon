@api @itembank @quiz @prc-1280
Feature: PRC-1280 Item Bank - Link from Assessments page
  As a logged in user, I want to be able to access PARCC items and the items I created so that I can view them; use them in assessments; or edit, duplicate or delete items that I created.
  Acceptance Criteria
  Given I am logged in
  When I am on the Assessment page
  Then I see a link to the Item Bank in the section navigation

  Scenario: Menu item exists
    Given I am logged in as a user with the "Educator" role
    And I am on "assessments/practice-assessments"
    Then I should see the link "Item Bank"

  Scenario: PRC-1402 Assessment - Items Added to Assessment- Error message shown when clicking Add questions to Assessment
    Given I am logged in as a user with the "Educator" role
    When I am on "assessments/item-bank"
    Then I should not see the button "Add questions to Assessment"
