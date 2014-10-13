Feature: Anonymous User Home Page (PRC-51)
  As an anonymous user,
  I want to access the PRC website,
  So that I can decide whether I want to register or continue accessing public information provided by PRC in the website.

  Scenario: When a user types the PRC URL in their browser, the PRC home page opens # AC1 AC2
    Given I am an anonymous user
      And I go to "/"
    Then I should see "Welcome!"
    And I should see a "logo" link
    And I should see the heading "Welcome!" in the "content" region
    And I should see the heading "Slideshow" in the "content" region
    And I should see the heading "User login" in the "content" region
    And I should see the heading "Sample Article" in the "content" region
    And I should see text matching "Join the discussions. Share tips and experiences. Connect with educators from all around the world."

  Scenario: The login block is present # AC3 AC4
    Given I am an anonymous user
      And I am on the homepage
    Then I should see a "E-mail" field
    And I should see an "Password" field
    And I should see an "Log in" button
    And I should see a "Forgot password?" link
    And I should see a "Join now!" link
    And I should see text matching "Not registered yet?"
