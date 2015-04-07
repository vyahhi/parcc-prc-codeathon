@api @diglib @favorites @prc-53
Feature: PRC-53 New Custom List Creation (End user)
  As an authenticated user,
  I want to create a new customized list,
  so that I can associate content with the newly created custom list.


#  Acceptance Criteria
#  1. In the Digital Library page where content is displayed, a new link Add to My Lists will be available.
#  2. Once the Add to My Lists link is selected, an overlay module will appear with "Add to My List" displaying in the title section.
#  3. The authenticated user will be able to add a new custom list and associate selected content to the new list.
#  4. To create a new custom list, a Create New List link will display within the "Add to My List" overlay module.
#  5. Once the Create New List link is selected, the following components will display:
#  "List Name" label, text box, and the following instructions:
#  Please enter a name for the new list.
#  A Create button
#  A Cancel link
#  6. When Create button is selected, the system will add the new list into the existing custom listing in Alphabetical order.
#  7. When the Cancel link is selected, the authenticated user will be directed back to the default view of the "Add to My List" overlay.
#  8. Validations:
#  Validate that all required fields contain valid values. If not, the system displays a red frame around the section or field text box, and provides feedback on the top of the form:
#  <Missing required> field is required.


  Scenario: AC1 In the Digital Library page where content is displayed, a new link Add to My Lists will be available.
    Given I am logged in as a user with the "Educator" role
    # Right now we are just using this line to create a node
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    And I index search results
    And I am on the homepage
    Then I click "Digital Library"
    Then I should see the link "Add to My Lists"

  Scenario: AC1a On a content view page, a new link Add to My Lists will be available.
    Given I am logged in as a user with the "Educator" role
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    Then I should see the link "Add to My Lists"

  Scenario Outline: AC3 Roles can edit a list
    Given I am logged in as a user with the "<role>" role
    Then I should be able to edit my own "Favorites List" node
    Examples:
      | role                  |
      | Educator              |
      | PARCC-Member Educator |
      | Content Contributor   |
      | PRC Admin             |
      | administrator         |

  Scenario: AC4 To create a new custom list, a Create New List link will display within the "Add to My List" overlay module.
    Given I am logged in as a user with the "Educator" role
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    And I click "Add to My Lists"
    Then I should see the link "Create New List"
    And I should see the text "Add to My Lists"
    When I click "Create New List"
    Then the url should match "favorites-list/\d+/nojs/create-list"

#  Once the Create New link is selected, an overlay opens with the following components:
#  Title: Add to My Lists
  Scenario: AC5 Add new list form / AC7 Cancel button
    Given I am logged in as a user with the "Educator" role
    And I am viewing a "Digital Library Content" node with the title "PRC-53 Add new list form"
    And I click "Add to My Lists"
    Then I click "Create New List"
    Then I should see the link "Cancel"
    And I should see a "Create" button
    And I should see a "List Name" field
    And I should see the text "Add to My Lists"
    And I should see the text "Please enter a name for the new list."
    When I click "Cancel"
    Then the url should match "favorites-list/\d+/nojs/add-to-list"

  Scenario: AC6 When Create button is clicked, the system will add the new list into the existing custom listing in Alphabetical order.
    Given I am logged in as a user with the "Educator" role
    And I am viewing a "Digital Library Content" node with the title "PRC-53 Add new list form"
    And I click "Add to My Lists"
    Then I click "Create New List"
    And I should see a "Create" button
    Then I fill in "List Name" with "Created by Behat"
    And I press "Create"
    Then I should see the message containing "Created new"
    Then I should see the message containing "Created by Behat"
    Then I should see the message containing "list"
    # Add another one before the letter C in alpha order to test ordering
    Then I click "Create New List"
    And I should see a "Create" button
    Then I fill in "List Name" with "Another One by Behat"
    And I press "Create"
    Then I should see the message containing "Created new"
    Then I should see the message containing "Another One by Behat"
    Then I should see the message containing "list"
    # Now here check the order
    Then "Another One by Behat" should precede "Created by Behat" for the query "#edit-select-list option"

  Scenario: Creating a new list makes it show up in the Add to Lists list
    Given I am logged in as a user with the "Educator" role
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    Then I click "Add to My Lists"
    Then I click "Create New List"
    Then I fill in "List Name" with "Created by Behat"
    And I press "Create"
    Then I select "Created by Behat" from "List"

