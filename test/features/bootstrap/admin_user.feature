@api @d7
Feature: PRC Administrators
  As a PRC Administrator,
  I want to log into PRC website, so that I can manage content and users later.

  @api @d7
  Scenario: PRC Admin role exists (AC1)
    Given I am logged in as a user with the "PRC Admin" role
    Then I should be able to edit an "Article" node
    And I should be able to edit a "Basic page" node
