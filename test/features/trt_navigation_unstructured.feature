@api @trt @navigation @unstructured @prc-816
Feature: PRC-816 Navigation - Readiness Check Pages - Unstructured
  As an unstructured user,
  I want to navigate from of one readiness check to the other
  so that I can quickly run both.

#  Acceptance Criteria
#  Given that I am a user
#  When I am on <page>
#  Then I see <navigation>
#  Given that I am a user
#  When I click on <navigation>
#  Then I see <page>
#  Navigation on System Check pages
#  On System Check - Unstructured - Form (PRC-760)
#  On System Check - Unstructured - View Results Page (PRC-791)
#  Navigation (above page headline)
#  System Check | Testing Capacity Checks (link to Testing Capacity Check - Unstructured - Form (PRC-761))
#  Navigation on Testing Capacity Check pages
#  On Testing Capacity Check - Unstructured - Form (PRC-761)
#  On Testing Capacity Check - Unstructured - View Results (PRC-801)
#  Navigation (above page headline)
#  System Check (link to On System Check - Unstructured - Form (PRC-760)) | Testing Capacity Checks

  Scenario: Sys Check to Cap check
    Given I am an anonymous user
    And I visit "assessments/technology-readiness"
    When I click "System Check"
    Then I should see the text "System Check"
    And I should see the link "Testing Capacity Checks"
    When I click "Testing Capacity Checks"
    Then I should see the link "System Check"
    And I should see the text "Testing Capacity Checks"

  Scenario: System check results
    Given I am logged in as a user with the "Educator" role
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 512 and under 1 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "System Check"
    And I should see the link "Testing Capacity Checks"

  Scenario: Capacity Check results
    Given I am logged in as a user with the "Educator" role
    And I am on "admin/structure/entity-type/prc_trt/capacity_check/add"
    When I fill in "Number of students" with "100"
    When I fill in "Number of devices ready for assessment" with "50"
    When I fill in "Number of days of testing" with "5"
    When I fill in "Number of test sessions per day" with "5"
    When I fill in "Number of sittings per student" with "5"
    When I fill in "Speed of connection (in Mbps)" with "14"
    And I press "Submit"
    Then I should see the link "System Check"
    And I should see the text "Testing Capacity Checks"
