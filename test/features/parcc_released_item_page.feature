@api @parcc-released-item @prc-1734 @prc-1739 @prc-1750
Feature: PRC-1734 Assessment - PARCC Released Items View Page
  As a user
  I want a page where I can view, download, or print material from the PRC website
  so that I can assemble PARCC released items into an assessment.

  Background:
    Given I have no "PARCC Released Item" nodes
    And I am logged in as a user with the "PRC Admin" role
    And parcc-released-item content:
      | resource name       | file                          | resource type | faux standard | faux subject | grade level | permissions  |
      | Test Resource | testfiles/GreatLakesWater.pdf | Item Set  | Standard One      | Subject One      | 1st Grade   | public     |
    # Todo - Populate valid subjects for testing
    # Todo - Allow release dates other than default

  @javascript
  Scenario: 1 - Default PARCC Released Items view
    Given I am an anonymous user
    And I am on "assessments/parcc-released-items"
    Then I should see the heading "PARCC Released Items"
    And I should not see the link "Add Resource"
    And I should see the text "The states that make up the PARCC consortium are taking the exceptional step"
    And I should see the text "Resource Name"
    And I should see the text "Subject"
    And I should see the text "Grade Level"
    And I should see the text "Release Year"
    And I should see the text "Resource Type"
    And I should not see the text "Actions"
    And I should see the text "Item Set"
    When I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/parcc-released-items"
    Then I should see the heading "PARCC Released Items"
    And I should see the link "Add Resource"
    And ".page-assessments-parcc-released-items .pane-menu-menu-parcc-released-items-menu ul.menu a" should have a "border-top-left-radius" css value of about "24.75px" with a margin of "1px"

    #And "<string>" should have a "<string>" css value of about "<string>" with a margin of "<string>"
    #And ".page-assessments-parcc-released-items .pane-menu-menu-parcc-released-items-menu ul.menu a" should have a "border-top-left-radius" css value of "24.75px"
    And I should see the text "Resource Name"
    And I should see the text "Subject"
    And I should see the text "Grade Level"
    And I should see the text "Release Year"
    And I should see the text "Resource Type"
    And I should see the text "Actions"
    And I should see the text "Item Set"
    When I am logged in as a user with the "PARCC Item Author" role
    And I am on "assessments/parcc-released-items"
    Then I should see the heading "PARCC Released Items"
    And I should see the link "Add Resource"
    And ".page-assessments-parcc-released-items .pane-menu-menu-parcc-released-items-menu ul.menu a" should have a "border-top-left-radius" css value of about "24.75px" with a margin of "1px"
    #And ".page-assessments-parcc-released-items .pane-menu-menu-parcc-released-items-menu ul.menu a" should have a "border-top-left-radius" css value of "24.75px"
    And I should see the text "Resource Name"
    And I should see the text "Subject"
    And I should see the text "Grade Level"
    And I should see the text "Release Year"
    And I should see the text "Resource Type"
    And I should see the text "Actions"
    And I should see the text "Item Set"

  Scenario: 2 - Add Resource button visibility
    # I think the scenario above should be 'edit button visibility'...
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/parcc-released-items"
    When I follow "edit"
    Then I should see the heading "Test Resource"

  Scenario: 3 - Clicking on the Add Resource button
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/parcc-released-items"
    When I follow "Add Resource"
    Then I should see the heading "Create PARCC Released Item"

  Scenario: 4 Clicking on a <Resource Name>
    Given I am an anonymous user
    And I am on "assessments/parcc-released-items"
    When I follow "Test Resource"
    Then the response Content-Type should be "application/pdf"

  Scenario: PRC-1739 - 1+2 - Edit icon and delete button visibility - PRC Admin
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/parcc-released-items"
    Then I should see the text "Actions"
    When I follow "edit"
    Then I should see the heading "Test Resource"
    And I should see a "Delete" button

  Scenario: PRC-1739 - 3+4 - Edit icon and delete button visibility - PRC Admin
    Given I am logged in as a user with the "PARCC Item Author" role
    And I am on "assessments/parcc-released-items"
    Then I should see the text "Actions"
    When I follow "edit"
    Then I should see the heading "Test Resource"
    And I should see a "Delete" button

  Scenario: PRC-1750 - 2+3 - Click on column header and sort
    Given parcc-released-item content:
      | resource name       | file                          | resource type | faux standard | faux subject | grade level | permissions  |
      | Test Resource | testfiles/GreatLakesWater.pdf | Item  | Standard One      | Subject One      | 1st Grade   | public     |
    And I am an anonymous user
    And I am on "assessments/parcc-released-items"
    When I click "Resource Type"
    Then "Item Set" should precede "Item" for the query ".views-field-field-released-item-type"
    When I click "Resource Type"
    Then "Item" should precede "Item Set" for the query ".views-field-field-released-item-type"

  @prc-1863
  Scenario: Pager displays at 25 results
    Given I have no "PARCC Released Item" nodes
    And I run drush "genc 20 --types=parcc_released_item"
    And I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/parcc-released-items"
    Then I should not see the link "next ›"
    And I run drush "genc 10 --types=parcc_released_item"
    And I am on "assessments/parcc-released-items"
    Then I should see the link "next ›"
