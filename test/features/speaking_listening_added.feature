@api @speaking-listening @prc-1420
Feature: PRC-1420 Speaking and Listening - Add Resource - Resource Added
  As a PRC Admin, I want to get feedback that I have successfully added a Speaking and Listening resource so that I can know the action was successful.

  Scenario: Resource Added
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "instructional-tools/speaking-listening"
    When I click "Add Resource"
    And I select "Listening logs - for students" from "Resource Type"
    And I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-file-single-und-0-upload"
    And I fill in "Resource name" with "Resource @timestamp"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I check the box "1st Grade"
    And I press "Save"
    Then I should see the message containing "Speaking and Listening Resource Resource @timestamp has been created."
    And the url should match "instructional-tools/speaking-listening"
#  The Speaking and Listening page with the resource I added. (See Speaking and Listening page - PRC Admin View PRC-1415)