@api @user @registration @prc-262 @prc-888 @prc-430 @prc-391
Feature: PRC-262 PARCC-Member Educator- Self Registration
  As a PARCC-Member Educator,
  I want to self-register for access to the PRC website,
  so that I can view all password protected content strictly available to PARCC-Member Educators.

  Scenario: AC1. A new role called PARCC-Member Educator exists.
    Given I am logged in as a user with the "PARCC-Member Educator" role

#  @javascript
#  Scenario: AC3. The following additional components will display on the registration form:
#    # Field Display Name         | Data Type   | Required (Y/N) |
#    # My State is a PARCC Member | Checkbox    | N              |
#    # State Account #            | String(255) | N              |
#    Given I am on the homepage
#    And I follow "Join now!"
# TODO: Update
#    Then I should see an "My State is a PARCC Member" field
#    And I should not see the text "State Account #"

  @javascript
  Scenario: AC5. When the "My State is a PARCC Member" checkbox is selected, the State Account # field will be required.
    Given I am on the homepage
    And I am browsing using a "desktop"
    And I click on the element with css selector "#profile-icon"
    And I follow "Create account"
    Then I should not see a "PARCC Member code *" field
# Changed due to change to member/state registration
# TODO: Update
#    Then I check the box "My State is a PARCC Member"
    And I should see a "PARCC Member code" field

  Scenario Outline: AC6 Validations:
#    If the "My State is a PARCC Member" checkbox is selected and a State Account # is correctly entered after the Create New Account button is selected, The system will add the user as a PARCC-Member Educator and display the following feedback on the top of the form:
#    Registration successful. You are now logged in.
#    The selected PARCC Member State will be saved and associated with the PARCC-Member Educator account.
#    Code is not case sensitive
    Given I am on the homepage
    And I follow "Create account"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    And I select "<state>" from "Where you teach"
    And I fill in "<account>" for "PARCC Member code"
    Then I check the box "I have read and agree with the Terms of Use and User Generated Content Disclaimer."
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
    | CO1876  | Colorado             |
    | DC1790  | District of Columbia |
    | IL1818  | Illinois             |
    | LOUS1   | Louisiana            |
    | MD1788  | Maryland             |
    | MA1788  | Massachusetts        |
    | MISS1   | Mississippi          |
    | NJ1787  | New Jersey           |
    | NM1912  | New Mexico           |
    | NEWY1   | New York             |
    | OHIO1   | Ohio                 |
    | RI1790  | Rhode Island         |

  Scenario: AC6 Registration without member state means can't see member state
    Given I am on the homepage
    And I follow "Create account"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    And I select "Wyoming" from "Where you teach"
    Then I check the box "I have read and agree with the Terms of Use and User Generated Content Disclaimer."
    Then I press the "Create new account" button
    Then I should see the message "Registration successful. You are now logged in."
    And I follow "My account"
    Then I should not see the text "Member State:"

  Scenario: Valid State Account Number is required.
    Given I am on the homepage
    And I follow "Create account"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    And I select "Illinois" from "Where you teach"
    And I fill in "Bad Account" for "PARCC Member code"
    Then I press the "Create new account" button
    Then I should see the error message "PARCC Member code is incorrect. Leave this blank if you do not have one."

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
