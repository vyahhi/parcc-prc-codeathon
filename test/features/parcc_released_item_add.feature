@api @parcc-released-item @prc-1733 @prc-1747 @prc-1748 @prc-1780 @prc-1749
Feature: PRC-1733 Assessment - PARCC Released Items Form
  As a PRC Admin or PARCC Item Author
  I want to be able to upload pdf files
  so that users will be able to assemble PARCC released items into an offline assessment until assessment publishing is available on PRC.

  Background:
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/parcc-released-items"
    When I click "Add Resource"

  Scenario: 1 - Default PARCC Released Items Add Resource form
    Given I should see the heading "Create PARCC Released Item"
    Then I should see the text "Resource name"
    And I should see the text "Body"
    And I should see the text "File"
    And I should see the text "Allowed file types: doc docx pdf mp3 mp4 xml ppt pptx."
    And I should see an "Upload" button
    And I should see the text "Resource Type"
    And I select "Item Set" from "Resource Type"
    And I select "Item" from "Resource Type"
    And I select "Manual" from "Resource Type"
    And I select "Sample Student Responses" from "Resource Type"
    And I select "Supplemental Document" from "Resource Type"
    And I should see the text "Subject"
    And I should see an "#edit-field-subject-und-0-tid" element
    And I should see an "#edit-field-subject-und-add-more" element
    And I should see the text "Standard"
    And I should see an "#edit-field-standard-und-0-tid" element
    And I should see an "#edit-field-standard-und-add-more" element
    And I should see the text "Grade Level"
    And I check the box "Pre-K"
    And I check the box "5th Grade"
    And I check the box "12th Grade"
    And I should see the text "Release Year"
    And I select "2016" from "Year"
    And I should see the text "Permissions"
    And I select the radio button "Public" with the id "edit-field-released-item-permissions-und-public"
    And I select the radio button "Registered" with the id "edit-field-released-item-permissions-und-registered"
    And I select the radio button "PARCC members ONLY" with the id "edit-field-released-item-permissions-und-members"
    And I should see a "Save" button
    And I should not see the text "Preview"

  Scenario: 2 - Default PARCC Released Items Add Resource form
    Given I should see the heading "Create PARCC Released Item"
    When I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-file-single-und-0-upload"
    And I click on the element with css selector "#edit-field-file-single-und-0-upload-button"
    Then I should see the link "GreatLakesWater.pdf"
    When I click on the element with css selector "#edit-field-file-single-und-0-remove-button"
    And I attach the file "testfiles/FireflyIpsum.doc" to "edit-field-file-single-und-0-upload"
    And I click on the element with css selector "#edit-field-file-single-und-0-upload-button"
    Then I should see the link "FireflyIpsum.doc"
    When I click on the element with css selector "#edit-field-file-single-und-0-remove-button"
    And I attach the file "testfiles/FireflyIpsum.docx" to "edit-field-file-single-und-0-upload"
    And I click on the element with css selector "#edit-field-file-single-und-0-upload-button"
    Then I should see the link "FireflyIpsum.docx"
    When I click on the element with css selector "#edit-field-file-single-und-0-remove-button"
    And I attach the file "testfiles/therapeutics.ppt" to "edit-field-file-single-und-0-upload"
    And I click on the element with css selector "#edit-field-file-single-und-0-upload-button"
    Then I should see the link "therapeutics.ppt"

  Scenario: 3 - Clicking the Upload button with a PDF / Word file selected
    Given I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-file-single-und-0-upload"
    When I click on the element with css selector "#edit-field-file-single-und-0-upload-button"
    Then I should see the link "GreatLakesWater.pdf"
    And I should see a "Remove" button

  Scenario: 4 Clicking the Remove button when a PDF / Word file is attached
    Given I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-file-single-und-0-upload"
    When I click on the element with css selector "#edit-field-file-single-und-0-upload-button"
    Then I should see the link "GreatLakesWater.pdf"
    And I should see a "Remove" button
    When I click on the element with css selector "#edit-field-file-single-und-0-remove-button"
    Then I should not see the link "GreatLakesWater.pdf"
    And I should see a "Upload" button

  @javascript
  Scenario: 5 Clicking the Add another subject button
    Given I select "English Language Arts" from "edit-field-subject-und-0-tid-select-1"
    When I click on the element with css selector "#edit-field-subject-und-add-more"
    And I wait for AJAX to finish
    Then I should see an ".form-item-field-subject-und-1-tid" element

  @javascript
  Scenario: 6 Clicking the Add another standard button
    Given I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    When I click on the element with css selector "#edit-field-standard-und-add-more"
    And I wait for AJAX to finish
    Then I should see an ".form-item-field-standard-und-1-tid" element

  Scenario: 7 Selecting a Grade Level Checkbox
    Given I check the box "Pre-K"
    # Todo - Confirm checkbox styles (technically we should be covered elsewhere...)

  Scenario: 8 Selecting Multiple Grade Level Checkboxes
    Given I check the box "Pre-K"
    And I check the box "5th Grade"
    And I check the box "12th Grade"

  Scenario: 9 Error Messaging
    When I click on the element with css selector "#edit-submit"
    Then I should see the error message containing "Resource name field is required."
    And I should see the error message containing "Grade Level field is required."
    And I should see the error message containing "At least one Subject is required."
    And I should see the error message containing "At least one Standard is required."
    And I should see the error message containing "Permissions field is required."
    And I should see the error message containing "Resource Type field is required."
