@api @d7
Feature: Edit User - Leaving Page Without Saving Changes (PRC-213)
  As a PRC Admin,
  I want the system to show a message when I attempt to navigate away from a page without saving changes,
  so that I will not lose any previous entered information by accident.

  Background:
    Given I am logged in as a user with the "PRC Admin" role
    And users:
      | name     | mail            | pass     | field_first_name | field_last_name | status |
      | PRC-213 User | joe@example.com | xyz123   | Joe              | User            | 1      |
    Then I click "Users"
    Then the url should match "admin-users"
    # Now sort by User ID descending so that the new user we created is up top
    Then I click "User ID"
    Then I click on the edit link for the user "PRC-213 User"

  Scenario: If a PRC Admin navigates away from the "Edit User" page without saving changes, the system will prompt the admin with the following message
    Then I click "Home"
