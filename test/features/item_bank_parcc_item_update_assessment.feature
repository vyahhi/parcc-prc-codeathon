@api @itembank @parcc-item @prc-1026
Feature: PRC-1026 Item Bank - Edit Item - Item Edited - Assessment/s Updated
  As a logged in user, I want edits that I made to an item to apply to the item within any assessments that contain the item.
  Acceptance Criteria
  Given that I am logged in
  And I am on the Edit Non-Interactive Item form, the Edit Interactive Choice Item form or the Edit Short Answer Item form
  And all my fields are valid
  When I press the Submit button
  Then the item is changed in any and all assessments that contain it.
  Note: Applies to all PARCC and non-PARCC item types:
  Non-Interactive Item
  Interactive Choice Item and
  Short Answer Item

  Scenario: Non-Interactive Item
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments"
    And I click "Create New Assessment"
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

    When I click on the element with css selector "td a.handle-changes"
    And I fill in "Title" with "New Title"
    And I fill in "Question" with "Blah blah blah"
    And I press "Save"

    When I click "New Title"
    Then I should see the text "New Title"
    And I should see the text "Blah blah blah"
