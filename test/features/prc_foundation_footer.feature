@api @d7 @styleguide
Feature: Footer Responsive Behavior (PRC-750)
  As a user,
  I want my view of the footer to be responsive,
  so that I can easily view the content on different devices.

  PRC Footer Theming (PRC-390)
  As a user,
  I want my view of the footer to be organized and easy to navigate,
  so that I can easily view the content consistently throughout the site.

  ##### Footer #####

  @javascript
  Scenario: Footer responsive behavior matches style guide
    Given I am an anonymous user
    And I am on "assessments"
    When I am browsing using a "phone"
    Then "footer #footer-copyright" should have a "text-align" css value of "center"
    And "footer #footer-contact" should have a "text-align" css value of "center"
    And "#footer-wrapper div:first-child" should have an "id" attribute value of "footer-copyright"
    And "footer #footer-copyright" should have a "width" css value of "345px"
    And "footer #footer-contact" should have a "width" css value of "345px"
    And "#footer-social" should not be visible
    When I am browsing using a "tablet"
    Then "footer #footer-copyright" should have a "text-align" css value of "left"
    And "footer #footer-copyright" should have a "padding-left" css value of "15px"
    And "footer #footer-copyright" should have a "width" css value of "354px"
    And "footer #footer-contact" should have a "text-align" css value of "right"
    And "footer #footer-contact" should have a "padding-right" css value of "15px"
    And "footer #footer-contact" should have a "width" css value of "354px"
    And "#footer-wrapper div:first-child" should have an "id" attribute value of "footer-copyright"
    And "#footer-social" should not be visible
    When I am browsing using a "desktop"
    Then "footer #footer-copyright" should have a "text-align" css value of "left"
    And "footer #footer-copyright" should have a "padding-left" css value of "30px"
    And "footer #footer-copyright" should have a "width" css value of "367px"
    And "footer #footer-contact" should have a "text-align" css value of "center"
    And "footer #footer-contact" should have a "width" css value of "367px"
    And "footer #footer-social" should have a "text-align" css value of "right"
    And "footer #footer-social" should have a "padding-right" css value of "30px"
    And "footer #footer-social" should have a "width" css value of "367px"
    And "#footer-wrapper div:first-child" should have an "id" attribute value of "footer-copyright"

  @javascript
  Scenario: Footer style matches style guide
    Given I am an anonymous user
    And I am on "assessments"
    When I am browsing using a "phone"
    Then "footer" should have a "padding-top" css value of "50px"
    And "footer" should have a "padding-bottom" css value of "30px"
    And "footer" should have a "background-color" css value of "rgb(112, 84, 125)"
    And "footer p" should have a "color" css value of "rgb(255, 255, 255)"
    And "footer p" should have a "font-size" css value of "13px"
    And "footer p" should have a "font-family" css value of "'Open Sans','Helvetica Neue',Helvetica,Arial,sans-serif"
    And "footer p a" should have a "color" css value of "rgb(255, 255, 255)"
    And "footer p a" should have a "text-decoration" css value of "underline"
    And "footer p a" should have a "font-size" css value of "13px"
    And "footer p a" should have a "font-family" css value of "'Open Sans','Helvetica Neue',Helvetica,Arial,sans-serif"
    And I hover over the element "#footer-copyright p a"
    And "#footer-copyright p a" should have a "color" css value of "rgb(255, 255, 255)"
    And "#footer-contact span.uppercase" should have a "text-transform" css value of "uppercase"
    And "#footer-social a:first-child img" should have an "src" attribute value of "/sites/all/themes/prc_foundation/images/facebook-icon.png"
    And "#footer-social a:last-child img" should have an "src" attribute value of "/sites/all/themes/prc_foundation/images/twitter-icon.png"
