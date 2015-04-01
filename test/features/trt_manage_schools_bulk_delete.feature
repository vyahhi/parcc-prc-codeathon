@api @trt @school @vbo @prc-997
Feature: PRC-997 Manage Schools - Delete Schools - Select Schools
  As a District Admin,
  I want to delete schools that have not run readiness checks
  so that I can remove any misnamed or duplicate schools.

#  Given that I am logged in as District Admin
#  And I have at least one school in my district
#  When I am on my Manage Schools page
#  Then I can click check boxes to select and deselect schools
#  Use existing check box functionality (see PRC-817)
#  Differences from existing Manage Schools page:
#  Button: Delete Schools
  Scenario Outline: Button exists
    Given I am logged in as a user with the "District Admin" role
    And users:
      | name        | mail        | pass   | field_first_name | field_last_name | status | roles                    |
      | <user_name> | <user_name> | xyz123 | Joe              | Educator        | 1      | Educator, District Admin |
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
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And I am logged in as "<user_name>"
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email | uid         |
      | <school_name> | @nid[<district_name>] | <user_name>         | @currentuid |
    And I click "Technology Readiness"
    And I click "<district_name>"
    And I click "Manage Schools"
    Then I break
  Examples:
    | user_state     | member_state   | user_name                          | district_name            | school_name            |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | District 1064 @timestamp | School 1064 @timestamp |
