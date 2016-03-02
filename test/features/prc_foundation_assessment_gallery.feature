@api @d7 @styleguide @prc-1089 @prc-431 @assessments
Feature: Gallery View Responsive behavior – Assessments (PRC-1089)
  As a user
  I want my view of the Assessments gallery to be responsive
  so that I can easily view the content on different devices.

  Gallery View Theming – Assessments (PRC-431)
  As a user
  I want my view of the Assessments gallery to be organized and easy to navigate
  so that I can easily view the content consistently throughout the site

  ##### Assessments Gallery View #####

  @javascript
  Scenario: Assessments responsive behavior matches style guide
    Given I am logged in as a user with the "PRC Admin" role
    And "Grade Level" terms:
      | name          |
      | Middle School |
    And "Assessment" nodes:
      | title                       | body   | field_grade_level_unlimited | field_subject                | field_quiz_type   | uid         |
      | PRC-1089 Assessment Title 1 | Body 1 | Middle School               | Educational Leadership, Math | Custom Assessment | @currentuid |
      | PRC-1089 Assessment Title 2 | Body 2 | Middle School               | Educational Leadership, Math | Custom Assessment | @currentuid |
      | PRC-1089 Assessment Title 3 | Body 3 | Middle School               | Educational Leadership, Math | Custom Assessment | @currentuid |
    And I index search results
    And I am on "assessments/practice-assessments"
    When I am browsing using a "phone"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    And ".panel-display div div:nth-child(7)" should have an "class" attribute value of "panel-pane pane-views-panes pane-assessments-panel-pane-1 digital-library-content-pane"
    # It would be much more realistic to test css width on the tiles, but the values on the library gallery often drift during tests. Current theory is that it is related to other elements being shown/hidden on the page.
    And ".view-assessments .row-first div.col-first" should have an "class" attribute value of "small-12 medium-6 large-4 columns col-1 col-first"
    When I am browsing using a "tablet"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    And ".panel-display div div:nth-child(7)" should have an "class" attribute value of "panel-pane pane-views-panes pane-assessments-panel-pane-1 digital-library-content-pane"
    And ".view-assessments .row-first div.col-first" should have an "class" attribute value of "small-12 medium-6 large-4 columns col-1 col-first"
    And ".view-assessments .view-content" should have a "position" css value of "static"
    And ".view-assessments .columns" should have a "position" css value of "relative"
    When I am browsing using a "desktop"
    Then ".main" should have a "padding-left" css value of "30px"
    And ".main" should have a "padding-right" css value of "30px"
    And ".panel-display div div:nth-child(7)" should have an "class" attribute value of "panel-pane pane-views-panes pane-assessments-panel-pane-1 digital-library-content-pane"
    And ".view-assessments .row-first div.col-first" should have an "class" attribute value of "small-12 medium-6 large-4 columns col-1 col-first"
    And ".view-assessments .view-content" should have a "position" css value of "static"
    And ".view-assessments .columns" should have a "position" css value of "relative"

  @javascript
  Scenario: Assessments responsive behavior matches style guide
    Given I am logged in as a user with the "PRC Admin" role
    And "Grade Level" terms:
      | name          |
      | Middle School |
    And "Assessment" nodes:
      | title                      | body   | field_grade_level_unlimited | field_subject                | field_quiz_type   | uid         |
      | PRC-431 Assessment Title 1 | Body 1 | Middle School               | Educational Leadership, Math | Custom Assessment | @currentuid |
      | PRC-431 Assessment Title 2 | Body 2 | Middle School               | Educational Leadership, Math | Custom Assessment | @currentuid |
      | PRC-431 Assessment Title 3 | Body 3 | Middle School               | Educational Leadership, Math | Custom Assessment | @currentuid |
    And I am on "assessments/practice-assessments"
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
    And ".view-content .columns .field-name-title" should have a "margin-left" css value of "-12.1833px"
    And ".view-content .columns .field-name-title" should have a "margin-right" css value of "-12.1833px"
    And ".view-content .columns .field-name-title" should have a "padding-left" css value of "12.1833px"
    And ".view-content .columns .field-name-title" should have a "padding-right" css value of "55.25px"
    And ".view-content .field-name-title" should have a "background-color" css value of "rgb(246, 107, 22)"
    # Todo - Test PARCC ITEM Background
    And ".view-content .columns .field-name-title h3" should have a "font-family" css value of "'Open Sans Condensed','Helvetica Neue',Helvetica,Arial,sans-serif"
    And ".view-content .columns .field-name-title h3" should have a "font-weight" css value of "700"
    And ".view-content .columns .field-name-title h3" should have a "font-size" css value of "18.6833px"
    And ".view-content .columns .field-name-title h3 a" should have a "color" css value of "rgb(255, 255, 255)"
    And I hover over the element ".view-content .columns .field-name-title h3 a"
    And ".view-content .columns .field-name-title h3 a" should have a "text-decoration" css value of "underline"
    And ".view-content .columns .field-name-field-subject" should have a "font-size" css value of "13px"
    And ".view-content .columns .field-name-field-subject" should have a "color" css value of "rgb(70, 70, 70)"
    And ".view-content .columns .field-name-field-subject .field-label" should have a "font-weight" css value of "700"
    And ".view-content .columns .field-name-field-grade-level-unlimited" should have a "font-size" css value of "13px"
    And ".view-content .columns .field-name-field-grade-level-unlimited" should have a "color" css value of "rgb(70, 70, 70)"
    And ".view-content .columns .field-name-field-grade-level-unlimited .field-label" should have a "font-weight" css value of "700"
    And ".view-content .columns .field-name-body" should have a "font-size" css value of "13px"
    And ".view-content .columns .field-name-body" should have a "color" css value of "rgb(70, 70, 70)"
    And ".view-content .columns .field-name-body a" should have a "color" css value of "rgb(112, 84, 125)"
    And I hover over the element ".view-content .columns .field-name-body a"
    And ".view-content .columns .field-name-body a" should have a "text-decoration" css value of "underline"
    And ".view-content .columns .field-name-changed-date" should have a "font-size" css value of "13px"
    And ".view-content .columns .field-name-changed-date" should have a "color" css value of "rgb(111, 126, 149)"
    And ".view-content .columns .field-name-changed-date" should have a "border-bottom-color" css value of "rgb(111, 126, 149)"
    And ".view-content .columns .field-name-changed-date" should have a "border-bottom-style" css value of "solid"
    And ".view-content .columns .field-name-changed-date" should have a "border-bottom-width" css value of "1px"
    # Todo - Test Like icon
    # Todo - Test View / Modify Link
    When I am browsing using a "tablet"
    And ".view-content .columns .field-name-title h3" should have a "font-size" css value of "22.75px"
    When I am browsing using a "desktop"
    Then "#sub-header h1" should have a "font-size" css value of "42px"
    And "#sub-header h1" should have a "margin-top" css value of "8.4px"
    And "#sub-header h1" should have a "margin-bottom" css value of "21px"
    And ".view-content .columns .field-name-title" should have a "margin-left" css value of "-24.3667px"
    And ".view-content .columns .field-name-title" should have a "margin-right" css value of "-24.3667px"
    And ".view-content .columns .field-name-title" should have a "padding-left" css value of "24.3833px"
    And ".view-content .columns .field-name-title" should have a "padding-right" css value of "55.25px"