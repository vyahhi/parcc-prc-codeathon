@instruction @api @styleguide @javascript
Feature: Instruction pages theming

  Scenario: prc-1686 - Themeing refinements to instruction section
#  On both the Formative Instructional Tasks and Speaking and Listening pages in the Instruction section, the following
#  refinements need to be made:
#    * There should be additional space between the header text and selected sort arrow in selected columns
#    * There should be additional padding between the table and the footer - at least greater than or equal to the
#      amount of padding between paragraph text and the table.
#
#  Do these issues exist outside of the Instruction section?  If so, we should address them there as well.
#
#  h2. Acceptance Criteria
#  *Additions to current functionality*
#  h3. Scenario: 1 Theming Formative Instructional Tasks - Default
#    Given that I am logged in
    Given formative instructional task content:
      | resource name       | resource type | file                          | faux standard | faux subject | grade level | permissions |
      | Resource @timestamp | Task          | testfiles/GreatLakesWater.pdf | Standard      | Subject      | 1st Grade   | public      |
    And I am logged in as a user with the "Educator" role
#    And I am on the Formative Instructional Tasks page
    And I visit "instructional-tools/formative-instructional-tasks"
    And I should not see the link "Add Resource"
#    Then I should see additional space between the column header and sort arrow for selected columns
    Then "th a img" should have a "margin-left" css value of "9.75px"
    Then "th a img" should have a "margin-right" css value of "9.75px"
#    And additional padding between the the table and the footer
    And ".view-id-formative_instructional_tasks" should have a "padding-bottom" css value of "48px"

#  h3. Scenario: 2 Theming Formative Instructional Tasks - Authorized Contributor
#    Given that I am logged in as a user role that can contribute content to the Instruction section

    Given I am logged in as a user with the "PRC Admin" role
#    And I am on the Formative Instructional Tasks page
    And I visit "instructional-tools/formative-instructional-tasks"
#    Then I should see that the form Add Resource link is now a button
#    And the button has all the necessary button styling
    And ".pane-menu-menu-formative-instructional-tas .pane-content ul li.leaf" should have a "margin-left" css value of "0px"
    And ".pane-menu-menu-formative-instructional-tas .pane-content ul li.leaf a" should have a "background-color" css value of "rgb(255, 255, 255)"
    And ".pane-menu-menu-formative-instructional-tas .pane-content ul li.leaf a" should have a "font-size" css value of "16px"
    And ".pane-menu-menu-formative-instructional-tas .pane-content ul li.leaf a" should have a "font-weight" css value of "700"
#    And the button functions in the same manner as the Add Resource link did
    And I click "Add Resource"

#  h3. Scenario: 3 Theming Speaking and Listening - Default
#    Given that I am logged in
    Given speaking-listening content:
      | resource name       | resource type                 | file                          | faux standard | faux subject | grade level |
      | Resource @timestamp | Listening logs - for students | testfiles/GreatLakesWater.pdf | Standard      | Subject      | 1st Grade   |
    And I am logged in as a user with the "Educator" role
#    And I am on the Speaking and Listening
    And I visit "instructional-tools/speaking-listening"
#    Then I should see additional space between the column header and sort arrow for selected columns
    Then "th a img" should have a "margin-left" css value of "9.75px"
    Then "th a img" should have a "margin-right" css value of "9.75px"
#    And additional padding between the the table and the footer
    And ".view-id-speaking_and_listening" should have a "padding-bottom" css value of "48px"
#
#  h3. Scenario: 4 Theming Speaking and Listening - Authorized Contributor
#    Given that I am logged in as a user role that can contribute content to the Instruction Section
    Given I am logged in as a user with the "PRC Admin" role
#    And I am on the Speaking and Listening page
    And I visit "instructional-tools/speaking-listening"
#    Then I should see that the form Add Resource link is now a button
#    And the button has all the necessary button styling
#    And the button functions in the same manner as the Add Resource link did
    And ".pane-menu-menu-speaking-and-listening-page .pane-content ul li.leaf" should have a "margin-left" css value of "0px"
    And ".pane-menu-menu-speaking-and-listening-page .pane-content ul li.leaf a" should have a "background-color" css value of "rgb(255, 255, 255)"
    And ".pane-menu-menu-speaking-and-listening-page .pane-content ul li.leaf a" should have a "font-size" css value of "16px"
    And ".pane-menu-menu-speaking-and-listening-page .pane-content ul li.leaf a" should have a "font-weight" css value of "700"
