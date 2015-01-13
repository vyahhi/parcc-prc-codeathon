@api @course
Feature: PRC-536 Admin: Select Module Content- Apostrophe in Module names do not show correctly

  Scenario: Edit settings doesn't encode module title
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Module" node with the title "PD Module PRC-350 AC5"
    And I am viewing my "PD Course" node with the title "PD Course PRC-350 AC4"
    And I follow "Course outline"
    And I select "Module" from "edit-more-object-type"
    And I press "Add object"
    Then I should see the text "Changes to this course have not yet been saved."
    # A link or button for Edit Settings (story PRC-361 and PRC-351)
    And I click "Edit Settings"
    And I select "PD Module PRC-350 AC5" from "Existing node"
    And I uncheck the box "Use existing content's title"
    And I fill in "Module Title" with "Something's wrong"
    And I press "Update"
    Then I click "Edit Settings"
    Then the "Use existing content's title" checkbox should not be checked
    And the "Module Title" field should contain "Something's wrong"