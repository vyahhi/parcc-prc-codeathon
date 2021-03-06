@api @user @registration @prc-608 @prc-1018 @prc-1250
Feature: PRC-608 Self-registration- State Attribute
  As an anonymous user,
  I want to enter the state in which I reside/work when self-registering to the PRC system,
  so that it is stored in my user account even if I do not have the state account number (passcode) at registration time.

#  In the self-registration page, add a new State Where You Teach drop-down menu, states listing alphabetically.
#  For all PARCC member states, the entry in the State drop-down menu will be appended with "- PARCC Member"
#  PARCC Members: AR, CO, DC, IL, LA, MD, MA, MS, NJ, NM, NY, OH, RI
  If you select a PARCC Member state, the State Account# field is displayed.
  When a user enters a State Account# , in addition to the existing validations, the system checks whether the state account number matches with the state the user entered. If not matched, the system prompts the user to try again.
  Once validated, the system stores the selected state and state account to the user's new account.
  Additional Considerations
  No change to the rest of attributes in self-registration page.

  Scenario: State where I teach - Members used to have - PARCC Member, prc-1973 asks that we remove it.
    Given I am an anonymous user
    And I click "Create account"
    And I should see the text "Where you teach"
    And I select "Arizona" from "Where you teach"
    And I select "Arkansas" from "Where you teach"
    And I select "Colorado" from "Where you teach"
    And I select "District of Columbia" from "Where you teach"
    And I select "Illinois" from "Where you teach"
    And I select "Louisiana" from "Where you teach"
    And I select "Maryland" from "Where you teach"
    And I select "Massachusetts" from "Where you teach"
    And I select "Mississippi" from "Where you teach"
    And I select "New Jersey" from "Where you teach"
    And I select "New Mexico" from "Where you teach"
    And I select "New York" from "Where you teach"
    And I select "Ohio" from "Where you teach"
    And I select "Rhode Island" from "Where you teach"

  # TODO: chosen.js needs some work on custom steps to be able to test it

  Scenario: PRC-1018 State where I teach - Required
    Given I am an anonymous user
    And I click "Create account"
    When I press "Create new account"
    Then I should see the error message containing "Where you teach field is required."

  Scenario: PRC-1250 State code has to match selected state
    Given I am an anonymous user
    And I click "Create account"
    And I should see the text "Where you teach"
    And I select "Arkansas" from "Where you teach"
    And I fill in "PARCC Member code" with "IL1818"
    And I press "Create new account"
    Then I should see the error message containing "PARCC Member code is incorrect. Leave this blank if you do not have one."