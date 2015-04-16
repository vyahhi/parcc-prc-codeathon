# Leaving this test out because Quiz currently isn't letting us delete this properly

#@api @itembank @prc-1009
#Feature: PRC-1009 Item Bank - Create New Non-PARCC Item - Item Created
#  As a logged in user, I want to see the non-PARCC item I created in the item bank so that I know I have successfully created the item.
#  Acceptance Criteria
#
#  Scenario 1: User is not a PRC Item Author
#    And all my fields are valid
#    When I press the Submit button
#    Then I see the Item Bank page displaying:
#  The item I created
#  The "PARCC Item?" column for the item populated with "No"
#    And any filters and search terms are cleared
#    And the table is sorted by the default sort (reverse-chronological order by last-updated date)
#
#  Scenario 2: User is a PRC Item Author
#    Given that I am logged in as a PRC Item Author
#    And I am on the Create Non-Interactive Item page, the Create Interactive Choice Item page or the Create Short Answer Item page
#    And I do not check the "Make this a PARCC item" check box
#    And all my fields are valid
#    When I press the Submit button
#    Then I see the Item Bank page displaying:
#  The item I created
#  The "PARCC Item?" column for the item populated with "No"
#    And any filters and search terms are cleared
#    And the table is sorted by the default sort (reverse-chronological order by last-updated date)
#  Additional Considerations
#  Applies to creation of all item types:
#  Non-Interactive Item
#  Interactive Choice Item and
#  Short Answer Item
#
#  Scenario: User is not a PRC Item Author
#    Given I am logged in as a user with the "Educator" role
#    And I am on "item-bank"
#    And I click "Short answer"
#    And I fill in "Title" with "SAT"
#    And I fill in "Question" with "Question text"
#    And I fill in "Correct answer" with "Right"
#    And I select "5th Grade" from "Grade Level"
#    And I fill in the hidden field "faux_standard" with "Short Answer Standard"
#    And I should not see the text "Make this a PARCC Item"
#    When I press "Submit"
#    Then I should be on "item-bank"
