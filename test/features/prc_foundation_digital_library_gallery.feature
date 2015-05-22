@api @d7 @styleguide @prc-542 @prc-752 @prc-1028 @diglib
Feature: Gallery View Responsive behavior – Digital Library (PRC-542)
  As a user
  I want my view of the Digital Library gallery to be responsive
  so that I can easily view the content on different devices.

  Digital Library - Gallery View Theming (PRC-752)
  As a user
  I want my view of the Digital Library gallery to be responsive
  so that I can easily view the content on different devices.

  As a user (PRC-1028)
  I want to know that state of the Filters Menu on the Digital Library Search/Filter Bar
  so that I can understand the condition of my filter selections

  ##### Digital Library Gallery View #####

  @javascript
  Scenario: Digital Library responsive behavior matches style guide
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
    And I am on "library"
    When I am browsing using a "phone"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    And ".view-digital-library-gallery div:first-child" should have an "class" attribute value of "view-content"
    # TODO - Figure out why widths are drifting even though there seem to be no visual regressions.
    # And ".view-digital-library-gallery .columns" should have a "width" css value of "320.63340000000005px"
    When I am browsing using a "tablet"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    And ".view-digital-library-gallery div:first-child" should have an "class" attribute value of "view-content"
    # And ".view-digital-library-gallery .columns" should have a "width" css value of "322.63340000000005px"
    And ".view-digital-library-gallery .view-content" should have a "position" css value of "static"
    And ".view-digital-library-gallery .columns" should have a "position" css value of "absolute"
    When I am browsing using a "desktop"
    Then ".main" should have a "padding-left" css value of "30px"
    And ".main" should have a "padding-right" css value of "30px"
    And ".view-digital-library-gallery div:first-child" should have an "class" attribute value of "view-content"
    # And ".view-digital-library-gallery .columns" should have a "width" css value of "321.23339999999996px"
    And ".view-digital-library-gallery .view-content" should have a "position" css value of "static"
    And ".view-digital-library-gallery .columns" should have a "position" css value of "absolute"

  @javascript
  Scenario: Digital library theming matches style guide
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
      | Video      |
      | Audio      |
      | Image      |
      | Text       |
    And "Digital Library Content" nodes:
      | title            | body        | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One       | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two       | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
      | Result Three     | First Body  | 1      | 1   | Filter Me One | GL One            | Video        |
      | Result Four      | Second Body | 1      | 1   | Filter Me Two | GL Two            | Audio       |
      | Result Five      | First Body  | 1      | 1   | Filter Me One | GL One            | Image        |
      | Result Six       | Second Body | 1      | 1   | Filter Me Two | GL Two            | Text       |
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
    And I am on "library"
    When I am browsing using a "phone"
    Then "#page" should have a "background-color" css value of "rgb(255, 255, 255)"
    And "#sub-header" should have a "background-color" css value of "transparent"
    And "#sub-header .breadcrumb" should be visible
    And "#sub-header h1#page-title" should be visible
    And "#sub-header .breadcrumb" should have a "font-size" css value of "16px"
    And "#sub-header .breadcrumb" should have a "font-family" css value of "'Open Sans Condensed','Helvetica Neue',Helvetica,Arial,sans-serif"
    And "#sub-header .breadcrumb" should have a "color" css value of "rgb(70, 70, 70)"
    And "#sub-header .breadcrumb" should have a "font-weight" css value of "700"
    And "#sub-header .breadcrumb" should have a "padding-top" css value of "10px"
    And "#sub-header .breadcrumb" should have a "padding-bottom" css value of "0px"
    And "#sub-header .breadcrumb a" should have a "color" css value of "rgb(112, 84, 125)"
    And I hover over the element "#sub-header .breadcrumb a"
    And "#sub-header .breadcrumb a" should have a "text-decoration" css value of "underline"
    And "#sub-header h1" should have a "margin-top" css value of "6.4px"
    And "#sub-header h1" should have a "margin-bottom" css value of "16px"
    And "#sub-header h1" should have a "color" css value of "rgb(112, 84, 125)"
    And "#sub-header h1" should have a "font-size" css value of "32px"
    And "#sub-header h1" should have a "text-align" css value of "center"
    And "#main-wrapper.gallery-main" should have a "background-color" css value of "rgb(238, 238, 238)"
    And "#main-wrapper.gallery-main" should have a "border-top-color" css value of "rgb(219, 219, 219)"
    And "#main-wrapper.gallery-main" should have a "border-top-style" css value of "solid"
    And "#main-wrapper.gallery-main" should have a "border-top-width" css value of "1px"
    # TODO - Pagination
    # TODO - Adjust node creation to upload dummy images and then re-enable the step below.
    # And ".gallery-main .view-content .columns .field-name-field-thumbnail img" should have a "width" css value of "345px"
    And ".view-content .columns .field-name-title" should have a "margin-left" css value of "-12.1833px"
    And ".view-content .columns .field-name-title" should have a "margin-right" css value of "-12.1833px"
    And ".view-content .columns .field-name-title" should have a "padding-left" css value of "12.1833px"
    And ".view-content .columns .field-name-title" should have a "padding-right" css value of "55.25px"
    # And ".view-content .media-type-none .field-name-title" should have a "background-color" css value of "rgb(112, 84, 125)"
    # And ".view-content .media-type-none .field-name-title" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/text-icon.png')"
    And ".view-content .media-type-video .field-name-title" should have a "background-color" css value of "rgb(0, 53, 183)"
    And ".view-content .media-type-video .field-name-title" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/video-icon.png')"
    And ".view-content .media-type-audio .field-name-title" should have a "background-color" css value of "rgb(0, 53, 183)"
    And ".view-content .media-type-audio .field-name-title" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/video-icon.png')"
    And ".view-content .media-type-text .field-name-title" should have a "background-color" css value of "rgb(111, 126, 149)"
    And ".view-content .media-type-text .field-name-title" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/attachment-icon.png')"
    And ".view-content .media-type-image .field-name-title" should have a "background-color" css value of "rgb(111, 126, 149)"
    And ".view-content .media-type-image .field-name-title" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/attachment-icon.png')"
    And ".view-content .columns .field-name-title h3" should have a "font-family" css value of "'Open Sans Condensed','Helvetica Neue',Helvetica,Arial,sans-serif"
    And ".view-content .columns .field-name-title h3" should have a "font-weight" css value of "700"
    And ".view-content .columns .field-name-title h3" should have a "font-size" css value of "18.6833px"
    And ".view-content .columns .field-name-title h3 a" should have a "color" css value of "rgb(255, 255, 255)"
    And I hover over the element ".view-content .columns .field-name-title h3 a"
    And ".view-content .columns .field-name-title h3 a" should have a "text-decoration" css value of "underline"
    And ".view-content .columns .field-name-post-date" should have a "font-size" css value of "13px"
    And ".view-content .columns .field-name-post-date" should have a "color" css value of "rgb(111, 126, 149)"
    And ".view-content .columns .field-name-body" should have a "font-size" css value of "13px"
    And ".view-content .columns .field-name-body" should have a "color" css value of "rgb(70, 70, 70)"
    And ".view-content .columns .field-name-body a" should have a "color" css value of "rgb(112, 84, 125)"
    And I hover over the element ".view-content .columns .field-name-body a"
    And ".view-content .columns .field-name-body a" should have a "text-decoration" css value of "underline"
    And ".view-content .columns .field-name-body" should have a "border-bottom-color" css value of "rgb(111, 126, 149)"
    And ".view-content .columns .field-name-body" should have a "border-bottom-style" css value of "solid"
    And ".view-content .columns .field-name-body" should have a "border-bottom-width" css value of "1px"
    # Todo - Favorite icon
    # Todo - Like icon
    # Todo - add tag values to node table above and re-enable the step below.
    # And ".view-content .columns .field-name-field-tags" should have a "color" css value of "rgb(111, 126, 149)"
    # And ".view-content .columns .field-name-field-tags .field-label" should have a "margin-bottom" css value of "5px"
    # And ".view-content .columns .field-name-field-tags .field-label" should have a "font-weight" css value of "700"
    # And ".view-content .columns .field-name-field-tags .field-label" should have a "font-size" css value of "13px"
    # And ".view-content .columns .field-name-field-tags .field-item a" should have a "color" css value of "rgb(112, 84, 125)"
    When I am browsing using a "tablet"
    # TODO - Adjust node creation to upload dummy images and then re-enable the step below.
    # And ".gallery-main .view-content .columns .field-name-field-thumbnail img" should have a "width" css value of "347px"
    And ".view-content .columns .field-name-title h3" should have a "font-size" css value of "22.75px"
    When I am browsing using a "desktop"
    Then "#sub-header h1" should have a "font-size" css value of "42px"
    And "#sub-header h1" should have a "margin-top" css value of "8.4px"
    And "#sub-header h1" should have a "margin-bottom" css value of "21px"
    # TODO - Adjust node creation to upload dummy images and then re-enable the step below.
    # And ".gallery-main .view-content .columns .field-name-field-thumbnail img" should have a "width" css value of "370px"
    And ".view-content .columns .field-name-title" should have a "margin-left" css value of "-24.3667px"
    And ".view-content .columns .field-name-title" should have a "margin-right" css value of "-24.3667px"
    And ".view-content .columns .field-name-title" should have a "padding-left" css value of "24.3833px"
    And ".view-content .columns .field-name-title" should have a "padding-right" css value of "55.25px"
    When I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Result Two"
    And I follow "Edit"
    Then I attach the file "testfiles/thumb_too_small.png" to "edit-field-thumbnail-und-0-upload"
    And I select the radio button "Public"
    And I press "Save"
    And I should see the error message containing "The specified file thumb_too_small.png could not be uploaded. The image is too small; the minimum dimensions are 595x1 pixels."

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
      | title            | body        | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One       | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two       | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
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
      | title            | body        | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One       | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two       | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
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
      | title            | body        | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One       | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two       | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
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
      | title            | body        | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One       | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two       | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
    And I index search results
    And I am on "library"
    When I am browsing using a "phone"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(248, 248, 248)"
    And ".filter-panel-toggle" should have a "display" css value of "none"
    When I click on the element with css selector ".filter-panel-toggle-link"
    And I click "Media Uno"
    Then "#filter-panel-filters" should have a "display" css value of "block"
    And "#facetapi-facet-search-apidigital-library-only-block-field-media-type a:first-child" should have a "background-color" css value of "rgb(52, 71, 89)"

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
      | title            | body        | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One       | First Body  | 1      | 1   | Filter Me One | GL One            | Media Uno        |
      | Result Two       | Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum | 1      | 1   | Filter Me Two | GL Two            | Media Deux       |
    And I index search results
    And I am on "library"
    When I am browsing using a "phone"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(248, 248, 248)"
    And ".filter-panel-toggle" should have a "display" css value of "none"
    When I click on the element with css selector ".filter-panel-toggle-link"
    Then "#filter-panel-filters" should have a "display" css value of "block"
    And "#facetapi-facet-search-apidigital-library-only-block-field-media-type a:first-child" should have a "background-color" css value of ""