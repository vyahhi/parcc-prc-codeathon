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
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My Draft @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press "Save"
    # navigate to the content
    And I visit "admin-content"
    And I click "My Draft @timestamp"
    # make sure the tab doesn't show
    And I should not see the link "Revisions"
    # edit the content and save a new draft
    And I click "Edit"
    And I fill in "Body" with "Making a new draft"
    And I press "Save New Draft"
    # confirm that the revisions tab shows up
    And I visit "admin-content"
    And I click "My Draft @timestamp"
    And I click "Revisions"
    # check that we can access correct drafts by clicking on the links
    And I click on the revision id link in row number "2" of the table
    And I should not see the text "Access Denied"
    And I should see the text "Isn't this swell?"
    And I should not see the text "Making a new draft"
    # Check that we can access the user profile pages that are linked to
    And I click "Joe Curator"
    And I should not see "Access Denied"

  Scenario: Tab shows a diff between the drafts
    #create content
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My Draft @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press "Save"
    # navigate to the content
    When I visit "admin-content"
    And I click "My Draft @timestamp"
    # edit the content and save a new draft
    And I click "Edit"
    And I fill in "Body" with "Making a new draft"
    And I press "Save New Draft"
    # visit the revisions tab
    And I visit "admin-content"
    And I click "My Draft @timestamp"
    # @todo: confirm that the added text is displayed within an ins element
    # Create a new draft and delete text (if possible)
    # Confirm that the deleted text is within a del element

  Scenario: Contributor's comments show on history table
    # create content and walk it through past request changes
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My Draft @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press "Save"
    And I visit "admin-content"
    And I click "My Draft @timestamp"
    And I click "Edit"
    And I fill in "Body" with "Making a new draft"
    And I press "Save New Draft"
    And I visit "admin-content"
    And I click "My Draft @timestamp"
    And I click "Edit"
    And I press "Request Approval"
    And I press "Update state"
    # make sure the comments from the contributor show up on the revisions tab
    When I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "My Draft @timestamp"
    And I press the "Request Change" button
    And I fill in "Message *" with "Please elaborate on this and that."
    And I press the "Send Request" button
    Then I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "My Draft @timestamp"
    # click the title in the breadcrumb
    And I click "My Draft @timestamp"
    And I click "Revisions"
    And I should see the text "Please elaborate on this and that."

  Scenario: The revisions page displays correctly
    # Walk content through to published to populate the table
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My first post."
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    And I click "Edit"
    And I press the "Request Approval" button
    And press the "Update state" button
    And I visit "admin-content"
    And I click "My first post."
    And I should see the text "Approval Requested"
    And I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "edit"
    And I press the "Publish" button
    And I press the "Update state" button
    And I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "My first post."
    And I fill in "Body" with "This is what I have to say."
    And I press "Save and Publish"
    And I press the "Update state" button
    And I am logged in as "Joe Contributor"
    And I visit "content/my-first-post"
    And I click "Edit"
    And I fill in "Body" with "Here is my clever addition."
    And I press the "Save New Draft" button
    And I visit "content/my-first-post"
    And I click "Edit"
    And I click "Request Approval"
    And I press the "Update state" button
    And I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "edit"
    And I press the "Publish" button
    And I press the "Update state" button
    And I am logged in as "Joe Contributor"
    And I visit "content/my-first-post"
    And I should see the text "Revision State: Published"
    And I click "Edit"
    And I fill in "Body" with "Here is my really clever addition."
    And I press "Save New Draft"
    And I press "Confirm"
    And I click "Edit Revision"
    And I press the "Request Approval" button
    And I should not see an "textarea" element
    And I press the "Update state" button
    And I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "edit"
    And I press the "Request Change" button
    And I fill in "Message *" with "Do it again, not so clever."
    And I press the "Send Request" button
    And I visit "content/my-first-post"
    And I am logged in as "Joe Curator"
    And I visit "content/my-first-post"
    And I click "Edit"
    And I press the "Unpublish" button
    And I press the "Update state" button
    And I visit "admin-content"
    And I click "My first post"
    And I am logged in as "Joe Contributor"
    And I visit "content/my-first-post"
    And I should see the text "Revision State: Draft"
    And I click "Edit"
    And I press the "Request Approval" button
    And press the "Update state" button
    And I visit "content/my-first-post"
    And I click "Rescind Request"
    And I should not see an "textarea" element
    And I press the "Update state" button
    And I visit "content/my-first-post"
    And I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "My first post"
    And I click "Edit"
    And I press the "Publish" button
    And I press the "Update state" button
    And I visit "content/my-first-post"
    And I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My second post."
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    And I click "Edit"
    And I press the "Request Approval" button
    And press the "Update state" button
    And I visit "content/my-second-post"
    And I click "Rescind Request"
    And I press the "Update state" button
    And I visit "content/my-second-post"
    And I visit "admin-content"
    # check that the current revision info is displayed correctly
    When I click "My first post."
    And I click "Revisions"
    Then I should see the text "Current Revision"
    And I should see "Published" in the "<string>" element
    And I should see the link in the "[rid-element]"
    # Check that the table is displaying in reverse chrono order
    And the history table is displayed in reverse chronological order
    # @todo: check that the time displayed is the current users system time?
    # And the time listed in the first row is in the current users system time

# from the ticket
# A new tab, Revisions, shall be added for all PRC Digital Library content pages {color:green} where there have been revisions beyond the initial draft{color}, viewable for the originating Content Contributor and the Content Administrator (Curator).
# The Version History tab will be in the tab bar along with the existing View and Edit tabs.
# The Version History tab shall be comprised of two sections
#    ** The Current Revision section contains the following:
#    *** Current Editorial Status of the Content
#    *** Content Revision ID
#    ** The History section contains a two-column table that has a Date and Message columns
#    ** The History table entries will display changes to the Content in reverse chronological order
#    ** The Date of the Editorial Change will display the local date and time of the current user's system time.
#  {quote}
#  12/31/2016 - 13:30
#  {quote}
#    ** The Message will display the description of the Editorial Change
#  {quote}
#  [name of contributor/curator] transitioned revision [Revision ID] to [Editorial Status]
#  [comment - if available]
#  {quote}
#    ** For content changes, the History entry will be appended with a two-column section, displaying the previous and changed content in a side-by-side comparison.
#    *** Each content section that has changed is displayed.
#    *** {color:red} Dev to confirm {color} Differences in content is highlighted.
#    *** {color:red} Dev to confirm {color} Changes in {color:green}hierarchical menus Standards and Subject are display to lowest hierarchical level entry that has changed. {color}
#    *** {color:red} Dev to confirm {color} Displaying deletions.
#
#
## From Jack's BDD task
#  Create published DLC nodes
#  Create new revision.
#  Verify that original content is still present in Digital Library.
#
#  Create published DLC nodes
#  Create new revision.
#  Navigate to Revision History.
#  Edit new revision.
#  Walk new revision through the workflow.
#  Verify that new content is present in Digital Library.
#  Verify that original content is not present in Digital Library.
#
#  Create published DLC nodes
#  Create new revision.
#  Navigate to Content tab.
#  Verify that new revision is in the content tab.
#  Verify that original content is not in the content tab.
#
#  Create published DLC nodes
#  Create new revision.
#  Diff revisions and check output.
#
#    Given I am logged in as "Joe Contributor"
#    And I visit "admin-content"
#    And I click "Add content"
#    And I fill in "edit-title" with "My first post."
#    And I fill in "Body" with "Isn't this swell?"
#    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
#    And I press the "Save" button
#    When I click "Edit"
#    And I should see the text "Revision State: Draft"
#    And I press the "Request Approval" button
#    #PRC-873 : should not see text area for request approval
#    And I should not see an "textarea" element
#    Then press the "Update state" button
#    And I visit "admin-content"
#    And I click "My first post."
#    And I should see the text "Approval Requested"
#    And the email to "joe_1prc_58ca@example.com" should contain "The following content is awaiting approval"
#    And I click "Log out"
#    And I follow the link in the email
#    And I should see the text "Access Denied"
#    And I should see the text "If you have a site account, log in and try to access the page again."
#
#    # Curator approves review
#    Given I am logged in as "Joe Curator"
#    And I visit "admin-content"
#    And I click "edit"
#    # prc-826 : Publish button is not correct
#    And I press the "Publish" button
#    #PRC-873 : should not see text area for publish
#    And I should not see an "textarea" element
#    When I press the "Update state" button
#    And I click "Log out"
#    And I visit "content/my-first-post"
#    And I should see the text "My first post"
#    # prc-827 : Digital Library in email is not capitalized
#    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."
#    # prc-824
#    And the email should contain "Content Administrator: Joe Curator (joe_1prc_58ca@example.com)"
#
#    # Curator updates published content
#    Given I am logged in as "Joe Curator"
#    And I visit "content/my-first-post"
#    And I should see the text "Revision State: Published"
#    And I click "Edit"
#    And I fill in "Body" with "This is what I have to say."
#    When I press "Save and Publish"
#
#    #PRC-873 : should not see text area for save and publish
#    And I should not see an "textarea" element
#    And I press the "Update state" button
#    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."
#    And I click "Log out"
#    And I visit "content/my-first-post"
#    And I should see the text "This is what I have to say."
#
#    #Contributer requests a new draft be published
#    Given I am logged in as "Joe Contributor"
#    And I visit "content/my-first-post"
#    And I should see the text "Revision State: Published"
#    And I click "Edit"
#    And I fill in "Body" with "Here is my clever addition."
#    And I press the "Save New Draft" button
#    And I visit "content/my-first-post"
#    And I click "Workflow"
#    When I click "Request Approval"
#    #PRC-873 : should not see text area for request approval
#    And I should not see an "textarea" element
#    Then I press the "Update state" button
#
#    #Curator approves new draft
#    Given I am logged in as "Joe Curator"
#    And I visit "admin-content"
#    And I click "edit"
#    And I press the "Publish" button
#    #PRC-873 : should not see text area for request approval
#    And I should not see an "textarea" element
#    When I press the "Update state" button
#    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."
#    # PRC-824 Content Curation: Approving Content- Email content not correct
#    Then the email should contain "Content Administrator: Joe Curator (joe_1prc_58ca@example.com)"
#    And I follow the link in the email
#    And I should not see the text "Access Denied"
#    And the email should not contain "By:"
#
#    #contributer is denied
#    Given I am logged in as "Joe Contributor"
#    And I visit "content/my-first-post"
#    And I should see the text "Revision State: Published"
#    And I click "Edit"
#    And I fill in "Body" with "Here is my really clever addition."
#    And I press "Save New Draft"
#    #prc-847 : Add tabs for save and view on node revision page
#    And I press "Confirm"
#    And I click "Edit Revision"
#    When I press the "Request Approval" button
#    #PRC-873 : should not see text area for request approval
#    And I should not see an "textarea" element
#    Then I press the "Update state" button
#    And I am logged in as "Joe Curator"
#    And I visit "admin-content"
#    And I click "edit"
#    # Clear out old messages
#    And the test email system is enabled
#    And I press the "Request Change" button
#    #PRC-873 : should see a text area for deny
#    And I fill in "Message *" with "Do it again, not so clever."
#    When I press the "Send Request" button
#    And I visit "content/my-first-post"
#    And I should see the text "Revision State: Published"
#    Then the email to "joe_1prc_58cc@example.com" should contain "Do it again, not so clever."
#    # PRC-868 Content Curation: Not Approving Content- Email subject "Approval" not capitalized
#    And the email should contain "Changes before Approval for"
#    # prc-824 List curator info in email
#    Then the email should contain "Content Administrator: Joe Curator (joe_1prc_58ca@example.com)"
#    And the email should not contain "By:"
#    And I follow the link in the email
#    And I should not see the text "Access Denied"
#
#    #Unpublish
#    Given I am logged in as "Joe Curator"
#    And I visit "content/my-first-post"
#    And I click "Edit"
#    And I press the "Unpublish" button
#    And I press the "Update state" button
#    And I visit "admin-content"
#    And I click "My first post"
#    # prc-872 : Change "private draft" to just draft
#    And I should see the text "Revision State: Draft"
#    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been unpublished."
#    And I follow the link in the email
#    And I should not see the text "Access Denied"
#    And I click "Log out"
#    And I follow the link in the email
#    And I should not see the text "Isn't this swell"
#    And I should see the text "Access Denied"
#    And I should see the text "If you have a site account, log in and try to access the page again."
#
#    #Requesting review and cancelling after it has been published once
#    Given I am logged in as "Joe Contributor"
#    And I visit "content/my-first-post"
#    And I should see the text "Revision State: Draft"
#    And I click "Edit"
#    And I press the "Request Approval" button
#    When press the "Update state" button
#    And I visit "content/my-first-post"
#    And I should see the text "Approval Requested"
#    And I click "Rescind Request"
#    #PRC-873 : should not see text area for request approval
#    And I should not see an "textarea" element
#    Then I press the "Update state" button
#    And the email to "joe_1prc_58ca@example.com" should contain "The following content has been withdrawn from review."
#    And I visit "content/my-first-post"
#    And I should see the text "Revision State: Draft"
#
#    #Curator publishes without needing approval
#    Given I am logged in as "Joe Curator"
#    And I visit "admin-content"
#    And I click "My first post"
#    And I click "Edit"
#    And I press the "Publish" button
#    #PRC-873 : should not see text area for request approval
#    And I should not see an "textarea" element
#    And I press the "Update state" button
#    When I visit "content/my-first-post"
#    Then I should see the text "Revision State: Published"
#    And the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."
#    And I follow the link in the email
#    And I should not see the text "Access Denied"
#
#  # Cancelling a request before it was ever published
#    Given I am logged in as "Joe Contributor"
#    And I visit "admin-content"
#    And I click "Add content"
#    And I fill in "edit-title" with "My second post."
#    And I fill in "Body" with "Isn't this swell?"
#    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
#    And I press the "Save" button
#    When I click "Edit"
#    And I should see the text "Revision State: Draft"
#    And I press the "Request Approval" button
#    #PRC-873 : should not see text area for request approval
#    And I should not see an "textarea" element
#    And press the "Update state" button
#    And I visit "content/my-second-post"
#    And I should see the text "Approval Requested"
#    And the email to "joe_1prc_58ca@example.com" should contain "The following content is awaiting approval"
#    #PRC-873 : should not see text area for rescind request
#    And I click "Rescind Request"
#    And I should not see an "textarea" element
#    Then I press the "Update state" button
#    And I visit "content/my-second-post"
#    # PRC-813
#    And I should see the text "Revision State: Draft"
#    # PRC-853
#    And I visit "admin-content"
#    And I should see the text "Draft" in the "My second post." row