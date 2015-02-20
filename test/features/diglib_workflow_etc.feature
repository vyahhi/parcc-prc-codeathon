@api
Feature: Workflow is functional

  Background:
    Given users:
      | name                       | mail                                | pass   | field_first_name | field_last_name | status | roles                           |
      | Joe Educator @timestamp    | joe_1prc_58ed@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator                        |
      | Joe Contributor @timestamp | joe_1prc_58cc@timestamp@example.com | xyz123 | Joe              | Contributor     | 1      | Content Contributor             |
      | Joe Curator @timestamp     | joe_1prc_58ca@timestamp@example.com | xyz123 | Joe              | Curator         | 1      | Content Administrator (Curator) |
    And the test email system is enabled

  Scenario: From draft to publish, editor makes changes and publishes, contributor publishes
    Given I am logged in as "Joe Contributor @timestamp"
    And I visit "admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My first post."
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    And I click "Edit"
    And I press the "Request Approval" button
    And I fill in "Log message for this state change *" with "Please approve my first post."
    And press the "Update state" button
    #Then the email to "joe_1prc_58cc@timestamp@example.com" should contain "The following content is awaiting approval"

    # Curator approves review
    Given I am logged in as "Joe Curator @timestamp"
    And I visit "admin-content"
    And I click "pending review"
    And I press the "Approve" button
    And I fill in "Log message for this state change *" with "Looks good to me."
    When I press the "Update state" button
    #Then the email to "joe_1prc_58cc@timestamp@example.com" should contain "The following digital library content has been published."

    # Curator updates published content
    Given I am logged in as "Joe Curator @timestamp"
    And I visit "content/my-first-post"
    And I click "Edit"
    And I fill in "Body" with "This is what I have to say."
    When I press "Save and Publish"
    And I fill in "Log message for this state change *" with "Need to get my word in."
    And I press the "Update state" button
    #Then the email to "joe_1prc_58cc@timestamp@example.com" should contain "The following digital library content has been published."
    And I click "Log out"
    And I visit "content/my-first-post"
    And I should see the text "This is what I have to say."

    #Contributer requests a new draft be published
    Given I am logged in as "Joe Contributor @timestamp"
    And I visit "content/my-first-post"
    And I should see the text "Content State: Published"
    And I click "Edit"
    And I fill in "Body" with "Here is my clever addition."
    When I press the "Request Approval" button
    And I fill in "Log message for this state change *" with "I'm so clever."
    Then I press the "Update state" button

    #Curator approves new draft
    Given I am logged in as "Joe Curator @timestamp"
    And I visit "admin-content"
    And I click "pending review"
    And I press the "Approve" button
    And I fill in "Log message for this state change *" with "Wow, you are so clever."
    When I press the "Update state" button
    #Then the email to "joe_1prc_58cc@timestamp@example.com" should contain "The following digital library content has been published."

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
    #Then the email to "joe_1prc_58cc@timestamp@example.com" should contain "Do it again, not so clever."
