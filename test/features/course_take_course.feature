@api @course
Feature: PRC-35 LMS: Take a Course
  As an educator,
  I want to take a PD course,
  so that I can view the related modules and develop my professional skill set.

  Acceptance Criteria
  AC1 In the Professional Development page, each course title shall be a link.
  AC2 At click, the course page opens. It contains the Course Title as the page header, followed by the Module Objectives and Course Length.
  AC3 The Modules associated with the selected course shall be listed in the defined order.
  AC4 Each module contains:
    Module Title (use display title field)
    Duration
    Status (all modules for this story shall have a Not Started status)
    Module Objectives: <Module Objectives>
  AC5 Selecting the Take Course action button will launch the actual module (future story after PRC-107)
  AC6 If any Course Exam is associated to the course, a button shall be available to launch that exam (in the defined order). The exam button label shall be the name of the object.
  AC7 Where there are more than 1 exam, they each appear at their order (the module attributes are displayed for modules only, The exam(s) appear in form of button with no additional attribute.
  AC8 When there is no exam for that course, only modules are listed (no exam button).

  Scenario: Take course
    Given "PD Module" nodes:
      | title       | field_course_objectives | status | uid | field_length_unit | field_length_quantity |
      | PD Module 1 | Obj1                    | 1      | 1   | day               | 4                     |
    And I am logged in as a user with the "Content Administrator (Curator)" role

    # TODO: Turn attaching modules to a course into step definitions
    And I am viewing my "PD Course" node with the title "PRC-35 Take Course"
    Then I follow "Edit"
    And I fill in "Course Objectives *" with "Take a Course"
    And I select the radio button "Public"
    And I check the box "Published"
    And I press "Save"
    And I follow "Course outline"
    Then I select "Module" from "edit-more-object-type"
    And I press "Add object"
    And I click "Edit Settings"
    And I fill in "PD Module 1 [nid:@nid[PD Module 1]]" for "Existing node"
    And I check the box "Use existing title"
    And I press "Update"
    Then I should see the text "PD Module 1"
    Then I press "Save outline"
    Then I should see the message containing "Updated course."

    And I am logged in as a user with the "Educator" role
    And I am on the homepage
    Then I click "Professional Development"
    Then I click "PRC-35 Take Course"
    Then I should see the heading "PRC-35 Take Course" in the "content" region
    And I should see the text "Course outline"
    And I should see the text "PD Module 1"
