@api @search @prc-106 @prc-560 @prc-559 @prc-1272 @prc-1354 @prc-1716
Feature: PRC-106 Search Content- Advanced
  As an educator,
  I want to narrow down my search results by entering advanced filtering criteria,
  so that I can find the specific content I'm looking for.

  #  BACKGROUND: The Search functionality in the header is global, and will search through all types of content in PRC, including:
  #  i. Digital Library
  #  ii. Professional Development
  #  iii. Assessments (Not implemented yet)
  #  Acceptance Criteria

  Scenario: PRC-559 Filters header was missing
    Given I am on "search-content"
    Then I should see the text "Filters"

  Scenario: AC2 A Clear All link shall be available by Filters title. At click, it resets the filters to no filter.
    Given "Subject" terms:
      | name     |
      | Subj one |
      | Subj two |
    And "Digital Library Content" nodes:
      | title  | body      | status | promote | uid | language | field_subject |
      | Africa | Continent | 1      | 0       | 1   | und      | Subj one      |
      | Europe | Continent | 1      | 0       | 1   | und      | Subj two      |
    And I run drush "sapi-i"
    When I visit "search-content"
    Then I should see the link "Subj one (1)"
    And I should see the link "Subj two (1)"
    Then I should see the link "Africa"
    And I should see the link "Europe"
    When I click "Subj one (1)"
    Then I should see an ".filter-panel-all-link" element
    And I should see the link "Africa"
    But I should not see the link "Europe"
    And I should not see the text "Subj two"
    When I click on the element with css selector ".filter-panel-all-link"
    Then I should see the link "Subj one (1)"
    And I should see the link "Subj two (1)"
    Then I should see the link "Africa"
    And I should see the link "Europe"

  Scenario: Searches through types
    Given "Digital Library Content" nodes:
      | title      | body      | status | promote | uid | language |
      | Africa DLC | Continent | 1      | 0       | 1   | und      |
    And "PD Course" nodes:
      | title      | body      | status | promote | uid | language |
      | Africa PDC | Continent | 1      | 0       | 1   | und      |
    And "PD Module" nodes:
      | title      | body      | status | promote | uid | language |
      | Africa PDM | Continent | 1      | 0       | 1   | und      |
    And I run drush "sapi-i"
    When I visit "search-content"
    Then I should not see the text "Subj one"
    And I fill in "edit-search-api-views-fulltext" with "Africa"
    And I press "Apply"
    Then I should see the link "Africa DLC"
    And I should see the link "Africa PDC"
    But I should not see the link "Africa PDM"

  Scenario: Searches through body
    Given "Digital Library Content" nodes:
      | title      | body     | status | promote | uid | language |
      | Africa DLC | Body DLC | 1      | 0       | 1   | und      |
    And "PD Course" nodes:
      | title      | field_course_objectives | status | promote | uid | language |
      | Africa PDC | Body PDC                | 1      | 0       | 1   | und      |
    And "PD Module" nodes:
      | title      | body     | status | promote | uid | language |
      | Africa PDM | Nope PDM | 1      | 0       | 1   | und      |
    And I run drush "sapi-i"
    When I visit "search-content"
    And I fill in "edit-search-api-views-fulltext" with "Body"
    And I press "Apply"
    Then I should see the link "Africa DLC"
    And I should see the link "Africa PDC"
    But I should not see the link "Africa PDM"

  Scenario: Searches through tags
    Given "Tags" terms:
      | name   |
      | prc597 |
      | prc593 |
    Given "Digital Library Content" nodes:
      | title      | body      | status | promote | uid | language | field_tags |
      | Africa DLC | Continent | 1      | 0       | 1   | und      | prc597     |
    And "PD Course" nodes:
      | title      | body      | status | promote | uid | language | field_tags |
      | Africa PDC | Continent | 1      | 0       | 1   | und      | prc597     |
    And "PD Module" nodes:
      | title      | body      | status | promote | uid | language | field_tags |
      | Africa PDM | Continent | 1      | 0       | 1   | und      | prc593     |
    And I run drush "sapi-i"
    When I visit "search-content"
    And I fill in "edit-search-api-views-fulltext" with "prc597"
    And I press "Apply"
    Then I should see the link "Africa DLC"
    And I should see the link "Africa PDC"
    But I should not see the link "Africa PDM"

  @javascript
  Scenario: Searches through tags
    Given "Tags" terms:
      | name   |
      | prc597 |
      | prc593 |
    Given "Digital Library Content" nodes:
      | title      | body      | status | promote | uid | language | field_tags |
      | English    | Ribs      | 1      | 0       | 1   | und      | prc597     |
      | American   | Bacon     | 1      | 0       | 1   | und      | prc597     |
      | African    | Ham       | 1      | 0       | 1   | und      | prc593     |
    And I run drush "sapi-i"
    When I visit "/library"
    And I should see the text "English"
    And I should see the text "American"
    And I should see the text "African"
    And I fill in "edit-search-api-views-fulltext" with "prc597"
    And I wait 1 seconds
    Then I should see the text "English"
    And I should see the text "American"
    But I should not see the text "Ham"

  Scenario: AC3 The system shall provide each the following filters:
    Given "Media Type" terms:
      | name   |
      | AC3 MT |
    And "Subject" terms:
      | name   |
      | AC3 Su |
    Given "Digital Library Content" nodes:
      | title      | body      | status | promote | uid | language | field_author_name | field_media_type | field_subject | field_standard |
      | Africa DLC | Continent | 1      | 0       | 1   | und      | Author One        | AC3 MT           | AC3 Su        | s11436b2       |
    And "PD Course" nodes:
      | title      | body      | status | promote | uid | language |
      | Africa PDC | Continent | 1      | 0       | 1   | und      |
    And "PD Module" nodes:
      | title      | body      | status | promote | uid | language |
      | Africa PDM | Continent | 1      | 0       | 1   | und      |
    And I run drush "sapi-i"
    When I visit "search-content"
    Then I should see the text "Content Type"
    Then I should see the text "Author"
    Then I should see the text "Media Type"
    Then I should see the text "Subject"
    Then I should see the text "Standard"
    And "By Content Type" should precede "Author" for the query ".pane-title"
    And "By Media Type" should precede "Subject" for the query ".pane-title"
    And "By Subject" should precede "Standard" for the query ".pane-title"

  Scenario: AC4 Each of the above filters are followed by their available values, along with the results count in the parentheses. See example below:
    Given "Subject" terms:
      | name     |
      | Subj one |
      | Subj two |
    And "Digital Library Content" nodes:
      | title  | body      | status | promote | uid | language | field_subject |
      | Africa | Continent | 1      | 0       | 1   | und      | Subj one      |
    And I run drush "sapi-i"
    When I visit "search-content"
    Then I should see the link "Subj one (1)"
    #  AC5 Only the filter values with a non-zero count shall be displayed. For example, do not show:
    #  Geometry (0)
    And I should not see the text "Subj two"

  Scenario: AC6 Filters with no value shall be invisible (For example, if none of the search results' content has an associated Standard , do not display Standard as a filter).
    Given "Subject" terms:
      | name     |
      | Subj one |
      | Subj two |
    And "Digital Library Content" nodes:
      | title  | body      | status | promote | uid | language |
      | Africa | Continent | 1      | 0       | 1   | und      |
    And I run drush "sapi-i"
    When I visit "search-content"
    Then I should not see the text "Subj one"
    And I fill in "edit-search-api-views-fulltext" with "Africa"
    And I press "Apply"
    Then I should not see the text "By Standard"

  Scenario: AC7 Clicking a filter value shall display the associated content only.
    Given "Subject" terms:
      | name     |
      | Subj one |
      | Subj two |
    And "Digital Library Content" nodes:
      | title  | body      | status | promote | uid | language | field_subject |
      | Africa | Continent | 1      | 0       | 1   | und      | Subj one      |
      | Europe | Continent | 1      | 0       | 1   | und      | Subj two      |
    And I run drush "sapi-i"
    When I visit "search-content"
    Then I should see the link "Subj one (1)"
    And I should see the link "Subj two (1)"
    When I click "Subj one (1)"
    Then I should see the link "Africa"
    But I should not see the link "Europe"
    And I should not see the text "Subj two"

  Scenario: Quick search takes user to new search page
    #  AC1 When a user searches for content by entering a keyword in Quick Search section (defined in PRC-31),
    #  the system redirects the user to the Search Results page (currently available), where a new left panel shall be
    #  available to display the filtering criteria in the Search Results page, titled as: Filters
    Given I am an anonymous user
    And I am on the homepage
    When I fill in "something" for "Search" in the "header" region
    And I press "Search" in the "header" region
    Then I should be on "search-content/search_api_views_fulltext?search_api_views_fulltext=something"

  Scenario: PRC-560 Index field_author_name as string rather than fulltext
    Given I have no "Digital Library Content" nodes
    And "Digital Library Content" nodes:
      | title  | body      | status | promote | uid | language | field_author_name |
      | Africa | Continent | 1      | 0       | 1   | und      | Auth One Alpha    |
      | Europe | Continent | 1      | 0       | 1   | und      | Auth Two Beta     |
    And I run drush "sapi-i"
    When I visit "search-content"
    Then I should see the link "auth one alpha"
    And I should see the link "auth two beta"
    When I click "auth one alpha"
    Then I should see the link "Africa"
    But I should not see the link "Europe"
    And I should not see the text "auth two beta"

  Scenario: PRC-1272 Site search - no results
    Given I have no "Digital Library Content" nodes
    And I have no "PD Course" nodes
    And I have no "Assessment" nodes
    And I run drush "sapi-c"
    When I visit "search-content"
    Then I should see the text "There are no results to display. Please change the search keywords and try again."
    # PRC-1354 - Heading
    And I should see the heading "Search Results"