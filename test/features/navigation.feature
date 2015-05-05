@api @navigation @menu @prc-1392
Feature: PRC-1392 Global Navigation
  As an administrator, I would like to have the global navigation updated so that the PRC site is easier to navigate.

  Scenario: 1 Default
    Given I am logged in as a user with the "PRC Admin" role
    When I am on the homepage
    Then I should see the link "Library"
    Then I should see the link "Instruction"
    Then I should see the link "Assessment"
    Then I should see the link "Professional Learning"
    Then I should see the link "Admin"

  Scenario: 2 Clicking Library link
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    When I click "Library"
    Then the url should match "library"
    And I should see the heading "Digital Library"

#  Scenario: 3 Hovering over the Instruction link
#    Given that I am on any page on the PRC website
#    And I hover over the Instruction global nav link
#    Then I see a secondary nav
#    And the secondary nav has the following options:
#  Formative Instructional Tasks
#  Speaking and Listening
#  Note: In the future Instruction will also be home to Formative Instructional Tasks and Model Content Frameworks, but does not need to be added for launch

  Scenario: 4 Clicking on Instruction link
    Given I am logged in as a user with the "Educator" role
    And I am on the homepage
    When I click "Instruction"
    Then the url should match "instruction"
    And I should see the heading "Instruction"
#  Note: Create separate story for Instruction page (2 links). Instruction is a clickable link

#  Scenario: 5 Hovering over the Assessment link
#    Given that I am on any page on the PRC website
#    And I hover over the Assessment global nav link
#    Then I see a secondary nav
#    And the secondary nav has the following options:
#  Item Bank
#  Technology Readiness

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

#  Scenario: 8 Hovering Admin global nav link (conditional)
#    Given that I am logged in as an Admin
#    And I am on any page on the PRC website
#    Then I should see an Admin global nav link
#    When I hover over the link
#    Then I should see a secondary nav with the following options:
#  Content
#  Course Management
#  Users

  Scenario: 9 Clicking on the Admin link
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    When I click "Admin"
    Then the url should match "prc/admin"
    And I should see the heading "PRC Admin"
    And I should see the link "Content"
    And I should see the link "Course Management"
    And I should see the link "Users"
    And "Content" should precede "Course Management" for the query "a"
    And "Course Management" should precede "Users" for the query "a"
