@api @d7 @diglib
Feature: Admin UI: Content Tab (PRC-169)
  As a Content Contributor,
  I want to view the content posted to Digital Library,
  so that I can edit them later as needed.

  Scenario: TT2 (PRC-225) Content View Created
    Given I am logged in as a user with the "Content Contributor" role
    And I am on "prc/admin"
    When I follow "Content" in the "content" region
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

  Scenario: AC8 A Filter textbox allows the user to narrow down the table content by entering a keyword from any of the fields displayed in the table.
    Given I am logged in as a user with the "Content Contributor" role
    And "Digital Library Content" nodes:
      | title     | body            | uid         | created    |
      | One       | One@timestamp   | @currentuid | 1410000100 |
      | Two       | Two@timestamp   | @currentuid | 1410000200 |
      | Three     | Three@timestamp | @currentuid | 1410000300 |
      | Fifty One | Four@timestamp  | @currentuid | 1410000400 |
    And I visit "admin-content"
    And I should see an "Filter all columns" field
    And I should see an "Apply" button
    When I fill in "Filter all columns" with "one"
    And I press "Apply"
    Then I should see the text "One"
    Then I should see the text "Fifty One"
    But I should not see the text "Two"
    But I should not see the text "Three"

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
    Then "One" should precede "Two" for the query "a"
    Then "Two" should precede "Three" for the query "a"
    Then "Three" should precede "Four" for the query "a"

  Scenario: AC10 Pagination: 100 per page -use the default pagination: e.g. first previous 1 2 3 4 .... 26 next last
    # If generate <100 Digital library content nodes, I should see no pagination
    Then I run drush "cc all"
    Then I run drush "genu 0 --kill"
    And I am logged in as a user with the "PRC Admin" role
    Then I run drush "genc 100 --kill --types=digital_library_content"
    And I visit "/admin-content"
    And I should not see the link "next"
    And I should not see the link "last"
    Then I run drush "genc 400 --types=digital_library_content"
    And I visit "/admin-content"
    And I should see the link "next"
    And I should see the link "last"
    And I should not see the link "previous"
    And I should not see the link "first"
    When I follow "next"
    Then I should see the link "previous"
    And I should see the link "first"
