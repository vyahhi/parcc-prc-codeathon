@api @workflow @diglib
Feature: As a Content Contributor, I want the system to keep track of the previous versions when a new version of
  Digital Library content is published (PRC-45).

  Background:
    Given users:
      | name            | mail                      | pass   | field_first_name | field_last_name | status | roles                           |
      | Joe Contributor | joe_1prc_58cc@example.com | xyz123 | Joe              | Contributor     | 1      | Content Contributor             |
      | Joe Curator     | joe_1prc_58ca@example.com | xyz123 | Joe              | Curator         | 1      | Content Administrator (Curator) |
    And the test email system is enabled

  Scenario: Tab should only show up when there is a new revision
    # create content
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My Draft @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press "Save"
    # navigate to the content
    And I visit "prc/admin/admin-content"
    And I click "My Draft @timestamp"
    # make sure the tab doesn't show
    And I should not see the link "Revisions"
    # edit the content and save a new draft
    And I click "Edit"
    And I fill in "Body" with "Making a new draft"
    And I press "Save"
    # confirm that the revisions tab shows up
    And I visit "prc/admin/admin-content"
    And I click "My Draft @timestamp"
    And I click "Revisions"
    # check that we can access correct drafts by clicking on the links
    And I should not see the text "Access Denied"

    # Can see the diffed content
    # @todo:  A step definition for checking the diff?
    # Check that we can access the user profile pages that are linked to

  Scenario: Tab shows a diff between the drafts
    #create content
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My Draft @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press "Save"
    # navigate to the content
    When I visit "prc/admin/admin-content"
    And I click "My Draft @timestamp"
    # edit the content and save a new draft
    And I click "Edit"
    And I fill in "Body" with "Isn't this cool?"
    And I press "Save"
    # visit the revisions tab
    And I click "Revisions"
    And the "ins" element should contain "cool"
    And the "del" element should contain "swell"

  Scenario: Contributor's comments show on history table
    # create content and walk it through past request changes
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My Draft @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press "Save"
    And I visit "prc/admin/admin-content"
    And I click "My Draft @timestamp"
    And I click "Edit"
    And I fill in "Body" with "Making a new draft"
    And I press "Save"
    And I visit "prc/admin/admin-content"
    And I click "My Draft @timestamp"
    And I click "Edit"
    And I press "Request Approval"
    And I press "Update state"
    # make sure the comments from the contributor show up on the revisions tab
    When I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My Draft @timestamp"
    And I press the "Request Change" button
    And I fill in "Message *" with "Please elaborate on this and that."
    And I press the "Send Request" button
    Then I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "edit" in the "My Draft @timestamp" row
    And I click on the element with css selector ".breadcrumb a:nth-child(4)"
    And I click "Revisions"
    And I should see the text "Please elaborate on this and that."

  Scenario: The revisions page displays correctly
    # Walk content through to published to populate the table
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My first post @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    And I click "Edit"
    And I press the "Request Approval" button
    And press the "Update state" button
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I press the "Publish" button
    And I press the "Update state" button
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I fill in "Body" with "This is what I have to say."
    And I press "Publish"
    And I press the "Update state" button
    And I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I click "Edit"
    And I fill in "Body" with "Here is my clever addition."
    And I press the "Save" button
    And I press "Confirm"
    And I click "Edit Revision"
    And I press "Request Approval"
    And I press the "Update state" button
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I press the "Publish" button
    And I press the "Update state" button
    And I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I click "Edit"
    And I fill in "Body" with "Here is my really clever addition."
    And I press "Save"
    And I press "Confirm"
    And I click "Edit Revision"
    And I press the "Request Approval" button
    And I should not see an "textarea" element
    And I press the "Update state" button
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I press the "Request Change" button
    And I fill in "Message *" with "Do it again, not so clever."
    And I press the "Send Request" button
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    # click the breadcrumb to return to the node view
    And I click "My first post @timestamp"
    And I click "Edit"
    And I press the "Unpublish" button
    And I press the "Update state" button
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I should see the text "Revision State: Draft"
    And I click "Edit"
    And I press the "Request Approval" button
    And press the "Update state" button
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I click "Rescind Request"
    And I press the "Update state" button
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I press the "Publish" button
    And I press the "Update state" button
    And I visit "prc/admin/admin-content"
    # check that the current revision info is displayed correctly
    When I click "My first post @timestamp"
    And I click "Revisions"
    Then I should see the text "Current Revision"
    And I should see the text "History"
    # selected items to validate the diffs
    And at least one "ins" element should contain "really"
    And at least one "del" element should contain "swell?"
    And at least one "ins" element should contain "Here"
    And at least one "del" element should contain "have to say"
    And I click "Joe Curator"
    And I should not see "Access Denied"

  @prc-1795
  Scenario: prc-1795 only published content visible in diglib gallery
    # Walk content through to published to populate the table
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My first post @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    And I click "Edit"
    And I press the "Request Approval" button
    And press the "Update state" button
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I press the "Publish" button
    And I press the "Update state" button
    And I index search results
    When I visit "library"
    And I should see the link "My first post @timestamp"
    And I click "My first post @timestamp"
    # click the breadcrumb to return to the node view
    And I click "Edit"
    And I press the "Unpublish" button
    And I press the "Update state" button
    Then I visit "library"
    And I should not see the link "My first post @timestamp"
