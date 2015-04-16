@api @d7 @styleguide @prc-542
Feature: Gallery View Responsive behavior – Digital Library
  As a user
  I want my view of the Digital Library gallery to be responsive
  so that I can easily view the content on different devices.

  ##### Digital Library Gallery View #####

  @javascript
  Scenario: Footer responsive behavior matches style guide
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
      | Result Two       | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
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
    And I index search results
    And I am on "digital-library"
    When I am browsing using a "phone"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    And ".view-digital-library-gallery div:first-child" should have an "class" attribute value of "view-filters"
    And ".view-digital-library-gallery .columns" should have a "width" css value of "300px"
    When I am browsing using a "tablet"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    And ".view-digital-library-gallery div:first-child" should have an "class" attribute value of "view-filters"
    And ".view-digital-library-gallery .columns" should have a "width" css value of "332px"
    And ".view-digital-library-gallery .view-content" should have a "position" css value of "relative"
    And ".view-digital-library-gallery .columns" should have a "position" css value of "absolute"
    When I am browsing using a "desktop"
    Then ".main" should have a "padding-left" css value of "30px"
    And ".main" should have a "padding-right" css value of "30px"
    And ".view-digital-library-gallery div:first-child" should have an "class" attribute value of "view-filters"
    And ".view-digital-library-gallery .columns" should have a "width" css value of "342px"
    And ".view-digital-library-gallery .view-content" should have a "position" css value of "relative"
    And ".view-digital-library-gallery .columns" should have a "position" css value of "absolute"

