@api @d7 @course
Feature: PRC-69 Admin: Create a Course

  Background:
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "prc/admin/admin-course"
    When I click "Add course"
    Then I fill in "Course Title *" with "title"
    Then I fill in "Course Objectives" with "objectives"
    Then the url should match "node/add/pd-course"
    Then I should see the heading "Create Course" in the "sub_header" region

  # Apparently the confirmation dialog is preventing our testing
  # browser from closing, so we have to explicitly confirm the
  # dialog after every dismissal test. Ridiculous!

  @javascript
  Scenario: Confirm dialog works on navigate away
    Then I follow the "PRC" link, confirming the dialog
    Then the url should match "/"

  @javascript
  Scenario: Dismiss dialog works on navigate away
    Then I follow the "PRC" link, dismissing the dialog
    Then the url should match "node/add/pd-course"
    Then I move backward one page, confirming the dialog

  @javascript
  Scenario: Confirm dialog works on Back button
    Then I move backward one page, confirming the dialog
    Then the url should match "/"

  @javascript
  Scenario: Dismiss dialog works on Back button
    Then I move backward one page, dismissing the dialog
    Then the url should match "node/add/pd-course"
    Then I move backward one page, confirming the dialog
