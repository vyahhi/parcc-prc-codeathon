@api @k2 @fit @prc-1226 @prc-1433 @prc-1434
Feature: PRC-1410 Speaking and Listening page - Regulars View
  As a PARCC-member Educator, I want to be able to view Formative Instructional Tasks resources.

  Background:
    Given formative instructional task content:
      | resource name       | resource type | file                          | faux standard | faux subject | grade level | permissions |
      | Resource @timestamp | Task          | testfiles/GreatLakesWater.pdf | Standard      | Subject      | 1st Grade   | public      |

  Scenario Outline: Resource View
    Given I am logged in as a user with the "<role>" role
    When I am on "instructional-tools/formative-instructional-tasks"
    Then I should see the heading "Formative Instructional Tasks"
    And I should see the text "There are 16 ELA and 16 Math performance tasks \(Kindergarten \– Gr.2\) which can be accessed in the table below."
    And I should see the text "The tasks are designed to engage students in learning while you observe how students demonstrate proficiencies with respect to the standards embedded in the tasks."
    And I should see the text "Your observations can be easily recorded using the formative tools \(e.g., checklists\) which can then be used to inform instructional decisions."
    And I should see the text "In the table below, there are three files for each ELA task; one that provides access to the actual performance task, one that provides the copyrighted text, and one that provides resources that accompany the task."
    And I should see the text "You will need all 3 ELA files in order to do the task with your students."
    And I should see the text "There are also three files for each math task; one that provides access to the full task, one that contains additional checklists besides the one already embedded in the full task file, and one that provides resources that accompany the task."
    And I should see the text "Note that the resources for math are embedded in the full task files; therefore, you may choose to only access the full task files when doing math tasks with your students."
    And I should see the text "Resource Name"
    And I should see the text "Subject"
    And I should see the text "Grade Level"
    And I should see the text "Resource Type"
    But I should not see the link "Edit"
    And I should not see the link "Add Resource"
    And I should not see the text "URL for Seraph"
    And I should see the link "Resource @timestamp"
  Examples:
    | role                            |
    | Educator                        |
    | PARCC-Member Educator           |
    | Content Contributor             |
    | Content Administrator (Curator) |
    | PARCC Item Author               |
    | State Admin                     |
    | District Admin                  |
    | School Admin                    |

  @prc-1519 @educator
  Scenario: Educators can see
    Given I am logged in as a user with the "Educator" role
    And I am on "instructional-tools"
    Then I should see an "Formative Instructional Tasks" link

  @prc-1519 @anonymous
  Scenario: Anonymous can't see
    Given I am an anonymous user
    And I am on "instructional-tools"
    Then I should not see the link "Formative Instructional Tasks"
    And I should see the text "Access Denied"

  @prc-1398
  Scenario: PRC-1398 View Resource name link
    Given I am logged in as a user with the "PARCC-Member Educator" role
    And I am on "instructional-tools/formative-instructional-tasks"
    When I click "Resource @timestamp"
    Then the response Content-Type should be "application/pdf"

  @prc-1434
  Scenario: PRC-1434 Admin view
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "instructional-tools/formative-instructional-tasks"
    Then I should see the link "Add Resource"
    And I should see the text "URL for Seraph"

  @prc-1863
  Scenario: Pager displays at 25 results
    Given I have no "Formative Instructional Task" nodes
    And I run drush "genc 20 --types=formative_instructional_task"
    And I am logged in as a user with the "PRC Admin" role
    And I am on "instructional-tools/formative-instructional-tasks"
    Then I should not see the link "next ›"
    And I run drush "genc 10 --types=formative_instructional_task"
    And I am on "instructional-tools/formative-instructional-tasks"
    Then I should see the link "next ›"