@javascript
Feature: Verify that migration worked correctly and that the scorm content is accessible.

  Background:
    Given I run drush "mr PrcCsvPdCourseMigration"
    And I run drush "mi PrcCsvPdCourseMigration"

  Scenario: prc-776 LEO Learning course: Introduction to the K-2 Formative Tasks
    Given I am an anonymous user
    And I visit "professional-learning"
    When I click "Introduction to the K-2 Formative Tasks"
    And I follow "Take course"
    # @todo: the following steps aren't working since they open in a new tab/window
    # Then I should see the text "Module 2 - Introduction to the K-2 Formative Tasks."

  Scenario: prc-1175 LEO Learning course: Introduction to PARCC Diagnostic Assessment
    Given I am an anonymous user
    And I visit "professional-learning"
    When I click "Introduction to PARCC Diagnostic Assessment"
    When I click "Take course"
    # Then I should see the text "Module 3 - Introduction to PARCC Diagnostic Assessment."

  Scenario: prc-1176 LEO Learning course: Introduction to the PARCC Speaking and Listening Tools
    Given I am an anonymous user
    And I visit "professional-learning"
    When I click "Introduction to the PARCC Speaking and Listening Tools"
    When I click "Take course"
    # Then I should see the text "Module 4 - Introduction to the PARCC Speaking and Listening Tools."

  Scenario: prc-1171 LEO Learning course: PARCC--An Overview
    Given I am an anonymous user
    And I visit "professional-learning"
    When I click "PARCC – An Overview"
    Then I click "Take course"
    # And I should see the text "Module 1 - Overview."

  Scenario: prc-1762 LEO Learning course: The PARCC Accessibility System
    Given I am an anonymous user
    And I visit "professional-learning"
    When I click "The PARCC Accessibility System"
    Then I click "Take course"
    # And I should see the text "The Partnership for Assessment of Readiness for College and Careers"


