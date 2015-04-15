@api @course @external @leo @prc-1177
Feature: PRC-1177 LEO Learning module: PARCC Accessibility System
  As a user
  I want to access the PARCC Accessibility System​ module
  so that I can learn about the PARCC Accessibility System​.

#  Given that I am a user
#  And I am on the Professional Development page
#  When I click on the PARCC Accessibility System​ link
#  Then I see the PARCC Accessibility System​ content
#  Note: Per Peter 3-27-15, everyone can access module. No restriction by log in status, PARCC membership, state or user's email address.

  Scenario: Course does not have link
    Given "PD Course" nodes:
      | title       | uid | field_course_objectives | field_permissions | status |
      | PRC-349 AC2 | 1   | objectives              | public            | 1      |
    And I am logged in as a user with the "Educator" role
    And I visit the last node created
    Then I should see the link "Take course"

  Scenario: Course has link
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And "PD Course" nodes:
      | title       | uid         | field_course_objectives | field_permissions | status |
      | PRC-349 AC2 | @currentuid | objectives              | public            | 1      |
    And I visit the last node created
    And I click "Edit"
    And I fill in "edit-field-link-to-a-url-und-0-title" with "External Link"
    And I fill in "edit-field-link-to-a-url-und-0-url" with "http://www.google.com"
    And I press "Save"
    Then I should not see the link "Take course"

  Scenario: Anonymous can see link
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And "PD Course" nodes:
      | title       | uid         | field_course_objectives | field_permissions | status |
      | PRC-349 AC2 | @currentuid | objectives              | public            | 1      |
    And I visit the last node created
    And I click "Edit"
    And I fill in "edit-field-link-to-a-url-und-0-title" with "External Link"
    And I fill in "edit-field-link-to-a-url-und-0-url" with "http://www.google.com"
    And I press "Save"
    And I am an anonymous user
    And I visit the first node created
    Then I should not see the link "Take course"
