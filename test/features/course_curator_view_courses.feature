@api @course
Feature: PRC-348 Admin: View Courses List
  As a Content Admin,
  I want to view the PD courses already created in PRC,
  so that I can manage the existing courses and add more if needed.

  Scenario Outline: AC1 Has Course Management Tab by role
    Given I am logged in as a user with the "<role>" role
    And I am on "prc/admin"
    Then I should see the link "Course Management"
    Examples:
    | role                            |
    | administrator                   |
    | PRC Admin                       |
    | Content Administrator (Curator) |

  Scenario Outline: AC1 Does not have Course Management Tab by role
    Given I am logged in as a user with the "<role>" role
    And I am on "prc/admin"
    Then I should not see the link "Course Management"
    Examples:
    | role                  |
    | Educator              |
    | PARCC-Member Educator |
    | Content Contributor   |

  Scenario: AC1 Anon does not have Course Management tab
    Given I am an anonymous user
    And I am on the homepage
    Then I should not see the link "Course Management"

  Scenario: AC2 At click, it redirects the user to a new PRC Courses page
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "prc/admin"
    When I click "Course Management"
    Then I should be on "prc/admin/admin-course"
    And I should see the heading "PRC Courses" in the "sub_header" region

  Scenario: AC3 This page contains:
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "prc/admin/admin-course"
    Then I should see the link "Add course" in the "content" region

  Scenario: AC4 The table contains the following fields:
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PD Course PRC-348 AC4"
    And I am on "prc/admin"
    When I follow "Course Management"
    Then I should see the link "ID"
    And I should see the link "Title"
    And I should see the link "Created On"
    And I should see the link "Last Updated"
    And I should see the link "Permission"
    And I should see the link "Published"
    And I should see the text "# of Modules/Quizzes"
    And I should see the text "Actions"

  Scenario: Curator should be able to see all published courses, not just their own
    Given I have no "PD Course" nodes
    And I am logged in as a user with the "Content Administrator (Curator)" role
    And "PD Course" nodes:
    | title  | uid         | status |
    | Mine   | @currentuid | 1      |
    | Theirs | 1           | 1      |
    And I am on "prc/admin"
    When I follow "Course Management"
    Then I should see the text "Mine"
    And I should see the text "Theirs"

  Scenario: Curator should be able to see all unpublished courses, not just their own
    Given I have no "PD Course" nodes
    And I am logged in as a user with the "Content Administrator (Curator)" role
    And "PD Course" nodes:
      | title  | uid         | status |
      | Mine   | @currentuid | 0      |
      | Theirs | 1           | 0      |
    And I am on "prc/admin"
    When I follow "Course Management"
    Then I should see the text "Mine"
    And I should see the text "Theirs"

  Scenario: AC6 Pagination: 100 per page -use the default pagination: e.g. first previous 1 2 3 4 .... 26 next last
    Given I have no "PD Course" nodes
    And I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "prc/admin/admin-course"
    And I should not see the link "first"
    And I should not see the link "previous"
    And I should not see the link "next"
    And I should not see the link "last"

    And I run drush "genc 100 --kill --types=pd_course"
    And I am on "prc/admin"
    Then I follow "Course Management"
    And I should not see the link "first"
    And I should not see the link "previous"
    And I should not see the link "next"
    And I should not see the link "last"

    And I run drush "genc 1 --types=pd_course"
    And I am on "prc/admin"
    Then I follow "Course Management"
    And I should not see the link "first"
    And I should not see the link "previous"
    And I should see the link "next"
    And I should see the link "last"

    Then I follow "next"
    And I should see the link "first"
    And I should see the link "previous"
    And I should not see the link "next"
    And I should not see the link "last"

  Scenario: A filter textbox to allow filtering the content of the table defined below
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I have no "PD Course" nodes
    And "PD Course" nodes:
      | title     | body            | uid         | created    | status |
      | One       | One@timestamp   | @currentuid | 1410000100 | 1      |
      | Two       | Two@timestamp   | @currentuid | 1410000200 | 1      |
      | Three     | Three@timestamp | @currentuid | 1410000300 | 1      |
      | Fifty One | Four@timestamp  | @currentuid | 1410000400 | 1      |
    Then I visit "prc/admin/admin-course"
    Then I should see the text "One"
    And I should see the text "Fifty One"
    And I should see the text "Two"
    And I should see the text "Three"
    And I should see the text "0"
    And I should see a "Filter all columns" field
    And I should see an "Apply" button
    When I fill in "Filter all columns" with "one"
    And I press "Apply"
    Then I should see the text "One"
    Then I should see the text "Fifty One"
    But I should not see the text "Two"
    But I should not see the text "Three"

  Scenario: PRC-479 Date format
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I have no "PD Course" nodes
    And "PD Course" nodes:
      | title     | body            | uid         | created    | status |
      | One       | One@timestamp   | @currentuid | 1410000100 | 1      |
    Then I visit "prc/admin/admin-course"
    Then I should see the text "One"
    And I should not see the text "Saturday, September 6, 2014"
    And I should see the text "09/06/2014 - 05:41"