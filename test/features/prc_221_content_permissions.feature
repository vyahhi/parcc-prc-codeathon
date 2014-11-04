@api
Feature: Content Permissions
  As a Content Contributor,
  I want to define the content permissions,
  so that only the intended audience can access my content.

#  Acceptance Criteria
  Scenario:  In Add Content and Edit Content pages, a new section Permissions shall be added below the More Info (Content Properties) section.
    Given I am logged in as a user with the "Content Contributor" role
    And I am on "node/add/digital-library-content"
    Then I should see the text "Permissions *"
    And I should see a "Public" field
    And I should see a "PARCC members ONLY" field

  Scenario:  In Edit Content pages, a new section Permissions shall be added below the More Info (Content Properties) section.
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "DLC C"
    When I click "Edit"
    Then I should see the text "Permissions *"
    And I should see a "Public" field
    And I should see a "PARCC members ONLY" field

  Scenario:  None of the Permission options is selected by default
    Given I am logged in as a user with the "Content Contributor" role
    And I am on "node/add/digital-library-content"
    # Without selecting a Permissions value
    Then I press "Save"
    And I should see the error message containing "Permissions field is required."

  # Not testing this explicitly because only PRC Admin and Content Contributor can create/edit content
  #  This feature is available to:
  #  PRC Admin
  #  Content Contributor


#  When the content is saved with the defined permission, it will be visible to the selected audience, as the following:

  Scenario: Saving content as Public; accessible to anonymous
    Given "Digital Library Content" nodes:
      | title      | body           | field_permissions | uid |
      | Public     | This is public | public            | 1   |
    And I am an anonymous user
    And I visit the last node created
    Then I should see the text "This is public"

  Scenario: Saving content as Members Only; hidden from anonymous
    Given "Digital Library Content" nodes:
      | title        | body            | field_permissions  | uid |
      | Members Only | This is private | members            | 1   |
    And I am an anonymous user
    And I cannot visit the last node created

  Scenario Outline: Saving content as Public; accessible to roles
    Given "Digital Library Content" nodes:
      | title      | body           | field_permissions | uid |
      | Public     | This is public | public            | 1   |
    And I am logged in as a user with the "<role>" role
    And I visit the last node created
    Then I should see the text "This is public"
    Examples:
    | role                |
    | Educator            |
    | Content Contributor |
    | PRC Admin           |
    | administrator       |
    | authenticated user  |

  Scenario Outline: Saving content as Members Only; hidden from role
    Given "Digital Library Content" nodes:
      | title        | body            | field_permissions  | uid |
      | Members Only | This is private | members            | 1   |
    And I am logged in as a user with the "<role>" role
    And I cannot visit the last node created
  Examples:
    | role                |
    | Educator            |
    | authenticated user  |

  Scenario Outline: Saving content as Members Only; hidden from role
    Given "Digital Library Content" nodes:
      | title        | body            | field_permissions  | uid |
      | Members Only | This is private | members            | 1   |
    And I am logged in as a user with the "<role>" role
    And I visit the last node created
  Examples:
    | role                |
    | Content Contributor |
    | PRC Admin           |
    | administrator       |

#  Public: No restrictions; any anonymous user or logged in user with any role, including Educator role shall see the content
#  PARCC members ONLY: PRC Admin, Content Contributor, PARCC-Member Educators shall see the content (not accessible to anonymous users or logged in users with Educator role).
#  When a public content gets switched to a PARCC members ONLY at Edit content, the system shall behave as Drupal default until future stories define the desired behavior On editing content and changing this Permissions value, the content will be added to or filtered from the content lists immediately, but the item will remain as it was permissioned in regards to search results until the scheduled cron job runs that re-indexes for searching.