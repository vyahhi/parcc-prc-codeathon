@api @d7
Feature: PRC-357 Invite User with Additional Role Selection- Need some definition around the "PRC-Member Educator" role
  As a PARCC-Member Educator,
  I want to view content only associated with my role,
  so that I can complete all assigned tasks without viewing the content of other roles associated with the PRC website.

  Scenario: PARCC-Member Educator sees links
    Given I am logged in as a user with the "PARCC-Member Educator" role
    And I am on the homepage
    Then I should see the link "Home"
    And I should see the link "Digital Library"
    And I should see the link "Assessments"
    And I should see the link "Professional Development"
    And I should not see the link "Content" in the "main_menu" region
    And I should not see the link "Users"
