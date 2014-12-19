@api @assessment
Feature: PRC-489 View A List of Tests
  As an educator,
  I want to access and view the practice tests released by PARCC,
  so that I can use them as is or make tweaks to fit my needs.

  Scenario: AC1 An Assessments tab exists and is available to all user roles. At click, it opens a new page Assessments (anonymous).
    Given I am an anonymous user
    And I am on the homepage
    Then I should see the link "Assessments"
    When I click "Assessments"
    Then I should see the heading "Assessments" in the "content" region

  Scenario Outline: AC1 Assessments tab for all roles
    Given I am logged in as a user with the "<role>" role
    And I am on the homepage
    Then I should see the link "Assessments"
    When I click "Assessments"
    Then I should see the heading "Assessments" in the "content" region
    Examples:
      | role                            |
      | administrator                   |
      | PRC Admin                       |
      | Content Administrator (Curator) |
      | Educator                        |
      | PARCC-Member Educator           |

  Scenario: Assessment View
    Given I am logged in as a user with the "Educator" role
    And "Assessment" nodes:
    | title                      | body   |
    | PRC-489 Assessment Title 1 | Body 1 |
    And I click "Assessments"
    # AC4 The assessment title shall be a link that opens the test (future story)
    Then I should see the link "PRC-489 Assessment Title 1"

    # AC3 Sort: The only option for now shall be: Date- most recent on the top
    And I select "Date" from "Sort by"
    And I select "most recent on top" from "Order"
    And I select "oldest on top" from "Order"

    #  AC2 Similar to Digital Library and Professional Development pages, the Assessments page contains a list of available tests, displaying the following components for each assessment:
    #    Assessment Title
    And I should see the text "PRC-489 Assessment Title 1"
    #    Publish date
    #    Summary/Description
    And I should see the text "Body 1"
    #    Grade
    #    Subject (comma-separated if more than one subject)
    #    (Actions are NOT part of this story).

    #  AC5 Left panel is NOT part of this story. Therefore, no filtering. All available assessments are listed.

