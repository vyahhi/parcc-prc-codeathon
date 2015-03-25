@api @d7 @user @invite
Feature: PRC-945 Invite - TRT Admin role(s)
  As a PRC Admin, I want to be able to invite a user who doesn't exist in the system to the PRC site as a State Admin, District Admin or School Admin so that the user can do the TRT things he/she is allowed to do.
  Acceptance Criteria
  Given I am logged in as a PRC Admin
  And I am on the user invite page
  When I select School Admin, District Admin or State Admin role
  Then a non-TRT role (Educator, PARCC-Member Educator, Content Contributor, Content Administrator (Curator) or PRC Admin) is required
  Additional Considerations
  If District Admin is also a School Admin, the District Admin will be able to run readiness checks for school.
  District Admin will not be admin for multiple districts, per Peter's email 2/26/15
  State Admin will not be admin for multiple states, per Peter's email 2/26/15

  Scenario: Non-TRT role is required
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    And I fill in "Message" with "4321MESSAGE1234"
    And I fill in "E-mail" with "example1@timestamp@example.com,example2@timestamp@example.com"
    And I check "School Admin"
    And I press "Send Invitation"
    Then I should see the message "A non-TRT role is required."