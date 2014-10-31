@d7 @api
Feature: Login & Public Registration (PRC-48)
  As an educator,
  I want to register and log in to the PRC website,
  So that I can benefit from the contents and features provided by PRC in the website.

  # This was taken out of this story and has moved somewhere else - keeping it here until permissions are introduced
  @api @d7
  Scenario: A new role Educator shall be created. This role can view content, but cannot make any changes to the update. (AC1)
    Given I am logged in as a user with the "Educator" role
    Then I should not be able to edit an "article" node
    And I should not be able to edit a "basic page" node
    And I should not be able to edit a "Digital Library Content" node

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

  Scenario: Field lengths (AC4)
    # Password length is managed by Drupal
    # Email length is managed by Drupal
    Then the field "field_first_name" should have a length of "255"
    Then the field "field_last_name" should have a length of "255"
    Then the field "field_profession" should have a length of "255"

  Scenario: Successful registration message (AC5)
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

  Scenario: The email the system sends by default when a user registers is: (AC5b)
    Given I am on the homepage
    And the test email system is enabled
    And I follow "Join now!"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    Then I press the "Create new account" button
    Then the email to "@timestamp@example.com" should contain "First Last,"
    And the email should contain "Thank you for registering at Partnership Resource Center. You may now log in"
    And the email should contain "at"
    And the email should contain "in the future using:"
    And the email should contain "username: @timestamp@example.com"
    And the email should contain "password: Your password"
    And the email should contain "--  Partnership Resource Center team"
    # PRC-277 Change the link in the email to the site url instead of login url
    And the email should not contain "/user"

  Scenario: Registration form validation - required fields (AC6a)
    Given I am on the homepage
    And I follow "Join now!"
    Then I press the "Create new account" button
    Then I should see the error message "First Name field is required."
    And I should see the error message "Last Name field is required."
    And I should not see the error message "Profession field is required."
    And I should see the error message "E-mail field is required."

  Scenario: Registration form validation - invalid email address (AC6b)
    Given I am on the homepage
    And I follow "Join now!"
    Then I fill in "invalid" for "E-mail"
    Then I press the "Create new account" button
    Then I should see the error message "The e-mail address invalid is not valid."

  Scenario: Registration form validation - passwords do not match (AC6c)
    Given I am on the homepage
    And I follow "Join now!"
    Then I fill in "abc" for "Password"
    And I fill in "xyz" for "Confirm password"
    Then I press the "Create new account" button
    Then I should see the error message "The specified passwords do not match."

  Scenario: Registration form - Password strength (AC6d)
    Given I am on the homepage
    And I follow "Join now!"
    Then I should see "Password strength:"

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
    Then the user "test@timestamp@example.com" should have a role of "Educator"

