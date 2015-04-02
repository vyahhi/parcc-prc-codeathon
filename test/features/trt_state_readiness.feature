@api @trt @state
Feature: PRC-941 Technology Readiness - State Admin View
  As a State Admin,
  I want to view the Technology Readiness page,
  so that I can learn about the readiness checks, run unstructured checks and access my state readiness page.

  Scenario Outline: State Admin on TRT page
    Given I am logged in as a user with the "District Admin" role
    And users:
      | name        | mail        | pass   | field_first_name | field_last_name | status | roles                 |
      | <user_name> | <user_name> | xyz123 | Joe              | Educator        | 1      | Educator, State Admin |
    And the user "<user_name>" should have a role of "State Admin"
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
    Then I should see the link "<member_state>"
    And I should see the text "Summary of what user can do here: export state readiness check data, view readiness by district, export district readiness checks data view school readiness data."
    And I take a screenshot
  Examples:
    | user_state     | member_state | user_name                          |
    | South Virginia | Old York     | joe_prc_941a@timestamp@example.com |

  Scenario Outline: State Admin can only see own states
    Given I am logged in as a user with the "District Admin" role
    And users:
      | name          | mail          | pass   | field_first_name | field_last_name | status | roles                 |
      | <user_name>   | <user_name>   | xyz123 | Joe              | Educator        | 1      | Educator, State Admin |
      | <second_user> | <second_user> | xyz123 | Joe              | Educator        | 1      | Educator, State Admin |
    And the user "<user_name>" should have a role of "State Admin"
    And "User States" terms:
      | name           |
      | <member_state> |
      | <user_state>   |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
      | <user_state>   | RHI1             |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid | field_contact_email |
      | <member_state> | <member_state>   | <member_state>     | 1   | <user_name>         |
      | <user_state>   | <user_state>     | <user_state>       | 1   | <second_user>       |
    And I am an anonymous user
    And I am logged in as "<user_name>"
    And I click "Technology Readiness"
    Then I should see the link "<member_state>"
    And I should not see the link "<user_state>"
    And I am an anonymous user
    And I am logged in as "<second_user>"
    And I click "Technology Readiness"
    Then I should not see the link "<member_state>"
    And I should see the link "<user_state>"
  Examples:
    | user_state     | member_state | user_name                          | second_user                  |
    | South Virginia | Old York     | joe_prc_941a@timestamp@example.com | second@timestamp@example.com |
