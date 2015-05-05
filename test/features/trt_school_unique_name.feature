@api @trt @school @district
Feature: PRC-996 Manage Schools - Add/Edit School - Form - Validation - Name can't match existing school
  As a District Admin, I want to see any errors if I am unsuccessful in adding a school so I can fix my mistakes and add the school.
  Acceptance Criteria
#  Given that I am logged in as a District Admin
#  And I am on my Add School or my Edit School page
#  And I have no invalid fields
#  When I click the Submit button
#  Then I see the following errors:
#  Differences from Manage Schools - Add/Edit School - Form - Validation (PRC-850)
#  Fields and error messages
#  Field Label	Type	Required?	Issue	Error message
#  School name *	Text field	Yes	School Name submitted contains the exact characters (not case sensitive) and spacing in the exact order as another existing school in the same district. Ignore leading and trailing spaces.	The school name is being used by another school in your district. Please enter a different school name.

  Scenario Outline: School name must be unique inside district
    Given I am logged in as a user with the "District Admin" role
    And users:
      | name            | mail               | pass   | field_first_name | field_last_name | status | roles                  |
      | Joe Educator    | <user_name>        | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
      | Second Educator | <second_user_name> | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
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
      | title                 | uid         | field_ref_trt_state  |
      | PRC-996 D1 @timestamp | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title                    | field_ref_district          | field_contact_email | uid         |
      | School 996 S1 @timestamp | @nid[PRC-996 D1 @timestamp] | <user_name>         | @currentuid |
    And I visit "technology-readiness"
    And I click "PRC-996 D1 @timestamp"
    And I click "Manage Schools"
    And I click "Add School - form"
    And I fill in "School name" with "School 996 S1 @timestamp"
    And I fill in "School contact's email address" with "<user_name>"
    When I press "Submit"
    Then I should see the error message containing "The school name is being used by another school in your district. Please enter a different school name."
  Examples:
    | user_state     | member_state   | user_name                          | second_user_name                      |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | second_prc_960b@timestamp@example.com |

  Scenario Outline: School name matches a name in another district
    Given I am logged in as a user with the "District Admin" role
    And users:
      | name            | mail               | pass   | field_first_name | field_last_name | status | roles                  |
      | Joe Educator    | <user_name>        | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
      | Second Educator | <second_user_name> | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
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
      | title                 | uid         | field_ref_trt_state  |
      | PRC-996 D1 @timestamp | @currentuid | @nid[<member_state>] |
      | PRC-996 D2 @timestamp | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title                    | field_ref_district          | field_contact_email | uid         |
      | School 996 S1 @timestamp | @nid[PRC-996 D2 @timestamp] | <user_name>         | @currentuid |
    And I visit "technology-readiness"
    And I click "PRC-996 D1 @timestamp"
    And I click "Manage Schools"
    And I click "Add School - form"
    And I fill in "School name" with "School 996 S1 @timestamp"
    And I fill in "School contact's email address" with "<user_name>"
    When I press "Submit"
    Then I should not see the error message containing "The school name is being used by another school in your district. Please enter a different school name."
  Examples:
    | user_state     | member_state   | user_name                          | second_user_name                      |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | second_prc_960b@timestamp@example.com |

  Scenario Outline: PRC-1172 Trailing/leading spaces
    Given I am logged in as a user with the "District Admin" role
    And users:
      | name            | mail               | pass   | field_first_name | field_last_name | status | roles                  |
      | Joe Educator    | <user_name>        | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
      | Second Educator | <second_user_name> | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
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
      | title                 | uid         | field_ref_trt_state  |
      | PRC-996 D1 @timestamp | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title                    | field_ref_district          | field_contact_email | uid         |
      | School 996 S1 @timestamp | @nid[PRC-996 D1 @timestamp] | <user_name>         | @currentuid |
    And I visit "technology-readiness"
    And I click "PRC-996 D1 @timestamp"
    And I click "Manage Schools"
    And I click "School 996 S1 @timestamp"
    And I fill in "School name" with "  School 996 S1 @timestamp  "
    And I press "Submit"
    And I click "Add School - form"
    And I fill in "School name" with "School 996 S1 @timestamp"
    And I fill in "School contact's email address" with "<user_name>"
    When I press "Submit"
    Then I should see the error message containing "The school name is being used by another school in your district. Please enter a different school name."
  Examples:
    | user_state     | member_state   | user_name                          | second_user_name                      |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | second_prc_960b@timestamp@example.com |

  Scenario Outline: PRC-1172 Trailing/leading spaces - Contains but without spaces
    Given I am logged in as a user with the "District Admin" role
    And users:
      | name            | mail               | pass   | field_first_name | field_last_name | status | roles                  |
      | Joe Educator    | <user_name>        | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
      | Second Educator | <second_user_name> | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
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
      | title                 | uid         | field_ref_trt_state  |
      | PRC-996 D1 @timestamp | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title                    | field_ref_district          | field_contact_email | uid         |
      | School 996 S1 @timestamp | @nid[PRC-996 D1 @timestamp] | <user_name>         | @currentuid |
    And I visit "technology-readiness"
    And I click "PRC-996 D1 @timestamp"
    And I click "Manage Schools"
    And I click "Add School - form"
    And I fill in "School name" with "996"
    And I fill in "School contact's email address" with "<user_name>"
    When I press "Submit"
    Then I should not see the error message containing "The school name is being used by another school in your district. Please enter a different school name."
  Examples:
    | user_state     | member_state   | user_name                          | second_user_name                      |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | second_prc_960b@timestamp@example.com |