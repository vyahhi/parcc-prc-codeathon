@api @trt @district @state @prc-1210
Feature: PRC-1210 District Readiness - PRC Admin View
  As a PRC Admin,
  I want to be able to see the results of the structured readiness checks run by schools in a district in a given state I
  so that I can understand if the schools are ready to run PARCC assessment tests.

#  Background
#    Given I am logged in as a PRC Admin
#    And I am on a State Readiness page
#    When I click a District Name link
#    Then I see the District Readiness page that has:
#  Differences from District Readiness - State Admin View (PRC-874)
#  None
#  Note: Only districts that have been created appear on the State Readiness page.

  Scenario Outline: State admin district readiness view
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "State" nodes
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
      | title           | uid | field_ref_trt_state  |
      | <district_name> | 1   | @nid[<member_state>] |
      | Other           | 1   | @nid[Another State]  |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | 1   |
    When I click "Technology Readiness"
    Then I should not see the link "<member_state> Readiness"
    And I should not see the link "<district_name> Readiness"
    When I click "PARCC Readiness"
    And I click "<member_state>"
    And I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
    And I should not see the link "Edit district name"
    And I should not see the link "Manage Schools"
    And I should not see the text "add schools and request readiness checks"
  Examples:
    | user_state     | member_state | user_name                           | district_name          | school_name               |
    | South Virginia | Old York     | joe_prc_1210a@timestamp@example.com | PRC-1210 S1 @timestamp | School 1210 S1 @timestamp |
