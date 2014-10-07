@api @d7
Feature: Admin UI: Post Content (PRC-28)
  As a Content Author,
  I want to post a new content to PRC Website,
  so that the educators can access and view them.

  Scenario: Content Author permission
    Given I am logged in as a user with the "Content Author" role
    Then I should be able to edit a "Document" node

  Scenario: Adding content - Form fields
    Given I am logged in as a user with the "Content Author" role
    And I am on the homepage
    Then I follow "Content"
    Then I should see "Create Document"
    Then I should see a "Title" field
    And I should see a "Body" field
    And I should see a "Tags" field