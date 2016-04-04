@api @drupal7 @parcc-released-item @practice-test @javascript
Feature: Practice Tests

  # Background:
    # Given I have no entities of type "practice_test" and bundle "practice_test"
    # Given I have a practice test entity called "Practice Test @timestamp"

  Scenario Outline: Both PRC Admin and Item Author can create a PARCC Released Item that links to a practice test
    Given I am logged in as a user with the "<Role>" role
    And I am on "assessments/parcc-released-items"
    When I click "Add Resource"
    And I enter "My Resource @timestamp" for "Resource name *"
    And I select "Item Set" from "Resource Type"
    # And I select "Practice Test @timestamp" from "edit-field-practice-test-und"
    And I enter "PRACTZLDLP" for "Test Key"
    And I select the radio button "Public" with the id "edit-field-released-item-permissions-und-public"
    And I select "English Language Arts" from "edit-field-subject-und-0-tid-select-1"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I check the box "Pre-K"
    And I press "Save"
    And I am on "assessments/parcc-released-items"
    Then I should see the link "Computer-Based Item Set"
  Examples:
    | Role              |
    | PRC Admin         |
    | PARCC Item Author |

  Scenario: Anonymous users can access public tests
    Given I am logged in as a user with the "PRC Admin" role
    Given I have no "PARCC Released Item" nodes
    And I am on "assessments/parcc-released-items"
    When I click "Add Resource"
    And I enter "My Resource @timestamp" for "Resource name *"
    And I select "Item Set" from "Resource Type"
    # And I select "Practice Test @timestamp" from "edit-field-practice-test-und"
    And I enter "PRACTZLDLP" for "Test Key"
    And I select the radio button "Public" with the id "edit-field-released-item-permissions-und-public"
    And I select "English Language Arts" from "edit-field-subject-und-0-tid-select-1"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I check the box "Pre-K"
    And I press "Save"
    And I am an anonymous user
    And I visit "assessments/parcc-released-items"
    And I should see the link "Computer-Based Item Set"
    And I access the practice test link for "Practice Test @timestamp" directly

  Scenario: Anonymous users can't access tests with Permisions : "Registered"
    Given I am logged in as a user with the "PRC Admin" role
    Given I have no "PARCC Released Item" nodes
    And I am on "assessments/parcc-released-items"
    When I click "Add Resource"
    And I enter "My Resource @timestamp" for "Resource name *"
    And I select "Item Set" from "Resource Type"
    # And I select "Practice Test @timestamp" from "edit-field-practice-test-und"
    And I enter "PRACTZLDLP" for "Test Key"
    And I select the radio button "Registered" with the id "edit-field-released-item-permissions-und-registered"
    And I select "English Language Arts" from "edit-field-subject-und-0-tid-select-1"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I check the box "Pre-K"
    And I press "Save"
    And I am logged in as a user with the "Educator" role
    And I visit "assessments/parcc-released-items"
    And I should see the link "Computer-Based Item Set"
    And I access the practice test link for "Practice Test @timestamp" directly
    And I am an anonymous user
    And I visit "assessments/parcc-released-items"
    And I should not see the link "Computer-Based Item Set"
    And I access the practice test link for "Practice Test @timestamp" directly

  Scenario: Anonymous users can't access tests with Permisions : "PARCC members ONLY"
    Given I am logged in as a user with the "PRC Admin" role
    Given I have no "PARCC Released Item" nodes
    And I am on "assessments/parcc-released-items"
    When I click "Add Resource"
    And I enter "My Resource @timestamp" for "Resource name *"
    And I select "Item Set" from "Resource Type"
    # And I select "Practice Test @timestamp" from "edit-field-practice-test-und"
    And I enter "PRACTZLDLP" for "Test Key"
    And I select the radio button "PARCC members ONLY" with the id "edit-field-released-item-permissions-und-members"
    And I select "English Language Arts" from "edit-field-subject-und-0-tid-select-1"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I check the box "Pre-K"
    And I press "Save"
    And I am logged in as a user with the "PARCC-Member Educator" role
    And I visit "assessments/parcc-released-items"
    And I should see the link "Computer-Based Item Set"
    And I access the practice test link for "Practice Test @timestamp" directly
    And I am logged in as a user with the "Educator" role
    And I visit "assessments/parcc-released-items"
    And I should not see the link "Computer-Based Item Set"
    And I access the practice test link for "Practice Test @timestamp" directly

  Scenario: 2063 - Valid link with key takes us to the ADS system
    Given I am an anonymous user
    And I visit "practice-tests/key/PRACT12345"
    # As far as PRC knows this is a valid test key, send them on
    And I should see "Oops!"

  Scenario: 2063 - 404 not found for links
    And I visit "practic-tests/key/thisisnotavalidkey"
    # PRC doesn't recognize this as a key
    And I should see the text "could not be found."

