@api @k2 @fit @prc-1230 @prc-1229
Feature: PRC-1229 Formative Instructional Tasks - Add Resource
  As a PRC Admin,
  I want to be able to add a Formative Instructional Tasks resource
  so that educators can access it and use it in their classrooms.

  Given that I am logged in as a PRC Admin
  And I am on the Formative Instructional Tasks page
  When I click the Add Resource link
  Then I see the Add Resource page that has:
  Page Headline
  Add Resource
  Overview Copy
  Overview and instructional copy goes here.
  Copy
  "* indicates required field"
  Form fields
  See Formative Instructional Tasks - Add/Edit/Delete Resource - Master table PRC-1230
  Button
  Save [button]

  Scenario: Add Form
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "node/add/formative-instructional-task"
    Then I should see the heading "Create Formative Instructional Task"
    And I should see the text "Allowed file types: doc docx mp4 pdf xls xlsx."
    And I should see a "Save" button
    And I select "Listening logs - for students" from "Resource Type"
    And I select "Listening logs - for teachers" from "Resource Type"
    And I select "Performance tasks - for students" from "Resource Type"
    And I select "Performance tasks - for teachers" from "Resource Type"
    And I select "Rubrics - for students" from "Resource Type"
    And I select "Rubrics - for teachers" from "Resource Type"
    And I select "Task models - for teachers" from "Resource Type"
    And I should see the checkbox "1st Grade"
    And I should see the checkbox "Pre-K"