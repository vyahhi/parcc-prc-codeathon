@api @parcc-released-item
Feature: Add search functionality to PARCC Released Items Page

  @prc-1864 @javascript
  Scenario: Add search functionality to PARCC Released Items Page
    Given I have no "PARCC Released Item" nodes
    And parcc-released-item content:
      | resource name       | file                          | resource type | faux standard | faux subject | grade level | permissions  |
      | First Grade Resource | testfiles/GreatLakesWater.pdf | Item Set  | Standard One      | Subject One      | 1st Grade   | public     |
      | Second Grade Resource | testfiles/GreatLakesWater.pdf | Item Set  | Standard One      | Subject One      | 2nd Grade   | public     |
    And I am logged in as a user with the "Educator" role
    And I am on "assessments/parcc-released-items"
    Then I should see the text "First Grade Resource"
    And I should see the text "Second Grade Resource"
    When I fill in "edit-title" with "First"
    And I press "edit-submit-parcc-released-items"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"
    When I fill in "edit-title" with "Second"
    And I press "edit-submit-parcc-released-items"
    Then I should not see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I fill in "edit-title" with "Grade Resource"
    And I press "edit-submit-parcc-released-items"
    Then I should see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I press "Reset"
    Then I should see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I select "1st Grade" from "Grade Level"
    And I press "edit-submit-parcc-released-items"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"
    When I select "2nd Grade" from "Grade Level"
    And I press "edit-submit-parcc-released-items"
    Then I should not see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    And I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/parcc-released-items"
    When I select "1st Grade" from "Grade Level"
    And I press "edit-submit-parcc-released-items"
    When I follow "edit"
    And I select "Math" from "edit-field-subject-und-0-tid-select-1"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I press "Save"
    Then I should see the message containing "PARCC Released Item First Grade Resource has been updated."
    When I press "Reset"
    Then I should see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I fill in "edit-field-subject-tid" with "Math"
    And I press "edit-submit-parcc-released-items"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"
    When I fill in "edit-title" with "First"
    When I select "1st Grade" from "Grade Level"
    And I press "edit-submit-parcc-released-items"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"

    @prc-1877 @javascript
    Scenario: Search PARCC Released Items from second page and reset.
    Given I have no "PARCC Released Item" nodes
    And I run drush "genc 150 --types=parcc_released_item"
    When I am logged in as a user with the "Educator" role
    And I am on "assessments/parcc-released-items/"
    And I click "2"
    And I fill in "edit-title" with "Ex"
    And I press "edit-submit-parcc-released-items"
    Then I should see the text "Ex"
      # PRC-1887
    Then I press "Reset"
    And I should not see the link "« first"
    And I should see the link "next ›"
    And the url should match "assessments/parcc-released-items\!*"
    Then I run drush "genc 0 --types=parcc_released_item --kill"