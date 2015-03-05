@api @trt @capacity_check
Feature: PRC-761 Testing Capacity Check - Unstructured - Form
  As an unstructured user
  I want to run a Testing Capacity Check
  so that I can determine whether my school has the number of ready devices needed to successfully run the PARCC assessment.

#  Acceptance Criteria
#  Given that I am on the Technology Readiness page
#  When I click the Testing Capacity Check link
#  Then I see the testing capacity check page that has:
  Page headline:
  Testing Capacity Check
  Overview/ Instructional copy:
  Instructions go here. For example: To determine if your school has the appropriate number of test-ready devices to run a successful assessment, enter information requested below.
  Important Message:
  Important: If you are a school administrator, please run this check from your school readiness page. Contact your District Administrator to have the link to that page emailed to you.
  Copy:
  "* indicates required field"
#  Form Fields
#  Field Label	Instructions	Type	Options	Required?	Other
  Number of students
  Enter the number of test-eligible students at your school.	Text field	N/A	Yes	Numbers only
  Number of devices ready for assessment
  Enter the number of devices that meet PARCC's minimum requirements.	Text field	N/A	Yes	Numbers only
  Number of days of testing
  Enter the number of days over which the assessment testing will take place.	Text field	N/A	Yes	Numbers only
  Number of test sessions per day
  Enter the number of test sessions for each day of testing at your school.	Text field	N/A	Yes	Numbers only
  Number of sittings per student
  Enter the number of sittings for each student at your school.	Text field	N/A	Yes	Numbers only
  Speed of connection (in Mbps)
  Enter the speed of your school's connection to the network.	Text field	N/A	Yes	Numbers only
  Network connection	–	Radio buttons	Wired; Wireless	No	Selection reveals another set of radio buttons
  Wired connection speed
  Enter the speed of your school's wired connection.	Radio buttons	10 Mbps; 100 Mbps; 1000 Mbps (1 Gbps)	No	Selection revealed is user selects Network connection: Wired radio button
  Wireless connection speed
  Enter the speed of your school's wireless connection.	Radio buttons	11 Mbps; 54 Mbps; 300 Mbps; 1000 Mbps (1 Gbps)	No	Selection revealed is user selects Network connection: Wireless radio button
  Number of access points
  Enter the number of access points to the network.	Text field	N/A	No	Numbers only
  Submit button

  Scenario: Create Capacity Check - Unstructured
    Given I am logged in as a user with the "Educator" role
    # TODO: Replace with actual TRT Capacity Check form
    And I am on "admin/structure/entity-type/prc_trt/capacity_check/add"
    Then I should see the text "Number of students"
    And I should see the text "Enter the number of test-eligible students at your school."
    Then I should see the text "Number of devices ready for assessment"
    And I should see the text "Enter the number of devices that meet PARCC's minimum requirements."
    Then I should see the text "Number of days of testing"
    And I should see the text "Enter the number of days over which the assessment testing will take place."
    Then I should see the text "Number of test sessions per day"
    And I should see the text "Enter the number of test sessions for each day of testing at your school."
    And I should see the text "Number of sittings per student"
    And I should see the text "Enter the number of sittings for each student at your school."
    Then I should see the text "Speed of connection \(in Mbps\)"
    And I should see the text "Enter the speed of your school's connection to the network."
    Then I should see the text "Network connection"
    And I select "Please select" from "Network connection"
    And I select "Wired" from "Network connection"
    And I select "Wireless" from "Network connection"
    Then I should see the text "Wired connection speed"
    And I should see the text "Enter the speed of your school's wired connection."
    And I select "Please select" from "Wired connection speed"
    And I select "10 Mbps" from "Wired connection speed"
    And I select "100 Mbps" from "Wired connection speed"
    And I select "1000 Mbps (1 Gbps)" from "Wired connection speed"
    Then I should see the text "Wireless connection speed"
    And I should see the text "Enter the speed of your school's wireless connection."
    And I select "Please select" from "Wireless connection speed"
    And I select "11 Mbps" from "Wireless connection speed"
    And I select "54 Mbps" from "Wireless connection speed"
    And I select "300 Mbps" from "Wireless connection speed"
    And I select "1000 Mbps (1 Gbps)" from "Wireless connection speed"
    Then I should see the text "Number of access points"
    And I should see the text "Enter the number of access points to the network."
    And I should see an "Submit" button

  @javascript
  Scenario: Wired or Wireless connection states
    Given I am logged in as a user with the "Educator" role
    # TODO: Replace with actual TRT Capacity Check form
    And I am on "admin/structure/entity-type/prc_trt/capacity_check/add"
    Then "#edit-field-wired-connection-speed-und" should not be visible
    And "#edit-field-wireless-connection-speed-und" should not be visible
    Then I select "Wired" from "Network connection"
    Then "#edit-field-wired-connection-speed-und" should be visible
    And "#edit-field-wireless-connection-speed-und" should not be visible
    Then I select "Wireless" from "Network connection"
    Then "#edit-field-wired-connection-speed-und" should not be visible
    And "#edit-field-wireless-connection-speed-und" should be visible
    Then I select "Wired" from "Network connection"
    Then "#edit-field-wired-connection-speed-und" should be visible
    And "#edit-field-wireless-connection-speed-und" should not be visible

  Scenario: PRC-799 Testing Capacity Check - Unstructured - Form Validation
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT Capacity Check form
    And I am on "admin/structure/entity-type/prc_trt/capacity_check/add"
    When I press "Submit"
    Then I should see the error message containing "Number of students field is required."
    Then I should see the error message containing "Number of devices ready for assessment field is required."
    Then I should see the error message containing "Number of days of testing field is required."
    Then I should see the error message containing "Number of test sessions per day field is required."
    Then I should see the error message containing "Number of sittings per student field is required."
    Then I should see the error message containing "Speed of connection (in Mbps) field is required."

    When I fill in "Number of students" with "A"
    When I fill in "Number of devices ready for assessment" with "A"
    When I fill in "Number of days of testing" with "A"
    When I fill in "Number of test sessions per day" with "A"
    When I fill in "Number of sittings per student" with "A"
    When I fill in "Speed of connection (in Mbps)" with "A"
    When I fill in "Number of access points" with "A"
    And I press "Submit"
    Then I should see the error message containing "Only numbers are allowed in Number of students."
    Then I should see the error message containing "Only numbers are allowed in Number of devices ready for assessment."
    Then I should see the error message containing "Only numbers are allowed in Number of days of testing."
    Then I should see the error message containing "Only numbers are allowed in Number of test sessions per day."
    Then I should see the error message containing "Only numbers are allowed in Number of sittings per student."
    Then I should see the error message containing "Only numbers are allowed in Speed of connection (in Mbps)."
    Then I should see the error message containing "Only numbers are allowed in Number of access points."
