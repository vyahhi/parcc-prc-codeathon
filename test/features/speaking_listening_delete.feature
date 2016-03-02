@api @speaking-listening @prc-1428 @prc-1429 @prc-1430
Feature: Delete Speaking and Listening Resource

  @prc-1428
  Scenario: Delete - Are you sure?
    Given I am logged in as a user with the "PRC Admin" role
    And "Speaking and Listening Resource" nodes:
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
    Then I should see the text "Are you sure you want to delete Resource @timestamp?"
    And I should see the text "This action cannot be undone."
    And I should see a "Delete" button
    And I should see a "Cancel" link

  @prc-1429
  Scenario: Delete - Cancel
    Given I am logged in as a user with the "PRC Admin" role
    And "Speaking and Listening Resource" nodes:
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

  @prc-1430
  Scenario: Delete - Deleted
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "Speaking and Listening Resource" nodes
    And "Speaking and Listening Resource" nodes:
      | title               | status | uid         |
      | Resource @timestamp | 1      | @currentuid |
    And I am on "instructional-tools/speaking-listening"
    When I click "edit"
    And I select "Listening logs - for students" from "Resource Type"
    And I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-file-single-und-0-upload"
    And I fill in "Resource name" with "Resource @timestamp"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I check the box "1st Grade"
    And I press "Save"
# Have to edit it to fill in the terms and fields and everything, then Delete
    And I am on "instructional-tools/speaking-listening"
    When I click "edit"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    When I press "Delete"
    And I press "Delete"
    Then I should see the message containing "Speaking and Listening Resource"
    And I should see the message containing "Resource @timestamp"
    And I should see the message containing "has been deleted."
    And the url should match "instructional-tools/speaking-listening"