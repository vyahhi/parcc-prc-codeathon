@api @diglib @filter @prc-967
Feature: PRC-967 Search/Filter Bar: View the Digital Library Filters
  As a user,
  I want to be able to view the Digital Library filters,
  so that I can see the choices I have to refine the Gallery results.

  @prc-1537
  Scenario: Subject filters stay on first level
    Given I am logged in as a user with the "Educator" role
    And I have no "Digital Library Content" nodes
    # Use existing Subject, Grade Level, Media Type, because these are set up on install
    And "Digital Library Content" nodes:
      | title           | body                                 | status | uid | field_subject              | field_grade_level_unlimited | field_media_type |
      | Result One      | First Body                           | 1      | 1   | Math                       | 1st Grade                   | Text             |
      | Result Two      | Lorem ipsum doloranim id est laborum | 1      | 1   | Algebra                    | 11th Grade                  | Text             |
      | Result Three    | First Body                           | 1      | 1   | Calculus                   | 12th Grade                  | Text             |
      | Result Four     | Lorem ipsum doloranim id est laborum | 1      | 1   | Number System              | 2nd Grade                   | Text             |
      | Result Five     | First Body                           | 1      | 1   | Trigonometry               | 4th Grade                   | Text             |
      | Result Six      | Lorem ipsum doloranim id est laborum | 1      | 1   | World Languages            | 3rd Grade                   | Text             |
      | Result Seven    | First Body                           | 1      | 1   | Visual and Performing Arts | 7th Grade                   | Text             |
      | Result Eight    | Lorem ipsum doloranim id est laborum | 1      | 1   | Science                    | 8th Grade                   | Text             |
      | Result Nine     | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 6th Grade                   | Text             |
      | Result Ten      | First Body                           | 1      | 1   | History/Social Studies     | 5th Grade                   | Text             |
      | Result Eleven   | Lorem ipsum doloranim id est laborum | 1      | 1   | STEM                       | 9th Grade                   | Text             |
      | Result Twelve   | First Body                           | 1      | 1   | History/Social Studies     | 10th Grade                  | Text             |
      | Result Thirteen | First Body                           | 1      | 1   | History/Social Studies     | Kindergarten                | Text             |
      | Result Fourteen | Lorem ipsum doloranim id est laborum | 1      | 1   | World Languages            | Pre-K                       | Text             |
    And I index search results
    When I am on "library"
    Then I should see the link "Math (5)"
    But I should not see the link "Algebra (1)"
    When I click "Math (5)"
    Then I should not see the link "Algebra (1)"
    Then I should not see the link "Calculus (1)"
    Then I should not see the link "Number System (1)"
    Then I should not see the link "Trigonometry (1)"
