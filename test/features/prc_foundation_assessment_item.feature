@styleguide @api @d7 @prc-1438 @prc-1439 @javascript @assessments
Feature: Assessment item theming stories.

  Scenario Outline: PRC-1438 Responsive Behavior.  All item types.
    Given I am logged in as a user with the "Educator" role
    And I visit "assessments/item-bank"
    When I click "<Item Type>"
    And I am browsing using a "phone"
    # The width of the main content area should be 100%
    Then  "form.node-form .form-item-title" should be "100%" of the width of ".region-content" within a margin of "0%"
    # The left margin of the main content area should align with the logo in the header.
    And "#content" should have a "padding-left" css value of "15px"
    # The right margin of the content area should line up with the Profile in the header.
    And "#content" should have a "padding-right" css value of "15px"
    When I am browsing using a "desktop"
    # The maximum width for the main content area should be 1400 px.
    Then "form.node-form .form-item-title" should be "100%" of the width of ".region-content" within a margin of "0%"
    # The main content should be 100% (a single column as wide as its container).
    # The left margin of the main content area should align with the logo in the header.
    And "#content" should have a "padding-left" css value of "30px"
    # The right margin of the content area should line up with the Profile in the header.
    And "#content" should have a "padding-right" css value of "30px"
    And the edge of "a#logo" should line up with "#content"
    # Title Text fields should be 50% of the width of the main content area.
    And "input#edit-title" should be "50%" of the width of ".region-content" within a margin of "5%"
    # Question field should be treated as body text and should be 100% of the width of the main content area.
    And ".form-item-body-und-0-value" should be "100%" of the width of ".region-content" within a margin of "5%"
    # Comment on 1588, textfield should be 50% width on tablet
    And I am browsing using a "tablet"
    And "#edit-title" should be "100%" of the width of "form.node-form" within a margin of "5%"
    Examples:
      | Item Type                   |
      | Interactive choice          |
      | Non-interactive (text only) |
      | Short answer                |

    Scenario: PRC-1438 responsive behavior.  Interactive choice.
      Given I am logged in as a user with the "Educator" role
      And I visit "assessments/item-bank"
      When I click "Interactive choice"
      And I am browsing using a "desktop"
      # For Standard Dropdown:
      # Maximum # of dropdown columns in a row is 4
      Then ".form-item-field-standard-und-0-tid > select" should be "25%" of the width of ".form-item-field-standard-und-0-tid" within a margin of "5%"
      # Maximum # of total dropdowns is 7
      # - Not relevant, this is associated with the taxonomy structure, not theming related
      # Dropdowns should use foundation's 'medium' select list width.
      And "#edit-field-standard-und-0-tid-select-1" should have a "height" css value of "38px"


    Scenario: PRC-1438 responsive behavior.  Interactive choice.
      Given I am logged in as a user with the "Educator" role
      And I visit "assessments/item-bank"
      When I click "Short answer"
      And I am browsing using a "phone"
      # Maximum # of total dropdowns is 7
      # - Not relevant, this is associated with the taxonomy structure, not theming related
      # Dropdowns should use foundation's 'medium' select list width.
      And "#edit-field-standard-und-0-tid-select-1" should have a "height" css value of "38px"
      # For "Grade" check boxes:
      # Maximum # of check boxes in a row is 7
      # Then the items within "" should have a width between "12%" and "17%" of their parent
      # Maximum number of grades is 14
      # And "select#edit-field-grade-level-und" should contain no more than "14" elements
      # Check boxes should stack from right to left
      # @todo: not currently checkboxes, is there a ticket?

    Scenario: PRC-1439.  Assessment item form styling.
      Given I am logged in as a user with the "Educator" role
      And I visit "assessments/item-bank"
      When I click "Short answer"
      #background of the question area is grey
      Then "#edit-answer" should have a "background-color" css value of "rgb(238, 238, 238)"
      And I visit "assessments/item-bank"
      When I click "Interactive choice"
      #background of the question area is grey
      Then "#edit-alternatives" should have a "background-color" css value of "rgb(238, 238, 238)"

