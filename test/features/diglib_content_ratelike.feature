@api @diglib @like
Feature: PRC-39 Rate/Like Content (end user)
  As an educator, I want to rate a content and view others' rating for that content, so that good content can be spread out among my colleagues quickly.
  BACKGROUND: This story captures and displays the number of people who liked a content. It is not yet defined how the popularity algorithm is calculated or used.
  AC1 In the Digital Library page where content is displayed, a link/icon shall display the number of users who clicked that link.
  AC2 At click, the system increment that number.
  AC3 Once clicked, the link label changes to undo (while keeping the count), and decrements if clicked.
  AC4 Same functionality shall be available in the content details page.

  Scenario: Like link in Digital Library view
    Given I have no "Digital Library Content" nodes
    Given "Digital Library Content" nodes:
      | title      | body           | field_permissions | uid | status |
      | Public     | This is public | public            | 1   | 1      |
    And I am logged in as a user with the "Educator" role
    And I am on "digital-library"
    Then I should see the link "Public"
    And I should see the link "Like (0)"
    And I should not see the text "Undo"
    When I click "Like (0)"
    Then I should see the link "Undo (1)"
    And I should not see the text "Like"

    Then I am an anonymous user
    Then I am logged in as a user with the "Educator" role
    And I am on "digital-library"
    Then I should see the link "Public"
    And I should see the link "Like (1)"
    And I should not see the text "Undo"
    When I click "Like (1)"
    Then I should see the link "Undo (2)"
    And I should not see the text "Like"
    Then I click "Undo (2)"
    And I should not see the text "Undo"
    And I should see the link "Like (1)"

  Scenario: Like link on Digital Library full view
    Given I have no "Digital Library Content" nodes
    Given "Digital Library Content" nodes:
      | title      | body           | field_permissions | uid | status |
      | Public     | This is public | public            | 1   | 1      |
    And I am logged in as a user with the "Educator" role
    And I am on "digital-library"
    And I click "Public"
    And I should see the link "Like (0)"
    And I should not see the text "Undo"
    When I click "Like (0)"
    Then I should see the link "Undo (1)"
    And I should not see the text "Like"