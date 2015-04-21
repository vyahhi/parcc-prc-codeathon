@api @d7 @anonymous
Feature: Anonymous User Home Page (PRC-51)
  As an anonymous user,
  I want to access the PRC website,
  So that I can decide whether I want to register or continue accessing public information provided by PRC in the website.

  Scenario: When a user types the PRC URL in their browser, the PRC home page opens # AC1 AC2
    Given I am an anonymous user
    And I have no "Favorites List" nodes
    And I have no "Digital Library Content" nodes
    And I have no "PD Course" nodes
    And I have no "PD Module" nodes
    And I have no "Assessment" nodes
    And I have no "Panel" nodes
    And I have no "Course" nodes
    And "Digital Library Content" nodes:
      | title         | body      | created            | published on       | status | promote | uid | language | tags         | field_permissions |
      | Africa        | Continent | 07/07/2014 12:03am | 08/07/2014 12:03am | 1      | 1       | 1   | und      | North        | public            |
    And I go to "/"
    Then I should see "Welcome!"
    And I should see a "logo" link
    And I should see the heading "Digital Library" in the "content" region
    And I should see the heading "Welcome!" in the "content" region
    And I should see the heading "Slideshow" in the "content" region
    And I should see the heading "User login" in the "content" region
#    And I should see the heading "Africa" in the "content" region
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

  Scenario: Anonymous sees home link
    Given I am an anonymous user
    # TODO: Add a step for this
    And I run drush "genc 0 --types=digital_library_content --kill"
    And I am on the homepage
    Then I should see the link "Home"
    And I should see the link "Digital Library"
    And I should see the link "Assessments"
    And I should see the link "Professional Development"
    And I should not see the link "Content" in the "main_menu"
    And I should not see the link "Users"