@api @course @javascript @styleguide @prc-1721 @prc-1680
Feature: styles related to professional development courses.
  Scenario: Course edit form styles.
    Given I am logged in as a user with the "Administrator" role
    And I am on "prc/admin/admin-course"
    When I click "Add course"
    And I am browsing using a "desktop"
    Then "fieldset#edit-course select" should be "25%" of the width of "#edit-course" within a margin of "5%"
    And I am browsing using a "phone"
    And "fieldset#edit-course select" should be "100%" of the width of "#edit-course" within a margin of "10%"

  Scenario: prc-1680 and prc-1721 Course detail styles.
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "prc/admin/admin-course"
    When I click "Add course"
    And I check the box "Pre-K"
    And I select "1" from "edit-field-length-quantity-und"
    And I select "Hour" from "edit-field-length-unit-und"
    And I fill in "Course Title" with "Title PRC-69 AC4 @timestamp"
    And I fill in "Course Objectives" with "Obj PRC-69 AC4 @timestamp"
    And I attach the file "testfiles/lovelythumbnail.png" to "edit-field-thumbnail-und-0-upload"
    And I select the radio button "Public"
    And I check "Published"
    And I press "Save"
    And I click "Course outline"
    And I select "Module" from "edit-more-object-type"
    And I press "Add object"
    And I press "Save outline"
    And I click "View"
    And I am browsing using a "desktop"
    # Items in the right column
    Then the ".panel-col-first" element should contain "Course Objectives:"
    And the ".panel-col-first" element should contain "Take course"
    And the ".panel-col-first" element should contain "Course Outline"
    # Items in the left column
    And ".panel-col-last .field-name-field-thumbnail img" should have a "display" css value of "inline-block"
    And the ".panel-col-last" element should contain "Share"
    # White on the left, grey on the right & 2:1 layout
    # @todo: find a way to check for the the linear gradient
    And ".panel-col-last" should have a "background-color" css value of "transparent"
    And ".panel-col-first" should have a "background-color" css value of "rgb(255, 255, 255)"
    # page title is left orientated, and above tabs
    And ".pane-content h1" should have a "text-align" css value of "start"
    # The time that the course will take is below objectives
    # Social media panel has a heading of share and is styled correctly
    And ".pane-node-links .pane-title" should have a "font-weight" css value of "700"
    And ".pane-node-links .pane-title hr" should have a "border-top-color" css value of "rgb(111, 126, 149)"
    # The "like" icon is in place & is styled
    And I am logged in as a user with the "educator" role
    And I visit "professional-learning"
    And I click "Title PRC-69 AC4 @timestamp"
    And ".flag-like-content a.flag" should have a "background-image" css value of "url('sites/all/themes/prc_foundation/images/authenticated-se60a58fb9b.png')"
    # prc-1721 : Responsive behaviro
    And I am browsing using a "phone"
    # Thumbnail image isn't visible
    And ".pane-node-field-thumbnail" should have a "height" css value of "0px"
    # both columns are 100% width
    And ".panel-col-first" should be "100%" of the width of "#block-system-main .content" within a margin of "5%"
    And ".panel-col-last" should be "100%" of the width of "#block-system-main .content" within a margin of "5%"
    # Background of share area is white
    And ".panel-col-last" should have a "background-color" css value of "transparent"
    When I am browsing using a "tablet"
    # Thumbnail image isn't visible
    And ".pane-node-field-thumbnail" should have a "height" css value of "0px"
    # both columns are 100% width
    And ".panel-col-first" should be "100%" of the width of "#block-system-main .content" within a margin of "5%"
    And ".panel-col-last" should be "100%" of the width of "#block-system-main .content" within a margin of "5%"
    # Background of share area is white
    And ".panel-col-last" should have a "background-color" css value of "transparent"


