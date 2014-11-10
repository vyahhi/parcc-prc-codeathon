@api @d7
Feature: Admin UI: Content Tab (PRC-169)
  As a Content Contributor,
  I want to view the content posted to Digital Library,
  so that I can edit them later as needed.

  Scenario: TT2 (PRC-225) Content View Created
    Given I am logged in as a user with the "Content Contributor" role
    And I am on the homepage
    When I follow "Content" in the "header" region
    Then I should see the heading "PRC Website Content" in the "content" region
    And I should see the link "Add content" in the "content" region

  Scenario: AC1 Content Authors should see own content only
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Mary's Content"
    And I visit "admin-content"
    Then I should not see the link "Jane's Content"
    And I should see the link "Mary's Content"
    Then I am an anonymous user
    Then I should get a "403" HTTP response at "admin-content"
    Then I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "Jane's Content"
    And I visit "admin-content"
    Then I should see the link "Jane's Content"
    And I should not see the link "Mary's Content"

  Scenario: AC2 ID: Displays the unique identifier that the system has assigned to each content. SORTABLE
    Given I am logged in as a user with the "Content Contributor" role
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
    #  AC8 A Filter textbox allows the user to narrow down the table content by entering a keyword from any of the fields displayed in the table.
    And I should see an "Filter all columns" field
    And I should see an "edit-submit-admin-content-view" button

    # AC9 and 10 tests temporarily removed awaiting user role assignment code.

  Scenario: AC7: The default sort will be by content ID in ascending order (PRC-333)
    Given I am logged in as a user with the "Content Contributor" role
    And "Digital Library Content" nodes:
    | title   | body            | uid         | created    |
    | One     | One@timestamp   | @currentuid | 1410000100 |
    | Two     | Two@timestamp   | @currentuid | 1410000200 |
    | Three   | Three@timestamp | @currentuid | 1410000300 |
    | Four    | Four@timestamp  | @currentuid | 1410000400 |
    Then I visit "admin-content"
    Then "One" should precede "Two" for the query ".view-id-admin_content_view table tr td:nth-child(5)"
    Then "Two" should precede "Three" for the query ".view-id-admin_content_view table tr td:nth-child(5)"
    Then "Three" should precede "Four" for the query ".view-id-admin_content_view table tr td:nth-child(5)"
