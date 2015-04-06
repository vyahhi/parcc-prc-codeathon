@api @diglig @filter @prc-980
Feature: PRC-980 Search/Filter Bar: View All
  As a user, I want to be able to clear any of my searches and/or filter selections so that I may see all the items in the Digital Library gallery.

#  Given that I am on Digital Library page
#  Scenario 1: Default state
#    And the Gallery is not affected from a search and/or filter selections
#    Then the View All state is disabled
#  Scenario 2: Active state
#    And the Gallery is affected from a search and/or filter selections
#    Then the View All state is enabled
#  Scenario 3: Using View All
#    And the Gallery is affected from a search and/or filter selections
#    When I press on the View All button/link
#    Then the search and/or filter selections are cleared
#    And the View All button state is updated to disabled

  Scenario: Default to View All
    Given I have no "Digital Library Content" nodes
    And "Subject" terms:
      | name          |
      | Filter Me One |
      | Filter Me Two |
    And "Grade Level" terms:
      | name   |
      | GL One |
      | GL Two |
    And "Media Type" terms:
      | name       |
      | Media Uno  |
      | Media Deux |
    And "Digital Library Content" nodes:
      | title      | body        | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
    And I am on the homepage
    And I index search results
    When I am on "digital-library"
    Then I should see the link "Result One"
    And I should see the link "Result Two"
    And I should see the text "View All"

  Scenario: View all from active filter
    Given I have no "Digital Library Content" nodes
    And "Subject" terms:
      | name          |
      | Filter Me One |
      | Filter Me Two |
    And "Grade Level" terms:
      | name   |
      | GL One |
      | GL Two |
    And "Media Type" terms:
      | name       |
      | Media Uno  |
      | Media Deux |
    And "Digital Library Content" nodes:
      | title      | body        | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
    And I am on the homepage
    And I index search results
    When I am on "digital-library"
    And I fill in "edit-search-api-views-fulltext" with "Bravo"
    And I press "Apply"
    Then I should not see the link "Result One"
    And I should not see the link "Result Two"
    And I should not see the text "View All"
    When I click "View All"
    Then I should not see the link "Result One"
    And I should not see the link "Result Two"
    And I should not see the text "View All"
    And the "edit-search-api-views-fulltext" field should contain ""