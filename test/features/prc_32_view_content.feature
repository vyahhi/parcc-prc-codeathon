@api @d7
Feature: View Content (PRC-32)
  As an educator,
  I want to view content posted to the Digital Library,
  so that I can benefit from PRC resources.

  Scenario: AC1 This story is about the content for Digital Library tab on the top navigation bar.
    Given I am an anonymous user
    And I am on the homepage
    Then I should not see the link "Digital Library" in the "header" region

  Scenario: AC2  At click, a new Digital Library page opens. All authenticated users have access to this page
    Given I am logged in as a user with the "authenticated user" role
    Then I should see the link "Digital Library" in the "header" region
    When I follow "Digital Library"
    Then I should see the heading "Digital Library" in the "content" region
    And the url should match "digital-library"

  Scenario: AC3-5  In this page, the content is listed and sortable by date
    Given I am logged in as a user with the "authenticated user" role
    And I visit "digital-library"
    Then I should see "Title"
    Then I should see the link "Posted On"
    Then I should see "Author"
    Then I should see "Summary"
    Then I should see "Thumbnail"
