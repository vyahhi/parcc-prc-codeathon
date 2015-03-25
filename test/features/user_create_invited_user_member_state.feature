@api @d7 @user @invite
Feature: PRC-363 State Association to Invited Users
  As a PRC Admin,
  I want the system to store the state I select for the users I invite to create account,
  so that their user profile is associated to their state when creating a new account.

  Scenario: Accepting an invitation with a state saves that state to the user
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Content Contributor"
    And I fill in "Message" with "4321MESSAGE1234"
    And I fill in "E-mail" with "example1@timestamp@example.com,example2@timestamp@example.com"
    And I select "Illinois" from "State"
    And I select "Wyoming" from "State Where You Teach"
    And I press "Send Invitation"
    Then the email to "example1@timestamp@example.com" should contain "has sent you an invite!"
    And the email should contain "has invited you to join Partnership Resource Center at"
    And the email should contain "4321MESSAGE1234"
    And I click "Log out"
    Then I follow link "1" in the email
    Then I should see the heading "Create User Account to Join Partnership Resource Center" in the "content" region
    And the url should match "user/register"
    And I should see "example1@timestamp@example.com" in the "E-mail" field
    And I fill in "Password" with "abc123"
    And I fill in "Confirm password" with "abc123"
    And I fill in "First Name *" with "First"
    And I fill in "Last Name *" with "Last"
    And I should not see a "Member State" field
    And I press "Create new account"
    Then I should see the message containing "You have accepted the invitation from"
    And I should see the message containing "Registration successful. You are now logged in."
    #  Creates a new account with the pre-defined role
    Then the user "example1@timestamp@example.com" should have a role of "Content Contributor"
    And the user "example1@timestamp@example.com" should not have a role of "Educator"
      And I follow "My account"
    Then I should see the text "Member State:"
    And I should see the link "Illinois"
    Then I delete the user with the email address "example1@timestamp@example.com"
