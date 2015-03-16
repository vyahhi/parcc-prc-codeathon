@api @user
Feature: PRC-262 PARCC-Member Educator- Self Registration
  As a PARCC-Member Educator,
  I want to self-register for access to the PRC website,
  so that I can view all password protected content strictly available to PARCC-Member Educators.

  Scenario: AC1. A new role called PARCC-Member Educator exists.
    Given I am logged in as a user with the "PARCC-Member Educator" role

  @javascript
  Scenario: AC3. The following additional components will display on the registration form:
    # Field Display Name         | Data Type   | Required (Y/N) |
    # My State is a PARCC Member | Checkbox    | N              |
    # State Account #            | String(255) | N              |
    Given I am on the homepage
    And I follow "Join now!"
    And I should not see the text "State Account #"

  @javascript
  Scenario: AC5. When the "My State is a PARCC Member" checkbox is selected, the State Account # field will be required.
    Given I am on the homepage
    And I follow "Join now!"
    Then I should not see the text "State Account #"
    # @todo: Figure out how to test the selects modified by chosen
    # And I select "Arkansas (PARCC Member)" from "User State"
    # And I should see a "State Account #" field

  Scenario: AC6. Validations:
    # prc-608 changes the following requirements:
    If the "My State is a PARCC Member" checkbox is selected and a State Account # is NOT entered after the Create New Account button is selected,
    The system will display the following feedback on the top of the form:
    <Field Name> field is required.
    Given I am on the homepage
    And I follow "Join now!"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    And I select "Arkansas (PARCC Member)" from "field_user_state[und]"
    Then I press the "Create new account" button
    # State account should no longer be required based on prc-608
    # Then I should see the error message "State Account # field is required."

  Scenario Outline: AC6 Validations:
    If the "My State is a PARCC Member" checkbox is selected and a State Account # is correctly entered after the Create New Account button is selected, The system will add the user as a PARCC-Member Educator and display the following feedback on the top of the form:
    Registration successful. You are now logged in.
    The selected PARCC Member State will be saved and associated with the PARCC-Member Educator account.
    Code is not case sensitive
    Given I am on the homepage
    And I follow "Join now!"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    And I fill in "<account>" for "State Account #"
    Then I press the "Create new account" button
    Then I should see the message containing "Registration successful. You are now logged in."
    And I follow "My account"
    Then I should see the text "Member State:"
    And I should see the link "<state>"
    # PRC-430 PARCC-Member Educator- Self Registration- Assigns wrong role when state account # is added
    And the user "@timestamp@example.com" should have a role of "PARCC-Member Educator"
    Then I delete the user with the email address "@timestamp@example.com"

    Examples:
    | account | state                |
    | ARKA1   | Arkansas             |
    | COLO1   | Colorado             |
    | DISTR1  | District of Columbia |
    | ILLI1   | Illinois             |
    | LOUS1   | Louisiana            |
    | MARY1   | Maryland             |
    | MASS1   | Massachusetts        |
    | MISS1   | Mississippi          |
    | NEWJ1   | New Jersey           |
    | NEWM1   | New Mexico           |
    | NEWY1   | New York             |
    | OHIO1   | Ohio                 |
    | RHOD1   | Rhode Island         |
    | arka1   | Arkansas             |
    | colo1   | Colorado             |
    | distr1  | District of Columbia |

  Scenario: AC6 Registration without member state means can't see member state
    Given I am on the homepage
    And I follow "Join now!"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    Then I press the "Create new account" button
    Then I should see the message "Registration successful. You are now logged in."
    And I follow "My account"
    Then I should not see the text "Member State:"

    #prc-608 Allows for creating account without the state #
  Scenario: Valid State Account Number is required.
    Given I am on the homepage
    And I follow "Join now!"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    And I fill in "Bad Account" for "State Account #"
    Then I press the "Create new account" button
    Then I should see the error message "Valid State Account # is incorrect. Leave this blank if you do not have one."

  Scenario: User cannot edit his own Member State
    Given I am logged in as a user with the "PARCC-Member Educator" role
    And I am on the homepage
    When I follow "My account"
    And I follow "Edit"
    Then I should not see the text "Member State"

  Scenario: Admin can edit his own Member State
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    When I follow "My account"
    And I follow "Edit"
    Then I should see the text "Member State"
