@api @d7
Feature: Admin UI: Edit User (PRC-105)
  As a PRC Administrator,
  I want to edit an existing user account,
  So that the last updated information is reflected in the system.

  Background:
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    And users:
      | name     | mail                    | pass     | field_first_name | field_last_name | status |
      | Joe User | joe_prc_105@example.com | xyz123   | Joe              | User            | 1      |
    Then I click "Users"
    Then the url should match "admin-users"
    # Now sort by User ID descending so that the new user we created is up top
    Then I click "User ID"
    Then I click on the edit link for the user "Joe User"

  Scenario: AC1 - Clickable user ID column
    Then I should be at the edit page for the user "Joe User"

  Scenario: AC2 - The header for this Admin page shall be the user's name (First Name + Last Name), followed by the User ID in the parentheses.
    Then I should see the heading "Joe User (@uname[Joe User])" in the "content" region

  Scenario: AC2 - The header should stay the same on failed validation
    Then I fill in "E-mail *" with ""
    Then I press the "Save" button
    Then I should see the heading "Joe User (@uname[Joe User])" in the "content" region

  Scenario: AC3 - Keep the top nav bar
    Then I should see the link "Users" in the "header" region

  Scenario: AC4 - The following fields are to be displayed
    Then I should see a "First Name *" field
    And I should see a "Last Name *" field
    And I should see a "Profession" field
    And I should not see a "Username" field
    And I should see an "E-mail *" field
    And I should see a "Password" field
    And I should see a "Confirm password" field
    And I should see "Password strength"

  Scenario: AC5 - Only 1 role can be selected - radio button
    Then I select the radio button "Educator"
    Then I select the radio button "PRC Admin"
    Then I select the radio button "Content Author"
    Then I should not see the radio button "administrator"

  Scenario: AC6a - Validation - required fields
    Then I fill in "First Name *" with ""
    Then I fill in "Last Name *" with ""
    Then I fill in "Profession" with ""
    Then I fill in "E-mail *" with ""
    Then I press the "Save" button
    Then I should see the error message "First Name field is required."
    And I should see the error message "Last Name field is required."
    And I should not see the error message "Profession field is required."
    And I should see the error message "E-mail field is required."

  Scenario: AC6b - Validation - invalid email address
    Then I fill in "invalid" for "E-mail"
    Then I press the "Save" button
    Then I should see the error message "The e-mail address invalid is not valid."

  Scenario: AC6c - Validation - passwords do not match
    Then I fill in "abc" for "Password"
    And I fill in "xyz" for "Confirm password"
    Then I press the "Save" button
    Then I should see the error message "The specified passwords do not match."

  Scenario: AC6d - Registration form - Password strength
    Then I should see "Password strength:"

  Scenario: AC7 - Save button
    Then I fill in "First Name *" with "New First"
    Then I fill in "Last Name *" with "New Last"
    Then I fill in "Profession" with "New Job"
    Then I fill in "E-mail *" with "new@example.com"
    Then I press the "Save" button
    Then I should see the message containing "The changes have been saved."

  #Scenario: AC8 - Cancel button
    # todo: Where does the Cancel button take you? What if you didn't come in through the users view?
    # Drupal doesn't give you a Cancel button on anything. It's the user's job to navigate away.
    # Users are used to clicking the Back button.Scenario:

  Scenario: AC9 - Javascript to confirm nav away from page
