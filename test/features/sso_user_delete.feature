@api @sso @prc-1862
Feature:  PRC-1862 Ensure users can delete accounts
  As a PRC Admin, when I delete a user account, I want the user's account information to be deleted from both Drupal and LDAP.

#  Scenario: Deleting
#  And I delete the LDAP user "joe_prc_611444772521@example.com"

  Scenario: Each of the scenarios is covered by the actual deletion of an account
    # Create the first user, the one to be deleted
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
    And I click "Log out"
    And I am an anonymous user
    And I am on the homepage
#    And I click "Log in"
    When I am on "onelogin_saml/sso?destination=user/login"
    And I fill in "username" with "@timestamp@example.com"
    And I fill in "password" with "abc123"
    And I press "Log in"
    And I press "Submit"
    Then I should be on "user"
    And I click "Log out"
    Then I am an anonymous user

    # We're logged out. Now create the admin user to delete the first user.
    Given I am on the homepage
#    And I click "Log in"
    When I am on "onelogin_saml/sso?destination=user/login"
    And I follow "Create new account"
    Then I fill in "admin@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    And I select "Wyoming" from "Where you teach"
    Then I check the box "I have read and agree with the Terms of Use and User Generated Content Disclaimer."
    Then I press the "Create new account" button
    Then I should see the message "Registration successful. You are now logged in."
    And I click "Log out"
    And I am an anonymous user
    And I am on the homepage
#    And I click "Log in"
    When I am on "onelogin_saml/sso?destination=user/login"
    And I fill in "username" with "@timestamp@example.com"
    And I fill in "password" with "abc123"
    And I press "Log in"
    And I press "Submit"
    Then I should be on "user"
    Then I give the user "admin@timestamp@example.com" the "administrator" role

    # Log out, then log in through SSO
    And I click "Log out"
    And I am an anonymous user
    And I am on the homepage
#    And I click "Log in"
    When I am on "onelogin_saml/sso?destination=user/login"
    And I fill in "username" with "admin@timestamp@example.com"
    And I fill in "password" with "abc123"
    And I press "Log in"
    And I press "Submit"
    And the LDAP user with "admin@timestamp@example.com" should have the role "administrator"
    And I edit the user "@timestamp@example.com"
    And I press "Cancel account"
    And I select the radio button "Delete the account and its content."
    And I press "Cancel account"
    And I follow meta refresh
    Then there should not be an LDAP user "@timestamp@example.com"
    Then there should not be an LDAP user "@timestamp@example.com"
    And I delete the LDAP user "admin@timestamp@example.com"