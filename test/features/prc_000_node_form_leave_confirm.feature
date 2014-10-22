@api @d7
Feature: Edit Content - Leaving page without saving
  There is no story for this yet, but we get the feature for free with node_edit_protection, which we
  are customizing for user_edit_protection.

  @javascript
  Scenario: Confirm dialog works
    Given I am logged in as a user with the "PRC Admin" role
    Then I click "Content"
    Then I click "Add content"
    Then I click "Document"
    Then I fill in "Title *" with "title"
    Then I follow the "Home" link, confirming the dialog
    Then the url should match "/"

  @javascript
  Scenario: Dismiss dialog works
    Given I am logged in as a user with the "PRC Admin" role
    Then I click "Content"
    Then I click "Add content"
    Then I click "Document"
    Then I fill in "Title *" with "title"
    Then the url should match "node/add/document"
    Then I should see the heading "Create Document " in the "content" region
    Then I follow the "Home" link, dismissing the dialog
    Then the url should match "node/add/document"
