@api @trt @district @export @prc-875
Feature: PRC-875 Export Testing Capacity Data - State Readiness
  As a State Admin,
  I want to export testing capacity checks data for all the schools in my state that have run testing capacity checks
  so that I can use the data to understand the schools' technology resources and needs.

  Scenario Outline: Export capacity checks
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
    And the school "<school_name>" has run a capacity check
    And I click "Technology Readiness"
    Then I click "<member_state>"
    And I click "<district_name>"
    When I click "Export all testing capacity checks data to .csv"

    Then I should see CSV text matching "District"
    Then I should see CSV text matching "School"
    Then I should see CSV text matching "School Contact Email Address"
    Then I should see CSV text matching "Device Capacity"
    Then I should see CSV text matching "Device Capacity results"
    Then I should see CSV text matching "Bandwidth Capacity"
    Then I should see CSV text matching "Bandwidth Capacity results"
    Then I should see CSV text matching "Number of devices ready for assessment"
    Then I should see CSV text matching "Number of students"
    Then I should see CSV text matching "Number of days of testing"
    Then I should see CSV text matching "Number of test sessions per day"
    Then I should see CSV text matching "Number of sittings per student"
    Then I should see CSV text matching "Number of devices required"
    Then I should see CSV text matching "Speed of connection"
    Then I should see CSV text matching "Network Connection"
    Then I should see CSV text matching "Wired Connection Speed"
    Then I should see CSV text matching "Wireless Connection Speed"
    Then I should see CSV text matching "Number of Access Points"
#  If there is no readiness data for cell within a row of results, I see that cell displays an em-dash.

  Examples:
    | user_state     | member_state | user_name                          | district_name         | school_name              |
    | South Virginia | Old York     | joe_prc_814a@timestamp@example.com | PRC-814 S1 @timestamp | School 814 S1 @timestamp |
