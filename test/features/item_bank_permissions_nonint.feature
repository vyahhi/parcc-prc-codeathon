@api @itembank @directions @prc-1023 @permissions
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
    Then I should see the link "NII T"

    # Log out
    Then I am an anonymous user

    # And log in as another user
    Given I am logged in as a user with the "PARCC-Member Educator" role
    And I am on "assessments/item-bank"
    Then I should not see the text "NII T"

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

    # Log out
    Then I am an anonymous user

    # And log in as another user
    Given I am logged in as a user with the "Educator" role
    And I am on "assessments/item-bank"
    Then I should see the text "NII T"
