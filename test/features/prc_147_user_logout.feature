Feature: Log Out (PRC-147)
  As a logged in user,
  I want to log out of the PRC website,
  so that I can access all content and features as an anonoymous user.

  Scenario: AC1 - When a logged in user selects the "Log Out" link in the top right section of the PRC website.
    Given I am logged in as a user with the "Educator" role
    When I click "Log out"
    Then I should not be logged in

  Scenario: AC2 - The anonymous user view of the PRC Homepage will display once the logged in user has successfully logged out.
    Given I am logged in as a user with the "Educator" role
    When I click "Log out"
    Then I should be at "/"
