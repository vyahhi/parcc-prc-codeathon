@api @speaking-listening @prc-1410
Feature: PRC-1410 Speaking and Listening page - Regulars View
  As a PARCC-member Educator, I want to be able to view Speaking and Listening resources.

  Scenario: Resource View
    # First create the node, annoying we have to do it this way but it's all files and SHS
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "speaking-listening"
    When I click "Add Resource"
    And I select "Listening logs - for students" from "Resource Type"
    And I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-file-single-und-0-upload"
    And I fill in "Resource name" with "Resource @timestamp"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I select "1st Grade" from "Grade Level"
    And I press "Save"

    Given I am an anonymous user
    And I am logged in as a user with the "PARCC-Member Educator" role
    When I am on "speaking-listening"
    Then I should see the heading "Speaking and Listening"
    And I should see the text "Overview / instructional copy goes here."
    And I should see the text "Resource Name"
    And I should see the text "Subject"
    And I should see the text "Grade Level"
    And I should see the text "Resource Type"
    And I should not see the link "Edit"

  Scenario: Educators can't see
    Given I am logged in as a user with the "Educator" role
    And I am on "instruction"
    Then I should not see the link "Speaking and Listening"