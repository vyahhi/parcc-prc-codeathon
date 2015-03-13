@api @d7 @styleguide
Feature: Header/Menu Responsive Behavior (PRC-749)
  As a user,
  I want my view of the header to be responsive,
  so that I can easily view the content on different devices.

  ##### Header #####

  @javascript
  Scenario: Header responsive behavior matches style guide for anonymous user
    Given I am an anonymous user
    And I am on the homepage
    When I am browsing using a "tablet"
    # Then the PARCC logo should be left aligned.
    Then "nav a#logo" should have a "margin-left" css value of "15px"
    # And the logo should be vertically centered on the header.
    And "nav a#logo" should have a "margin-top" css value of "25px"
    And "nav a#logo" should have a "margin-bottom" css value of "25px"
    # And the mobile navigation icon should display.
    And ".toggle-topbar.menu-icon" should be visible
    # And the mobile navigation icon should be vertically centered on the header.
    And ".top-bar .toggle-topbar.menu-icon" should have a "top" css value of "42.5px"
    And ".top-bar .toggle-topbar.menu-icon" should have a "margin-top" css value of "-16px"
    # And the right padding of the mobile navigation icon should be approximately 15px
    And "nav li.toggle-topbar.menu-icon" should have a "margin-right" css value of "15px"
    And "nav li.toggle-topbar.menu-icon" should have a "right" css value of "5px"
    # When I click on the mobile menu
    When I click on the element with css selector "nav li.toggle-topbar.menu-icon"
    # Then the mobile menu should display
    Then "nav.expanded" should be visible
    # And search should be included in the navigation above the main menu.
    And "form#search-block-form" should be visible
    # And the main menu should be displayed.
    And "#main-menu-section" should be visible
    # And the login link should be displayed.
    And "#secondary-menu-section a[href='/user/login']" should be visible
    # And all mobile menu items should be left aligned.
    And "#main-menu" should have a "float" css value of "left"
    And "nav #block-search-form" should have a "float" css value of "left"
    And "#secondary-menu-section" should have a "left" css value of "0px"
    # And the left padding of all menu items should be 16 px (was 30px.)
    And "nav .top-bar-section ul li > a" should have a "padding-left" css value of "16px"
    When I am browsing using a "desktop"
    # Then the left padding of the logo should be approximately 30px
    Then "nav a#logo" should have a "margin-left" css value of "30px"
    When I click on the element with css selector "#profile-icon"
    # And the user login link should display
    And "#profile-dropdown a[href='/user/login']" should be visible
    When I click on the element with css selector "#search-icon"
    # And the search should display
    And "form#search-block-form" should be visible
    # And the user login and search should be right aligned
    And "#secondary-menu" should have a "float" css value of "right"
    # And the user login and search should have 30px of right padding.
    And "#header-icons" should have a "margin-right" css value of "30px"
    # And the main menu should be evenly distributed between the logo and user login link.
    And ".top-bar-section li a:not(.button)" should have a "line-height" css value of "85px"
    # And the mobile menu icon should not be displayed.
    And ".toggle-topbar.menu-icon" should not be visible

  @javascript
  Scenario: Header responsive behavior matches style guide for authenticated user
    Given I am logged in as a user with the "PRC Admin" role
    And I am on the homepage
    When I am browsing using a "tablet"
    # And I click on the mobile menu icon
    And I click on the element with css selector "nav li.toggle-topbar.menu-icon"
    # Then the My Account link should be visible as the second to last item in the mobile menu
    Then "#secondary-menu-section a[href='/user']" should be visible
    # And the Logout link should be visible as the last item in the mobile menu
    And "#secondary-menu-section a[href='/user/logout']" should be visible
    When I am browsing using a "desktop"
    And I click on the element with css selector "#profile-icon"
    # Then the My Account link should be visible
    Then "#profile-dropdown a[href='/user']" should be visible
    # And the Logout link should be visible
    And "#profile-dropdown a[href='/user/logout']" should be visible
    # And the mobile menu icon should not be visible
    And ".toggle-topbar.menu-icon" should not be visible