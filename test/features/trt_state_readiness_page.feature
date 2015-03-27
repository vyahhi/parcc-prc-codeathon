@api @trt @state
Feature: PRC-707 State Readiness
  As a State Admin,
  I want to view my State Readiness page,
  so that I can access the results of readiness checks run by schools in my district.

#  Acceptance Criteria
#  Then I see my State Readiness page that has:
#  Common page elements
#  Page headline
#  <State Name> Readiness
#  Overview copy
#  Overview / instructional copy goes here (admin can export all test results data for state to csv or click district name to view results of technology checks by school).
#  Subhead
#  Districts
#  Scenario 1: No Districts Created
#  Copy
#  No districts in your state have been created
#  Scenario 2: At least one District Created
#  Export all system checks data to .csv [link]
#  Export all testing capacity checks data to .csv [link to the right of link to export system checks data]
#  <District Name> for each district display in alphabetical order under District subhead
#  Export all system checks data to .csv [link]
#  Export all testing capacity checks data to .csv [link to the right of link to export system checks data]
#  Note: [Lynn & Jack, adding note here, per what I understood from Jack. Let me know if there is a better treatment for this.]
#    When the district name is added (PRC-840), the district name appears on the associated State Readiness page
#    When the district name is edited (PRC-841), the updated name appears on the associated State Readiness page

  Scenario Outline: No Districts Created
    Given I am logged in as a user with the "State Admin" role
    And users:
      | name        | mail        | pass   | field_first_name | field_last_name | status | roles                 |
      | <user_name> | <user_name> | xyz123 | Joe              | Educator        | 1      | Educator, State Admin |
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid | field_contact_email |
      | <member_state> | <user_state>     | <member_state>     | 1   | <user_name>         |
    And I am an anonymous user
    And I am logged in as "<user_name>"
    And I click "Technology Readiness"
    Then I click "<member_state>"
    Then I should see the heading "<member_state> Readiness"

  Examples:
    | user_state     | member_state | user_name                          |
    | South Virginia | Old York     | joe_prc_941a@timestamp@example.com |
