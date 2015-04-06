@api @diglib @sort @prc-962 @flag
Feature: PRC-982 Search/Filter Bar: Sorting Results
  As a user, I want to be able to sort the items in the Digital Library gallery so that I can find the items that I want.

  Scenario: 1: Default
    Given I have no "Digital Library Content" nodes
    And I am logged in as a user with the "Educator" role
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
      | title            | body        | status | uid | field_subject | field_grade_level | field_media_type | created    | changed                                |
      | Result One One   | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        | 1418362114 | 1418362114
      | Result One Two   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       | 1418362214 | 1418362214
      | Result One Three | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        | 1418362314 | 1418362314
      | Result One Four  | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       | 1418362414 | 1418362414
      | Result One Five  | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        | 1418362514 | 1418362514
      | Result One Six   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       | 1418362614 | 1418362614
      | Result One Seven | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        | 1418362714 | 1418362714
      | Result One Eight | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       | 1418362814 | 1418362814
      | Result One Nine  | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        | 1418362914 | 1418362914
      | Result One Ten   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       | 1418363014 | 1418363014
      | Result Two One   | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        | 1418363114 | 1418363114
      | Result Two Two   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       | 1418363214 | 1418363214
      | Result Two Three | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        | 1418363314 | 1418363314
      | Result Two Four  | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       | 1418363414 | 1418363414
      | Result Two Five  | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        | 1418363514 | 1418363514
      | Result Two Six   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       | 1418363614 | 1418363614
      | Result Two Seven | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        | 1418363714 | 1418363714
      | Result Two Eight | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       | 1418363814 | 1418363814
      | Result Two Nine  | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        | 1418363914 | 1418363914
      | Result Two Ten   | Second Body | 1      | 1   | Filter Me Two | GL Two            | Media Deux       | 1418364014 | 1418364014    And I am on the homepage
    And I flag "Result Two One" with "Like Content"
    And I flag "Result One One" with "Like Content"
    And I flag "Result Two Three" with "Like Content"
    And I flag "Result One Seven" with "Like Content"
    And I index search results
    When I am on "digital-library"

    And I select "Popularity" from "Sort by"
    And I select "Desc" from "Order"
    And I press "Apply"
    Then "Result Two Three" should precede "Result One Four" for the query "a"
    Then "Result One Seven" should precede "Result One Six" for the query "a"

    When I select "Date" from "Sort by"
    Then I select "Asc" from "Order"
    And I press "Apply"
    Then "Result One One" should precede "Result One Two" for the query "a"
    Then "Result One Nine" should precede "Result Two One" for the query "a"
    Then "Result Two Two" should precede "Result Two Three" for the query "a"
    Then "Result One Seven" should precede "Result One Eight" for the query "a"


    Then I select "Date" from "Sort by"
    And I select "Desc" from "Order"
    And I press "Apply"

    # This is not working in Mink. Every other sort works, and this sort works when
    # testing manually, but it doesn't work here.