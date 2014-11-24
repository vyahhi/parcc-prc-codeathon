@api
Feature: PRC-401 Content Admin Role (Curator)
  As a Content Admin (Curator),
  I want to receive an invite from the PRC Admin,
  so that I can create an account and access PRC system.

  #  Acceptance Criteria
  #  The Content Administrator (Curator) role exists
  #  In the Invite Users page, a new role shall be added to the role radio buttons list, as: Content Administrator (Curator) between PRC Admin and Content Contributor radio buttons
  #  When the Content Administrator (Curator) radio button is selected, the State dropdown menu is not visible
  #  A potential Content Administrator (Curator) who receives the invite shall access the system by entering his information along with a password to access the the system as Content Administrator (Curator) role
  #  The available links in the top navigation bar, and permissions for a Content Administrator (Curator) are the same as a Content Contributor

  Scenario: AC1 The Content Administrator (Curator) role exists
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    # The available links in the top navigation bar, and permissions for a Content Administrator (Curator) are the same as a Content Contributor
    And I am on the homepage
    Then I should see the link "Home"
    And I should see the link "Digital Library"
    And I should see the link "Assessments"
    And I should see the link "Professional Development"
    And I should see the link "Content"
    And I should not see the link "Users"