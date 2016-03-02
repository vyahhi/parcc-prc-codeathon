@api @speaking-listening @prc-1418 @prc-1417 @prc-1603 @prc-1602
Feature: PRC-1418 Speaking And Listening - Add Resource
  As a PRC Admin,
  I want to be able to add a Speaking and Listening resource
  so that educators can access it and use it.

  Scenario: Add Form
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "instructional-tools/speaking-listening"
    When I click "Add Resource"
    Then I should see the heading "Create Speaking and Listening Resource"
    And I should see the text "Allowed file types: brf doc docx mp4 pdf xls xlsx."
    And I should see a "Save" button
    And I select "Listening logs - for students" from "Resource Type"
    And I select "Listening logs - for teachers" from "Resource Type"
    And I select "Performance tasks - for students" from "Resource Type"
    And I select "Performance tasks - for teachers" from "Resource Type"
    And I select "Rubrics - for students" from "Resource Type"
    And I select "Rubrics - for teachers" from "Resource Type"
    And I select "Task models - for teachers" from "Resource Type"