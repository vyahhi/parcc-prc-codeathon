@api
Feature: PRC-350 Admin: View Course
  As a Content Admin,
  I want to view existing modules and exams within an existing course,
  so that I can update them when needed.

#  Acceptance Criteria
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


#  AC3 At click, the system shall list the objects that have already been added to the course.

  Scenario: AC4 When there are no objects in the course, the system shall display:
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PRC-350 AC4"
    And I follow "Course outline"
    Then I should see the text "No objects are assigned to this course."

  @javascript
  Scenario: AC5 List of objects contain:
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Module" node with the title "PD Module PRC-350 AC5"
    And I am viewing my "PD Course" node with the title "PD Course PRC-350 AC4"
    And I follow "Course outline"
    And I select "Module" from "edit-more-object-type"
    And I press "Add object"
    Then I should see the text "Changes to this course have not yet been saved."
    And I click "Edit Settings"
    And I fill in "PD Module PRC-350 AC5 [nid:@nid[PD Module PRC-350 AC5]]" for "Existing node"
    Then I break
    And I check the box "Use existing title"
    And I press "Update"
    Then I should see the text "PD Module PRC-350 AC5"
#  Object Name (examples: Module 1: Getting Started or End of Course Exam )
#  A link or button for Edit Settings (story PRC-361 and PRC-351)
#  A link or button for Remove (story PRC-362)
#  The ability to move the order of objects within the course by drag & drop handle by the module title
#  Testing the pair of dropdown/btn is not part of this story (it will be in PRC-360)