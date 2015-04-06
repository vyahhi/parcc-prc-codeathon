@api @diglib @filter @prc-965
Feature: PRC-965 Search/Filter Bar: Search for Digital Library Content
  As a user,
  I want to search through Digital Library content based on entering metadata,
  so that I find content specific for my needs.

#  Given that I am on Digital Library page
#  When I enter a search string in the search field on the Search/Filter Bar
#  And I press the Search button/icon
#  Then any current Search or Filter selections are reset
#  And I see my search string displayed in the search field on the Search/Filter Bar
#  Scenario 1: Search results
#    And there are search results
#    And I see the results in the Gallery
#  Scenario 2: No search results
#    And there are no search results
#    Then I see the following message:
#  There are no results to display. Please change the search or filter selections and try again.

  Scenario: Search results
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
      | title        | body              | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One   | First Body Alpha  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two   | Second Body Bravo | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Three | Third Body Alpha  | 1      | 1   | Filter Me Two | GL One            | Media Tres       |
    And I am on the homepage
    And I index search results
    When I am on "digital-library"
    Then I should see the link "Result One"
    And I should see the link "Result Two"
    And I should see the link "Result Three"
    And I fill in "edit-search-api-views-fulltext" with "Alpha"
    And I press "Apply"
    Then I should see the link "Result One"
    And I should see the link "Result Three"
    But I should not see the link "Result Two"
    And I fill in "edit-search-api-views-fulltext" with "Bravo"
    And I press "Apply"
    Then I should see the link "Result Two"
    But I should not see the link "Result One"
    And I should not see the link "Result Three"

  Scenario: No results
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
      | title        | body              | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One   | First Body Alpha  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two   | Second Body Bravo | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Three | Third Body Alpha  | 1      | 1   | Filter Me Two | GL One            | Media Tres       |
    And I am on the homepage
    And I index search results
    When I am on "digital-library"
    Then I should see the link "Result One"
    And I should see the link "Result Two"
    And I should see the link "Result Three"
    And I fill in "edit-search-api-views-fulltext" with "Nothing"
    And I press "Apply"
    Then I should see the text "There are no results to display. Please change the search or filter selections and try again."
    And I should not see the link "Result One"
    And I should not see the link "Result Three"
    And I should not see the link "Result Two"
