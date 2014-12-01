@api
Feature: PRC-360 Admin: Add Object to a Course
  As a Content Admin,
  I want to add a new module or exam to an existing course,
  so that my educators can access them when taking a course.

  #  Acceptance Criteria
  # Tested in PRC-350 - course_modules_add.feature
  # AC1 When an existing course is selected, in addition to the existing tabs, a Course Outline tab shall be available to the user.
  # AC2 The following roles are permitted to access this page:
  #   Content Administrator (Curator)
  #   PRC Admin

  Scenario: AC3 In the Course Outline tab defined in PRC-350, add a pair of dropdown menu and button.
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PRC-350 AC4"
    And I follow "Course outline"

    #  AC4 The dropdown menu shall contain the following options (none selected by default):
    #  Module
    #  Exam
    # The type dropdown has no label...
    And I should see an "edit-faux-more-faux-object-type" field
    And I select "Module" from "edit-faux-more-faux-object-type"
    And I select "Exam" from "edit-faux-more-faux-object-type"
    
    And "Module" should precede "Exam" for the query "#edit-faux-more-faux-object-type option"
    
    # AC5 The Add object button shall be enabled when an object is selected from the drop down menu
    Then I should see an "Add object" button
    # AC6 A Save outline button shall be available at all time
    Then I should see an "Save outline" button
    # AC7 At click, it will save the new object, and lists it in the list of objects above (defined in PRC-350)