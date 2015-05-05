@api @trt @system_check @district @export @prc-1070
Feature: PRC-1070 Export System Check Data - District Readiness
  As a District Admin,
  I want to export all system checks data for the schools in my district
  so that I can use the data to understand the schools' technology resources and needs.

#  A row for each system check run by each school in my district in alphabetical order by district name, then in alphabetical order by school name then in reverse-chronological order by date and time system check was run.

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
    And the school "<school_name>" has run a system check
    And I visit "technology-readiness"
    Then I click "<member_state>"
    And I click "<district_name>"
    When I click "Export all system checks data to .csv"
    Then I should see CSV text matching "District"
    Then I should see CSV text matching "School"
    Then I should see CSV text matching "School Contact Email Address"
    Then I should see CSV text matching "System Check Name"
    Then I should see CSV text matching "Date & Time System Check Run"
    Then I should see CSV text matching "Number of Devices in system check"
    Then I should see CSV text matching "System Check Results"
    Then I should see CSV text matching "Device Type"
    Then I should see CSV text matching "Operating System name"
    Then I should see CSV text matching "Operating System results"
    Then I should see CSV text matching "Monitor Size"
    Then I should see CSV text matching "Monitor Size results"
    Then I should see CSV text matching "Monitor color depth"
    Then I should see CSV text matching "Monitor color depth results"
    Then I should see CSV text matching "Screen resolution"
    Then I should see CSV text matching "Screen resolution results"
    Then I should see CSV text matching "Processor speed"
    Then I should see CSV text matching "Processor speed results"
    Then I should see CSV text matching "RAM"
    Then I should see CSV text matching "RAM results"
    Then I should see CSV text matching "Browser name"
    Then I should see CSV text matching "Browser results"
    Then I should see CSV text matching "Cookies enabled"
    Then I should see CSV text matching "Cookies enabled results"
    Then I should see CSV text matching "JavaScript enabled"
    Then I should see CSV text matching "JavaScript enabled results"
    Then I should see CSV text matching "Images enabled"
    Then I should see CSV text matching "Images enabled results"
    Then I should see CSV text matching "Java plugin version"
    Then I should see CSV text matching "Java plugin results"
  Examples:
    | user_state     | member_state | user_name                          | district_name         | school_name              |
    | South Virginia | Old York     | joe_prc_814a@timestamp@example.com | PRC-814 S1 @timestamp | School 814 S1 @timestamp |
