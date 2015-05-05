@api @speaking-listening @prc-1425
Feature: PRC-1425 Speaking and Listening - Edit Resource
  As a PRC Admin, I want to be able to edit a Speaking and Listening resource so that educators can access and use the updated resource.

  Scenario: Edit form
    Given I am logged in as a user with the "PRC Admin" role
    And "Speaking and Listening Resource" nodes:
      | title               | status | uid         | Grade Level | Subject | Standard                  |
      | Resource @timestamp | 1      | @currentuid | 1st Grade   | Math    | Common Core Language Arts |
    And I visit the first node created
    And I click "Edit"
    Then  I take a screenshot
    Then I should see the heading "Resource @timestamp"
    And the "Resource name" field should contain "Resource @timestamp"
    And I should see a "Save" button
    And I should see a "Delete" button
