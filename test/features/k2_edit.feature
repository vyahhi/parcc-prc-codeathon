@api @k2 @prc-1244
Feature: PRC-1244 Formative Instructional Task - Edit Resource
  As a PRC Admin, I want to be able to edit a Formative Instructional Tasks resource so that educators can access the edited resource and use it in their classrooms.

  Scenario: Edit form
    Given I am logged in as a user with the "PRC Admin" role
    And "Formative Instructional Task" nodes:
      | title               | status | uid         |
      | Resource @timestamp | 1      | @currentuid |
    And I visit the first node created
    And I click "Edit"
    Then I should see the heading "Resource @timestamp"
    And the "Resource name" field should contain "Resource @timestamp"
    And I should see a "Save" button
    And I should see a "Delete" button

  @prc-1415
  Scenario: Edited - click edit from view
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "Formative Instructional Task" nodes
    And "Formative Instructional Task" nodes:
      | title               | status | uid         |
      | Resource @timestamp | 1      | @currentuid |
    And I am on "formative-instructional-tasks"
    When I click "edit"
    And I select "Listening logs - for students" from "Resource Type"
    And I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-file-single-und-0-upload"
    And I fill in "Resource name" with "Resource @timestamp"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I check the box "1st Grade"
    And I press "Save"
    Then the url should match "formative-instructional-tasks"

    @prc-1416
    Scenario: Sorting
      Given I am logged in as a user with the "PRC Admin" role
      And I have no "Formative Instructional Task" nodes
      And "Formative Instructional Task" nodes:
        | title               | status | uid         |
        | Resource @timestamp | 1      | @currentuid |
      When I am on "formative-instructional-tasks"
      Then I should see the link "Resource Name"
      And I should see the link "Resource Type"