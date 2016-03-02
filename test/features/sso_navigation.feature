@api @javascript @sso
Feature: prc-1763 Links to Seraph should be hidden for certain roles
  As a PARCC-Member Educator, Content Contributor, Content Administrator (Curator) or PRC Admin I want to be able to navigate to the Seraph viewer from the Instructional Tools menu in the global nav so I can easily access the Seraph viewer from any page on the PRC.

  @prc-1763
  Scenario Outline: prc-1763 Links to Seraph should be hidden for certain roles
    Given I am logged in as a user with the "<user_role>" role
    Then I hover over the element "#main-menu-section .dropdown a[href='/instructional-tools/formative-instructional-tasks']"
    Then I should not see the link "Formative Instructional Tasks (Technology Enhanced)"
  Examples:
    | user_role      |
    | Educator       |
    | District Admin |
    | School Admin   |
    | State Admin    |

  @prc-1763
  Scenario Outline: prc-1763 Links to Seraph should *not* be hidden for certain roles
    Given I am logged in as a user with the "<user_role>" role
    Then I hover over the element "#main-menu-section .dropdown a[href='/instructional-tools/formative-instructional-tasks']"
    Then I hover over the element "#main-menu-section .dropdown a[href='/formative-external']"
  Examples:
    | user_role                       |
    | PARCC-Member Educator           |
    | Content Contributor             |
    | PRC Admin                       |
    | Content Administrator (Curator) |

  @prc-1764
  Scenario Outline: prc-1764 Links to Seraph should be hidden for certain roles
    Given I am logged in as a user with the "<user_role>" role
    And I visit "instructional-tools"
    And I should not see the link "Formative Instructional Tasks (Technology Enhanced)" in the "content" region
  Examples:
    | user_role      |
    | Educator       |
    | District Admin |
    | School Admin   |
    | State Admin    |

  @prc-1764
  Scenario Outline: prc-1764 Links to Seraph should *not* be hidden for certain roles
    Given I am logged in as a user with the "<user_role>" role
    And I visit "instructional-tools"
    And I should see the link "Formative Instructional Tasks (Technology Enhanced)" in the "content" region
  Examples:
    | user_role                       |
    | PARCC-Member Educator           |
    | Content Contributor             |
    | PRC Admin                       |
    | Content Administrator (Curator) |
