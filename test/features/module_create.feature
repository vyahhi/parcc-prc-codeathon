@api
Feature: PRC-107 Admin - Add PD Module (Backend)
  As an Admin,
  I want to add Professional Development (PD) modules to the PRC website using backend functionality,
  so that users can access all available PD modules as needed.

  Scenario: AC1. Fields on PD Modules
    Given I am logged in as a user with the "administrator" role
    And I am viewing my "PD Module" node with the title "PRC-107 Edit"
    When I click "Edit"
    Then I should see "Module Title *"
    And I should see "Module Objectives *"
    And I should see "Module Length *"
    And I should see "Module Type"
    And I should not see "Module Type *"
    And I should see "Tags"
    And I should not see "Tags *"
