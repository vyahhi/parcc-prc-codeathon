@api @trt @structured @school
Feature: PRC-828 Manage Schools
  As a District Admin,
  I want to ask schools in my district to run the readiness checks
  so I can understand if the schools are ready to run the PARCC assessment.

#  Acceptance Criteria
#  Background
#    Given that I am logged in as District Admin
#    And I am on my District Readiness page
#    When I click the Manage Schools link
#    Then I see the Manage Schools page that has:
#  Common page elements
#  Page Headline
#  Manage Schools
#  Overview Copy
#  "Overview / instructional copy goes here: user can add/edit school information and request readiness checks. Consider describing information needed for each school (school name and email address of person responsible for running readiness checks at each school)."
#  Add School links
#  Add School - form
#  Scenario 1: I have no schools added to my district
#    Given I have no schools added to my district
#    Then I see common page elements and:
#  Add School links
#  Add School(s) - upload .csv file [link, appears below Add School - form link]
#  Copy
#  "No schools have been added to your district. Please click one of the Add School links above to add schools."
#  Scenario 2: I have one or more schools added to my district and no district admin has uploaded any schools to my district
#    Given I have one or more schools added to my district
#    And no district admin has uploaded any schools to my district
#    Then I see common page elements and:
#  Add School links
#  Add School(s) - upload .csv file [link, appears below Add School - form link]
#  Schools Table
#  Table displaying schools in alphabetical order with a row for each added school.
#  <checkbox>	School Name	School Contact Email Address
#  <checkbox>	<School Name>	<School Contact's Email Addresss>
#  Request Readiness Checks button
#  Scenario 3: I have one or more schools added to my district and a district admin has uploaded one or more schools to my school
#    Given I have one or more schools added to my district
#    And a district admin has uploaded one or more schools to my district
#    Then I see the same as scenario 2 except:
#  *Differences from Scenario 2:
#  I do not see Add School(s) - upload .csv file link

  Scenario: No schools added
    Given I am logged in as a user with the "District Admin" role
    And I follow "Technology Readiness"