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

  Scenario: AC2 ID: Displays the unique identifier that the system has assigned to each content. SORTABLE
    Given I am logged in as a user with the "Content Author" role
    And I am viewing my "Digital Library Content" node with the title "ID Content"
    And I visit "admin-content"
    Then I should see the link "Nid"
    # AC3 Posted On: Displays the date this content was created for the 1st time. SORTABLE
    Then I should see the link "Posted On"
    # AC4  Content Type: Displays the content type. SORTABLE
    Then I should see the link "Content Type"
    # AC5 Last Updated: Display the timestamp for the update. Sortable (e.g. Default Format: 10/13/2014 - 12:12)
    Then I should see the link "Last Updated"
    # AC6  Action: An Action column will display in the table.
    Then I should see "Action"
     # AC7 All fields are sortable except the Action column. The default sort will be by content ID in ascending order.
    And I should not see the link "Action"
    And I should see the link "delete"
    And I should see the link "edit"

    # AC8 A Filter textbox allows the user to narrow down the table content by entering a keyword from any of the fields displayed in the table.
    # AC9 The filter should affect the entire data and not just the current page.
    # AC10 Pagination: 100 per page -use the default pagination: e.g. first previous 1 2 3 4 .... 26 next last