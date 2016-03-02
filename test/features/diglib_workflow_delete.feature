@api @diglib @workflow @prc-857 @prc-859
Feature: PRC-857 & PRC-859 - Tests concerning delete access for different user roles and different content states

  Background:
    Given users:
      | name            | mail                      | pass   | field_first_name | field_last_name | status | roles                           |
      | Joe Educator    | joe_1prc_58ed@example.com | xyz123 | Joe              | Educator        | 1      | Educator                        |
      | Joe Contributor | joe_1prc_58cc@example.com | xyz123 | Joe              | Contributor     | 1      | Content Contributor             |
      | Joe Curator     | joe_1prc_58ca@example.com | xyz123 | Joe              | Curator         | 1      | Content Administrator (Curator) |
    And I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "Delete Me @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button

   Scenario Outline: Delete should only be available on the content table for content that is solely in the draft state

     Given I am logged in as "<name>"
     And I visit "prc/admin/admin-content"
     And I click "delete" in the "Delete Me @timestamp" row
     And I press "Delete"
     And I visit "prc/admin/admin-content"
     And I should not see the text "Delete Me @timestamp"
   Examples:
     | name            |
     | Joe Contributor |
     | Joe Curator     |

  Scenario: Deleting as a contributor
    # Can't delete waiting for review
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I should see an "delete" link
    And I click "Delete Me @timestamp"
    And I click "Edit"
    When I press the "Request Approval" button
    And I press "Update state"
    And I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    Then I do not see a "delete" link in the "Delete Me @timestamp" row

    # Can't delete published
    Given I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "Delete Me @timestamp"
    And I should see the text "Revision State: Approval Requested"
    # And I click "Edit"
    And I should not see the button "Delete"
    When I press the "Publish" button
    And I press "Update state"
    And I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    Then I should not see the link "delete"
    And I click "edit"
    And I should not see the button "Delete"

    # Can't delete draft created after published
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Delete Me @timestamp"
    And I click "Edit"
    And I press "Save"
    When I press "Confirm"
    And I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    Then I should not see the link "delete"
    And I click "Delete Me @timestamp"
    And I should not see the button "Delete"

    # Can't delete waiting for review after published
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Delete Me @timestamp"
    And I click "Edit Revision"
    When I press "Request Approval"
    And I press "Update state"
    And I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    # @todo: fails if there is existing content
    # Then I should not see the link "delete"
    And I click "Delete Me @timestamp"
    And I should not see the button "Delete"

   # Can delete after unpublished
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Delete Me @timestamp"
    And I click "Rescind Request"
    And I press "Update state"
    Given I am logged in as "Joe Curator"
    And I index search results
    And I visit "library"
    And I click "Delete Me @timestamp"
    And I click "Edit"
    When I press "Unpublish"
    And I press "Update state"
    Then I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Delete Me @timestamp"
    And I click "Edit"
    And I press "Delete"
    And I press "Delete"
    And I visit "prc/admin/admin-content"
    And I should not see the text "Delete Me @timestamp"

  Scenario: Deleting as a curator
# Can't delete waiting for review
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I should see an "delete" link
    And I click "Delete Me @timestamp"
    And I click "Edit"
    When I press the "Request Approval" button
    And I press "Update state"
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    Then I do not see a "delete" link in the "Delete Me @timestamp" row

# Can't delete published
    Given I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "Delete Me @timestamp"
    And I should see the text "Revision State: Approval Requested"
# And I click "Edit"
    And I should not see the button "Delete"
    When I press the "Publish" button
    And I press "Update state"
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    Then I should not see the link "delete"
    And I click "edit"
    And I should not see the button "Delete"

# Can't delete draft created after published
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Delete Me @timestamp"
    And I click "Edit"
    And I press "Save"
    When I press "Confirm"
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    Then I should not see the link "delete"
    And I click "Delete Me @timestamp"
    And I should not see the button "Delete"

# Can't delete waiting for review after published
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Delete Me @timestamp"
    And I click "Edit Revision"
    When I press "Request Approval"
    And I press "Update state"
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
# Then I should not see the link "delete"
    And I click "Delete Me @timestamp"
    And I should not see the button "Delete"

# Can delete after unpublished
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Delete Me @timestamp"
    And I click "Rescind Request"
    And I press "Update state"
    Given I am logged in as "Joe Curator"
    And I index search results
    And I visit "library"
    And I click "Delete Me @timestamp"
    And I click "Edit"
    When I press "Unpublish"
    And I press "Update state"
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "Delete Me @timestamp"
    And I press "Delete"
    And I press "Delete"
    And I visit "prc/admin/admin-content"
    And I should not see the text "Delete Me @timestamp"
