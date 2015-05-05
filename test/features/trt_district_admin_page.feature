@api @trt @district @prc-940 @structured @prc-1242
Feature: PRC-940 Technology Readiness - District Admin View
  As a District Admin,
  I want to view the Technology Readiness page,
  so that I can learn about the readiness checks, run unstructured checks, add my district name and access my district readiness page.

#  Acceptance Criteria
#  Given that I am logged in as a District Admin
#  When I click the Technology Readiness tab
#  Then I see the Technology Readiness page that has:
#  Differences from Technology Readiness (PRC-836)
#  Scenario 1: My district does not exist
#  Subhead, linked
#  Add District Name
#  Copy
#  Instructions to District Admin to add district, which will allow results generate by School Admin to be reported to the district.
#  Scenario 2: My district exists
#  Subhead, linked
#  <District Name> Readiness [for my district only]
#  Copy
#  Summary of what user can do here: add schools, request school admins to run checks, view readiness by schools in district.

  Scenario: I am not a district administrator
    Given users:
      | name                         | mail                         | pass   | field_first_name | field_last_name | status |
      | prc940@timestamp@example.com | prc940@timestamp@example.com | xyz123 | District         | Administrator   | 1      |
    And I am logged in as "prc940@timestamp@example.com"
    When I visit "technology-readiness"
    Then I should not see the link "Add District"
    And I should not see the text "Instructions to District Admin to add district, which will allow results generate by School Admin to be reported to the district."

  Scenario: 1 - My district does not exist
    Given users:
      | name                         | mail                         | pass   | field_first_name | field_last_name | status | roles                    |
      | prc940@timestamp@example.com | prc940@timestamp@example.com | xyz123 | District         | Administrator   | 1      | Educator, District Admin |
    And I am logged in as "prc940@timestamp@example.com"
    When I visit "technology-readiness"
    Then I should see the link "Add District"
    And I should see the text "Instructions to District Admin to add district, which will allow results generate by School Admin to be reported to the district."
    And I should not see the text "Summary of what user can do here: add schools, request school admins to run checks, view readiness by schools in district."

  Scenario: 2 - I have a district (PRC-1242)
    Given users:
      | name                         | mail                         | pass   | field_first_name | field_last_name | status | roles                    |
      | prc940@timestamp@example.com | prc940@timestamp@example.com | xyz123 | District         | Administrator   | 1      | Educator, District Admin |
    And I am logged in as "prc940@timestamp@example.com"
    And "District" nodes:
      | title                 | uid         |
      | PRC-944 S1 @timestamp | @currentuid |
    When I visit "technology-readiness"
    Then I should not see the link "Add District"
    And I should not see the text "Instructions to District Admin to add district, which will allow results generate by School Admin to be reported to the district."
    But I should see the link "PRC-944 S1 @timestamp"
    And I should see the text "Summary of what user can do here: add schools, request school admins to run checks, view readiness by schools in district."

  Scenario: I can only see my own districts
    Given users:
      | name                         | mail                         | pass   | field_first_name | field_last_name | status | roles                    |
      | prc940@timestamp@example.com | prc940@timestamp@example.com | xyz123 | District         | Administrator   | 1      | Educator, District Admin |
    And I am logged in as "prc940@timestamp@example.com"
    And "District" nodes:
      | title            | uid         |
      | Mine @timestamp  | @currentuid |
      | Yours @timestamp | 1           |
    When I visit "technology-readiness"
    Then I should not see the link "Add District"
    And I should not see the text "Instructions to District Admin to add district, which will allow results generate by School Admin to be reported to the district."
    But I should see the link "Mine @timestamp Readiness"
    And I should see the text "Summary of what user can do here: add schools, request school admins to run checks, view readiness by schools in district."
    But I should not see the link "Yours @timestamp Readiness"