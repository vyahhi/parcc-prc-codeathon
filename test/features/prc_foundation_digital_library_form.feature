@api @d7 @styleguide @prc-865 @diglib
Feature: Digital Library - Create a post Responsive Behavior (PRC-865)
  As a user
  I want my view of the Digital Library content creation forms to be responsive
  so that I can easily view the content on different devices.

  ##### Digital Library Create / Edit Form #####

  @javascript
  Scenario: Digital Library Create a Post Responsive Behavior matches style guide
    Given I am logged in as a user with the "Content Contributor" role
    And I am on "node/add/digital-library-content"
    When I am browsing using a "phone"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    # And "input#edit-title.form-text.required" should have a "width" css value of "299px"
    When I click "Add More Information (Content Properties)"
    # Then "select#edit-field-standard-und-0-tid-select-1" should have a "width" css value of "186px"
    When I am browsing using a "desktop"
    Then ".main" should have a "padding-left" css value of "30px"
    And ".main" should have a "padding-right" css value of "30px"
    # And "input#edit-title.form-text.required" should have a "width" css value of "564px"
    # And "select#edit-field-grade-level-und" should have a "width" css value of "1091px"
    # And "select#edit-field-standard-und-0-tid-select-1" should have a "width" css value of "216px"
    # prc-1620
    And "#edit-field-media-type-und" should be "25%" of the width of ".pane-content" within a margin of "5%"
    And "#edit-field-genre-und" should be "25%" of the width of ".pane-content" within a margin of "5%"