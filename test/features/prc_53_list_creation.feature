@api
Feature: PRC-53 New Custom List Creation (End user)
  As an authenticated user,
  I want to create a new customized list,
  so that I can associate content with the newly created custom list.

  Scenario: In the Digital Library page where content is displayed, a new link Add to My Lists will be available.
    Given I am logged in as a user with the "Educator" role
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    Then I should see the link "Add to My Lists"

  Scenario Outline: Roles can edit a list
    Given I am logged in as a user with the "<role>" role
    Then I should be able to edit my own "Favorites List" node
    Examples:
      | role                  |
      | Educator              |
      | PARCC-Member Educator |
      | Content Contributor   |
      | PRC Admin             |
      | administrator         |

#  Once the Add to My Lists link is selected, the educator can add a new custom list and associate selected content to the new list.
#  To create a new custom list, a Create New link is available in the menu.
#  Once the Create New link is selected, an overlay opens with the following components:
#  Title: Add to My Lists
#  Custom List Name textbox with the following label:
#  Please enter a new list name:
#  A Create button
#  A Cancel button
#  When Create button is clicked, the system will add the new list into the existing custom listing in Alphabetical order.
#  When the Cancel button is selected, the overlay closes without the items added to the list.