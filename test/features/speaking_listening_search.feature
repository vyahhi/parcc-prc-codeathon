@api @speaking-listening
Feature: Add search functionality to Speaking and Listening Page

  @prc-1864 @javascript
  Scenario: Add search functionality to Speaking and Listening Page
    Given I have no "Speaking and Listening Resource" nodes
    Given speaking-listening content:
      | resource name       | resource type                 | file                          | faux standard | faux subject | grade level |
      | First Grade Resource | Listening logs - for students | testfiles/GreatLakesWater.pdf | Standard      | Subject      | 1st Grade   |
      | Second Grade Resource | Listening logs - for students | testfiles/GreatLakesWater.pdf | Standard      | Subject      | 2nd Grade   |
    And I am logged in as a user with the "Educator" role
    And I am on "instructional-tools/speaking-listening"
    Then I should see the text "First Grade Resource"
    And I should see the text "Second Grade Resource"
    When I fill in "edit-title" with "First"
    And I press "edit-submit-speaking-and-listening"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"
    When I fill in "edit-title" with "Second"
    And I press "edit-submit-speaking-and-listening"
    Then I should not see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I fill in "edit-title" with "Grade Resource"
    And I press "edit-submit-speaking-and-listening"
    Then I should see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I press "Reset"
    Then I should see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I select "1st Grade" from "Grade Level"
    And I press "edit-submit-speaking-and-listening"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"
    When I select "2nd Grade" from "Grade Level"
    And I press "edit-submit-speaking-and-listening"
    Then I should not see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    And I am logged in as a user with the "PRC Admin" role
    And I am on "instructional-tools/speaking-listening"
    When I select "1st Grade" from "Grade Level"
    And I press "edit-submit-speaking-and-listening"
    When I follow "edit"
    And I wait for AJAX to finish
    And I select "Math" from "edit-field-subject-und-0-tid-select-1"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I press "Save"
    Then I should see the message containing "Speaking and Listening Resource First Grade Resource has been updated."
    When I press "Reset"
    Then I should see the link "First Grade Resource"
    And I should see the link "Second Grade Resource"
    When I fill in "edit-field-subject-tid" with "Math"
    And I press "edit-submit-speaking-and-listening"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"
    When I fill in "edit-title" with "First"
    When I select "1st Grade" from "Grade Level"
    And I press "edit-submit-speaking-and-listening"
    Then I should see the link "First Grade Resource"
    And I should not see the link "Second Grade Resource"

  @prc-1877 @javascript
  Scenario: Search Speaking and Listening from second page and reset.
    Given I have no "Speaking and Listening Resource" nodes
    And I run drush "genc 150 --types=speaking_and_listening_resource"
    When I am logged in as a user with the "PARCC-Member Educator" role
    And I am on "instructional-tools/speaking-listening"
    And I click "2"
    And I fill in "edit-title" with "Ex"
    And I press "edit-submit-speaking-and-listening"
    Then I should see the text "Ex"
      # PRC-1887
    Then I press "Reset"
    And I should not see the link "< prev"
    And I should see the link "next ›"
    And the url should match "instructional-tools/speaking-listening\!*"
    Then I run drush "genc 0 --types=speaking_and_listening_resource --kill"
