@api @trt @district @school
Feature: PRC-944 School Admin - Assign Role
  As a District Admin, I want to be able to assign a user (who either does or doesn't exist in the system) to the School Admin role so that the user can run readiness checks and view school readiness.
  Acceptance Criteria
#  State where you teach field displays state associated with District is displayed (static text)

  Scenario: User doesn't exist in system - non-member
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title                 | uid         |
      | PRC-944 S1 @timestamp | @currentuid |
    And "School" nodes:
      | title                    | field_ref_district          | field_contact_email            | uid         |
      | School 944 S1 @timestamp | @nid[PRC-944 S1 @timestamp] | example1@timestamp@example.com | @currentuid |
    Then the email to "example1@timestamp@example.com" should contain "has sent you an invite!"
    # Now the invitation is generated. Accept it and verify the user.
    And I am an anonymous user
    Then I follow link "1" in the email
    And I fill in "Password" with "abc123"
    And I fill in "Confirm password" with "abc123"
    And I fill in "First Name *" with "First"
    And I fill in "Last Name *" with "Last"
    And I should not see a "Member State" field
    And I press "Create new account"
    Then I should see the message containing "You have accepted the invitation from"
    And I should see the message containing "Registration successful. You are now logged in."
    And the user "example1@timestamp@example.com" should have a role of "Educator"
    And the user "example1@timestamp@example.com" should have a role of "School Admin"
    Then I delete the user with the email address "example1@timestamp@example.com"

  Scenario Outline: User doesn't exist in system - member
    Given I am logged in as a user with the "District Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid |
      | <member_state> | <user_state>     | <member_state>     | 1   |
    And "District" nodes:
      | title                 | uid         | field_ref_trt_state  |
      | PRC-944 S1 @timestamp | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title                    | field_ref_district          | field_contact_email            | uid         |
      | School 944 S1 @timestamp | @nid[PRC-944 S1 @timestamp] | example1@timestamp@example.com | @currentuid |
    Then the email to "example1@timestamp@example.com" should contain "has sent you an invite!"
    # Now the invitation is generated. Accept it and verify the user.
    And I am an anonymous user
    Then I follow link "1" in the email
    And I fill in "Password" with "abc123"
    And I fill in "Confirm password" with "abc123"
    And I fill in "First Name *" with "First"
    And I fill in "Last Name *" with "Last"
    And I should not see a "Member State" field
    And I press "Create new account"
    Then I should see the message containing "You have accepted the invitation from"
    And I should see the message containing "Registration successful. You are now logged in."
    And the user "example1@timestamp@example.com" should not have a role of "Educator"
    And the user "example1@timestamp@example.com" should have a role of "PARCC-Member Educator"
    And the user "example1@timestamp@example.com" should have a role of "School Admin"
    And I follow "My account"
    Then I should see the text "Member State:"
    And I should see the link "<member_state>"
    And I should see the text "State Where I Teach"
    And I should see the link "<user_state>"
    Then I delete the user with the email address "example1@timestamp@example.com"
  Examples:
    | user_state    | member_state   |
    | West Colorado | South Illinois
#  Scenario 2: User exists in system and user is not already a school admin
#    Given the user exists in the system
#    And user is not already a school admin
#    When school is saved
#    Then user gets School Admin role
#    And the School Admin has access to the associated School Readiness page
#  Scenario 3: User exists in system and user is not already a school admin and user has Educator role and school is in a PARCC-member state
#    Given the user exists in the system
#    And user is not already a school admin
#    And user has Educator role
#    And the school for which the user is being given school admin role is in a PARCC-member state
#    When school is saved
#    Then user gets School Admin role
#    And user gets PARCC-Member Educator role
#    And the School Admin has access to the associated School Readiness page
#  Scenario 4: User exists in system and user is already a school admin
#    Given the user exists in the system
#    And user is already a school admin
#    When school is saved
#    Then the School Admin has access to the associated School Readiness page
#  Scenario 5: User exists in system and user is already a school admin and user has Educator role and new school is in a PARCC-member state
#    Given the user exists in the system
#    And user is already a school admin
#    And user has Educator role
#    And the school for which the user is being given school admin role is in a PARCC-member state
#    When school is saved
#    Then user gets PARCC-Member Educator role
#    And the School Admin has access to the associated School Readiness page
