@api @sso @login @prc-1891
Feature: PRC-1891 PRC SSO Login Screen
  As a user, I want to log in with SSO so that I am logged in to PRC and Seraph with a single log in.

  Scenario: SSO Login Screen - login valid
    Given users:
      | name                    | mail                             | pass   | field_first_name | field_last_name | status | roles                 |
      | Behat Admin @timestamp  | behatadmin@timestamp@example.com | xyz123 | Joe              | Admin           | 1      | administrator         |
      | Joe Educator @timestamp | joe_1891ed@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator, State Admin |
    # Provisioning users programmatically doesn't work because the password is already hashed by the time we get to the
    # object. We have to edit the user manually so the clear password gets sent over.

    And I am logged in as "Behat Admin @timestamp"
    And I should be at the edit page for the user "Joe Educator @timestamp"
    And I fill in "Password" with "xyz123"
    And I fill in "Confirm password" with "xyz123"
    And I fill in "First Name" with "Joe"
    And I fill in "Last Name" with "Educator"
    And I select "Alabama" from "State Where I Teach"
    And I check the box "State Admin"
    And I check the box "Content Contributor"
    And I press "Save"

    Then the LDAP user with "joe_1891ed@timestamp@example.com" should have the role "State Admin"
    Then the LDAP user with "joe_1891ed@timestamp@example.com" should have the role "Content Contributor"

    # Log out of the admin and use SSO on the user we just edited
    And I am an anonymous user
    And I am on the homepage
#    And I click "Log in"
    When I am on "onelogin_saml/sso?destination=user/login"
    And I fill in "username" with "joe_1891ed@timestamp@example.com"
    And I fill in "password" with "xyz123"
    And I press "Log in"
    And I press "Submit"
    Then I should be on "user"

  Scenario: SSO Login Screen - login invalid
    Given users:
      | name                    | mail                             | pass   | field_first_name | field_last_name | status | roles    |
      | Joe Educator @timestamp | joe_1891ed@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator |
    When I am on "onelogin_saml/sso?destination=user/login"
    And I fill in "username" with "joe_1891ed@timestamp@example.com"
    And I fill in "password" with "xyz123"
    And I press "Log in"
    Then I should see the text "Incorrect username or password"
    And I should see the text "Either no user with the given username could be found, or the password you gave was wrong. Please check the username and try again."