@api @itembank @parcc-item @prc-1316
Feature: PRC-1316 Item Bank - Edit Item - Form Validation - PARCC Item unchecked
  As a PARCC Item Author
  I want to get feedback when I edit a PARCC item and uncheck the "Make this a PARCC item" box
  so that i can fix errors and successfully edit the item.

  Given that I am logged in as a PARCC Item Author
  And I am on the Edit Non-Interactive Item page, the Edit Interactive Choice Item page or the Edit Short Answer Item page
  And the item is a PARCC item
  And the item is in any assessment (either a PARCC or non-PARCC assessment)
  And I uncheck the "Make this a PARCC item" check box
  When I press the Submit button
  Then I see the error message:
  "A PARCC item that is in an assessment cannot be changed to a non-PARCC item" [wording?]
  Note: Applies to PARCC items of all item types:
  Non-Interactive Item
  Interactive Choice Item and
  Short Answer Item

  Scenario: Non-Interactive Item
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Quiz directions" nodes
    And I am on "assessments"
    And I click "Create New Quiz"
    And I fill in "Title" with "Quiz Title"
    And I fill in "Objectives" with "Objectives"
    And I select "1st Grade" from "Grade Level"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I press "Save Draft"

    When I click "Non-interactive Item (text only)"
    And I fill in "Title" with "NII T"
    And I fill in "Question" with "NII Question"
    And I check "Make this a PARCC item"
    And I press "Save"

    Then I am on "item-bank"
    And I should see the text "Yes" in the "NII T" row
    When I click "Edit"
    And I uncheck the box "Make this a PARCC item"
    And I press "Save"
    Then I should see the error message containing "A PARCC item that is in an assessment cannot be changed to a non-PARCC item."

    But I check the box "Make this a PARCC item"
    And I press "Save"
    Then I should not see the error message containing "A PARCC item that is in an assessment cannot be changed to a non-PARCC item."

  Scenario: Short Answer Item
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Quiz directions" nodes
    And I am on "assessments"
    And I click "Create New Quiz"
    And I fill in "Title" with "Quiz Title"
    And I fill in "Objectives" with "Objectives"
    And I select "1st Grade" from "Grade Level"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I press "Save Draft"

    And I click "Short Answer"
    And I fill in "Title" with "SA 1"
    And I fill in "Question" with "Stem 1"
    And I fill in "Correct answer" with "Correct"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I select "1st Grade" from "Grade Level"
    And I check the box "Make this a PARCC item"
    Then I press "Save"

    Then I am on "item-bank"
    And I should see the text "Yes" in the "SA 1" row
    When I click "Edit"
    And I uncheck the box "Make this a PARCC item"
    And I press "Save"
    Then I should see the error message containing "A PARCC item that is in an assessment cannot be changed to a non-PARCC item."

    But I check the box "Make this a PARCC item"
    And I press "Save"
    Then I should not see the error message containing "A PARCC item that is in an assessment cannot be changed to a non-PARCC item."


  Scenario: Interactive Choice Item
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Quiz directions" nodes
    And I am on "assessments"
    And I click "Create New Quiz"
    And I fill in "Title" with "Quiz Title"
    And I fill in "Objectives" with "Objectives"
    And I select "1st Grade" from "Grade Level"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I press "Save Draft"

    And I click "Interactive Choice"
    And I fill in "Item Title" with "IC 1"
    And I fill in "Question (Item Stem)" with "Stem 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in "edit-alternatives-0-answer-value" with "One"
    And I fill in "edit-alternatives-1-answer-value" with "Two"
    And I check the box "edit-alternatives-1-correct"
    And I select "1st Grade" from "Grade Level"
    And I check the box "Make this a PARCC item"
    Then I press "Save"

    Then I am on "item-bank"
    And I should see the text "Yes" in the "IC 1" row
    When I click "Edit"
    And I uncheck the box "Make this a PARCC item"
    And I press "Save"
    Then I should see the error message containing "A PARCC item that is in an assessment cannot be changed to a non-PARCC item."

    But I check the box "Make this a PARCC item"
    And I press "Save"
    Then I should not see the error message containing "A PARCC item that is in an assessment cannot be changed to a non-PARCC item."