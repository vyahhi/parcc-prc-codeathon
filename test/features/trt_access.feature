@api @trt @prc-1741 @javascript
Feature: PRC-1741 make sure that TRT pages are granting access correctly for all roles

  Scenario Outline: See feature description
    Given users:
      | name          | mail          | pass   | field_first_name | field_last_name | status | roles                    |
      | <user_name>   | <user_name>   | xyz123 | Joe              | Educator        | 1      | Educator, District Admin |
      | <state_admin> | <state_admin> | xyz123 | John             | Smith           | 1      | Educator, State Admin    |
      | <school_admin> | <school_admin> | xyz123 | Johan             | Smith           | 1      | Educator, School Admin |
    And I am logged in as "<user_name>"
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid | field_contact_email |
      | <member_state> | <user_state>     | <member_state>     | 1   | <state_admin>       |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title             | field_ref_district    | field_contact_email | uid         |
      | <school_name>     | @nid[<district_name>] | <user_name>         | @currentuid |
      | School Two Checks | @nid[<district_name>] | <school_admin>      | @currentuid |
    And the school "School Two Checks" has run a capacity check
    And the school "School Two Checks" has run a system check
    And I am an anonymous user
    And I visit "assessments/technology-readiness"
    And I visit the path "assessments/technology-readiness"
    And I should see the link "System Check"
    And I should see the link "Testing Capacity Check"
    And I should not see the link "PARCC Readiness"
    And I visit the path "district/@nid[<district_name>]/upload-schools"
    And I should see "Access Denied"
    And I visit "assessments/technology-readiness/parcc"
    And I should see "Access Denied"
    And I visit ""
    # state
    And I visit the path "node/@nid[<member_state>]"
    And I should see "Access Denied"
    # district
    And I visit the path "node/@nid[<district_name>]"
    And I should see "Access Denied"
    # Individual school information
    And I visit the path "node/@nid[School Two Checks]"
    And I should see "Access Denied"
    # Individual checks
    # Download system checks reports for the state
    And I visit ""
    And I visit the path "trt/system-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    # download system checks for the district
    And I visit ""
    And I visit the path "trt/system-check/export/district/@nid[<district_name>]"
    And I should see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/district/@nid[<district_name>]"
    And I should see "Access Denied"
    # can run unstructured tests, covered elsewhere

    # Basic authenticated user shouldn't have access either
    Given I am logged in as a user with the "Educator" role
    And I visit the path "assessments/technology-readiness"
    And I should see the link "System Check"
    And I should see the link "Testing Capacity Check"
    And I should not see the link "PARCC Readiness"
    And I visit the path "assessments/technology-readiness/parcc"
    And I should see "Access Denied"
    # state
    And I visit the path "node/@nid[<member_state>]"
    And I should see "Access Denied"
    # district
    And I visit the path "node/@nid[<district_name>]"
    And I should see "Access Denied"
    And I visit the path "district/@nid[<district_name>]/upload-schools"
    And I should see "Access Denied"
    # Individual school information
    And I visit the path "node/@nid[School Two Checks]"
    And I should see "Access Denied"

    # Download system checks reports for the state
    And I visit ""
    And I visit the path "trt/system-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    # can run unstructured tests, covered elsewhere

    # School admin
    Given I am logged in as "<school_admin>"
    And I visit the path "assessments/technology-readiness"
    And I should see the link "System Check"
    And I should see the link "Testing Capacity Check"
    And I should not see the link "PARCC Readiness"
    And I visit the path "assessments/technology-readiness/parcc"
    And I should see "Access Denied"
    # state
    And I visit the path "node/@nid[<member_state>]"
    And I should see "Access Denied"
    # district
    And I visit the path "node/@nid[<district_name>]"
    And I should see "Access Denied"
    And I visit the path "district/@nid[<district_name>]/upload-schools"
    And I should see "Access Denied"
    # Individual school information
    And I visit the path "node/@nid[School Two Checks]"
    And I should not see "Access Denied"
    And I should see the link "run testing capacity check"
    And I should see the link "run system check"
    # Individual
    And I click "Fakey Check"
    And I should not see "Access Denied"
    # Download system checks reports for the state
    And I visit ""
    And I visit the path "trt/system-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    # download system checks for the district
    And I visit ""
    And I visit the path "trt/system-check/export/district/@nid[<district_name>]"
    And I should see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/district/@nid[<district_name>]"
    And I should see "Access Denied"

    # District admin of district 1064
    Given I am logged in as "joe_prc_960a@timestamp@example.com"
    And I visit the path "assessments/technology-readiness"
    And I should see the link "System Check"
    And I should see the link "Testing Capacity Check"
    And I should not see the link "PARCC Readiness"
    And I visit the path "assessments/technology-readiness/parcc"
    And I should see "Access Denied"
    # state
    And I visit the path "node/@nid[<member_state>]"
    And I should see "Access Denied"
    # district
    And I visit the path "node/@nid[<district_name>]"
    And I should not see "Access Denied"
    And I visit the path "district/@nid[<district_name>]/upload-schools"
    And I should not see "Access Denied"
   # Individual school information
    And I visit the path "node/@nid[School Two Checks]"
    And I should not see "Access Denied"
    And I should not see the link "run testing capacity check"
    And I should not see the link "run system check"
    # Individual checks
    And I click "Fakey Check"
    And I should not see "Access Denied"
    # Download system checks reports for the state
    And I visit ""
    And I visit the path "trt/system-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    # download system checks for the district
    And I visit ""
    And I visit the path "trt/system-check/export/district/@nid[<district_name>]"
    And I should not see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/district/@nid[<district_name>]"
    And I should not see "Access Denied"

    # District admin of another district
    Given I am logged in as a user with the "District Admin" role
    And I visit the path "assessments/technology-readiness"
    And I should see the link "System Check"
    And I should see the link "Testing Capacity Check"
    And I should not see the link "PARCC Readiness"
    And I visit the path "assessments/technology-readiness/parcc"
    And I should see "Access Denied"
    # state
    And I visit the path "node/@nid[<member_state>]"
    And I should see "Access Denied"
    # district
    And I visit the path "node/@nid[<district_name>]"
    And I should see "Access Denied"
    And I visit the path "district/@nid[<district_name>]/upload-schools"
    And I should see "Access Denied"

    # Download system checks reports for the state
    And I visit ""
    And I visit the path "trt/system-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    # download system checks for the district
    And I visit ""
    And I visit the path "trt/system-check/export/district/@nid[<district_name>]"
    And I should see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/district/@nid[<district_name>]"
    And I should see "Access Denied"

    # State admin of Vermont Island
    Given I am logged in as "<state_admin>"
    And I visit the path "assessments/technology-readiness"
    And I should see the link "System Check"
    And I should see the link "Testing Capacity Check"
    # prc-1929 : no errors on unstructured test pages
    And I click "System Check"
    And I should not see the error message containing "Notice: Trying to get property of non-object"
    And I visit the path "assessments/technology-readiness"
    And I click "Testing Capacity Check"
    And I should not see the error message containing "Notice: Trying to get property of non-object"
    And I should not see the link "PARCC Readiness"
    And I visit the path "assessments/technology-readiness/parcc"
    And I should see "Access Denied"
    # state
    And I visit the path "node/@nid[<member_state>]"
    And I should not see "Access Denied"
    # district
    And I visit the path "node/@nid[<district_name>]"
    And I should not see "Access Denied"
    # Individual school information
    And I visit the path "node/@nid[School Two Checks]"
    And I should not see "Access Denied"
    And I visit the path "district/@nid[<district_name>]/upload-schools"
    And I should see "Access Denied"
    # Individual checks
    And I visit the path "node/@nid[School Two Checks]"
    And I should not see the link "run testing capacity check"
    And I should not see the link "run system check"
    # Individual
    And I click "Fakey Check"
    And I should not see "Access Denied"
    # And I should not see "Access Denied"
    # Download system checks reports for the state
    And I visit ""
    And I visit the path "trt/system-check/export/State/@nid[<member_state>]"
    And I should not see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/State/@nid[<member_state>]"
    And I should not see "Access Denied"
    # download system checks for the district
    And I visit ""
    And I visit the path "trt/system-check/export/district/@nid[<district_name>]"
    And I should not see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/district/@nid[<district_name>]"
    And I should not see "Access Denied"

    # State admin of another state
    Given I am logged in as a user with the "State Admin" role
    And I visit the path "assessments/technology-readiness"
    And I should see the link "System Check"
    And I should see the link "Testing Capacity Check"
    And I should not see the link "PARCC Readiness"
    And I visit the path "assessments/technology-readiness/parcc"
    And I should see "Access Denied"
    # state
    And I visit the path "node/@nid[<member_state>]"
    And I should see "Access Denied"
    # district
    And I visit the path "node/@nid[<district_name>]"
    And I should see "Access Denied"
    And I visit the path "district/@nid[<district_name>]/upload-schools"
    And I should see "Access Denied"
    # Individual school information
    And I visit the path "node/@nid[School Two Checks]"
    And I should see "Access Denied"
    # Individual checks

    # Download system checks reports for the state
    And I visit ""
    And I visit the path "trt/system-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/State/@nid[<member_state>]"
    And I should see "Access Denied"
    # download system checks for the district
    And I visit ""
    And I visit the path "trt/system-check/export/district/@nid[<district_name>]"
    And I should see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/district/@nid[<district_name>]"
    And I should see "Access Denied"

    # PRC Admin
    Given I am logged in as a user with the "PRC Admin" role
    # can export results
    And I visit ""
    And I visit the path "trt/system-check/export/State/@nid[<member_state>]"
    And I should not see "Access Denied"
    And I visit ""
    And I visit the path "trt/capacity-check/export/State/@nid[<member_state>]"
    And I should not see "Access Denied"
    # can view the landing pages for states and districts
    # state
    And I visit the path "node/@nid[<member_state>]"
    And I should not see "Access Denied"
    # district
    And I visit the path "node/@nid[<district_name>]"
    And I should not see "Access Denied"
    And I visit the path "district/@nid[<district_name>]/upload-schools"
    And I should see "Access Denied"
    # Individual school information
    And I visit the path "node/@nid[School Two Checks]"
    And I should not see "Access Denied"
    # prc admin cannot run structured sys/cap checks
    And I should not see the link "run testing capacity check"
    And I should not see the link "run system check"
    # Individual checks
    And I click "Fakey Check"
    And I should not see "Access Denied"

  Examples:
    | user_state     | member_state   | user_name                          | district_name            | school_name            | state_admin                        | school_admin |
    | North Virginia | Vermont Island | joe_prc_960a@timestamp@example.com | District 1064 @timestamp | School 1064 @timestamp | state_admin-@timestamp@example.com | school_admin-@timestamp@example.com |