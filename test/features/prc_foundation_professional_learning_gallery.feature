@api @d7 @styleguide @prc-391 @professional-learning
Feature: PRC-General Theming Cleanup (PRC-391)
  As a user
  I want my view of the professional learning gallery to be responsive
  so that I can easily view the content on different devices.

  As a user
  I want my view of the professional learning gallery to be organized and easy to navigate
  so that I can easily view the content consistently throughout the site

  ##### Professional Learning Gallery View #####

  @javascript
  Scenario: Professional Learning responsive behavior matches style guide
    Given "PD Course" nodes:
      | title       | field_course_objectives | field_permissions | field_length_quantity | field_length_unit | status | uid |
      | PD Course 1 | Obj1                    | public            | 1                     | week              | 1      | 1   |
      | PD Course 2 | Obj2                    | public            | 2                     | month             | 1      | 1   |
      | PD Course 3 | Obj3                    | public            | 3                     | year              | 0      | 1   |
    And I am logged in as a user with the "Educator" role
    And I am on "professional-learning"
    When I am browsing using a "phone"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    And ".view-professional-development-view .row-first div.col-first" should have an "class" attribute value of "small-12 medium-6 large-4 columns col-1 col-first"
    When I am browsing using a "tablet"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    And ".view-professional-development-view .row-first div.col-first" should have an "class" attribute value of "small-12 medium-6 large-4 columns col-1 col-first"
    And ".view-professional-development-view .view-content" should have a "position" css value of "static"
    And ".view-professional-development-view .columns" should have a "position" css value of "absolute"
    When I am browsing using a "desktop"
    Then ".main" should have a "padding-left" css value of "30px"
    And ".main" should have a "padding-right" css value of "30px"
    And ".view-professional-development-view .row-first div.col-first" should have an "class" attribute value of "small-12 medium-6 large-4 columns col-1 col-first"
    And ".view-professional-development-view .view-content" should have a "position" css value of "static"
    And ".view-professional-development-view .columns" should have a "position" css value of "absolute"

  @javascript
  Scenario: Professional Learning style matches style guide
    Given "PD Course" nodes:
      | title       | field_course_objectives | field_permissions | field_length_quantity | field_length_unit | status | uid |
      | PD Course 1 | Obj1                    | public            | 1                     | week              | 1      | 1   |
      | PD Course 2 | Obj2                    | public            | 2                     | month             | 1      | 1   |
      | PD Course 3 | Obj3                    | public            | 3                     | year              | 0      | 1   |
    And I am logged in as a user with the "Educator" role
    And I am on "professional-learning"
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
    And ".view-content .field-name-title" should have a "background-color" css value of "rgb(112, 84, 125)"
    And ".view-content .columns .field-name-title h3" should have a "font-family" css value of "'Open Sans Condensed','Helvetica Neue',Helvetica,Arial,sans-serif"
    And ".view-content .columns .field-name-title h3" should have a "font-weight" css value of "700"
    And ".view-content .columns .field-name-title h3" should have a "font-size" css value of "18.6833px"
    And ".view-content .columns .field-name-title h3 a" should have a "color" css value of "rgb(255, 255, 255)"
    And I hover over the element ".view-content .columns .field-name-title h3 a"
    And ".view-content .columns .field-name-title h3 a" should have a "text-decoration" css value of "underline"
    # Todo - Thumbnail
    And ".view-content .columns .field-name-formatted-course-length" should have a "font-size" css value of "13px"
    And ".view-content .columns .field-name-formatted-course-length" should have a "color" css value of "rgb(70, 70, 70)"
    And ".view-content .columns .field-name-formatted-course-length .field-item" should have a "font-weight" css value of "700"
    And ".view-content .columns .field-name-field-course-objectives" should have a "font-size" css value of "13px"
    And ".view-content .columns .field-name-field-course-objectives" should have a "color" css value of "rgb(70, 70, 70)"
    And ".view-content .columns .field-name-field-course-objectives .field-label" should have a "font-weight" css value of "700"
    And ".view-content .columns .field-name-field-course-objectives" should have a "font-size" css value of "13px"
    And ".view-content .columns .field-name-field-course-objectives" should have a "border-bottom-color" css value of "rgb(111, 126, 149)"
    And ".view-content .columns .field-name-field-course-objectives" should have a "border-bottom-style" css value of "solid"
    And ".view-content .columns .field-name-field-course-objectives" should have a "border-bottom-width" css value of "1px"
    # Todo - Test Read More Link
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