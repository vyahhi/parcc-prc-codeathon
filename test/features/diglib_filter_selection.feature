@api @diglig @filter @prc-968 @prc-967
Feature: PRC-968 Search/Filter Bar: Filter the Digital Library Content
  As a user,
  I want to be able to filter any results in the Digital Library,
  so that I can refine the content in the Gallery.

#  Given that I am on Digital Library page
#  And the Filter menu is open
#  Scenario 1: Select one filter
#    When I click on one unselected filter
#    Then the Gallery refreshes with the filtered results

  Scenario: Select one filter
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
      | title      | body        | status | uid | field_subject | field_grade_level_unlimited | field_media_type |
      | Result One | First Body  | 1      | 1   | Filter Me One | GL One                      | Media Uno        |
      | Result Two | Second Body | 1      | 1   | Filter Me Two | GL Two                      | Media Deux       |
    And I am on the homepage
    And I index search results
    When I am on "library"
    Then I should see the link "Result One"
    And I should see the link "Result Two"
    When I click "GL One"
    Then I should see the link "Result One"
    But I should not see the link "Result Two"
    # Scenario 3
    # When I select more than one filter from the same category
    # Then I should see the results matching both of the filters
    When I click "GL Two"
    Then I should see the link "Result One"
    And I should see the link "Result Two"

#  Scenario 2: Deselect one filter
#    When I click on one selected filter
#    And press the Update button/link
#    Then the Gallery refreshes with the filtered results
# Can't test without JS

  Scenario: Select filters from different menu sections
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
      | Media Tres |
    And "Digital Library Content" nodes:
      | title        | body        | status | uid | field_subject | field_grade_level_unlimited | field_media_type |
      | Result One   | First Body  | 1      | 1   | Filter Me One | GL One                      | Media Uno        |
      | Result Two   | Second Body | 1      | 1   | Filter Me Two | GL Two                      | Media Deux       |
      | Result Three | Third Body  | 1      | 1   | Filter Me Two | GL One                      | Media Tres       |
    And I am on the homepage
    And I index search results
    When I am on "library"
    Then I should see the link "Result One"
    And I should see the link "Result Two"
    And I should see the link "Result Three"
    When I click "GL One"
    Then I should see the link "Result One"
    And I should see the link "Result Three"
    But I should not see the link "Result Two"
    When I click "Filter Me Two"
    Then I should see the link "Result Three"
    But I should not see the link "Result One"
    And I should not see the link "Result Two"

#  Scenario 5: No results
#    When I press the Update button/link
#    And there are no search results
#    Then I see the following message:
#  There are no results to display. Please change your search or filter selections and try again.
  @prc-967
  Scenario: Filters with no results don't show up
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
      | Media Tres |
    And "Digital Library Content" nodes:
      | title        | body        | status | uid | field_subject | field_grade_level_unlimited | field_media_type |
      | Result One   | First Body  | 1      | 1   | Filter Me Two | GL One                      | Media Uno        |
      | Result Two   | Second Body | 1      | 1   | Filter Me Two | GL One                      | Media Deux       |
      | Result Three | Third Body  | 1      | 1   | Filter Me Two | GL One                      | Media Uno        |
    And I am on the homepage
    And I index search results
    When I am on "library"
    Then I should not see the link "Filter Me One"
    And I should not see the link "GL Two"
    And I should not see the link "Media Tres"
    But I should see the link "Filter Me Two"
    And I should see the link "GL One"
    And I should see the link "Media Uno"
    And I should see the link "Media Deux"
