@api @d7 @user @prc-105 @prc-1335
Feature: Admin UI: Edit User (PRC-105)
  As a PRC Administrator,
  I want to edit an existing user account,
  So that the last updated information is reflected in the system.

  Background:
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "prc/admin"
    And users:
      | name                    | mail                    | pass   | field_first_name | field_last_name | status |
      | joe_prc_105@example.com | joe_prc_105@example.com | xyz123 | Joe              | User            | 1      |
    Then I click "Users"
    Then the url should match "prc/admin/admin-users"
    # Now sort by User ID descending so that the new user we created is up top
    Then I click "User ID"
    Then I click on the edit link for the user "joe_prc_105@example.com"

  Scenario: AC1 - Clickable user ID column
    Then I should be at the edit page for the user "joe_prc_105@example.com"

  Scenario: AC2 - The header for this Admin page shall be the user's name (First Name + Last Name), followed by the User ID in the parentheses.
    Then I should see "Joe User"
    And I should see "(@uname[joe_prc_105@example.com])"
#    Then I should see the heading "Joe User (@uname[joe_prc_105@example.com])" in the "sub_header" region

  Scenario: AC2 - The header should stay the same on failed validation
    Then I fill in "E-mail *" with ""
    Then I press the "Save" button
    Then I should see "Joe User"
    And I should see "(@uname[joe_prc_105@example.com])"

  Scenario: AC3 - Keep the top nav bar (now in content area)
    Then I am on "prc/admin"
    Then I should see the link "Users" in the "content" region

  Scenario: AC4 - The following fields are to be displayed
    Then I should see a "First Name *" field
    And I should see a "Last Name *" field
    And I should see a "Profession" field
    And I should not see a "Username" field
    And I should see an "E-mail *" field
    And I should see a "Password" field
    And I should see a "Confirm password" field
    And I should see "Password strength"

  Scenario: AC5 - Only 1 role can be selected - radio button PRC-823 Changes to allow multiple roles
    Then I should see the checkbox "Educator"
    Then I should see the checkbox "PRC Admin"
    Then I should see the checkbox "Content Contributor"
    Then I should not see the checkbox "administrator"

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
    Then I select "Wyoming" from "State Where I Teach"
    Then I press the "Save" button
    Then I should see the message containing "The changes have been saved."

  #Scenario: AC8 - Cancel button
    # todo: Where does the Cancel button take you? What if you didn't come in through the users view?
    # Drupal doesn't give you a Cancel button on anything. It's the user's job to navigate away.
    # Users are used to clicking the Back button.Scenario:

  Scenario: PRC-948 Role field should be required
    Then I should see the text "Roles \*"
    When I uncheck the box "Educator"
    And I press the "Save" button
    Then I should see the error message containing "Roles field is required."

  Scenario: PRC-1335 Editing another user shouldn't show State Account #
    Then I should not see "State Account #"
