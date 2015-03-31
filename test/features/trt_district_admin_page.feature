@api @trt @district @prc-940 @structured
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

  Scenario: 1 - My district does not exist
    Given users:
      | name                         | mail                         | pass   | field_first_name | field_last_name | status |
      | prc940@timestamp@example.com | prc940@timestamp@example.com | xyz123 | District         | Administrator   | 1      |
    And I am logged in as "prc940@timestamp@example.com"
    When I click "Technology Readiness"
#    Then I should see the link "Add District Name"
