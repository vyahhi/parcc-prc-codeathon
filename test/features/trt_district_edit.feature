@api @trt @structured @district
Feature: PRC-838 District Name - Edit Form
  As a District Admin, I want to be able to edit my district name so I can make any corrections to my district name.

  Acceptance Criteria
#  Given that I am logged in as a District Admin
#  And I am on my District Readiness page
#  When I click the Edit district name link
  Then I see the Edit District name page that has:
  Differences from Add District (PRC-837):
  Page header
  Edit District
  Form fields
  Text field prepopulated with previously submitted district name

  Scenario: Add new district - District Admin
    Given I am logged in as a user with the "District Admin" role
    And I have no "District" nodes
    And I click "Technology Readiness"
    When I click "Add District"
    And I fill in "District Name" with "PRC-838 @timestamp"
    And I press "Submit"
    Then I should see the text "PRC-838 @timestamp Readiness"
    When I click "Edit district name"
    Then I should see the heading "Edit District"
    And the "District Name" field should contain "PRC-838 @timestamp"
    When I fill in "District Name" with "PRC-838 @timestamp New Text"
    And I press "Submit"
    # PRC-841
    Then I should see the text "PRC-838 @timestamp New Text Readiness"
