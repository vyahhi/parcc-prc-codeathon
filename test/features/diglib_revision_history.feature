@api @diglib @revisions @prc-1269 @prc-1030 @prc-1489
Feature: PRC-1269 Content Version History - revisions for all fields
  As a Content Contributor,
  I want the system to keep track of the previous versions when a new version of Digital Library content is published.

#  Given that I am logged in as a Content Contributor or Content Administrator (Curator)
#  When I click on the Revisions tab
#  Then I see the Revisions page that has:
#  Changes from existing functionality (see PRC-45 Content Version History)
#  Tracked changes for all content fields:
#  Title
#  Author Name
#  Tags
#  Body
#  Attachment
#  Thumbnail
#  Link to URL
#  Grade level
#  Subject
#  Media Type
#  Genre
#  Standard
#  Permissions
  Scenario: Body field track changes
    Given I am logged in as a user with the "Content Contributor" role
    And "Digital Library Content" nodes:
      | title              | body                   | status | field_permissions | uid         |
      | PRC-1269 DLC Title | PRC-1269 DLC Body Text | 1      | public            | @currentuid |
    And I visit the first node created
    And I click "Edit"
    And I fill in "Body" with "New Body Text Here"
    And I press "Save"
    And I click "Revisions"
    Then I should see the text "PRC-1269 DLC"
    And I should see the text "New Body Text Here"

  Scenario: Title field track changes
    Given I am logged in as a user with the "Content Contributor" role
    And "Digital Library Content" nodes:
      | title              | body                   | status | field_permissions | uid         |
      | PRC-1269 DLC Title | PRC-1269 DLC Body Text | 1      | public            | @currentuid |
    And I visit the first node created
    And I click "Edit"
    And I fill in "edit-title" with "New Title Text Here"
    And I press "Save"
    And I click "Revisions"
    Then I should see the text "PRC-1269 DLC"
    And I should see the text "New Title Text Here"

    # TODO: Better test coverage - scaffolded nodes don't save all the safe_value vs value correctly

  Scenario: PRC-1489 Revisions for Tags terms should be delimited.
    Given I am logged in as a user with the "Content Contributor" role
    And "Digital Library Content" nodes:
      | title              | body                   | status | field_permissions | uid         |
      | PRC-1269 DLC Title | PRC-1269 DLC Body Text | 1      | public            | @currentuid |
    And I visit the first node created
    And I click "Edit"
    And I fill in "Tags" with "Bacon ipsum dolor amet chicken, Pork loin pork chop, Porchetta pastrami meatball fatback"
    When I press "Save"
    And I click "Revisions"
    Then I should not see text matching "Bacon ipsum dolor amet chicken Pork loin pork chop Porchetta pastrami meatball fatback"
    But I should see text matching "Bacon ipsum dolor amet chicken, Pork loin pork chop, Porchetta pastrami meatball fatback"

  @javascript
  Scenario: PRC-1489 Revisions for Subject terms should be delimited.
    Given I am logged in as a user with the "Content Contributor" role
    And "Digital Library Content" nodes:
      | title              | body                   | status | field_permissions | uid         |
      | PRC-1269 DLC Title | PRC-1269 DLC Body Text | 1      | public            | @currentuid |
    And I visit the first node created
    And I click "Edit"
    And I click "Add More Information (Content Properties)"
    And I select "Math" from "edit-field-subject-und-0-tid-select-1"
    And I wait for AJAX to finish
    And I select "Basic Counting" from "edit-field-subject-und-0-tid-select-2"
    And I press "Add another item"
    And I select "Math" from "edit-field-subject-und-1-tid-select-1"
    And I wait for AJAX to finish
    And I select "Number System" from "edit-field-subject-und-1-tid-select-2"
    When I press "Save"
    And I click "Revisions"
    Then I should not see text matching "Basic Counting Number System"
    But I should see text matching "Basic Counting, Number System"
