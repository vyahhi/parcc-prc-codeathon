@api @trt @school @delete @prc-1064 @prc-1061 @prc-1062 @prc-1219
Feature: PRC-1064 Manage Schools - Edit School - Delete button
  As a District Admin,
  I want to delete a school that has not run readiness checks
  so that I can remove any misnamed or duplicate schools.

  PRC-1061 - Delete confirm
  PRC-1062 - School deleted
#  Acceptance Criteria
#  Given that I am logged in as District Admin
#  When I click the name of a school that has no readiness checks results
#  Then I see the Edit School page with:
#  Differences from existing Edit School page:
#  Button: Delete Schools [to the right of the Submit button]
  Scenario Outline: Delete school
    Given users:
      | name        | mail        | pass   | field_first_name | field_last_name | status | roles                    |
      | <user_name> | <user_name> | xyz123 | Joe              | Educator        | 1      | Educator, District Admin |
    And I am logged in as "<user_name>"
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
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email | uid         |
      | <school_name> | @nid[<district_name>] | <user_name>         | @currentuid |
    And I visit "assessments/technology-readiness"
    And I click "<district_name>"
    And I click "Manage Schools"
    When I click "<school_name>"
    Then I should see a "Delete" button
    # PRC-1061
    When I press "Delete"
    Then I should see the heading "Are you sure you want to delete <school_name>?"
    Then I should see the text "This action cannot be undone."
    And I should see a "Delete" button
    And I should see the link "Cancel"
    # PRC-1062
    When I press "Delete"
    Then I should see the message containing "School <school_name> has been deleted."
    And I should see the heading "Manage Schools"
  Examples:
    | user_state     | member_state   | user_name                          | district_name            | school_name            |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | District 1064 @timestamp | School 1064 @timestamp |

  Scenario Outline: PRC-1219 Can't delete school with readiness check
    Given users:
      | name        | mail        | pass   | field_first_name | field_last_name | status | roles                    |
      | <user_name> | <user_name> | xyz123 | Joe              | Educator        | 1      | Educator, District Admin |
    And I am logged in as "<user_name>"
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
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email | uid         |
      | <school_name> | @nid[<district_name>] | <user_name>         | @currentuid |
    And the school "<school_name>" has run a system check
    And I visit "assessments/technology-readiness"
    And I click "<district_name>"
    And I click "Manage Schools"
    When I click "<school_name>"
    Then I should not see the button "Delete"
  Examples:
    | user_state     | member_state   | user_name                          | district_name            | school_name            |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | District 1064 @timestamp | School 1064 @timestamp |
