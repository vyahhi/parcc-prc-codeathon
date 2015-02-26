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
    And I should see the text "Content State: Private Draft"
    And I press the "Request Approval" button
    And I fill in "Log message for this state change *" with "Please approve my first post."
    Then press the "Update state" button
    And I visit "content/my-first-post"
    And I should see the text "Approval Requested"
    And the email to "joe_1prc_58ca@example.com" should contain "The following content is awaiting approval"
    And I click "Log out"
    And I follow the link in the email
    And I should see the text "Access Denied"
    And I should see the text "If you have a site account, log in and try to access the page again."

    # Curator approves review
    Given I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "pending review"
    # prc-826 : Publish button is not correct
    And I press the "Publish" button
    And I fill in "Log message for this state change *" with "Looks good to me."
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
    And I should see the text "Content State: Published"
    And I click "Edit"
    And I fill in "Body" with "This is what I have to say."
    When I press "Save and Publish"
    And I fill in "Log message for this state change *" with "Need to get my word in."
    And I press the "Update state" button
    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."
    And I click "Log out"
    And I visit "content/my-first-post"
    And I should see the text "This is what I have to say."

    #Contributer requests a new draft be published
    Given I am logged in as "Joe Contributor"
    And I visit "content/my-first-post"
    And I should see the text "Content State: Published"
    And I click "Edit"
    And I fill in "Body" with "Here is my clever addition."
    And I press the "Save New Draft" button
    # @todo: change once we have an edit tab on the revision page
    And I visit "content/my-first-post"
    And I click "Workflow"
    When I click "Request Approval"
    And I fill in "Log message for this state change *" with "I'm so clever."
    Then I press the "Update state" button

    #Curator approves new draft
    Given I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "pending review"
    And I press the "Publish" button
    And I fill in "Log message for this state change *" with "Wow, you are so clever."
    When I press the "Update state" button
    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."

    #contributer is denied
    Given I am logged in as "Joe Contributor"
    And I visit "content/my-first-post"
    And I should see the text "Content State: Published"
    And I click "Edit"
    And I fill in "Body" with "Here is my really clever addition."
    And I press "Save New Draft"
    #@todo : change once we have an edit tab on revision pages
    And I visit "content/my-first-post"
    And I click "Workflow"
    When I click "Request Approval"
    And I fill in "Log message for this state change *" with "I'm so clever."
    Then I press the "Update state" button
    And I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "pending review"
    And I press the "Request Change" button
    And I fill in "Message *" with "Do it again, not so clever."
    When I press the "Send Request" button
    And I visit "content/my-first-post"
    And I should see the text "Content State: Published"
    Then the email to "joe_1prc_58cc@example.com" should contain "Do it again, not so clever."

    #Unpublish
    Given I am logged in as "Joe Curator"
    And I visit "content/my-first-post"
    And I click "Edit"
    And I press the "Unpublish" button
    And I fill in "Log message for this state change *" with "Let's take this down."
    And I press the "Update state" button
    And I visit "admin-content"
    And I click "My first post"
    And I should see the text "Content State: Private Draft"
    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been unpublished."
    And I click "Log out"
    And I follow the link in the email
    And I should not see the text "Isn't this swell"
    And I should see the text "Access Denied"
    And I should see the text "If you have a site account, log in and try to access the page again."

    #Requesting review and cancelling after it has been published once
    Given I am logged in as "Joe Contributor"
    And I visit "content/my-first-post"
    And I should see the text "Content State: Private Draft"
    And I click "Edit"
    And I press the "Request Approval" button
    And I fill in "Log message for this state change *" with "Please approve my first post."
    When press the "Update state" button
    And I visit "content/my-first-post"
    And I should see the text "Approval Requested"
    And I click "Rescind Request"
    And I fill in "Log message for this state change *" with "Please approve my first post."
    Then I press the "Update state" button
    And the email to "joe_1prc_58ca@example.com" should contain "The following content has been withdrawn from review."
    And I visit "content/my-first-post"
    And I should see the text "Content State: Private Draft"

    #Curator publishes without needing approval
    Given I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "My first post"
    And I press the "Publish" button
    And I fill in "Log message for this state change *" with "Let's put this back up."
    And I press the "Update state" button
    When I visit "content/my-first-post"
    Then I should see the text "Content State: Published"
    And the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."

  # Cancelling a request before it was ever published
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My second post."
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I click "Edit"
    And I should see the text "Content State: Private Draft"
    And I press the "Request Approval" button
    And I fill in "Log message for this state change *" with "Please approve my first post."
    And press the "Update state" button
    And I visit "content/my-second-post"
    And I should see the text "Approval Requested"
    And the email to "joe_1prc_58ca@example.com" should contain "The following content is awaiting approval"
    And I click "Rescind Request"
    And I fill in "Log message for this state change *" with "I changed my mind."
    Then I press the "Update state" button
    And I visit "content/my-second-post"
    And I should see the text "Content State: Private Draft"

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
    And I should see the text "Content State: Private Draft"
    And I press the "Request Approval" button
    And I fill in "Log message for this state change *" with "Please approve my first post."
    Then press the "Update state" button
    And I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "My first post."
    And I press the "Publish" button
    And I fill in "Log message for this state change *" with "Looks good."
    And I press "Update state"

    # Content is in published state the request approval button should not be visible
    Given I am logged in as "Joe Contributor"
    And I visit "content/my-first-post"
    And I click "Edit"
    And I fill in "Body" with "This is my unpublished addition"
    # prc-857 No delete and request buttons on published node
    And I should not see the button "Request Approval"
    And I should not see the button "Delete"
    # prc-856
    And I press the "Save New Draft" button
    And I visit "admin-content"
    # prc-844
    And I should see the text "Draft" in the "My first post." row
    #Go into workflow and find the new draft
    And I visit "content/my-first-post"
    And I click "Workflow"
    And I click "Request Approval"
    And I fill in "Log message for this state change *" with "Please approve my update."
    When  I press "Update state"
    And I click "Log out"
    Then I visit "content/my-first-post"
    And I should see "Isn't this swell?"
    And I should not see "This is my unpublished addition"

    #Content is updated after approval
    Given I am logged in as "Joe Curator"
    And I visit "admin-content"
    And I click "pending review"
    And I press the "Publish" button
    And I fill in "Log message for this state change *" with "Update approved."
    And I press the "Update state" button
    Then I click "Log out"
    And I visit "content/my-first-post"
    And I should see the text "This is my unpublished addition"

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
    #  NOTE: When they click on "pending review" link in Actions column, it works fine.
    Given I am logged in as "Joe Contributor"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My first post @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I follow "Edit"
    And I press "Request Approval"
    And I fill in "Log message for this state change *" with "Review requested"
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
    And I fill in "Log message for this state change *" with "Review requested"
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
    And I fill in "Log message for this state change *" with "Review requested"
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
    And I fill in "Log message for this state change *" with "Review requested"
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
    And I fill in "Log message for this state change *" with "Review requested"
    When I press the "Update state" button

    Given I am an anonymous user

    Then I am logged in as "Joe Curator"
    And I follow "Content"
    And I follow "PRC-592 @timestamp"
    Then I press "Request Change"
    Then I should see the text "Message"

