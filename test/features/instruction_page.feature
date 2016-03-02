@api @instruction @prc-1400 @prc-1519
Feature: PRC-1400 Instruction Page - Create Landing Page
  As a user,
  I want to be able to navigate to the Instruction landing page
  so that I can get to where I want to go more efficiently.

  Scenario: 1 Default
    Given I am logged in as a user with the "PARCC-Member Educator" role
    And I am on the homepage
    When I click "Instructional Tools"
    Then the url should match "instructional-tools"
    And I should see the link "Formative Instructional Tasks"
    And I should see the link "Speaking and Listening"
    And the "Formative Instructional Tasks" link should point to "instructional-tools/formative-instructional-tasks"
    And the "Speaking and Listening" link should point to "instructional-tools/speaking-listening"

  @prc-1519
  Scenario Outline: 1 All roles do see link
    Given I am logged in as a user with the "<role>" role
    And I am on the homepage
    When I click "Instructional Tools"
    Then the url should match "instructional-tools"
    And I should see the link "Formative Instructional Tasks"
    But I should see the link "Speaking and Listening"
  Examples:
    | role                            |
    | Educator                        |
    | PARCC-Member Educator           |
    | Content Contributor             |
    | Content Administrator (Curator) |
    | PRC Admin                       |
    | administrator                   |
    | PARCC Item Author               |

  @prc-1519 @anonymous
  Scenario: 1 Anonymous doesn't see link
    Given I am an anonymous user
    When I am on the homepage
    Then I should not see the link "Instructional Tools"

  @prc-1519 @anonymous
  Scenario Outline: 1 Anonymous can't access instruction pages
    Given I am an anonymous user
    When I am on "<url>"
    Then I should see the text "Access Denied"
  Examples:
    | url                           |
    | instructional-tools                   |
    | instructional-tools/speaking-listening            |
    | instructional-tools/formative-instructional-tasks |