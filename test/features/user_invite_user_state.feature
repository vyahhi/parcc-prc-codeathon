@api @user @invite @state @prc-1020 @prc-1032
Feature: PRC-1020 Registration from Invite - State
  As an anonymous user,
  I want to register from an invitation for the PRC site and see my state displayed,
  so I can verify that it is correct.
  Given that I received an invitation to the PRC site
  When I click on the link to become a member in the invite email
  Then I see the Create User Account to Join Partnership Resource Center page
  Differences from existing functionality:
  "State where you teach" field label [was "User State"]
  <State entered when invitation created> [static text, was dropdown] (Jack, I think we discussed that state will be static and email will be populated and editable (and the email functionality already exists). Holler if this is incorrect; if correct, feel free to delete this note from the story. )
  For reference
  For the form to invite user, see Admin - Invite User - State PRC-1032

  Scenario: PRC-1032 - State field on user invite
    Given I am logged in as a user with the "PRC Admin" role
    When I visit "invite/add/invite_by_email"
    Then I should see the text "State where the invitee teaches"

  Scenario: PRC-1032 - State where invitee teaches is required
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    When I press "Send Invitation"
    Then I should see the error message containing "State where the invitee teaches field is required."

  Scenario: PRC-1032 - Member state appended to member states
    Given I am logged in as a user with the "PRC Admin" role
    When I visit "invite/add/invite_by_email"
    Then I select "Illinois" from "State where the invitee teaches"

  Scenario: PRC-1032 - State where invitee teaches saved on invitation
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Educator"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@timestamp@example.com"
    Given I am logged in as a user with the "PRC Admin" role
    When I visit "invite/add/invite_by_email"
    Then I select "Illinois" from "State where the invitee teaches"
    And I press "Send Invitation"
    Then I should see the text "Illinois"
