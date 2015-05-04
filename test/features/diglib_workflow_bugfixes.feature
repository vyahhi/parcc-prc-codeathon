@diglib @workflow @api @prc-1385 @prc-1386 @prc-1390
  Feature: Various bugfixes associated with workflow and revisions.
    
    @javascript
    Scenario: prc-1385 & prc : Setting a standard, and removing the standard in a separate draft causes
    errors.
      Given I am logged in as a user with the "Content Administrator (Curator)" role
      And I visit "admin-content"
      And I click "Add content"
      And I enter "My node @timestamp" for "Title *"
      And I click "Show Add More Information (Content Properties)"
      And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
      And I wait for AJAX to finish
      And I select "Reading Standards for Literature" from "edit-field-standard-und-0-tid-select-2"
      And I wait for AJAX to finish
      And I select "Craft and Structure" from "edit-field-standard-und-0-tid-select-3"
      And I wait for AJAX to finish
      And I select "Ask and answer questions about unknown words in a text." from "edit-field-standard-und-0-tid-select-4"
      And I wait for AJAX to finish
      And I select the radio button "Public" with the id "edit-field-permissions-und-public"
      And I press "Save"
      When I click "Edit"
      And I select "None" from "edit-field-standard-und-0-tid-select-1"
      And I press "Publish"
      And I press "Update state"
      # prc-1386
      Then I should not see the message containing "Illegal string offset"
      And I click "My node @timestamp"
      And I click "Revisions"
      # prc-1385
      And I should not see the message containing "Trying to get property of non-object"

    @javascript
    Scenario: prc-1391 - Need to click save twice when adding a tag
      Given I am logged in as a user with the "Content Administrator (Curator)" role
      And I visit "admin-content"
      And I click "Add content"
      And I enter "My node @timestamp" for "Title *"
      When I fill in "Tags" with "Test"
      And I select the radio button "Public" with the id "edit-field-permissions-und-public"
      And I press "Save"
      And I click "Edit"
      And I press "Publish"
      And I press "Update state"
      And I click "My node @timestamp"
      And I click "Edit"
      And I press "Save"
      And I press "Confirm"
      Then I should see the message containing "Digital Library Content My node"

    Scenario: prc-1390 - Revisions for all fields, only last tag is tracked for revisions.
      Given I am logged in as a user with the "Content Administrator (Curator)" role
      And I visit "admin-content"
      And I click "Add content"
      And I enter "My node @timestamp" for "Title *"
      And I select the radio button "Public" with the id "edit-field-permissions-und-public"
      And I fill in "Tags" with "Test, Assessment"
      And I press "Save"
      And I click "Edit"
      And I fill in "Tags" with "Peanut Butter"
      And I press "Publish"
      And I press "Update state"
      And I click "My node @timestamp"
      And I click "Edit"
      And I fill in "Tags" with "Peanut Butter, Crackers, Milk"
      And I press "Save"
      And I press "Confirm"
      Then I visit "admin-content"
      And I click "My node @timestamp"
      # we are on the edit page of the revision, click the breadcrumb to get to the main node
      And I click "My node @timestamp"
      And I click "Revisions"
      And I should see the text "Test"
      And I should see the text "Assessment"
      And I should see the text "Peanut Butter"
      And I should see the text "Peanut Butter Crackers Milk"

    @javascript
    Scenario: prc-1387 - Make sure standards are tracked correctly.
      Given I am logged in as a user with the "Content Administrator (Curator)" role
      And I visit "admin-content"
      And I click "Add content"
      And I enter "My node @timestamp" for "Title *"
      And I select the radio button "Public" with the id "edit-field-permissions-und-public"
      And I click "Show Add More Information (Content Properties)"
      And I select "Career and Technical Education" from "edit-field-subject-und-0-tid-select-1"
      And I wait for AJAX to finish
      And I select "Career Academies and Programs" from "edit-field-subject-und-0-tid-select-2"
      And I wait for AJAX to finish
      And I press "Save"
      And I click "Edit"
      And I press "edit-field-subject-und-add-more"
      And I select "English Language Arts" from "edit-field-subject-und-1-tid--2-select-1"
      And I wait for AJAX to finish
      And I select "Reading" from "edit-field-subject-und-1-tid--2-select-2"
      And I wait for AJAX to finish
      And I press "Publish"
      And I press "Update state"
      And I click "My node @timestamp"
      And I click "Edit"
      And I select "- None -" from "edit-field-subject-und-0-tid-select-1"
      And I press "Save"
      And I press "Confirm"
      Then I visit "admin-content"
      And I click "My node @timestamp"
      # we are on the edit page of the revision, click the breadcrumb to get to the main node
      And I click "My node @timestamp"
      And I click "Revisions"
      And I should see the text "Reading"
      And I should see the text "Career Academies and Programs"
