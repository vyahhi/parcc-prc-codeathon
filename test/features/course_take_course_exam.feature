@api @course @assessment @javascript
Feature: PRC-476 Take Course Exam
  As an educator,
  I want to take a course exam when accessing a PD course,
  so that I can evaluate my learning from modules preceding the exam.

  AC1 In the Take Course page that an educator views the course modules, the system shall also include the course exams in the defined order.
  AC2 For course exams, ONLY the exam Title shall be available (Contrary to the modules, the other attributes, such as: duration, objectives, and status are NOT displayed for course exam objects).
  AC3 The course exam title shall appear in form of link as long as the user has not successfully completed the course exam.
  AC4 At click, it opens the course exam where questions are available to the user to respond.
  AC5 The user shall navigate through exam questions and the system shall store user's responses as entered into the system (Drupal built-in functionality).
  AC6 Once the user clicks the Submit Exam button, the system shall redirect the user to the feedback page after prompting the user to confirm the submission.
  AC7 The feedback page contains the following components:
  Page Title-
  Result Summary-
  Action Button-
  AC8 Passed and Failed case scenarios have their own verbiage (see examples below):
  PASSED Verbiage:
  Score: 86.
  Congratulations! You successfully passed the <exam name> exam.
  FAILED Verbiage:
  Score: 64.
  Sorry. You did not reach the required score to pass the <exam name> exam. Please try again later.
  You may revisit the course modules and retake the course exam when ready.
  AC9 The modules shall be available for revisiting at any time regardless the exam results.
  AC10 The exam shall be available for retaking UNTIL the user successfully passes the exam. After then, the Exam link shall be disabled.
  AC11 A course exam cannot be paused/resumed. Once exited, the scores are lost, and the user has to start over.
  AC12 Clicking the Go Back button shall redirect the user back to:
  The Professional Development page if this is the last object of the course.
  The Take Course page if there are other objects after this exam.

  Background: Set up the course and quiz
    Given I am logged in as a user with the "administrator" role
    Given I have no "PD Module" nodes
    And I have no "PD Course" nodes
    And I have no "Quiz" nodes
    Given "PD Module" nodes:
      | title       | field_course_objectives | status | uid | field_length | language |
      | PD Module 1 | Obj1                    | 1      | 1   | 4 day        | und      |
    And "Subject" terms:
      | name  |
      | Subj1 |
    And "Grade Level" terms:
      | name    |
      | Grade 1 |
    And "Quiz" nodes:
      | title        | field_subject | field_quiz_type | author      | field_grade_level |
      | PRC-476 Exam | Subj1         | PD Exam         | @currentuid | Grade 1           |
    And I visit the last node created

    And I click "Quiz"
    Then I click "Manage questions"
    Then I click "Create new question"
    Then I click "Quiz directions"
    And I fill in "edit-body-und-0-value" with "PRC-490 Directions 1 And these are the Body Body Directions Directions"
    And I fill in "Title" with "PRC-527 Directions 1"
    And I fill in "Item Order" with "D1"
    And I press "Save"

    # Add the first question
    Then I click "Create new question"
    Then I click "Multiple choice question"
    And I fill in "edit-body-und-0-value" with "PRC-527 Multi Multi Question Question<p>Paragraph</p>"
    And I fill in "Item Order" with "Q2"
    And I fill in "Title" with "PRC-527 Multi"
    And I select "Common Core Mathematics" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "edit-alternatives-0-answer-value" with "Answer Wrong"
    And I fill in "edit-alternatives-1-answer-value" with "Answer Correct"
    And I check the box "edit-alternatives-1-correct"
    And I press "Save"

    # Add the second question
    Then I click "Create new question"
    Then I click "Multiple choice question"
    And I fill in "edit-body-und-0-value" with "PRC-527 Multi Multi Question Question<p>Paragraph</p>"
    And I fill in "Item Order" with "Q3"
    And I fill in "Title" with "PRC-527 Two"
    And I select "Common Core Mathematics" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "edit-alternatives-0-answer-value" with "Answer Wrong"
    And I fill in "edit-alternatives-1-answer-value" with "Answer Correct"
    And I check the box "edit-alternatives-1-correct"
    And I press "Save"

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
    And I select "PD Module 1" from "Existing node"
    And I check the box "Use existing content's title"
    And I press "Update"
    Then I should see the text "PD Module 1"

    Then I select "Exam" from "edit-more-object-type"
    And I press "Add object"

    And I follow "Edit Settings" number "1"
    And I select "PRC-476 Exam" from "Existing node"
    And I fill in "Module Title" with "PRC-476 Exam"
    And I press "Update"
    And I should see the text "PRC-476 Exam"

    Then I press "Save outline"
    Then I should see the message containing "Updated course."

  Scenario: Course with exam step - Pass
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    Then I click "Professional Development"
    Then I click "PRC-35 Take Course"
    Then I click "Take course"
    And I should see the message containing "Your enrollment in this course has been recorded."
    And I should not see the link "PRC-476 Exam"
    But I should see the text "PRC-476 Exam"
    And I click "PD Module 1"
    Then I click "Professional Development"
    Then I click "PRC-35 Take Course"
    And I should see the text "Complete"
    And I should not see the text "Not started"
    And I should see the link "PRC-476 Exam"
    And "PD Module 1" should precede "PRC-476 Exam" for the query "a"
    Then I click "PRC-476 Exam"
    Then I press "Next"
    Then I check radio button number "1"
    Then I press "Next"
    Then I check radio button number "1"
    Then I press "Finish"
    Then I should see the text "Score: 100."
    And I should see the text "Congratulations! You successfully passed the PRC-476 Exam exam."
    Then I click "Professional Development"
    Then I click "PRC-35 Take Course"
    And I should not see the link "PRC-476 Exam"

  Scenario: Course with exam step - Fail
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    Then I click "Professional Development"
    Then I click "PRC-35 Take Course"
    Then I click "Take course"
    And I should see the message containing "Your enrollment in this course has been recorded."
    And I should not see the link "PRC-476 Exam"
    But I should see the text "PRC-476 Exam"
    And I click "PD Module 1"
    Then I click "Professional Development"
    Then I click "PRC-35 Take Course"
    And I should see the text "Complete"
    And I should not see the text "Not started"
    And I should see the link "PRC-476 Exam"
    And "PD Module 1" should precede "PRC-476 Exam" for the query "a"
    Then I click "PRC-476 Exam"
    Then I press "Next"
    Then I check radio button number "1"
    Then I press "Next"
    Then I check radio button number "0"
    Then I press "Finish"
    Then I should see the text "Score: 50."
    And I should see the text "Sorry. You did not reach the required score to pass the PRC-476 Exam exam. Please try again later."
    And I should see the text "You may revisit the course modules and retake the course exam when ready."
    Then I click "Professional Development"
    Then I click "PRC-35 Take Course"
    And I should see the link "PRC-476 Exam"

  Scenario: Course with exam step - Leave and Restart
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    Then I click "Professional Development"
    Then I click "PRC-35 Take Course"
    Then I click "Take course"
    And I should see the message containing "Your enrollment in this course has been recorded."
    And I should not see the link "PRC-476 Exam"
    But I should see the text "PRC-476 Exam"
    And I click "PD Module 1"
    Then I click "Professional Development"
    Then I click "PRC-35 Take Course"
    And I should see the text "Complete"
    And I should not see the text "Not started"
    And I should see the link "PRC-476 Exam"
    And "PD Module 1" should precede "PRC-476 Exam" for the query "a"
    Then I click "PRC-476 Exam"
    And I should see the text "Page 1 of 3"
    Then I press "Next"
    Then I check radio button number "1"
    Then I press "Next"
    Then I click "Professional Development"
    Then I click "PRC-35 Take Course"
    And I should see the link "PRC-476 Exam"
    When I click "PRC-476 Exam"
    And I should see the text "Page 1 of 3"