@api @diglib @workflow
Feature: Workflow is functional

  Scenario: From draft to publish, editor makes changes and requests review, contributor publishes, etc
    Given users:
      | name                      | mail                                | pass   | field_first_name | field_last_name | status | roles                           |
      | Joe Educator@timestamp    | joe_1prc_58ed@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator                        |
      | Joe Contributor @timestamp | joe_1prc_58cc@timestamp@example.com | xyz123 | Joe              | Contributor     | 1      | Content Contributor             |
      | Joe Curator @timestamp     | joe_1prc_58ca@timestamp@example.com | xyz123 | Joe              | Curator         | 1      | Content Administrator (Curator) |
    And the test email system is enabled
    And I am logged in as "Joe Contributor @timestamp"
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
    And the email to "joe_1prc_58ca@timestamp@example.com" should contain "The following content is awaiting approval"
    And I click "Log out"
    And I follow the link in the email
    And I should see the text "Access Denied"
    And I should see the text "If you have an account please log in."

    # Curator approves review
    Given I am logged in as "Joe Curator @timestamp"
    And I visit "admin-content"
    And I click "pending review"
    And I press the "Publish" button
    And I fill in "Log message for this state change *" with "Looks good to me."
    When I press the "Update state" button
    And I click "Log out"
    And I visit "content/my-first-post"
    And I should see the text "My first post"
    Then the email to "joe_1prc_58cc@timestamp@example.com" should contain "The following digital library content has been published."

    # Curator updates published content
    Given I am logged in as "Joe Curator @timestamp"
    And I visit "content/my-first-post"
    And I should see the text "Content State: Published"
    And I click "Edit"
    And I fill in "Body" with "This is what I have to say."
    When I press "Save and Publish"
    And I fill in "Log message for this state change *" with "Need to get my word in."
    And I press the "Update state" button
    Then the email to "joe_1prc_58cc@timestamp@example.com" should contain "The following digital library content has been published."
    And I click "Log out"
    And I visit "content/my-first-post"
    And I should see the text "This is what I have to say."

    # Contributor requests a new draft be published
    Given I am logged in as "Joe Contributor @timestamp"
    And I visit "content/my-first-post"
    And I should see the text "Content State: Published"
    And I click "Edit"
    And I fill in "Body" with "Here is my clever addition."
    When I press the "Request Approval" button
    And I fill in "Log message for this state change *" with "I'm so clever."
    Then I press the "Update state" button

    # Curator approves new draft
    Given I am logged in as "Joe Curator @timestamp"
    And I visit "admin-content"
    And I click "pending review"
    And I press the "Publish" button
    And I fill in "Log message for this state change *" with "Wow, you are so clever."
    When I press the "Update state" button
    Then the email to "joe_1prc_58cc@timestamp@example.com" should contain "The following digital library content has been published."

    #contributer is denied
    Given I am logged in as "Joe Contributor @timestamp"
    And I visit "content/my-first-post"
    And I should see the text "Content State: Published"
    And I click "Edit"
    And I fill in "Body" with "Here is my really clever addition."
    When I press the "Request Approval" button
    And I fill in "Log message for this state change *" with "I'm so clever."
    Then I press the "Update state" button
    And I am logged in as "Joe Curator @timestamp"
    And I visit "admin-content"
    And I click "pending review"
    And I press the "Request Change" button
    And I fill in "Changes before Approval *" with "Do it again, not so clever."
    When I press the "Update state" button
    And I visit "content/my-first-post"
    And I should see the text "Content State: Published"
    Then the email to "joe_1prc_58cc@timestamp@example.com" should contain "Do it again, not so clever."

    #Unpublish
    Given I am logged in as "Joe Curator @timestamp"
    And I visit "content/my-first-post"
    And I click "Edit"
    And I press the "Unpublish" button
    And I fill in "Log message for this state change *" with "Let's take this down."
    And I press the "Update state" button
    And I visit "admin-content"
    And I click "My first post"
    And I should see the text "Content State: Unpublished"
    Then the email to "joe_1prc_58cc@timestamp@example.com" should contain "The following digital library content has been unpublished."
    And I click "Log out"
    And I follow the link in the email
    And I should not see the text "Isn't this swell"
    And I should see the text "Access Denied"
    And I should see the text "If you have an account please log in."

    #Requesting review and cancelling after it has been published once
    Given I am logged in as "Joe Contributor @timestamp"
    And I visit "content/my-first-post"
    And I should see the text "Content State: Unpublished"
    And I click "Edit"
    And I press the "Request Approval" button
    And I fill in "Log message for this state change *" with "Please approve my first post."
    When press the "Update state" button
    And I visit "content/my-first-post"
    And I should see the text "Approval Requested"
    And I click "Rescind Request"
    And I fill in "Log message for this state change *" with "Please approve my first post."
    Then I press the "Update state" button
    And the email to "joe_1prc_58ca@timestamp@example.com" should contain "The following content has been withdrawn from review."
    And I visit "content/my-first-post"
    And I should see the text "Content State: Unpublished"

    #Curator publishes without needing approval
    Given I am logged in as "Joe Curator @timestamp"
    And I visit "admin-content"
    And I click "My first post"
    And I press the "Publish" button
    And I fill in "Log message for this state change *" with "Let's put this back up."
    And I press the "Update state" button
    When I visit "content/my-first-post"
    Then I should see the text "Content State: Published"
    And the email to "joe_1prc_58cc@timestamp@example.com" should contain "The following digital library content has been published."

  # Cancelling a request before it was ever published
    Given I am logged in as "Joe Contributor @timestamp"
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
    And the email to "joe_1prc_58ca@timestamp@example.com" should contain "The following content is awaiting approval"
    And I click "Rescind Request"
    And I fill in "Log message for this state change *" with "I changed my mind."
    Then I press the "Update state" button
    And I visit "content/my-second-post"
    And I should see the text "Content State: Private Draft"

  Scenario: Content is published, but changes don't show up until after it has been approved
    Given users:
      | name                      | mail                                | pass   | field_first_name | field_last_name | status | roles                           |
      | Joe Educator@timestamp    | joe_1prc_58ed@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator                        |
      | Joe Contributor @timestamp | joe_1prc_58cc@timestamp@example.com | xyz123 | Joe              | Contributor     | 1      | Content Contributor             |
      | Joe Curator @timestamp     | joe_1prc_58ca@timestamp@example.com | xyz123 | Joe              | Curator         | 1      | Content Administrator (Curator) |
    And the test email system is enabled
    And I am logged in as "Joe Contributor @timestamp"
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
    And I am logged in as "Joe Curator @timestamp"
    And I visit "admin-content"
    And I click "My first post."
    And I press the "Publish" button
    And I fill in "Log message for this state change *" with "Looks good."
    And I press "Update state"

    #content is in published state
    Given I am logged in as "Joe Contributor @timestamp"
    And I visit "content/my-first-post"
    And I click "Edit"
    And I fill in "Body" with "This is my unpublished addition"
    And I press the "Request Approval" button
    And I fill in "Log message for this state change *" with "Please approve my update."
    When  I press "Update state"
    And I click "Log out"
    Then I visit "content/my-first-post"
    And I should see "Isn't this swell?"
    And I should not see "This is my unpublished addition"

    #Content is updated after approval
    Given I am logged in as "Joe Curator @timestamp"
    And I visit "admin-content"
    And I click "pending review"
    And I press the "Publish" button
    And I fill in "Log message for this state change *" with "Update approved."
    And I press the "Update state" button
    Then I click "Log out"
    And I visit "content/my-first-post"
    And I should see the text "This is my unpublished addition"



