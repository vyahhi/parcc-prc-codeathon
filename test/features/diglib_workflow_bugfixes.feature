@diglib @workflow @api @prc-1385 @prc-1386
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
      Then I should see the message containing "Digital Library Content My node"

