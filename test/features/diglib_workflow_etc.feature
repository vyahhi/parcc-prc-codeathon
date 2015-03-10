@api @diglib @workflow
Feature: Workflow is functional

  Background:
    Given users:
      | name            | mail                      | pass   | field_first_name | field_last_name | status | roles                           |
      | Joe Educator    | joe_1prc_58ed@example.com | xyz123 | Joe              | Educator        | 1      | Educator                        |
      | Joe Contributor | joe_1prc_58cc@example.com | xyz123 | Joe              | Contributor     | 1      | Content Contributor             |
      | Joe Curator     | joe_1prc_58ca@example.com | xyz123 | Joe              | Curator         | 1      | Content Administrator (Curator) |
    And the test email system is enabled

  Scenario: From draft to publish, editor makes changes and publishes, contributor publishes
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My first post."
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I click "Edit"
    And I should see the text "Revision State: Draft"
    And I press the "Request Approval" button
    #PRC-873 : should not see text area for request approval
    And I should not see an "textarea" element
    Then press the "Update state" button
    And I visit "admin-content"
    And I click "My first post."
    And I should see the text "Approval Requested"
    And the email to "joe_1prc_58ca@example.com" should contain "The following content is awaiting approval"
    And I click "Log out"
    And I follow the link in the email
    And I should see the text "Access Denied"
    And I should see the text "If you have a site account, log in and try to access the page again."

    # Curator approves review
    Given I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "edit"
    # prc-826 : Publish button is not correct
    And I press the "Publish" button
    #PRC-873 : should not see text area for publish
    And I should not see an "textarea" element
    When I press the "Update state" button
    And I click "Log out"
    And I visit "content/my-first-post"
    And I should see the text "My first post"
    # prc-827 : Digital Library in email is not capitalized
    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."
    # prc-824
    And the email should contain "Content Administrator: Joe Curator (joe_1prc_58ca@example.com)"

    # Curator updates published content
    Given I am logged in as "Joe Curator"
    And I visit "content/my-first-post"
    And I should see the text "Revision State: Published"
    And I click "Edit"
    And I fill in "Body" with "This is what I have to say."
    When I press "Save and Publish"
    
    #PRC-873 : should not see text area for save and publish
    And I should not see an "textarea" element
    And I press the "Update state" button
    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."
    And I click "Log out"
    And I visit "content/my-first-post"
    And I should see the text "This is what I have to say."

    #Contributer requests a new draft be published
    Given I am logged in as "Joe Contributor"
    And I visit "content/my-first-post"
    And I should see the text "Revision State: Published"
    And I click "Edit"
    And I fill in "Body" with "Here is my clever addition."
    And I press the "Save New Draft" button
    And I visit "content/my-first-post"
    And I click "Workflow"
    When I click "Request Approval"
    #PRC-873 : should not see text area for request approval
    And I should not see an "textarea" element
    Then I press the "Update state" button

    #Curator approves new draft
    Given I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "edit"
    And I press the "Publish" button
    #PRC-873 : should not see text area for request approval
    And I should not see an "textarea" element
    When I press the "Update state" button
    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."
    # PRC-824 Content Curation: Approving Content- Email content not correct
    Then the email should contain "Content Administrator: Joe Curator (joe_1prc_58ca@example.com)"
    And I follow the link in the email
    And I should not see the text "Access Denied"
    And the email should not contain "By:"

    #contributer is denied
    Given I am logged in as "Joe Contributor"
    And I visit "content/my-first-post"
    And I should see the text "Revision State: Published"
    And I click "Edit"
    And I fill in "Body" with "Here is my really clever addition."
    And I press "Save New Draft"
    #prc-847 : Add tabs for save and view on node revision page
    And I press "Confirm"
    And I click "Edit Revision"
    When I press the "Request Approval" button
    #PRC-873 : should not see text area for request approval
    And I should not see an "textarea" element
    Then I press the "Update state" button
    And I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "edit"
    # Clear out old messages
    And the test email system is enabled
    And I press the "Request Change" button
    #PRC-873 : should see a text area for deny
    And I fill in "Message *" with "Do it again, not so clever."
    When I press the "Send Request" button
    And I visit "content/my-first-post"
    And I should see the text "Revision State: Published"
    Then the email to "joe_1prc_58cc@example.com" should contain "Do it again, not so clever."
    # PRC-868 Content Curation: Not Approving Content- Email subject "Approval" not capitalized
    And the email should contain "Changes before Approval for"
    # prc-824 List curator info in email
    Then the email should contain "Content Administrator: Joe Curator (joe_1prc_58ca@example.com)"
    And the email should not contain "By:"
    And I follow the link in the email
    And I should not see the text "Access Denied"

    #Unpublish
    Given I am logged in as "Joe Curator"
    And I visit "content/my-first-post"
    And I click "Edit"
    And I press the "Unpublish" button
    And I press the "Update state" button
    And I visit "admin-content"
    And I click "My first post"
    # prc-872 : Change "private draft" to just draft
    And I should see the text "Revision State: Draft"
    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been unpublished."
    And I follow the link in the email
    And I should not see the text "Access Denied"
    And I click "Log out"
    And I follow the link in the email
    And I should not see the text "Isn't this swell"
    And I should see the text "Access Denied"
    And I should see the text "If you have a site account, log in and try to access the page again."

    #Requesting review and cancelling after it has been published once
    Given I am logged in as "Joe Contributor"
    And I visit "content/my-first-post"
    And I should see the text "Revision State: Draft"
    And I click "Edit"
    And I press the "Request Approval" button
    When press the "Update state" button
    And I visit "content/my-first-post"
    And I should see the text "Approval Requested"
    And I click "Rescind Request"
    #PRC-873 : should not see text area for request approval
    And I should not see an "textarea" element
    Then I press the "Update state" button
    And the email to "joe_1prc_58ca@example.com" should contain "The following content has been withdrawn from review."
    And I visit "content/my-first-post"
    And I should see the text "Revision State: Draft"

    #Curator publishes without needing approval
    Given I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "My first post"
    And I click "Edit"
    And I press the "Publish" button
    #PRC-873 : should not see text area for request approval
    And I should not see an "textarea" element
    And I press the "Update state" button
    When I visit "content/my-first-post"
    Then I should see the text "Revision State: Published"
    And the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."
    And I follow the link in the email
    And I should not see the text "Access Denied"

  # Cancelling a request before it was ever published
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My second post."
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I click "Edit"
    And I should see the text "Revision State: Draft"
    And I press the "Request Approval" button
    #PRC-873 : should not see text area for request approval
    And I should not see an "textarea" element
    And press the "Update state" button
    And I visit "content/my-second-post"
    And I should see the text "Approval Requested"
    And the email to "joe_1prc_58ca@example.com" should contain "The following content is awaiting approval"
    #PRC-873 : should not see text area for rescind request
    And I click "Rescind Request"
    And I should not see an "textarea" element
    Then I press the "Update state" button
    And I visit "content/my-second-post"
    # PRC-813
    And I should see the text "Revision State: Draft"
    # PRC-853
    And I visit "admin-content"
    And I should see the text "Draft" in the "My second post." row

  Scenario: Content is published, but changes don't show up until after it has been approved
    And the test email system is enabled
    And I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My first post."
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I click "Edit"
    And I should see the text "Revision State: Draft"
    And I press the "Request Approval" button
    #PRC-873 : should not see text area for request approval
    And I should not see an "textarea" element
    Then press the "Update state" button
    And I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "My first post."
    And I press the "Publish" button
    #PRC-873 : should not see text area for publish
    And I should not see an "textarea" element
    And I press "Update state"

    # Content is in published state the request approval button should not be visible
    Given I am logged in as "Joe Contributor"
    And I visit "content/my-first-post"
    And I click "Edit"
    And I fill in "Body" with "This is my unpublished addition"
    # prc-857 No delete and request buttons on published node
    And I should not see the button "Request Approval"
    #And I should not see the button "Delete"
    # prc-856
    And I press the "Save New Draft" button
    And I press the "Confirm" button
    And I visit "admin-content"
    # prc-844
    And I should see the text "Draft" in the "My first post." row
    #Go into workflow and find the new draft
    And I visit "content/my-first-post"
    And I click "Workflow"
    And I click "Request Approval"
    #PRC-873 : should not see text area for request approval
    And I should not see an "textarea" element
    When  I press "Update state"
    And I click "Log out"
    And I am an anonymous user
    Then I visit "digital-library"
    And I click "My first post."
    And I should see "Isn't this swell?"
    And I should not see "This is my unpublished addition"

    #Content is updated after approval
    Given I am logged in as "Joe Curator"
    And the test email system is enabled
    And I visit "admin-content"
    And I click "edit"
    And I press the "Publish" button
    # PRC-873 : should not see text area for publish
    And I should not see an "textarea" element
    And I press the "Update state" button
    Then I click "Log out"
    And I visit "content/my-first-post"
    And I should see the text "This is my unpublished addition"
    And the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."
    And I am logged in as "Joe Curator"
    And I follow the link in the email
    And I should not see the text "Access Denied"

  Scenario: PRC-786 Access Denied message when clicking on item in Content tab
    #  Content Curation: Curator permissions- Access Denied message when when clicking on item in Content tab
    #  Precondition:
    #  1. Have Content Contributor create content and then send for approval.
    #  2. Log in as PRC Admin or Content Administrator (Curator) role
    #  Steps:
    #  1. Click Content tab
    #  2. Click on title of content that is in state "Waiting for Review"
    #  Actual Results:
    #  2. Access Denied. You are not allowed to view this content.
    #  Expected Results:
    #  2. Should be able to view content that I am trying to approve.
    #  NOTE: When they click on "edit" link in Actions column, it works fine.
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My first post @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I follow "Edit"
    And I press "Request Approval"
    When I press the "Update state" button

    Given I am an anonymous user

    Then I am logged in as "Joe Curator"
    And I follow "Content"
    And I follow "My first post @timestamp"
    Then I should see the text "My first post @timestamp"
    And I should not see the text "Access denied"

  Scenario: PRC-829 Not Approving Content - Items are not in specified order
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My first post @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I follow "Edit"
    And I press "Request Approval"
    When I press the "Update state" button

    Given I am an anonymous user

    Then I am logged in as "Joe Curator"
    And I follow "Content"
    And I follow "My first post @timestamp"
    Then I press "Request Change"
    Then "Instructions: (to be added)" should precede "Message *" for the query "div"

  Scenario: PRC-830 Content Curation: Not Approving Content- Form Title not as specified in AC
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "PRC-592 @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I follow "Edit"
    And I press "Request Approval"
    When I press the "Update state" button

    Given I am an anonymous user

    Then I am logged in as "Joe Curator"
    And I follow "Content"
    And I follow "PRC-592 @timestamp"
    Then I press "Request Change"
    Then I should see the text "Changes before Approval for PRC-592"

  Scenario: PRC-832 Content Curation: Not Approving Content- Send Request button not as specified
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "PRC-592 @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I follow "Edit"
    And I press "Request Approval"
    When I press the "Update state" button

    Given I am an anonymous user

    Then I am logged in as "Joe Curator"
    And I follow "Content"
    And I follow "PRC-592 @timestamp"
    Then I press "Request Change"
    Then I press "Send Request"

  Scenario: PRC-833 Content Curation: Not Approving Content- Text Field Label is not correct
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "PRC-592 @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I follow "Edit"
    And I press "Request Approval"
    When I press the "Update state" button

    Given I am an anonymous user

    Then I am logged in as "Joe Curator"
    And I follow "Content"
    And I follow "PRC-592 @timestamp"
    Then I press "Request Change"
    Then I should see the text "Message"

  Scenario: PRC-831 node save button says "Save New Draft" instead of "Save Draft"
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "PRC-592 @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I follow "Edit"
    And I fill in "Body" with "This is swell"
    And I press the "Save New Draft" button
    And I should see the text "This is swell"

  Scenario: prc-871  access denied when clicking link in email
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "PRC-592 @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I follow "Edit"
    And I press the "Request Approval" button
    And I press the "Update state" button
    And I am logged in as "Joe Curator"
    And the email to "joe_1prc_58ca@example.com" should contain "The following content is awaiting approval"
    #prc-870 : email subject of request approval
    And the email should contain "PRC-592 @timestamp has an Approval Request"
    And I follow the link in the email
    Then I should not see the text "Access Denied"
    And I should see the text "PRC-592 @timestamp"
    And I should see an "Publish" button
    And I should see an "Request Change" button

    #setup for 845
    And I press "Publish"
    And I press "Update state"
    And I am logged in as "Joe Contributor"
    #prc-845 Confirmation prompt on save new draft
    Given I visit "admin-content"
    And I click "PRC-592 @timestamp"
    And I click "Edit"
    And I should see the text "Revision State: Published"
    And I fill in "Title *" with "My new draft"
    When I fill in "Body" with "testing confirmation stage cancel"
    And I press the "Save New Draft" button
    And I should see an "Confirm" button
    And I click "Cancel"
    # We should now be on the node view page
    And I click "Workflow"
    Then I should not see the link "My new draft"
    And I click "Edit"
    When I fill in "Body" with "testing confirm button"
    And I fill in "Title *" with "My new draft"
    And I press "Save New Draft"
    And I press "Confirm"
    # We should now be on teh revision page
    And I should see the text "testing confirm button"
