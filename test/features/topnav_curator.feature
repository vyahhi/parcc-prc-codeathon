@api
Feature: PRC-401 Content Admin Role (Curator)
  As a Content Admin (Curator),
  I want to receive an invite from the PRC Admin,
  so that I can create an account and access PRC system.

  #  Acceptance Criteria
  #  A potential Content Administrator (Curator) who receives the invite shall access the system by entering his information along with a password to access the the system as Content Administrator (Curator) role
  #  The available links in the top navigation bar, and permissions for a Content Administrator (Curator) are the same as a Content Contributor

  Scenario: AC1 The Content Administrator (Curator) role exists
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    # The available links in the top navigation bar, and permissions for a Content Administrator (Curator) are the same as a Content Contributor
    And I am on the homepage
    Then I should see the link "Home"
    And I should see the link "Digital Library"
    And I should see the link "Assessments"
    And I should see the link "Professional Learning"
    And I should see the link "Technology Readiness"
    When I am on "prc/admin"
    Then I should see the link "Content"
    And I should see the link "Course Management"
    And I should not see the link "Users"

  Scenario: AC2 In the Invite Users page, a new role shall be added to the role radio buttons list, as: Content Administrator (Curator) between PRC Admin and Content Contributor radio buttons
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    Then "Educator" should precede "PARCC-Member Educator" for the query ".form-item-invite-role label"
    Then "PARCC-Member Educator" should precede "Content Contributor" for the query ".form-item-invite-role label"
    Then "Content Contributor" should precede "Content Administrator (Curator)" for the query ".form-item-invite-role label"
    Then "Content Administrator (Curator)" should precede "PRC Admin" for the query ".form-item-invite-role label"

  @javascript
  Scenario: AC3 When the Content Administrator (Curator) radio button is selected, the State dropdown menu is not visible
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "invite/add/invite_by_email"
    When I check the box "Content Administrator (Curator)"
    Then "#edit-field-member-state-und" should not be visible

