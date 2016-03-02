@api @navigation @menu @prc-1392
Feature: PRC-1392 Global Navigation
  As an administrator, I would like to have the global navigation updated so that the PRC site is easier to navigate.

  Scenario: 1 Default
    Given I am logged in as a user with the "PRC Admin" role
    When I am on the homepage
    Then I should see the link "Library"
    Then I should see the link "Instructional Tools"
    Then I should see the link "Assessment"
    Then I should see the link "Professional Learning"
    Then I should see the link "Admin"

  Scenario: 2 Clicking Library link
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    When I click "Library"
    Then the url should match "library"
    And I should see the heading "Library"

  @javascript
  Scenario: 3 Hovering over the Instruction link
    Given I am logged in as a user with the "PARCC-Member Educator" role
    When I am browsing using a "desktop"
    When I am on the homepage
    And I hover over the element "#main-menu-section a[href='/instructional-tools']"
    Then I hover over the element "#main-menu-section .dropdown a[href='/instructional-tools/formative-instructional-tasks']"
    Then I hover over the element "#main-menu-section .dropdown a[href='/instructional-tools/speaking-listening']"

  #Note: In the future Instruction will also be home to Formative Instructional Tasks and Model Content Frameworks, but does not need to be added for launch

  Scenario: 4 Clicking on Instruction link
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    When I click "Instructional Tools"
    Then the url should match "instructional-tools"
    And I should see the heading "Instructional Tools"
#  Note: Create separate story for Instruction page (2 links). Instruction is a clickable link

  @javascript
  Scenario: 5 Hovering over the Assessment link
    When I am browsing using a "desktop"
    And I am on the homepage
    And I hover over the element "#main-menu-section a[href='/assessments']"
    Then I hover over the element "#main-menu-section .dropdown a[href='/assessments/item-bank']"
    Then I hover over the element "#main-menu-section .dropdown a[href='/assessments/parcc-released-items']"
    Then I hover over the element "#main-menu-section .dropdown a[href='/assessments/technology-readiness']"


  Scenario: 6 Clicking on the Assessment link
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    When I click "Assessment"
    Then the url should match "assessments"
    And I should see the heading "Assessment"

  Scenario: 7 Clicking on Professional Learning
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    When I click "Professional Learning"
    Then the url should match "professional-learning"
    And I should see the heading "Professional Learning"

  @javascript
  Scenario: 8 Hovering Admin global nav link (conditional)
    Given I am logged in as a user with the "PRC Admin" role
    When I am browsing using a "desktop"
    When I am on the homepage
    And I hover over the element "#main-menu-section a[href='/prc/admin']"
    Then I hover over the element "#main-menu-section .dropdown a[href='/prc/admin/admin-content']"
    Then I hover over the element "#main-menu-section .dropdown a[href='/prc/admin/admin-course']"
    Then I hover over the element "#main-menu-section .dropdown a[href='/prc/admin/admin-users']"

  Scenario: 9 Clicking on the Admin link
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    When I click "Admin"
    Then the url should match "prc/admin"
    And I should see the heading "Admin"
    And I should see the link "Content"
    And I should see the link "Course Management"
    And I should see the link "Users"
    And "Content" should precede "Course Management" for the query "a"
    And "Course Management" should precede "Users" for the query "a"

  @javascript @PRC-1684
  Scenario: 10 Mobile navigation as Admin viewing instruction menu
    Given I am logged in as a user with the "PRC Admin" role
    And I am browsing using a "tablet"
    And I am on the homepage
    When I click on the element with css selector ".toggle-topbar.menu-icon a"
    Then I should see the link "Library"
    And I should see the link "Instructional Tools"
    And I should see the link "Assessment"
    And I should see the link "Professional Learning"
    And I should see the link "Admin"
    And I should see "My account"
    And I should see "Log out"


  @javascript @PRC-1684
  Scenario: 11 Mobile navigation as Admin viewing instruction menu
    Given I am logged in as a user with the "PRC Admin" role
    And I am browsing using a "tablet"
    And I am on the homepage
    When I click on the element with css selector ".toggle-topbar.menu-icon a"
    Then I should see the link "Library"
    And I should see the link "Instructional Tools"
    And I should see the link "Assessment"
    And I should see the link "Professional Learning"
    And I should see the link "Admin"
    And I should see "My account"
    And I should see "Log out"
    When I click "Instructional Tools"
    Then I should see the link "Back"
    # @todo: investigate why we are getting a failure here
    And I should see the link "Instructional Tools"
    And I should see the link "Formative Instructional Tasks"
    And I should see the link "Speaking and Listening"
    When I follow "Back"
    Then I should see the link "Library"
    And I should see the link "Instructional Tools"
    And I should see the link "Assessment"
    And I should see the link "Professional Learning"
    And I should see the link "Admin"
    And I should see "My account"
    And I should see "Log out"

  @javascript @PRC-1684
  Scenario: 12 Mobile navigation as Admin viewing Assessment menu
    Given I am logged in as a user with the "PRC Admin" role
    And I am browsing using a "tablet"
    And I am on the homepage
    When I click on the element with css selector ".toggle-topbar.menu-icon a"
    Then I should see the link "Library"
    And I should see the link "Instructional Tools"
    And I should see the link "Assessment"
    And I should see the link "Professional Learning"
    And I should see the link "Admin"
    And I should see "My account"
    And I should see "Log out"
    When I visit "assessments/practice-assessments"
    # @todo: investigate why this consistently fails
    Then I should see the link "Assessment"
    And I should see the link "Item Bank"
    And I should see the link "PARCC Released Items"
    And I should see the link "Technology Readiness"
    When I follow "Back" number "1"
    Then I should see the link "Library"
    And I should see the link "Instructional Tools"
    And I should see the link "Assessment"
    And I should see the link "Professional Learning"
    And I should see the link "Admin"
    And I should see "My account"
    And I should see "Log out"

  @javascript @PRC-1684
  Scenario: 13 Mobile navigation as Admin viewing Admin menu
    Given I am logged in as a user with the "PRC Admin" role
    And I am browsing using a "tablet"
    And I am on the homepage
    When I click on the element with css selector ".toggle-topbar.menu-icon a"
    Then I should see the link "Library"
    And I should see the link "Instructional Tools"
    And I should see the link "Assessment"
    And I should see the link "Professional Learning"
    And I should see the link "Admin"
    And I should see "My account"
    And I should see "Log out"
    When I click "Admin"
    And I should see "Admin" number "1"
    And I should see the link "Content"
    And I should see the link "Course Management"
    And I should see the link "Users"
    When I follow "Back" number "2"
    Then I should see the link "Library"
    And I should see the link "Instructional Tools"
    And I should see the link "Assessment"
    And I should see the link "Professional Learning"
    And I should see the link "Admin"
    And I should see "My account"
    And I should see "Log out"
