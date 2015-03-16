@api @user @invite
Feature: PRC-485 Admin UI: Invite User - Email Already Exists
  As a PRC Admin,
  I want to be notified of any emails that already exist in the system,
  so that I can remove the existing email address listed in the email text box within the form.

#  User is on the Invite New User page
#  User enters at least one email address that is already in the system
#  User has pressed the "Send Invitation" button
#  Validations: The following validation shall occur:
  All entered e-mail addresses must be unique (Back-end coding in the validation routine). If the user enters an existing e-mail addresses, the system provides feedback on the top of the form, appending additional exisiting email addresses:
  Please remove the following already existing email addresses from the list: example1@example.com, example2@example.com
  All other validation messages appear along with the duplicate messaging
#  Valid email address format (PRC-92)
#  No emails will be sent until all error conditions are successfully corrected
#  Resubmit the form

  Scenario: Duplicate email addresses
    Given users:
      | name         | mail                                | pass   | field_first_name | field_last_name | status |
      | Joe Illinois | joe_prc_485il@timestamp@example.com | xyz123 | Joe              | Illinois        | 1      |
      | Joe Arkansas | joe_prc_485ar@timestamp@example.com | xyz123 | Joe              | Arkansas        | 1      |
    And I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@example.com;joe_prc_485il@timestamp@example.com"
    And I select "Illinois" from "State"
    And I press "Send Invitation"
    Then I should see the error message containing "Please remove the following already existing email addresses from the list:"
    Then I should see the error message containing "joe_prc_485il@timestamp@example.com"
    Then I should not see the error message containing "example@example.com"

  Scenario: Multiple duplicate email addresses
    Given users:
      | name         | mail                                | pass   | field_first_name | field_last_name | status |
      | Joe Illinois | joe_prc_485il@timestamp@example.com | xyz123 | Joe              | Illinois        | 1      |
      | Joe Arkansas | joe_prc_485ar@timestamp@example.com | xyz123 | Joe              | Arkansas        | 1      |
    And I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "joe_prc_485ar@timestamp@example.com;example@example.com;joe_prc_485il@timestamp@example.com"
    And I select "Illinois" from "State"
    And I press "Send Invitation"
    Then I should see the error message containing "Please remove the following already existing email addresses from the list:"
    Then I should see the error message containing "joe_prc_485il@timestamp@example.com"
    Then I should see the error message containing "joe_prc_485ar@timestamp@example.com"
    Then I should not see the error message containing "example@example.com"
