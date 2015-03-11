@api @trt @structured @school
Feature: PRC-848 Manage Schools - Add School - Form
  As a District Admin, I want to add schools to my district so that I can request school admins to run readiness checks and view the results of those checks.
#  Acceptance Criteria
#  Given that I am logged in as a District Admin
#  And I am on my Manage Schools page
#  When I click the Add School - form link
#  Then I see the School Add page that has:
#  Page headline
#  Add School
#  Overview copy
#  Overview / instructional copy goes here, if any.
#  Required field notation
#  "* indicates required field"
#  Form Fields
#  Field Label	Instructions	Type	Required?
#  School name *	–	Text field	Yes
#  School contact's email address *	Enter the email address of the person responsible for running the school's technology readiness checks.	Text field	Yes
#  Submit button

  Scenario: Check form
    Given I am logged in as a user with the "District Admin" role
    And I have no "School" nodes
    And I have no "District" nodes
    And "District" nodes:
      | title              | uid         |
      | PRC-848 @timestamp | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    And I click "Add School - form"
    And I should see the heading "Add School"
    And I should see the text "Overview / instructional copy goes here, if any."
    And I should see the text "\* indicates required field"
    And I should see the text "School name \*"
    And I should see the text "School contact's email address \*"
    And I should see the text "Enter the email address of the person responsible for running the school's technology readiness checks."
    And I should see a "Submit" button

  Scenario: PRC-864 Validate form
    Given I am logged in as a user with the "District Admin" role
    And I have no "School" nodes
    And I have no "District" nodes
    And "District" nodes:
      | title              | uid         |
      | PRC-848 @timestamp | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    And I click "Add School - form"
    When I press "Submit"
    Then I should see the error message containing "School name field is required."
    And I should see the error message containing "School contact's email address field is required."
    When I fill in "School contact's email address" with "badmail"
    And I press "Submit"
    Then I should see the error message containing "is not a valid e-mail address."
    When I fill in "School contact's email address" with "@badmail"
    And I press "Submit"
    Then I should see the error message containing "is not a valid e-mail address."
    When I fill in "School contact's email address" with "badmailexample.com"
    And I press "Submit"
    Then I should see the error message containing "is not a valid e-mail address."
    When I fill in "School contact's email address" with "badmail@!example.com"
    And I press "Submit"
    Then I should see the error message containing "is not a valid e-mail address."