@api @sso @prc-1880
Feature: PRC-1880 SSO -- Users Created in PRC Exist in SSP IdP
  As a user, I want my information to be in PRC and LDAP / SSP IdP so that I can log in using SSO.

  Scenario: Account created in PRC via self-registration
    Given I am on the homepage
    And I follow "Create account"
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

#  Scenario: 2 Account created in PRC via admin - This is tested in sso_login_page.feature

  Scenario: Account created in PRC via an invite
    Given users:
      | name                    | mail                             | pass   | field_first_name | field_last_name | status | roles                 |
      | Behat Admin @timestamp  | behatadmin@timestamp@example.com | xyz123 | Joe              | Admin           | 1      | administrator         |
    And I am logged in as "Behat Admin @timestamp"
    And I visit "invite/add/invite_by_email"
    Then I check the box "Content Contributor"
    And I fill in "Message" with "4321MESSAGE1234"
    And I fill in "E-mail" with "example1@timestamp@example.com,example2@timestamp@example.com"
    And I select "Wyoming" from "State where the invitee teaches"
    And I press "Send Invitation"
    Then the email to "example1@timestamp@example.com" should contain "has sent you an invite!"
    And the email should contain "Congratulations! Parcc Inc. invites you to register and then log into the Partnership Resource Center."
    And the email should contain "4321MESSAGE1234"
    And I click "Log out"
    Then I follow link "0" in the email
    And I fill in "Password" with "abc123"
    And I fill in "Confirm password" with "abc123"
    And I fill in "First Name *" with "First"
    And I fill in "Last Name *" with "Last"
    # PRC-1020 State where I teach should be filled in
    And I should see the text "State Where I Teach"
    And I should see the text "Wyoming"
    And I check the box "I have read and agree with the Terms of Use and User Generated Content Disclaimer."
    And I press "Create new account"
    And I am an anonymous user
    And I am on the homepage
#    And I click "Log in"
    When I am on "onelogin_saml/sso?destination=user/login"
    And I fill in "username" with "example1@timestamp@example.com"
    And I fill in "password" with "abc123"
    And I press "Log in"
    And I press "Submit"
    Then I should be on "user"
