@api @user @registration @prc-888
Feature: PRC-888 Acceptance of privacy policies upon registration
  As an anonymous user,
  I want to be able to accept the privacy policies (terms of use and the user generated content disclaimer)
  so I can complete my registration.

#  Given that I am an anonymous user
#  And I am on the self-registration page
#  And that all the input the other registration fields is valid
#  And I see the copy:
#  I have read and agree with the Terms of Use and User Generated Content Disclaimer
#  And the phrase "Terms of Use" links to the Terms of Use page (PRC-615)
#  And the phrase "User Generated Content Disclaimer" links to the User Generated Content Disclaimer page (PRC-889)
#  Scenario 1: Checked acceptance
#    When I checked the privacy policy acceptance checkbox
#    And I press the Create New Account button
#    Then I'm registered as a new user.
#  Scenario 2: Not checked acceptance
#    When I have not checked the privacy policy acceptance checkbox
#    And I press the Create New Account button
#    Then the following error is displayed:
#  Accepting the Terms of Use and User Generated Content Disclaimer is required.
#  Additional Considerations
#  The acceptance checkbox to marked with an asterisk as required.

  Scenario: Checked acceptance
    Given I am an anonymous user
    And I am on the homepage
    And I follow "Create account"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    Then I check the box "I have read and agree with the Terms of Use and User Generated Content Disclaimer."
    Then I press the "Create new account" button
    Then I should not see the error message containing "Accepting the Terms of Use and User Generated Content Disclaimer is required."

  Scenario: Not checked acceptance
    Given I am an anonymous user
    And I am on the homepage
    And I follow "Create account"
    Then the "I have read and agree with the Terms of Use and User Generated Content Disclaimer." checkbox should not be checked
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    Then I press the "Create new account" button
    Then I should see the error message containing "Accepting the Terms of Use and User Generated Content Disclaimer is required."

  Scenario Outline: Links
    Given I am an anonymous user
    And I am on the homepage
    And I follow "Create account"
    Then the "I have read and agree with the Terms of Use and User Generated Content Disclaimer." checkbox should not be checked
    When I click "<link>" in the "content" region
    Then I should see the heading "<link>"
  Examples:
    | link                              |
    | Terms of Use                      |
    | User Generated Content Disclaimer |

  Scenario: Links - User Generated Content Disclaimer