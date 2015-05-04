@api @diglib @like
Feature: PRC-553 Social Media: PD Content "Like"
  As an educator, I want to rate a PD content and view others' rating for that content, so that good content can be spread out among my colleagues quickly.
  BACKGROUND: This story provides the same functionality as the story PRC-39, but for PD courses and modules.
  Acceptance Criteria
  In the Professional Development page where courses are displayed, a link/icon shall display "Like" and the number of users who clicked that link, like "Like (0)".
  At click, the system increments the number and label changes, like “Undo (3)”.
  Once “Undo” label is clicked, the system decrements the number and changes label back, like “Like (2)”.
  Same functionality shall be available in the course page for each module.

  Scenario: Like link in Professional Development view
    Given I have no "PD Course" nodes
    Given "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | Public     | This is public | public            | 1   | 1      |
    And I am logged in as a user with the "Educator" role
    And I am on "professional-learning"
    Then I should see the link "Public"
    And I should see the link "Like (0)"
    And I should not see the text "Undo"
    When I click "Like (0)"
    Then I should see the link "Undo (1)"
    And I should not see the text "Like"

    Then I am an anonymous user
    Then I am logged in as a user with the "Educator" role
    And I am on "professional-learning"
    Then I should see the link "Public"
    And I should see the link "Like (1)"
    And I should not see the text "Undo"
    When I click "Like (1)"
    Then I should see the link "Undo (2)"
    And I should not see the text "Like"
    Then I click "Undo (2)"
    And I should not see the text "Undo"
    And I should see the link "Like (1)"

  Scenario: Like link on Professional Development full view
    Given I have no "PD Course" nodes
    Given "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | Public     | This is public | public            | 1   | 1      |
    And I am logged in as a user with the "Educator" role
    And I am on "professional-learning"
    And I click "Public"
    And I should see the link "Like (0)"
    And I should not see the text "Undo"
    When I click "Like (0)"
    Then I should see the link "Undo (1)"
    And I should not see the text "Like"

  Scenario: PRC-910 User can't Like own content
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    Given "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | Public     | This is public | public            | @currentuid   | 1      |
    And I visit the last node created
    And I should not see the link "Like (0)"
    And I should not see the text "Undo"