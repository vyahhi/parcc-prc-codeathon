@api @d7 @styleguide @prc-751 @prc-902 @diglib
Feature: Digital Library - Item Detail Page Responsive Behavior (PRC-751)
  As a user
  I want my view of the Digital Library interior pages to be responsive
  so that I can easily view the content on different devices.

  Digital Library - Item Detail Page Styling (PRC-902)
  As a user
  I want my view of the Digital Library interior pages to be organized and easy to navigate
  so that I can easily view the content consistently throughout the site.

  ##### Digital Library Item Detail #####

  @javascript
  Scenario: Digital library item detail page responsive behavior matches style guide
    Given "Digital Library Content" nodes:
      | title         | body              | status | promote | uid | field_author_name | field_thumbnail          | field_subject | field_grade_level | field_media_type  |
      | DL Content        | Body Content | 1      | 0       | 1   | Author Name               | lovelythumbnail.png       | Math         | 1st Grade    | Text              |
    And I index search results
    And I am logged in as a user with the "authenticated user" role
    And I visit the last node created
    When I am browsing using a "phone"
    Then ".group-left" should have a "padding-left" css value of "15px"
    And ".group-left" should have a "width" css value of "341px"
    And ".group-left" should have a "padding-right" css value of "15px"
    And ".group-left .breadcrumb" should be visible
    And ".group-left #page-title" should be visible
    And ".group-left .field-name-field-author-name" should be visible
    And ".group-left .field-name-body" should be visible
    And ".group-left li.prc_digital_library_comment_email" should be visible
    Then ".group-right" should have a "padding-left" css value of "15px"
    And ".group-right" should have a "width" css value of "341px"
    And ".group-right" should have a "padding-right" css value of "15px"
    And ".group-right .field-name-field-grade-level" should be visible
    And ".group-right .field-name-field-subject" should be visible
    And ".group-right .sharethis" should be visible
    When I am browsing using a "desktop"
    Then ".group-left" should have a "padding-left" css value of "30px"
    And ".group-left" should have a "width" css value of "785px"
    And ".group-left" should have a "padding-right" css value of "30px"
    Then ".group-right" should have a "padding-left" css value of "30px"
    And ".group-right" should have a "width" css value of "362px"
    And ".group-right" should have a "padding-right" css value of "30px"

  @javascript
  Scenario: Digital library item detail page styling matches style guide
    Given "Digital Library Content" nodes:
      | title         | body              | status | promote | uid | field_author_name | field_subject | field_grade_level | field_media_type  |
      | DL Content        | Body Content | 1      | 0       | 1   | Author Name               | Math         | 1st Grade    | Text              |
    And I index search results
    And I am logged in as a user with the "authenticated user" role
    And I visit the last node created
    When I am browsing using a "phone"
    Then ".group-left .breadcrumb" should be visible
    # And "#sub-header h1#page-title" should be visible
    And ".group-left .breadcrumb" should have a "font-size" css value of "16px"
    And ".group-left .breadcrumb" should have a "font-family" css value of "'Open Sans Condensed','Helvetica Neue',Helvetica,Arial,sans-serif"
    And ".group-left .breadcrumb" should have a "color" css value of "rgb(70, 70, 70)"
    And ".group-left .breadcrumb" should have a "font-weight" css value of "700"
    And ".group-left .breadcrumb" should have a "padding-top" css value of "10px"
    And ".group-left .breadcrumb" should have a "padding-bottom" css value of "0px"
    And ".group-left .breadcrumb a" should have a "color" css value of "rgb(112, 84, 125)"
    And I hover over the element ".group-left .breadcrumb a"
    And ".group-left .breadcrumb a" should have a "text-decoration" css value of "underline"
    And ".group-left #page-title" should have a "font-size" css value of "32px"
    And ".group-left #page-title" should have a "line-height" css value of "32.4px"
    And ".group-left #page-title" should have a "color" css value of "rgb(112, 84, 125)"
    And ".group-left .field-name-field-author-name" should have a "font-family" css value of "'Open Sans Condensed','Helvetica Neue',Helvetica,Arial,sans-serif"
    And ".group-left .field-name-field-author-name" should have a "font-weight" css value of "700"
    And ".group-left .field-name-field-author-name" should have a "margin-bottom" css value of "0px"
    And ".group-left .field-name-post-date" should have a "font-family" css value of "'Open Sans Condensed','Helvetica Neue',Helvetica,Arial,sans-serif"
    And ".group-left .field-name-post-date" should have a "font-weight" css value of "700"
    And ".group-left .field-name-post-date" should have a "margin-bottom" css value of "20px"
    And ".group-left .field-name-body" should have a "font-family" css value of "'Open Sans','Helvetica Neue',Helvetica,Arial,sans-serif"
    And ".group-left .field-name-body p" should have a "font-size" css value of "16px"
    And ".group-left .field-name-body p" should have a "font-weight" css value of "400"
    And ".group-left .field-name-body p" should have a "line-height" css value of "24px"
    And ".group-left .field-name-body p" should have a "margin-bottom" css value of "20px"
    And ".group-left .field-name-body p" should have a "color" css value of "rgb(70, 70, 70)"
    And ".group-left .prc_digital_library_comment_email" should have a "width" css value of "125px"
    # The test is giving us a value of 0 for the margin steps below which isn't accurate or useful.
    # And ".group-left .prc_digital_library_comment_email" should have a "margin-left" css value of "auto"
    # And ".group-left .prc_digital_library_comment_email" should have a "margin-right" css value of "auto"
    And ".group-left .prc_digital_library_comment_email" should have a "list-style-type" css value of "none"
    And ".group-left .prc_digital_library_comment_email a" should have a "border-top-color" css value of "rgb(85, 64, 94)"
    And ".group-left .prc_digital_library_comment_email a" should have a "background-color" css value of "rgb(255, 255, 255)"
    And ".group-left .prc_digital_library_comment_email a" should have a "border-top-left-radius" css value of "24.75px"
    And ".group-left .prc_digital_library_comment_email a" should have a "margin-top" css value of "32px"
    And ".group-left .prc_digital_library_comment_email a" should have a "margin-bottom" css value of "32px"
    When I hover over the element ".group-left .prc_digital_library_comment_email a"
    And ".group-left .prc_digital_library_comment_email a" should have a "background-color" css value of "rgb(85, 64, 94)"
    And ".group-left .prc_digital_library_comment_email a" should have a "color" css value of "rgb(255, 255, 255)"
    And ".group-right .field-label.divider" should have a "font-family" css value of "'Open Sans Condensed','Helvetica Neue',Helvetica,Arial,sans-serif"
    And ".group-right .field-label.divider" should have a "font-weight" css value of "700"
    And ".group-right .field-name-field-subject .field-label.divider hr" should be visible
    # Todo - Responsive image coverage
    And ".prc_digital_library_add_to_favorites a" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/favorite-icon.png')"
    And ".page-node.node-type-digital-library-content .group-right ul.links .flag-like_content a, .gallery-main .view-content .columns ul.links .flag-like_content a" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/like-icon.png')"
    And "li.pinit a" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/pinterest-icon.png')"
    # Add this load delay makes this unreliable to test.
    # And "span.st-email-counter" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/email-icon.png')"
    # And "span.st-email-counter" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/facebook-icon.png')"
    # And "ul.links span.st_edmodo_button .stButton_gradient" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/edmodo-icon.png')"
    And "#page" should have a "background-color" css value of "rgb(255, 255, 255)"
    When I am browsing using a "desktop"
    Then ".group-left #page-title" should have a "font-size" css value of "42px"
    # Todo - rewrite css value step to be able to test for linear gradient background here.