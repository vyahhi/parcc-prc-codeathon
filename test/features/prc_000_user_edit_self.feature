@api @d7
Feature: PRC ??? - User edits own account
  As an educator,
  I want to edit my account,
  so that I can continue to benefit from the contents and features provided by PRC in the website.

  Scenario: User edits own account
    Given users:
      | name     | mail            | pass     | field_first_name | field_last_name | status |
      | Joe User | joe@example.com | xyz123   | Joe              | User            | 1      |
    And I am an anonymous user
    And I am on the homepage
    # Log in
    Then the user "joe_@uname[Joe User]" should have a role of "Educator"
    Then I fill in "E-mail" with "joe_@uname[Joe User]"
    And I fill in "Password" with "xyz123"
    And I press "Log in"
    Then I should see the link "Log out"
    And I should see "Welcome, Joe User"
    # Edit my account
    Then I follow "My account"
    Then I follow "Edit"
    And I fill in "Current password" with "xyz123"
    And I fill in "Password" with "password1"
    And I fill in "Confirm password" with "password1"
    And I press "Save"
    Then I should see the message containing "The changes have been saved."
    Then the user "joe_@uname[Joe User]" should have a role of "Educator"
    Then I click "Log out"
    Then the url should match "/"
    Then I fill in "E-mail" with "joe_@uname[Joe User]"
    And I fill in "Password" with "password1"
    And I press "Log in"
    Then I should see the link "Log out"
    And I should see "Welcome, Joe User"
