@api @diglib @favorites @prc-253
Feature: PRC-253 - Organize Content: Filter by Custom List
  As an Educator,
  I want to filter the listed content to include the ones I organized into my custom list,
  so that I can quickly find the content I want.

  Scenario: AC1 In the Digital Library page, place a left panel containing a expandable/collapsable section as My Lists .
    Given I am logged in as a user with the "Educator" role
    # Creating lists out of numerical order so we can test alpha sort
    And I am viewing my "Favorites List" node with the title "List 2"
    And I am viewing my "Favorites List" node with the title "List 4"
    And I am viewing my "Favorites List" node with the title "List 3"
    And I am viewing my "Favorites List" node with the title "List 1"
    And I am on "library"
    Then I should see the link "View All"
    And I should see the heading "My Lists"
    # AC4 The custom lists that the current user has created so far shall be listed
    And I should see the link "List 1"
    And I should see the link "List 2"
    And I should see the link "List 3"
    And I should see the link "List 4"
    And I should see 4 ".view-my-lists a" elements
    # AC6 The lists shall be listed in alphabetical order, A to Z
    And "List 1" should precede "List 2" for the query ".view-my-lists a"
    And "List 2" should precede "List 3" for the query ".view-my-lists a"
    And "List 3" should precede "List 4" for the query ".view-my-lists a"

  Scenario: AC2 A View All option shall be available above (outside of) the list, and is selected by default and does not filter any content
    Given I am logged in as a user with the "Educator" role
    Then I run drush "genc 0 --types=digital_library_content --kill"
    Then I visit "library"
    Then I should see the link "View All"
    # AC3 The My Lists control is not visible when no list created
    And I should not see the heading "My Lists"

  Scenario: AC5 When a list is clicked, the list of content in the middle of the screen filters to display only the content associated to that list.
    Given I am logged in as a user with the "Educator" role
    And I am viewing my "favorites_list" node with the title "PRC-253 AC5 List 1"
    And I am viewing my "favorites_list" node with the title "PRC-253 AC5 List 2"
    And I am viewing a "Digital Library Content" node with the title "PRC-253 AC5 Unlisted"
    And I am viewing a "Digital Library Content" node with the title "PRC-253 AC5 DLC"
    Then I click "Add to My Lists"
    And I select "PRC-253 AC5 List 1" from "List"
    And I press "Add to List"
    And I index search results
    Then I visit "library"
    Then I should see the link "PRC-253 AC5 List 1"
    And I should see the link "PRC-253 AC5 List 2"
    And I should see the link "PRC-253 AC5 Unlisted"
    And I should see the link "PRC-253 AC5 DLC"
    Then I click "PRC-253 AC5 List 1"
    And I should not see the link "PRC-253 AC5 Unlisted"
    And I should see the link "PRC-253 AC5 DLC"

#  Acceptance Criteria
#  AC1 In the Digital Library page, place a left panel containing a expandable/collapsable section as My Lists .
#  AC2 A View All option shall be available above (ouside of) the list, and is selected by default and does not filter any content
#  AC3 The My Lists control is not visible when no list created
#  AC4 The custom lists that the current user has created so far shall be listed
#  AC5 When a list is clicked, the list of content in the middle of the screen filters to display only the content associated to that list.
#  AC6 The lists shall be listed in alphabetical order, A to Z
#  Additional Considerations
#  So far, no story has covered de-association or deletion of a custom list (future feature)