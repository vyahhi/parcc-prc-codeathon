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
    And I visit "assessments/technology-readiness/parcc"
    Then I should see the heading "PARCC Readiness"
    And I should see the text "Click the links to access state reports."
    And I should see the text "For more information on the technology requirements used to evaluate platforms and networks please download the"
    And I should see the link "PARCC minimum technology requirements"
    And I should see the text "No states have been created"

  Scenario: Has states
    Given I am logged in as a user with the "PRC Admin" role
    And "State" nodes:
      | title    | field_user_state | field_member_state | uid | field_contact_email |
      | Illinois | Illinois         | Illinois           | 1   | x@example.com       |
    And "State" nodes:
      | title         | field_user_state | uid | field_contact_email |
      | New Hampshire | New Hampshire    | 1   | y@example.com       |
    And I visit "assessments/technology-readiness/parcc"
    Then I should see the heading "PARCC Readiness"
    And I should see the heading "States"
    And I should see the text "Click the links to access state reports."
    And I should see the text "For more information on the technology requirements used to evaluate platforms and networks please download the"
    And I should see the link "PARCC minimum technology requirements"
    And I should not see the text "No states have been created"
    But I should see the link "New Hampshire"
    And I should see the link "Illinois - PARCC Member"

  Scenario: PRC-1382 PRC Admin should not display "No states have been created"
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "State" nodes
    And I am on "assessments/technology-readiness"
    Then I should not see the text "No states have been created"