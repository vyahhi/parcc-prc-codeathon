@api @d7
Feature: Admin UI: View User Accounts (PRC-37)
  As a PRC Administrator,
  I want to view and manage PRC website user accounts,
  So that I can assist the educators when they have issues accessing the website.

  # Test visibility first. Only PRC Admin should see this link.
  Scenario: AC1 - PRC Admin sees the Users link
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    Then I should see the link "Users"

  Scenario: AC1 - Anonymous user should not see Users link
    Given I am an anonymous user
    And I am on the homepage
    Then I should not see the link "Users"

  Scenario: AC1 - Educator user should not see Users link
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    Then I should not see the link "Users"

  Scenario: AC2 - PRC Admin clicks the Users link
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    And I follow "Users"
    Then I should be on "/admin-users"

  Scenario: AC2 - Page title
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I should see "PRC Website Users"

  Scenario: AC3 - Page contains table that only contains Educator and PRC Admin users
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I should not see the text "administrator"
    And I should not see any empty "Roles" cells

  Scenario: AC3 - Page contains user fields
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I should see the text "User ID"
    Then I should see the text "First Name"
    Then I should see the text "Last Name"
    Then I should see the text "E-mail Address"
    Then I should see the text "Role(s)"
    Then I should see the text "Profession"
    Then I should see the text "Active"

  Scenario: AC4 - All fields are sortableexcept Role(s)
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I should see the link "User ID"
    Then I should see the link "Last Name"
    Then I should see the link "First Name"
    Then I should see the link "E-mail"
    # Multivalue fields are not sortable
    Then I should not see the link "Role(s)"
    Then I should see the link "Profession"
    Then I should see the link "Active"

  @javascript
  Scenario: AC5 - Filter box
    Given I have a total of 50 users with the "Educator" role
    And I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I fill in "Search" with "example.com"
    And I press "Apply"

  @javascript
  Scenario: AC6 - Filter searches all data and not just the current page
    Given I have a total of 150 users with the "Educator" role
    And I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I click "next"
    # We are on page 2. We should see 125 but not see 25.
    Then I should see the link "userbehat125@example.com"
    And I should not see the link "userbehat25@example.com"
    Then I fill in "Search" with "behat25"
    And I press "Apply"
    # Now the search is complete and behat25 matches and behat125 doesn't.
    Then I should see the link "userbehat25@example.com"
    Then I should not see the link "userbehat125@example.com"

  Scenario: AC7 - Pagination - 100 users no pagination
    # Create 99 users because the PRC Admin we will be logged in as makes 100
    Given I have a total of 98 users with the "Educator" role
    And I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    And I should not see the link "next"
    And I should not see the link "last"

  Scenario: AC7 - Pagination - 100 per page
    # Our PRC Admin makes user 100
    Given I have a total of 99 users with the "Educator" role
    And I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    And I should see the link "next"
    And I should see the link "last"
