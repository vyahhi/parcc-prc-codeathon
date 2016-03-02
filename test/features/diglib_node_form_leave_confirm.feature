@api @d7 @diglib
Feature: PRC-251 Edit Content - Leaving page without saving
  There is no story for this yet, but we get the feature for free with node_edit_protection, which we
  are customizing for user_edit_protection.

  Background:
    Given I am logged in as a user with the "PRC Admin" role
    When I am browsing using a "desktop"
    And I am on "prc/admin"
    And I hover over the element "#main-menu-section a[href='/prc/admin']"
    Then I hover over the element "#main-menu-section .dropdown a[href='/prc/admin/admin-content']"
    Then I click "Content"
    Then I click "Add content"
    Then I fill in "Title *" with "title"
    Then I fill in "Body" with "body"
    Then the url should match "node/add/digital-library-content"
    Then I should see the heading "Create Digital Library Content" in the "sub_header" region

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
    Then the url should match "node/add/digital-library-content"
    Then I move backward one page, confirming the dialog

  @javascript
  Scenario: Confirm dialog works on Back button
    Then I move backward one page, confirming the dialog
    Then the url should match "/"

  @javascript
  Scenario: Dismiss dialog works on Back button
    Then I move backward one page, dismissing the dialog
    Then the url should match "node/add/digital-library-content"
    Then I move backward one page, confirming the dialog
