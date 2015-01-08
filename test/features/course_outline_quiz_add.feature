@api @course @assessment
Feature: PRC-552 Use created test for course exam
  As a Content Admin (Curator),
  I want to use a quiz I created in Assessments page as a Course Exam within my course,
  so that educators can evaluate their knowledge based of the course modules provided in my course.


  Scenario: PD Exam quizzes appear in list
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And "Quiz" nodes:
      | title       | author      |
      | Ny Untagged | @currentuid |
      | U1 Untagged | 1           |
    And "Quiz" nodes:
      | title       | author      | field_quiz_type            |
      | My Custom   | @currentuid | Custom Assessment          |
      | My PD Exam  | @currentuid | PD Exam                    |
      | My PRC Q    | @currentuid | PRC Released Practice Test |
      | U1 Custom   | 1           | Custom Assessment          |
      | U1 PD Exam  | 1           | PD Exam                    |
      | U1 PRC Q    | 1           | PRC Released Practice Test |

    And I am viewing my "PD Course" node with the title "PRC-350 AC4"
    And I follow "Course outline"
    And I select "Exam" from "edit-more-object-type"
    And I press "Add object"
    And I follow "Edit Settings"
    And I should see the text "PARCC members ONLY"
    And I should not see the text "My Untagged"
    And I should not see the text "U1 Untagged"
    And I should see the text "My Custom"
    And I should see the text "My PD Exam"
    And I should not see the text "My PRC Q"
    And I should not see the text "U1 Custom"
    And I should see the text "U1 PD Exam"
    And I should not see the text "U1 PRC Q"

#  Given: I just created a quiz in Create New Quiz page,
#  When: I get to the Edit Settings page for a Course Exam,
#  Then: I shall be able to select that test as my Course Exam.
#  Same as Edit Settings functionality for Modules, the user may select to change the test title for the selected course exam. That will not change the actual quiz's title in the system.
