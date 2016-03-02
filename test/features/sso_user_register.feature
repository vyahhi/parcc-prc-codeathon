@api @sso @prc-1893
Feature: PRC-1893 PRC SSO Register
  As a user, I want to be able to register from the SSO login screen so that I can register for PRC.

  Scenario: Account created in PRC via self-registration clicked on the SSO login page
    Given I am on the homepage
#    And I click "Log in"
    When I am on "onelogin_saml/sso?destination=user/login"
    And I follow "Create new account"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    And I select "Wyoming" from "Where you teach"
    Then I check the box "I have read and agree with the Terms of Use and User Generated Content Disclaimer."
    Then I press the "Create new account" button
    Then I should see the message "Registration successful. You are now logged in."
    And I am an anonymous user
    And I am on the homepage
#    And I click "Log in"
    When I am on "onelogin_saml/sso?destination=user/login"
    And I fill in "username" with "@timestamp@example.com"
    And I fill in "password" with "abc123"
    And I press "Log in"
    And I press "Submit"
    Then I should be on "user"
