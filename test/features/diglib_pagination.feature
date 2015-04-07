@api @diglib @pagination @filter @prc-981
Feature: PRC-981 Search/Filter Bar: Pagination
  As a user, I want to be able to page through Digital Library content so that I don't have to scroll through long lists.

#  Given that I am on Digital Library page
#  And the number of results is > 20
#  Then I see pagination:
#  Pagination
#  Display 20 per page -use the default pagination: e.g. first previous 1 2 3 4 .... 26 next last
#  If user is on the first page, the first link is disabled.
#  If user is on the last page, the last link is disabled.

  Scenario: Pagination
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
      | title            | body        | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One       | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two       | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Three     | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Four      | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Five      | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Six       | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Seven     | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Eight     | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Nine      | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Ten       | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result One One   | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result One Two   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result One Three | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result One Four  | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result One Five  | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result One Six   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result One Seven | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result One Eight | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result One Nine  | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result One Ten   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Two One   | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two Two   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Two Three | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two Four  | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Two Five  | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two Six   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Two Seven | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two Eight | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Two Nine  | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two Ten   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
    And I am on the homepage
    And I index search results
    When I am on "digital-library"
    Then I should not see the link "first"
    And I should not see the link "prev"
    But I should see the link "next"
    And I should see the link "last"
    And I should not see the link "\b1\b"
    But I should see the text "1"
    And I should see the link "2"
    And I should not see the link "\b3\b"
    When I click "2"
    Then I should see the link "first"
    And I should see the link "prev"
    And I should not see the link "next"
    And I should not see the link "last"
    And I should see the text "2"
    But I should not see the link "\b2\b"

  Scenario: No pagination
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
      | title            | body        | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One       | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two       | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Three     | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Four      | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Five      | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Six       | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Seven     | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Eight     | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Nine      | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Ten       | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result One One   | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result One Two   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result One Three | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result One Four  | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result One Five  | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result One Six   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result One Seven | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result One Eight | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result One Nine  | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result One Ten   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
    And I am on the homepage
    And I index search results
    When I am on "digital-library"
    Then I should not see the link "first"
    And I should not see the link "prev"
    And I should not see the link "\b1\b"
    And I should not see the link "\b2\b"
    And I should not see the link "\b3\b"
    And I should not see the link "next"
    And I should not see the link "last"
    # Add one more to tip over the page max
    And "Digital Library Content" nodes:
      | title            | body        | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One       | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
    And I index search results
    When I am on "digital-library"
    Then I should not see the link "first"
    And I should not see the link "prev"
    But I should see the link "next"
    And I should see the link "last"
    And I should not see the link "\b1\b"
    But I should see the text "1"
    And I should see the link "2"
