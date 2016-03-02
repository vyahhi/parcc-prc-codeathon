@api @diglib @workflow
Feature: PRC-1825 - Allow prc admin to do everything a curator can

  Background:
    Given users:
      | name            | mail                      | pass   | field_first_name | field_last_name | status | roles               |
      | Joe Educator    | joe_1prc_58ed@example.com | xyz123 | Joe              | Educator        | 1      | Educator            |
      | Joe Contributor | joe_1prc_58cc@example.com | xyz123 | Joe              | Contributor     | 1      | Content Contributor |
      | Joe Curator     | joe_1prc_58ca@example.com | xyz123 | Joe              | Curator         | 1      | PRC Admin           |
    And the test email system is enabled

  Scenario: From draft to publish, editor makes changes and publishes, prc admin publishes
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My first post @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I click "Edit"
    And I press the "Request Approval" button
    And I should not see an "textarea" element
    Then press the "Update state" button

    Given I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I press the "Publish" button
    And I should not see an "textarea" element
    When I press the "Update state" button
    And I visit "user/logout"
    And I index search results
    And I visit "library"
    And I click "My first post @timestamp"
    And I should see the text "My first post @timestamp"
    Then the email to "joe_1prc_58cc@example.com" should contain "The following Digital Library content has been published."
    And the email should contain "Content Administrator: Joe Curator (joe_1prc_58ca@example.com)"

    # Curator updates published content
    Given I am logged in as "Joe Curator"
    And I visit "library"
    And I click "My first post @timestamp"
    And I click "Edit"
    And I fill in "Body" with "This is what I have to say."
    When I press "Save and Publish"
    And I should not see an "textarea" element
    And I press the "Update state" button
    And I visit "user/logout"

    And I index search results
    And I visit "library"
    And I click "My first post @timestamp"
    And I should see the text "This is what I have to say."

    #Contributer requests a new draft be published
    Given I am logged in as "Joe Contributor"
    And I visit "library"
    And I click "My first post @timestamp"
    And I click "Edit"
    And I fill in "Body" with "Here is my clever addition."
    And I press the "Save" button
    And I press "Confirm"
    And I click "Edit Revision"
    When I press "Request Approval"
    And I should not see an "textarea" element
    Then I press the "Update state" button

    #Curator approves new draft
    Given I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I press the "Publish" button
    And I should not see an "textarea" element
    When I press the "Update state" button
    Given I am logged in as "Joe Contributor"
    And I visit "library"
    And I click "My first post @timestamp"
    And I click "Edit"
    And I fill in "Body" with "Here is my really clever addition."
    And I press "Save"
    And I press "Confirm"
    And I click "Edit Revision"
    When I press the "Request Approval" button
    And I should not see an "textarea" element
    Then I press the "Update state" button
    And I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I press the "Request Change" button
    And I fill in "Message *" with "Do it again, not so clever."
    When I press the "Send Request" button
    And I visit "library"
    And I click "My first post @timestamp"
    Given I am logged in as "Joe Curator"
    And I visit "library"
    And I click "My first post @timestamp"
    And I click "Edit"
    And I press the "Unpublish" button
    And I press the "Update state" button
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I click "Edit"
    And I press the "Request Approval" button
    When press the "Update state" button
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I should see the text "Approval Requested"
    And I click "Rescind Request"
    And I should not see an "textarea" element
    Then I press the "Update state" button
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"

    Given I am logged in as "Joe Curator"
    And I visit "prc/admin/admin-content"
    And I click "My first post @timestamp"
    And I press the "Publish" button

    And I should not see an "textarea" element
    And I press the "Update state" button
    When I visit "library"
    And I click "My first post @timestamp"
    Given I am logged in as "Joe Contributor"
    And I visit "prc/admin/admin-content"
    And I click "Add content"
    And I fill in "edit-title" with "My second post @timestamp"
    And I fill in "Body" with "Isn't this swell?"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I click "Edit"
    And I press the "Request Approval" button
    And I should not see an "textarea" element
    And press the "Update state" button
    And I visit "prc/admin/admin-content"
    And I click "My second post @timestamp"
    And I should see the text "Approval Requested"
    And I click "Rescind Request"
    And I should not see an "textarea" element
    Then I press the "Update state" button
    And I visit "prc/admin/admin-content"
    And I click "My second post @timestamp"
    And I visit "prc/admin/admin-content"
    And I should see the text "Draft" in the "My second post @timestamp" row