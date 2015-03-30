@api @d7 @user @invite
Feature: Create User Account Following an Invite (PRC-73)
  As a potential PRC Administrator,
  I want to create a new user account for myself after having received the create user account invitation from my fellow PRC Administrators,
  so that I can access the system with designated role/permissions.

  Background:
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Content Contributor"
    And I fill in "Message" with "4321MESSAGE1234"
    And I fill in "E-mail" with "example1@timestamp@example.com,example2@timestamp@example.com"
    And I select "Wyoming" from "State Where You Teach"
    And I press "Send Invitation"
    Then the email to "example1@timestamp@example.com" should contain "has sent you an invite!"
    And the email should contain "has invited you to join Partnership Resource Center at"
    And the email should contain "4321MESSAGE1234"
    And I click "Log out"
    Then I follow link "1" in the email

  Scenario: AC1 - When a potential user receives an invitation E-mail, the potential user may click the temporary URL that redirects the user to a Create User Account page.
    Then I should see the heading "Create User Account to Join Partnership Resource Center" in the "content" region
    And the url should match "user/register"
    And I should see "example1@timestamp@example.com" in the "E-mail" field

  Scenario: AC2 - The Create User Account page provides the following fields:
    Then I should see the heading "Create User Account to Join Partnership Resource Center" in the "content" region
    And the url should match "user/register"
    And I should see a "First Name *" field
    And I should see a "Last Name *" field
    And I should see a "Profession" field
    And I should see a "Password *" field
    And I should see a "Confirm password *" field

  Scenario: AC3 - Password Strength: A bar displays the provided password's strength. No restrictions.
    And I should see "Password strength"

  Scenario: AC4 - Validations: The following validations shall occur: Required fields
    Then I press the "Create new account" button
    Then I should see the error message "First Name field is required."
    And I should see the error message "Last Name field is required."
    And I should not see the error message "Profession field is required."
    # E-mail is filled in from the invitation
    And I should not see the error message "E-mail field is required."

   Scenario: AC4 - Validations: The following validations shall occur: Password must match Confirm Password field.
    Then I fill in "Password *" with "abc123"
    And I fill in "Confirm password *" with "123abc"
    Then I press the "Create new account" button
    Then I should see the error message "The specified passwords do not match."

  Scenario: AC5 - A Create New Account button is provided at the end. At click, the system shall:
    Then I should see the heading "Create User Account to Join Partnership Resource Center" in the "content" region
    And the url should match "user/register"
    And I should see "example1@timestamp@example.com" in the "E-mail" field
    And I fill in "Password" with "abc123"
    And I fill in "Confirm password" with "abc123"
    And I fill in "First Name *" with "First"
    And I fill in "Last Name *" with "Last"
    And I press "Create new account"
    Then I should see the message containing "You have accepted the invitation from"
    And I should see the message containing "Registration successful. You are now logged in."
    #  Creates a new account with the pre-defined role
    Then the user "example1@timestamp@example.com" should have a role of "Content Contributor"
    And the user "example1@timestamp@example.com" should not have a role of "Educator"
    Then I delete the user with the email address "example1@timestamp@example.com"
