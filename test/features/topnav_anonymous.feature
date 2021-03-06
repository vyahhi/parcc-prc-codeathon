@api @d7 @anonymous
Feature: PRC-347 Top Nav Bar for Anonymous Users
  As an anonymous user,
  I want to navigate within various PRC content using the top navigation bar,
  so that I can explore before creating a user account with PRC system.

  Scenario: Anonymous links
    Given I am an anonymous user
    And I am on the homepage
    Then I should see the link "Home"
    And I should see the link "Library"
    And I should see the link "Assessment"
    And I should see the link "Professional Learning"
    And I should not see the link "Content" in the "main_menu" region
    And I should not see the link "Users"

  Scenario: PRC-435 Anon should see DL content
    Given "Digital Library Content" nodes:
      | title          | body           | field_permissions | uid | status |
      | Public PRC-435 | This is public | public            | 1   | 1      |
    And I am an anonymous user
    And I index search results
    And I am on "library"
    Then I should see the link "Public PRC-435"