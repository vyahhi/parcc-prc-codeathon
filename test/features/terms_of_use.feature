@api @footer @terms_of_use @prc-615 @prc-1254
Feature: PRC-615 Accessing Terms of Use
  As a user,
  I want to have access to PARCC Terms of Use when accessing PRC.

  Scenario: View ToU
    Given I am an anonymous user
    When I click "Terms of Use" in the "footer_copyright" region
    Then I should see the heading "Terms of Use"
    And I should see the text "Effective Date"
    And I should see the text "January 01, 2015"
    And I should see the text "Placeholder content: This page sets out the terms on which you may access and make use of our website"
    # Leaving out the check for [DOMAIN ADDRESS] (the "Site") because I don't want to muck with regex and this will be the first thing to change.
    And I should see the text "whether as a guest or a registered user. Please read these terms of use carefully before you start to use the site. By using the Site, you indicate that you accept these terms of use and that you agree to abide by them. If you do not agree to these terms of use, please refrain from using the Site."

  Scenario: PRC-1254 - No submitted by author or date
    Given I am an anonymous user
    When I click "Terms of Use" in the "footer_copyright" region
    Then I should not see the text "Submitted by"