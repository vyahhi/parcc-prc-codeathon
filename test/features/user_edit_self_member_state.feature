@api @user @profile @edit @self @member-state @prc-1335
Feature: PRC-1335 User Account - Allow user to enter/edit PARCC member state code
  As a logged in user,
  I want to be able to enter my PARCC member state code, if I did not do so during registration,
  so that I can access PARCC member content.

  Background: I have not provided my PARCC member state code
    Given I am logged in as a user with the "Educator" role
    And I am on "user"
    When I click "Edit"

  Scenario: 1 Default
    Then I should see the text "PARCC Member code"

  Scenario: 2 Entering a valid PARCC Member State Code
    Then I should not have the "PARCC-Member Educator" role
    # We are using taxonomy data that already exists, created in the import during site setup
    And I fill in "First Name" with "Samantha"
    And I fill in "Last Name" with "Franks"
    When I select "Illinois" from "State Where I Teach"
    And I fill in "PARCC Member code" with "IL1818"
    And I press "Save"
    Then I should see the message containing "You have successfully entered a valid PARCC member state code."
    And I should have the "PARCC-Member Educator" role
    # User with a Member State does not see PARCC Member code
    When I am on "user"
    And I click "Edit"
    Then I should not see "PARCC Member code"


  Scenario: 3 Entering an invalid PARCC Member State Code
    Then I should not have the "PARCC-Member Educator" role
    # We are using taxonomy data that already exists, created in the import during site setup
    And I fill in "First Name" with "Samantha"
    And I fill in "Last Name" with "Franks"
    When I select "Illinois" from "State Where I Teach"
    And I fill in "PARCC Member code" with "XX"
    And I press "Save"
    Then I should see the error message containing "PARCC Member code is incorrect. Leave this blank if you do not have one."
    And I should not see the message containing "You have successfully entered a valid PARCC member state code."
    And I should not have the "PARCC-Member Educator" role
    And the "PARCC Member code" field should contain "XX"