@api @trt @structured @school @readiness
Feature: PRC-818 Request Readiness Checks - Select Schools - Form Validation
  As a District Admin, I want to get feedback about any errors that occur when I ask schools in my district to run the readiness checks so that I can fix errors and successfully send a request that schools run readiness checks.
#  Acceptance Criteria
#  Given that I am logged in as District Admin
#  And I am on my Manage Schools page
#  And I do not select any schools
#  When I click the Request Readiness Checks button
#  Then I see the error messages:
#  Error message
#  Please select the school or schools to which you would like to send a request to run readiness checks.

  Scenario: No schools selected
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
    When I press "Request Readiness Checks"
    Then I should see the error message containing "Please select at least one item."