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
#  AC6 An ADD button/link shall allow a user to add more distractor. At click, it displays an additional distractor container. When displayed, it is required.
#  AC7 An x link shall allow a user to remove a distractor
  AC8 The user shall define which answer choice is the correct answer. At least one distractor must be selected as correct answer
  AC9 A Save Draft button is available to save any changes to the item order/removal for that assessment. At click, the system stores the changes associated to that user.
#  AC10 If a user navigates away from the page without saving the changes, the system prompts the user to confirm.
  AC11 Permissions: All the above features are available to all roles, except for anonymous users (separate anonymous users stories PRC-526)

  Background: Create quiz we are adding items to
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

  Scenario: Links are present and in the right order
    Then I should see the text "Add Item"
    And I should see the link "Non-interactive Item (text only)"
    And I should see the link "Interactive Choice"
    And I should see the link "Short Answer"
    And "Non-interactive Item (text only)" should precede "Interactive Choice" for the query ".add-questions"
    And "Interactive Choice" should precede "Short Answer" for the query ".add-questions"

  Scenario: Adding a multiple choice item to a test
    When I click "Interactive Choice"
    Then I should see the text "Create Interactive Choice"
    And I should see the text "Item Title *"
    And I should see the text "Item Standard *"
    And I should see the text "Question"
    And I should see the text "(Item Stem)"
    And I should see the text "Answer Choice"
    And I should see the text "(Distractor)"

  Scenario: AC7 An x link shall allow a user to remove a distractor
    Then I click "Interactive Choice"
    Then I should see a "Remove" button
    When I fill in "edit-alternatives-0-answer-value" with "Answer 1"
    When I fill in "edit-alternatives-1-answer-value" with "Answer 2"
    Then I should see an "edit-alternatives-0-answer-value" field
    And I should see an "edit-alternatives-1-answer-value" field
    When I press "edit-alternatives-0-remove"
    And I should not see an "edit-alternatives-0-answer-value" field
    And I should see an "edit-alternatives-1-answer-value" field

  Scenario: AC6 An ADD button/link shall allow a user to add more distractor. At click, it displays an additional distractor container. When displayed, it is required.
    Then I click "Interactive Choice"
    When I fill in "edit-alternatives-0-answer-value" with "Answer 1"
    When I fill in "edit-alternatives-1-answer-value" with "Answer 2"
    Then I should see an "edit-alternatives-0-answer-value" field
    And I should see an "edit-alternatives-1-answer-value" field
    And I should not see an "edit-alternatives-2-answer-value" field
    And I press "ADD"
    And I should see an "edit-alternatives-0-answer-value" field
    And I should see an "edit-alternatives-1-answer-value" field
    And I should see an "edit-alternatives-2-answer-value" field

  Scenario: Field validation
    Then I click "Interactive Choice"
    When I press "Save"
    Then I should see the error message containing "Item Title field is required."
    Then I should see the error message containing "Question (Item Stem) field is required."
    Then I should see the error message containing "Item Order field is required."
    Then I should see the error message containing "You have not marked any alternatives as correct. If there are no correct alternatives you should allow multiple answers."

  Scenario: Remove a field, then add a field, removed field should not reappear
    Then I click "Interactive Choice"
    Then I should see a "Remove" button
    When I fill in "edit-alternatives-0-answer-value" with "Answer 1"
    When I fill in "edit-alternatives-1-answer-value" with "Answer 2"
    Then I should see an "edit-alternatives-0-answer-value" field
    And I should see an "edit-alternatives-1-answer-value" field
    When I press "edit-alternatives-1-remove"
    And I should see an "edit-alternatives-0-answer-value" field
    And I should not see an "edit-alternatives-1-answer-value" field
    And I press "ADD"
    And I should see an "edit-alternatives-0-answer-value" field
    And I should not see an "edit-alternatives-1-answer-value" field
    And I should see an "edit-alternatives-2-answer-value" field

  Scenario: Full cycle - save, check, change, remove, add
    Then I click "Interactive Choice"
    And I fill in "Item Order" with "O1"
    And I fill in "Item Title" with "T1"
    And I fill in "Question" with "Q1"
    When I fill in "edit-alternatives-0-answer-value" with "Alpha"
    When I fill in "edit-alternatives-1-answer-value" with "Beta"
    And I check the box "edit-alternatives-1-correct"
    Then I press "Save"
    And I follow "Edit" number "1"
    Then the "edit-alternatives-0-answer-value" field should contain "Alpha"
    Then the "edit-alternatives-1-answer-value" field should contain "Beta"
    When I press "ADD"
    And I fill in "edit-alternatives-2-answer-value" with "Gamma"
    And I press "Save"
    And I follow "Edit" number "1"
    Then the "edit-alternatives-0-answer-value" field should contain "Alpha"
    Then the "edit-alternatives-1-answer-value" field should contain "Beta"
    Then the "edit-alternatives-2-answer-value" field should contain "Gamma"
    And I press "edit-alternatives-1-remove"
    When I press "ADD"
    And I fill in "edit-alternatives-3-answer-value" with "Delta"
    And I press "Save"
    Then I should see the error message containing "You have not marked any alternatives as correct. If there are no correct alternatives you should allow multiple answers."
    Then I check the box "edit-alternatives-3-correct"
    And I press "Save"
    And I follow "Edit" number "1"
    Then the "edit-alternatives-0-answer-value" field should contain "Alpha"
    Then the "edit-alternatives-1-answer-value" field should contain "Gamma"
    Then the "edit-alternatives-2-answer-value" field should contain "Delta"
