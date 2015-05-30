@api @like @profile
Feature: View total number of likes on profile
  As a logged in user,
  I want to see the total number of likes that all of my content has received
  so I can see how my content is received by users.

  Scenario: Profile starts at 0
    Given I am logged in as a user with the "Educator" role
    When I click "My account"
    Then I should see the text "My Library Contributions 0"
    Then I should see the text "My Assessments 0"
    Then I should see the text "My Individual Assessment Items 0"
    Then I should see the text "Items Others Have Bookmarked 0"
    Then I should see the text "Items Others Have Liked 0"

  Scenario: Profile reflects total likes for all user's nodes
    Given I am logged in as a user with the "Educator" role
    And "Digital Library Content" nodes:
      | title      | body             | field_permissions | uid         | status |
      | PRC First  | This is public 1 | public            | @currentuid | 1      |
      | PRC Second | This is public 2 | public            | @currentuid | 1      |
      | PRC Third  | This is public 3 | public            | @currentuid | 1      |
      | PRC Fourth | This is public 4 | public            | @currentuid | 1      |
    When I click "My account"
    Then I should see the text "My Library Contributions 4"

  Scenario: Profile reflects total likes for all user's assessments
    Given I am logged in as a user with the "Educator" role
    And "Assessment" nodes:
      | title      | body             | uid         | status |
      | PRC First  | This is public 1 | @currentuid | 1      |
      | PRC Second | This is public 2 | 1           | 1      |
      | PRC Fourth | This is public 4 | @currentuid | 1      |
    When I click "My account"
    Then I should see the text "My Assessments 2"

  Scenario: Profile reflects total likes for all user's likes
    Given I am logged in as a user with the "Educator" role
    And "Assessment" nodes:
      | title      | body             | uid         | status |
      | PRC First  | This is public 1 | @currentuid | 1      |
      | PRC Second | This is public 2 | 1           | 1      |
      | PRC Fourth | This is public 4 | @currentuid | 1      |
    When I click "My account"
    Then I should see the text "Items Others Have Liked 0"
    And I flag "PRC Fourth" with "Like Content"
    When I reload the page
    Then I should see the text "Items Others Have Liked 1"
