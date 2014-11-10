@api
Feature: PRC-53 New Custom List Creation (End user)
  As an authenticated user,
  I want to create a new customized list,
  so that I can associate content with the newly created custom list.

  Scenario: In the Digital Library page where content is displayed, a new link Add to My Lists will be available.
    Given I am logged in as a user with the "Educator" role
    # Right now we are just using this line to create a node
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    And I am on the homepage
    Then I click "Digital Library"
    Then I should see the link "Add to My Lists"

  Scenario: On a content view page, a new link Add to My Lists will be available.
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

  Scenario: To create a new custom list, a Create New link is available in the menu.
    Given I am logged in as a user with the "Educator" role
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    And I click "Add to My Lists"
    Then I should see the link "Create new"
    And I should see the text "Add to My Lists"
    When I click "Create new"
    Then the url should match "favorites-list/\d+/nojs/create-list"

#  Once the Create New link is selected, an overlay opens with the following components:
#  Title: Add to My Lists
  Scenario: Add new list form
    Given I am logged in as a user with the "Educator" role
    And I am viewing a "Digital Library Content" node with the title "PRC-53 Add new list form"
    And I click "Add to My Lists"
    Then I click "Create new"
    Then I should see the link "Cancel"
    And I should see a "Create" button
    And I should see a "Please enter a new list name" field
    And I should see the text "Add to My Lists"
    When I click "Cancel"
    Then the url should match "favorites-list/\d+/nojs/add-to-list"

  Scenario: When Create button is clicked, the system will add the new list into the existing custom listing in Alphabetical order.
    Given I am logged in as a user with the "Educator" role
    And I am viewing a "Digital Library Content" node with the title "PRC-53 Add new list form"
    And I click "Add to My Lists"
    Then I click "Create new"
    And I should see a "Create" button
    Then I fill in "Please enter a new list name" with "Created by Behat"
    And I press "Create"
    Then I should see the message containing "Created new"
    Then I should see the message containing "Created by Behat"
    Then I should see the message containing "list"

  Scenario: Creating a new list makes it show up in the Add to Lists list
    Given I am logged in as a user with the "Educator" role
    And I am viewing a "Digital Library Content" node with the title "To Add To Lists"
    Then I click "Add to My Lists"
    Then I click "Create new"
    Then I fill in "Please enter a new list name" with "Created by Behat"
    And I press "Create"
    Then I select "Created by Behat" from "List"
