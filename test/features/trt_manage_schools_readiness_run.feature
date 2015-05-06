@api @trt @district @prc-1055
Feature: PRC-1055 Manage Schools - Indicate if readiness checks run
  As a District Admin, I want to see if schools have run readiness checks so that I can know if the schools have run readiness checks and then request readiness checks or delete empty schools, if that's what I want to do.

#  Given that I am logged in as District Admin
#  And I have at least one school in my district
#  When I am on my Manage Schools page
#  Then I see:
#  Differences from existing functionality (see PRC-828)
#  Schools Table
#  Table displaying schools in alphabetical order with a row for each added school now with column indicating if readiness checks have been run. "Yes" displays if school has successfully run at least one readiness check (either system check or capacity check).
#  <checkbox>	School Name	School Contact Email Address	Readiness Checks Run?
#  <checkbox>	<School Name>	<School Contact's Email Addresss>	<Yes or No>

  Scenario Outline: Readiness checks run?
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
      | title             | field_ref_district    | field_contact_email | uid         |
      | <school_name>     | @nid[<district_name>] | <user_name>         | @currentuid |
      | School Two Checks | @nid[<district_name>] | <user_name>         | @currentuid |
    And the school "School Two Checks" has run a capacity check
    And the school "School Two Checks" has run a system check
    And I visit "technology-readiness"
    And I click "<district_name>"
    And I click "Manage Schools"
    Then I should see the text "Readiness Checks Run?"
    And I should see the text "Yes" in the "School Two Checks" row
    And I should see the text "No" in the "<school_name>" row
  Examples:
    | user_state     | member_state   | user_name                          | district_name            | school_name            |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | District 1064 @timestamp | School 1064 @timestamp |
