@api @d7
Feature: Forgot Password (PRC-146)
  As an educator,
  I want to reset my login password,
  so that I can continue to benefit from the contents and features provided by PRC in the website.

  # This test needs to run in Web Driver since it tests redirection and visibility
  @javascript
  Scenario: AC1 - The educator will select the "Forgot Password" link located in the Login block of the Home page. On click, the system will...
    # This test actually goes through the entire reset password flow and covers all 3 ACs.
    Given users:
      | name     | mail            | pass     | field_first_name | field_last_name | status |
      | Joe User | joe@example.com | xyz123   | Joe              | User            | 1      |
    And I am an anonymous user
    And I am on the homepage
    And the test email system is enabled
    When I click "Forgot password?"
    Then the url should match "user/password"
    Then I fill in "E-mail" with "joe@example.com"
    And I press "E-mail new password"
    Then I should see the message containing "Further instructions have been sent to your e-mail address."
    # The matching is very dependent on line-breaks and formatting
    Then the email to "joe@example.com" should contain "A request to reset the password for your account has been made at"
    And the email should contain "You may now log in by clicking this link or copying and pasting it to your"
    And I follow the link in the email
    Then I should see "Reset Password"
    And I should see "This is a one-time login for"
    And I should see an "Log in" button
    And I press "Log in"
    Then I should see the message containing "You have just used your one-time login link. It is no longer necessary to use this link to log in. Please change your password."
    And I fill in "Password" with "password"
    And I fill in "Confirm password" with "password"
    And I press "Save"
    Then I should see the message containing "The changes have been saved."
    Then I click "Log out"
    Then the url should match "/"
    Then I fill in "E-mail" with "joe@example.com"
    And I fill in "Password" with "password"
    And I press "Log in"
    Then I should see the link "Log out"
    And I should see "Welcome, Joe User"

  Scenario: AC2 - The educator will select the reset password link from the email and update their password.
    # This is covered in the big test for AC1

  Scenario: AC3 - The educator will log into the PRC website.
    # This is also covered in the big test for AC1.
