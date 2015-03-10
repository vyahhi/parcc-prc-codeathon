@api @trt @structured @district
Feature: PRC-839 District Name - Add / Edit - Form Validation
  As a District Admin, I want to be able to see any errors when I add or edit my district name so that I can fix the errors.
  Acceptance Criteria
  Given that I am logged in as a District Admin
  And I am on the Add / Edit District page
  And I have invalid fields
  When I click the Submit button
  Then I see the following errors:
  District name is a required field. Please enter District name.

  Scenario: No District name
    Given I am logged in as a user with the "District Admin" role
    And I have no "District" nodes
    And I click "Technology Readiness"
    When I click "Add District"
    And I press "Submit"
    Then I should see the error message containing "District Name field is required."