@api @course
Feature: PRC-360 Admin: Add Object to a Course
  As a Content Admin,
  I want to add a new module or exam to an existing course,
  so that my educators can access them when taking a course.

  #  Acceptance Criteria
  #  When an existing course is selected, in addition to the existing tabs, a Course Outline tab will be available to the user.
  #  The following roles are permitted to access this page:
  #  Content Administrator (Curator)
  #  PRC Admin
  #  Tested in PRC-350 - course_modules_add.feature

  Scenario: AC3 In the Course Outline tab defined in PRC-350, add a pair of dropdown menu and button.
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PRC-350 AC4"
    And I follow "Course outline"

    #  AC4 The dropdown menu shall contain the following options (none selected by default):
    #  Module
    #  Exam
    # The type dropdown has no label...
    And I should see an "edit-more-object-type" field
    And I select "Module" from "edit-more-object-type"
      And I select "Exam" from "edit-more-object-type"
    
    And "Module" should precede "Exam" for the query "#edit-more-object-type option"
    
    # AC5 Once an option has been selected from the drop-down menu, selecting the Add object button will add another Object to the Course Outline page and display it within the list of objects on the page.(defined in PRC-350) .
    Then I should see an "Add object" button
    # AC6 A Save outline button shall be available at all time
    Then I should see an "Save outline" button

  Scenario: AC7 Once the Save Outline button is selected, the system will display the following message:
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PRC-350 AC4"
    And I follow "Course outline"
    Then I select "Module" from "edit-more-object-type"
    And I press "Add object"
    And I press "Save outline"
    Then I should see the message containing "Updated course."

  Scenario: Order of groups on form
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PRC-350 AC4"
    And I follow "Course outline"
    Then I select "Module" from "edit-more-object-type"
    And I press "Add object"
    Then I click "Edit Settings"
    Then "Content" should precede "Title & description" for the query ".fieldset-legend"
    Then "Title & Description" should precede "Delete" for the query ".fieldset-legend"
    And I should see the text "Use existing content's title"

  @javascript
  Scenario: Title field enabled and required when Use existing title unchecked
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PRC-350 AC4"
    And I follow "Course outline"
    Then I select "Module" from "edit-more-object-type"
    And I press "Add object"
    Then I click "Edit Settings"
    Then the "Use existing content's title" checkbox should be checked