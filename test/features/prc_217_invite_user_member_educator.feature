@api
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
    Then I select the radio button "PARCC-Member Educator"
    Then I select the radio button "Content Contributor"
    Then I should not see the radio button "Content Author"

  @javascript
  Scenario: When Content Contributor or PARCC-member Educator role is selected in the Invite User page, a new attribute State appears with a dropdown menu. The State field is invisible when PRC Admin or Educator role is selected.
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I should not see the text "State"
    But I select the radio button "PARCC-Member Educator"
    And I should see the text "State"
    Then I select the radio button "Educator"
    And I should not see the text "State"
    But I select the radio button "Content Contributor"
    And I should see the text "State"
    But I select the radio button "PRC Admin"
    And I should not see the text "State"
    When I select the radio button "Content Administrator (Curator)"
    And I should not see the text "State"

  Scenario:  The State dropdown menu contains the following options (notice they're in alphabetical order):
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    And I should see the text "Select a state"
    And I should see the text "Arkansas"
    And I should see the text "Colorado"
    And I should see the text "District of Columbia"
    And I should see the text "Illinois"
    And I should see the text "Louisiana"
    And I should see the text "Maryland"
    And I should see the text "Massachusetts"
    And I should see the text "Mississippi"
    And I should see the text "New Jersey"
    And I should see the text "New Mexico"
    And I should see the text "New York"
    And I should see the text "Ohio"
    And I should see the text "Rhode Island"

  Scenario: Selecting a state saves the state to the invite
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I select the radio button "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@example.com"
    And I select "Illinois" from "State"
    And I press "Send Invitation"
    Then I should see the text "Illinois"

  Scenario: The State field is optional. One or no option can be selected.
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I select the radio button "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@example.com"
    And I select "Select a state" from "State"
    And I press "Send Invitation"
    Then I should not see the text "Member State"

  Scenario: Fill in State field and then change roles
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I select the radio button "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@example.com"
    And I select "Ohio" from "State"
    Then I select the radio button "Educator"
    And I press "Send Invitation"
    Then I should not see the text "Member State"
    And I should not see the text "Ohio"

#  The email sending shall be the same as implemented currently