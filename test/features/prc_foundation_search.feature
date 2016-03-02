@api @search @styleguide @prc-1703 @prc-1745
Feature: Style search result page
  As a user
  when I perform a search the PRC site
  I want to be taken to a styled faceted search page so that I can see links and information to related content.

  @javascript
  Scenario: PRC-1703 Style Search result page
    Given I am logged in as a user with the "Educator" role
    And "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Grade Level" terms:
      | name      |
      | Grade 490 |
    And "Digital Library Content" nodes:
      | title      | body      | status | promote | uid | language | tags  | field_author_name |
      | Africa DLC | Continent | 1      | 0       | 1   | und      | North | Ted               |
      | Europe DLC | Continent | 1      | 0       | 1   | und      | South | Fred              |
      | DLC 1 | Continent | 1      | 0       | 1   | und      | North | Ted               |
      | DLC 2 | Continent | 1      | 0       | 1   | und      | South | Fred              |
      | DLC 3 | Continent | 1      | 0       | 1   | und      | North | Ted               |
      | DLC 4 | Continent | 1      | 0       | 1   | und      | South | Fred              |
      | DLC 5 | Continent | 1      | 0       | 1   | und      | North | Ted               |
      | DLC 6 | Continent | 1      | 0       | 1   | und      | South | Fred              |
      | DLC 7 | Continent | 1      | 0       | 1   | und      | North | Ted               |
      | DLC 8 | Continent | 1      | 0       | 1   | und      | South | Fred              |
      | DLC 9 | Continent | 1      | 0       | 1   | und      | North | Ted               |
      | DLC 10 | Continent | 1      | 0       | 1   | und      | South | Fred              |
      | DLC 11 | Continent | 1      | 0       | 1   | und      | North | Ted               |
    And "PD Course" nodes:
      | title      | body      | status | promote | uid | language | tags  | field_author_name |
      | Africa PDC | Continent | 1      | 0       | 1   | und      | North | Ted               |
      | Europe PDC | Continent | 1      | 0       | 1   | und      | South | Fred              |
    And "PD Module" nodes:
      | title      | body      | status | promote | uid | language | tags  | field_author_name |
      | Africa PDM | Continent | 1      | 0       | 1   | und      | North | Ted               |
      | Europe PDM | Continent | 1      | 0       | 1   | und      | South | Fred              |
    And "Favorites List" nodes:
      | title     | body      | status | promote | uid         | language | tags  | field_author_name |
      | Africa FL | Continent | 1      | 0       | @currentuid | und      | North | Ted               |
      | Europe FL | Continent | 1      | 0       | @currentuid | und      | South | Fred              |
    And "Assessment" nodes:
      | title       | field_subject | field_grade_level_unlimited | field_quiz_type                    | uid |
      | Africa Quiz | subj1, subj2  | Grade 490                   | PARCC-Released Practice Assessment | 1   |
      | Europe Quiz | subj1, subj2  | Grade 490                   | PARCC-Released Practice Assessment | 1   |
    And I run drush "sapi-i"
    # Cron redirects us. Navigate back. Also cron will pop errors into the log but it still runs and indexes.
    When I am browsing using a "phone"
    And I am on "search-content"
    # Todo - also check for width here
    Then I should see an ".panel-col-first.small-12" element
    And "#filters" should have a "display" css value of "none"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(248, 248, 248)"
    And I should see an ".pagination-centered" element
    When I click on the element with css selector ".filter-panel-toggle-link"
    Then "#filters" should have a "display" css value of "block"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(112, 84, 125)"
    When I click "PD Course"
    Then "#filters" should have a "display" css value of "block"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(112, 84, 125)"
    And ".filter-selected" should have a "background-color" css value of "rgb(52, 71, 89)"
    When I reload the page
    Then "#filters" should have a "display" css value of "block"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(112, 84, 125)"
    And ".filter-selected" should have a "background-color" css value of "rgb(52, 71, 89)"
    When I click on the element with css selector ".filter-panel-all-link"
    Then ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(248, 248, 248)"
    And "#filters" should have a "display" css value of "none"
    When I am browsing using a "desktop"
    And I reload the page
    Then I should see an ".panel-col-first.large-4" element
    And I should see an ".panel-col-last.large-8" element
    And "#filters" should have a "display" css value of "block"
    And ".filter-panel-toggle-link" should have a "background-color" css value of "rgb(112, 84, 125)"
    And ".facetapi-facetapi-links li a" should have a "background-color" css value of "transparent"
    And I should not see the text "North"
    And I should not see the text "South"
    When I hover over the element ".facetapi-facetapi-links li a"
    Then ".facetapi-facetapi-links li a" should have a "background-color" css value of "rgb(255, 255, 255)"