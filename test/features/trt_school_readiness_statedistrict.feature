@api @trt @school @state @district @admin @prc-814
Feature: PRC-814 School Readiness - District and State Admins View
  As a District Admin or State Admin,
  I want to be able to view the results of school's readiness checks
  so that I can understand if the school is ready to run a PARCC assessment test.

#  Acceptance Criteria
#  Background
#  Differences from School Readiness - School Admin View (PRC-757)
#  School Contact (below page header)
#  School Contact: <School contact's email address>
#  Testing capacity checks
#  No link to run or run again
#  System checks
#  No link to run system check

  Scenario Outline: State or District Admin
    Given users:
      | name        | mail        | pass   | field_first_name | field_last_name | status | roles                 |
      | <user_name> | <user_name> | xyz123 | Joe              | Educator        | 1      | Educator, State Admin |
    And I am logged in as "<user_name>"
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid | field_contact_email |
      | <member_state> | <user_state>     | <member_state>     | 1   | <user_name>         |
      | Another State  | <user_state>     | <member_state>     | 1   | <user_name>         |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
      | Other           | @currentuid | @nid[Another State]  |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And the school "<school_name>" has run a system check
    And I visit "assessments/technology-readiness"
    Then I click "<member_state>"
    And I click "<district_name>"
    And I click "<school_name>"
    Then I should see the heading "<school_name> Readiness"
    But I should not see the link "run testing capacity check"
    And I should not see the link "run system check"
    And I should see the text "School Contact: example1@timestamp@example.com"
  Examples:
    | user_state     | member_state | user_name                          | district_name         | school_name              |
    | South Virginia | Old York     | joe_prc_814a@timestamp@example.com | PRC-814 S1 @timestamp | School 814 S1 @timestamp |
