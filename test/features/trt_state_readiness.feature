@api @trt @state
Feature: PRC-941 Technology Readiness - State Admin View
  As a State Admin,
  I want to view the Technology Readiness page,
  so that I can learn about the readiness checks, run unstructured checks and access my state readiness page.

  Scenario Outline: State Admin on TRT page with a state
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
    And I visit "assessments/technology-readiness"
    Then I should see the link "<member_state>"
    And I should see the text "Click the link above to access and manage state data and readiness reports. State admins can access and download district and school reports."
    And I should see the text "For more information on the TRT, please refer to the online tutorial found in the professional learning section of this site."
    And I should see the text "Each year, after July 31, but before August 15, the checks and reports in this system will be retired and not accessible to users. Please download your reports for your archives before July 31 of each year."
    And I should not see the text "Summary of what user can do here view readiness by school, run readiness checks, view readiness check results."

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
    And I visit "assessments/technology-readiness"
    Then I should see the link "<member_state>"
    And I should not see the link "<user_state>"
    And I am an anonymous user
    And I am logged in as "<second_user>"
    And I visit "assessments/technology-readiness"
    Then I should not see the link "<member_state>"
    And I should see the link "<user_state>"
  Examples:
    | user_state     | member_state | user_name                          | second_user                  |
    | South Virginia | Old York     | joe_prc_941a@timestamp@example.com | second@timestamp@example.com |

    Scenario: State Admin on TRT page without a state
      When I am logged in as a user with the "State Admin" role
      And I visit "assessments/technology-readiness"
      Then I should see "No states have been created"
      And I should see an ".view-id-trt_states" element
      And I should not see "Click the link above to access and manage state data and readiness reports. State admins can access and download district and school reports." in the ".view-id-trt_states" element
      And I should not see "For more information on the TRT, please refer to the online tutorial found in the professional learning section of this site." in the ".view-id-trt_states" element
      And I should not see "Each year, after July 31, but before August 15, the checks and reports in this system will be retired and not accessible to users. Please download your reports for your archives before July 31 of each year." in the ".view-id-trt_states" element