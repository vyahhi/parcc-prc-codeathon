@api @diglib @prc-32
Feature: View Content (PRC-32)
  As an educator,
  I want to view content posted to the Digital Library,
  so that I can benefit from PRC resources.

  # AC1 This story is about the content for Digital Library tab on the top navigation bar.

  Scenario: AC2  At click, a new Digital Library page opens. All authenticated users have access to this page
    Given I am logged in as a user with the "authenticated user" role
    Then I should see the link "Library" in the "header" region
    When I follow "Library"
    Then I should see the heading "Library"
    And the url should match "library"

  Scenario: AC3-5  In this page, the content is listed and sortable by date
    Given "Digital Library Content" nodes:
      | title         | body              | status | promote | uid | field_author_name | field_thumbnail          |
      | Title1        | Trimmed Content 1 | 1      | 0       | 1   | Bob               | thumbnailimage.png       |
      | Title2        | Trimmed Content 2 | 1      | 0       | 1   | Prasdi            | thumbnailimage.png       |
      | Title3        | Trimmed Content 3 | 1      | 0       | 1   | Jimmy             | thumbnailimage.png       |
    And I index search results
    And I am logged in as a user with the "authenticated user" role
    And I visit "library"
    Then I should see "Title1"
    And I should see "Trimmed Content 1"
    # I should see the thumbnail too, but I don't know how to test it in the context of this script
    Then I should see "Title2"
    And I should see "Trimmed Content 2"
    # I should see the thumbnail too, but I don't know how to test it in the context of this script
    Then I should see "Title3"
    And I should see "Trimmed Content 3"
    # I should see the thumbnail too, but I don't know how to test it in the context of this script
    #  AC3. In this page, the content is listed based on the sort definition. Default by date: the most recent on the top
    #  AC4. The following components are displayed for each content:
    #  AC4a. Title
    #  AC4b. statement containing date and author (if available), such as: Created Feb 14, 2014 10:37 AM by Joe Admin
    #  AC4c. Summary
    #  AC4d. Thumbnail (when available)

  Scenario: AC5. A Sort dropdown menu allows the user to change the order. The only available option for now is: Date: most recent on the top
     And I should see "Sort by"
     And I should see "Date" in the "#edit-sort-by" element
     And I should see "DESC" in the "edit-sort-order" field

  Scenario: PRC-519 Add a Thumbnail Image text in results
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "Digital Library Content" node with the title "PRC-519"
    When I click "Edit"
    Then I attach the file "testfiles/lovelythumbnail.png" to "edit-field-thumbnail-und-0-upload"
    And I select the radio button "Public"
    And I press "Save"
    And I should see the success message containing "Digital Library Content PRC-519 has been updated."
    And I index search results
    Then I click "Library"
    And I should not see the text "Add a Thumbnail Image"
    When I click "PRC-519"
    Then I should not see the text "Add a Thumbnail Image"
