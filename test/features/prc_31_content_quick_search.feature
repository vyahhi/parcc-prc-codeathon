@api
Feature: Search Content - Quick Search (PRC-31)
  As an educator,
  I want to search for content by entering a keyword,
  so that I can quickly find the content I'm looking for.

  Scenario: AC1 - Content search
    Given I am logged in as a user with the "Educator" role
    And I am on "search"
    Then I should see the heading "Search" in the "content" region
    And I should see an "Enter your keywords" field
    And I should see an "edit-submit" button

  Scenario: AC1(ish) - Should not see Advanced search here
    Given I am logged in as a user with the "Educator" role
    And I am on "search"
    Then I should not see the text "Advanced search"

  @javascript
  Scenario: AC2 - Search terms
    Given "Digital Library Content" nodes:
      | title         | body      | status | promote | uid | language | tags         | field_author_name |
      | Africa        | Continent | 1      | 0       | 1   | und      | North        | Ted    |
      | Europe        | Continent | 1      | 0       | 1   | und      | South        | Fred   |
      | North America | Continent | 1      | 0       | 1   | und      | East         | Ed     |
      | South America | Continent | 1      | 0       | 1   | und      | East, West   | Jed    |
      | South Africa  | Country   | 1      | 0       | 1   | und      | South        |        |
      | Austria       | Country   | 1      | 0       | 1   | und      | North        |        |
    And I run drush "search-index"
    # Cron redirects us. Navigate back. Also cron will pop errors into the log but it still runs and indexes.
    And I am logged in as a user with the "Educator" role
    And I am on "search"
    When I fill in "Enter your keywords" with "Africa"
    And I press "edit-submit"
    Then I should not see the text "Your search yielded no results"
    And I should see the text "Search results for: Africa"
    But I should see the text "Africa"
    And I should see the text "Continent"
    And I should see the text "Created"
    Then I break
    And I should see the text "by Ted"
    And I should see the text "South Africa"
    And I should see the text "Country"
    But I should not see the text "Europe"
    And I should not see the text "America"

    When I fill in "Enter your keywords" with "America"
    And I press "edit-submit"
    Then I should see the text "North America"
    And I should see the text "South America"
    And I should see the text "Continent"
    But I should not see the text "Country"
    And I should not see the text "Europe"
    And I should not see the text "Africa"
    And I should not see the text "Austria"

    When I fill in "Enter your keywords" with "Continent"
    And I press "edit-submit"
    Then I should see the text "Africa"
    And I should see the text "North America"
    And I should see the text "South America"
    And I should see the text "Europe"
    But I should not see the text "Austria"
    And I should not see the text "South Africa"
    And I should not see the text "Country"

    When I fill in "Enter your keywords" with "Continent"
    And I press "edit-submit"
    Then I should see the text "Africa"
    And I should see the text "North America"
    And I should see the text "South America"
    And I should see the text "Europe"
    But I should not see the text "Austria"
    And I should not see the text "South Africa"
    And I should not see the text "Country"

#    When I fill in "Enter your keywords" with "East"
#    And I press "edit-submit"
#    Then I should not see the text "Africa"
#    And I should see the text "North America"
#    And I should see the text "South America"
#    And I should not see the text "Europe"
#    But I should not see the text "Austria"
#    And I should not see the text "South Africa"
#    And I should not see the text "Austria"
#    And I should not see the text "Country"
#
#    When I fill in "Enter your keywords" with "West"
#    And I press "edit-submit"
#    Then I should not see the text "Africa"
#    And I should not see the text "North America"
#    And I should see the text "South America"
#    And I should not see the text "Europe"
#    But I should not see the text "Austria"
#    And I should not see the text "South Africa"
#    And I should not see the text "Austria"
#    And I should not see the text "Country"



#  h1.Acceptance Criteria
  # Add a Search block to the header for all authenticated and anonymous users. It contains the following components:
#  # When a user enters a value in the textbox and clicks the _Go_ button, the system searches for all Digital Library content containing the entered string in one of the following fields:
#  ** Content Title
#  ** Content Summary
#  ** Content Body
#  ** Tag(s) associated to the content
#  # The system opens a new _Search Results_ page to display the results found in AC2.
#  # The _Search Results_ page header shall be: _Search Results for: <keyword>_ where <keyword> represents the string user entered into the Search textbox (please see example below):
#  {quote}
#  _Search Results for 'Africa':_
#  {quote}
#  # The system shall display results underneath the page header. Each search result element contains:
#  ** Title
#  ** A statement containing date and author (if available), such as:
#  {quote}
#  Created Feb 14, 2014 10:37 AM by Joe Admin
#  {quote}
#  ** Summary
#  ** Thumbnail

  Scenario: PRC-284 Using header search block twice in a row should search twice in a row with an invalid term first
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    When I fill in "co" for "Search" in the "header" region
    And I press "Search" in the "header" region
    Then the url should match "search/node/co"
    And I should see the error message containing "You must include at least one positive keyword with 3 characters or more."
    Then I fill in "comis" for "Search" in the "header" region
    And I press "Search" in the "header" region
    Then the url should match "search/node/comis"

  Scenario: PRC-284 Using header search block twice in a row should search twice in a row with valid terms both times
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    When I fill in "seven" for "Search" in the "header" region
    And I press "Search" in the "header" region
    Then the url should match "search/node/seven"
    And I should not see the error message containing "You must include at least one positive keyword with 3 characters or more."
    Then I fill in "comis" for "Search" in the "header" region
    And I press "Search" in the "header" region
    Then the url should match "search/node/comis"

  Scenario: PRC-283 Anonymous users can search
    Given I am an anonymous user
    And I am on the homepage
    Then I fill in "comis" for "Search" in the "header" region
    And I press "Search" in the "header" region
    Then the url should match "search/node/comis"

