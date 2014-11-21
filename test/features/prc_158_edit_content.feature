@api @d7
Feature: Edit Content (PRC-158)
  As a Content Contributor,
  I want to view and modify existing content within the PRC Digital Library,
  so that the educators can access and view the latest and greatest version.

  Scenario: AC1  Content Contributors click on content tab and see content with edit button
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    And I follow "Content" in the "header" region
    Then I should see the link "edit" in the "content" region
    #  AC2 At click, the Edit Content page opens.
    Then I follow "edit"
    Then I should see the heading "Edit Digital Library Content Test-o-rama" in the "content" region

  Scenario: AC3 Editable attributes are shown in the Edit Content page
    #  Title: Required, String(255)
    Then I should see a "Title *" field
    #  Author Name: Optional, String(255), followed by a description
    And I should see a "Author Name" field
    And I should see "Enter the author name as you wish it to be displayed with the content"
    #  Tags: Optional, Comma separated strings (each: String(255) , followed by a description
    And I should see a "Tags" field
    And I should see "Enter a comma-separated list of words to describe your content."
    #  Summary Description: Required Optional,
    And I should see a "Summary" field
    #  Body: Optional- Extended text
    And I should see an "Body" field
    #  Attach a File: A user may upload one or multiple files as attachment. No restriction on the file format for now; 2MB size limit
    And I should see "Attach a File"
    #  Add a Thumbnail Image: A user may upload an image file as thumbnail. Accepted formats are: JPG, PNG
    And I should see "Add a Thumbnail"
    #  Link to URL: A user may provide an external link that will redirect the end user to that external page
    And I should see "Link to URL"
    #  Add More Information (Content Properties): The following attributes are available in this section: Grade Level, Subject, Standard, Media Type, Genre
    And I should see "Add More Information (Content Properties)"
    And I should see the text "Grade Level"
    And I should see the text "Subject"
    #  And I should see the text "Standard"
    And I should see the text "Media Type"
    And I should see the text "Genre"

  @javascript
  Scenario: AC4 Attachment files are listed, along with a Remove link/button. At click, the file is removed after having the user to confirm removal
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    And I follow "Content" in the "header" region
    Then I should see the link "edit" in the "content" region
    Then I follow "edit"
    Then I should see the heading "Edit Digital Library Content Test-o-rama" in the "content" region
    # AC5  A user may add more files; a Browse button along with an Upload button are provided to allow the user to select the file.
    Then I attach the file "testfiles/lovelythumbnail.png" to "edit-field-thumbnail-und-0-upload"
    And I select the radio button "Public"
    # AC8  A Save button allows the user to save the entries for the updated content to be posted.
    And I press "Save"
    # AC9  Once Saved, the system shall provide confirmation that the content has been successfully modified.
    And I should see the success message containing "Digital Library Content Test-o-rama has been updated."
    Then I follow "edit"
    # AC6  Once file is selected, the name of the file appears by the Browse button.
    And I should see the link "lovelythumbnail.png"
    # AC7  is tested in PRC 157
    # AC10 is tested in PRC 251

  @javascript
  Scenario: PRC-342 No sections filled in
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    Then I follow "Edit"
    Then I should see the link "Show Add More Information (Content Properties)"
    Then I should see the link "Show Attach a File"
    Then I should see the link "Show Link to URL"
    Then I should not see the link "Show Add a Thumbnail"

  @javascript
  Scenario: PRC-342 Attach a file and it should be expanded
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    Then I follow "Edit"
    And I click "Attach a File"
    Then I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-document-und-0-upload"
    And I select the radio button "Public"
    And I press "Save"
    Then I follow "Edit"
    Then I should see the link "Show Add More Information (Content Properties)"
    Then I should not see the link "Show Attach a File"
    Then I should see the link "Show Link to URL"
    Then I should not see the link "Show Add a Thumbnail"

  @javascript
  Scenario: PRC-342 Set media and it should be expanded
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    Then I follow "Edit"
    Then I click "Show Add More Information (Content Properties)"
    And I select "Audio" from "Media Type"
    And I select the radio button "Public"
    And I press "Save"
    Then I follow "Edit"
    Then I should not see the link "Show Add More Information (Content Properties)"
    Then I should see the link "Show Attach a File"
    Then I should see the link "Show Link to URL"
    Then I should not see the link "Show Add a Thumbnail"

  @javascript
  Scenario: PRC-342 Set grade and it should be expanded
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    Then I follow "Edit"
    Then I click "Show Add More Information (Content Properties)"
    And I select "PreK" from "Grade Level"
    And I select the radio button "Public"
    And I press "Save"
    Then I follow "Edit"
    Then I should not see the link "Show Add More Information (Content Properties)"
    Then I should see the link "Show Attach a File"
    Then I should see the link "Show Link to URL"
    Then I should not see the link "Show Add a Thumbnail"

  @javascript
  Scenario: PRC-342 Set genre and it should be expanded
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    Then I follow "Edit"
    Then I click "Show Add More Information (Content Properties)"
    And I select "Learning Fun" from "Genre"
    And I select the radio button "Public"
    And I press "Save"
    Then I follow "Edit"
    Then I should not see the link "Show Add More Information (Content Properties)"
    Then I should see the link "Show Attach a File"
    Then I should see the link "Show Link to URL"
    Then I should not see the link "Show Add a Thumbnail"

  @javascript
  Scenario: PRC-342 Set subject and it should be expanded
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    Then I follow "Edit"
    Then I click "Show Add More Information (Content Properties)"
    Then I select "Educational Leadership" from "edit-field-subject-und-0-tid-select-1"
    Then I wait for AJAX to finish
    And I select the radio button "Public"
    And I press "Save"
    Then I follow "Edit"
    Then I should not see the link "Show Add More Information (Content Properties)"
    Then I should see the link "Show Attach a File"
    Then I should see the link "Show Link to URL"
    Then I should not see the link "Show Add a Thumbnail"

  @javascript
  Scenario: PRC-342 Set standard and it should be expanded
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    Then I follow "Edit"
    Then I click "Show Add More Information (Content Properties)"
    Then I select "National Council" from "edit-field-standard-und-0-tid-select-1"
    Then I wait for AJAX to finish
    And I select the radio button "Public"
    And I press "Save"
    Then I follow "Edit"
    Then I should not see the link "Show Add More Information (Content Properties)"
    Then I should see the link "Show Attach a File"
    Then I should see the link "Show Link to URL"
    Then I should not see the link "Show Add a Thumbnail"

  @javascript
  Scenario: PRC-342 Edit Content- Expandable/collapsible controls when attachment are in sections
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    And I follow "Content" in the "header" region
    Then I should see the link "edit" in the "content" region
    Then I follow "edit"
    Then I should see the heading "Edit Digital Library Content Test-o-rama" in the "content" region
    Then I should see the text "Attach a File"
    Then I should not see the text "Add a new file"
    And I click "Attach a File"
    Then I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-document-und-0-upload"
    And I select the radio button "Public"
    And I press "Save"
    And I should see the success message containing "Digital Library Content Test-o-rama has been updated."
    Then I follow "edit"
    Then I should see the text "Add a new file"
    And I should see the text "Link to URL"
    But I should not see the text "The link title is limited to 128 characters maximum."
    Then I click "Link to URL"
    And I fill in "URL" with "http://breaktech.com"
    Then I press "Save"
    And I should see the success message containing "Digital Library Content Test-o-rama has been updated."
    Then I follow "edit"
    And I should see the text "The link title is limited to 128 characters maximum."
    And I should see the text "Add More Information" 
    But I should not see the text "Grade Level"
    Then I click "Add More Information (Content Properties)"
    And I select "First Grade" from "Grade Level"
    Then I press "Save"
    And I should see the success message containing "Digital Library Content Test-o-rama has been updated."
    Then I follow "edit"
    And I should see the text "Grade Level"

