@api
Feature: PRC-835 Content Curation: Unpublish Content- Access Denied appended message not as specified

  Scenario: Anonymous user viewing unpublished content
    Given I am an anonymous user
    And "Digital Library Content" nodes:
      | title          | body           | field_permissions | uid | status |
      | PRC-58 Comment | This is public | public            | 1   | 0      |
    And I visit the last node created
    Then I should see the text "Access Denied"
    And I should see the text "If you have a site account, log in and try to access the page again."