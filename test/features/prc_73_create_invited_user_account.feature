@api @d7
Feature: Create User Account Following an Invite (PRC-73)
  As a potential PRC Administrator,
  I want to create a new user account for myself after having received the create user account invitation from my fellow PRC Administrators,
  so that I can access the system with designated role/permissions.

  Background:
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    And the test email system is enabled
    Then I select the radio button "Educator"
    And I fill in "Message" with "4321MESSAGE1234"
    And I fill in "E-mail" with "example1@example.com,example2@example.com"
    And I press "Send Invitation"
    Then the email to "example1@example.com" should contain "has sent you an invite!"
    And the email should contain "has invited you to join Partnership Resource Center at"
    And the email should contain "4321MESSAGE1234"
    And I click "Log out"

  @javascript
  Scenario: AC1 - When a potential user receives an invitation E-mail, the potential user may click the temporary URL that redirects the user to a Create User Account page.
    Then I follow link "1" in the email
    Then I should see the heading "Create User Account to Join Partnership Resource Center" in the "content" region
    And the url should match "user/register"
    And I should see "example1@example.com" in the "E-mail" field
#    And I fill in "Password" with "abc123"
#    And I fill in "Confirm password" with "abc123"
#    And I fill in "First name" with "First"
#    And I fill in "Last name" with "Last"
#    And I press "Create new account"

  @javascript
  Scenario: AC2 - The Create User Account page provides the following fields:
    Then I follow link "1" in the email
    Then I should see the heading "Create User Account to Join Partnership Resource Center" in the "content" region
    And the url should match "user/register"
    And I should see a "First Name *" field
    And I should see a "Last Name *" field
    And I should see a "Profession" field
    And I should see a "Password *" field
    And I should see a "Confirm password *" field

  @javascript
  Scenario: AC3 - Password Strength: A bar displays the provided password's strength. No restrictions.
    Then I follow link "1" in the email
    And I should see "Password strength"

  @javascript
  Scenario: AC4 - Validations: The following validations shall occur:
#  Password must match Confirm Password field. If the user did not provide the same values, the system provides feedback:
#  Passwords do not match
    Then I press the "Create new account" button
    Then I should see the error message "First Name field is required."
    And I should see the error message "Last Name field is required."
    And I should not see the error message "Profession field is required."
    And I should see the error message "E-mail field is required."


  # AC5 - A Create New Account button is provided at the end. At click, the system shall:
#  Validate that all required fields contain valid values. If not, the system displays Required Field in red font by the field, and provides with feedback:
#  Missing required fields.
#  Creates a new account with the pre-defined role
#  the account shall be Active
#  Logs the user in
#  Displays a confirmation message
