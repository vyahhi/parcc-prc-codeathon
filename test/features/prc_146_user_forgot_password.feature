@api @d7
Feature: Forgot Password (PRC-146)
  As an educator,
  I want to reset my login password,
  so that I can continue to benefit from the contents and features provided by PRC in the website.

  Scenario: Complete walkthrough
    # This test actually goes through the entire reset password flow and covers all 3 ACs.
    Given users:
      | name     | mail                    | pass     | field_first_name  | field_last_name  | status |
      | Joe User | joe_prc_146@example.com | xyz123   | JoeF              | UserL            | 1      |
    And I am an anonymous user
    And I am on the homepage
    And the test email system is enabled
    When I click "Forgot password?"
    Then the url should match "user/password"
    And I should see the text "Request new password"
    Then I fill in "E-mail" with "joe_prc_146@example.com"
    And I press "E-mail new password"
    Then I should see the message containing "Further instructions have been sent to your e-mail address."
    # The matching is very dependent on line-breaks and formatting
    Then the email to "joe_prc_146@example.com" should contain "A request to reset the password for your account has been made at"
    And the email should contain "You may now log in by clicking this link or copying and pasting it to your"
    And the email should contain "Replacement login information for JoeF UserL at Partnership Resource Center"
    And the email should contain "JoeF UserL,"
    And I follow the link in the email
    Then I should see "Reset Password"
    And I should see "This is a one-time login for"
    And I should see an "Log in" button
    And I press "Log in"
    Then I should see the message containing "You have just used your one-time login link. It is no longer necessary to use this link to log in. Please change your password."
    And I fill in "Password" with "password1"
    And I fill in "Confirm password" with "password1"
    And I press "Save"
    Then I should see the message containing "The changes have been saved."
    Then I click "Log out"
    Then the url should match "/"
    Then I fill in "E-mail" with "joe_prc_146@example.com"
    And I fill in "Password" with "password1"
    And I press "Log in"
    Then I should see the link "Log out"
    And I should see "Welcome, JoeF UserL"

  # AC2 - The educator will select the reset password link from the email and update their password.
  # This is covered in the big test for AC1

  # AC3 - The educator will log into the PRC website.
  # This is also covered in the big test for AC1.

  Scenario: Unregistered email address
  # This test actually goes through the entire reset password flow and covers all 3 ACs.
    Given I am an anonymous user
    And I am on the homepage
    And the test email system is enabled
    When I click "Forgot password?"
    Then I fill in "E-mail" with "notarealemailaddress@example.com"
    And I press "E-mail new password"
    Then I should see the error message containing "Sorry, notarealemailaddress@example.com is not recognized as a user name or an e-mail address."

  Scenario: Invalid email address
    Given I am an anonymous user
    And I am on the homepage
    And the test email system is enabled
    When I click "Forgot password?"
    Then I fill in "E-mail" with "notarealemailaddress"
    And I press "E-mail new password"
    Then I should see the error message containing "Sorry, notarealemailaddress is not recognized as a user name or an e-mail address."
