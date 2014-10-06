@api @d7
Feature: Admin UI: View User Accounts (PRC-37)
  As a PRC Administrator,
  I want to view and manage PRC website user accounts,
  So that I can assist the educators when they have issues accessing the website.

  # Test visibility first. Only PRC Admin should see this link.
  Scenario: PRC Admin sees the Users link
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    Then I should see the link "Users"

  Scenario: Anonymous user should not see Users link
    Given I am an anonymous user
    And I am on the homepage
    Then I should not see the link "Users"

  Scenario: Educator user should not see Users link
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    Then I should not see the link "Users"

  Scenario: PRC Admin clicks the Users link (AC1)
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    And I follow "Users"
    Then I should be on "/admin-users"

  Scenario: Page contains table that only contains Educator and PRC Admin users
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I should see the text "First Name"

  Scenario: Last Name field is sortable

  Scenario: First Name field is sortable

  Scenario: E-Mail field is sortable

