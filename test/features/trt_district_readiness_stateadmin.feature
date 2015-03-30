@api @trt @district @state @prc-874
Feature: PRC-874 District Readiness - State Admin View
  As a State Admin,
  I want to be able to see the results of the structured readiness checks run by schools in a district in my state I
  so that I can understand if the schools are ready to run PARCC assessment tests.

#  Acceptance Criteria
#  Background
#    Given I am logged in as a state admin
#    And I am on my State Readiness page
#    When I click the District Name link
#    Then I see the District Readiness page that has:
#  Differences from District Readiness - District Admin View (PRC-706)
#  Manage schools
#  No Edit district name link
#  No Manage schools link with explanatory copy: – add schools and request readiness checks

  Scenario Outline: State admin district readiness view
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
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
      | Other           | @currentuid | @nid[Another State]  |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And I click "Technology Readiness"
    And I click "<member_state>"
    And I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
    And I should not see the link "Edit district name"
    And I should not see the link "Manage Schools"
    And I should not see the text "add schools and request readiness checks"
  Examples:
    | user_state     | member_state | user_name                          | district_name         | school_name              |
    | South Virginia | Old York     | joe_prc_814a@timestamp@example.com | PRC-814 S1 @timestamp | School 814 S1 @timestamp |
