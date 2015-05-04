@api @diglib @favorites @prc-52
Feature: PRC-52 Existing Custom List- Organize/Structure Content (End user)
  As an authenticated user,
  I want to organize content into one of my existing custom lists,
  so that I can locate the content quickly and as needed.

  Scenario: ACx Anonymous cannot see Add to My Lists
    Given I am an anonymous user
    And I am viewing a "Digital Library Content" node with the title "PRC-52 Anonymous Link"
    Then I should not see the link "Add to My Lists"

  Scenario: AC1 In the Digital Library page where all the content is listed, a new link called Add to My Lists will be available.
    Given I am logged in as a user with the "Educator" role
    And I have no "digital_library_content" nodes
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    And I index search results
    And I am on the homepage
    Then I click "Library"
    Then I should see the link "Add to My Lists"
    Then I click "Add to My Lists"
    Then I should see a "List" field
    And the "List" select box should be empty
    And I should see the link "Create New List"
    And I should see an "Add to List" button

  Scenario: AC4e, With a previously existing list
    Given I am logged in as a user with the "Educator" role
    And I have no "digital_library_content" nodes
    # Right now we are just using this line to create a node
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    And I index search results
    And I am viewing my "favorites_list" node with the title "My Only List"
    And I am on the homepage
    Then I click "Library"
    # AC1
    Then I should see the link "Add to My Lists"
    Then I click "Add to My Lists"
    Then I should see a "List" field
    Then I select "My Only List" from "List"

  Scenario: AC4e, With 10 previously existing lists
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
    And I index search results
    And I am on the homepage
    Then I click "Library"
    # AC1
    Then I should see the link "Add to My Lists"
    Then I click "Add to My Lists"
    Then I should see a "List" field
    Then I select "first list" from "List"
    Then I select "second list" from "List"
    Then I select "third list" from "List"
    Then I select "tenth list" from "List"

    And "eighth list" should precede "fifth list" for the query "#edit-select-list option"
    And "fifth list" should precede "first list" for the query "#edit-select-list option"
    And "first list" should precede "fourth list" for the query "#edit-select-list option"


  Scenario: AC9 Selecting a list
    Given I am logged in as a user with the "Educator" role
    And I am viewing my "favorites_list" node with the title "My Only List"
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    Then I click "Add to My Lists"
    Then I select "My Only List" from "List"
    Then I press "Add to List"
    # Now how do we verify that the node was referenced by the list?

  Scenario: AC4a Item gets added to list
    Given I am logged in as a user with the "Educator" role
    And I am viewing my "favorites_list" node with the title "My Only List"
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    Then I click "Add to My Lists"
    Then I select "My Only List" from "List"
    Then I press "Add to List"
    Then I should see the message containing "The content is now associated with "
    And I should see the message containing "My Only List"
    # Due to goutte tests not using js, this won't appear in a popup.
    # That means that this test will not pass by simply adding a @javascript
    # tag.
    Then I visit the first node created
    And I should see the heading "My Only List" in the "content" region
    And I should see the text "Favorite Content:"
    And I should see the text "To Add To Lists"
    And I should see the text "Content Type:"
    And I should see the text "Digital Library Content"
    And I should see 2 ".field-item" elements

  Scenario: AC8 Item can only be added to a list once
    Given I am logged in as a user with the "Educator" role
    And I am viewing my "favorites_list" node with the title "My Only List"
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    Then I click "Add to My Lists"
    Then I select "My Only List" from "List"
    Then I press "Add to List"
    Then I should see the message containing "The content is now associated with "
    And I should see the message containing "My Only List"
    Then I press "Add to List"
    Then I press "Add to List"
    Then I visit the first node created
#    Then I reload the page
    And I should see the heading "My Only List" in the "content" region
    And I should see the text "Favorite Content:"
    And I should see the text "To Add To Lists"
    And I should see the text "Content Type:"
    And I should see the text "Digital Library Content"
    And I should see 2 ".field-item" elements

  Scenario: AC8? Multiple items can be added to a list
    Given I am logged in as a user with the "Educator" role
    And I am viewing my "favorites_list" node with the title "My Only List"
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    Then I click "Add to My Lists"
    Then I select "My Only List" from "List"
    Then I press "Add to List"
    Then I should see the message containing "The content is now associated with "
    And I should see the message containing "My Only List"
    Then I visit the first node created
    And I should see 2 ".field-item" elements
    # View another node and add it
    And I am viewing a "Digital Library Content" node with the title "Another Favorite Item"
    Then I click "Add to My Lists"
    Then I select "My Only List" from "List"
    Then I press "Add to List"
    Then I should see the message containing "The content is now associated with "
    And I should see the message containing "My Only List"
    Then I visit the first node created
    Then I reload the page
    And I should see 3 ".field-item" elements

#  Acceptance Criteria
#  AC1 In the Digital Library page where all the content is listed, a new link called Add to My Lists will be available.
#  AC2 Once the Add to My Lists link is selected, an overlay module will appear with "Add to My List" displaying in the title section.
#  AC3 The authenticated user can associate specific content to any of the custom items, by selecting a specific item from the list displayed.
#  AC4 The components will display:
#    A Create New List link (covered in story PRC-53): The authenticated user can create a new custom list item.
#    Label called "List"
#    Select the list you would like to use to categorize this content.
#    Search field (Combobox/Autocomplete dropdown is one field.)
#    A list of existing custom items: This list contains the custom lists the current user has already created.
#  AC5 To filter the existing custom list results, the authenticated user will select the drop down list and begin typing.
#  AC6 If the entered value does not match any of the existing custom lists, the following message will display:
#    No results match "<entered characters here>"
#  AC7 Selecting the list name does not save the content/custom list association and dismiss the form.
#  AC8 Content can be associated to only one list at a time.
#  AC9 An Add to List button will save the association between the content and the existing list and will close the overlay module.