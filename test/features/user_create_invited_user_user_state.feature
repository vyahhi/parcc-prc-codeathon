@api @d7 @user @invite
Feature: PRC-834 Registration from Invite - Make State Required
  As a PRC Admin or District Admin I want to invite users to register for PRC website and provide their state, so the users are connected with their states.
  Acceptance Criteria
  State dropdown
  Field label: State where you teach
  Type: Dropdown
  Required: Yes
  Dropdown options see PRC-Registration-States.csv + "Other" at the end of the list

  Scenario: State Where You Teach is required
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Educator"
    And I fill in "Message" with "4321MESSAGE1234"
    And I fill in "E-mail" with "example1@timestamp@example.com,example2@timestamp@example.com"
    When I press "Send Invitation"
    Then I should see the error message containing "State Where You Teach field is required."

  Scenario: Non-member
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Educator"
    And I fill in "Message" with "4321MESSAGE1234"
    And I fill in "E-mail" with "example1@timestamp@example.com,example2@timestamp@example.com"
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
    But I should see the text "State Where I Teach"
    And I should see the text "Wyoming"
    And I press "Create new account"
    Then I should see the message containing "You have accepted the invitation from"
    And I should see the message containing "Registration successful. You are now logged in."
    #  Creates a new account with the pre-defined role
    And the user "example1@timestamp@example.com" should have a role of "Educator"
      And I follow "My account"
    Then I should not see the text "Member State:"
    But I should see the text "State Where I Teach:"
    And I should see the link "Wyoming"
    Then I delete the user with the email address "example1@timestamp@example.com"

  Scenario: Member
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "PARCC-Member Educator"
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
    But I should see the text "State Where I Teach"
    And I should see the text "Wyoming"
    And I press "Create new account"
    Then I should see the message containing "You have accepted the invitation from"
    And I should see the message containing "Registration successful. You are now logged in."
    # Creates a new account with the pre-defined role
    And the user "example1@timestamp@example.com" should not have a role of "Educator"
    And the user "example1@timestamp@example.com" should have a role of "PARCC-Member Educator"
    And I follow "My account"
    Then I should see the text "Member State:"
    And I should see the link "Illinois"
    And I should see the text "State Where I Teach:"
    And I should see the link "Wyoming"
    Then I delete the user with the email address "example1@timestamp@example.com"
