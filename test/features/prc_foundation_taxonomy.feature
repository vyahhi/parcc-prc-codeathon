@api @d7 @styleguide @prc-1628 @taxonomy
Feature: Style Taxonomy Drill Down Pages (PRC-1628)
  As a user
  when I click on a taxonomy link throughout the PRC site
  I want to be taken to a styled faceted search page so that I can see links and information to related content.

  ##### Taxonomy List Page #####

  @javascript
  Scenario: Taxonomy Drill Down Pages Display Appropriate Content
    Given I have no "Digital Library Content" nodes
    And "Digital Library Content" nodes:
      | title      | body         | status | promote | uid | field_author_name | field_thumbnail     | field_subject | field_grade_level_unlimited | field_media_type |
      | 1st Grade Content | Body Content 1st Grade | 1      | 0       | 1   | Author Name       | lovelythumbnail.png | Math          | 1st Grade                   | Text             |
      | 2nd Grade Content | Body Content 2nd Grade | 1      | 0       | 1   | Author Name       | lovelythumbnail.png | Math          | 2nd Grade                   | Text             |
    And I index search results
    And I am logged in as a user with the "authenticated user" role
    When I am browsing using a "desktop"
    And I visit the last node created
    And I follow "2nd Grade"
    Then I should see text matching "2nd Grade"
    And I should see text matching "2nd Grade Content"
    And I should see text matching "Body Content 2nd Grade"
    And I should not see text matching "Author Name"
    And I should not see text matching "Math"
    And I should not see text matching "Text"
    And I should not see text matching "1st Grade"
    And I should not see text matching "1st Grade Content"
    And I should not see text matching "Body Content 1st Grade"
    When I follow "Read more"
    Then I should see text matching "2nd Grade Content"
