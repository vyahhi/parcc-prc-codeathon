@api @district @admin @trt @prc-706
Feature: PRC-706 District Readiness - District Admin View
  As a District Admin,
  I want to be able to see the results of the structured readiness checks run by schools in my district I
  so that I can understand if the schools are ready to run PARCC assessment tests.
#
#  Acceptance Criteria
#  Background
#    Given I am logged in as a district admin
#    When I am on my District Readiness page
#    Then I see:
#  Scenario 1: Common page elements
#  Overview copy
#  Overview / instructional copy goes here (admin can export all test results data for district to csv or click school name to view results of technology checks for school). Note only schools that have run structured readiness checks display on this page.
#  Scenario 2: No schools in my district have run structured readiness checks
#  No change from Scenario 1
#  Scenario 3: At least one school in my district has run a structured system check but not a structured testing capacity check
#  Export all system checks data to .csv [link]
#  Export all testing capacity checks data to .csv [link to the right of link to export system checks data]
#  Schools table
#  School Name	No. of Students	Devices Capacity	Devices Capacity Results	Bandwidth Capacity	Bandwidth Capacity Results
#  <School Name> (link)	– [em dash]	– [em dash]	– [em dash]	– [em dash]	– [em dash]
#  Export all system checks data to .csv [link]
#  Export all testing capacity checks data to .csv [link to the right of link to export system checks data]
#  Scenario 4: At least one school in my district has run structured testing capacity check
#  Export all system checks data to .csv [link]
#  Export all testing capacity checks data to .csv [link to the right of link to export system checks data]
#  Schools table
#  School Name	No. of Students	Devices Capacity	Devices Capacity Results	Bandwidth Capacity	Bandwidth Capacity Results
#  <School Name>(link)	<number of students>	<devices capacity>	<Devices capacity results>	<bandwidth capacity>	<Bandwidth capacity results>
#  Export all system checks data to .csv [link]
#  Export all testing capacity checks data to .csv [link to the right of link to export system checks data]

  Scenario Outline: No schools have run checks
    Given users:
      | name        | mail        | pass   | field_first_name | field_last_name | status | roles                    |
      | <user_name> | <user_name> | xyz123 | Joe              | Educator        | 1      | Educator, District Admin |
    And I am logged in as "<user_name>"
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title         | field_ref_district          | field_contact_email            | uid         |
      | <school_name> | @nid[PRC-944 S1 @timestamp] | example1@timestamp@example.com | @currentuid |
    And I click "Technology Readiness"
    And I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
#    And I should see the text "Overview / instructional copy goes here \(admin can export all test results data for district to csv or click school name to view results of technology checks for school\). Note only schools that have run structured readiness checks display on this page."
    And I should see the link "Edit district name"
    And I should see the link "Manage Schools"
    And I should see the text "add schools and request readiness checks"
  Examples:
    | member_state | user_name                          | district_name         | school_name              |
    | Old York     | joe_prc_706a@timestamp@example.com | PRC-706 S1 @timestamp | School 706 S1 @timestamp |

  Scenario Outline: 3 - School has run system check but not capacity check
    Given users:
      | name        | mail        | pass   | field_first_name | field_last_name | status | roles                    |
      | <user_name> | <user_name> | xyz123 | Joe              | Educator        | 1      | Educator, District Admin |
    And I am logged in as "<user_name>"
    And "District" nodes:
      | title           | uid         |
      | <district_name> | @currentuid |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And the school "<school_name>" has run a system check
    And I click "Technology Readiness"
    And I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
    And I should see the text "<school_name>"
    And I should see the text "No. of Students"
    And I should see the text "Devices Capacity"
    And I should see the text "Devices Capacity Results"
    And I should see the text "Bandwidth Capacity"
    And I should see the text "Bandwidth Capacity Results"
    And I should see the text "—"
  Examples:
    | user_name                          | district_name         | school_name              |
    | joe_prc_706a@timestamp@example.com | PRC-706 S1 @timestamp | School 706 S1 @timestamp |
