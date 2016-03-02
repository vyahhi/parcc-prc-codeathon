@api @itembank @prc-1337 @filter @parccitem
Feature: PRC-1337 Item Bank - PARCC Items Filter
  As a logged in user,
  I want to be able to filter the Item Bank by PARCC Items
  so that I can view only PARCC released items within the bank.

#  Scenario: 1 Default
#    Given that I am logged in
#    And I am on the Item Bank page
#    When the Filter area is expanded
#    Then I see a View filter section
#    And the options are:
#  PARCC Items	My Items
#    And PARCC and custom items are displayed by default within the Item Bank
#    And the items in the bank are sorted by "Last Updated"
#  Scenario: 2 Clicking on the PARCC Items Link
#    Given that I am logged in
#    And I am on the Item Bank page
#    And the Filter area is expanded
#    When I click the "PARCC Items" link (as seen in the Item Bank Wireframe)
#    Then I see that the "PARCC Items" link is selected
#    And the "My Items" link is unselected.
#    And that the item bank displays only PARCC items within the bank
#    And the items in the bank are sorted by "Last Updated"

#  Scenario: Default view
#    Given I am logged in as a user with the "Educator" role
#    When I am on "assessments/item-bank"
#    Then "- Any -" in "PARCC items" should be selected
#
#  Scenario: Filter selections
#    Given I am logged in as a user with the "Educator" role
#    And "multichoice" nodes:
#      | title         | body          | alternatives | parcc_item |
#      | AA PARCC Item | AA PARCC Item | Yes,No       | Yes        |
#      | BB My Item    | BB My Item    | Yes,No       | No         |
#    And I am on "assessments/item-bank"
#
#    When I select "- Any -" from "PARCC items"
#    And I press "Apply"
#    Then I should see the link "AA PARCC Item"
#    And I should see the link "BB My Item"
#
#    When I select "My items" from "PARCC items"
#    And I press "Apply"
#    Then I should not see the link "AA PARCC Item"
#    And I should see the link "BB My Item"
#
#    When I select "PARCC items" from "PARCC items"
#    And I press "Apply"
#    Then I should see the link "AA PARCC Item"
#    And I should not see the link "BB My Item"
