@api @trt @structured @school
Feature: PRC-960 School Admin - Replace
  As a District Admin, I want to be able to change an admin associated with a school so that if the person responsible for running the readiness checks for a school changes, the right person will have access to the school readiness page and the structured capacity checks.
#  Acceptance Criteria
#  Given that I am logged in as a District Admin
#  And I am on my Edit School page
#  And I change the email address
#  And I have no invalid fields
#  When I click Submit:
#  Scenario 1: Previous school admin is not an admin for another school
#    Given the previous school admin is not an admin for another school
#    Then the previous school admin loses School Admin role
#    And the previous school admin loses access to the associated school readiness page
#    And the new school admin should have School Admin role
#    And the new school admin gets access to the associated School Readiness page
#  Scenario 2: Previous school admin is an admin for another school
#    Given the previous school admin is an admin for another school
#    Then the previous school admin loses access to the associated school readiness page
#    And the previous school admin retains School Admin role
#    And the new school admin should have School Admin role
#    And the new school admin gets access to the associated School Readiness page

  Scenario Outline: Previous school admin is not an admin for another school
    Given I am logged in as a user with the "District Admin" role
    And users:
      | name            | mail               | pass   | field_first_name | field_last_name | status | roles                  |
      | Joe Educator    | <user_name>        | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
      | Second Educator | <second_user_name> | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
    And the user "<user_name>" should have a role of "School Admin"
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
      | title                    | field_ref_district          | field_contact_email | uid         |
      | School 944 S1 @timestamp | @nid[PRC-944 S1 @timestamp] | <user_name>         | @currentuid |
    Then "<user_name>" should not have an email
    And the user "<user_name>" should have a role of "School Admin"
    And I visit the last node created
    And I click "Edit"
    And I fill in "School contact's email address" with "<second_user_name>"
    And I press "Submit"
    Then the user "<second_user_name>" should have a role of "School Admin"
    And the user "<user_name>" should not have a role of "School Admin"
  Examples:
  | user_state     | member_state   | user_name                          | second_user_name                      |
  | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | second_prc_960b@timestamp@example.com |
