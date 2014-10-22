@api @d7
Feature: PRC Administrators (PRC-61)
  As a PRC Administrator,
  I want to log into PRC website, so that I can manage content and users later.

  Scenario: AC1 - Anonymous user should not see the Welcome, First Last text
    Given I am an anonymous user
    And I am on the homepage
    Then I should not see the text "Welcome,"
  
  @api @d7
  Scenario: AC1 - A user shall use the Login block of the Home page and enter the E-mail and password provided.
    Given users:
      | name     | mail                   | pass     | field_first_name | field_last_name | status |
      | Joe User | joe_prc_61@example.com | xyz123   | Joe              | User            | 1      |
    And I am on the homepage
    When I fill in "E-mail" with "joe_prc_61@example.com"
    And I fill in "Password" with "xyz123"
    And I press "Log in"
    Then I should see the link "Log out"
    And I should see "Welcome, Joe User"

  Scenario: AC2 - Once logged in, the Login block will not display
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    Then I should not see an "E-mail" field
    And I should not see a "Password" field

  Scenario: AC3 - If any of the credentials are missing, the following messages appear (email and password)
    Given I am an anonymous user
    And I am on the homepage
    When I press "Log in"
    Then I should see the error message containing "E-mail field is required."
    And I should see the error message containing "Password field is required."

  Scenario: AC3 - If any of the credentials are missing, the following messages appear (email)
    Given I am an anonymous user
    And I am on the homepage
    When I fill in "E-mail" with "joe_prc_61@example.com"
    And I press "Log in"
    Then I should not see the error message containing "E-mail field is required."
    And I should see the error message containing "Password field is required."

  Scenario: AC3 - If any of the credentials are missing, the following messages appear (password)
    Given I am an anonymous user
    And I am on the homepage
    When I fill in "Password" with "joe"
    And I press "Log in"
    Then I should see the error message containing "E-mail field is required."
    And I should not see the error message containing "Password field is required."

  Scenario: AC4 - If any of the credentials are wrong, the following message appears (wrong password)
    Given users:
      | name     | mail            | pass     | field_first_name | field_last_name | status |
      | Joe User | joe_prc_61_4@example.com | xyz123   | Joe              | User            | 1      |
    And I am on the homepage
    When I fill in "E-mail" with "joe_prc_61_4@example.com"
    And I fill in "Password" with "wrong"
    And I press "Log in"
    # Quotes apparently screw it up, so we'll just leave out the link
    Then I should see the error message containing "Sorry, unrecognized username or password."
    And I should see the link "Have you forgotten your password?"

  Scenario: AC4 - If any of the credentials are wrong, the following message appears (wrong username)
    Given I am on the homepage
    When I fill in "E-mail" with "User that does not exist"
    And I press "Log in"
    # Quotes apparently screw it up, so we'll just leave out the link
    Then I should see the error message containing "Sorry, unrecognized username or password."
    And I should see the link "Have you forgotten your password?"

  Scenario: AC4 - If any of the credentials are wrong, the following message appears (wrong username and password)
    Given I am on the homepage
    When I fill in "E-mail" with "User that does not exist"
    And I fill in "Password" with "Wrong password too"
    And I press "Log in"
    # Quotes apparently screw it up, so we'll just leave out the link
    Then I should see the error message containing "Sorry, unrecognized username or password."
    And I should see the link "Have you forgotten your password?"
