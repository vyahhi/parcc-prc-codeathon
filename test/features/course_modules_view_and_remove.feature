@api @course
Feature: PRC-350 Admin: View Course
  As a Content Admin,
  I want to view existing modules and exams within an existing course,
  so that I can update them when needed.

#  also tests PRC-361
#  Admin: Select Module Content
#  As a Content Admin,
#  I want to select an existing content as a PD course module,
#  so that the video modules created and ingested into PRC for this purpose can be accessed by the course defined audience.
#
#  Acceptance Criteria
#  AC1 In the Course Outline tab for a selected course, an Edit Settings link shall be available for each course object.
#  AC2 At click, a new page Settings opens.
#  AC3 A Module drop down menu allows a user to start typing an existing content name
#  AC4 The system provides a list of available content based on entered characters (auto-complete list)
#  AC5 A Module Title textbox allows the user to define a different display title from its original title. Once a content is selected, the Title textbox is populated with the current title of the content although the user can change it. Changing the title here will NOT change the content's original title
#  AC7 A Save button allows the user to associate the selected content as the content of this module.

Scenario Outline: AC1 When an existing course is selected, in addition to the existing tabs, a Course Outline tab shall be available to the user.
          AC2 The following roles are permitted to access this page:
          Content Administrator (Curator)
          PRC Admin
  Given I am logged in as a user with the "<role>" role
  And I am viewing my "PD Course" node with the title "PRC-350 AC1"
  Then I should see the link "Course outline"
  Examples:
  | role                            |
  | Content Administrator (Curator) |
  | PRC Admin                       |

  Scenario: AC4 When there are no objects in the course, the system shall display:
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PRC-350 AC4"
    And I follow "Course outline"
    Then I should see the text "No objects are assigned to this course."

  #  AC3 At click, the system shall list the objects that have already been added to the course.

  Scenario: Use existing title
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Module" node with the title "PD Module PRC-350 AC5"
    And I am viewing my "PD Course" node with the title "PD Course PRC-350 AC4"
    And I follow "Course outline"
    And I select "Module" from "edit-more-object-type"
    And I press "Add object"
    Then I should see the text "Changes to this course have not yet been saved."
    # A link or button for Edit Settings (story PRC-361 and PRC-351)
    And I click "Edit Settings"
    And I fill in "PD Module PRC-350 AC5 [nid:@nid[PD Module PRC-350 AC5]]" for "Existing node"
    And I check the box "Use existing content's title"
    And I press "Update"
    # Object Name (examples: Module 1: Getting Started or End of Course Exam )
    Then I should see the text "PD Module PRC-350 AC5"
    Then I press "Save outline"
    # The ability to move the order of objects within the course by drag & drop handle by the module title
    # We are not Javascripting the functionality of Drupal's drag handles.
    #  A link or button for Remove (story PRC-362)
    Then I click "Edit Settings"
    Then I check the box "Delete"
    Then I should not see the text "Also delete the referenced content."
    And I press "Update"
    Then I press "Save outline"
    And I should not see the text "PD Module PRC-350 AC5"

  Scenario: Enter a new title
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Module" node with the title "PD Module PRC-350 AC5"
    And I am viewing my "PD Course" node with the title "PD Course PRC-350 AC4"
    And I follow "Course outline"
    And I select "Module" from "edit-more-object-type"
    And I press "Add object"
    Then I should see the text "Changes to this course have not yet been saved."
    # A link or button for Edit Settings (story PRC-361 and PRC-351)
    And I click "Edit Settings"
    And I fill in "PD Module PRC-350 AC5 [nid:@nid[PD Module PRC-350 AC5]]" for "Existing node"
    And the "Use existing content's title" checkbox should be checked
    And I uncheck the box "Use existing content's title"
    And I fill in "Module Title" with "Step 1: New Module"
    And I press "Update"
    # Object Name (examples: Module 1: Getting Started or End of Course Exam )
    Then I should see the text "Step 1: New Module"
    But I should not see the text "PD Module PRC-350 AC5"
    Then I press "Save outline"
    # The ability to move the order of objects within the course by drag & drop handle by the module title
    # We are not Javascripting the functionality of Drupal's drag handles.
    #  A link or button for Remove (story PRC-362)
    Then I click "Edit Settings"
    Then I check the box "Delete"
    Then I should not see the text "Also delete the referenced content."
    And I press "Update"
    Then I press "Save outline"
    And I should not see the text "PD Module PRC-350 AC5"

