@api @trt @district @schools @prc-1056
Feature: PRC-1056 Manage Schools - Filter
  As a District Admin,
  I want to filter schools by whether or not they have run readiness checks
  so that I can easily see which schools have run readiness checks and which haven't.

  Given that I am logged in as District Admin
  And I have at least one school in my district
  When I am on my Manage Schools page
  Then I see:
  Differences from existing functionality (see PRC-828)
  Label: Readiness Checks Run? [appears above schools table]
  Radio button: - Any -
  Radio button: Yes
  Radio button: No
  Button: Apply

  Scenario Outline: Filtering
    Given I am logged in as a user with the "District Admin" role
    And users:
      | name        | mail        | pass   | field_first_name | field_last_name | status | roles                    |
      | <user_name> | <user_name> | xyz123 | Joe              | Educator        | 1      | Educator, District Admin |
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
    And I am logged in as "<user_name>"
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email | uid         |
      | <school_name> | @nid[<district_name>] | <user_name>         | @currentuid |
      | School Two    | @nid[<district_name>] | <user_name>         | @currentuid |
    And the school "<school_name>" has run a capacity check
    And I click "Technology Readiness"
    And I click "<district_name>"
    And I click "Manage Schools"

    When I select the radio button "Yes"
    And I press "Apply"
    Then I should see the link "<school_name>"
    But I should not see the link "School Two"

    When I select the radio button "No"
    And I press "Apply"
    Then I should not see the link "<school_name>"
    But I should see the link "School Two"

    When I select the radio button "- Any -"
    And I press "Apply"
    Then I should see the link "<school_name>"
    And I should see the link "School Two"
  Examples:
    | user_state     | member_state   | user_name                          | district_name            | school_name            |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | District 1064 @timestamp | School 1064 @timestamp |
