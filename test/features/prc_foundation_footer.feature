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
    And I am on "assessments/practice-assessments"
    When I am browsing using a "phone"
    Then "footer #footer-copyright" should have a "text-align" css value of "center"
    And "footer #footer-contact" should have a "text-align" css value of "center"
    And "#footer-wrapper div:first-child" should have an "id" attribute value of "footer-copyright"
    And "footer #footer-copyright" should be "92%" of the width of "#page" within a margin of "1%"
    And "footer #footer-contact" should be "92%" of the width of "#page" within a margin of "1%"
    And "#footer-social" should not be visible
    When I am browsing using a "tablet"
    Then "footer #footer-copyright" should have a "text-align" css value of "left"
    And "footer #footer-copyright" should have a "padding-left" css value of "15px"
    And "footer #footer-copyright" should be "46%" of the width of "#page" within a margin of "2%"
    And "footer #footer-contact" should have a "text-align" css value of "right"
    And "footer #footer-contact" should have a "padding-right" css value of "15px"
    And "footer #footer-contact" should be "46%" of the width of "#page" within a margin of "2%"
    And "#footer-wrapper div:first-child" should have an "id" attribute value of "footer-copyright"
    And "#footer-social" should not be visible
    When I am browsing using a "desktop"
    Then "footer #footer-copyright" should have a "text-align" css value of "left"
    And "footer #footer-copyright" should have a "padding-left" css value of "30px"
    And "footer #footer-copyright" should be "29%" of the width of "#page" within a margin of "2%"
    And "footer #footer-contact" should have a "text-align" css value of "center"
    And "footer #footer-contact" should be "29%" of the width of "#page" within a margin of "2%"
    And "footer #footer-social" should have a "text-align" css value of "right"
    And "footer #footer-social" should have a "padding-right" css value of "30px"
    And "footer #footer-social" should be "29%" of the width of "#page" within a margin of "2%"
    And "#footer-wrapper div:first-child" should have an "id" attribute value of "footer-copyright"

  @javascript
  Scenario: Footer style matches style guide
    Given I am an anonymous user
    And I am on "assessments/practice-assessments"
    When I am browsing using a "phone"
    Then "body" should have a "background-color" css value of "rgb(112, 84, 125)"
    And "#page" should have a "background-color" css value of "rgb(255, 255, 255)"
    And "footer" should have a "padding-top" css value of "50px"
    And "footer" should have a "padding-bottom" css value of "30px"
    # Todo - Once footer image is finalized, test for existance of background image
    # Will require a new function that does a contains match on a URL so we can test for a path and ignore the host.  Will also have to check for different versions of the background image at different breakpoints.
    And "footer" should have a "background-size" css value of "cover"
    And "footer" should have a "background-position" css value of "50% 50%"
    And "footer p" should have a "color" css value of "rgb(255, 255, 255)"
    And "footer p" should have a "font-size" css value of "13px"
    And "footer p" should have a "font-family" css value of "'Open Sans','Helvetica Neue',Helvetica,Arial,sans-serif"
    And "footer p a" should have a "color" css value of "rgb(255, 255, 255)"
    And "footer p a" should have a "text-decoration" css value of "underline"
    And "footer p a" should have a "font-size" css value of "13px"
    And "footer p a" should have a "font-family" css value of "'Open Sans','Helvetica Neue',Helvetica,Arial,sans-serif"
    And I hover over the element "#footer-copyright p a"
    And "#footer-copyright p a" should have a "color" css value of "rgb(255, 255, 255)"
    # TODO -  update css value step to handle relative paths starting with '../'
    # And "#footer-social a:first-child" should have a "background-image" css value of "/sites/all/themes/prc_foundation/images/facebook-icon.png"
    # And "#footer-social a:last-child" should have a "background-image" css value of "/sites/all/themes/prc_foundation/images/twitter-icon.png"
    # prc-1920
    And I should see the text "Comments, questions, help, call us at 1-866-845-2110 or email us at prc-questions@parcconline.org."
    And I should see the link "1-866-845-2110"
    And I should see the link "prc-questions@parcconline.org"
