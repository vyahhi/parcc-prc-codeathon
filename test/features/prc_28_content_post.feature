@api @d7
Feature: Admin UI: Post Content (PRC-28)
  As a Content Author,
  I want to post a new content to PRC Website,
  so that the educators can access and view them.

  Scenario: AC1 Content Author permission
    Given I am logged in as a user with the "Content Author" role
    Then I should be able to edit a "Digital Library Content" node

  Scenario Outline: AC2 and AC3 Content tab visibility for authorized users
    Given I am logged in as a user with the "<role>" role
    And I am on the homepage
    Then I should see the link "Content"

    Examples:
    | role            |
    |  Content Author |
    |  PRC Admin      |
    |  administrator  |

  Scenario: AC2 and AC3 Content tab invisibility for Educators
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    Then I should not see the link "Content"

  Scenario: AC2 and AC3 Content tab invisibility for anonymous
    Given I am an anonymous user
    And I am on the homepage
    Then I should not see the link "Content"

  Scenario: AC4-6 Content Authors click on Content tab link
    Given I am logged in as a user with the "Content Author" role
    And I am on the homepage
    When I follow "Content"
    Then the url should match "admin-content"
    Then I click "Add content"
    Then the url should match "node/add/digital-library-content"
    And I should see the heading "Create Digital Library Content" in the "content" region

