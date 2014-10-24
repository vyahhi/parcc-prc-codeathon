@api
Feature: Admin UI: Post Content (PRC-28)
  As a Content Author,
  I want to post a new content to PRC Website,
  so that the educators can access and view them.

  Scenario: Content Author permission - Edit Any
    Given I am logged in as a user with the "Content Author" role
    Then I should not be able to edit another user's "Digital Library Content" node

  Scenario: Content Author permission - Edit Own
    Given I am logged in as a user with the "Content Author" role
    Then I should be able to edit my own "Digital Library Content" node

  Scenario: AC1 Content author permission to create
    Given I am logged in as a user with the "Content Author" role
    And I am viewing my "Digital Library Content" node with the title "PRC-28 AC1 Title"

  Scenario: Adding content - Form fields
    Given I am logged in as a user with the "Content Author" role
    And I am on the homepage
    Then I follow "Content"
    Then I should see "Create Document"
    Then I should see a "Title" field
    And I should see a "Body" field
    And I should see a "Tags" field
