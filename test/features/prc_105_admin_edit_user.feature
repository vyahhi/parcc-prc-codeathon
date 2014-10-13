@api @d7
Feature: Admin UI: Edit User (PRC-105)
  As a PRC Administrator,
  I want to edit an existing user account,
  So that the last updated information is reflected in the system.

  Scenario: Clickable user ID column
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    And users:
      | name     | mail            | pass     | field_first_name | field_last_name | status |
      | Joe User | joe@example.com | xyz123   | Joe              | User            | 1      |
    Then I click "Users"
    Then the url should match "admin-users"
    # Now sort by User ID descending so that the new user we created is up top
    Then I click "User ID"
    Then I click on the edit link for the user "Joe User"
    Then I should see a "First Name *" field
    And I should see a "Last Name *" field
    And I should see a "Profession" field
    And I should not see a "Username" field
    And I should see an "E-mail *" field
    And I should see a "Password *" field
    And I should see a "Confirm password *" field
    And I should see "Password strength"

