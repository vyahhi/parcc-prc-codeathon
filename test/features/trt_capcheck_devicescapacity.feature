@api @trt @capacity_check @prc-1071
Feature: PRC-1071 School Readiness - Devices capacity number
  As a School, District or State Admin,
  I want to see the devices capacity number associated with the passed/failed result
  so that I can understand the difference between the ready devices and the required devices.

  Acceptance Criteria
  Given that I am on a school's readiness page
  When I open my eyes
  Then I see:
  Differences from existing functionality
  Subhead: Devices Capacity Results
  <Devices capacity results> – <Devices Capacity>
  [that's an em dash separating results and number]
  [new content in green just to distinguish it in the story. Will be regular font color in pre-theming execution.]

  Scenario Outline: New devices capacity results
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
    And I click "<school_name>"
    Then I should see the text "Passed — 0"
  Examples:
    | user_state     | member_state | user_name                          | district_name         | school_name              |
    | South Virginia | Old York     | joe_prc_814a@timestamp@example.com | PRC-814 S1 @timestamp | School 814 S1 @timestamp |
