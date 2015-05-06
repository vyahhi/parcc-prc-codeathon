@api @district @admin @trt @prc-706 @prc-878
Feature: PRC-706 District Readiness - District Admin View
  As a District Admin,
  I want to be able to see the results of the structured readiness checks run by schools in my district I
  so that I can understand if the schools are ready to run PARCC assessment tests.

  PRC-878 District Readiness - sort school list
  As a School, District or State Admin, I want to sort the list of schools on my District Readiness page so that I can find the information that I want.

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
    And I visit "technology-readiness"
    And I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
    And I should see the text "Overview / instructional copy goes here \(admin can export all test results data for district to csv or click school name to view results of technology checks for school\). Note only schools that have run structured readiness checks display on this page."
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
    And I visit "technology-readiness"
    And I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
    And I should see the text "<school_name>"
    And I should see the text "No. of Students"
    And I should see the text "Devices Capacity"
    And I should see the text "Devices Capacity Results"
    And I should see the text "Bandwidth Capacity"
    And I should see the text "Bandwidth Capacity Results"
    And I should see the text "-" in the "<school_name>" row
    And I should see the link "Export all system checks data to .csv"
    And I should see the link "Export all testing capacity checks data to .csv"
  Examples:
    | user_name                          | district_name         | school_name              |
    | joe_prc_706a@timestamp@example.com | PRC-706 S1 @timestamp | School 706 S1 @timestamp |



  Scenario Outline: 4 - At least one school in my district has run structured testing capacity check
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
    And the school "<school_name>" has run a capacity check
    And I visit "technology-readiness"
    And I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
    And I should see the text "<school_name>"
    And I should see the text "No. of Students"
    And I should see the text "Devices Capacity"
    And I should see the text "Devices Capacity Results"
    And I should see the text "Bandwidth Capacity"
    And I should see the text "Bandwidth Capacity Results"
    And I should see the text "10" in the "<school_name>" row
    And I should see the link "Export all system checks data to .csv"
    And I should see the link "Export all testing capacity checks data to .csv"

    # PRC-878 Sorts these results
    And I should see the link "School Name"
    And I should see the link "No. of Students"
    And I should see the link "Devices Capacity"
    And I should see the link "Devices Capacity Results"
    And I should see the link "Bandwidth Capacity"
    And I should see the link "Bandwidth Capacity Results"

  Examples:
    | user_name                          | district_name         | school_name              |
    | joe_prc_706a@timestamp@example.com | PRC-706 S1 @timestamp | School 706 S1 @timestamp |
