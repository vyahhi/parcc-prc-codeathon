@api @d7 @styleguide @prc-1516 @homepage
Feature: Gallery View Responsive behavior – Assessments (PRC-1089)
  As a user
  I want my view of the homepage to be organized and easy to navigate
  so that I can easily view the content consistently throughout the site.

  ##### Homepage #####

  @javascript
  Scenario: Homepage style matches style guide
    Given I have no "Homepage Band" nodes
    And "Homepage Band" nodes:
      | title            | body        | status | field_link_to_a_url | field_band_image |
      | Band 1       | First Body  | 1      | library   | lovelythumbnail.png |
      | Band 2       | Second Body  | 1      | library   | lovelythumbnail.png |
    #And I index search results
    And I am logged in as a user with the "PRC Admin" role
    And I am viewing my "Homepage Band" node with the title "Band 1"
    And I follow "Edit"
    And I attach the file "testfiles/lovelythumbnail.png" to "edit-field-band-image-und-0-upload"
    And I press "Save"
    And I am on "front"
    When I am browsing using a "phone"
    Then ".main" should have a "padding-left" css value of "15px"
    And ".main" should have a "padding-right" css value of "15px"
    And ".pane-1 h2" should have a "font-size" css value of "32px"
    And ".pane-1 h2" should have a "text-align" css value of "center"
    And ".pane-1 h2" should have a "font-family" css value of "'Open Sans Condensed','Helvetica Neue',Helvetica,Arial,sans-serif"
    And ".homepage-menu li:first-child" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/homepage_menu_bkg_library.jpeg')"
    And ".homepage-menu li:first-child a" should have an "href" attribute value of "/library"
    And ".homepage-menu li:nth-child(2)" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/homepage_menu_bkg_instruction.jpeg')"
    And ".homepage-menu li:nth-child(2) a" should have an "href" attribute value of "/instructional-tools"
    And ".homepage-menu li:nth-child(3)" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/homepage_menu_bkg_assessment.jpeg')"
    And ".homepage-menu li:nth-child(3) a" should have an "href" attribute value of "/assessments"
    And ".homepage-menu li:nth-child(4)" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/homepage_menu_bkg_professional.jpeg')"
    And ".homepage-menu li:nth-child(4) a" should have an "href" attribute value of "/professional-learning"
    # TODO - Need to find an alternate approach to testing widths
    # And ".homepage-menu li:nth-child(2)" should have a "width" css value of "360px"
    And ".homepage-menu li:nth-child(2) a" should have a "font-size" css value of "32px"
    And ".homepage-menu li:nth-child(2) a" should have a "color" css value of "rgb(255, 255, 255)"
    And ".homepage-menu li:nth-child(2) a" should have a "text-decoration" css value of "none"
    And ".homepage-menu li:nth-child(2) a" should have a "padding-top" css value of "200px"
    And ".field-name-field-band-image" should have a "display" css value of "none"
    And ".views-row-even" should have a "background-color" css value of "rgb(238, 238, 238)"
    # Todo - update css step to handle multiple backgrounds in a single rule.
    When I am an anonymous user
    And I am on "front"
    Then ".homepage-menu li:first-child" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/homepage_menu_bkg_library.jpeg')"
    And ".homepage-menu li:first-child a" should have an "href" attribute value of "/library"
    And ".homepage-menu li:nth-child(2)" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/homepage_menu_bkg_assessment.jpeg')"
    And ".homepage-menu li:nth-child(2) a" should have an "href" attribute value of "/assessments"
    And ".homepage-menu li:nth-child(3)" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/homepage_menu_bkg_professional.jpeg')"
    And ".homepage-menu li:nth-child(3) a" should have an "href" attribute value of "/professional-learning"
    When I am browsing using a "tablet"
    # Then ".homepage-menu li:nth-child(2)" should have a "width" css value of "251px"
    And ".field-name-field-band-image" should have a "display" css value of "block"
    # When I am browsing using a "desktop"
    # Then ".homepage-menu li:nth-child(2)" should have a "width" css value of "422px"