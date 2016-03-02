@api @assessment @itembank @prc-1346 @prc-1347 @prc-1348 @prc-1349
Feature: PRC-1346 Assessment - Add Existing Item link/button
  As a logged in user, I want to add an existing item to an assessment so I don't have to re-create the item just for that assessment because that takes time and I have other things to do.
#  Acceptance Criteria
#  Given that I am logged in
#  And I am viewing an assessment
#  When I click the Add Existing Item link/button
#  Then I see the Item Bank page:
#  Differences from Item Bank (PRC-1001)
#  I see Operations box above scoring note (which is above Item table)with:
  "Add Items to Assessment" button
#  "Cancel" button
#  On click cancel button returns user to assessment with no changes

  Background: Clear items
    Given I am logged in as a user with the "Educator" role
    And I have no "Multiple choice question" nodes
    And I have no "Short answer question" nodes
    And I have no "Assessment directions" nodes
    And I am on "assessments/item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "NII T"
    And I fill in "Question" with "NII Question"
    And I press "Save"

  Scenario: Add existing item
    Given I am logged in as a user with the "Educator" role
    And I am on "assessments/practice-assessments"
    Then I follow "Create New Assessment"
    Then I should see the heading "Create Assessment" in the "sub_header" region
    And I fill in "Title" with "my Title"
    And I fill in "Objectives" with "my Objectives"
    And I check the box "1st Grade"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I press "Save"
    Then I should see the heading "my Title"
    Then I should see the text "There are currently no questions in this Assessment."
    When I click "Add Existing Item"
    Then I should see the text "Scoring note: All interactive choice and short answer questions are machine scored."
    # PRC-1347 Select items
    And I check the box "edit-views-bulk-operations-0"
    And I press "Add questions to Assessment"
    And I follow meta refresh
    Then I should see the message containing "Performed Add questions to Assessment on 1 item."
    When I click "Back to Assessment"
    Then I should see the heading "my Title"
    # PRC-1349 Items added to assessment
    And I should see the link "NII T"

  Scenario: PRC-1348 - Form validation
    Given I am logged in as a user with the "Educator" role
    And I am on "assessments/practice-assessments"
    Then I follow "Create New Assessment"
    Then I should see the heading "Create Assessment" in the "sub_header" region
    And I fill in "Title" with "my Title"
    And I fill in "Objectives" with "my Objectives"
    And I check the box "1st Grade"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I press "Save"
    When I click "Add Existing Item"
    And I press "Add questions to Assessment"
    Then I should see the error message containing "Please select at least one item."

  Scenario: prc-1868 Views caching interferes with adding items to assessment more than once
    Given I am logged in as a user with the "Educator" role

    And I am on "assessments/item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "Question 2"
    And I fill in "Question" with "q2"
    And I press "Save"

    And I am on "assessments/item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "Question 3"
    And I fill in "Question" with "q3"
    And I press "Save"

    And I am on "assessments/item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "Question 3"
    And I fill in "Question" with "q3"
    And I press "Save"

    And I am on "assessments/item-bank"
    When I click "Non-interactive (text only)"
    And I fill in "Title" with "Question 4"
    And I fill in "Question" with "q4"
    And I press "Save"

    And I am on "assessments/practice-assessments"
    Then I follow "Create New Assessment"
    Then I should see the heading "Create Assessment" in the "sub_header" region
    And I fill in "Title" with "my Title"
    And I fill in "Objectives" with "my Objectives"
    And I check the box "1st Grade"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I press "Save"
    Then I should see the heading "my Title"
    Then I should see the text "There are currently no questions in this Assessment."
    When I click "Add Existing Item"
    Then I should see the text "Scoring note: All interactive choice and short answer questions are machine scored."
    And I check the box "edit-views-bulk-operations-0"
    And I check the box "edit-views-bulk-operations-1"
    And I press "Add questions to Assessment"
    And I follow meta refresh
    Then I should see the message containing "Performed Add questions to Assessment on 2 items."
    When I click "Back to Assessment"
    When I click "Add Existing Item"
    Then I should see the text "Scoring note: All interactive choice and short answer questions are machine scored."
    And I check the box "edit-views-bulk-operations-2"
    And I check the box "edit-views-bulk-operations-3"
    And I press "Add questions to Assessment"
    And I follow meta refresh
    Then I should see the message containing "Performed Add questions to Assessment on 2 items."
