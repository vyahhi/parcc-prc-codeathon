@api @trt @parcc-readiness @prc-1208
Feature: PRC-1208 PARCC Readiness
  As a PRC Admin,
  I want to be able to access technology readiness data for all schools in all districts in all states
  so that I can understand the readiness for these entities.

#  Scenario 2: No states have been created
#  Copy
#  No states have been created.
#  Scenario 3: One or more states have been created
#  List of States
#  States [subhead]
#  List of states that have been created, including District of Columbia, in alphabetical order and spelled out (e.g., District of Columbia).
#  PARCC member states have appended to state name "- PARCC Member" (e.g., "Illinois - PARCC Member")
#  PARCC member states are: AR, CO, DC, IL, LA, MD, MA, MS, NJ, NM, NY, OH, RI

  Scenario: PARCC Readiness Page, no states
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "State" nodes
    And I visit "technology-readiness/parcc"
    Then I should see the heading "PARCC Readiness"
    And I should see the text "Overview / instructional copy goes here \(admin can navigate to state and export all test results data for state to csv or further navigate to view readiness check results by school\)."
    And I should see the text "No states have been created"

  Scenario: Has states
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "State" nodes
    And "State" nodes:
      | title    | field_user_state | field_member_state | uid | field_contact_email |
      | Illinois | Illinois         | Illinois           | 1   | x@example.com       |
    And "State" nodes:
      | title         | field_user_state | uid | field_contact_email |
      | New Hampshire | New Hampshire    | 1   | y@example.com       |
    And I visit "technology-readiness/parcc"
    Then I should see the heading "PARCC Readiness"
    And I should see the text "Overview / instructional copy goes here \(admin can navigate to state and export all test results data for state to csv or further navigate to view readiness check results by school\)."
    And I should not see the text "No states have been created"
    But I should see the link "New Hampshire"
    And I should see the link "Illinois - PARCC Member"