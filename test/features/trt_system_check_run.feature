@api @trt @system_check @prc-791 @prc-964 @prc-1045
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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
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

  Scenario Outline: PRC-964 Browser/OS check - Upgrade recommended
    Given I am logged in as a user with the "Educator" role
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "<operating_system>" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 2 GB and under 4 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "<browser>"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should not see the text "Fail"
    And I should see the text "Passed"
    And I should see the text "Upgrade recommended"
    And I should not see the text "Failed"
  Examples:
    | operating_system | browser    |
    | Mac 10.6         | safari 5.1 |
    | Windows Vista    | ie 9       |
    | Windows 7        | ie 9       |

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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"

  Scenario: Run check headless - RAM Minimum pass
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
    Then I should not see the text "Fail"
    And I should see the text "Passed"
    And I should see the text "Passed"

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
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"

  Scenario Outline: OS/Browser results
    When I run a system check with the "<os>" operating system and the "<browser>" browser version "<version>"
    Then I should get a "<result>" result

  Examples:
    | os       | browser | version | result |
    | winxpsp3 | ie      | 9       | false  |
    | winxpsp3 | ie      | 10      | false  |
    | winxpsp3 | ie      | 11      | false  |
    | winxpsp3 | chrome  | 34      | false  |
    | winxpsp3 | chrome  | 35      | true   |
    | winxpsp3 | chrome  | 36      | true   |
    | winxpsp3 | chrome  | 37      | true   |
    | winxpsp3 | chrome  | 38      | true   |
    | winxpsp3 | chrome  | 39      | true   |
    | winxpsp3 | chrome  | 40      | false  |
    | winxpsp3 | ff      | 27      | false  |
    | winxpsp3 | ff      | 28      | true   |
    | winxpsp3 | ff      | 29      | true   |
    | winxpsp3 | ff      | 30      | true   |
    | winxpsp3 | ff      | 31      | true   |
    | winxpsp3 | ff      | 32      | true   |
    | winxpsp3 | ff      | 33      | true   |
    | winxpsp3 | ff      | 34      | true   |
    | winxpsp3 | ff      | 35      | true   |
    | winxpsp3 | ff      | 36      | false  |
    | winvista | ie      | 9       | true   |
    | winvista | ie      | 10      | false  |
    | winvista | ie      | 11      | false  |
    | winvista | chrome  | 34      | false  |
    | winvista | chrome  | 35      | true   |
    | winvista | chrome  | 36      | true   |
    | winvista | chrome  | 37      | true   |
    | winvista | chrome  | 38      | true   |
    | winvista | chrome  | 39      | true   |
    | winvista | chrome  | 40      | false  |
    | winvista | ff      | 27      | false  |
    | winvista | ff      | 28      | true   |
    | winvista | ff      | 29      | true   |
    | winvista | ff      | 30      | true   |
    | winvista | ff      | 31      | true   |
    | winvista | ff      | 32      | true   |
    | winvista | ff      | 33      | true   |
    | winvista | ff      | 34      | true   |
    | winvista | ff      | 35      | true   |
    | winvista | ff      | 36      | false  |
    | win7     | ie      | 9       | true   |
    | win7     | ie      | 10      | true   |
    | win7     | ie      | 11      | true   |
    | win7     | chrome  | 34      | false  |
    | win7     | chrome  | 35      | true   |
    | win7     | chrome  | 36      | true   |
    | win7     | chrome  | 37      | true   |
    | win7     | chrome  | 38      | true   |
    | win7     | chrome  | 39      | true   |
    | win7     | chrome  | 40      | false  |
    | win7     | ff      | 27      | false  |
    | win7     | ff      | 28      | true   |
    | win7     | ff      | 29      | true   |
    | win7     | ff      | 30      | true   |
    | win7     | ff      | 31      | true   |
    | win7     | ff      | 32      | true   |
    | win7     | ff      | 33      | true   |
    | win7     | ff      | 34      | true   |
    | win7     | ff      | 35      | true   |
    | win7     | ff      | 36      | false  |
    | win8     | ie      | 9       | false  |
    | win8     | ie      | 10      | true   |
    | win8     | ie      | 11      | false  |
    | win8     | chrome  | 34      | false  |
    | win8     | chrome  | 35      | true   |
    | win8     | chrome  | 36      | true   |
    | win8     | chrome  | 37      | true   |
    | win8     | chrome  | 38      | true   |
    | win8     | chrome  | 39      | true   |
    | win8     | chrome  | 40      | false  |
    | win8     | ff      | 27      | false  |
    | win8     | ff      | 28      | true   |
    | win8     | ff      | 29      | true   |
    | win8     | ff      | 30      | true   |
    | win8     | ff      | 31      | true   |
    | win8     | ff      | 32      | true   |
    | win8     | ff      | 33      | true   |
    | win8     | ff      | 34      | true   |
    | win8     | ff      | 35      | true   |
    | win8     | ff      | 36      | false  |
    | win81    | ie      | 9       | false  |
    | win81    | ie      | 10      | false  |
    | win81    | ie      | 11      | true   |
    | win81    | chrome  | 34      | false  |
    | win81    | chrome  | 35      | true   |
    | win81    | chrome  | 36      | true   |
    | win81    | chrome  | 37      | true   |
    | win81    | chrome  | 38      | true   |
    | win81    | chrome  | 39      | true   |
    | win81    | chrome  | 40      | false  |
    | win81    | ff      | 27      | false  |
    | win81    | ff      | 28      | true   |
    | win81    | ff      | 29      | true   |
    | win81    | ff      | 30      | true   |
    | win81    | ff      | 31      | true   |
    | win81    | ff      | 32      | true   |
    | win81    | ff      | 33      | true   |
    | win81    | ff      | 34      | true   |
    | win81    | ff      | 35      | true   |
    | win81    | ff      | 36      | false  |

    | mac106   | safari  | 5       | true   |
    | mac106   | safari  | 6       | false  |
    | mac106   | safari  | 7       | false  |
    | mac106   | safari  | 8       | false  |
    | mac106   | ff      | 27      | false  |
    | mac106   | ff      | 28      | true   |
    | mac106   | ff      | 29      | true   |
    | mac106   | ff      | 30      | true   |
    | mac106   | ff      | 31      | true   |
    | mac106   | ff      | 32      | true   |
    | mac106   | ff      | 33      | true   |
    | mac106   | ff      | 34      | true   |
    | mac106   | ff      | 35      | true   |
    | mac106   | ff      | 36      | false  |
    | mac106   | chrome  | 34      | false  |
    | mac106   | chrome  | 35      | false  |
    | mac106   | chrome  | 36      | false  |
    | mac106   | chrome  | 37      | false  |
    | mac106   | chrome  | 38      | false  |
    | mac106   | chrome  | 39      | false  |
    | mac106   | chrome  | 40      | false  |

    | mac107   | safari  | 5       | false  |
    | mac107   | safari  | 6       | true   |
    | mac107   | safari  | 7       | false  |
    | mac107   | safari  | 8       | false  |
    | mac107   | ff      | 27      | false  |
    | mac107   | ff      | 28      | true   |
    | mac107   | ff      | 29      | true   |
    | mac107   | ff      | 30      | true   |
    | mac107   | ff      | 31      | true   |
    | mac107   | ff      | 32      | true   |
    | mac107   | ff      | 33      | true   |
    | mac107   | ff      | 34      | true   |
    | mac107   | ff      | 35      | true   |
    | mac107   | ff      | 36      | false  |
    | mac107   | chrome  | 34      | false  |
    | mac107   | chrome  | 35      | false  |
    | mac107   | chrome  | 36      | false  |
    | mac107   | chrome  | 37      | false  |
    | mac107   | chrome  | 38      | false  |
    | mac107   | chrome  | 39      | false  |
    | mac107   | chrome  | 40      | false  |

    | mac108   | safari  | 5       | false  |
    | mac108   | safari  | 6       | true   |
    | mac108   | safari  | 7       | false  |
    | mac108   | safari  | 8       | false  |
    | mac108   | ff      | 27      | false  |
    | mac108   | ff      | 28      | true   |
    | mac108   | ff      | 29      | true   |
    | mac108   | ff      | 30      | true   |
    | mac108   | ff      | 31      | true   |
    | mac108   | ff      | 32      | true   |
    | mac108   | ff      | 33      | true   |
    | mac108   | ff      | 34      | true   |
    | mac108   | ff      | 35      | true   |
    | mac108   | ff      | 36      | false  |
    | mac108   | chrome  | 34      | false  |
    | mac108   | chrome  | 35      | false  |
    | mac108   | chrome  | 36      | false  |
    | mac108   | chrome  | 37      | false  |
    | mac108   | chrome  | 38      | false  |
    | mac108   | chrome  | 39      | false  |
    | mac108   | chrome  | 40      | false  |

    | mac109   | safari  | 5       | false  |
    | mac109   | safari  | 6       | false  |
    | mac109   | safari  | 7       | true   |
    | mac109   | safari  | 8       | false  |
    | mac109   | ff      | 27      | false  |
    | mac109   | ff      | 28      | true   |
    | mac109   | ff      | 29      | true   |
    | mac109   | ff      | 30      | true   |
    | mac109   | ff      | 31      | true   |
    | mac109   | ff      | 32      | true   |
    | mac109   | ff      | 33      | true   |
    | mac109   | ff      | 34      | true   |
    | mac109   | ff      | 35      | true   |
    | mac109   | ff      | 36      | false  |
    | mac109   | chrome  | 34      | false  |
    | mac109   | chrome  | 35      | false  |
    | mac109   | chrome  | 36      | false  |
    | mac109   | chrome  | 37      | false  |
    | mac109   | chrome  | 38      | false  |
    | mac109   | chrome  | 39      | false  |
    | mac109   | chrome  | 40      | false  |

    | mac1010  | safari  | 5       | false  |
    | mac1010  | safari  | 6       | false  |
    | mac1010  | safari  | 7       | false  |
    | mac1010  | safari  | 8       | true   |
    | mac1010  | ff      | 27      | false  |
    | mac1010  | ff      | 28      | true   |
    | mac1010  | ff      | 29      | true   |
    | mac1010  | ff      | 30      | true   |
    | mac1010  | ff      | 31      | true   |
    | mac1010  | ff      | 32      | true   |
    | mac1010  | ff      | 33      | true   |
    | mac1010  | ff      | 34      | true   |
    | mac1010  | ff      | 35      | true   |
    | mac1010  | ff      | 36      | false  |
    | mac1010  | chrome  | 34      | false  |
    | mac1010  | chrome  | 35      | false  |
    | mac1010  | chrome  | 36      | false  |
    | mac1010  | chrome  | 37      | false  |
    | mac1010  | chrome  | 38      | false  |
    | mac1010  | chrome  | 39      | false  |
    | mac1010  | chrome  | 40      | false  |

    | chrome35 | safari  | 5       | true   |
    | chrome35 | safari  | 6       | true   |
    | chrome35 | safari  | 7       | true   |
    | chrome35 | safari  | 8       | true   |
    | chrome35 | ff      | 27      | true   |
    | chrome35 | ff      | 28      | true   |
    | chrome35 | ff      | 29      | true   |
    | chrome35 | ff      | 30      | true   |
    | chrome35 | ff      | 31      | true   |
    | chrome35 | ff      | 32      | true   |
    | chrome35 | ff      | 33      | true   |
    | chrome35 | ff      | 34      | true   |
    | chrome35 | ff      | 35      | true   |
    | chrome35 | ff      | 36      | true   |
    | chrome35 | chrome  | 34      | true   |
    | chrome35 | chrome  | 35      | true   |
    | chrome35 | chrome  | 36      | true   |
    | chrome35 | chrome  | 37      | true   |
    | chrome35 | chrome  | 38      | true   |
    | chrome35 | chrome  | 39      | true   |
    | chrome35 | chrome  | 40      | true   |

    | ios6     | safari  | 5       | true   |
    | ios6     | safari  | 6       | true   |
    | ios6     | safari  | 7       | true   |
    | ios6     | safari  | 8       | true   |
    | ios6     | ff      | 27      | true   |
    | ios6     | ff      | 28      | true   |
    | ios6     | ff      | 29      | true   |
    | ios6     | ff      | 30      | true   |
    | ios6     | ff      | 31      | true   |
    | ios6     | ff      | 32      | true   |
    | ios6     | ff      | 33      | true   |
    | ios6     | ff      | 34      | true   |
    | ios6     | ff      | 35      | true   |
    | ios6     | ff      | 36      | true   |
    | ios6     | chrome  | 34      | true   |
    | ios6     | chrome  | 35      | true   |
    | ios6     | chrome  | 36      | true   |
    | ios6     | chrome  | 37      | true   |
    | ios6     | chrome  | 38      | true   |
    | ios6     | chrome  | 39      | true   |
    | ios6     | chrome  | 40      | true   |

    | fedora19 | safari  | 5       | false  |
    | fedora19 | safari  | 6       | false  |
    | fedora19 | safari  | 7       | false  |
    | fedora19 | safari  | 8       | false  |
    | fedora19 | ff      | 27      | false  |
    | fedora19 | ff      | 28      | true   |
    | fedora19 | ff      | 29      | true   |
    | fedora19 | ff      | 30      | true   |
    | fedora19 | ff      | 31      | true   |
    | fedora19 | ff      | 32      | true   |
    | fedora19 | ff      | 33      | true   |
    | fedora19 | ff      | 34      | true   |
    | fedora19 | ff      | 35      | true   |
    | fedora19 | ff      | 36      | false  |
    | fedora19 | chrome  | 34      | false  |
    | fedora19 | chrome  | 35      | false  |
    | fedora19 | chrome  | 36      | false  |
    | fedora19 | chrome  | 37      | false  |
    | fedora19 | chrome  | 38      | false  |
    | fedora19 | chrome  | 39      | false  |
    | fedora19 | chrome  | 40      | false  |

    | ubuntu12 | safari  | 5       | false  |
    | ubuntu12 | safari  | 6       | false  |
    | ubuntu12 | safari  | 7       | false  |
    | ubuntu12 | safari  | 8       | false  |
    | ubuntu12 | ff      | 27      | false  |
    | ubuntu12 | ff      | 28      | true   |
    | ubuntu12 | ff      | 29      | true   |
    | ubuntu12 | ff      | 30      | true   |
    | ubuntu12 | ff      | 31      | true   |
    | ubuntu12 | ff      | 32      | true   |
    | ubuntu12 | ff      | 33      | true   |
    | ubuntu12 | ff      | 34      | true   |
    | ubuntu12 | ff      | 35      | true   |
    | ubuntu12 | ff      | 36      | false  |
    | ubuntu12 | chrome  | 34      | false  |
    | ubuntu12 | chrome  | 35      | false  |
    | ubuntu12 | chrome  | 36      | false  |
    | ubuntu12 | chrome  | 37      | false  |
    | ubuntu12 | chrome  | 38      | false  |
    | ubuntu12 | chrome  | 39      | false  |
    | ubuntu12 | chrome  | 40      | false  |

  Scenario Outline: PRC-1045 Java plugin pass/fail
    When I run a system check with the "<jre>" JRE version and the "<os>" operating system and the "<browser>" browser version "<version>"
    Then I should get a "<result>" result
  Examples:
    | jre      | os       | browser | version | result |
    | 1.4.0_65 | winxpsp3 | ie      | 9       | false  |
    | 1.4.0_65 | winxpsp3 | ie      | 10      | false  |
    | 1.4.0_65 | winxpsp3 | ie      | 11      | false  |
    | 1.5.0_65 | winxpsp3 | ie      | 9       | true   |
    | 1.5.0_65 | winxpsp3 | ie      | 10      | false  |
    | 1.5.0_65 | winxpsp3 | ie      | 11      | false  |
    | 1.6.0_65 | winxpsp3 | ie      | 9       | true   |
    | 1.6.0_65 | winxpsp3 | ie      | 10      | true   |
    | 1.6.0_65 | winxpsp3 | ie      | 11      | false  |
    | 1.7.0_65 | winxpsp3 | ie      | 9       | true   |
    | 1.7.0_65 | winxpsp3 | ie      | 10      | true   |
    | 1.7.0_65 | winxpsp3 | ie      | 11      | true   |
    | 1.5.0_65 | winxpsp3 | chrome  | 34      | false  |
    | 1.5.0_65 | winxpsp3 | chrome  | 35      | false  |
    | 1.5.0_65 | winxpsp3 | chrome  | 36      | false  |
    | 1.5.0_65 | winxpsp3 | chrome  | 37      | false  |
    | 1.5.0_65 | winxpsp3 | chrome  | 38      | false  |
    | 1.5.0_65 | winxpsp3 | chrome  | 39      | false  |
    | 1.5.0_65 | winxpsp3 | chrome  | 40      | false  |
    | 1.6.0_65 | winxpsp3 | chrome  | 34      | false  |
    | 1.6.0_65 | winxpsp3 | chrome  | 35      | true   |
    | 1.6.0_65 | winxpsp3 | chrome  | 36      | true   |
    | 1.6.0_65 | winxpsp3 | chrome  | 37      | true   |
    | 1.6.0_65 | winxpsp3 | chrome  | 38      | true   |
    | 1.6.0_65 | winxpsp3 | chrome  | 39      | true   |
    | 1.6.0_65 | winxpsp3 | chrome  | 40      | false  |
    | 1.6.0_65 | winxpsp3 | ff      | 27      | false  |
    | 1.6.0_65 | winxpsp3 | ff      | 28      | true   |
    | 1.6.0_65 | winxpsp3 | ff      | 29      | true   |
    | 1.6.0_65 | winxpsp3 | ff      | 30      | true   |
    | 1.6.0_65 | winxpsp3 | ff      | 31      | true   |
    | 1.6.0_65 | winxpsp3 | ff      | 32      | true   |
    | 1.6.0_65 | winxpsp3 | ff      | 33      | true   |
    | 1.6.0_65 | winxpsp3 | ff      | 34      | true   |
    | 1.6.0_65 | winxpsp3 | ff      | 35      | true   |
    | 1.6.0_65 | winxpsp3 | ff      | 36      | false  |
    | 1.6.0_25 | winxpsp3 | ff      | 27      | false  |
    | 1.6.0_25 | winxpsp3 | ff      | 28      | false  |
    | 1.6.0_25 | winxpsp3 | ff      | 29      | false  |
    | 1.6.0_25 | winxpsp3 | ff      | 30      | false  |
    | 1.6.0_25 | winxpsp3 | ff      | 31      | false  |
    | 1.6.0_25 | winxpsp3 | ff      | 32      | false  |
    | 1.6.0_25 | winxpsp3 | ff      | 33      | false  |
    | 1.6.0_25 | winxpsp3 | ff      | 34      | false  |
    | 1.6.0_25 | winxpsp3 | ff      | 35      | false  |
    | 1.6.0_25 | winxpsp3 | ff      | 36      | false  |

    | 1.5.0_65 | mac106   | safari  | 5       | false  |
    | 1.5.0_65 | mac106   | safari  | 6       | false  |
    | 1.5.0_65 | mac106   | safari  | 7       | false  |
    | 1.5.0_65 | mac106   | safari  | 8       | false  |
    | 1.6.0_35 | mac106   | safari  | 5       | false  |
    | 1.6.0_35 | mac106   | safari  | 6       | true   |
    | 1.6.0_35 | mac106   | safari  | 7       | true   |
    | 1.6.0_35 | mac106   | safari  | 8       | true   |

    | 1.6.0_65 | mac106   | safari  | 5       | true   |
    | 1.6.0_65 | mac106   | safari  | 6       | true   |
    | 1.6.0_65 | mac106   | safari  | 7       | true   |
    | 1.6.0_65 | mac106   | safari  | 8       | true   |
    | 1.6.0_30 | mac106   | ff      | 27      | false  |
    | 1.6.0_30 | mac106   | ff      | 28      | true   |
    | 1.6.0_30 | mac106   | ff      | 29      | true   |
    | 1.6.0_30 | mac106   | ff      | 30      | true   |
    | 1.6.0_30 | mac106   | ff      | 31      | true   |
    | 1.6.0_30 | mac106   | ff      | 32      | true   |
    | 1.6.0_30 | mac106   | ff      | 33      | true   |
    | 1.6.0_30 | mac106   | ff      | 34      | true   |
    | 1.6.0_30 | mac106   | ff      | 35      | true   |
    | 1.6.0_30 | mac106   | ff      | 36      | false  |
    | 1.6.0_65 | mac106   | chrome  | 34      | false  |
    | 1.6.0_65 | mac106   | chrome  | 35      | false  |
    | 1.6.0_65 | mac106   | chrome  | 36      | false  |
    | 1.6.0_65 | mac106   | chrome  | 37      | false  |
    | 1.6.0_65 | mac106   | chrome  | 38      | false  |
    | 1.6.0_65 | mac106   | chrome  | 39      | false  |
    | 1.6.0_65 | mac106   | chrome  | 40      | false  |

    | 1.6.0_65 | chrome35 | safari  | 5       | false  |
    | 1.6.0_65 | chrome35 | safari  | 6       | false  |
    | 1.6.0_65 | chrome35 | safari  | 7       | false  |
    | 1.6.0_65 | chrome35 | safari  | 8       | false  |
    | 1.6.0_65 | chrome35 | ff      | 27      | false  |
    | 1.6.0_65 | chrome35 | ff      | 28      | false  |
    | 1.6.0_65 | chrome35 | ff      | 29      | false  |
    | 1.6.0_65 | chrome35 | ff      | 30      | false  |
    | 1.6.0_65 | chrome35 | ff      | 31      | false  |
    | 1.6.0_65 | chrome35 | ff      | 32      | false  |
    | 1.6.0_65 | chrome35 | ff      | 33      | false  |
    | 1.6.0_65 | chrome35 | ff      | 34      | false  |
    | 1.6.0_65 | chrome35 | ff      | 35      | false  |
    | 1.6.0_65 | chrome35 | ff      | 36      | false  |
    | 1.6.0_65 | chrome35 | chrome  | 34      | false  |
    | 1.6.0_65 | chrome35 | chrome  | 35      | false  |
    | 1.6.0_65 | chrome35 | chrome  | 36      | false  |
    | 1.6.0_65 | chrome35 | chrome  | 37      | false  |
    | 1.6.0_65 | chrome35 | chrome  | 38      | false  |
    | 1.6.0_65 | chrome35 | chrome  | 39      | false  |
    | 1.6.0_65 | chrome35 | chrome  | 40      | false  |

    | 1.6.0_65 | ios6     | safari  | 5       | false  |
    | 1.6.0_65 | ios6     | safari  | 6       | false  |
    | 1.6.0_65 | ios6     | safari  | 7       | false  |
    | 1.6.0_65 | ios6     | safari  | 8       | false  |
    | 1.6.0_65 | ios6     | ff      | 27      | false  |
    | 1.6.0_65 | ios6     | ff      | 28      | false  |
    | 1.6.0_65 | ios6     | ff      | 29      | false  |
    | 1.6.0_65 | ios6     | ff      | 30      | false  |
    | 1.6.0_65 | ios6     | ff      | 31      | false  |
    | 1.6.0_65 | ios6     | ff      | 32      | false  |
    | 1.6.0_65 | ios6     | ff      | 33      | false  |
    | 1.6.0_65 | ios6     | ff      | 34      | false  |
    | 1.6.0_65 | ios6     | ff      | 35      | false  |
    | 1.6.0_65 | ios6     | ff      | 36      | false  |
    | 1.6.0_65 | ios6     | chrome  | 34      | false  |
    | 1.6.0_65 | ios6     | chrome  | 35      | false  |
    | 1.6.0_65 | ios6     | chrome  | 36      | false  |
    | 1.6.0_65 | ios6     | chrome  | 37      | false  |
    | 1.6.0_65 | ios6     | chrome  | 38      | false  |
    | 1.6.0_65 | ios6     | chrome  | 39      | false  |
    | 1.6.0_65 | ios6     | chrome  | 40      | false  |

    | 1.6.0_65 | fedora19 | safari  | 5       | false  |
    | 1.6.0_65 | fedora19 | safari  | 6       | false  |
    | 1.6.0_65 | fedora19 | safari  | 7       | false  |
    | 1.6.0_65 | fedora19 | safari  | 8       | false  |
    | 1.6.0_65 | fedora19 | ff      | 27      | false  |
    | 1.6.0_65 | fedora19 | ff      | 28      | false  |
    | 1.6.0_65 | fedora19 | ff      | 29      | false  |
    | 1.6.0_65 | fedora19 | ff      | 30      | false  |
    | 1.6.0_65 | fedora19 | ff      | 31      | false  |
    | 1.6.0_65 | fedora19 | ff      | 32      | false  |
    | 1.6.0_65 | fedora19 | ff      | 33      | false  |
    | 1.6.0_65 | fedora19 | ff      | 34      | false  |
    | 1.6.0_65 | fedora19 | ff      | 35      | false  |
    | 1.6.0_65 | fedora19 | ff      | 36      | false  |
    | 1.7.0_65 | fedora19 | ff      | 27      | false  |
    | 1.7.0_65 | fedora19 | ff      | 28      | true   |
    | 1.7.0_65 | fedora19 | ff      | 29      | true   |
    | 1.7.0_65 | fedora19 | ff      | 30      | true   |
    | 1.7.0_65 | fedora19 | ff      | 31      | true   |
    | 1.7.0_65 | fedora19 | ff      | 32      | true   |
    | 1.7.0_65 | fedora19 | ff      | 33      | true   |
    | 1.7.0_65 | fedora19 | ff      | 34      | true   |
    | 1.7.0_65 | fedora19 | ff      | 35      | true   |
    | 1.7.0_65 | fedora19 | ff      | 36      | false  |
    | 1.6.0_65 | fedora19 | chrome  | 34      | false  |
    | 1.6.0_65 | fedora19 | chrome  | 35      | false  |
    | 1.6.0_65 | fedora19 | chrome  | 36      | false  |
    | 1.6.0_65 | fedora19 | chrome  | 37      | false  |
    | 1.6.0_65 | fedora19 | chrome  | 38      | false  |
    | 1.6.0_65 | fedora19 | chrome  | 39      | false  |
    | 1.6.0_65 | fedora19 | chrome  | 40      | false  |

    | 1.6.0_65 | ubuntu12 | safari  | 5       | false  |
    | 1.6.0_65 | ubuntu12 | safari  | 6       | false  |
    | 1.6.0_65 | ubuntu12 | safari  | 7       | false  |
    | 1.6.0_65 | ubuntu12 | safari  | 8       | false  |
    | 1.6.0_65 | ubuntu12 | ff      | 27      | false  |
    | 1.6.0_65 | ubuntu12 | ff      | 28      | false  |
    | 1.6.0_65 | ubuntu12 | ff      | 29      | false  |
    | 1.6.0_65 | ubuntu12 | ff      | 30      | false  |
    | 1.6.0_65 | ubuntu12 | ff      | 31      | false  |
    | 1.6.0_65 | ubuntu12 | ff      | 32      | false  |
    | 1.6.0_65 | ubuntu12 | ff      | 33      | false  |
    | 1.6.0_65 | ubuntu12 | ff      | 34      | false  |
    | 1.6.0_65 | ubuntu12 | ff      | 35      | false  |
    | 1.6.0_65 | ubuntu12 | ff      | 36      | false  |
    | 1.7.0_65 | ubuntu12 | ff      | 27      | false  |
    | 1.7.0_65 | ubuntu12 | ff      | 28      | true   |
    | 1.7.0_65 | ubuntu12 | ff      | 29      | true   |
    | 1.7.0_65 | ubuntu12 | ff      | 30      | true   |
    | 1.7.0_65 | ubuntu12 | ff      | 31      | true   |
    | 1.7.0_65 | ubuntu12 | ff      | 32      | true   |
    | 1.7.0_65 | ubuntu12 | ff      | 33      | true   |
    | 1.7.0_65 | ubuntu12 | ff      | 34      | true   |
    | 1.7.0_65 | ubuntu12 | ff      | 35      | true   |
    | 1.7.0_65 | ubuntu12 | ff      | 36      | false  |
    | 1.6.0_65 | ubuntu12 | chrome  | 34      | false  |
    | 1.6.0_65 | ubuntu12 | chrome  | 35      | false  |
    | 1.6.0_65 | ubuntu12 | chrome  | 36      | false  |
    | 1.6.0_65 | ubuntu12 | chrome  | 37      | false  |
    | 1.6.0_65 | ubuntu12 | chrome  | 38      | false  |
    | 1.6.0_65 | ubuntu12 | chrome  | 39      | false  |
    | 1.6.0_65 | ubuntu12 | chrome  | 40      | false  |

  Scenario: PRC-1045 - Run check headless - JRE Version Fail
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
    And I fill in the hidden field "faux_jre_version" with "1.5.0_65"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the text "Fail"
    And I should not see the text "Passed"
    And I should see the text "Failed"

