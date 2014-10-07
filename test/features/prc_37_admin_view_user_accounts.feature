@api @d7
Feature: Admin UI: View User Accounts (PRC-37)
  As a PRC Administrator,
  I want to view and manage PRC website user accounts,
  So that I can assist the educators when they have issues accessing the website.

  # Test visibility first. Only PRC Admin should see this link.
  Scenario: PRC Admin sees the Users link (AC1)
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    Then I should see the link "Users"

  Scenario: Anonymous user should not see Users link (AC1)
    Given I am an anonymous user
    And I am on the homepage
    Then I should not see the link "Users"

  Scenario: Educator user should not see Users link (AC1)
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    Then I should not see the link "Users"

  Scenario: PRC Admin clicks the Users link (AC1)
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    And I follow "Users"
    Then I should be on "/admin-users"

  Scenario: Page title (AC1)
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I should see "PRC Website Users"

  Scenario: Page contains table that only contains Educator and PRC Admin users (AC2)
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I should not see the text "administrator"
    And I should not see any empty "Roles" cells

  Scenario: Page contains user fields (AC2)
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I should see the text "First Name"
    Then I should see the text "Last Name"
    Then I should see the text "E-mail"
    Then I should see the text "Roles"
    Then I should see the text "Profession"
    Then I should see the text "Active"

  Scenario: All fields are sortable (AC3)
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I should see the link "Last Name"
    Then I should see the link "First Name"
    Then I should see the link "E-mail"
    # Multivalue fields are not sortable
    Then I should not see the link "Roles"
    Then I should see the link "Profession"
    Then I should see the link "Active"

  Scenario: Pagination - 100 per page (AC5)
    Given I am logged in as a user with the "PRC Admin" role
    And I create 100 users with the "Educator" role
    And I visit "/admin-users"
    Then I should see the link "2"
    And I should see the link "next"
    And I should see the link "last"
