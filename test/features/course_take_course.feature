@api @course
Feature: PRC-35 LMS: Take a Course
  As an educator,
  I want to take a PD course,
  so that I can view the related modules and develop my professional skill set.

  Scenario: Take course
    Given "PD Module" nodes:
      | title       | field_course_objectives | status | uid | field_length | language |
      | PD Module 1 | Obj1                    | 1      | 1   | 4 day        | und      |
    And I am logged in as a user with the "Content Administrator (Curator)" role

    # TODO: Turn attaching modules to a course into step definitions
    And I am on "admin-course"
    When I click "Add course"
    Then I should see the heading "Create Course" in the "content" region
    And I fill in "Course Title *" with "PRC-35 Take Course"
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

    #AC1 In the Professional Development page, each course title shall be a link.
    Then I click "PRC-35 Take Course"
    #AC2 At click, the course page opens. It contains the Course Title as the page header, followed by the Module Objectives and Course Length.
    Then I should see the heading "PRC-35 Take Course" in the "content" region
    And I should see the text "Course outline"
    #AC3 The Modules associated with the selected course shall be listed in the defined order.
    #AC4 Each module contains:
    #  Module Title (use display title field)
    And I should see the text "PD Module 1"
    #  Module Objectives: <Module Objectives>
    And I should see the text "Obj1"
    #  Duration
    And I should see the text "(4 day)"
    #  Status (all modules for this story shall have a Not Started status)
    And I should see the text "Not started"
    And I should not see the text "Complete"

    Then I click "Take course"
    And I should see the message containing "Your enrollment in this course has been recorded."
    And I should not see the text "Outline not provided."
    #AC8 When there is no exam for that course, only modules are listed (no exam button).

    #AC5 Selecting the Take Course action button will launch the actual module (future story after PRC-107)
    And I click "PD Module 1"
    And I should see the heading "PD Module 1" in the "content" region
    And I should see the text "Obj1"

    Then I click "Professional Development"
    Then I click "PRC-35 Take Course"
    And I should see the text "Complete"
    And I should not see the text "Not started"

  Scenario: Take course with exam
    Given "PD Module" nodes:
      | title       | field_course_objectives | status | uid | field_length_quantity | field_length_unit | language |
      | PD Module 2 | Obj2                    | 1      | 1   | 5                     | hour              | und      |
    And I am logged in as a user with the "Content Administrator (Curator)" role

    # TODO: Turn attaching modules to a course into step definitions
    And I am on "admin-course"
    When I click "Add course"
    Then I should see the heading "Create Course" in the "content" region
    And I fill in "Course Title *" with "PRC-35 Take Course"
    And I fill in "Course Objectives *" with "Take a Course"
    And I select the radio button "Public"
    And I check the box "Published"
    And I press "Save"

    And I follow "Course outline"