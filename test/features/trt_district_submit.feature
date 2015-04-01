@api @trt @structured @district @prc-840 @prc-706
Feature: PRC-840 District Readiness - Name Added
  As a District Admin, I want to be able to add my district name so I can set up my district readiness page.

#  Acceptance Criteria
#  Given that I am logged in as a District Admin
#  And I am on the Add District page
#  And my fields are valid
#  When I click the Submit button
  Then the district name is added to my state's State Readiness page (PRC-707)
#  And I see District Readiness page with:
#  Page header
#  <District Name> Readiness
#  Overview copy
#  Overview / instructional copy goes here (click on school name to see admin can add / edit school, request that readiness checks be run, view results of technology checks by school and export all test results data to csv).
#  Edit district name (link)
#  Manage schools (link) – descriptive copy: add schools and request readiness checks

  Scenario: Add new district - District Admin
    Given I am logged in as a user with the "District Admin" role
    And I have no "District" nodes
    And I click "Technology Readiness"
    When I click "Add District"
    And I fill in "District Name" with "PRC-840 @timestamp"
    And I press "Submit"
    Then I should see the heading "PRC-840 @timestamp Readiness"
    # Text changed by PRC-706
    And I should see the text "Overview / instructional copy goes here \(admin can export all test results data for district to csv or click school name to view results of technology checks for school\). Note only schools that have run structured readiness checks display on this page."
    And I should see the link "Edit district name"
    And I should see the link "Manage Schools"
    And I should see the text "add schools and request readiness checks"