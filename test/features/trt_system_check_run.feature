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
  • Monitor color depth
  • Screen resolution
#  • Browser
  • Browser: Cookies enabled
  • Browser: JavaScript enabled
  • Browser: Images enabled
#  Then I see the System Check Results page that has:
  Page headline
  System Check
  Results
  If all tested areas passed: Passed
  If any tested area failed: Failed plus copy: "Instructions or next steps go here. Consider linking to PARCC minimum requirements."
  System Check Name and Number of Devices
#  System Check: <System check name>
#  Number of devices: <#>
  Results table
  Area	System Details	Results	Pass requirement
#  Device type	<Device type>	N/A
#  Operating system	<Operating system>	<Passed or Failed>	Any option besides "other" selected from Operating system dropdown on System Check page
  Monitor size (in inches)	<Monitor size> inch	<Passed or Failed>	9.7 inch or better
  Monitor color depth	<Monitor color depth>	<Passed or Failed>	16 Bit or better
  Screen resolution	<Screen resolution>	<Passed or Failed>	1024 x 768 or higher
  Processor speed	<Processor speed>	<Passed or Failed>	1 Ghz or faster
  RAM	<RAM>	<Passed or Failed>	1 GB or greater
  Browser	<Browser>	<Passed or Failed>	See charts PARCC PRC Browser Requirements by OS.docx
  Browser: Cookies enabled	<Yes or No>	<Passed or Failed>	Cookies enabled
  Browser: JavaScript enabled	<Yes or No>	<Passed or Failed>	JavaScript enabled
  Browser: Images enabled	<Yes or No>	<Passed or Failed>	Images enabled
  Additional Consideration
  If Java Script not enabled, "Failed" message appears and for each area system detects "Failed" appears

  Scenario: Run check
    Given I am logged in as a user with the "Educator" role
    # TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 1"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I fill in "Processor speed" with "45"
    And I fill in "RAM" with "16GB"
    When I press "Submit"
    Then I should see the text "System check name:"
    And I should see the text "Check 1"
    And I should see the text "Number of devices:"
    And I should see the text "23"
    And I should see the text "Device type:"
    And I should see the text "Desktop"
    And I should see the text "Operating system:"
    And I should see the text "Windows 7"
    And I should see the text "Monitor size \(in inches\):"
    And I should see the text "17"
    And I should see the text "Processor speed:"
    And I should see the text "45"
    And I should see the text "RAM:"
    And I should see the text "16GB"
    And I should see the text "Browser:"
    And I should see the text "other"
