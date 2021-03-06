@api @diglib
Feature: PRC-219 Content Categorization - Standard
  As a Content Contributor,
  I want to do a more specialized categorization for content,
  so that end users can leverage the advanced content search.

  Acceptance Criteria
  1. A new Advanced link will be added by the Standards drop-down menu in the content metadata.
  2. At click, the system will provide a "Standards" overlay.
  3. For Standards overlay, a table allows a hierarchical drill down selection where each selection provides the user with the following options:
  associate content to the selected level.
  drill down to a lower level for a more specified selection (until reaching the leaf level).
  4. A user will select these Standard options by clicking the label name displayed in the table.
  5. A user may associate one or more Standards to content, and it can be different level.
  6. The system will ignore any duplicate selection.
  7. The content will come from the Learning Registry data. (decision about the level of testing?)
  8. A breadcrumb on top of the table allows for returning to previous level.
  9. A Save button allows the user to save the categorization.
  10. A Cancel button allows the user to go back to the edit content page with no change.
  11. If a user attempts to navigate away without saving changes, the system prompts the user to confirm.

  This is being changed to support Simple Hierarchy Select instead of an Advanced popup.

  @javascript
  Scenario: PRC-405 Standard select triggers leave confirmation
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-219 Standard"
    Then I click "Edit"
    And I click "Show Add More Information (Content Properties)"
    When I click on the element with css selector "#edit-field-standard-und-0-tid-select-1"
    When I click on the element with css selector "#edit-title"
    Then I move backward one page, confirming the dialog

  @javascript
  Scenario: I can see the Standard field
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-219 Standard"
    Then I click "Edit"
    And I click "Show Add More Information (Content Properties)"
    Then I should see 1 "#edit-field-standard-und-0-tid-select-1" elements

  @javascript
  Scenario: I can drill hierarchically through the Standard field
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-29 Subject"
    Then I click "Edit"
    And I click "Show Add More Information (Content Properties)"
    Then I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    Then I wait for AJAX to finish
    Then I select "Reading Standards for Literature" from "edit-field-standard-und-0-tid-select-2"
    Then I wait for AJAX to finish
    Then I select "Craft and Structure" from "edit-field-standard-und-0-tid-select-3"
    Then I wait for AJAX to finish
    Then I select "Ask and answer questions about unknown words in a text." from "edit-field-standard-und-0-tid-select-4"
    Then I wait for AJAX to finish

  @javascript
  Scenario: I can select multiple Standards
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-29 Subject"
    Then I click "Edit"
    And I click "Show Add More Information (Content Properties)"
    Then I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    Then I wait for AJAX to finish
    Then I select "Reading Standards for Literature" from "edit-field-standard-und-0-tid-select-2"
    Then I wait for AJAX to finish
    Then I select "Craft and Structure" from "edit-field-standard-und-0-tid-select-3"
    Then I wait for AJAX to finish
    Then I select "Ask and answer questions about unknown words in a text." from "edit-field-standard-und-0-tid-select-4"
    Then I wait for AJAX to finish
    Then I press "edit-field-standard-und-add-more"
    Then I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid--2-select-1"
    Then I wait for AJAX to finish
    Then I select "College and Career Readiness Anchor Standards for Reading" from "edit-field-standard-und-0-tid--2-select-2"
    Then I wait for AJAX to finish
    Then I select "Key Ideas and Details" from "edit-field-standard-und-0-tid--2-select-3"
    Then I wait for AJAX to finish
    Then I select "Read closely to determine what the text says explicitly and to make logical inferences from it; cite specific textual evidence when writing or speaking to support conclusions drawn from the text." from "edit-field-standard-und-0-tid--2-select-4"
    Then I wait for AJAX to finish

  @javascript
  Scenario: I can save a node with a Standard
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-29 Subject"
    Then I click "Edit"
    And I select the radio button "Public"
    And I click "Show Add More Information (Content Properties)"
    Then I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    Then I wait for AJAX to finish
    Then I press "Save"
    Then I should see the text "Common Core English Language Arts"

  @javascript
  Scenario: PRC-1485 select and save terms with SHS without ajax failures
    Given I am logged in as a user with the "Content Contributor" role
    And I visit "prc/admin/admin-content"
    And I click "Add content"
    And I fill in "Title *" with "My Content @timestamp"
    When I click "Edit"
    And I click "Show Add More Information (Content Properties)"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I wait for AJAX to finish
    And I select "Reading Standards for Literature" from "edit-field-standard-und-0-tid-select-2"
    And I wait for AJAX to finish
    And I select "Craft and Structure" from "edit-field-standard-und-0-tid-select-3"
    And I wait for AJAX to finish
    And I select "Ask and answer questions about unknown words in a text." from "edit-field-standard-und-0-tid-select-4"
    And I wait for AJAX to finish
    And I press "edit-field-standard-und-add-more"
    And I wait for AJAX to finish
    And I select "Common Core English Language Arts" from "edit-field-standard-und-1-tid-select-1"
    And I wait for AJAX to finish
    And I select "College and Career Readiness Anchor Standards for Reading" from "edit-field-standard-und-1-tid-select-2"
    And I wait for AJAX to finish
    And I select "Key Ideas and Details" from "edit-field-standard-und-1-tid-select-3"
    And I wait for AJAX to finish
    And I select "Read closely to determine what the text says explicitly and to make logical inferences from it; cite specific textual evidence when writing or speaking to support conclusions drawn from the text." from "edit-field-standard-und-1-tid-select-4"
    And I wait for AJAX to finish
    And I select the radio button "Public"
    And I press the "Save" button
    Then I click "Edit"
    And I wait for AJAX to finish
    And I press the "Save" button
    And I should see the text "Read closely to determine what the text says explicitly and to make logical inferences from it; cite specific textual evidence when writing or speaking to support conclusions drawn from the text."
    And I should see the text "Ask and answer questions about unknown words in a text."


