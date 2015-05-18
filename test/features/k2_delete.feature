@api @k2 @prc-1247 @prc-1248 @prc-1249
Feature: Delete Formative Instructional Task Resource

  Background:
    Given I have no "Formative Instructional Task" nodes
    And formative instructional task content:
      | resource name       | resource type                 | file                          | faux standard | faux subject | grade level |
      | Resource @timestamp | Listening logs - for students | testfiles/GreatLakesWater.pdf | Standard      | Subject      | 1st Grade   |

  @prc-1247
  Scenario: Delete - Are you sure?
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "formative-instructional-tasks"
    And I click "edit"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    When I press "Delete"
    Then I should see the text "Are you sure you want to delete Resource @timestamp?"
    And I should see the text "This action cannot be undone."
    And I should see a "Delete" button
    And I should see a "Cancel" link

  @prc-1248
  Scenario: Delete - Cancel
    Given I am logged in as a user with the "PRC Admin" role
    And "Formative Instructional Task" nodes:
      | title               | status | uid         |
      | Resource @timestamp | 1      | @currentuid |
    And I visit the first node created
    And I click "Edit"
    And I select "Listening logs - for students" from "Resource Type"
    And I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-file-single-und-0-upload"
    And I fill in "Resource name" with "Resource @timestamp"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I check the box "1st Grade"
    And I press "Save"
    # Have to edit it to fill in the terms and fields and everything, then Delete
    And I visit the first node created
    And I click "Edit"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    When I press "Delete"
    And I click "Cancel"
    Then I should see the heading "Resource @timestamp"
  
  @prc-1249
  Scenario: Delete - Deleted
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "formative-instructional-tasks"
    And I click "edit"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    When I press "Delete"
    And I press "Delete"
    Then I should see the message containing "Formative Instructional Task"
    And I should see the message containing "Resource @timestamp"
    And I should see the message containing "has been deleted."
    And the url should match "formative-instructional-tasks"