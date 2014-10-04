@api @d7
Feature: PRC Administrators
  As a PRC Administrator,
  I want to log into PRC website, so that I can manage content and users later.

  @api @d7
  Scenario: PRC Admin role exists (AC1)
    Given I am logged in as a user with the "PRC Admin" role
    Then I should be able to edit an "Article" node
    And I should be able to edit a "Basic page" node

  @api @d7
  Scenario: Logout (AC5)
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    When I click "Log out"
    And I go to "front"
    Then I should see a "Log in" button
