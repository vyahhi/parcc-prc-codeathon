@api @speaking-listening @prc-1410
Feature: PRC-1410 Speaking and Listening page - Regulars View
  As a PARCC-member Educator, I want to be able to view Speaking and Listening resources.
  Acceptance Criteria
  Given that I am logged in as a PARCC-member Educator
  And I am on the Instruction page
  When I click the Speaking and Listening link
  Then I see the Speaking and Listening page that has:
  Scenario: 1 Common page elements
  Page Headline
  Speaking and Listening
  Overview Copy
  Overview / instructional copy goes here.
  Resources Table
  [Table displays resources alphabetical order by Resource Name.]
  Resource Name	Subject	Grade Level	Resource Type
  <Resource Name>	<Subject> [Note: User can enter multiple subjects, and they display in order added	<Grade level> [note: user can enter multiple, and all entered display]	<Resource Type>
  Note: Peter expects that when page is accessible to PARCC-member Educators, there will always be at least one resource on this page

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

  Scenario: Educators can't see
    Given I am logged in as a user with the "Educator" role
    And I am on "instruction"
    Then I should not see the link "Speaking and Listening"