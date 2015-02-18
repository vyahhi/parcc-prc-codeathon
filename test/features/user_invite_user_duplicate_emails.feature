@api @user @invite
Feature: PRC-214 Admin UI: Invite User - Duplicate Emails
  As a PRC Admin,
  I want to be notified of any duplicate emails,
  so that I can remove the duplicate email address listed in the email text box within the form.

#  AC1 User is on the Invite New User page
  AC2 User enters more than one duplicate email address into the email field
  AC3 User has pressed the "Send Invitation" button
  AC4 Validations: The following validation shall occur:
  - All entered e-mail addresses must be unique (Back-end coding in the validation routine). If the user enters duplicate e-mail addresses, the system provides feedback on the top of the form, appending additional duplicate email addresses:
      Please remove the following duplicate email addresses from the list: example1@example.com, example2@example.com
  - All other validation messages appear along with the duplicate messaging
      Valid email address format (PRC-92)
  - No emails will be sent until all error conditions are successfully corrected
  - Resubmit the form

  Scenario: Duplicate email addresses
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I select the radio button "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@example.com;example@example.com;one@example.com"
    And I select "Illinois" from "State"
    And I press "Send Invitation"
    Then I should see the error message containing "Please remove the following duplicate email addresses from the list:"
    Then I should see the error message containing "example@example.com"
    Then I should not see the error message containing "one@example.com"

  Scenario: Multiple sets of duplicate email addresses
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I select the radio button "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@example.com,example@example.com,example1@example.com,example2@example.com,example2@example.com"
    And I select "Illinois" from "State"
    And I press "Send Invitation"
    Then I should see the error message containing "Please remove the following duplicate email addresses from the list:"
    Then I should see the error message containing "example@example.com"
    Then I should not see the error message containing "example1@example.com"
    Then I should see the error message containing "example2@example.com"

  Scenario: Multiple sets of duplicate email addresses, out of order
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I select the radio button "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@example.com,example1@example.com,example2@example.com,example1@example.com,example2@example.com"
    And I select "Illinois" from "State"
    And I press "Send Invitation"
    Then I should see the error message containing "Please remove the following duplicate email addresses from the list:"
    Then I should see the error message containing "example1@example.com"
    Then I should not see the error message containing "example@example.com"
    Then I should see the error message containing "example2@example.com"
