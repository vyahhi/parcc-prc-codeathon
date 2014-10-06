Feature: Admin UI: View User Accounts (PRC-37)
  As a PRC Administrator,
  I want to view and manage PRC website user accounts,
  So that I can assist the educators when they have issues accessing the website.

  Scenario: PRC Admin clicks the Users link
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    Then I should see the link "Users"