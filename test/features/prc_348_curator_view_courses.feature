@api
Feature: PRC-348 Admin: View Courses List
  As a Content Admin,
  I want to view the PD courses already created in PRC,
  so that I can manage the existing courses and add more if needed.

#  A new tab Course Management shall be added to the top navigation bar for the following roles:
#  Content Administrator (Curator)
#  PRC Admin
#  At click, it redirects the user to a new PRC Courses page
#  This page contains:
#  An Add Course button/link (defined in PRC-69)
#  A filter textbox to allow filtering the content of the table defined below
#  A table containing available courses
#  The table contains the following fields:
#  ID: (course ID)
#  Title: (course Title)
#  Created On: (The date the course was created)
#  Last Updated: (The most recent date the course was updated)
#  Permission: (Public vs. PARCC members ONLY)
#  Published: (Y/N) , or published / Unpublished
#  # of Modules/Quizzes: (adds up all the objects within the course, whether module or quiz) for this story, all rows have zero count
#  An Actions column containing an Actions button (non-functional in this story)
#  All columns (except for Actions) are sortable. Default sort is by ID Ascending
#  Pagination: 100 per page -use the default pagination: e.g. first previous 1 2 3 4 .... 26 next last
#  If user is on the first page, the first link is disabled.
#  If user is on the last page, the last link is disabled.

  Scenario Outline: AC1 Has Course Management Tab by role
    Given I am logged in as a user with the "<role>" role
    And I am on the homepage
    Then I should see the link "Course Management"
    Examples:
      | role                            |
      | administrator                   |
      | PRC Admin                       |
      | Content Administrator (Curator) |

  Scenario Outline: AC1 Does not have Course Management Tab by role
    Given I am logged in as a user with the "<role>" role
    And I am on the homepage
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

  Scenario: View PD Courses
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on the homepage
    When I follow "Course Management"