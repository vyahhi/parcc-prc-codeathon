@api @itembank @directions @prc-1023
Feature: PRC-1023 Item Bank - Edit Non-Interactive Item - Form
  As a logged in user,
  I want to be able to edit a non-PARCC, non-interactive, text-only item from the Item Bank
  so that I can make the changes I want to make.

#  Scenario 1: User is not a PARCC Item Author
#    Given I am logged in
#    And I am on the Item Bank page
#    When I click Edit link / button associated with the non-interactive item
#    Then I see the Edit Non-interactive Item (text only) page:
#  Differences from Item Bank - Create Non-PARCC Non-interactive Item (text only) - Form (PRC-1007)
#  Fields are populated with previously submitted changes

  Scenario: User is not a PARCC Item Author
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "NII T"
    And I fill in "Question" with "NII Question"
    And I press "Save"
    When I click "Edit"
    Then the "Title" field should contain "NII T"
    And the "Question" field should contain "NII Question"
    When I fill in "Title" with "NI Take Two"
    And I press "Save"
    Then I should see the link "NI Take Two"

  Scenario: User is a PARCC Item Author
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "NII T"
    And I fill in "Question" with "NII Question"
    And I check "Make this a PARCC item"
    And I press "Save"
    Then I should see the text "Yes" in the "NII T" row
    When I click "Edit"
    Then the "Title" field should contain "NII T"
    And the "Question" field should contain "NII Question"
    When I fill in "Title" with "NI Take Two"
    And I uncheck "Make this a PARCC item"
    And I press "Save"
    Then I should see the link "NI Take Two"
    Then I should see the text "No" in the "NI Take Two" row

#  Scenario 2: User is a PARCC Item Author
#    Given I am logged in as a PARCC Item Author
#    And I am on the Item Bank page
#    When I click Edit link / button associated with the non-interactive item (either PARCC or non-PARCC)
#    Then I see the Edit Non-interactive Item (text only) page:
#  Differences from Item Bank - Create PARCC Non-interactive Item (text only) - Form (PRC-1273)
#  Fields are populated with previously submitted changes