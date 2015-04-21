@api @diglib @search
Feature: Search Content - Quick Search (PRC-31)
  As an educator,
  I want to search for content by entering a keyword,
  so that I can quickly find the content I'm looking for.

  Scenario: PRC-515 Search Content - Quick Search - Search only Digital Library and PD Course
    Given I am logged in as a user with the "Educator" role
    And "Subject" terms:
      | name  |
      | subj1 |
      | subj2 |
    And "Grade Level" terms:
      | name      |
      | Grade 490 |
    And "Digital Library Content" nodes:
      | title         | body      | status | promote | uid | language | tags         | field_author_name |
      | Africa DLC    | Continent | 1      | 0       | 1   | und      | North        | Ted               |
      | Europe DLC    | Continent | 1      | 0       | 1   | und      | South        | Fred              |
    And "PD Course" nodes:
      | title         | body      | status | promote | uid | language | tags         | field_author_name |
      | Africa PDC    | Continent | 1      | 0       | 1   | und      | North        | Ted               |
      | Europe PDC    | Continent | 1      | 0       | 1   | und      | South        | Fred              |
    And "PD Module" nodes:
      | title         | body      | status | promote | uid | language | tags         | field_author_name |
      | Africa PDM    | Continent | 1      | 0       | 1   | und      | North        | Ted               |
      | Europe PDM    | Continent | 1      | 0       | 1   | und      | South        | Fred              |
    And "Favorites List" nodes:
      | title         | body      | status | promote | uid         | language | tags         | field_author_name |
      | Africa FL     | Continent | 1      | 0       | @currentuid | und      | North        | Ted               |
      | Europe FL     | Continent | 1      | 0       | @currentuid | und      | South        | Fred              |
    And "Assessment" nodes:
      | title       | field_subject | field_grade_level | field_quiz_type            | uid |
      | Africa Quiz | subj1, subj2  | Grade 490         | PARCC-Released Practice Assessment | 1   |
      | Europe Quiz | subj1, subj2  | Grade 490         | PARCC-Released Practice Assessment | 1   |
    And I run drush "sapi-i"
    # Cron redirects us. Navigate back. Also cron will pop errors into the log but it still runs and indexes.
    And I am on "search-content"
    When I fill in "Enter your keywords" with "Africa"
    And I press "Apply"
    Then I should not see the text "Your search yielded no results"
# TODO: And I should see the text "Search results for: Africa"
    But I should see the text "Africa DLC"
    And I should see the text "Africa PDC"
    But I should not see the text "Africa PDM"
    And I should not see the text "Africa FL"
    And I should see the text "Africa Quiz"
    And I should not see the text "Europe"
    # PRC-514 Search Content- Quick search- Error message shown when searching specific terms
    And I should not see the error message containing "Notice"
    And I should not see the error message containing "Warning"
