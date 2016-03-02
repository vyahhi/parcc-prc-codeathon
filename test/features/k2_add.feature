@api @k2 @fit @prc-1230 @prc-1229 @prc-1524 @permissions @prc-1556 @prc-1600 @prc-1601
Feature: PRC-1229 Formative Instructional Tasks - Add Resource
  As a PRC Admin,
  I want to be able to add a Formative Instructional Tasks resource
  so that educators can access it and use it in their classrooms.

  Scenario: Add Form
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "node/add/formative-instructional-task"
    Then I should see the heading "Create Formative Instructional Task"
    And I should see the text "Allowed file types: brf doc docx mp4 pdf xls xlsx."
    And I should see a "Save" button
    And I select "Licensed Resource" from "Resource Type"
    And I select "Task" from "Resource Type"
    And I should see the checkbox "1st Grade"
    And I should see the checkbox "Pre-K"
    And I should see a "Public" field
    And I should see a "PARCC members ONLY" field
    And I should see the text "This content shall be available to:"