@api @trt @system_check @district @export @prc-1070
Feature: PRC-1070 Export System Check Data - District Readiness
  As a District Admin,
  I want to export all system checks data for the schools in my district
  so that I can use the data to understand the schools' technology resources and needs.

  Given that I am logged in as a District Admin
  And I am on my District Readiness page
  When I click the Export all system checks data to csv link
  Then I see a csv file containing:
  Difference from Export System Check Data - State Readiness (PRC-1069)
  A row for each system check run by each school in my district in alphabetical order by district name, then in alphabetical order by school name then in reverse-chronological order by date and time system check was run.

  Scenario Outline: Export system checks
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
#    And the school "<school_name>" has run a system check
    And I click "Technology Readiness"
    Then I click "<member_state>"
    And I click "<district_name>"
  Examples:
    | user_state     | member_state | user_name                          | district_name         | school_name              |
    | South Virginia | Old York     | joe_prc_814a@timestamp@example.com | PRC-814 S1 @timestamp | School 814 S1 @timestamp |
