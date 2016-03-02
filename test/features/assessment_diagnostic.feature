@api @assessments @diagnostic
Feature: Adding diagnostics page and related changed.

  @prc-1984
  Scenario Outline: 1 - As a PARCC-Member Educator, Content Contributor, Content Administrator (Curator), PARCC Item
  Author or PRC Admin I want to be able to view the Diagnostics page.
    Given I am logged in as a user with the "<role>" role
    When I visit "assessments/diagnostics"
    Then I should see the link "PRC"
    And I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "Diagnostic Tools" in the ".breadcrumb" element
    And I should see the heading "Diagnostic Tools" in the "sub_header" region
    # Default copy provided by client, might change once in production
    And I should see the text "The PARCC Diagnostic Tools are listed in the table below. The purpose"
    And I should see the text "Diagnostic Assessments"
    And I should see the text "Grade Levels"
    And I should see the text "Interactive learning module"
    # @todo: Link to ADS Teach will be made visible sometime in the near future to the roles listed below
    And I should see the text "Launch ADS Teach if you are ready"
  Examples:
    | role                            |
    | PARCC-Member Educator           |
    | Content Contributor             |
    | Content Administrator (Curator) |
    | PARCC Item Author               |
    | PRC Admin                       |

  @prc-1984 @javascript
  Scenario: 2 - Body copy field in Drupal
    Given I am logged in as a user with the "administrator" role
    When I visit "assessments/diagnostics"
    Then I should see the link "Customize this page"

  @prc-1984
  Scenario: 3 - No access to diagnostics page for Unauthenticated or Educator
    Given I am an anonymous user
    When I am on "assessments/diagnostics"
    Then I should see "Access Denied"
    Given I am logged in as a user with the "Educator" role
    When I am on "assessments/diagnostics"
    Then I should see "Access Denied"

  @prc-1976 @javascript
  Scenario:   Access control of diagnostic link, and presence of assessments plural
    Given I am an anonymous user
    And I am on the homepage
    And I hover over the element "#main-menu-section a[href='/assessments']"
    And I should not see the link "Diagnostics"
    And I should see the link "Assessments"
    Given I am logged in as a user with the "Educator" role
    And I hover over the element "#main-menu-section a[href='/assessments']"
    And I should not see the link "Diagnostics"

  @prc-1976 @javascript
  Scenario Outline: As a user I want to see the Assessment sub-sections available to me and easily navigate to those
  sub-sections using the Assessment menu in the global nav.
    Given I am logged in as a user with the "<role>" role
    And I am on the homepage
    And I hover over the element "#main-menu-section a[href='/assessments']"
    And I should see the link "Diagnostics"
  Examples:
  | role                            |
  | PARCC-Member Educator           |
  | Content Contributor             |
  | Content Administrator (Curator) |
  | PARCC Item Author               |
  | PRC Admin                       |

  @prc-1962
  Scenario Outline: 1 - As a user I want to be able to go to the Assessment landing page to see the Assessment sub-sections
  available to me and easily navigate to those sub-sections.
    Given I am logged in as a user with the "<role>" role
    When I visit "assessments"
    Then "Assessments" should precede "Diagnostic Tools" for the query ".pane-menu-menu-assessment ul, .pane-menu-menu-assessment p"
    And "Diagnostic Tools" should precede "Item Bank" for the query ".pane-menu-menu-assessment ul, .pane-menu-menu-assessment p"
    And "Diagnostic Tools" should precede "PARCC Released Items" for the query ".pane-menu-menu-assessment ul, .pane-menu-menu-assessment p"
    And "PARCC Released Items" should precede "Technology Readiness" for the query ".pane-menu-menu-assessment ul, .pane-menu-menu-assessment p"
    And I should see the text "From here, you can view available assessments"
    And I should see the text "The PARCC Diagnostic Tools are designed"
    And I should see the text "View PARCC released and practice items."
    And I should see the text "The states that make up the PARCC consortium are taking the exceptional"
    And I should see the text "This tool will help you gauge the overall readiness"
  Examples:
    | role                            |
    | PARCC-Member Educator           |
    | Content Contributor             |
    | Content Administrator (Curator) |
    | PARCC Item Author               |
    | PRC Admin                       |

  @prc-1962
  Scenario: 2 - Block access to diagnostic link, and page
    Given I am an anonymous user
    When I visit "assessments"
    Then I should not see the link "Diagnostics"
    And I am on "assessments/diagnostics"
    And I should see "Access Denied"
    Given I am logged in as a user with the "Educator" role
    When I visit "assessments"
    Then I should not see the link "Diagnostics"
    And I am on "assessments/diagnostics"
    And I should see "Access Denied"



