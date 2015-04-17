@api @trt @navigation @structured @prc-1285
Feature: PRC-815 Navigation - Breadcrumbs - PRC Admin
  As PRC Admin,
  I want to navigate backwards through the structured pages
  so that I can quickly run to a higher-level page.

  Given that I am a PRC Admin
  When I am on <page>
  Then I see <breadcrumbs>
  Given that I am a PRC Admin
  When I click on <breadcrumb>
  Then I see <page>
  PRC Admin on State Readiness page:
    PARCC Readiness (links to PARCC Readiness (PRC-1208))
  PRC Admin on District Readiness page:
    PARCC Readiness (links to PARCC Readiness (PRC-1208))
    <State Name> Readiness (links to State Readiness (PRC-707))
  PRC Admin on School Readiness page:
  PARCC Readiness (links to PARCC Readiness (PRC-1208))
    <State Name> Readiness (links to State Readiness (PRC-707))
    <District Name> Readiness (links to District Readiness - State Admin View (PRC-874))
  PRC Admin on a school's View System Check Results page (PRC-877)
    PARCC Readiness (links to PARCC Readiness (PRC-1208))
    <State Name> Readiness (links to State Readiness (PRC-707))
    <District Name> Readiness (links to System Check - Structured - View Results Page (PRC-803))
    <School Name> Readiness (links to School Readiness - District and State Admins View (PRC-814))

  Scenario Outline: PRC Admin on State Readiness page
    Given I am logged in as a user with the "State Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title                    | field_ref_district    | field_contact_email            | uid         |
      | School 944 S1 @timestamp | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And I am an anonymous user
    And I am logged in as a user with the "PRC Admin" role
    And I visit the first node created
    Then I should see the link "PARCC Readiness"
    When I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
    Then I should see the link "<member_state> Readiness"
    When I click "<member_state> Readiness"
    Then I should see the heading "<member_state> Readiness"
  Examples:
    | user_state    | member_state   | district_name       |
    | West Colorado | South Illinois | District @timestamp |

  Scenario Outline: PRC Admin on District Readiness page
    Given I am logged in as a user with the "State Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title                    | field_ref_district    | field_contact_email            | uid         |
      | School 944 S1 @timestamp | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And I am an anonymous user
    And I am logged in as a user with the "PRC Admin" role
    And I visit the first node created
    Then I should see the heading "<member_state> Readiness"
    When I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
    Then I should see the link "PARCC Readiness"
    Then I should see the link "<member_state> Readiness"
  Examples:
    | user_state    | member_state   | district_name       |
    | West Colorado | South Illinois | District @timestamp |

  Scenario Outline: PRC Admin on School Readiness page
    Given I am logged in as a user with the "State Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And I am an anonymous user
    And I am logged in as a user with the "PRC Admin" role
    And I visit the last node created
    Then I should see the heading "<school_name> Readiness"
    Then I should see the link "<member_state> Readiness"
    And I should see the link "<district_name> Readiness"
    When I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
    And I visit the last node created
    Then I should see the link "PARCC Readiness"
  Examples:
    | user_state    | member_state   | district_name       | school_name       |
    | West Colorado | South Illinois | District @timestamp | School @timestamp |

  Scenario Outline: PRC Admin on a school's View System Check Results page
    Given users:
      | name                   | mail                   | pass   | field_first_name | field_last_name | status | roles                 |
      | stateadmin@example.com | stateadmin@example.com | xyz123 | Joe              | Educator        | 1      | Educator, State Admin |
    Given I am logged in as "stateadmin@example.com"
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         | field_contact_email    |
      | <member_state> | <user_state>     | <member_state>     | @currentuid | stateadmin@example.com |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And the school "<school_name>" has run a system check
    And I am an anonymous user
    And I am logged in as a user with the "PRC Admin" role
    And I visit the last node created
    And I click "Fakey Check"
    Then I should see the link "PARCC Readiness"
    And I should see the link "<member_state> Readiness"
    And I should see the link "<district_name> Readiness"
    And I should see the link "<school_name> Readiness"
  Examples:
    | user_state    | member_state   | district_name       | school_name       |
    | West Colorado | South Illinois | District @timestamp | School @timestamp |
