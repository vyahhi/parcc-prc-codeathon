@api @course @assessment
Feature: PRC-476 Take Course Exam
  As an educator,
  I want to take a course exam when accessing a PD course,
  so that I can evaluate my learning from modules preceding the exam.

  @javascript
  Scenario: Another educator should be able to take a user's PD Exam
    Given I am logged in as a user with the "PRC Admin" role
    Given "PD Module" nodes:
      | title       | field_course_objectives | status | uid | field_length | language |
      | PD Module 1 | Obj1                    | 1      | 1   | 4 day        | und      |
    And "Subject" terms:
      | name  |
      | Subj1 |
    And "Assessment" nodes:
      | title        | field_subject | field_quiz_type | author      | field_grade_level_unlimited |
      | PRC-476 Exam | Subj1         | PD Exam         | @currentuid | 1st Grade                   |
    And I visit the last node created
    And I press "Add Item"
    And I click "Non-interactive Item (text only)"
    And I fill in "edit-body-und-0-value" with "PRC-490 Directions 1 And these are the Body Body Directions Directions"
    And I fill in "Title" with "PRC-527 Directions 1"
    And I press "Save"
    # Add the first question
    And I press "Add Item"
    Then I click "Interactive Choice"
    And I fill in "edit-body-und-0-value" with "PRC-527 Multi Multi Question Question<p>Paragraph</p>"
    And I fill in "Title" with "PRC-527 Multi"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "edit-alternatives-0-answer-value" with "Answer Wrong"
    And I fill in "edit-alternatives-1-answer-value" with "Answer Correct"
    And I check the box "edit-alternatives-1-correct"
    And I check the box "1st Grade"
    And I press "Save"
    # Add the second question
    And I press "Add Item"
    Then I click "Interactive Choice"
    And I fill in "edit-body-und-0-value" with "PRC-527 Multi Multi Question Question<p>Paragraph</p>"
    And I fill in "Title" with "PRC-527 Two"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "edit-alternatives-0-answer-value" with "Answer Wrong"
    And I fill in "edit-alternatives-1-answer-value" with "Answer Correct"
    And I check the box "edit-alternatives-1-correct"
    And I check the box "1st Grade"
    And I press "Save"

    # TODO: Turn attaching modules to a course into step definitions
    And I am on "prc/admin/admin-course"
    When I click "Add course"
    Then I should see the heading "Create Course" in the "sub_header" region
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

    When I am logged in as a user with the "Educator" role
      #Specifing desktop for headless testing (oz's default is tablet)
    And I am browsing using a "desktop"
    And I am on the homepage
    Then I click "Professional Learning"
    Then I click "PRC-35 Take Course"
    Then I click "Take course"
    And I should see the message containing "Your enrollment in this course has been recorded."
    And I should not see the link "PRC-476 Exam"
    But I should see the text "PRC-476 Exam"
    And I click "PD Module 1"
    Then I click "Professional Learning"
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
    Then I click "Professional Learning"
    Then I click "PRC-35 Take Course"
    And I should not see the link "PRC-476 Exam"


  @javascript
  Scenario: Another educator should NOT be able to take a user's Custom Assessment Exam
    Given I am logged in as a user with the "PRC Admin" role
    Given "PD Module" nodes:
      | title       | field_course_objectives | status | uid | field_length | language |
      | PD Module 1 | Obj1                    | 1      | @currentuid   | 4 day        | und      |
    And "Subject" terms:
      | name  |
      | Subj1 |
    And "Assessment" nodes:
      | title        | field_subject | field_quiz_type   | uid      | field_grade_level_unlimited |
      | PRC-476 Exam | Subj1         | Custom Assessment | @currentuid | 1st Grade                   |
    And I visit the last node created
    And I press "Add Item"
    Then I click "Non-interactive Item (text only)"
    And I fill in "edit-body-und-0-value" with "PRC-490 Directions 1 And these are the Body Body Directions Directions"
    And I fill in "Title" with "PRC-527 Directions 1"
    And I press "Save"
    # Add the first question
    And I press "Add Item"
    Then I click "Interactive Choice"
    And I fill in "edit-body-und-0-value" with "PRC-527 Multi Multi Question Question<p>Paragraph</p>"
    And I fill in "Title" with "PRC-527 Multi"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "edit-alternatives-0-answer-value" with "Answer Wrong"
    And I fill in "edit-alternatives-1-answer-value" with "Answer Correct"
    And I check the box "edit-alternatives-1-correct"
    And I check the box "1st Grade"
    And I press "Save"
    # Add the second question
    And I press "Add Item"
    Then I click "Interactive Choice"
    And I fill in "edit-body-und-0-value" with "PRC-527 Multi Multi Question Question<p>Paragraph</p>"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "Title" with "PRC-527 Two"
    And I fill in "edit-alternatives-0-answer-value" with "Answer Wrong"
    And I fill in "edit-alternatives-1-answer-value" with "Answer Correct"
    And I check the box "edit-alternatives-1-correct"
    And I check the box "1st Grade"
    And I press "Save"

    # TODO: Turn attaching modules to a course into step definitions
    And I am on "prc/admin/admin-course"
    When I click "Add course"
    Then I should see the heading "Create Course" in the "sub_header" region
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
    And I should not see the text "PRC-476 Exam"
