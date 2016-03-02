@api @d7 @styleguide @prc-542 @prc-752 @prc-1028 @diglib
Feature: Gallery View Responsive behavior – Digital Library (PRC-542)
  As a user
  I want my view of the Digital Library gallery to be responsive
  so that I can easily view the content on different devices.

  As a user (PRC-1028)
  I want to know that state of the Filters Menu on the Digital Library Search/Filter Bar
  so that I can understand the condition of my filter selections

  #### Digital Library Filter Panel ####

  @javascript
  Scenario: Open status
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
      | title      | body                                                                                                                                                                                                                                                                                                                                                                                                                                                         | status | uid | field_subject | field_grade_level_unlimited | field_media_type |
      | Result One | First Body                                                                                                                                                                                                                                                                                                                                                                                                                                                   | 1      | 1   | Filter Me One | GL One                      | Media Uno        |
      | Result Two | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two                      | Media Deux       |
    And I index search results
    And I am on "library"
    When I am browsing using a "phone"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(248, 248, 248)"
    And ".filter-panel-toggle" should have a "display" css value of "none"
    When I click on the element with css selector ".filter-panel-toggle-link"
    Then "#filter-panel-filters" should have a "display" css value of "block"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(112, 84, 125)"

  @javascript
  Scenario: Filtered status
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
      | title      | body                                                                                                                                                                                                                                                                                                                                                                                                                                                         | status | uid | field_subject | field_grade_level_unlimited | field_media_type |
      | Result One | First Body                                                                                                                                                                                                                                                                                                                                                                                                                                                   | 1      | 1   | Filter Me One | GL One                      | Media Uno        |
      | Result Two | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two                      | Media Deux       |
    And I index search results
    And I am on "library"
    When I am browsing using a "phone"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(248, 248, 248)"
    And ".filter-panel-toggle" should have a "display" css value of "none"
    When I click on the element with css selector ".filter-panel-toggle-link"
    And I click "Media Uno"
    And I click on the element with css selector ".filter-panel-toggle-link"
    Then "#filter-panel-filters" should have a "display" css value of "none"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(112, 84, 125)"

  @javascript
  Scenario: Default status
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
      | title      | body                                                                                                                                                                                                                                                                                                                                                                                                                                                         | status | uid | field_subject | field_grade_level_unlimited | field_media_type |
      | Result One | First Body                                                                                                                                                                                                                                                                                                                                                                                                                                                   | 1      | 1   | Filter Me One | GL One                      | Media Uno        |
      | Result Two | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two                      | Media Deux       |
    And I index search results
    And I am on "library"
    When I am browsing using a "phone"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(248, 248, 248)"
    And ".filter-panel-toggle" should have a "display" css value of "none"

  @javascript
  Scenario: Selected
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
      | title      | body                                                                                                                                                                                                                                                                                                                                                                                                                                                         | status | uid | field_subject | field_grade_level_unlimited | field_media_type |
      | Result One | First Body                                                                                                                                                                                                                                                                                                                                                                                                                                                   | 1      | 1   | Filter Me One | GL One                      | Media Uno        |
      | Result Two | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two                      | Media Deux       |
    And I index search results
    And I am on "library"
    When I am browsing using a "phone"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(248, 248, 248)"
    And ".filter-panel-toggle" should have a "display" css value of "none"
    When I click on the element with css selector ".filter-panel-toggle-link"
    And I click "Media Uno"
    Then "#filter-panel-filters" should have a "display" css value of "block"
    And "#facetapi-facet-search-apidigital-library-only-block-field-media-type a.filter-selected" should have a "background-color" css value of "rgb(52, 71, 89)"

  @javascript
  Scenario: Unselected
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
      | title      | body                                                                                                                                                                                                                                                                                                                                                                                                                                                         | status | uid | field_subject | field_grade_level_unlimited | field_media_type |
      | Result One | First Body                                                                                                                                                                                                                                                                                                                                                                                                                                                   | 1      | 1   | Filter Me One | GL One                      | Media Uno        |
      | Result Two | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two                      | Media Deux       |
    And I index search results
    And I am on "library"
    When I am browsing using a "phone"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(248, 248, 248)"
    And ".filter-panel-toggle" should have a "display" css value of "none"
    When I click on the element with css selector ".filter-panel-toggle-link"
    Then "#filter-panel-filters" should have a "display" css value of "block"
    And "#facetapi-facet-search-apidigital-library-only-block-field-media-type a:first-child" should have a "background-color" css value of ""

  @javascript @prc-1553 @filter @gradelevel
  Scenario: Sort order for grade level facets
    Given I have no "Digital Library Content" nodes
    # Use existing Subject, Grade Level, Media Type, because these are set up on install
    And "Digital Library Content" nodes:
      | title           | body                                 | status | uid | field_subject              | field_grade_level_unlimited | field_media_type |
      | Result One      | First Body                           | 1      | 1   | Math                       | 1st Grade                   | Text             |
      | Result Two      | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                    | 11th Grade                  | Text             |
      | Result Three    | First Body                           | 1      | 1   | Educational Leadership     | 12th Grade                  | Text             |
      | Result Four     | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 2nd Grade                   | Text             |
      | Result Five     | First Body                           | 1      | 1   | History/Social Studies     | 4th Grade                   | Text             |
      | Result Six      | Lorem ipsum doloranim id est laborum | 1      | 1   | World Languages            | 3rd Grade                   | Text             |
      | Result Seven    | First Body                           | 1      | 1   | Visual and Performing Arts | 7th Grade                   | Text             |
      | Result Eight    | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                    | 8th Grade                   | Text             |
      | Result Nine     | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 6th Grade                   | Text             |
      | Result Ten      | First Body                           | 1      | 1   | History/Social Studies     | 5th Grade                   | Text             |
      | Result Eleven   | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 9th Grade                   | Text             |
      | Result Twelve   | First Body                           | 1      | 1   | History/Social Studies     | 10th Grade                  | Text             |
      | Result Thirteen | First Body                           | 1      | 1   | History/Social Studies     | Kindergarten                | Text             |
      | Result Fourteen | Lorem ipsum doloranim id est laborum | 1      | 1   | World Languages            | Pre-K                       | Text             |
    And I index search results
    When I am on "library"
    Then " Apply Pre-K filter " should precede " Apply Kindergarten filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply Kindergarten filter " should precede " Apply 1st Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply 1st Grade filter " should precede " Apply 2nd Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply 2nd Grade filter " should precede " Apply 3rd Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply 3rd Grade filter " should precede " Apply 4th Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply 4th Grade filter " should precede " Apply 5th Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply 5th Grade filter " should precede " Apply 6th Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply 6th Grade filter " should precede " Apply 7th Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply 7th Grade filter " should precede " Apply 8th Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply 8th Grade filter " should precede " Apply 9th Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply 9th Grade filter " should precede " Apply 10th Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply 10th Grade filter " should precede " Apply 11th Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"
    Then " Apply 11th Grade filter " should precede " Apply 12th Grade filter " for the query ".facetapi-facet-field-grade-level-unlimited label"

  @javascript @prc-1553 @filter @subject @prc-1558
  Scenario: Sort order for subject facets
    Given I have no "Digital Library Content" nodes
# Use existing Subject, Grade Level, Media Type, because these are set up on install
    And "Digital Library Content" nodes:
      | title         | body                                 | status | uid | field_subject              | field_grade_level_unlimited | field_media_type |
      | Result One    | First Body                           | 1      | 1   | Math                       | 1st Grade                   | Text             |
      | Result Two    | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                    | 11th Grade                  | Text             |
      | Result Three  | First Body                           | 1      | 1   | Educational Leadership     | 12th Grade                  | Text             |
      | Result Four   | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 2nd Grade                   | Text             |
      | Result Five   | First Body                           | 1      | 1   | History/Social Studies     | 4th Grade                   | Text             |
      | Result Six    | Lorem ipsum doloranim id est laborum | 1      | 1   | World Languages            | 3rd Grade                   | Text             |
      | Result Seven  | First Body                           | 1      | 1   | Visual and Performing Arts | 7th Grade                   | Text             |
      | Result Eight  | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                    | 8th Grade                   | Text             |
      | Result Nine   | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 6th Grade                   | Text             |
      | Result Ten    | First Body                           | 1      | 1   | History/Social Studies     | 5th Grade                   | Text             |
      | Result Eleven | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 9th Grade                   | Text             |
      | Result Twelve | First Body                           | 1      | 1   | History/Social Studies     | 10th Grade                  | Text             |
    And I index search results
    When I am on "library"
    Then " Apply Educational Leadership filter " should precede " Apply History/Social Studies filter " for the query ".facetapi-facet-field-subject label"
    Then " Apply History/Social Studies filter " should precede " Apply Math filter " for the query ".facetapi-facet-field-subject label"
    Then " Apply Math filter " should precede " Apply Science filter " for the query ".facetapi-facet-field-subject label"
    Then " Apply Science filter " should precede " Apply STEM filter " for the query ".facetapi-facet-field-subject label"
    Then " Apply STEM filter " should precede " Apply Visual and Performing Arts filter " for the query ".facetapi-facet-field-subject label"
    Then " Apply Visual and Performing Arts filter " should precede " Apply World Languages filter " for the query ".facetapi-facet-field-subject label"

  @javascript @prc-1553 @filter @mediatype @prc-1558
  Scenario: Sort order for media type facets
    Given I have no "Digital Library Content" nodes
# Use existing Subject, Grade Level, Media Type, because these are set up on install
    And "Digital Library Content" nodes:
      | title        | body                                 | status | uid | field_subject          | field_grade_level_unlimited | field_media_type |
      | Result One   | First Body                           | 1      | 1   | Math                   | 1st Grade                   | Audio            |
      | Result Two   | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                | 11th Grade                  | Text             |
      | Result Three | First Body                           | 1      | 1   | Educational Leadership | 12th Grade                  | Video            |
      | Result Four  | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                   | 2nd Grade                   | Image            |
    And I index search results
    When I am on "library"
    Then " Apply Audio filter " should precede " Apply Image filter " for the query ".facetapi-facet-field-media-type label"
    Then " Apply Image filter " should precede " Apply Text filter " for the query ".facetapi-facet-field-media-type label"
    Then " Apply Text filter " should precede " Apply Video filter " for the query ".facetapi-facet-field-media-type label"

  @javascript @filter @prc-1682 @prc-1683
  Scenario: Filter panel should be closed on second page of unfiltered results
    Given I have no "Digital Library Content" nodes
    And "Digital Library Content" nodes:
      | title         | body                                 | status | uid | field_subject              | field_grade_level_unlimited | field_media_type |
      | Result One    | First Body                           | 1      | 1   | Math                       | 1st Grade                   | Text             |
      | Result Two    | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                    | 11th Grade                  | Text             |
      | Result Three  | First Body                           | 1      | 1   | Educational Leadership     | 12th Grade                  | Text             |
      | Result Four   | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 2nd Grade                   | Text             |
      | Result Five   | First Body                           | 1      | 1   | History/Social Studies     | 4th Grade                   | Text             |
      | Result Six    | Lorem ipsum doloranim id est laborum | 1      | 1   | World Languages            | 3rd Grade                   | Text             |
      | Result Seven  | First Body                           | 1      | 1   | Visual and Performing Arts | 7th Grade                   | Text             |
      | Result Eight  | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                    | 8th Grade                   | Text             |
      | Result Nine   | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 6th Grade                   | Text             |
      | Result Ten    | First Body                           | 1      | 1   | History/Social Studies     | 5th Grade                   | Text             |
      | Result One One  | First Body                           | 1      | 1   | Math                       | 1st Grade                   | Text             |
      | Result One Two    | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                    | 11th Grade                  | Text             |
      | Result One Three  | First Body                           | 1      | 1   | Educational Leadership     | 12th Grade                  | Text             |
      | Result One Four   | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 2nd Grade                   | Text             |
      | Result One Five   | First Body                           | 1      | 1   | History/Social Studies     | 4th Grade                   | Text             |
      | Result One Six    | Lorem ipsum doloranim id est laborum | 1      | 1   | World Languages            | 3rd Grade                   | Text             |
      | Result One Seven  | First Body                           | 1      | 1   | Visual and Performing Arts | 7th Grade                   | Text             |
      | Result One Eight  | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                    | 8th Grade                   | Text             |
      | Result One Nine   | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 6th Grade                   | Text             |
      | Result Two Ten    | First Body                           | 1      | 1   | History/Social Studies     | 5th Grade                   | Text             |
      | Result Two One    | First Body                           | 1      | 1   | Math                       | 1st Grade                   | Text             |
      | Result Two Two    | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                    | 11th Grade                  | Text             |
      | Result Two Three  | First Body                           | 1      | 1   | Educational Leadership     | 12th Grade                  | Text             |
      | Result Two Four   | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 2nd Grade                   | Text             |
      | Result Two Five   | First Body                           | 1      | 1   | History/Social Studies     | 4th Grade                   | Text             |
      | Result Two Six    | Lorem ipsum doloranim id est laborum | 1      | 1   | World Languages            | 3rd Grade                   | Text             |
      | Result Two Seven  | First Body                           | 1      | 1   | Visual and Performing Arts | 7th Grade                   | Text             |
      | Result Two Eight  | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                    | 8th Grade                   | Text             |
      | Result Two Nine   | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 6th Grade                   | Text             |
      | Result Two Ten    | First Body                           | 1      | 1   | History/Social Studies     | 5th Grade                   | Text             |
    And I index search results
    When I am on "library"
    Then "#filter-panel-filters" should have a "display" css value of "none"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(248, 248, 248)"
    When I follow "next ›"
    Then "#filter-panel-filters" should have a "display" css value of "none"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(248, 248, 248)"
    When I click on the element with css selector ".filter-panel-toggle-link"
    Then ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(112, 84, 125)"
    When I follow "4th Grade (3)"
    Then "#filter-panel-filters" should have a "display" css value of "block"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(112, 84, 125)"
    When I click on the element with css selector ".filter-panel-toggle-link"
    Then "#filter-panel-filters" should have a "display" css value of "none"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(112, 84, 125)"