@api
Feature: PRC-253 - Organize Content: Filter by Custom List
  As an Educator,
  I want to filter the listed content to include the ones I organized into my custom list,
  so that I can quickly find the content I want.

  Scenario: A left panel exists on Digital Library with my lists
    Given I am logged in as a user with the "Educator" role
    # Creating lists out of numerical order so we can test alpha sort
    And I am viewing my "Favorites List" node with the title "List 2"
    And I am viewing my "Favorites List" node with the title "List 4"
    And I am viewing my "Favorites List" node with the title "List 3"
    And I am viewing my "Favorites List" node with the title "List 1"



#  Acceptance Criteria
#  AC1 In the Digital Library page, place a left panel containing a expandable/collapsable section as My Lists .
#  AC2 A View All option shall be available above (ouside of) the list, and is selected by default and does not filter any content
#  AC3 The My Lists control is expanded by default when there is content in it ( not visible when no list created
#  AC4 The custom lists that the current user has created so far shall be listed
#  AC5 When a list is clicked, the list of content in the middle of the screen filters to display only the content associated to that list.
#  AC6 The lists shall be listed in alphabetical order, A to Z
#  Additional Considerations
#  So far, no story has covered de-association or deletion of a custom list (future feature)