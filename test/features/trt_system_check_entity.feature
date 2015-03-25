@api @trt @system_check
Feature: PRC-760 System Check - Unstructured - Form
  As an unstructured user
  I want to run a System Check
  so that I can determine whether a computer meets the minimum tech requirements to run a PARCC Test.

#  Acceptance Criteria
#  Given I am on the Technology Readiness page
#  When I click the System Check link
#  Then I see the system check page that has:
#  Page headline:
#  System Check
#  Overview/ Instructional copy:
#  Overview and instructional copy goes here. Consider explaining importance of running system check and how to do it: To prepare school for successful assessment, user can run system check to make sure device or devices meet PARCC minimum requirements. Include instructions that user can run test for on single device and apply the results to multiple devices with same configuration.
#  Important Message:
#  Important: If you are a school administrator, please run this check from your school readiness page. Contact your District Administrator to have the link to that page emailed to you.
#  Copy:
#  "* indicates required field"
#  Form Fields
#  Field Label	Instructions	Type	Dropdown Options	Required?	Other
#  System check name	Enter a name to describe the lab or device(s) you are testing.	Text field	N/A	No	–
#  Number of devices	Enter the number of devices with the same configuration to include in test results.	Text field	N/A	Yes	Numbers only
#  Device type	–	Dropdown	Select one (default); Desktop; Laptop; Netbook; Thin client; Tablet	Yes	–
#  Operating system	–	Dropdown	Select one (default); Apple iOS 6, 7, or 8; Chrome OS (Chromebook); Mac 10.8, 10.9 or 10.10; Windows 7; Windows 8; Windows 8.1; Other	Yes	–
#  Monitor size (in inches)	–	Text field	N/A	Yes	–
#  Processor speed	–	Dropdown	Select one (default); under 1 Ghz; 1 Ghz or greater"	Yes	–
#  RAM	–	Dropdown	under 1 GB; 1 GB or greater	Yes	–
#  Submit button

  Scenario: Create System Check - Unstructured
    Given I am logged in as a user with the "Educator" role
    # TODO: Replace with actual TRT System Check form
    When I am on "admin/structure/entity-type/prc_trt/system_check/add"
    Then I should see the text "System check name"
    And I should see the text "Enter a name to describe the lab or device\(s\) you are testing."
    And I should see the text "Number of devices"
    And I should see the text "Enter the number of devices with the same configuration to include in test results."
    And I should see the text "Device type"
    And I select "Desktop" from "Device type"
    And I select "Laptop" from "Device type"
    And I select "Netbook" from "Device type"
    And I select "Thin client" from "Device type"
    And I select "Tablet" from "Device type"
    And I should see the text "Operating system"

    # PRC-962 Changes tech options
    And I select "Android Lollipop" from "Operating system"
    And I select "Apple iOS 6, 7 or 8" from "Operating system"
    And I select "Chrome OS 35-39 (Chromebook)" from "Operating system"
    And I select "Fedora 19 or 20" from "Operating system"
    And I select "Mac 10.6" from "Operating system"
    And I select "Mac 10.7" from "Operating system"
    And I select "Mac 10.8" from "Operating system"
    And I select "Mac 10.9" from "Operating system"
    And I select "Mac 10.10" from "Operating system"
    And I select "Ubuntu 12.04 or 14.04" from "Operating system"
    And I select "Windows XP (SP 3)" from "Operating system"
    And I select "Windows Vista" from "Operating system"
    And I select "Windows 7" from "Operating system"
    And I select "Windows 8" from "Operating system"
    And I select "Windows 8.1" from "Operating system"
    And I select "Other" from "Operating system"

    And I should see the text "Monitor size \(in inches\)"
    And I should see the text "Processor speed"
    And I select "under 1 Ghz" from "Processor speed"
    And I select "1 Ghz or greater" from "Processor speed"
    And I should see the text "RAM"
    And I select "under 1 GB" from "RAM"
    And I select "1 GB or greater" from "RAM"
    And I should see an "Submit" button

    And I should not see the text "Monitor color depth"
    And I should not see the text "Screen resolution"
    And I should not see the text "Browser"
    And I should not see the checkbox "edit-field-browser-cookies-enabled-und"
    And I should not see the checkbox "edit-field-browser-javascript-enabled-und"
    And I should not see the checkbox "edit-field-browser-images-enabled-und"
    And I should not see the text "School"
    And I should not see the text "Result"

  Scenario: PRC-800 Unstructured System Check form validation
    Given I am logged in as a user with the "Educator" role
    # TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    When I press "Submit"
    Then I should not see the error message containing "System check name field is required."
    Then I should see the error message containing "Number of devices field is required."
    Then I should see the error message containing "Device type field is required."
    Then I should see the error message containing "Operating system field is required."
    Then I should see the error message containing "Monitor size (in inches) field is required."
    Then I should see the error message containing "Processor speed field is required."
    Then I should see the error message containing "RAM field is required."
    When I fill in "Number of devices" with "Text"
    And I fill in "Monitor size (in inches)" with "Text"
    And I press "Submit"
    Then I should see the error message containing "Only numbers are allowed in Number of devices."
    Then I should see the error message containing "Only numbers and the decimal separator (.) allowed in Monitor size (in inches)."

  Scenario: PRC-955 Limit number of devices
    Given I am logged in as a user with the "Educator" role
    # TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "3453453453"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "3453453453"
    And I select "1 Ghz or greater" from "Processor speed"
    And I select "1 GB or greater" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"
    Then I should see the error message containing "Number of devices: the value may be no greater than 32676."
    Then I should see the error message containing "Monitor size (in inches): the value may be no greater than 32676."

  Scenario: PRC-760 Page text
    Given I am logged in as a user with the "Educator" role
    # TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    Then I should see the heading "System Check"
    And I should see the text "Overview and instructional copy goes here."
    And I should see the text "Important: If you are a school administrator, please run this check from your school readiness page. Contact your District Administrator to have the link to that page emailed to you."
    And I should see the text "\* indicates required field"