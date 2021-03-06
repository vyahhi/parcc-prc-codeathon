@api @d7 @diglib
Feature: Admin UI: Post Content (PRC-28)
  As a Content Contributor,
  I want to post a new content to PRC Website,
  so that the educators can access and view them.

  Scenario: Content Contributor permission - Edit Any
    Given I am logged in as a user with the "Content Contributor" role
    Then I should not be able to edit another user's "Digital Library Content" node

  Scenario: Content Contributor permission - Edit Own
    Given I am logged in as a user with the "Content Contributor" role
    Then I should be able to edit my own "Digital Library Content" node

  Scenario: AC1 Content Contributor permission to create
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-28 AC1 Title"

  Scenario Outline: AC2 and AC3 Content tab visibility for authorized users
    Given I am logged in as a user with the "<role>" role
    And I am on "prc/admin"
    Then I should see the link "Content" in the "content" region

  Examples:
    | role                            |
    | Content Contributor             |
    | Content Administrator (Curator) |
    | PRC Admin                       |
    | administrator                   |

  Scenario: AC2 and AC3 Content tab invisibility for Educators
    Given I am logged in as a user with the "Educator" role
    And I am on "prc/admin"
    Then I should not see the link "Content" in the "content" region

  Scenario: AC2 and AC3 Content tab invisibility for anonymous
    Given I am an anonymous user
    And I am on "prc/admin"
    Then I should not see the link "Content" in the "content" region

  Scenario: AC4-6 Content Authors click on Content tab link
    Given I am logged in as a user with the "Content Contributor" role
    And I am on "prc/admin"
    When I follow "Content"
    Then the url should match "prc/admin/admin-content"
    Then I click "Add content"
    Then the url should match "node/add/digital-library-content"
    And I should see the heading "Create Digital Library Content" in the "sub_header" region

  Scenario: AC7 - The following fields are to be displayed on
    Given I am logged in as a user with the "Content Contributor" role
    And I am on "node/add/digital-library-content"
    Then I should see a "Title *" field
    And I should see a "Author Name" field
    And I should see a "Tags" field
    And I should see a "Summary" field
    And I should see an "Body" field
    And I should see "Attach a File"
    And I should see "Add a Thumbnail Image"
    And I should see "Link to URL"
    And I should see "Add More Information (Content Properties)"

  @javascript
  Scenario: AC8-11 Users can upload and save an attachment
    Given I am logged in as a user with the "Content Contributor" role
    And I am on "node/add/digital-library-content"
    And I fill in "Title *" with "Test-o-rama"
    And I should see "Attach a File"
 #  We need to expand Attach a File because it's collapsed by default
    And I click "Show Attach a File"
    Then I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-document-und-0-upload"
    And I select the radio button "Public"
    And I press "Save"
    And I should see the success message containing "Digital Library Content Test-o-rama has been created."
    Then I follow "Edit"
    And I should see the link "GreatLakesWater.pdf"

  @javascript @prc-1572 @mp4
  Scenario: PRC-1572 Valid file extensions
    Given I am logged in as a user with the "Content Contributor" role
    And I am on "node/add/digital-library-content"
    And I fill in "Title *" with "Test-o-rama"
    And I should see "Attach a File"
 #  We need to expand Attach a File because it's collapsed by default
    And I click "Show Attach a File"
    Then I attach the file "testfiles/test1.csv" to "edit-field-document-und-0-upload"
    Then I should see the error message "The selected file test1.csv cannot be uploaded. Only files with the following extensions are allowed: txt, pdf, doc, docx, xls, xlsx, ppt, pptx, mp4."

  @javascript
  Scenario: AC8-11 Users can upload and save a thumbnail
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Test-o-rama"
    And I follow "Edit"
    Then I attach the file "testfiles/lovelythumbnail.png" to "edit-field-thumbnail-und-0-upload"
    And I select the radio button "Public"
    And I press "Save"
    And I should see the success message containing "Digital Library Content Test-o-rama has been updated."
    Then I follow "Edit"
    And I should see the link "lovelythumbnail.png"
    