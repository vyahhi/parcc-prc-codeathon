#@api @workflow @diglib
  Feature: As a Content Contributor, I want the system to keep track of the previous versions when a new version of
    Digital Library content is published.

    Background:
      Given users:
        | name            | mail                      | pass   | field_first_name | field_last_name | status | roles                           |
        | Joe Contributor | joe_1prc_58cc@example.com | xyz123 | Joe              | Contributor     | 1      | Content Contributor             |
        | Joe Curator     | joe_1prc_58ca@example.com | xyz123 | Joe              | Curator         | 1      | Content Administrator (Curator) |
      And I am logged in as "Joe Contributor"
      And I create "Public" Digital Library Content with the title "My Title @timestamp"

# A new tab, Revisions, shall be added for all PRC Digital Library content pages, viewable for the originating
# - Content Contributor and the Content Administrator (Curator).
# - The Version History tab will be in the tab bar along with the existing View and Edit tabs.
    Scenario: Tab isn't shown for content without revisions
    And I visit "admin-content"
    And I click "My Title @timestamp"
    And I should not see the link "Revisions"

  Scenario: Tab is shown for content with revisions
    Given I am logged in as a user with the "Content Contributor" role
    And I advance "My Title @timestamp" to the "Draft" state
    And I visit "admin-content"
    And I click "My Title @timestamp"
    And I click "Revisions"
    And I should not see the text "Access Denied"

  Scenario: Creating a new draft doesn't change the published content
    Given I am logged in as a user with the "Content Contributor" role
    And I advance "My Title @timestamp" to the "Published" state
    And I visit "admin-content"
    And I click "My Title @timestamp"
    And I click "Edit"
    And I fill in "Title *" with "Changed Title @timestamp"
    When I press "Save new Draft"
    And I press "Confirm"
    Then I visit "digital-library"
    And I should see the text "My Title @timestamp"
    And I should not see the text "Changed Title @timestamp"

  Scenario: Content contributor gets a new version published
    Given I am logged in as a user with the "Content Contributor" role
    And I advance "My Title @timestamp" to the "Published" state
    And I visit "admin-content"
    And I click "My Title @timestamp"
    And I click "Edit"
    And I fill in "Title *" with "Changed Title @timestamp"
    When I press "Save new Draft"
    And I press "Confirm"
    And I visit "admin-content"
    And I click "My Title @timestamp"
    And I click "Revisions"
  #    Walk new revision through the workflow.
  #    Verify that new content is present in Digital Library.
  #    Verify that original content is not present in Digital Library.
    And fail

  Scenario: Confirm that it doesn't work as it does now?
  #    Create published DLC nodes
  #    Create new revision.
  #    Navigate to Content tab.
  #    Verify that new revision is in the content tab.
  #    Verify that original content is not in the content tab.
    And fail

  Scenario: Current revision section of the revisions tab is correct
    #    *** Current Editorial Status of the Content
    #    *** Content Revision ID
    And fail

  Scenario: Diff is working correctly
    Given I am logged in as a user with the "Content Contributor" role
    And I advance "My Title @timestamp" to the "Published" state
    And I visit "admin-content"
    And I click "My Title @timestamp"
    And I click "Edit"
    And I fill in "Title *" with "Changed Title @timestamp"
    When I press "Save new Draft"
  #    Diff revisions and check output.
    And fail

  Scenario: The history section of the revisions tab is correct.
    And it should fail

#    ** The Current Revision section contains the following:

#    ** The History section contains a two-column table that has a Date and Message columns
#    ** The History table entries will display changes to the Content in reverse chronological order
#    ** The Date of the Editorial Change will display the local date and time of the current user's system time.
#    {quote}
#    12/31/2016 - 13:30
#    {quote}
#    ** The Message will display the description of the Editorial Change
#    {quote}
#    [name of contributor/curator] transitioned revision [Revision ID] to [Editorial Status]
#    [comment - if available]
#    {quote}
#    ** For content changes, the History entry will be appended with a two-column section, displaying the previous and
#    changed content in a side-by-side comparison.
#    *** Each content section that has changed is displayed.
#    *** {color:red} Dev to confirm {color} Differences in content is highlighted.
#    *** {color:red} Dev to confirm {color} Changes in hierarchal menus display to lowest level change.
#    *** {color:red} Dev to confirm {color} Displaying deletions.
