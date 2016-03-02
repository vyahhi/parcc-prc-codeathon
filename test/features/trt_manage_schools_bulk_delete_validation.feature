@api @trt @school @vbo @prc-1057
Feature: PRC-1057 Manage Schools - Delete Schools - Select Schools - Form Validation
  As a District Admin,
  I want to get feedback about any errors that occur when I delete schools
  so that I can fix errors and delete the appropriate schools.

#  Then I see the error messages:
#  Issue	Error message
#  No school selected	Please select at least one item
#  At least one school with readiness checks data selected	Only schools that haven't run readiness checks can be deleted. (This message will appear on another page.)

  Scenario Outline: School has already run a check
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
    And the school "<school_name>" has run a capacity check
    And I visit "assessments/technology-readiness"
    And I click "<district_name>"
    And I click "Manage Schools"
    And I check the box "edit-views-bulk-operations-0"
    When I press "Delete Schools"
    Then I should see the error message containing "Only schools that haven't run readiness checks can be deleted."
  Examples:
    | user_state     | member_state   | user_name                          | district_name            | school_name            |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | District 1064 @timestamp | School 1064 @timestamp |

  Scenario Outline: No school selected
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
    And the school "<school_name>" has run a capacity check
    And I visit "assessments/technology-readiness"
    And I click "<district_name>"
    And I click "Manage Schools"
    When I press "Delete Schools"
    Then I should see the error message containing "Please select at least one item"
  Examples:
    | user_state     | member_state   | user_name                          | district_name            | school_name            |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | District 1064 @timestamp | School 1064 @timestamp |

  Scenario Outline: School has not run a check
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
    And I check the box "edit-views-bulk-operations-0"
    When I press "Delete Schools"
    Then I should see the text "You selected the following item"
    And I should see the text "<school_name>"
    And I press "Confirm"
    Then I follow meta refresh
    Then I should not see the error message containing "Only schools that haven't run readiness checks can be deleted."
    But I should see the message containing "Performed Delete Schools on 1 item."
  Examples:
    | user_state     | member_state   | user_name                          | district_name            | school_name            |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | District 1064 @timestamp | School 1064 @timestamp |
