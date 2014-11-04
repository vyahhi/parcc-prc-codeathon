@api
Feature: Content Permissions
  As a Content Contributor,
  I want to define the content permissions,
  so that only the intended audience can access my content.

#  Acceptance Criteria
  Scenario:  In Add Content and Edit Content pages, a new section Permissions shall be added below the More Info (Content Properties) section.
    Given I am logged in as a user with the "Content Contributor" role
    And I am on "node/add/digital-library-content"
    Then I should see the text "Permissions"
    And I should see a "Public" field
    And I should see a "PARCC members ONLY" field

#  Scenario:  In Edit Content pages, a new section Permissions shall be added below the More Info (Content Properties) section.

#  A set of 2 radio buttons are available after a statement such as the following:
#  This content shall be available to:
#  Public
#  PARCC members ONLY
#  Permissions field is Required.
#  Only 1 option can be selected
#  None of the Permission options is selected by default
#  This feature is available to:
#  PRC Admin
#  Content Contributor
#  When the content is saved with the defined permission, it will be visible to the selected audience, as the following:
#  Public: No restrictions; any anonymous user or logged in user with any role, including Educator role shall see the content
#  PARCC members ONLY: PRC Admin, Content Contributor, PARCC-Member Educators shall see the content (not accessible to anonymous users or logged in users with Educator role).
#  When a public content gets switched to a PARCC members ONLY at Edit content, the system shall behave as Drupal default until future stories define the desired behavior On editing content and changing this Permissions value, the content will be added to or filtered from the content lists immediately, but the item will remain as it was permissioned in regards to search results until the scheduled cron job runs that re-indexes for searching.