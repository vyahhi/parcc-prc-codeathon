@api @d7 @diglib
  Feature: PRC-1485, if a user has been invited it may cause errors when creating content with the subject and standards fields.

    Scenario: Invite a user, and simulate shs requests
      Given the test email system is enabled
      And I am logged in as a user with the "PRC Admin" role
      And I visit "prc/admin/admin-users"
      And I click "Invite New User"
      And I enter "user-sub-standard-test@example.com" for "E-mail *"
      And I select "Wyoming" from "State where the invitee teaches"
      And I check the box "Content Contributor"
      And I press "Send Invitation"
      And I should see the message containing "Invitation was sent"
      And I am an anonymous user
      And the email to "user-sub-standard-test@example.com" should contain "I'd like to invite you"
      When I follow the link in the email
      And I fill in "abc123" for "Password"
      And I fill in "abc123" for "Confirm password"
      And I fill in "First" for "First Name"
      And I fill in "Last" for "Last Name"
      And I check the box "I have read and agree with the Terms of Use and User Generated Content Disclaimer."
      And I press the "Create new account" button

    @javascript
    Scenario: actual test
      Given I visit "user/login"
      And I enter "user-sub-standard-test@example.com" for "E-mail *"
      And I enter "abc123" for "Password *"
      And I press "Log in"
      Then I visit "node/add/digital-library-content"
      And I simulate subject/standard shs requests

    Scenario: clean up
      And I delete the user with the email address "user-sub-standard-test@example.com"




