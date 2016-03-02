@assessment @api @prc-1427 @styleguide @javascript @prc-1424 @prc-1475
Feature: As a user I want my view of the Item Bank to be organized and easy to navigate, so that I can easily view
  the content consistently throughout the site.*

  Scenario: Confirm styling of the item bank
    Given I am logged in as a user with the "Educator" role
    When I visit "assessments/item-bank"
    # Breadcrumb and title should be in a section with a white background.
    Then I should see the heading "Item Bank" in the "sub_header" region

    # ToDo:PRC-1632: Add correct breadcrumbs
    #And I should see the link "PRC" in the "sub_header" region
    #And I should see the link "Assessment" in the "sub_header" region

    And "#sub-header" should have a "background-color" css value of "transparent"
    And "#page" should have a "background-color" css value of "rgb(255, 255, 255)"
    # Title (should match h1 from style guide) - covered elsewhere
    # Main content section should have a grey background
    And "main" should have a "background-color" css value of "rgb(238, 238, 238)"
    # Top of main content section has a 1px stroke of #dbdbdb
    And "main" should have a "border-top-width" css value of "1px"

  Scenario: Item bank responsive behavior
    Given I am logged in as a user with the "Educator" role
    When I visit "assessments/item-bank"
    When I am browsing using a "phone"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    And ".views-exposed-widget" should have a "display" css value of "block"
    And I am browsing using a "desktop"
    And ".main" should have a "padding-left" css value of "30px"
    And ".main" should have a "padding-right" css value of "30px"
    And ".views-exposed-widget" should have a "display" css value of "inline-block"

  Scenario: Item bank question preview
    Given I am logged in as a user with the "PRC Admin" role
    And "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Grade Level" terms:
      | name      |
      | Grade 527 |
    And "Assessment" nodes:
      | title        | field_subject | field_grade_level_unlimited | field_quiz_type                    | uid         |
      | PRC-527 View | subj1, subj2  | Grade 527                   | PARCC-Released Practice Assessment | @currentuid |
  # That standard already exists, and I hate it, but I am getting an error
  # creating a Standard term is giving me an error.
  # We're cheating and using one that exists already.
    And I visit the last node created
    And I press "Add Item"
    And I click "Non-interactive Item (text only)"
    And I fill in "edit-body-und-0-value" with "PRC-490 Directions 1 And these are the Body Body Directions Directions"
    And I fill in "Title" with "PRC Foundation Quiz #1"
    And I press "Save"
    And I press "Add Item"
    And I click "Interactive Choice"
    And I fill in "edit-body-und-0-value" with "PRC-527 Multi Multi Question Question<p>Paragraph</p>"
    And I fill in "Title" with "PRC Foundation Quiz #2"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "edit-alternatives-0-answer-value" with "Answer 1"
    And I fill in "edit-alternatives-1-answer-value" with "Answer 2"
    And I check the box "edit-alternatives-1-correct"
    And I check the box "1st Grade"
    And I press "Save"
    When I visit "assessments/item-bank"
    And I click "PRC Foundation Quiz #1"
    #title has a purple background-color
    Then ".item-preview-pane .question-title" should have a "background-color" css value of "rgb(112, 84, 125)"
    #Height of the title div is around 40px
    And ".item-preview-pane .question-title" should have a "padding-top" css value of "12px"
    And ".item-preview-pane .question-title" should have a "padding-bottom" css value of "12px"
    And ".item-preview-pane .question-title" should have a "font-size" css value of "16px"
    #title is white and bold
    And ".item-preview-pane .question-title" should have a "color" css value of "rgb(255, 255, 255)"
    And ".item-preview-pane .question-title" should have a "font-weight" css value of "700"
    # Check left padding on the fields
    And ".item-preview-pane .question-title" should have a "padding-left" css value of "16px"
    # white background
    And ".item-preview-pane .answering-form" should have a "background-color" css value of "rgb(255, 255, 255)"
    # Question is bold
    And ".item-preview-pane .field-name-body p" should have a "font-weight" css value of "700"
        # Table Style
    # Header
    # Table Background color: icon grey
    And "table.views-table thead tr" should have a "background-color" css value of "rgb(111, 126, 149)"
    # Column headers: bold weight
    And "th" should have a "font-weight" css value of "700"
    # Rows
    # background color alternates between background-gray and white.
    # height of row is 40px
    And "td" should have a "padding-top" css value of "13px"
    And "td" should have a "padding-bottom" css value of "13px"
    # Edit and duplicate icons have inactive and hover states
    # @todo: Need to get sprite sheet set-up
    # Cells
    # 20px left and right padding
    # Links
    # Use link styles in style guide
    # Selected Row
    # Background color parcc purple (this should also extend into the selected sort column) (Not applicable on item-bank)
    # Font color: white
    # Selected Sort Column
    # background color #ddd
    And I click "Title"
    And "tr.odd.views-row-first td.views-field.views-field-title.active" should have a "background-color" css value of "rgb(221, 221, 221)"