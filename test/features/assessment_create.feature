@api @assessment
Feature: PRC-521 Create a New Quiz
  As an educator, I want to add a new test, so that I can utilize my customized test with my classroom later.

  AC1 In the Assessments page(implemented in PRC-489), add a new Create New Quiz button/link. At click, open a new Create New Quiz page with the following specifications.
  Page title: Create Quiz
  Instruction: a dummy text for now.
  The following attributes shall be captured:
  Title: textbox string(255)- Required
  Objectives: free text- Optional- no size limit
  Subject: Dropdown menu (options are same as the current ones for content and courses)- at least one subject is required. multiple subjects can be selected. Drill-down subject shall be available.
  Grade: Dropdown menu (options are same as the current ones for content and courses)- Required
  AC2 An Add link/button to add an item to the test shall be defined in future stories (PRC-547).
  AC3 A Save Draft button is available to save the new quiz. At click, the system stores the data associated to the current user.
  AC4 If a user navigates away from the page without saving the changes, the system prompts the user to confirm.
  AC5 Permissions: All the above features are available to all roles, except for anonymous users (Future stories: e.g. PRC-526)

  Scenario: Anonymous can't add quiz

  Scenario Outline: Add quiz - form
    Given I am logged in as a user with the "<role>" role
    And I am on "assessments"
    Then I follow "Create New Quiz"
    Then I should see the heading "Create Quiz" in the "content" region
    Then I should see the text "Title *"
    And I should see the text "Objectives"
    And I should see the text "Subject *"
    And I should see the text "Grade *"
    And I should see a "Save Draft" button
    And I should see an "Add" link
    Examples:
      | role                            |
      | Educator                        |
      | Content Contributor             |
      | PRC Admin                       |
      | Content Administrator (Curator) |
      | authenticated user              |

  Scenario: Hidden fields!
    Given I am logged in as a user with the "Educator" role
    And I am on "assessments"
    When I follow "Create New Quiz"
    Then I should not see the text "Quiz Type"
    And I should not see the text "Remember my settings"
    And I should not see the text "Taking options"
    And I should not see the text "Result feedback"
    And I should not see the text "Pass/fail options"
    And I should not see the text "Availability options"
    And I should not see the text "Remember as global"

  Scenario: Educator creates a quiz
    Given I am logged in as a user with the "Educator" role
    Given "Subject" terms:
      | name  |
      | subj1 |
    And "Grade Level" terms:
      | name      |
      | Grade 521 |
    And I am on "assessments"
    Then I follow "Create New Quiz"
    And I fill in "Title" with "PRC-521 @timestamp"
    And I fill in "Objectives" with "PRC-521 @timestamp Objectives"
    And I select "Grade 521" from "Grade"
    # Subject is javascript-only. Leave it out of here.
    And I press "Save Draft"
    Then I should see the message "has been created."
