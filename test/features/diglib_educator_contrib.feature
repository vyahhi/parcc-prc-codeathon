@api @diglib
Feature: Educator-contributed digital library content
  As an educator,
  I want to contribute content to the PRC
  so that I share my resources with the PRC community.

  Scenario: Educator can add digital library content
    Given I am logged in as a user with the "Educator" role
#    When I hover over "Library"
    When I am on "library"
    Then I should see the link "Contribute"

  Scenario: User submitted lesson plans under instruction

  Scenario: What are you contributing?
    Given I am logged in as a user with the "Educator" role
#    When I hover over "Library"
    When I am on "library"
    Then I click "Contribute"
    Then I select the radio button "Story"
    And I select the radio button "Lesson Plan"

  Scenario: Educator content should always be public
    Given I am logged in as a user with the "Educator" role
#    When I hover over "Library"
    When I am on "library"
    Then I click "Contribute"
    Then I should not see the text "Permissions"
    And I should not see the text "Public"
    And I should not see the text "PARCC members ONLY"
    And I select the radio button "Story"
    And I fill in "edit-title" with "My Title @timestamp"
    And I press "Save"
    Then I should see the message containing "Digital Library Content My Title @timestamp has been created."
    Then the node titled "My Title @timestamp" should have the fields:
      | title               | field_permissions |
      | My Title @timestamp | public            |

  Scenario: Educator users do not have "Author" field
    Given users:
      | name                               | mail                               | pass   | field_first_name | field_last_name | status | roles    |
      | joe_prc_346a@timestamp@example.com | joe_prc_346a@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator |
    And I am logged in as "joe_prc_346a@timestamp@example.com"
    Then I should have the "Educator" role
#    When I hover over "Library"
    When I am on "library"
    Then I click "Contribute"
    Then I should not see the text "Permissions"
    And I should not see the text "Public"
    And I should not see the text "PARCC members ONLY"
    And I select the radio button "Story"
    And I fill in "edit-title" with "My Title @timestamp"
    And I press "Save"

    Then I should see the message containing "Digital Library Content My Title @timestamp has been created."
    Then the node titled "My Title @timestamp" should have the fields:
      | title               | field_permissions | field_author_name |
      | My Title @timestamp | public            | Joe Educator      |

  Scenario: Stories but not lesson plans show up in library page
    Given "Digital Library Content" nodes:
      | title               | field_permissions | field_author_name | status | field_contribution_type |
      | My Story @timestamp | public            | Joe Educator      | 1      | story                   |
      | My Plan @timestamp  | public            | Joe Educator      | 1      | lessonplan              |
    And I am an anonymous user
    And I index search results
    When I am on "library"
    Then I should see the link "My Story @timestamp"
    But I should not see the link "My Plan @timestamp"