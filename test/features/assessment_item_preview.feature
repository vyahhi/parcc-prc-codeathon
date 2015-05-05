@api @assessment
Feature: PRC-527 Preview an item in Assessment Details page
  As an educator,
  I want to preview an item within the test I'm viewing,
  so that I will know the details about the items within the test.

  Acceptance Criteria
  AC1 Clicking an item in the Assessment Details page (implemented in PRC-490) provides a new section underneath the test metadata for the selected item metadata and preview.
  AC2 Item Metadata: Display the following item attributes:
  Item Type
  Item Standard (line-separated: 1 standard per line)
  Q1 (Choice Interaction)
  Standard:
  Creating Equations and describe numbers or relationships
  Reasoning with Equations and inequalities
  Understand solving equations as a process of reasoning and explain the reasoning
  Represent and solve equations and inequalities graphically
  AC3 Item Preview: Display the item stem and distractors as it will be displayed in the actual test (see Additional Consideration below for future functionality).
  AC4 Permissions: This feature is available to all roles, including anonymous users.
  AC5 Selecting elsewhere in the items list area shall de-select the item; therefore the item metadata and preview disappear. ADDED 12/21/14

  @javascript
  Scenario: AC1 Clicking an item in the Assessment Details page (implemented in PRC-490) provides a new section underneath the test metadata for the selected item metadata and preview.
    Given I am logged in as a user with the "PRC Admin" role
    And "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Grade Level" terms:
      | name      |
      | Grade 527 |
    And "Assessment" nodes:
      | title        | field_subject | field_grade_level | field_quiz_type                    | uid         |
      | PRC-527 View | subj1, subj2  | Grade 527         | PARCC-Released Practice Assessment | @currentuid |
  # That standard already exists, and I hate it, but I am getting an error
  # creating a Standard term is giving me an error.
  # We're cheating and using one that exists already.
    When I visit the last node created
    And I click "Quiz"
    Then I click "Manage questions"
    Then I click "Create new question"
    Then I click "Assessment directions"
    And I fill in "edit-body-und-0-value" with "PRC-490 Directions 1 And these are the Body Body Directions Directions"
    And I fill in "Title" with "PRC-527 Directions 1"
    And I press "Save"
    Then I click "Create new question"
    Then I click "Multiple choice question"
    And I fill in "edit-body-und-0-value" with "PRC-527 Multi Multi Question Question<p>Paragraph</p>"
    And I fill in "Title" with "PRC-527 Multi"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "edit-alternatives-0-answer-value" with "Answer 1"
    And I fill in "edit-alternatives-1-answer-value" with "Answer 2"
    And I check the box "edit-alternatives-1-correct"
    And I select "1st Grade" from "Grade Level"
    And I press "Save"
    Then I visit the last node created
    And I should see the text "Item Type"

    And I should not see the text "Body Body Directions Directions"
    But I should see the link "PRC-527 Directions 1"
    And I should not see the text "Multi Multi Question Question"
    But I should see the link "PRC-527 Multi"

    When I follow "PRC-527 Directions 1"
    Then I should see the text "Body Body Directions Directions"
    Then I move backward one page

    When I follow "PRC-527 Multi"
    Then I should see the text "Multi Multi Question Question"

    When I am an anonymous user
    And I visit the last node created
    And I should see the text "Item Type"

    And I should not see the text "Body Body Directions Directions"
    But I should see the link "PRC-527 Directions 1"
    And I should not see the text "Multi Multi Question Question"
    But I should see the link "PRC-527 Multi"

    When I follow "PRC-527 Directions 1"
    Then I should see the text "Body Body Directions Directions"
    And I should see the text "Item Title"

    And I visit the last node created
    When I follow "PRC-527 Multi"
    Then I should see the text "Multi Multi Question Question"
    And I should see the text "Item Title"
    And I should not see the text "<p>"