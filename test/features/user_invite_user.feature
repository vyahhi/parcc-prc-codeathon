@api @d7 @user @invite
Feature: Invite User (PRC-92)
  As a PRC Administrator,
  I want to invite a new user with a pre-defined role/permission,
  So that the receiver can create a user account in PRC and access the system with designated role/permissions.

  Scenario: AC1 - Role PRC Admin exists +
    Given I am logged in as a user with the "PRC Admin" role

  Scenario: AC2 - In the Users page, a new Invite New User button shall be added. At click, it opens a new Invite New User page. +
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "prc/admin"
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
    And I am on "prc/admin"
    And I should see the link "Users"

  Scenario: AC5 - The following fields are to be captured:
    # Role captured in AC6
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I should see an "E-mail *" field
    And I should see a "Message *" field
    And I should see "Role *"

  Scenario: AC6 - Role: Replaced by PRC-823 - Allow multiple roles
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I should see the checkbox "Educator"
    Then I should see the checkbox "PRC Admin"
    Then I should see the checkbox "Content Contributor"
    Then I should not see the checkbox "administrator"
    Then I should not see the checkbox "authenticated user"

  # AC7 - The Role selected will apply to all E-Mail addresses entered and the invitational message drafted before submission.
  # This is really a UI constraint, and the test for PRC-73 Create User Account Following an Invitation will cover it

  Scenario: AC8 - Validations: The following validations shall occur:
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I press "Send Invitation"
    Then I should see the error message containing "E-mail field is required."
    Then I should not see the error message containing "Message field is required."
    Then I should see the error message containing "Role field is required."

  Scenario: AC8 - Validations: E-mail required
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I fill in "E-mail *" with "example@example.com"
    And I press "Send Invitation"
    Then I should not see the error message containing "E-mail field is required."
    Then I should not see the error message containing "Message field is required."
    Then I should see the error message containing "Role field is required."

  Scenario: AC8 - Validations: Message required
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I fill in "Message *" with ""
    And I press "Send Invitation"
    Then I should see the error message containing "E-mail field is required."
    Then I should see the error message containing "Message field is required."
    Then I should see the error message containing "Role field is required."

  Scenario: AC8 - Validations: Role required
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Educator"
    And I press "Send Invitation"
    Then I should see the error message containing "E-mail field is required."
    Then I should not see the error message containing "Role field is required."

  Scenario: AC9 - A Send Invitation button is provided at the end. At click, the system shall sends an email to the address provided, stating the pre-defined role.
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Content Contributor"
    And I fill in "Message" with "MESSAGE1234"
    And I fill in "E-mail" with "example@example.com"
    And I select "Wyoming" from "State Where You Teach"
    And I press "Send Invitation"
    Then the email to "example@example.com" should contain "has sent you an invite!"
    And the email should contain "has invited you to join Partnership Resource Center at"
    And the email should contain "Content Contributor"
    And the email should contain "MESSAGE1234"

  Scenario: AC9 - Send invitations to multiple users
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then I check the box "Educator"
    And I fill in "Message" with "4321MESSAGE1234"
    And I fill in "E-mail" with "example1@example.com,example2@example.com"
    And I select "Wyoming" from "State Where You Teach"
    And I press "Send Invitation"
    Then the email to "example1@example.com" should contain "has sent you an invite!"
    And the email should contain "has invited you to join Partnership Resource Center at"
    And the email should contain "4321MESSAGE1234"
    Then the email to "example2@example.com" should contain "has sent you an invite!"
    And the email should contain "has invited you to join Partnership Resource Center at"
    And the email should contain "4321MESSAGE1234"
    And the email should contain "Educator"

  Scenario: AC10 - Only a PRC Admin can perform this task. - Educator cannot
    Given I am logged in as a user with the "Educator" role
    Then I should get a "403" HTTP response at "invite/add/invite_by_email"

  Scenario: AC10 - Only a PRC Admin can perform this task. - auth user cannot
    Given I am logged in as a user with the "authenticated user" role
    Then I should get a "403" HTTP response at "invite/add/invite_by_email"

  Scenario: AC10 - Only a PRC Admin can perform this task. - anonymous cannot
    Given I am an anonymous user
    Then I should get a "403" HTTP response at "invite/add/invite_by_email"

  Scenario: AC10 - Only a PRC Admin can perform this task. - Content Contributor cannot
    Given I am logged in as a user with the "Content Contributor" role
    Then I should get a "403" HTTP response at "invite/add/invite_by_email"

  Scenario: Default message text
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then the "Message" field should contain "I'd like to invite you to the PARCC Partnership Resource Center."

  Scenario: PRC-948 Roles field required
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    When I fill in "Message" with "4321MESSAGE1234"
    And I fill in "E-mail" with "example1@example.com,example2@example.com"
    And I press "Send Invitation"
    Then I should see the error message containing "Role field is required."
