@api @d7 @diglib
Feature: Admin UI: Define Content Metadata (PRC-30)
  As a Content Contributor,
  I want to define the metadata associated to a content I'm posting to PRC digital library,
  so that the educators can find the content they wish to view using the content metadata.

  @javascript
  Scenario: AC1 Test presence of metadata section with terms
    Given I am logged in as a user with the "Content Contributor" role
    And "Grade Level" terms:
      | name          |
      | Middle School |
    When I am browsing using a "desktop"
    And I am on "prc/admin"
    And I hover over the element "#main-menu-section a[href='/prc/admin']"
    And I hover over the element "#main-menu-section .dropdown a[href='/prc/admin/admin-content']"
    When I follow "Content"
    Then I click "Add content"
    Then I should see the text "Add More Information (Content Properties)" in the "content" region
    And I click "Show Add More Information (Content Properties)"
    And I should see the text "Grade Level"
    And I should see the text "Subject"
    And I should see the text "Media Type"
    And I should see the text "Genre"

  # AC2 Test grade level options

    Then I check the box "Pre-K"
    And I check the box "Kindergarten"
    And I check the box "1st Grade"
    And I check the box "2nd Grade"
    And I check the box "8th Grade"
    And I check the box "12th Grade"

  # AC3 Test subject options

    And I should see "English Language Arts"
    And I should see "Math"
    And I should see "Science"
    And I should see "History/Social Studies"
    And I should see "World Languages"
    And I should see "Visual and Performing Arts"
    And I should see "Career and Technical Education"
    And I should see "STEM"
    And I should see "Physical Education"
    And I should see "English Language Development"
    And I should see "Special Needs Support"
    And I should see "Educational Leadership"

  # AC5 Test media type options

    Then I should see "Text" in the "content" region
    And I should see "Image"
    And I should see "Audio"
    And I should see "Video"

  # AC6 Test grade level options

    And I should see "Learning Fun"
    And I should see "Bonding Activities"
