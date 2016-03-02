@api @user @invite
Feature: PRC-217  Invite User with Additional Role Selection
  As a PRC Admin,
  I want to specify the user's state when I invite a state lead as Content Contributor role,
  so that the system can offer additional functionality using this new attribute.

#  Acceptance Criteria
#  PARCC-Member Educator exists (new role in addition of the current Educator ).

  Scenario: PARCC-Member Educator exists
    Given I am logged in as a user with the "PARCC-Member Educator" role

  Scenario:  The role Content Author shall be renamed to Content Contributor.
    Given I am logged in as a user with the "Content Contributor" role

  Scenario: In the Invite User page, the Role options will display the new role (PARCC-Member Educator) and role name (Content Contributor instead of Content Author). The new list of Role options shall be:
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I should see the checkbox "PARCC-Member Educator"
    Then I should see the checkbox "Content Contributor"
    Then I should not see the checkbox "Content Author"

  @javascript
  Scenario: When Content Contributor or PARCC-member Educator role is selected in the Invite User page, a new attribute State appears with a dropdown menu. The State field is invisible when PRC Admin or Educator role is selected.
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then "#edit-field-member-state-und" should not be visible
    But I check the box "PARCC-Member Educator"
    Then "#edit-field-member-state-und" should be visible
    Then I check the box "Educator"
    Then "#edit-field-member-state-und" should be visible
    Then I uncheck the box "PARCC-Member Educator"
    And I uncheck the box "Educator"
    Then "#edit-field-member-state-und" should not be visible
    But I check the box "Content Contributor"
    Then "#edit-field-member-state-und" should be visible
    But I check the box "PRC Admin"
    Then "#edit-field-member-state-und" should be visible
    But I uncheck the box "Content Contributor"
    Then "#edit-field-member-state-und" should not be visible
    When I check the box "Content Administrator (Curator)"
    Then "#edit-field-member-state-und" should not be visible

  Scenario: Selecting a state saves the state to the invite
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@example.com"
    And I select "Wyoming" from "State where the invitee teaches"
    And I press "Send Invitation"
    Then I should see the text "Wyoming"

  Scenario: The State field is optional. One or no option can be selected.
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@example.com"
    And I select "Wyoming" from "State where the invitee teaches"
    And I select "- None -" from "Member State"
    And I press "Send Invitation"
    Then I should not see the text "Member State"

  Scenario: Fill in State field and then change roles
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@example.com"
    And I select "Ohio" from "State where the invitee teaches"
    Then I check the box "Educator"
    And I uncheck the box "Content Contributor"
    And I select "Wyoming" from "State where the invitee teaches"
    And I press "Send Invitation"
    Then I should not see the text "Member State"
    And I should not see the text "Ohio"

#  The email sending shall be the same as implemented currently