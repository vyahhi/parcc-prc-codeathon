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

  # Also tests AC5 - Filter box
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
    Given I have a total of 100 users with the "Educator" role
    And I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    And I should see the link "next"
    And I should see the link "last"

  Scenario: PRC-286 - Users with multiple roles appear once for each role
    Given users:
      | name     | mail                              | pass     | field_first_name | field_last_name | status |
      | Joe User | joe_prc_286@timestamp@example.com | xyz123   | Joe              | User            | 1      |
    And I am logged in as a user with the "PRC Admin" role
    Then I run drush "user-add-role" "'Educator' joe_prc_286@timestamp@example.com"
    Then I run drush "user-add-role" "'PRC Admin' joe_prc_286@timestamp@example.com"
    And I am at "admin-users"
    Then I click "User ID"
    Then I should see 1 "//a[text()='@uname[Joe User]']" elements

  Scenario: PRC-338 - Users with multiple roles appear once for each role
    Given users:
      | name            | mail                               | pass   | field_first_name | field_last_name | status |
      | Joe Educator    | joe_prc_286a@timestamp@example.com | xyz123 | Joe              | Educator        | 1      |
      | Joe Contributor | joe_prc_286b@timestamp@example.com | xyz123 | Joe              | Contributor     | 1      |
      | Joe Member      | joe_prc_286c@timestamp@example.com | xyz123 | Joe              | Member          | 1      |
      | Joe Admin       | joe_prc_286d@timestamp@example.com | xyz123 | Joe              | Admin           | 1      |
      | Joe Curator     | joe_prc_286e@timestamp@example.com | xyz123 | Joe              | Curator         | 1      |
    And I am logged in as a user with the "PRC Admin" role
    Then I run drush "user-add-role" "'PRC Admin' joe_prc_286d@timestamp@example.com"
    Then I run drush "user-add-role" "'PARCC-Member Educator' joe_prc_286c@timestamp@example.com"
    Then I run drush "user-add-role" "'Content Contributor' joe_prc_286b@timestamp@example.com"
    Then I run drush "user-add-role" "'Content Administrator (Curator)' joe_prc_286e@timestamp@example.com"
    Then I run drush "user-remove-role" "'Educator' joe_prc_286d@timestamp@example.com"
    Then I run drush "user-remove-role" "'Educator' joe_prc_286c@timestamp@example.com"
    Then I run drush "user-remove-role" "'Educator' joe_prc_286b@timestamp@example.com"
    Then I run drush "user-remove-role" "'Educator' joe_prc_286e@timestamp@example.com"
    And I am at "admin-users"
    Then I click "User ID"
      # Then here add in the xpath to grab a link for each of the users we created above
    Then I should see 1 "//a[text()='@uname[Joe Educator]']" elements
    Then I should see 1 "//a[text()='@uname[Joe Contributor]']" elements
    Then I should see 1 "//a[text()='@uname[Joe Member]']" elements
    Then I should see 1 "//a[text()='@uname[Joe Admin]']" elements

  Scenario: PRC-367 Accounts that are blocked do not show up in list
    Given users:
      | name            | mail                               | pass   | field_first_name | field_last_name | status |
      | Joe Blocked     | joe_prc_367a@timestamp@example.com | xyz123 | Joe              | Blocked         | 0      |
      | Joe Active      | joe_prc_367b@timestamp@example.com | xyz123 | Joe              | Active          | 1      |
    And I am logged in as a user with the "PRC Admin" role
    And I am at "admin-users"
    Then I click "User ID"
      # Then here add in the xpath to grab a link for each of the users we created above
    Then I should see 1 "//a[text()='@uname[Joe Blocked]']" elements
    Then I should see 1 "//a[text()='@uname[Joe Active]']" elements
