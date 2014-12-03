@api @course
Feature: PRC-69 Admin: Create a Course
  As a Content Administrator,
  I want to define all courses for the PRC website,
  so that these courses will be available for users as needed.

  Acceptance Criteria:
  AC1 A new tab Course Management shall be added to the top navigation bar for the following roles:
  Content Administrator (Curator)
  PRC Admin
  Tested in prc_348_curator_view_courses.feature


  6. If the user navigates away without saving changes, the system prompts the user to confirm by displaying the following:
  Stay On Page - this will keep the Admin UI on the "Create Course" page.
  Leave Page - this will direct the Admin UI to navigate away from the page.

  Scenario: AC2 Create course fields
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "admin-course"
    When I click "Add course"
    Then I should see the heading "Create Course" in the "content" region
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
    And the "Published" checkbox should be checked

  Scenario: AC3. Validations: If a required field is NOT entered after the Save button is selected, The system will display the following feedback on the top of the form:
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "admin-course"
    When I click "Add course"
    And I press "Save"
    Then I should see the error message containing "Course Title field is required."
    Then I should see the error message containing "Permissions field is required."
    Then I should see the error message containing "Course Objectives field is required."

  Scenario: AC4. The Save button will allow the user to save the entries for all the course information.
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "admin-course"
    When I click "Add course"
    And I fill in "Course Title" with "Title PRC-69 AC4 @timestamp"
    And I fill in "Course Objectives" with "Obj PRC-69 AC4 @timestamp"
    And I select the radio button "Public"
    And I press "Save"
    # AC5 Once Saved, the system will provide confirmation that the course information has been successfully saved.
    Then I should see the message containing "PD Course Title PRC-69 AC4 @timestamp has been created."

  Scenario: Published checked makes a PD Course published
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "admin-course"
    When I click "Add course"
    And I fill in "Course Title" with "Title PRC-69 Published @timestamp"
    And I fill in "Course Objectives" with "Obj PRC-69 Published @timestamp"
    And I select the radio button "Public"
    And the "Published" checkbox should be checked
    And I press "Save"
    Then the node titled "Title PRC-69 Published @timestamp" should be published

  Scenario: Published unchecked makes a PD Course not published
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "admin-course"
    When I click "Add course"
    And I fill in "Course Title" with "Title PRC-69 Published @timestamp"
    And I fill in "Course Objectives" with "Obj PRC-69 Published @timestamp"
    And I select the radio button "Public"
    And I uncheck the box "Published"
    And I press "Save"
    Then the node titled "Title PRC-69 Published @timestamp" should not be published
