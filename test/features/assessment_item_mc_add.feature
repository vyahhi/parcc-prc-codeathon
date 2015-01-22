@api @assessment @mc
Feature: PRC-547 Add New Item to a Quiz
  As an educator,
  I want to add an item when creating a new to a quiz,
  so that I can utilize my customized quiz with my classroom later.

  BACKGROUND: This story is a branch of PRC-521 and contains the Add Item portion only.
  Acceptance Criteria
#  AC1 In the Assessment Details page where items are displayed (implemented in PRC-490), add a new _Add Item button/link.
#  AC2 At click, it provides the following options to select before getting to the actual item authoring part (for this story, only the 2nd options is clickable):
#    Non-interactive Item (text only)
#    Interactive Choice
#    Short Answer
#  AC3 When the user clicks the Interactive Choice (single selection) option, a set of attributes for an interactive choice item appears, defined below.
#  AC4 Item Metadata: The following attributes shall be available for the user to define as item metadata:
#  Item Title- Required, String(255)
#  Item Standard: Required (at least 1)- more than 1 standard may be selected- options are the same as what is implemented for content and courses so far
#  AC5 Item attributes:
#    Question (Item Stem)- Required (Drupal has no size limit)
#    Answer Choice (Distractor)- Required (at least 2 are required) (Drupal has no size limit)
  AC6 An ADD button/link shall allow a user to add more distractor. At click, it displays an additional distractor container. When displayed, it is required.
  AC7 An x link shall allow a user to remove a distractor
  AC8 The user shall define which answer choice is the correct answer. At least one distractor should be selected as correct answer
  AC9 A Save Draft button is available to save any changes to the item order/removal for that assessment. At click, the system stores the changes associated to that user.
  AC10 If a user navigates away from the page without saving the changes, the system prompts the user to confirm.
  AC11 Permissions: All the above features are available to all roles, except for anonymous users (separate anonymous users stories PRC-526)

  Scenario: Links are present and in the right order
    Given "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Grade Level" terms:
      | name      |
      | Grade 547 |
    And "Quiz" nodes:
      | title        | field_subject | field_grade_level | field_quiz_type            |
      | PRC-547 View | subj1, subj2  | Grade 547         | PRC Released Practice Test |
    And I am logged in as a user with the "PRC Admin" role
    When I visit the last node created
    Then I should see the text "Add Item"
    And I should see the link "Non-interactive Item (text only)"
    And I should see the link "Interactive Choice"
    And I should see the link "Short Answer"
    And "Non-interactive Item (text only)" should precede "Interactive Choice" for the query ".add-questions"
    And "Interactive Choice" should precede "Short Answer" for the query ".add-questions"

  Scenario: Adding a multiple choice item to a test
    Given "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Grade Level" terms:
      | name      |
      | Grade 547 |
    And "Quiz" nodes:
      | title        | field_subject | field_grade_level | field_quiz_type            |
      | PRC-547 View | subj1, subj2  | Grade 547         | PRC Released Practice Test |
    And I am logged in as a user with the "Educator" role
    When I visit the last node created
    When I click "Interactive Choice"
    Then I should see the text "Create Interactive Choice"
    And I should see the text "Item Title *"
    And I should see the text "Item Standard *"
    And I should see the text "Question"
    And I should see the text "(Item Stem)"
    And I should see the text "Answer Choice"
    And I should see the text "(Distractor)"