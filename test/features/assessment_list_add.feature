@api @course @favorites
Feature: PRC-610 Assessment Custom List
  As an Educator,
  I want to create a custom list for the assessments available to me, and add an assessment to my custom list,
  so that I can find it easily the next time I access PRC.
#  Given I am logged in as an authenticated user and I'm on the Assessments page, an Add to My Quiz Lists link/button shall be available on every assessment entry.
#  The link allows a user to create and organize tests into customized lists. Once added, the list shall appear underneath My Quiz Lists section of left panel, which is invisible when no custom list exists for that user. The create custom list and organize Assessments into the custom lists functionality is the same as Digital Library custom lists functionality, defined in PRC-52 & PRC-53.
#  When My Quiz Lists is visible, an All Available Assessments link on top of the left panel allows the user to remove the filter.

  Scenario: Add to My Quiz Lists shows Assessment list but not DL list or PD list
    Given I have no "Favorites List" nodes
    And I am logged in as a user with the "Educator" role
    And "Favorites List" nodes:
      | title       | uid         | status | field_content_type      |
      | My DLC List | @currentuid | 1      | digital_library_content |
      | My PDC List | @currentuid | 1      | pd_course               |
      | My Asm List | @currentuid | 1      | quiz                    |
    And "Subject" terms:
      | name  |
      | subj1 |
    And "Assessment" nodes:
      | title     | field_subject | field_quiz_type                    | author      |
      | PRC-610-1 | subj1         | PARCC-Released Practice Assessment | @currentuid |
      | PRC-610-2 | subj1         | PARCC-Released Practice Assessment | @currentuid |
    And I am on the homepage
    When I follow "Assessment"
    Then I should see the link "PRC-610-1"
    And I should see the link "Add to My Quiz Lists"
    When I click "Add to My Quiz Lists"
    Then I should not see the text "My DLC List"
    Then I should not see the text "My PDC List"
    But I should see the text "My Asm List"

  Scenario: Add new list from Quiz node makes the list a Quiz list
    Given I have no "PD Course" nodes
    Given I have no "Favorites List" nodes
    And I am logged in as a user with the "Educator" role
    And "Subject" terms:
      | name  |
      | subj1 |
    And "Assessment" nodes:
      | title     | field_subject | field_quiz_type                    | author      |
      | PRC-610-1 | subj1         | PARCC-Released Practice Assessment | @currentuid |
    And I am on the homepage
    When I follow "Assessment"
    Then I should see the link "PRC-610-1"
    And I should see the link "Add to My Quiz Lists"
    When I click "Add to My Quiz Lists"
    And I click "Create New List"
    And I fill in "List Name *" with "Quiz List PRC-610"
    Then I press "Create"
    Then I should see the message containing "Created new"
    Then I should see the message containing "Quiz List PRC-610"
    Then I should see the message containing "list"
    Then I select "Quiz List PRC-610" from "List"
    Then I press "Add to List"
    Then I should see the message containing "The content is now associated with "
    And I should see the message containing "Quiz List PRC-610"

  Scenario: Quiz Lists show up on the Assessments page
    Given I have no "Favorites List" nodes
    And I am logged in as a user with the "Educator" role
    And "Favorites List" nodes:
      | title            | uid         | status | field_content_type      |
      | My DLC List      | @currentuid | 1      | digital_library_content |
      | My PDC List      | @currentuid | 1      | pd_course               |
      | My Quiz 610 List | @currentuid | 1      | quiz                    |
    And "Subject" terms:
      | name  |
      | subj1 |
    And "Assessment" nodes:
      | title     | field_subject | field_quiz_type                    | author      |
      | PRC-610-1 | subj1         | PARCC-Released Practice Assessment | @currentuid |
    And I am on the homepage
    When I follow "Assessment"
    Then I should see the link "My Quiz 610 List"
    But I should not see the link "My DLC List"
    But I should not see the link "My PDC List"

  Scenario: Add Quiz to Favorites List and Filter
    And I am logged in as a user with the "Educator" role
    And "Favorites List" nodes:
      | title          | uid         | status | field_content_type      |
      | My DLC List    | @currentuid | 1      | digital_library_content |
      | My PDC List    | @currentuid | 1      | pd_course               |
      | My Quiz List a | @currentuid | 1      | quiz                    |
      | My Quiz List b | @currentuid | 1      | quiz                    |
      | My Quiz List c | @currentuid | 1      | quiz                    |
    And "Subject" terms:
      | name  |
      | subj1 |
    And "Assessment" nodes:
      | title     | field_subject | field_quiz_type                    | author      |
      | PRC-610-1 | subj1         | PARCC-Released Practice Assessment | @currentuid |
      | PRC-610-2 | subj1         | PARCC-Released Practice Assessment | @currentuid |
    And I visit "assessments"
    Then I click "Add to My Quiz Lists"
    And I select "My Quiz List b" from "List"
    And I press "Add to List"
    Then I visit "assessments"
    Then I should see the link "My Quiz List a"
    Then I should see the link "My Quiz List b"
    Then I should see the link "My Quiz List c"
    Then I click "My Quiz List b"
    And I should not see the link "PRC-610-2"
    And I should see the link "PRC-610-1"

  Scenario: Section name My Quiz Lists
    Given I am logged in as a user with the "Educator" role
    And "Favorites List" nodes:
      | title     | uid         | status | field_content_type |
      | My Q List | @currentuid | 1      | quiz               |
    When I visit "assessments"
    Then I should see the text "My Quiz Lists"

  Scenario: All Available Assessments link
    Given I am logged in as a user with the "Educator" role
    And "Favorites List" nodes:
      | title        | uid         | status | field_content_type |
      | My Quiz List | @currentuid | 1      | quiz               |
    When I visit "assessments"
    Then I should see the text "All Available Assessments"
