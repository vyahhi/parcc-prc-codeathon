@api @d7
Feature: PRC-347 Top Nav Bar for Anonymous Users
  As an anonymous user,
  I want to navigate within various PRC content using the top navigation bar,
  so that I can explore before creating a user account with PRC system.

  Scenario: Anonymous links
    Given I am an anonymous user
    And I am on the homepage
    Then I should see the link "Home"
    And I should see the link "Digital Library"
    And I should see the link "Assessments"
    And I should see the link "Professional Development"
    And I should not see the link "Content"
    And I should not see the link "Users"

  Scenario: PRC-435 Anon should see DL content
    Given "Digital Library Content" nodes:
      | title          | body           | field_permissions | uid |
      | Public PRC-435 | This is public | public            | 1   |
    And I am an anonymous user
    And I am on "digital-library"
    Then I should see the link "Public PRC-435"