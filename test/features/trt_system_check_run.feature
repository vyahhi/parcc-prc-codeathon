@api @trt @system_check
Feature: PRC-791 System Check - Unstructured - View Results Page
  As an unstructured user
  I want to view the results page of a System Check I have run
  so that I can determine whether a computer meets the minimum tech requirements to run a PARCC Assessment.

  Acceptance Criteria
#  Given that I am on System Check page
#  And my fields are valid
#  When I click the Submit button
#  Then the system checks for:
#  • Monitor color depth
#  • Screen resolution
#  • Browser
#  • Browser: Cookies enabled
#  • Browser: JavaScript enabled
#  • Browser: Images enabled
#  Then I see the System Check Results page that has:
#  Page headline
#  System Check
  Results
  If all tested areas passed: Passed
  If any tested area failed: Failed plus copy: "Instructions or next steps go here. Consider linking to PARCC minimum requirements."
  System Check Name and Number of Devices
#  System Check: <System check name>
#  Number of devices: <#>
  Results table
  Area	System Details	Results	Pass requirement
#  Device type	<Device type>	N/A
  Operating system	<Operating system>	<Passed or Failed>	Any option besides "other" selected from Operating system dropdown on System Check page
#  Monitor size (in inches)	<Monitor size> inch	<Passed or Failed>	9.7 inch or better
#  Monitor color depth	<Monitor color depth>	<Passed or Failed>	16 Bit or better
#  Screen resolution	<Screen resolution>	<Passed or Failed>	1024 x 768 or higher
  Processor speed	<Processor speed>	<Passed or Failed>	1 Ghz or faster
#  RAM	<RAM>	<Passed or Failed>	At least 2 GB and under 4 GB
  Browser	<Browser>	<Passed or Failed>	See charts PARCC PRC Browser Requirements by OS.docx
#  Browser: Cookies enabled	<Yes or No>	<Passed or Failed>	Cookies enabled
#  Browser: JavaScript enabled	<Yes or No>	<Passed or Failed>	JavaScript enabled
#  Browser: Images enabled	<Yes or No>	<Passed or Failed>	Images enabled
#  Additional Consideration
#  If Java Script not enabled, "Failed" message appears and for each area system detects "Failed" appears

  Scenario: Run check headless
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the heading "System Check"
    Then I should see the text "System check name:"
    And I should see the text "Check 2"
    And I should see the text "Number of devices:"
    And I should see the text "23"
    And I should see the text "Device type"
    And I should see the text "Desktop"
    And I should see the text "Operating system"
    And I should see the text "Windows 7"
    And I should see the text "Monitor size \(in inches\)"
    And I should see the text "17"
    And I should see the text "Processor speed"
    And I should see the text "At least 2 Ghz and under 2.5 Ghz"
    And I should see the text "RAM"
    And I should see the text "At least 2 GB and under 4 GB"
    And I should see the text "Browser"
    And I should see the text "ff"
    And I should see the text "33"
    And I should see the text "24"
    And I should see the text "1024"
    And I should see the text "768"
    And I should not see the text "Fail"
    And I should see the text "Passed"
    And I should not see the text "Failed"

  Scenario: Run check headless - Javascript fail
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "false"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"

  Scenario: Run check headless - Cookies fail
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "false"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"

  Scenario: Run check headless - Images fail
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "false"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"

  Scenario: Run check headless - Screen width fail
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1023"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"

  Scenario: Run check headless - Screen height fail
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "767"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"

  Scenario: Run check headless - Color depth fail
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "15"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"

  Scenario: PRC-964 - Processor speed now N/A instead of pass/fail
    Given I am logged in as a user with the "Educator" role
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should not see the text "Fail"
    And I should see the text "Passed"
    And I should not see the text "Failed"
    And I should see the text "N/A"

  Scenario Outline: PRC-964 RAM doesn't fail on Chromebook or iPad
    Given I am logged in as a user with the "Educator" role
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "<operating_system>" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "Less than 512 MB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should not see the text "Fail"
    And I should see the text "Passed"
    And I should not see the text "Failed"
  Examples:
    | operating_system             |
    | Apple iOS 6, 7 or 8          |
    | Chrome OS 35-39 (Chromebook) |

  Scenario Outline: Run check headless - Browser/OS Pass
    Given I am logged in as a user with the "Educator" role
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "<operating_system>" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should not see the text "Fail"
    And I should see the text "Passed"
    And I should not see the text "Failed"
  Examples:
    | operating_system             |
    | Android Lollipop             |
    | Apple iOS 6, 7 or 8          |
    | Chrome OS 35-39 (Chromebook) |
    | Fedora 19 or 20              |
    | Mac 10.6                     |
    | Mac 10.7                     |
    | Mac 10.8                     |
    | Mac 10.9                     |
    | Mac 10.10                    |
    | Ubuntu 12.04 or 14.04        |
    | Windows XP (SP 3)            |
    | Windows Vista                |
    | Windows 7                    |
    | Windows 8                    |
    | Windows 8.1                  |

  Scenario: PRC-964 Change  Run check headless - Browser/OS Fail
    Given I am logged in as a user with the "Educator" role
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Other" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"

  Scenario: Run check headless - RAM Fail
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "Less than 512 MB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"

  Scenario: Run check headless - Monitor size Fail
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    # PRC-964 Change to minimum monitor size
    And I fill in "Monitor size (in inches)" with "9.4"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"
