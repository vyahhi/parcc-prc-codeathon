@api @d7
Feature: Role-Based Top Nav - PRC Admin (PRC-160)
  As a PRC Admin,
  I want to view content only associated with my role,
  so that I can complete all assigned tasks without viewing the content of other roles associated with the PRC website.

  Scenario: Educator sees links
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    Then I should see the link "Home"
    And I should see the link "Library"
    And I should see the link "Assessment"
    And I should see the link "Professional Learning"
    And I should see the link "Technology Readiness"
    And I should see the link "Admin"
    When I am on "prc/admin"
    Then I should see the link "Users"
    And I should see the link "Content"
    And I should see the link "Course Management"