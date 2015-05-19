@api @speaking-listening @prc-1226 @prc-1433 @prc-1434
Feature: PRC-1410 Speaking and Listening page - Regulars View
  As a PARCC-member Educator, I want to be able to view Formative Instructional Tasks resources.

  Background:
    Given formative instructional task content:
      | resource name       | resource type                 | file                          | faux standard | faux subject | grade level |
      | Resource @timestamp | Listening logs - for students | testfiles/GreatLakesWater.pdf | Standard      | Subject      | 1st Grade   |

  Scenario: Resource View
    Given I am an anonymous user
    And I am logged in as a user with the "PARCC-Member Educator" role
    When I am on "formative-instructional-tasks"
    Then I should see the heading "Formative Instructional Tasks"
    And I should see the text "Overview / instructional copy goes here."
    And I should see the text "Resource Name"
    And I should see the text "Subject"
    And I should see the text "Grade Level"
    And I should see the text "Resource Type"
    But I should not see the link "Edit"
    And I should not see the link "Add Resource"
    And I should not see the text "URL for Seraph"

  Scenario: Educators can't see
    Given I am logged in as a user with the "Educator" role
    And I am on "instruction"
    Then I should not see the link "Formative Instructional Tasks"

  @prc-1398
  Scenario: PRC-1398 View Resource name link
    Given I am logged in as a user with the "PARCC-Member Educator" role
    And I am on "formative-instructional-tasks"
    When I click "Resource @timestamp"
    Then the response Content-Type should be "application/pdf"

  @prc-1434
  Scenario: PRC-1434 Admin view
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "formative-instructional-tasks"
    Then I should see the link "Add Resource"
    And I should see the text "URL for Seraph"