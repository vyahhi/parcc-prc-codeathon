@api @trt @structured @district @prc-838 @prc-995 @prc-940
Feature: PRC-838 District Name - Edit Form
  As a District Admin, I want to be able to edit my district name so I can make any corrections to my district name.

  Acceptance Criteria
#  Given that I am logged in as a District Admin
#  And I am on my District Readiness page
#  When I click the Edit district name link
  Then I see the Edit District name page that has:
  Differences from Add District (PRC-837):
  Page header
  Edit District
  Form fields
  Text field prepopulated with previously submitted district name

  Scenario: Add new district - District Admin
    Given I am logged in as a user with the "District Admin" role
    And I have no "District" nodes
    And I visit "assessments/technology-readiness"
    When I click "Add District"
    And I fill in "District Name" with "PRC-838 @timestamp"
    And I press "Submit"
    Then I should see the text "PRC-838 @timestamp Readiness"
    When I click "Edit district name"
    Then I should see the heading "Edit District"
    And the "District Name" field should contain "PRC-838 @timestamp"
    When I fill in "District Name" with "PRC-838 @timestamp New Text"
    And I press "Submit"
    # PRC-841
    Then I should see the text "PRC-838 @timestamp New Text Readiness"

  Scenario: PRC-1034 - Edit other
    Given I am logged in as a user with the "District Admin" role
    And I have no "District" nodes
    And I visit "assessments/technology-readiness"
    When I click "Add District"
    And I fill in "District Name" with "PRC-1034 @timestamp"
    And I press "Submit"
    Then I should see the text "PRC-1034 @timestamp Readiness"
    Then I am an anonymous user
    And I am logged in as a user with the "District Admin" role
    And I visit "assessments/technology-readiness"
    Then I should not see the link "PRC-1034 @timestamp"

  Scenario Outline: PRC-995 - District name must be unique in state
    Given users:
      | name        | mail                         | pass   | field_first_name | field_last_name | status | roles                    |
      | <user_name> | <user_name>                  | xyz123 | Joe              | Educator        | 1      | Educator, District Admin |
      | second@timestamp@example.com | second@timestamp@example.com | xyz123 | Joey             | Admin           | 1      | Educator, District Admin |
    And I am logged in as "second@timestamp@example.com"
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title            | field_user_state | field_member_state | uid |
      | 1 <member_state> | <user_state>     | <member_state>     | 1   |
      | 2 <member_state> | <user_state>     | <member_state>     | 1   |
    And "District" nodes:
      | title                 | uid         | field_ref_trt_state    |
      | PRC-996 D1 @timestamp | @currentuid | @nid[1 <member_state>] |
      | PRC-996 D2 @timestamp | @currentuid | @nid[2 <member_state>] |
    # PRC-940 changed District Admins. Now only allowed to have one district, so this link is hidden for the user who owns those other districts.
    And I am logged in as "<user_name>"
    And I visit "assessments/technology-readiness"
    And I click "Add District"
    And I fill in "District Name" with "PRC-996 D1 @timestamp"
    And I select "1 <member_state>" from "State"
    When I press "Submit"
    Then I should see the error message containing "The district name is being used by another district in your state. Please enter a different district name."
  Examples:
    | user_state     | member_state   | user_name                          | second_user_name                      |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | second_prc_960b@timestamp@example.com |