@api @d7
Feature: Edit Content (PRC-158)
  As a Content Author,
  I want to view and modify existing content within the PRC Digital Library,
  so that the educators can access and view the latest and greatest version.

  Scenario: AC1  Content Authors click on content tab and see content with edit button
    Given I am logged in as a user with the "Content Author" role
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
  Scenario: AC4  Attachment files are listed, along with a Remove link/button. At click, the file is removed after having the user to confirm removal
    Given I am logged in as a user with the "Content Author" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    And I follow "Content" in the "header" region
    Then I should see the link "edit" in the "content" region
    Then I follow "edit"
    Then I should see the heading "Edit Digital Library Content Test-o-rama" in the "content" region
    Then I attach the file "/sites/default/files/color/responsive_bartik-60224c8b/logo.png" to "edit-field-thumbnail-und-0-upload"
    And I press "Save"
    And I should see the success message containing "Digital Library Content Test-o-rama has been updated."
    Then I follow "edit"
    And I should see the link "logo.png"
  # And I attach the file "test2.pdf"
#  Scenario: AC5  A user may add more files; a Browse button along with an Upload button are provided to allow the user to select the file.
#  Scenario: AC6  Once file is selected, the name of the file appears by the Browse button. When no file is selected, it displays _No file selected.
#  Scenario: AC7  From the above attributes, the following will be provided with an expandable/collapsable control that allows a user to hide or unhide the content underneath it:
#  Attach a File -collapsed by default unless an attached file already exist (updated 10/15)
#  Add a Thumbnail Image -expanded by default
#  Link to URL -collapsed by default unless an URL already exist (updated 10/15)
#  Add More Information (Content Properties) -collapsed by default unless more data has been entered (updated 10/15)
#  AC8  A Save button allows the user to save the entries for the updated content to be posted.
#  AC9  Once Saved, the system shall
#  provide confirmation that the content has been successfully modified.
#  store the timestamp and the user ID of the user who saved it
#  display it in the updated content in Digital Library page with a latency of up to an hour ( updated 10/15)
#  AC10 If the user navigates away without saving changes, the system prompts the user to confirm.