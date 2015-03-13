@api @trt @structured @school
Feature: PRC-817
  Request Readiness Checks - Select Schools
  As a District Admin, I want to select the schools to which to send a request to run readiness checks so that the school contacts will run the checks.
  Acceptance Criteria
#  Background
#  Given that I am logged in as District Admin
#  And I have schools added to my district
#  When I am on my Manage Schools page
  Then I can click check boxes to select and deselect schools
#  Scenario 1: School not selected
  Checkbox in row selects school associated with that row
#  Scenario 2: School selected
  Checkbox in row deselects school associated with that row
#  Scenario 3: No schools selected
  Checkbox in header selects all schools
#  Scenario 4: All schools selected
  Checkbox in header deselects all schools
#  Scenario 5: All schools selected then one deselected
  Checkbox in header is unchecked

  Scenario: Exercise checkboxes
    Given I am logged in as a user with the "District Admin, Educator" roles
    And "District" nodes:
      | title                   | uid         |
      | District 817 @timestamp | @currentuid |
    And "School" nodes:
      | title                   | field_ref_district            | field_contact_email     |
      | School 828-1 @timestamp | @nid[District 817 @timestamp] | e@timestamp@example.com |
      | School 828-2 @timestamp | @nid[District 817 @timestamp] | e@timestamp@example.com |
      | School 828-3 @timestamp | @nid[District 817 @timestamp] | e@timestamp@example.com |
      | School 828-4 @timestamp | @nid[District 817 @timestamp] | e@timestamp@example.com |
    And I visit the first node created
    And I click "Manage Schools"
    And I check the box with the css selector ".vbo-table-select-all"
#    And I check the box with the css selector "#views-form-trt-district-schools-panel-pane-1 > div > table > thead > tr > th.views-field.views-field-views-bulk-operations > div > input"
    Then I should see the link "School 828-4 @timestamp"

#    And "<string>" should precede "<string>" for the query "<string>"