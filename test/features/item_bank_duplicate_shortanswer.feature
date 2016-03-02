@api @itembank @shortanswer @prc-1036 @prc-1038 @prc-1412
Feature: PRC-1036 Item Bank - Duplicate Short Answer Item - Form
  As a logged in user,
  I want to be able to duplicate a non-PARCC short answer item from the Item Bank
  so that I can make the changes I want to make.

  Scenario: User is not a PARCC Item Author
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    And I click "Short answer"
    And I fill in "Title" with "SA 1"
    And I fill in "Question" with "Stem 1"
    And I fill in "Correct answer" with "Correct"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I check the box "Pre-K"
    And I check the box "1st Grade"
    And I check the box "2nd Grade"
    And I check the box "3rd Grade"
    And I check the box "4th Grade"
    And I check the box "5th Grade"
    And I check the box "6th Grade"
    And I check the box "7th Grade"
    And I check the box "8th Grade"
    And I check the box "9th Grade"
    And I check the box "10th Grade"
    And I check the box "11th Grade"
    And I check the box "12th Grade"
    Then I press "Save"
    Then I should see the text "No" in the "SA 1" row
    When I click "Duplicate"
    Then the "Title" field should contain "Clone of SA 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I press "Save"
    Then I should see the link "SA 1"
    And I should see the link "Clone of SA 1"
    Then I should see the text "No" in the "Clone of SA 1" row

  Scenario: User is a PARCC Item Author and the Make this a PARCC Item box is checked
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    And I click "Short answer"
    And I fill in "Title" with "SA 1"
    And I fill in "Question" with "Stem 1"
    And I fill in "Correct answer" with "Correct"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I check the box "Pre-K"
    And I check the box "1st Grade"
    And I check the box "2nd Grade"
    And I check the box "3rd Grade"
    And I check the box "4th Grade"
    And I check the box "5th Grade"
    And I check the box "6th Grade"
    And I check the box "7th Grade"
    And I check the box "8th Grade"
    And I check the box "9th Grade"
    And I check the box "10th Grade"
    And I check the box "11th Grade"
    And I check the box "12th Grade"
    And I check the box "Make this a PARCC item"
    Then I press "Save"
    Then I should see the text "Yes" in the "SA 1" row
    When I click "Duplicate"
    Then the "Title" field should contain "Clone of SA 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And the "Make this a PARCC item" checkbox should be checked
    And I press "Save"
    Then I should see the link "SA 1"
    And I should see the link "Clone of SA 1"
    Then I should see the text "Yes" in the "Clone of SA 1" row

  Scenario: User is a PARCC Item Author and the Make this a PARCC Item box is not checked
    Given I am logged in as a user with the "PARCC Item Author" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    And I click "Short answer"
    And I fill in "Title" with "SA 1"
    And I fill in "Question" with "Stem 1"
    And I fill in "Correct answer" with "Correct"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I check the box "Pre-K"
    And I check the box "1st Grade"
    And I check the box "2nd Grade"
    And I check the box "3rd Grade"
    And I check the box "4th Grade"
    And I check the box "5th Grade"
    And I check the box "6th Grade"
    And I check the box "7th Grade"
    And I check the box "8th Grade"
    And I check the box "9th Grade"
    And I check the box "10th Grade"
    And I check the box "11th Grade"
    And I check the box "12th Grade"
    And I uncheck the box "Make this a PARCC item"
    Then I press "Save"
    Then I should see the text "No" in the "SA 1" row
    When I click "Duplicate"
    Then the "Title" field should contain "Clone of SA 1"
    And I fill in the hidden field "faux_standard" with "Standard"
    And the "Make this a PARCC item" checkbox should not be checked
    And I press "Save"
    Then I should see the link "SA 1"
    And I should see the link "Clone of SA 1"
    Then I should see the text "No" in the "Clone of SA 1" row

#  Scenario 2: User is a PARCC Item Author
#    Given I am logged in as a PARCC Item Author
#    And I am on the Item Bank page
#    When I click Edit link / button associated with the short answer item (either PARCC or non-PARCC)
#    Then I see the Edit Short Answer Item page:
#  Differences from Item Bank - Create PARCC Short Answer Item - Form (PRC-1275)
#  Fields are populated with previously submitted changes