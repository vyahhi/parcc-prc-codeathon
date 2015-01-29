@api @course
Feature: PRC-349 Admin: Edit Course
  As a Content Admin,
  I want to edit an existing course,
  so that I can update the course attributes and course audience when needed.

  Acceptance Criteria:
  1. The tab Course Management shall be available in the top navigation bar for the following roles:
  Content Administrator (Curator)
  PRC Admin
  Tested in prc_348_curator_view_courses.feature

  Background:
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I have no "PD Course" nodes
    And I am viewing my "PD Course" node with the title "PRC-349 AC2"
    And I am on "admin-course"
    When I click "Edit"
    Then I should see the heading "Edit Course PRC-349 AC2" in the "content" region

  Scenario: AC2 Create course fields
    And I should see a "Course Title *" field
    And I should see a "Course Objectives *" field
    And I should not see a "Body" field
    And I should see a "Tags" field
    And I should see the text "Enter a comma-separated list of words to describe your content."
    And I should see a "Grade Level" field
    And I should see the text "Subject"

    And I should see the text "Course Length"
  # Course length doesn't have a label
    And I should see 1 "#edit-field-length-quantity-und" elements
    And I select "1" from "edit-field-length-quantity-und"
    And I select "2" from "edit-field-length-quantity-und"
    And I select "3" from "edit-field-length-quantity-und"
    And I select "4" from "edit-field-length-quantity-und"
    And I select "5" from "edit-field-length-quantity-und"
    And I select "6" from "edit-field-length-quantity-und"
    And I select "7" from "edit-field-length-quantity-und"
    And I select "8" from "edit-field-length-quantity-und"
    And I select "9" from "edit-field-length-quantity-und"
    And I select "10" from "edit-field-length-quantity-und"
    And I select "11" from "edit-field-length-quantity-und"
    And I select "12" from "edit-field-length-quantity-und"
    And I select "13" from "edit-field-length-quantity-und"
    And I select "14" from "edit-field-length-quantity-und"
    And I select "15" from "edit-field-length-quantity-und"
    And I select "16" from "edit-field-length-quantity-und"
    And I select "17" from "edit-field-length-quantity-und"
    And I select "18" from "edit-field-length-quantity-und"
    And I select "19" from "edit-field-length-quantity-und"
    And I select "20" from "edit-field-length-quantity-und"
    And I select "21" from "edit-field-length-quantity-und"
    And I select "22" from "edit-field-length-quantity-und"
    And I select "23" from "edit-field-length-quantity-und"
    And I select "24" from "edit-field-length-quantity-und"

  # Neither does unit
    And I should see 1 "#edit-field-length-unit-und" elements
    And I select "Hour" from "edit-field-length-unit-und"
    And I select "Day" from "edit-field-length-unit-und"
    And I select "Week" from "edit-field-length-unit-und"
    And I select "Month" from "edit-field-length-unit-und"
    And I select "Year" from "edit-field-length-unit-und"

    And I should see the text "Permissions *"
    And I should see the radio button "Public"
    And I should see the radio button "PARCC members ONLY"

    And I should see a "Published" field
    And the "Published" checkbox should not be checked

  Scenario: AC4. Validations: If a required field is NOT entered after the Save button is selected, The system will display the following feedback on the top of the form:
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "admin-course"
    When I click "Add course"
    And I press "Save"
    Then I should see the error message containing "Course Title field is required."
    Then I should see the error message containing "Permissions field is required."
    Then I should see the error message containing "Course Objectives field is required."

  Scenario: AC5. The Save button will allow the user to save the entries for all the course information.
    And I fill in "Course Title" with "Title PRC-349 AC5 @timestamp"
    And I fill in "Course Objectives" with "Obj PRC-349 AC5 @timestamp"
    And I select the radio button "Public"
    And I press "Save"
    # AC6 Once Saved, the system will provide confirmation that the course information has been successfully saved.
    Then I should see the message containing "PD Course Title PRC-349 AC5 @timestamp has been updated."

  Scenario: Published reflects published status
    And the "Published" checkbox should not be checked
    And I check the box "Published"
    And I fill in "Course Objectives" with "@timestamp"
    And I select the radio button "Public"
    And I press "Save"
    Then I click "Edit"
    And the "Published" checkbox should be checked
    And I uncheck the box "Published"
    And I press "Save"
    Then I click "Edit"
    And the "Published" checkbox should not be checked
