@api @d7 @styleguide
Feature: Header/Menu Responsive Behavior (PRC-749)
  As a user,
  I want my view of the header to be responsive,
  so that I can easily view the content on different devices.

  PRC Header Theming (PRC-389)
  As a user,
  I want my view of the header to be organized and easy to navigate,
  so that I can easily view the content consistently throughout the site.

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
    And ".show-for-medium-down input#edit-search-block-form--2" should be visible
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

  # PRC Header Theming (PRC-389)

  @javascript
  Scenario: Header matches style guide for anonymous user
    Given I am an anonymous user
    And I am on the homepage
    When I am browsing using a "tablet"
    # Then the top bar background color is #344758
    Then "#header .contain-to-grid" should have a "background-color" css value of "rgb(52, 71, 88)"
    When I am browsing using a "small desktop"
    Then ".top-bar-section li a" should have a "font-family" css value of "'Open Sans','Helvetica Neue',Helvetica,Arial,sans-serif"
    And ".top-bar-section li a" should have a "padding-left" css value of "15px"
    And ".top-bar-section li a" should have a "padding-right" css value of "15px"
    And ".top-bar-section li a" should have a "font-size" css value of "13px"
    And ".top-bar-section li a" should have a "color" css value of "rgb(149, 176, 205)"
    And "#search-icon" should be visible
    And "#profile-icon" should be visible
    When I am browsing using a "desktop"
    Then ".top-bar-section li a" should have a "font-size" css value of "14px"
    And ".top-bar-section li a" should have a "padding-left" css value of "24.5px"
    And ".top-bar-section li a" should have a "padding-right" css value of "24.5px"

  @javascript
  Scenario: Menu interactivity matches style guide for anonymous user
    Given I am an anonymous user
    And I am on the homepage
    When I am browsing using a "tablet"
    And I click on the element with css selector "nav li.toggle-topbar.menu-icon"
    Then "#main-menu" should have a "background-color" css value of "rgb(51, 51, 51)"
    And I hover over the element "#main-menu-section a[href='/library']"
    Then "#main-menu-section li.first a" should have a "color" css value of "rgb(255, 255, 255)"
    And "#main-menu-section li.first a" should have a "background-color" css value of "rgb(43, 43, 43)"
    When I am browsing using a "desktop"
    And I hover over the element "#main-menu-section a[href='/library']"
    Then "#main-menu-section li.first a" should have a "color" css value of "rgb(255, 255, 255)"
    And "#main-menu-section li.first a" should have a "background-color" css value of "rgb(46, 63, 78)"
    When I click on the element with css selector "#search-icon"
    Then "#search-dropdown" should be visible
    When I click on the element with css selector "#profile-icon"
    Then "#profile-dropdown" should be visible

  @javascript
  Scenario: Current page is highlighted in menu
    Given I am an anonymous user
    And I am on "library"
    When I am browsing using a "tablet"
    And I click on the element with css selector "nav li.toggle-topbar.menu-icon"
    Then "#main-menu-section li.first a" should have a "color" css value of "rgb(255, 255, 255)"
    And "#main-menu-section li.first a" should have a "background-color" css value of "rgb(43, 43, 43)"
    When I am browsing using a "desktop"
    Then "#main-menu-section li.first a" should have a "color" css value of "rgb(255, 255, 255)"
    And "#main-menu-section li.first a" should have a "background-color" css value of "rgb(46, 63, 78)"

  @javascript @api
  Scenario: prc-1617 is applied correctly and there are no regressions
    Given I am logged in as a user with the "Administrator" role
    And I am browsing using a "desktop"
    And I visit "instructional-tools/formative-instructional-tasks"
    # The style applies correctly to the contextual links menu
    Then ".contextual-links-region ul.menu li" should have a "margin-left" css value of "0px"
    # No regression with the dropdowns
    When I hover over the element "ul#main-menu li.has-dropdown"
    Then "li.dropdown-item" should have a "margin-left" css value of "0px"
    # No regression for the links at the bottom of diglib content on gallery view
    Given "Digital Library Content" nodes:
      | title      | body         | status | promote | uid | field_author_name | field_subject | field_grade_level_unlimited | field_media_type |
      | DL Content | Body Content | 1      | 0       | 1   | Author Name       | Math          | 1st Grade                   | Text             |
    And I visit the last node created
    And I click "Edit"
    And I select the radio button "Public" with the id "edit-field-permissions-und-public"
    And I press the "Save" button
    When I visit "library"
    # No additional margin added to the tabs
    When I click "DL Content"
    Then "ul.tabs li" should have a "margin-left" css value of "0px"
