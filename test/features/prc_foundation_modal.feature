@api @prc-1625 @styleguide @javascript
Feature: Test styling of modal windows
  @javascript @api
  Scenario: Styling of the modal for digital library content.
    Given I have no "Digital Library Content" nodes
    And "Subject" terms:
      | name          |
      | Filter Me One |
    And "Grade Level" terms:
      | name   |
      | GL One |
    And "Media Type" terms:
      | name      |
      | Media Uno |
    And "Digital Library Content" nodes:
      | title      | body       | status | uid | field_subject | field_grade_level | field_media_type |
      | Result One | First Body | 1      | 1   | Filter Me One | GL One            | Media Uno        |
    And I index search results
    And I am logged in as a user with the "educator" role
    And I am on "library"
    When I click "Add to My Lists"
    Then ".modal-header" should have a "background-color" css value of "rgb(52, 71, 89)"
    And ".modal-header" should have a "color" css value of "rgb(0, 0, 0)"
    And ".prc-modal-submit-wrapper" should have a "border-top-width" css value of "1px"
    And ".prc-modal-submit-wrapper" should have a "border-top-color" css value of "rgb(217, 217, 217)"
    And ".prc-modal-submit-wrapper" should have a "padding-top" css value of "32px"
    And ".prc-modal-submit-wrapper" should have a "margin-top" css value of "32px"
