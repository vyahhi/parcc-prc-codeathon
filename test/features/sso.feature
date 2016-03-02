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




