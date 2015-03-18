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