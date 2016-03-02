@api @parcc-released-item @prc-1740
Feature: PRC-1740 Assessment - PARCC Released Items Save Button

  Scenario: 1 - PRC Admin - Clicking the Save button on the Create Form
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/parcc-released-items"
    When I click "Add Resource"
    And I fill in "Resource name" with "Resource @timestamp"
    And I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-file-single-und-0-upload"
    And I select "Item Set" from "Resource Type"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I check the box "1st Grade"
    And I select the radio button "Public"
    And I press "Save"
    Then I should see the link "Resource @timestamp"
    And the url should match "assessments/parcc-released-items"
    And I should see the message containing "PARCC Released Item Resource @timestamp has been created."

  Scenario: 2 - PRC Admin - Clicking the Save button on the Edit Form
    Given parcc-released-item content:
      | resource name       | file                          | resource type | faux standard | faux subject | grade level | permissions  |
      | Test Resource | testfiles/GreatLakesWater.pdf | Item Set  | Standard One      | Subject One      | 1st Grade   | public     |
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/parcc-released-items"
    And I follow "edit"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I should not see the text "Preview"
    When I press "Save"
    Then I should see the link "Test Resource"
    And the url should match "assessments/parcc-released-items"
    And I should see the message containing "PARCC Released Item Test Resource has been updated."

  Scenario: 3 - PARCC Item Author - Clicking the Save button on the Create Form
    Given I am logged in as a user with the "PARCC Item Author" role
    And I am on "assessments/parcc-released-items"
    When I click "Add Resource"
    And I fill in "Resource name" with "Resource @timestamp"
    And I attach the file "testfiles/GreatLakesWater.pdf" to "edit-field-file-single-und-0-upload"
    And I select "Item Set" from "Resource Type"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I check the box "1st Grade"
    And I select the radio button "Public"
    And I press "Save"
    Then I should see the link "Resource @timestamp"
    And the url should match "assessments/parcc-released-items"
    And I should see the message containing "PARCC Released Item Resource @timestamp has been created."

  Scenario: 4 - PARCC Item Authoe - Clicking the Save button on the Edit Form
    Given parcc-released-item content:
      | resource name       | file                          | resource type | faux standard | faux subject | grade level | permissions  |
      | Test Resource | testfiles/GreatLakesWater.pdf | Item Set  | Standard One      | Subject One      | 1st Grade   | public     |
    Given I am logged in as a user with the "PARCC Item Author" role
    And I am on "assessments/parcc-released-items"
    And I follow "edit"
    And I fill in the hidden field "faux_standard" with "Standard"
    And I fill in the hidden field "faux_subject" with "Subject"
    And I should not see the text "Preview"
    When I press "Save"
    Then I should see the link "Test Resource"
    And the url should match "assessments/parcc-released-items"
    And I should see the message containing "PARCC Released Item Test Resource has been updated."