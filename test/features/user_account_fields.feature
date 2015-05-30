@api @d7 @user
Feature: PRC ??? - User profile fields
  As an educator,
  I want to edit my extended profile fields
  so PARCC can have deeper demographic data for its users.

  Scenario: User extended profile fields
    Given I am logged in as a user with the "Educator" role
    Then I follow "My account"
    Then I click "Edit"
    And I should see the text "State Where I Teach"
    And I should see the text "First Name"
    And I should see the text "Last Name"
    And I should see the text "Profession"
    And I should see the text "About Me"
    And I should see the text "Tell everyone a little about yourself."
    And I should see the text "Subject I Teach"
    And I should see the text "What subject\(s\) do you teach?"
    And I should see the text "Grade Level I Teach"
    And I should see the text "What grade levels do you teach?"
    And I should see the text "Areas of Interest"

  Scenario: Viewing my profile
#  | name                                | mail                               | pass   | field_first_name | field_last_name | status | field_profession | field_about_me | field_subject | field_grade_level_unlimited | field_areas_of_interest_unlimite |
#  | joe_prc_346a@timestamp@example.comn | joe_prc_346a@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Teacher          | My Bio         | Chemistry     | 1st Grade                   | Fishing                          |
    Given users:
      | name                                | mail                               | pass   | field_first_name | field_last_name | status | field_profession | field_about_me |
      | joe_prc_346a@timestamp@example.comn | joe_prc_346a@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Teacher          | My Bio         |
    When I follow "My account"
    Then I should see the text "Joe"
    And I should see the text "Educator"
    And I should see the text "Teacher"
    And I should see the text "My Bio"
    And I should see the text "Chemistry"
    And I should see the text "1st Grade"
    And I should see the text "2nd Grade"
    And I should see the text "Fishing"
    And I should see the text "Hiking"
