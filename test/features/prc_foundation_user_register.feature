@api @prc-1635 @styleguide @javascript
Feature: Test Responsive Behavior For Registration Form
  As a user,
  I want the registration form to be properly styled for mobile, tablet, and desktop devices
  so that I can register easily on any device.

  @javascript @tablet
  Scenario: Styling for the User Registration Form on a tablet.
    Given I am on "/user/register"
    When I am browsing using a "tablet"
  # ToDo: Replace this with the rule with a margin of error.
  #  Then "#edit-mail" should have a "width" css value of "730px" (714px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-pass-pass1" should have a "width" css value of "730px" (714px)
    And ".password-strength" should have a "float" css value of "right"
    And ".password-strength" should have a "width" css value of "272px"

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-pass-pass2" should have a "width" css value of "730px" (714px)
    When for "Password" I enter "123"

  # ToDo: Replace this with the rule with a margin of error.
  #  Then ".password-suggestions" should have a "width" css value of "722.4000000000001px" (706.4000000000001px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-field-first-name-und-0-value" should have a "width" css value of "730px" (714px)

  # ToDo: Replace this with the rule with a margin of error.
  # And "#edit-field-last-name-und-0-value" should have a "width" css value of "730px" (714px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-field-profession-und-0-value" should have a "width" css value of "730px" (714px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And ".chosen-search" should have a "width" css value of "728px" (712px)
    And I should not see "PARCC Member code"
    When for "Confirm password" I enter "123"
    Then ".password-confirm" should have a "width" css value of "165px"
    When I click on the element with css selector ".chosen-container"
    And I click on the element with css selector ".active-result:nth-child(7)"
    Then I should see "PARCC Member code"

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-state-account-number" should have a "width" css value of "730px" (714px)

  @javascript @phone
  Scenario: Styling for the User Registration Form on a phone.
    Given I am on "/user/register"
    When I am browsing using a "phone"
  # ToDo: Replace this with the rule with a margin of error.
  #  Then "#edit-mail" should have a "width" css value of "337px" (321px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-pass-pass1" should have a "width" css value of "337px" (321px)
    And ".password-strength" should have a "float" css value of "right"

  # ToDo: Replace this with the rule with a margin of error.
  #  And ".password-strength" should have a "width" css value of "228px" (217px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-pass-pass2" should have a "width" css value of "337px" (321px)
    When for "Password" I enter "123"

  # ToDo: Replace this with the rule with a margin of error.
  #  Then ".password-suggestions" should have a "width" css value of "329.4px" (313.4px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-field-first-name-und-0-value" should have a "width" css value of "337px" (321px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-field-last-name-und-0-value" should have a "width" css value of "337px" (321px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-field-profession-und-0-value" should have a "width" css value of "337px" (321px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And ".chosen-search" should have a "width" css value of "335px" (319px)
    And I should not see "PARCC Member code"
    When for "Confirm password" I enter "123"
    Then ".password-confirm" should have a "width" css value of "165px"
    When I click on the element with css selector ".chosen-container"
    And I click on the element with css selector ".active-result:nth-child(7)"
    Then I should see "PARCC Member code"

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-state-account-number" should have a "width" css value of "337px" (321px)

  @javascript @desktop
  Scenario: Styling for the User Registration Form on a desktop.
    Given I am on "/user/register"
    When I am browsing using a "desktop"
  # ToDo: Replace this with the rule with a margin of error.
  #  Then "#edit-mail" should have a "width" css value of "602px" (594px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-pass-pass1" should have a "width" css value of "297px" (293px)
    And ".password-strength" should have a "float" css value of "right"
    And ".password-strength" should have a "width" css value of "272px"

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-pass-pass2" should have a "width" css value of "297px" (293px)
    When for "Password" I enter "123"

  # ToDo: Replace this with the rule with a margin of error.
  #  Then ".password-suggestions" should have a "width" css value of "594.4000000000001px" (586.4000000000001px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-field-first-name-und-0-value" should have a "width" css value of "602px" (594px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-field-last-name-und-0-value" should have a "width" css value of "602px" (594px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-field-profession-und-0-value" should have a "width" css value of "602px" (594px)

  # ToDo: Replace this with the rule with a margin of error.
  #  And ".chosen-search" should have a "width" css value of "295px" (291px)
    And I should not see "PARCC Member code"
    When for "Confirm password" I enter "123"
    Then ".password-confirm" should have a "width" css value of "272px"
    When I click on the element with css selector ".chosen-container"
    And I click on the element with css selector ".active-result:nth-child(7)"
    Then I should see "PARCC Member code"

  # ToDo: Replace this with the rule with a margin of error.
  #  And "#edit-state-account-number" should have a "width" css value of "602px" (594px)