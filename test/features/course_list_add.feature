@api @course @favorites
Feature: PRC-406 PD Custom List
  As an Educator,
  I want to create a PD custom list, and add a course to my custom list,
  so that I can find it easily the next time I access PRC.


#  An Add to My PD Lists link shall be available by each displayed course in Professional Development page for authenticated users.
#  The link allows a user to create and organize courses into customized lists. Once added, the list shall appear underneath MY PD Lists section of left panel, which is invisible when no custom list exists for that user. The create custom list and organize PD content into the custom lists functionality is the same as Digital Library custom lists functionality, defined in PRC-52 & PRC-53.
#  When My PD Lists is visible, an All Available Courses link on top of the left panel allows the user to remove the filter.

  Scenario: Add to My PD Lists shows PD list but not DL list
    Given I have no "PD Course" nodes
    Given I have no "Favorites List" nodes
    And I am logged in as a user with the "Educator" role
    And "Favorites List" nodes:
      | title       | uid         | status | field_content_type      |
      | My DLC List | @currentuid | 1      | digital_library_content |
      | My PDC List | @currentuid | 1      | pd_course               |
    And "PD Course" nodes:
      | title     | uid | status | field_permissions |
      | PRC-406-1 | 1   | 1      | public            |
      | PRC-406-2 | 1   | 1      | public            |
    And I am on the homepage
    When I follow "Professional Development"
    Then I should see the link "PRC-406-1"
    And I should see the link "Add to My PD Lists"
    When I click "Add to My PD Lists"
    Then I should not see the text "My DLC List"
    But I should see the text "My PDC List"

  Scenario: Add new list from PDC node makes the list a PDC list
    Given I have no "PD Course" nodes
    Given I have no "Favorites List" nodes
    And I am logged in as a user with the "Educator" role
    And "PD Course" nodes:
      | title     | uid | status | field_permissions |
      | PRC-406-1 | 1   | 1      | public            |
    And I am on the homepage
    When I follow "Professional Development"
    Then I should see the link "PRC-406-1"
    And I should see the link "Add to My PD Lists"
    When I click "Add to My PD Lists"
    And I click "Create New List"
    And I fill in "List Name *" with "PD Course List PRC-406"
    Then I press "Create"
    Then I should see the message containing "Created new"
    Then I should see the message containing "PD Course List PRC-406"
    Then I should see the message containing "list"
    Then I select "PD Course List PRC-406" from "List"
    Then I press "Add to List"
    Then I should see the message containing "The content is now associated with "
    And I should see the message containing "PD Course List PRC-406"

  Scenario: PDC Lists show up on the Professional Development page
    Given I have no "PD Course" nodes
    Given I have no "Favorites List" nodes
    And I am logged in as a user with the "Educator" role
    And "Favorites List" nodes:
      | title       | uid         | status | field_content_type      |
      | My DLC List | @currentuid | 1      | digital_library_content |
      | My PDC List | @currentuid | 1      | pd_course               |
    And "PD Course" nodes:
      | title     | uid | status | field_permissions |
      | PRC-406-1 | 1   | 1      | public            |
      | PRC-406-2 | 1   | 1      | public            |
    And I am on the homepage
    When I follow "Professional Development"
    Then I should see the link "My PDC List"
    But I should not see the link "My DLC List"

#  @javascript
  Scenario: Add PD Course to Favorites List and Filter
    Given I have no "PD Course" nodes
    And I am logged in as a user with the "Educator" role
    And "Favorites List" nodes:
      | title         | uid         | status | field_content_type      |
      | My DLC List   | @currentuid | 1      | digital_library_content |
      | My PDC List b | @currentuid | 1      | pd_course               |
      | My PDC List a | @currentuid | 1      | pd_course               |
      | My PDC List c | @currentuid | 1      | pd_course               |
    And "PD Course" nodes:
      | title     | uid | status | field_permissions |
      | PRC-406-1 | 1   | 1      | public            |
      | PRC-406-2 | 1   | 1      | public            |
    And I visit "professional-development"
    Then I click "Add to My PD Lists"
    And I select "My PDC List b" from "List"
    And I press "Add to List"
    Then I visit "professional-development"
    Then I should see the link "My PDC List a"
    Then I should see the link "My PDC List b"
    Then I should see the link "My PDC List c"
    Then I click "My PDC List b"
    And I should not see the link "PRC-406-2"
    And I should see the link "PRC-406-1"

  Scenario: PRC-481 PD Custom List- AC#2 section name should be "My PD Lists".
    Given I am logged in as a user with the "Educator" role
    And "Favorites List" nodes:
      | title         | uid         | status | field_content_type |
      | My DLC List   | @currentuid | 1      | pd_course          |
    When I visit "professional-development"
    Then I should see the text "My PD Lists"

  Scenario: PRC-482 PD Custom List- AC#3 "All Available Courses" link has wrong name.
    Given I am logged in as a user with the "Educator" role
    And "Favorites List" nodes:
      | title         | uid         | status | field_content_type |
      | My DLC List   | @currentuid | 1      | pd_course          |
    When I visit "professional-development"
    Then I should see the text "All Available Courses"
