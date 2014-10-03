@d7 @api
Feature: Login & Public Registration (PRC-48)
  As an educator,
  I want to register and log in to the PRC website,
  So that I can benefit from the contents and features provided by PRC in the website.

  @api @d7
  Scenario: A new role Educator shall be created. This role can view content, but cannot make any changes to the update. (AC1)
    Given I am logged in as a user with the "Educator" role
    Then I should not be able to edit an "article" node

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
      And I should see a "Profession *" field
      And I should not see a "Username" field
      And I should see an "E-mail *" field
      # JF lobbying to rename this field label
      # And I should see a "Confirm Email Address *" field
      # JF lobbying to remove this requirement
      And I should see a "Password *" field
      And I should see a "Confirm password *" field

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
    And I should see the error message "Profession field is required."
    And I should see the error message "E-mail field is required."

  @api @d7
  Scenario: Logout (AC8)
    Given I am logged in as a user with the "authenticated user" role
      And I am on the homepage
    When I click "Log out"
      And I go to "front"
    Then I should see a "Log in" button

