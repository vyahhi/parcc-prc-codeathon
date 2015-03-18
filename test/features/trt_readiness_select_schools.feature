@api @trt @structured @school @readiness
Feature: PRC-817 Request Readiness Checks - Select Schools
  As a District Admin, I want to select the schools to which to send a request to run readiness checks so that the school contacts will run the checks.
#  Acceptance Criteria
#  Background
#    Given that I am logged in as District Admin
#    And I have schools added to my district
#    When I am on my Manage Schools page
#    Then I can click check boxes to select and deselect schools
#  Scenario 1: School not selected
#  Checkbox in row selects school associated with that row
#  Scenario 2: School selected
#  Checkbox in row deselects school associated with that row
#  Scenario 3: No schools selected
#  Checkbox in header selects all schools
#  Scenario 4: All schools selected
#  Checkbox in header deselects all schools
#  Scenario 5: All schools selected then one deselected
#  Checkbox in header is unchecked

  # The select all checkbox is all Javascript and it's built-in Drupal VBO functionality.
  # We'll exercise this in other request readiness stories.

  Scenario: Only the schools I select are included on the compose mail page
    Given I am logged in as a user with the "District Admin" role
    And I have no "School" nodes
    And I have no "District" nodes
    And "District" nodes:
      | title              | uid         |
      | PRC-828 @timestamp | @currentuid |
    And "School" nodes:
      | title                   | field_ref_district       | field_contact_email      |
      | School 828-3 @timestamp | @nid[PRC-828 @timestamp] | e3@timestamp@example.com |
      | School 828-1 @timestamp | @nid[PRC-828 @timestamp] | e1@timestamp@example.com |
      | School 828-2 @timestamp | @nid[PRC-828 @timestamp] | e2@timestamp@example.com |
    And I visit the first node created
    And I click "Manage Schools"
    When I check the box "edit-views-bulk-operations-1"
    When I press "Request Readiness Checks"
    Then I should see the heading "Request Readiness Checks"
    And I should not see the link "Add School - form"
    Then I should see the text "To:"
    And I should not see the text "School 828-1 @timestamp"
    And I should see the text "School 828-2 @timestamp"
    And I should not see the text "School 828-3 @timestamp"
