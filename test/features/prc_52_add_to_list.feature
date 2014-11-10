@api
Feature: PRC-52 Existing Custom List- Organize/Structure Content (End user)
  As an authenticated user,
  I want to organize content into one of my existing custom lists,
  so that I can locate the content quickly and as needed.

  Scenario: Anonymous cannot see Add to My Lists
    Given I am an anonymous user
    And I am viewing a "Digital Library Content" node with the title "PRC-52 Anonymous Link"
    Then I should not see the link "Add to My Lists"

  Scenario: No previously existing lists
    Given I am logged in as a user with the "Educator" role
    And I have no "digital_library_content" nodes
    # Right now we are just using this line to create a node
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    And I am on the homepage
    Then I click "Digital Library"
    # AC1
    Then I should see the link "Add to My Lists"
    Then I click "Add to My Lists"
    Then I should see a "List" field
    And the "List" select box should be empty
    
    And I should see the link "Create new"
    And   I should see an "Add to List" button

  Scenario: With a previously existing list
    Given I am logged in as a user with the "Educator" role
    And I have no "digital_library_content" nodes
    # Right now we are just using this line to create a node
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    And I am viewing my "favorites_list" node with the title "My Only List"
    And I am on the homepage
    Then I click "Digital Library"
    # AC1
    Then I should see the link "Add to My Lists"
    Then I click "Add to My Lists"
    Then I should see a "List" field
    Then I select "My Only List" from "List"

  Scenario: With 10 previously existing lists
    Given I am logged in as a user with the "Educator" role
    And I have no "digital_library_content" nodes
    # Right now we are just using this line to create a node
    And "Favorites List" nodes:
    | title        | uid         |
    | first list   | @currentuid |
    | second list  | @currentuid |
    | third list   | @currentuid |
    | fourth list  | @currentuid |
    | fifth list   | @currentuid |
    | sixth list   | @currentuid |
    | seventh list | @currentuid |
    | eighth list  | @currentuid |
    | ninth list   | @currentuid |
    | tenth list   | @currentuid |
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    And I am on the homepage
    Then I click "Digital Library"
    # AC1
    Then I should see the link "Add to My Lists"
    Then I click "Add to My Lists"
    Then I should see a "List" field
    Then I select "first list" from "List"
    Then I select "second list" from "List"
    Then I select "third list" from "List"
    Then I select "tenth list" from "List"

  Scenario: Selecting a list
    Given I am logged in as a user with the "Educator" role
    And I am viewing my "favorites_list" node with the title "My Only List"
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    Then I click "Add to My Lists"
    Then I select "My Only List" from "List"
    Then I press "Add to List"
    # Now how do we verify that the node was referenced by the list?


  #  Acceptance Criteria
  # AC1 In the Digital Library page where all the content is listed, a new link called Add to My Lists will be available.
  # AC2 Once the Add to My Lists link is selected, a list of existing custom items will appear.
#  AC3 The educator can associate specific content to any of the custom items, by selecting a specific item from the list displayed.
#  AC4 The menu contains:
#    A "Add to My Lists" Label & Textbox: The user can start typing a custom list name in order to narrow down the number of custom lists displayed.
#    A Create New link (covered in story PRC-53): The educator can create a new custom list item.
#    A list of existing custom items: This list contains the custom lists the current user has already created. This list gets smaller based on what the user enters in the "Add to My List" textbox.
#    If the entered value does not match any of the existing custom lists, the only available option will be the Create New link
#  AC5 Content can be associated to only one list at a time.
#  AC6 When a custom list is clicked, the system will associate the content to the selected custom list and close the overlay.
