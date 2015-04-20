@api @assessment @permissions
Feature: Custom assessments are only visible to their creators

  Scenario: Any user can view PARCC-Released Practice Assessment, but only their own custom
    Given I am logged in as a user with the "Educator" role
    And "Quiz" nodes:
      | title       | uid         |
      | My Untagged | @currentuid |
      | U1 Untagged | 1           |
    And "Quiz" nodes:
      | title      | uid         | field_quiz_type                    |
      | My Custom  | @currentuid | Custom Assessment                  |
      | My PD Exam | @currentuid | PD Exam                            |
      | My PRC Q   | @currentuid | PARCC-Released Practice Assessment |
      | U1 Custom  | 1           | Custom Assessment                  |
      | U1 PD Exam | 1           | PD Exam                            |
      | U1 PRC Q   | 1           | PARCC-Released Practice Assessment |
    When I visit "assessments"
    Then I should see the link "My Custom"
    And I should not see the link "My PD Exam"
    And I should see the link "My PRC Q"
    And I should not see the link "U1 Custom"
    And I should not see the link "U1 PD Exam"
    And I should see the link "U1 PRC Q"
