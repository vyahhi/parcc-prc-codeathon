@api @k2 @fit @prc-1241
Feature: PRC-1241 Formative Instructional Tasks - Add Resource - Resource Added
  As a PRC Admin,
  I want to get feedback that I have successfully added a Formative Instructional Tasks resource
  so that I can know the action was successful.

  Scenario: Resource Added
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "instructional-tools/formative-instructional-tasks"
    And I click "Add Resource"
    And I select "Licensed Resource" from "Resource Type"
    And I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-file-single-und-0-upload"
    And I fill in "Resource name" with "Resource @timestamp"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I check the box "1st Grade"
    And I select the radio button "Public"
    And I press "Save"
    Then I should see the message containing "Formative Instructional Task Resource @timestamp has been created."
    And the url should match "instructional-tools/formative-instructional-tasks"