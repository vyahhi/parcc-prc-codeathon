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
    When I am on "instructional-tools/speaking-listening"
    Then I should see the heading "Speaking and Listening"
    And I should see the text "The Speaking and Listening Tools focus on the student's ability to engage in collaborative discussion, determine main ideas and supporting ideas from texts presented in a variety of multi-media formats, and to effectively present complex information and ideas to others. These skills are integral to all grade levels and content areas."
    And I should see the text "Resource Name"
    And I should see the text "Subject"
    And I should see the text "Grade Level"
    And I should see the text "Resource Type"
    And I should not see the link "Edit"

  @prc-1514 @educator
  Scenario: Educators can see
    Given I am logged in as a user with the "Educator" role
    And I am on "instructional-tools"
    Then I should see the link "Speaking and Listening"

  @prc-1514 @anonymous
  Scenario: Anonymous can't see
    Given I am an anonymous user
    And I am on "instructional-tools"
    Then I should not see the link "Speaking and Listening"

  Scenario: PRC-1433 S&L Resource name link
    Given I am logged in as a user with the "PARCC-Member Educator" role
    And I am on "instructional-tools/speaking-listening"
    When I click "Resource @timestamp"
    Then the response Content-Type should be "application/pdf"

  @prc-1863
  Scenario: Pager displays at 25 results
    Given I have no "Speaking and Listening Resource" nodes
    And I run drush "genc 20 --types=speaking_and_listening_resource"
    And I am logged in as a user with the "PRC Admin" role
    And I am on "instructional-tools/speaking-listening"
    # Test was failing with '2' so using next link instead to confirm pager.
    Then I should not see the link "next ›"
    And I run drush "genc 10 --types=speaking_and_listening_resource"
    And I am on "instructional-tools/speaking-listening"
    Then I should see the link "next ›"
