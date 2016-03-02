@api @d7 @styleguide @parcc-released-item @prc-1750 @javascript
Feature: PARCC Released Items - View Page Resource Types (PRC-1750)
  As a any user
  I want to be able to assign a resource type to a resource on the PARCC Released Items page
  so that users will know what type of resource the file is.

  Scenario: Responsive Behavior Mobile and Tablet
    Given I have no "PARCC Released Item" nodes
    And parcc-released-item content:
      | resource name       | file                          | resource type | faux standard | faux subject | grade level | permissions  |
      | Test Resource | testfiles/GreatLakesWater.pdf | Item Set  | Standard One      | Subject One      | 1st Grade   | public     |
    And I am on "assessments/parcc-released-items"
    When I am browsing using a "phone"
    Then I should see the text "Resource Name"
    And I should see the text "Subject"
    And I should see the text "Grade Level"
    And I should not see the text "Release Year"
    And I should not see the text "Resource Type"
    When I am browsing using a "tablet"
    Then I should see the text "Resource Name"
    And I should see the text "Subject"
    And I should see the text "Grade Level"
    And I should see the text "Release Year"
    And I should see the text "Resource Type"

