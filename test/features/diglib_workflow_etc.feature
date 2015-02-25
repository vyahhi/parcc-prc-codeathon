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
      Given I am logged in as "Joe Contributor @timestamp"
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

      Then I am logged in as "Joe Curator @timestamp"
      And I follow "Content"
      And I follow "My first post @timestamp"
      Then I should see the text "My first post @timestamp"
      And I should not see the text "Access denied"

    Scenario: PRC-829 Not Approving Content - Items are not in specified order
      Given I am logged in as "Joe Contributor @timestamp"
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

      Then I am logged in as "Joe Curator @timestamp"
      And I follow "Content"
      And I follow "My first post @timestamp"
      Then I press "Request Change"
      Then "Instructions: (to be added)" should precede "Changes before Approval *" for the query "div"

    Scenario: PRC-830 Content Curation: Not Approving Content- Form Title not as specified in AC
      Given I am logged in as "Joe Contributor @timestamp"
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

      Then I am logged in as "Joe Curator @timestamp"
      And I follow "Content"
      And I follow "PRC-592 @timestamp"
      Then I press "Request Change"
      Then I should see the text "Changes before Approval for PRC-592"

  Scenario: PRC-832 Content Curation: Not Approving Content- Send Request button not as specified
    Given I am logged in as "Joe Contributor @timestamp"
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

    Then I am logged in as "Joe Curator @timestamp"
    And I follow "Content"
    And I follow "PRC-592 @timestamp"
    Then I press "Request Change"
    Then I press "Send Request"