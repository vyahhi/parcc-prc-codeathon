@api @d7
Feature: Admin UI: Content Tab (PRC-169)
  As a Content Author,
  I want to view the content posted to Digital Library,
  so that I can edit them later as needed.

  Scenario: TT2 (PRC-225) Content View Created
    Given I am logged in as a user with the "Content Author" role
    And I am on the homepage
    When I follow "Content" in the "header" region
    Then I should see the heading "PRC Website Content" in the "content" region
    And I should see the link "Add content" in the "content" region

  Scenario: AC1 Content Authors should see own content only
    Given I am logged in as a user with the "Content Author" role
    And I am viewing my "Digital Library Content" node with the title "Mary's Content"
    And I visit "admin-content"
    Then I should not see the link "Jane's Content"
    And I should see the link "Mary's Content"
    Then I am an anonymous user
    Then I should get a "403" HTTP response at "admin-content"
    Then I am logged in as a user with the "Content Author" role
    And I am viewing my "Digital Library Content" node with the title "Jane's Content"
    And I visit "admin-content"
    Then I should see the link "Jane's Content"
    And I should not see the link "Mary's Content"

  Scenario: AC2 ID: Displays the unique identifier that the system has assigned to each content.
    Given I am logged in as a user with the "Content Author" role
    And I am viewing my "Digital Library Content" node with the title "ID Content"
    And I visit "admin-content"
    Then I should see "Nid" in the "content" region


#  3. Posted On: Displays the date this content was created for the 1st time.
#  4. Content Type: Displays the content type as captured at create content process (NOTE: In this story, there is only one content type Digital Library )
#  5. Last Updated: If the content has been updated after creation, display the timestamp for the update. If not, leave it blank. If multiple updates, display the most recent timestamp. (e.g. Default Format: 10/13/2014 - 12:12)
#  6. Action: An Action column will display in the table.
#  7. All fields are sortable except the Action column. The default sort will be by content ID in ascending order.
#  8. A Filter textbox allows the user to narrow down the table content by entering a keyword from any of the fields displayed in the table.
#  9.The filter should affect the entire data and not just the current page.
#  10. Pagination: 100 per page -use the default pagination: e.g. first previous 1 2 3 4 .... 26 next last
#  If user is on the first page, the first link is disabled.
#  If user is on the last page, the last link is disabled.