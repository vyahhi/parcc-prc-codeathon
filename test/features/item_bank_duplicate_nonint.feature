@api @itembank @directions @prc-1035 @prc-1038 @prc-1412
Feature: PRC-1035 Item Bank - Duplicate Non-Interactive Item - Form
  As a logged in user,
  I want to be able to duplicate a non-interactive, text-only item from the Item Bank
  so that I can use another item as the basis for a new item.

#  Acceptance Criteria
#  Scenario 1: User is not a PARCC Item Author
#    Given I am logged in
#    And I am on the Item Bank page
#    When I click Duplicate link / button associated with the non-interactive item
#    Then I see the Duplicate Non-interactive Item (text only) page:
#  Differences from Item Bank - Edit Non-Interactive Item - Form (PRC-1023) Scenario 1
#  Item Title is preceded by "COPY - " [Jack will update with drupal / treatment for duplicating assessment w.r.t. appending "copy" to title.]
#  Scenario 2: User is a PARCC Item Author
#    Given I am logged in as a PARCC Item Author
#    And I am on the Item Bank page
#    When I click Duplicate link / button associated with the non-interactive item (either PARCC or non-PARCC)
#    Then I see the Duplicate Non-interactive Item (text only) page:
#  Differences from Item Bank - Edit Non-Interactive Item - Form (PRC-1023) Scenario 2
#  Item Title is preceded by "COPY - " [Jack will update with drupal / treatment for duplicating assessment w.r.t. appending "copy" to title.]
#

  Scenario: User is not a PARCC Item Author
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "NII T"
    And I fill in "Question" with "NII Question"
    And I press "Save"
    When I click "Duplicate"
    Then the "Title" field should contain "Clone of NII T"
    And the "Question" field should contain "NII Question"
    And I press "Save"
    Then I should see the link " NII T"
    Then I should see the link "Clone of NII T"
    Then I should see the text "No" in the "Clone of NII T" row

  Scenario: User is a PARCC Item Author and Make this a PARCC item is checked
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "NII T"
    And I fill in "Question" with "NII Question"
    And I check the box "Make this a PARCC item"
    And I press "Save"
    Then I should see the text "Yes" in the "NII T" row
    When I click "Duplicate"
    Then the "Title" field should contain "Clone of NII T"
    And the "Question" field should contain "NII Question"
    And the "Make this a PARCC item" checkbox should be checked
    And I press "Save"
    Then I should see the link " NII T"
    Then I should see the link "Clone of NII T"
    Then I should see the text "Yes" in the "Clone of NII T" row

  Scenario: User is a PARCC Item Author and Make this a PARCC item is unchecked
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "NII T"
    And I fill in "Question" with "NII Question"
    And I uncheck the box "Make this a PARCC item"
    And I press "Save"
    Then I should see the text "No" in the "NII T" row
    When I click "Duplicate"
    Then the "Title" field should contain "Clone of NII T"
    And the "Question" field should contain "NII Question"
    And the "Make this a PARCC item" checkbox should not be checked
    And I press "Save"
    Then I should see the link " NII T"
    Then I should see the link "Clone of NII T"
    Then I should see the text "No" in the "Clone of NII T" row
