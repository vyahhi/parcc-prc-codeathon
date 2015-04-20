@api @diglib @like
Feature: PRC-554 Social Media: Like an Assessment
  As an educator, I want to rate an assessment and view others' rating for that content, so that good content can be spread out among my colleagues quickly.
  BACKGROUND: This story provides the same functionality as the story PRC-39, but for assessment type of content.
  Acceptance Criteria
  In the Assessments page where courses are displayed, a link/icon shall display "Like" and the number of users who clicked that link, like "Like (0)".
  At click, the system increments the number and changes label, like “Undo (3)”.
  Once “Undo” label is clicked, the system decrements the number and changes label back, like “Like (2)”.
  Only PARCC-Released content can be rated. The user-created quizzes (and items) cannot be seen by others, so no need to be rated.

  Scenario: Like link in Assessment view
    Given "Subject" terms:
      | name  |
      | subj1 |
    And "Grade Level" terms:
      | name      |
      | Grade 554 |
    And "Quiz" nodes:
      | title        | field_subject | field_grade_level | field_quiz_type                    |
      | PRC-554 View | subj1         | Grade 554         | PARCC-Released Practice Assessment |
    And I am logged in as a user with the "Educator" role
    And I am on "assessments"
    Then I should see the link "PRC-554 View"
    And I should see the link "Like (0)"
    And I should not see the text "Undo"
    When I click "Like (0)"
    Then I should see the link "Undo (1)"
    And I should not see the text "Like"

    Then I am an anonymous user
    Then I am logged in as a user with the "Educator" role
    And I am on "assessments"
    Then I should see the link "PRC-554 View"
    And I should see the link "Like (1)"
    And I should not see the text "Undo"
    When I click "Like (1)"
    Then I should see the link "Undo (2)"
    And I should not see the text "Like"
    Then I click "Undo (2)"
    And I should not see the text "Undo"
    And I should see the link "Like (1)"

  Scenario: Like link on Assessment full view
    Given "Subject" terms:
      | name  |
      | subj1 |
    And "Grade Level" terms:
      | name      |
      | Grade 554 |
    And "Quiz" nodes:
      | title        | field_subject | field_grade_level | field_quiz_type                    |
      | PRC-554 View | subj1         | Grade 554         | PARCC-Released Practice Assessment |
    And I am logged in as a user with the "Educator" role
    And I am on "assessments"
    And I click "PRC-554 View"
    And I should see the link "Like (0)"
    And I should not see the text "Undo"
    When I click "Like (0)"
    Then I should see the link "Undo (1)"
    And I should not see the text "Like"

  Scenario: PRC-910 User can't Like own content
    Given I am logged in as a user with the "Educator" role
    And "Subject" terms:
      | name  |
      | subj1 |
    And "Grade Level" terms:
      | name      |
      | Grade 554 |
    And "Quiz" nodes:
      | title        | field_subject | field_grade_level | field_quiz_type                    | uid         |
      | PRC-554 View | subj1         | Grade 554         | PARCC-Released Practice Assessment | @currentuid |
    And I am logged in as a user with the "Educator" role
    And I am on "assessments"
    And I click "PRC-554 View"
    And I should not see the link "Like (0)"
    And I should not see the text "Undo"
