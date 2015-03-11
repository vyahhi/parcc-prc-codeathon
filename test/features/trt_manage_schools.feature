@api @trt @structured @school
Feature: PRC-828 Manage Schools
  As a District Admin,
  I want to ask schools in my district to run the readiness checks
  so I can understand if the schools are ready to run the PARCC assessment.

#  Request Readiness Checks button

  Scenario: No schools added
    Given I am logged in as a user with the "District Admin" role
    And I have no "School" nodes
    And I have no "District" nodes
    And "District" nodes:
      | title              | uid         |
      | PRC-828 @timestamp | @currentuid |
    And I visit the last node created
    And I click "Manage Schools"
    Then I should see the heading "Manage Schools"
    And I should see the text "Overview / instructional copy goes here: user can add/edit school information and request readiness checks. Consider describing information needed for each school \(school name and email address of person responsible for running readiness checks at each school\)."
    And I should see the link "Add School - form"
    And I should see the link "Add School(s) - upload csv file"
    And I should see the text "No schools have been added to your district. Please click one of the Add School links above to add schools."

  Scenario: District has schools
    Given I am logged in as a user with the "District Admin" role
    And I have no "School" nodes
    And I have no "District" nodes
    And "District" nodes:
      | title              | uid         |
      | PRC-828 @timestamp | @currentuid |
    And "School" nodes:
      | title                 | field_ref_district       | field_contact_email     |
      | School 828 @timestamp | @nid[PRC-828 @timestamp] | e@timestamp@example.com |
    And I visit the first node created
    And I click "Manage Schools"
    Then I should see the heading "Manage Schools"
    And I should see the text "Overview / instructional copy goes here: user can add/edit school information and request readiness checks. Consider describing information needed for each school \(school name and email address of person responsible for running readiness checks at each school\)."
    And I should see the link "Add School - form"
    And I should see the link "Add School(s) - upload csv file"
    And I should not see the text "No schools have been added to your district. Please click one of the Add School links above to add schools."
    And I should see the text "School 828 @timestamp"
    And I should see the text "e@timestamp@example.com"
    And I select "Request Readiness Checks" from "edit-operation"

  Scenario: District has an upload
    Given I am logged in as a user with the "District Admin" role
    And I have no "School" nodes
    And I have no "District" nodes
    And "District" nodes:
      | title              | uid         |
      | PRC-828 @timestamp | @currentuid |
    And "School" nodes:
      | title                 | field_ref_district       | field_contact_email     |
      | School 828 @timestamp | @nid[PRC-828 @timestamp] | e@timestamp@example.com |
    And I flag "PRC-828 @timestamp" with "File Uploaded"
    And I visit the first node created
    And I click "Manage Schools"
    And I should see the link "Add School - form"
    And I should not see the link "Add School(s) - upload csv file"
