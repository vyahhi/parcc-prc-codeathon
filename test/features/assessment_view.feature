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
    Given I am logged in as a user with the "PRC Admin" role
    And "Quiz" nodes:
      | title                      | body   | field_grade_level | field_subject                | field_quiz_type   | uid         |
      | PRC-489 Assessment Title 1 | Body 1 | Middle School     | Educational Leadership, Math | Custom Assessment | @currentuid |
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
    # TODO: Write a date formatter for last updated date

    #    Summary/Description
    And I should see the text "Body 1"
    #    Grade
    And I should see the text "Grade Level:"
    And I should see the text "Middle School"
    #    Subject (comma-separated if more than one subject)
    And I should see the text "Subject:"
    And I should see the text "Educational Leadership, Math"
    #    (Actions are NOT part of this story).

    #  AC5 Left panel is NOT part of this story. Therefore, no filtering. All available assessments are listed.

  @javascript
  Scenario: PRC-534 Assessment update date sorting
    Given I am logged in as a user with the "PRC Admin" role
    And "Quiz" nodes:
      | title                      | body   | field_grade_level | field_subject                | field_quiz_type   | uid         |
      | PRC-534 Assessment Title 1 | Body 1 | Middle School     | Educational Leadership, Math | Custom Assessment | @currentuid |
      | PRC-534 Assessment Title 2 | Body 2 | Middle School     | Educational Leadership, Math | Custom Assessment | @currentuid |
      | PRC-534 Assessment Title 3 | Body 3 | Middle School     | Educational Leadership, Math | Custom Assessment | @currentuid |
    And I click "Assessments"
    Then "PRC-534 Assessment Title 1" should precede "PRC-534 Assessment Title 2" for the query "a"
    Then "PRC-534 Assessment Title 2" should precede "PRC-534 Assessment Title 3" for the query "a"
    When I click "PRC-534 Assessment Title 2"
    Then I click "Edit"
    And I fill in "Objectives" with "Body 2 Update"
    Then I wait 1 seconds
    Then I press "Save"
    When I click "Assessments"
    Then "PRC-534 Assessment Title 2" should precede "PRC-534 Assessment Title 1" for the query "a"
    Then "PRC-534 Assessment Title 1" should precede "PRC-534 Assessment Title 3" for the query "a"
