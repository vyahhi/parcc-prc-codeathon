@api @sso @prc-1892
Feature:  PRC-1892 PRC SSO Request New Password
  As a user, I want to be able to reset my password from the SSO login screen so that I am able to access PRC content for authenticated users.

  Scenario: 1 SSO Log In screen - Request New Password Link
    Given I am an anonymous user
    And I am on the homepage
    When I click "Log in"
    And I click "Forgot Password?"
    Then the url should match "user/password"

  Scenario: 2 Request New Password page - Email New Password button - Valid entry
    Given users:
      | name                    | mail                             | pass   | field_first_name | field_last_name | status | roles    |
      | Joe Educator @timestamp | joe_1892@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator |
    And I am an anonymous user
    And I am on the homepage
    And I click "Log in"
    When I click "Forgot Password?"
    And I fill in "E-mail" with "joe_1892@timestamp@example.com"
    And I press "E-mail new password"
    Then I should see "Further instructions have been sent to your e-mail address."
    And I should see "Please check your email"
    And I should see "An email with a link to reset your password has been sent to the email address you entered. The link will expire after 24 hours, and nothing will happen if the link is not used."
#    Then I see the Reset Password Email Sent Confirmation page [new page, see attached image Request New Password 2015-10-01 at 2.13.52 PM.png] that has:
#  PRC global nav
#  Alert: "Further instructions have been sent to your email address." [This alert is not mandatory, but it is what appears now after user clicks "Email New Password" button.]
#  Headline [H1]: "Please check your email [headline]
#  Body copy [standard body copy, see style guide]: "An email with a link to reset your password has been sent to the email address you entered. The link will expire after 24 hours, and nothing will happen if the link is not used."
#    And I receive a Request New Password email [existing functionality]

  Scenario: 2a Request New Password page - Email New Password button - Invalid entry [existing functionality]
    And I am an anonymous user
    And I am on the homepage
    And I click "Log in"
    When I click "Forgot Password?"
    And I fill in "E-mail" with "invalid@timestamp@example.com"
    And I press "E-mail new password"
    Then I should see "Sorry, invalid@timestamp@example.com is not recognized as a user name or an e-mail address."

#  Scenario: 3 Request New Password Email - link [existing functionality]
#    Given that I am an unauthenticated user
#    And I am viewing my Request New Password Email
#    When I click the reset password link
#    Then I see the Reset Password page [existing functionality, see attached image PRC - Reset Password - 2015-10-01 at 2.25.30 PM.png]

#  Scenario: 4 Reset Password page - Log In button [existing functionality]
#    Given that I am an unauthenticated user
#    And I am on the Reset Password page
#    When I click the Log In button
#    Then I see my Edit Account page [existing functionality]
#    And I am logged in to PRC

#  Scenario: 5 Edit Account page - Save button
#    Given that I am an authenticated user
#    And I am on my Edit Account page
#    And I have updated my password
#    And my fields are valid
#    When I click the save button
#    Then I see my Edit Account page [existing functionality]
#    And my new password is saved in IdP / LDAP
