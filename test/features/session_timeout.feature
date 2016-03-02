@api @timeout
Feature: Session idle timeout

  # I'd rather have these features run as part of the SSO suite, but for some reason they cause sso_users_exist and sso_users_delete to require a second run.
  # Technically, the session timeout doesn't depend on SSO and will behave the same for both SSO and non-sso sessions.

  Scenario: Time user out after 60 seconds of inactivity
    Given I am logged in as a user with the "Educator" role
    And I am on "library"
    When I wait 60 seconds
    Then I should see the text "Your session is about to expire. Do you want to extend it?"
    When I wait 7 seconds
    Then I am on the homepage
    And I should see the message containing "You have been logged out due to inactivity."

  @javascript
  Scenario: Prompt user and allow them to extend session.
    Given I am logged in as a user with the "Educator" role
    And I am on "library"
    When I wait 60 seconds
    Then I should see the text "Your session is about to expire. Do you want to extend it?"
    When I press the "Yes" button
    And I wait 60 seconds
    Then I should see the text "Your session is about to expire. Do you want to extend it?"
    When I press the "No" button
    And I wait 2 seconds
    Then I should be on the homepage
    And I should see the message containing "You have been logged out due to inactivity."