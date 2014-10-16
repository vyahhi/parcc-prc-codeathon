@api @d7
Feature: Invite User (PRC-92)
  As a PRC Administrator,
  I want to invite a new user with a pre-defined role/permission,
  So that the receiver can create a user account in PRC and access the system with designated role/permissions.

  Scenario: AC1 - Role PRC Admin exists +
    Given I am logged in as a user with the "PRC Admin" role

  Scenario: AC2 - In the Users page, a new Invite New User button shall be added. At click, it opens a new Invite New User page. +
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    Then I follow "Users"
    Then I should see the link "Invite New User"
    Then I follow "Invite New User"
    And I should be on "invite/add/invite_by_email"

  Scenario: AC3 - The header for this Admin page shall be: Invite New PRC Website User +
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I should see the heading "Invite New PRC Website User" in the "content" region

  Scenario: AC4 - Keep the top nav bar as a link for the user to come back to users page from here
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I should see the link "Home"
    And I should see the link "Users"

  Scenario: AC5 - The following fields are to be captured:
    # Role captured in AC6
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I should see an "E-mail *" field
    And I should see a "Message *" field

  Scenario: AC6 - Role: Only 1 of the roles listed below can be selected from the radio button at a time:
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I select the radio button "Educator"
    Then I select the radio button "PRC Admin"
    Then I select the radio button "Content Author"
    Then I should not see the radio button "administrator"

  Scenario: AC7 - The Role selected will apply to all E-Mail addresses entered and the invitational message drafted before submission.
  Scenario: AC8 - Validations: The following validations shall occur:
  Scenario: AC9 - A Send Invitation button is provided at the end. At click, the system shall:

  Scenario: AC10 - Only a PRC Admin can perform this task. - Educator cannot
    Given I am logged in as a user with the "Educator" role
    Then I should get a "403" HTTP response at "invite/add/invite_by_email"

  Scenario: AC10 - Only a PRC Admin can perform this task. - auth user cannot
    Given I am logged in as a user with the "authenticated user" role
    Then I should get a "403" HTTP response at "invite/add/invite_by_email"

  Scenario: AC10 - Only a PRC Admin can perform this task. - anonymous cannot
    Given I am an anonymous user
    Then I should get a "403" HTTP response at "invite/add/invite_by_email"

  Scenario: AC10 - Only a PRC Admin can perform this task. - Content Author cannot
    Given I am logged in as a user with the "Content Author" role
    Then I should get a "403" HTTP response at "invite/add/invite_by_email"