@d7 @api
Feature: Login & Public Registration (PRC-48)
  As an educator,
  I want to register and log in to the PRC website,
  So that I can benefit from the contents and features provided by PRC in the website.

  @api @d7
  Scenario: A new role Educator shall be created. This role can view content, but cannot make any changes to the update. (AC1)
    Given I am logged in as a user with the "Educator" role
    Then I should not be able to edit an "article" node
    Then I should not be able to edit a "basic page" node

  Scenario: When a user clicks the Join Now! button or link from the PRC website home page, a new page opens to allow the user create a new user account. (AC2)
    Given I am on the homepage
    And I follow "Join now!"
    Then the url should match "user/register"

  Scenario: The create user account header shall be: Create User Account to Join Partnership Resource Center. (AC3)
    Given I am on the homepage
    And I follow "Join now!"
    Then I should see the text "Create User Account to Join Partnership Resource Center"

  Scenario: Fields on registration form (AC4)
    Given I am on the homepage
    And I follow "Join now!"
    Then I should see a "First Name *" field
    And I should see a "Last Name *" field
    And I should see a "Profession" field
    And I should not see a "Username" field
    And I should see an "E-mail *" field
    And I should see a "Password *" field
    And I should see a "Confirm password *" field
    And I should see "Password strength"

  Scenario: Registration form validation - invalid email address (AC5a)
    Given I am on the homepage
    And I follow "Join now!"
    Then I fill in "invalid" for "E-mail"
    Then I press the "Create new account" button
    Then I should see the error message "The e-mail address invalid is not valid."

  Scenario: Registration form validation - passwords do not match (AC5b)
    Given I am on the homepage
    And I follow "Join now!"
    Then I fill in "abc" for "Password"
    And I fill in "xyz" for "Confirm password"
    Then I press the "Create new account" button
    Then I should see the error message "The specified passwords do not match."

  Scenario: Registration form validation - required fields (AC6)
    Given I am on the homepage
    And I follow "Join now!"
    Then I press the "Create new account" button
    Then I should see the error message "First Name field is required."
    And I should see the error message "Last Name field is required."
    And I should not see the error message "Profession field is required."
    And I should see the error message "E-mail field is required."

  Scenario: Successful registration message (AC6d)
    Given I am on the homepage
    And I follow "Join now!"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    Then I press the "Create new account" button
    Then I should see the message "Registration successful. You are now logged in."

  @api @d7
  Scenario: Logout (AC8)
    Given I am logged in as a user with the "authenticated user" role
    And I am on the homepage
    When I click "Log out"
    And I go to "front"
    Then I should see a "Log in" button

  Scenario: When I self-register, I am automatically given the Educator role
    Given I am an anonymous user
    And I am on the homepage
    And I follow "Join now!"
    Then I fill in "test@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    Then I press the "Create new account" button
    Then I should see the message "Registration successful. You are now logged in."
    Then I should know that the user "test@timestamp@example.com" has a role of "Educator"
