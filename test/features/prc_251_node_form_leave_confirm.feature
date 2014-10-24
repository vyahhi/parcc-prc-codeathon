@api @d7
Feature: PRC-251 Edit Content - Leaving page without saving
  There is no story for this yet, but we get the feature for free with node_edit_protection, which we
  are customizing for user_edit_protection.

  Background:
    Given I am logged in as a user with the "PRC Admin" role
    Then I click "Content"
    Then I click "Add content"
    Then I click "Document"
    Then I fill in "Title *" with "title"
    Then I fill in "Body" with "body"
    Then the url should match "node/add/document"
    Then I should see the heading "Create Document" in the "content" region

  # Apparently the confirmation dialog is preventing our testing
  # browser from closing, so we have to explicitly confirm the
  # dialog after every dismissal test. Ridiculous!

  @javascript
  Scenario: Confirm dialog works on navigate away
    Then I follow the "Home" link, confirming the dialog
    Then the url should match "/"

  @javascript
  Scenario: Dismiss dialog works on navigate away
    Then I follow the "Home" link, dismissing the dialog
    Then the url should match "node/add/document"
    Then I move backward one page, confirming the dialog

  @javascript
  Scenario: Confirm dialog works on Back button
    Then I move backward one page, confirming the dialog
    Then the url should match "/"

  @javascript
  Scenario: Dismiss dialog works on Back button
    Then I move backward one page, dismissing the dialog
    Then the url should match "node/add/document"
    Then I move backward one page, confirming the dialog
