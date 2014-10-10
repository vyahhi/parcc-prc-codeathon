@api @d7
Feature: PRC Administrators (PRC-61)
  As a PRC Administrator,
  I want to log into PRC website, so that I can manage content and users later.

  Scenario: AC1 - Anonymous user should not see the Welcome, First Last text
    Given I am an anonymous user
    And I am on the homepage
    Then I should not see the text "Welcome,"
  
  @api @d7 @javascript
  Scenario: AC1 - A user shall use the Login block of the Home page and enter the E-mail and password provided.
    Given users:
      | name     | mail            | pass     | field_first_name | field_last_name | status |
      | Joe User | joe@example.com | xyz123   | Joe              | User            | 1      |
    And I am on the homepage
    When I fill in "E-mail" with "joe@example.com"
    And I fill in "Password" with "xyz123"
    And I press "Log in"
    Then I should see the link "Log out"
    And I should see "Welcome, Joe User"

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
