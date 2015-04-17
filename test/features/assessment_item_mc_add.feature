@api @assessment @mc
Feature: PRC-547 Add New Item to a Quiz
  As an educator,
  I want to add an item when creating a new to a quiz,
  so that I can utilize my customized quiz with my classroom later.

  BACKGROUND: This story is a branch of PRC-521 and contains the Add Item portion only.
  Acceptance Criteria
#  Given I am logged in as a user with the “Educator” role
#  And I am viewing an assessment (implemented in PRC-490),
#  When I click “Add Item”
#  These links appear
#  •	Non-interactive Item (text only)
#  •	Interactive Choice
#  •	Short Answer
#  When the user clicks the Interactive Choice option, a set of attributes for an interactive choice item appears, defined below.
#  Item Metadata: The following attributes shall be available for the user to define as item metadata:
#  Item Title- Required, String(255)
#  Item Standard: Required (at least 1)- more than 1 standard may be selected- options are the same as what is implemented for content and courses so far
#  Item attributes:
#  Question (Item Stem)- Required (Drupal has no size limit)
#  Answer Choice (Distractor)- Required (at least 2 are required) (Drupal has no size limit)
#  A Multiple correct answers checkbox appears above Answer Choice (Distractor) section and is unchecked by default. When Multiple correct answers is checked, the system will allow any number of correct answers to be checked, including 0 or 1.
#  An ADD button/link shall allow a user to add more distractor. At click, it displays an additional distractor container.
#  A Remove button shall allow a user to remove a distractor
#  The user shall define which answer choice is the correct answer. At least one distractor must be selected as correct answer when Multiple correct answers is checked.
#  A Save Draft button is available to save any changes to the item order/removal for that assessment. At click, the system stores the changes associated to that user.
#  If a user navigates away from the page without saving the changes, the system prompts the user to confirm.
#  If the user clicks Save Draft button and Item Title is blank, a validation error message is displayed, saying "Item Title field is required."
#  If the user clicks Save Draft button and Question (Item Stem) is blank, a validation error message is displayed, saying "Question (Item Stem) field is required."
#  If the user clicks Save Draft button and all Item Standard dropdowns are "- None -", a validation error message is displayed, saying "At least one Item Standard is required."
#  If the user clicks Save Draft button, Multiple correct answers is not checked, and all Correct check boxes are unchecked, a validation error message is displayed, saying "One correct answer must be selected. If all answer choices (distractors) are incorrect, check the Multiple correct answers box."
#  If the user clicks Save Draft button, Multiple correct answers is not checked, and the Correct check box is selected for more than one distractor, a validation error message is displayed, saying "One correct answer must be selected. To select multiple correct answers, check the Multiple correct answers box."
#  If the user clicks Save Draft button, and the form contains any blank distractors (with Correct checkbox unchecked and no data in answer field) that precede any non-blank distractors (with Correct checkbox unchecked and/or data in answer field), a validation error message is displayed saying, "All answer choices (distractors) require an Answer. Please enter an Answer or click the Remove button to remove the answer choice (distractor)."
#  If the user clicks Save Draft button, and the form contains any blank distractors (with both Correct checkbox unchecked and no data in answer field) that do not precede any non-blank distractors (with Correct checkbox unchecked and/or data in answer field), the form is submitted blank distractors are ignored and do not appear in the saved draft.
#  If the user clicks Save Draft button, and fewer than two distractors are complete, a validation error message is displayed saying, "At least two answer choices (distractors) are required."
#  Permissions: All the above features are available to all roles, except for anonymous users (separate anonymous users stories PRC-526)

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
    And I am logged in as a user with the "Educator" role
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

  Scenario: AC5 A Multiple correct answers checkbox appears above Answer Choice (Distractor) section and is unchecked by default.
    When I click "Interactive Choice"
    Then I should see the checkbox "Multiple correct answers"
    And the "Multiple correct answers" checkbox should not be checked

  Scenario: If the user clicks Save Draft button, Multiple correct answers is not checked, and all Correct check boxes are unchecked, a validation error message is displayed, saying "One correct answer must be selected. If all answer choices (distractors) are incorrect, check the Multiple correct answers box."
    When I click "Interactive Choice"
    And the "Multiple correct answers" checkbox should not be checked
    When I press "Submit"
    Then I should see the error message containing "One correct answer must be selected. If all answer choices (distractors) are incorrect, check the Multiple correct answers box."

  Scenario: AC5 When Multiple correct answers is checked, no message on 0 selected.
    When I click "Interactive Choice"
    And the "Multiple correct answers" checkbox should not be checked
    And I check "Multiple correct answers"
    When I press "Submit"
    Then I should not see the error message containing "One correct answer must be selected. If all answer choices (distractors) are incorrect, check the Multiple correct answers box."

  Scenario: If the user clicks Save Draft button, Multiple correct answers is not checked, and the Correct check box is selected for more than one distractor, a validation error message is displayed, saying "One correct answer must be selected. To select multiple correct answers, check the Multiple correct answers box."
    When I click "Interactive Choice"
    And the "Multiple correct answers" checkbox should not be checked
    And I check the box "edit-alternatives-0-correct"
    And I check the box "edit-alternatives-1-correct"
    Then I press "Submit"
    Then I should see the error message containing "One correct answer must be selected. If all answer choices (distractors) are incorrect, check the Multiple correct answers box."

  Scenario: AC7 A Remove button shall allow a user to remove a distractor
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
    When I press "Submit"
    Then I should see the error message containing "Item Title field is required."
    Then I should see the error message containing "Question (Item Stem) field is required."
    Then I should see the error message containing "At least one Item Standard is required."
    Then I should see the error message containing "One correct answer must be selected. If all answer choices (distractors) are incorrect, check the Multiple correct answers box."

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

  @javascript
  Scenario: Full cycle - save, check, change, remove, add
    When I click "Add Item"
    Then I click "Interactive Choice"
    And I fill in "Item Title" with "T1"
    And I fill in "Question" with "Q1"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    When I fill in "edit-alternatives-0-answer-value" with "Alpha"
    When I fill in "edit-alternatives-1-answer-value" with "Beta"
    And I check the box "edit-alternatives-1-correct"
    And I select "1st Grade" from "Grade Level"
    Then I press "Submit"
    And I follow "Edit"
    Then the "edit-alternatives-0-answer-value" field should contain "Alpha"
    Then the "edit-alternatives-1-answer-value" field should contain "Beta"
    When I press "ADD"
    And I fill in "edit-alternatives-2-answer-value" with "Gamma"
    And I press "Submit"
    And I follow "Edit"
    Then the "edit-alternatives-0-answer-value" field should contain "Alpha"
    Then the "edit-alternatives-1-answer-value" field should contain "Beta"
    Then the "edit-alternatives-2-answer-value" field should contain "Gamma"
    And I press "edit-alternatives-1-remove"
    When I press "ADD"
    And I fill in "edit-alternatives-3-answer-value" with "Delta"
    And I press "Submit"
    Then I should see the error message containing "One correct answer must be selected. If all answer choices (distractors) are incorrect, check the Multiple correct answers box."
    Then I check the box "edit-alternatives-3-correct"
    And I press "Submit"
    And I follow "Edit"
    Then the "edit-alternatives-0-answer-value" field should contain "Alpha"
    Then the "edit-alternatives-1-answer-value" field should contain "Gamma"
    Then the "edit-alternatives-2-answer-value" field should contain "Delta"

  @javascript
  Scenario: If the user clicks Submit button, and the form contains any blank distractors (with both Correct checkbox unchecked and no data in answer field) that do not precede any non-blank distractors (with Correct checkbox unchecked and/or data in answer field), the form is submitted blank distractors are ignored and do not appear in the saved draft.
    When I click "Add Item"
    Then I click "Interactive Choice"
    And I fill in "Item Title" with "T1"
    And I fill in "Question" with "Q1"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    When I fill in "edit-alternatives-0-answer-value" with "Alpha"
    When I fill in "edit-alternatives-1-answer-value" with "Beta"
    Then I check the box "edit-alternatives-1-correct"
    When I press "ADD"
    When I press "ADD"
    When I press "ADD"
    Then I should see a "edit-alternatives-2-answer-value--3" field
    Then I should see a "edit-alternatives-3-answer-value--2" field
    Then I should see a "edit-alternatives-4-answer-value" field
    And I select "1st Grade" from "Grade Level"
    And I press "Submit"
    And I follow "Edit"
    Then the "edit-alternatives-0-answer-value" field should contain "Alpha"
    Then the "edit-alternatives-1-answer-value" field should contain "Beta"
    Then I should not see a "edit-alternatives-2-answer-value" field
    Then I should not see a "edit-alternatives-3-answer-value" field
    Then I should not see a "edit-alternatives-4-answer-value" field

  Scenario: If the user clicks Submit button, and the form contains any blank distractors (with Correct checkbox unchecked and no data in answer field) that precede any non-blank distractors (with Correct checkbox unchecked and/or data in answer field), a validation error message is displayed saying, "All answer choices (distractors) require an Answer. Please enter an Answer or click the Remove button to remove the answer choice (distractor)."
    Then I click "Interactive Choice"
    And I fill in "Item Title" with "T1"
    And I fill in "Question" with "Q1"
    # Skip alternatives-0
    When I fill in "edit-alternatives-1-answer-value" with "Alpha"
    Then I check the box "edit-alternatives-1-correct"
    When I press "ADD"
    When I fill in "edit-alternatives-2-answer-value" with "Beta"
    When I press "ADD"
    When I fill in "edit-alternatives-3-answer-value" with "Gamma"
    When I press "ADD"
    When I fill in "edit-alternatives-3-answer-value" with "Delta"
    And I press "Submit"
    Then I should see the error message containing "All answer choices (distractors) require an Answer. Please enter an Answer or click the Remove button to remove the answer choice (distractor)."

  Scenario: If the user clicks Submit button, and fewer than two distractors are complete, a validation error message is displayed saying, "At least two answer choices (distractors) are required."
    Then I click "Interactive Choice"
    Then I press "Submit"
    Then I should see the error message containing "At least two answer choices (distractors) are required."
    When I fill in "edit-alternatives-0-answer-value" with "Alpha"
    Then I press "Submit"
    Then I should see the error message containing "At least two answer choices (distractors) are required."
    When I fill in "edit-alternatives-1-answer-value" with "Beta"
    Then I press "Submit"
    Then I should not see the error message containing "At least two answer choices (distractors) are required."
