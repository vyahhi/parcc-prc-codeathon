@api @trt @system_check
Feature: PRC-760 System Check - Unstructured - Form
  As an unstructured user
  I want to run a System Check
  so that I can determine whether a computer meets the minimum tech requirements to run a PARCC Test.

#  Acceptance Criteria
#  Given I am on the Technology Readiness page
#  When I click the System Check link
#  Then I see the system check page that has:
  Page headline:
  System Check
  Overview/ Instructional copy:
  Overview and instructional copy goes here. Consider explaining importance of running system check and how to do it: To prepare school for successful assessment, user can run system check to make sure device or devices meet PARCC minimum requirements. Include instructions that user can run test for on single device and apply the results to multiple devices with same configuration.
  Important Message:
  Important: If you are a school administrator, please run this check from your school readiness page. Contact your District Administrator to have the link to that page emailed to you.
  Copy:
  "* indicates required field"
#  Form Fields
#  Field Label	Instructions	Type	Dropdown Options	Required?	Other
#  System check name	Enter a name to describe the lab or device(s) you are testing.	Text field	N/A	No	–
#  Number of devices	Enter the number of devices with the same configuration to include in test results.	Text field	N/A	Yes	Numbers only
#  Device type	–	Dropdown	Select one (default); Desktop; Laptop; Netbook; Thin client; Tablet	Yes	–
#  Operating system	–	Dropdown	Select one (default); Apple iOS 6, 7, or 8; Chrome OS (Chromebook); Mac 10.8, 10.9 or 10.10; Windows 7; Windows 8; Windows 8.1; Other	Yes	–
#  Monitor size (in inches)	–	Text field	N/A	Yes	–
#  Processor speed	–	Text field	N/A	Yes	–
#  RAM	–	Text field	N/A	Yes	–
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
    And I should see the text "Monitor size \(in inches\)"
    And I should see the text "Processor speed"
    And I should see the text "RAM"
    And I should see an "Submit" button

    And I should not see the text "Monitor color depth"
    And I should not see the text "Screen resolution"
    And I should not see the text "Browser"
    And I should not see the checkbox "edit-field-browser-cookies-enabled-und"
    And I should not see the checkbox "edit-field-browser-javascript-enabled-und"
    And I should not see the checkbox "edit-field-browser-images-enabled-und"

  Scenario: PRC-800 Unstructured System Check form validation
    Given I am logged in as a user with the "Educator" role
    # TODO: Replace with actual TRT System Check form
    And I am on "admin/structure/entity-type/prc_trt/system_check/add"
    When I press "Submit"
    Then I should see the error message containing "Number of devices field is required."
    Then I should see the error message containing "Device type field is required."
    Then I should see the error message containing "Monitor size (in inches) field is required."
    Then I should see the error message containing "Processor speed field is required."
    Then I should see the error message containing "RAM field is required."
    When I fill in "Number of devices" with "Text"
    And I press "Submit"
    Then I should see the error message containing "Only numbers are allowed in Number of devices."
