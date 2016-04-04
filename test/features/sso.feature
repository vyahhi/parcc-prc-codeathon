@sso @prc-1879 @api
Feature: SSO login functionality
    Scenario: PRC-1879 Allow for us to login through Drupal in the event that SSO has gone AWOL.
      Given users:
        | name            | mail                               | pass   | field_first_name | field_last_name | status |
        | Joe Admin       | joe_prc_346a@timestamp@example.com | xyz123 | Joe              | Admin           | 1      |
      And I am an anonymous user
      When I visit "user/local-login"
      And I fill in "E-mail *" with "joe_prc_346a@timestamp@example.com"
      And I fill in "Password *" with "xyz123"
      And I press "Log in"
      Then I should see "Joe Admin"

    @prc-1878
    Scenario: PRC-1878 - Redirect user to SSO login when they click log-in link
      Given SSO is enabled
      And I am an anonymous user
      When I visit "user/login"
      Then I should not see "Log in using"
      And I should see "Email:"
      And I should see an "Log in" button

    Scenario: PRC-1878 - Redirect user to SSO if they visit /user and are not logged in.
      Given SSO is enabled
      And I am an anonymous user
      When I visit "user"
      Then I should not see "Log in using"
      And I should see "Email:"
      And I should see an "Log in" button

     Scenario: /user shows the currently logged in users profile
       Given SSO is enabled
       Given users:
         | name            | mail                               | pass   | field_first_name | field_last_name | status |
         | Joe Admin       | joe_prc_346a@timestamp@example.com | xyz123 | Joe              | Admin           | 1      |
       When I visit "user/local-login"
       And I fill in "E-mail *" with "joe_prc_346a@timestamp@example.com"
       And I fill in "Password *" with "xyz123"
       And I press "Log in"
       When I visit "user"
       Then I should see "History"

  Scenario: PRC-2058 - passwords get changed when a user accepts an invite
    Given users:
      | name                       | mail                        | pass   | field_first_name | field_last_name | status | roles     |
      | Joe Educator @timestamp    | admin@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | PRC Admin |
    And I am logged in as "Joe Educator @timestamp"
    # Need to re-save the password so pw in ldap is one we know instead of random
    And I should be at the edit page for the user "Joe Educator @timestamp"
    And I fill in "Current password" with "xyz123"
    And I fill in "Password" with "xyz123"
    And I fill in "Confirm password" with "xyz123"
    And for "First Name *" I enter "fname"
    And for "Last Name *" I enter "lname"
    And I select "Alabama" from "State Where I Teach *"
    # And I select "Alabama" from the "State Where I Teach *" Chosen widget
    And I press "Save"
    And I visit "invite/add/invite_by_email"
    Then I check the box "Educator"
    And I fill in "Message" with "4321MESSAGE1234"
    And I fill in "E-mail" with "james@timestamp@example.com"
    And I select "Alabama" from "State where the invitee teaches"
    # And I select "Alabama" from the "State where the invitee teaches" Chosen widget
    And I press "Send Invitation"
    And I am an anonymous user
    Then the email to "james@timestamp@example.com" should contain "has sent you an invite!"
    And I follow the link in the email
    And for "Password *" I enter "password"
    And for "Confirm password *" I enter "password"
    And for "First Name *" I enter "fname"
    And for "Last Name *" I enter "lname"
    Then I check the box "I have read and agree with the Terms of Use and User Generated Content Disclaimer."
    And I press "Create new account"
    And I am an anonymous user
    And I visit "user"
    And I enter "admin@timestamp@example.com" for "username"
    And I enter "password" for "password"
    And I press "Log in"
    And I follow meta refresh
    And I should see "Incorrect username or password"
    And I should not see the link "Admin"
    And I enter "admin@timestamp@example.com" for "username"
    And I enter "xyz123" for "password"
    And I press "Log in"
    And I should not see "Incorrect username or password"


