@api @diglib @favorites @prc-253
Feature: PRC-253 - Organize Content: Filter by Custom List
  As an Educator,
  I want to filter the listed content to include the ones I organized into my custom list,
  so that I can quickly find the content I want.

  Scenario: AC1 In the Digital Library page, place a left panel containing a expandable/collapsable section as My Lists .
    Given I am logged in as a user with the "Educator" role
    And "Digital Library Content" nodes:
      | title               | body           | field_permissions | uid         | status |
      | PRC-253 List Item 1 | This is public | public            | @currentuid | 1      |
      | PRC-253 List Item 2 | This is public | public            | @currentuid | 1      |
      | PRC-253 List Item 3 | This is public | public            | @currentuid | 1      |
      | PRC-253 List Item 4 | This is public | public            | @currentuid | 1      |
    # Creating lists out of numerical order so we can test alpha sort
    And "Favorites List" nodes:
      | title  | uid         | status | field_favorite_content    |
      | List 2 | @currentuid | 1      | @nid[PRC-253 List Item 2] |
      | List 4 | @currentuid | 1      | @nid[PRC-253 List Item 4] |
      | List 3 | @currentuid | 1      | @nid[PRC-253 List Item 3] |
      | List 1 | @currentuid | 1      | @nid[PRC-253 List Item 1] |
    Then I index search results
    And I am on "library"
    Then I should see the link "Reset"
    And I should see the heading "My Lists"
    # AC4 The custom lists that the current user has created so far shall be listed
    And I should see the link "List 1"
    And I should see the link "List 2"
    And I should see the link "List 3"
    And I should see the link "List 4"
    And I should see 4 ".facetapi-facet-prc-favorites-listings a" elements
    # AC6 The lists shall be listed in alphabetical order, A to Z
    And "List 1 (1) Apply List 1 filter" should precede "List 2 (1) Apply List 2 filter" for the query ".facetapi-facet-prc-favorites-listings a"
    And "List 2 (1) Apply List 2 filter" should precede "List 3 (1) Apply List 3 filter" for the query ".facetapi-facet-prc-favorites-listings a"
    And "List 3 (1) Apply List 3 filter" should precede "List 4 (1) Apply List 4 filter" for the query ".facetapi-facet-prc-favorites-listings a"

  Scenario: AC2 A View All option shall be available above (outside of) the list, and is selected by default and does not filter any content
    Given I am logged in as a user with the "Educator" role
    Then I run drush "genc 0 --types=digital_library_content --kill"
    Then I visit "library"
    Then I should see the link "Reset"
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
    And I should not see the link "PRC-253 AC5 List 2"
    And I should see the link "PRC-253 AC5 Unlisted"
    And I should see the link "PRC-253 AC5 DLC"
    Then I click "PRC-253 AC5 List 1"
    And I should not see the link "PRC-253 AC5 Unlisted"
#    And I should see the link "PRC-253 AC5 DLC"

#  Acceptance Criteria
#  AC1 In the Digital Library page, place a left panel containing a expandable/collapsable section as My Lists .
#  AC2 A View All option shall be available above (ouside of) the list, and is selected by default and does not filter any content
#  AC3 The My Lists control is not visible when no list created
#  AC4 The custom lists that the current user has created so far shall be listed
#  AC5 When a list is clicked, the list of content in the middle of the screen filters to display only the content associated to that list.
#  AC6 The lists shall be listed in alphabetical order, A to Z
#  Additional Considerations
#  So far, no story has covered de-association or deletion of a custom list (future feature)