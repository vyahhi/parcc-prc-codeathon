@api @d7
Feature: Admin UI: Define Content Metadata (PRC-30)
  As a Content Author,
  I want to define the metadata associated to a content I'm posting to PRC digital library,
  so that the educators can find the content they wish to view using the content metadata.

  Scenario Outline: AC1 Test presence of metadata section with terms
    Given I am logged in as a user with the "Content Author" role
    And I am on the homepage
    When I follow "Content"
    Then I click "Add content"
    Then I should see the text "Add more information (Content Properties)" in the "content" region
    And I should see the text "<metadata>"

  Examples:
    | metadata            |
    |  Grade Level        |
    |  Subject            |
    |  Media Type         |
    |  Genre              |

  Scenario Outline: AC2 Test grade level options
    Given I am logged in as a user with the "Content Author" role
    And I am on the homepage
    When I follow "Content"
    And I click "Add content"
    Then I should see "<grade>" in the "content" region

  Examples:
    | grade                    |
    |  PreK                    |
    |  Kindergarten            |
    |  First Grade             |
    |  Elementary School       |
    |  Middle School           |
    |  High School             |

  Scenario Outline: AC3 Test subject options
    Given I am logged in as a user with the "Content Author" role
    And I am on the homepage
    When I follow "Content"
    And I click "Add content"
    Then I should see "<subject>" in the "content" region

  Examples:
    | subject                    |
    | English Language Arts |
    | Math |
    | Science |
    | History/Social Studies |
    | World Languages |
    | Visual and Performing Arts |
    | Career and Technical Education |
    | STEM |
    | Physical Education |
    | English Language Development |
    | Special Needs Support |
    | Educational Leadership |



  Scenario Outline: AC5 Test media type options
    Given I am logged in as a user with the "Content Author" role
    And I am on the homepage
    When I follow "Content"
    And I click "Add content"
    Then I should see "<media>" in the "content" region

  Examples:
    | media                    |
    |  Text                    |
    |  Image            |
    |  Audio           |
    |  Video        |

  Scenario Outline: AC6 Test grade level options
    Given I am logged in as a user with the "Content Author" role
    And I am on the homepage
    When I follow "Content"
    And I click "Add content"
    Then I should see "<genre>" in the "content" region

  Examples:
    | genre                    |
    |  Learning Fun                    |
    |  Bonding Activities            |
