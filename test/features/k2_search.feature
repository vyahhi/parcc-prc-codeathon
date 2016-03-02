@api @k2 @fit
Feature: Add search functionality to Formative Instructional Tasks Page

  @prc-1864 @javascript
  Scenario: Add search functionality to Formative Instructional Tasks Page
    Given I have no "Formative Instructional Task" nodes
    And formative instructional task content:
      | resource name       | resource type                 | file                          | faux standard | faux subject | grade level | permissions  |
      | First Grade Resource | Task | testfiles/TT_Rules_2015.pdf | Standard      | Subject      | 1st Grade   | public                                          |
      | Second Grade Resource | Task | testfiles/TT_Rules_2015.pdf | Standard      | Subject      | 2nd   | public                                          |
    And I am logged in as a user with the "Educator" role
    And I am on "instructional-tools/formative-instructional-tasks"
    Then I should see the text "First Grade Resource"
    And I should see the text "Second Grade Resource"
    When I fill in "edit-title" with "First"
    And I press "edit-submit-formative-instructional-tasks"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"
    When I fill in "edit-title" with "Second"
    And I press "edit-submit-formative-instructional-tasks"
    Then I should not see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I fill in "edit-title" with "Grade Resource"
    And I press "edit-submit-formative-instructional-tasks"
    Then I should see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I press "Reset"
    Then I should see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I select "1st Grade" from "Grade Level"
    And I press "edit-submit-formative-instructional-tasks"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"
    When I select "2nd Grade" from "Grade Level"
    And I press "edit-submit-formative-instructional-tasks"
    Then I should not see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    And I am logged in as a user with the "PRC Admin" role
    And I am on "instructional-tools/formative-instructional-tasks"
    When I select "1st Grade" from "Grade Level"
    And I press "edit-submit-formative-instructional-tasks"
    When I follow "edit"
    And I select "Math" from "edit-field-subject-und-0-tid-select-1"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I press "Save"
    Then I should see the message containing "Formative Instructional Task First Grade Resource has been updated."
    When I press "Reset"
    Then I should see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I fill in "edit-field-subject-tid" with "Math"
    And I press "edit-submit-formative-instructional-tasks"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"
    When I fill in "edit-title" with "First"
    When I select "1st Grade" from "Grade Level"
    And I press "edit-submit-formative-instructional-tasks"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"

  @prc-1877 @javascript
  Scenario: Search Formative Instructional Task from second page and reset.
    Given I have no "Formative Instructional Task" nodes
    And I run drush "genc 150 --types=formative_instructional_task"
    When I am logged in as a user with the "PARCC-Member Educator" role
    And I am on "instructional-tools/formative-instructional-tasks/"
    And I click "2"
    And I fill in "edit-title" with "Ex"
    And I press "edit-submit-formative-instructional-tasks"
    Then I should see the text "Ex"
      # PRC-1887
    Then I press "Reset"
    And I should not see the link "« first"
    And I should see the link "2"
    And the url should match "instructional-tools/formative-instructional-tasks\!*"
    Then I run drush "genc 0 --types=formative_instructional_task --kill"

