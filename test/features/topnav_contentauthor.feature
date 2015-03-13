@api @d7
Feature: Role-Based Top Nav - Content Contributor (PRC-159)
  As a PRC Content Contributor,
  I want to view content only associated with my role,
  so that I can complete all assigned tasks without viewing the content of other roles associated with the PRC website.

  Scenario: Content Contributor sees links
    Given I am logged in as a user with the "Content Contributor" role
    And I am on the homepage
    Then I should see the link "Home"
    And I should see the link "Digital Library"
    And I should see the link "Assessments"
    And I should see the link "Professional Development"
    And I should see the link "Technology Readiness"
    When I am on "prc/admin"
    Then I should see the link "Content"
    And I should not see the link "Users"
    And I should not see the link "Course Management"