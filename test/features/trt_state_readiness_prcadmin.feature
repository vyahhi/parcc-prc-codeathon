@api @trt @state @prcadmin @prc-1209
Feature: PRC-1209 State Readiness - PRC Admin View
  As a PRC Admin,
  I want to be able to access all state readiness pages
  so that I can understand the readiness for the states and their districts and schools.

  Given that I am logged in as a PRC Admin
  And I am on the Admin Technology Readiness page
  When I click on a state
  Then I see the State Readiness page for the selected state that has:
  Differences from State Readiness - State Admin View (PRC-707):
  None
  Note: Only states that have been created appear as links on the PARCC Readiness page

  Scenario: Drill into state with no districts
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "State" nodes
    And "State" nodes:
      | title    | field_user_state | field_member_state | uid | field_contact_email |
      | Illinois | Illinois         | Illinois           | 1   | x@example.com       |
    And I visit "assessments/technology-readiness/parcc"
    And I click "Illinois"
    Then I should see the heading "Illinois Readiness"
    And I should see the text "Click the links on this page to access and download district and school data and readiness reports."
    And I should see the text "For more information on the technology requirements used to evaluate platforms and networks please download the"
    And I should see the link "PARCC minimum technology requirements"
    And I should see the text "No districts in your state have been created"
    And I should see the heading "Districts"

  Scenario: Drill into a state with districts
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "State" nodes
    And "State" nodes:
      | title    | field_user_state | field_member_state | uid | field_contact_email |
      | Illinois | Illinois         | Illinois           | 1   | x@example.com       |
    And "District" nodes:
      | title               | uid         | field_ref_trt_state |
      | District @timestamp | @currentuid | @nid[Illinois]      |
    And I visit "assessments/technology-readiness/parcc"
    And I click "Illinois - PARCC Member"
    Then I should see the heading "Illinois Readiness"
    And I should see the text "Click the links on this page to access and download district and school data and readiness reports."
    And I should see the text "For more information on the technology requirements used to evaluate platforms and networks please download the"
    And I should see the link "PARCC minimum technology requirements"
    But I should not see the text "No districts in your state have been created"
    And I should see the heading "Districts"
    And I should see the link "District @timestamp"
    And I should see the link "Export all system checks data to .csv"
    And I should see the link "Export all testing capacity checks data to .csv"

