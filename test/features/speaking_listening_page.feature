@api @speaking-listening @prc-1410 @prc-1433
Feature: PRC-1410 Speaking and Listening page - Regulars View
  As a PARCC-member Educator, I want to be able to view Speaking and Listening resources.

  Background:
    Given speaking-listening content:
      | resource name       | resource type                 | file                          | faux standard | faux subject | grade level |
      | Resource @timestamp | Listening logs - for students | testfiles/GreatLakesWater.pdf | Standard      | Subject      | 1st Grade   |

  Scenario: Resource View
    Given I am an anonymous user
    And I am logged in as a user with the "PARCC-Member Educator" role
    When I am on "speaking-listening"
    Then I should see the heading "Speaking and Listening"
    And I should see the text "Overview / instructional copy goes here."
    And I should see the text "Resource Name"
    And I should see the text "Subject"
    And I should see the text "Grade Level"
    And I should see the text "Resource Type"
    And I should not see the link "Edit"

  Scenario: Educators can't see
    Given I am logged in as a user with the "Educator" role
    And I am on "instruction"
    Then I should not see the link "Speaking and Listening"

  Scenario: PRC-1433 S&L Resource name link
    Given I am logged in as a user with the "PARCC-Member Educator" role
    And I am on "speaking-listening"
    When I click "Resource @timestamp"
    Then the response Content-Type should be "application/pdf"
