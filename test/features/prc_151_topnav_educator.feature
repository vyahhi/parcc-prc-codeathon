@api @d7
Feature: Role-Based Top Nav - Educator (PRC-151)
  As a PRC Educator,
  I want to view content only associated with my role,
  so that I can complete all assigned tasks without viewing the content of other roles associated with the PRC website.

  Scenario: Educator sees links
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    Then I should see the link "Home"
    And I should see the link "Digital Library"
    And I should see the link "Assessments"
    And I should see the link "Professional Development"
