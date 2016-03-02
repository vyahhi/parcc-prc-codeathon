@api @d7 @styleguide @prc-1090 @assessment @prc-433
Feature: Assessment - Create a post Responsive Behavior (PRC-865)
  As a user
  I want my view of the Assesment content creation forms to be responsive
  so that I can easily create or edit content on different devices.

  ##### Assessment Create / Edit Form #####

  @javascript
  Scenario: Assessment Create a Post Responsive Behavior matches style guide
    Given I am logged in as a user with the "Educator" role
    And I am on "node/add/quiz"
    When I am browsing using a "phone"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    # And "input#edit-title.form-text.required" should have a "width" css value of "316px"
    # And "select#edit-field-subject-und-0-tid-select-1" should have a "width" css value of "260px"
    And I am browsing using a "desktop"
    And ".main" should have a "padding-left" css value of "30px"
    And ".main" should have a "padding-right" css value of "30px"
    # And "input#edit-title.form-text.required" should have a "width" css value of "588px"
    # And "#edit-field-grade-level-und .form-item" should have a "width" css value of "170px"
    # And "select#edit-field-subject-und-0-tid-select-1" should have a "width" css value of "243px"

  @javascript
  Scenario: PRC-433, additional styling of the assessment form.
    Given I am logged in as a user with the "PRC Admin" role
    And "Assessment" nodes:
      | title                      | body   | field_grade_level_unlimited | field_subject                | field_quiz_type   | uid         |
      | PRC-534 Assessment Title 2 | Body 2 | 4th Grade                   | Educational Leadership, Math | Custom Assessment | @currentuid |
    And I visit "assessments/practice-assessments"
    And I am browsing using a "desktop"
    When I click "PRC-534 Assessment Title 2"
    When I click "Edit"
    # When the user is browsing on any device:
    ## Sub header will contain Breadcrumb and title should be in a section with a background grey color background.
    Then I should see the link "PRC" in the "sub_header" region
    ### Title H1 is text-align center.
    And "h1#page-title" should have a "text-align" css value of "center"
    ### H1 uses default H1 padding, margin and line height.
    And "h1#page-title" should have a "margin-top" css value of "8.4px"
    And "h1#page-title" should have a "margin-bottom" css value of "21px"
    And "h1#page-title" should have a "line-height" css value of "50.4px"
    ## The main content region should be White.
    And "#content" should have a "background-color" css value of "rgb(255, 255, 255)"
    ## Tabs should use button styles and be aligned in the upper right corner.
    And ".tabs.primary" should have a "border-bottom" css value of ""
    ### The left margin of the main content area should show the gray background.
    ### The right margin of the main content area should show the gray background.
    And ".page-node #page" should have a "background-color" css value of "rgb(238, 238, 238)"
    ## Form labels should match H3 font styles (but not actually be H3)
    And "label" should have a "color" css value of "rgb(70, 70, 70)"
    And "label" should have a "font-size" css value of "21px"
    And "label" should have a "font-family" css value of "'Open Sans Condensed','Helvetica Neue',Helvetica,Arial,sans-serif"
    ## The field is required indicator (*) is PARCC Orange
    # And ".form-item-field-grade-level-und span.form-required" should have a "color" css value of "rgb(246, 107, 22)"
    ## Stroke on text field  and check boxes -  #6f7e95 (define this color as a variable)
    And "input[type=\'text\']" should have a "border-top-color" css value of "rgb(111, 126, 149)"
    ## Buttons should use button styles (see style guide)
    And "input[type=\'submit\']" should have a "background-color" css value of "rgb(255, 255, 255)"
    And "input[type=\'submit\']" should have a "color" css value of "rgb(70, 70, 70)"
    ## Dropdowns use dropdown styles (see style guide)
    ## Arrows in dropdown are PARCC Purple (see style guide)
    # @todo: background image for the parcc purple down arrow will likely need to be visually confirmed
    And "select" should have a "-moz-appearance" css value of "none"
    ## Checkboxes use Foundation like checkbox style Selected box should be parcc purple and the x should be white.
    And ".form-type-checkbox" should have a "display" css value of "inline-block"
