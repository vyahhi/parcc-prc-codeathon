@api @prc-1991
Feature: PRC-835 Content Curation: Unpublish Content- Access Denied appended message not as specified

  Scenario: Anonymous user viewing unpublished content
    Given I am an anonymous user
    And "Digital Library Content" nodes:
      | title          | body           | field_permissions | uid | status |
      | PRC-58 Comment | This is public | public            | 1   | 0      |
    And I visit the last node created
    # PRC-1991 : Change access denied messages
    Then I should see the text "Access Denied - Please Log In"
    And I should see the text "Your session within PRC may have expired."
    And I should see the text "If you would like to login to PRC, please click here."
    And I follow "here"
    And I should see the text "Enter your e-mail address."

  Scenario: Authenticated user viewing content they don't have access to.
    Given I am logged in as a user with the "Educator" role
    And "Digital Library Content" nodes:
      | title          | body           | field_permissions | uid | status |
      | PRC-58 Comment | This is public | public            | 1   | 0      |
    And I visit the last node created
    # PRC-1991 : Change access denied messages
    Then I should see the text "Access Denied - Insufficient Permissions"
    And I should see the text "It appears that you have tried to access a resource that you do not have permission to view."
    And I should see the text "Click here to return to the homepage."
    And I follow "here"
    And I should see the text "Welcome to the Partnership Resource Center."