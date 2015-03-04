@api @trt @capacity_check
Feature: PRC-801 Testing Capacity Check - Unstructured - View Results
  As an unstructured user
  I want to view the results page of a Testing Capacity Check
  so that I can determine whether my school has the number of ready devices needed to successfully run the PARCC assessment.

#  Acceptance Criteria
#  Given I am on the Testing Capacity Check page
#  And my fields are valid
#  When I click the Submit button
#  Then the system performs calculations:
# # of devices required =[ (# of test-eligible students * # of sittings per student) / (# days of testing * # test sessions per day) ] *1.10
#  devices capacity = # of devices ready for assessment - # of devices required
#  bandwidth capacity = speed of connection / number of students in Mbps
#  Then I see the Testing Capacity Check Results page that has:
#  Page headline
#  Testing Capacity Check Results
#  Page subhead
#  Devices Capacity Results
#  Devices Capacity Results
#  If number positive: Passed
#  If number negative: Failed plus copy: "Instructions or next steps go here."
#  Inputs from Testing Capacity Check form
#  Number of students: <#>
#  Number of devices ready for assessment: <#>
#  Number of days of testing: <#>
#  Number of test sessions per day: <#>
#  Number of sittings per student: <#>
#  Devices Capacity formula
#  Number of assessment-ready devices <#> - Number of devices required <#>= Devices Capacity <#>
#  Page subhead
  Bandwidth Capacity Results
  Bandwidth Capacity Results
  • If result is .1+ Mbps/student, page displays "Good".
  • If result is .050-.99 Mbps/student, page displays "OK" and copy: "Provide explanation of what OK means and any next steps."
  • If result is under .05 Mbps/student, page displays "Poor" and copy: "Provide explanation of what poor means (will not be able to run successful assessment) and any next steps."
  Inputs from Testing Capacity Check form
  Network Connection: <Wired or Wireless>
  <Wired or Wireless> Connection Speed: <#>
  Number of Access Points: <#>
  Number of Students: <#>
  Speed of Connection: <#>


  Scenario: Complete a Capacity Check - calculation A
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT Capacity Check form
    And I am on "admin/structure/entity-type/prc_trt/capacity_check/add"
    When I fill in "Number of students" with "100"
    When I fill in "Number of devices ready for assessment" with "50"
    When I fill in "Number of days of testing" with "10"
    When I fill in "Number of test sessions per day" with "4"
    When I fill in "Number of sittings per student" with "4"
    When I fill in "Speed of connection (in Mbps)" with "500"
    When I fill in "Number of access points" with "600"
    And I press "Submit"
    And the ".field-devices-required" element should contain "11"
    And the ".field-devices-capacity" element should contain "39"
    And the ".field-bandwidth-capacity" element should contain "5 Mbps/student"
    And I should see the heading "Testing Capacity Check Results"
    And I should see the text "# of devices required"
    And I should see the text "devices capacity"
    And I should see the text "bandwidth capacity"
    And I should see the text "Devices Capacity Results"
    And I should not see the text "Failed"
    And I should see the text "Passed"
    And I should not see the text "Instructions or next steps go here."
    And I should see the text "Number of students:"
    And I should see the text "Number of devices ready for assessment:"
    And I should see the text "Number of sittings per student:"
    And I should see the text "Number of days of testing:"
    And I should see the text "Number of test sessions per day:"
    And the ".field-name-field-number-of-students" element should contain "100"
    And the ".field-name-field-number-of-devices" element should contain "50"
    And the ".field-name-field-sittings-per-student" element should contain "4"
    And the ".field-name-field-number-testing-days" element should contain "10"
    And the ".field-name-field-number-of-sessions" element should contain "4"

  Scenario: Complete a Capacity Check - calculation B
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT Capacity Check form
    And I am on "admin/structure/entity-type/prc_trt/capacity_check/add"
    When I fill in "Number of students" with "100"
    When I fill in "Number of devices ready for assessment" with "5"
    When I fill in "Number of days of testing" with "10"
    When I fill in "Number of test sessions per day" with "4"
    When I fill in "Number of sittings per student" with "4"
    When I fill in "Speed of connection (in Mbps)" with "500"
    When I fill in "Number of access points" with "600"
    And I press "Submit"
    And the ".field-devices-required" element should contain "11"
    And the ".field-devices-capacity" element should contain "-6"
    And the ".field-bandwidth-capacity" element should contain "5 Mbps/student"
    And I should see the heading "Testing Capacity Check Results"
    And I should see the text "# of devices required"
    And I should see the text "devices capacity"
    And I should see the text "bandwidth capacity"
    And I should see the text "Devices Capacity Results"
    And I should see the text "Failed"
    And I should not see the text "Passed"
    And I should see the text "Instructions or next steps go here."
    And I should see the text "Number of students:"
    And I should see the text "Number of devices ready for assessment:"
    And I should see the text "Number of sittings per student:"
    And I should see the text "Number of days of testing:"
    And I should see the text "Number of test sessions per day:"
    And the ".field-name-field-number-of-students" element should contain "100"
    And the ".field-name-field-number-of-devices" element should contain "5"
    And the ".field-name-field-sittings-per-student" element should contain "4"
    And the ".field-name-field-number-testing-days" element should contain "10"
    And the ".field-name-field-number-of-sessions" element should contain "4"

  Scenario: Complete a Capacity Check - Bandwidth Good
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT Capacity Check form
    And I am on "admin/structure/entity-type/prc_trt/capacity_check/add"
    When I fill in "Number of students" with "100"
    When I fill in "Number of devices ready for assessment" with "5"
    When I fill in "Number of days of testing" with "10"
    When I fill in "Number of test sessions per day" with "4"
    When I fill in "Number of sittings per student" with "4"
    When I fill in "Speed of connection (in Mbps)" with "500"
    When I fill in "Number of access points" with "600"
    And I press "Submit"
    And the ".field-devices-required" element should contain "11"
    And the ".field-devices-capacity" element should contain "-6"
    And the ".field-bandwidth-capacity" element should contain "5 Mbps/student"
    And I should see the heading "Testing Capacity Check Results"
    And I should see the text "# of devices required"
    And I should see the text "devices capacity"
    And I should see the text "bandwidth capacity"
    And I should see the text "Devices Capacity Results"
    And I should see the text "Failed"
    And I should not see the text "Passed"
    And I should see the text "Instructions or next steps go here."
    And I should see the text "Number of students:"
    And I should see the text "Number of devices ready for assessment:"
    And I should see the text "Number of sittings per student:"
    And I should see the text "Number of days of testing:"
    And I should see the text "Number of test sessions per day:"
    And the ".field-name-field-number-of-students" element should contain "100"
    And the ".field-name-field-number-of-devices" element should contain "5"
    And the ".field-name-field-sittings-per-student" element should contain "4"
    And the ".field-name-field-number-testing-days" element should contain "10"
    And the ".field-name-field-number-of-sessions" element should contain "4"
    And I should see the text "Good"
    And I should not see the text "OK"
    And I should not see the text "Poor"
    And I should not see the text "Provide explanation of what OK means and any next steps."
    And I should not see the text "Provide explanation of what poor means (will not be able to run successful assessment) and any next steps."

  Scenario: Complete a Capacity Check - Bandwidth OK
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT Capacity Check form
    And I am on "admin/structure/entity-type/prc_trt/capacity_check/add"
    When I fill in "Number of students" with "55"
    When I fill in "Number of devices ready for assessment" with "5"
    When I fill in "Number of days of testing" with "10"
    When I fill in "Number of test sessions per day" with "4"
    When I fill in "Number of sittings per student" with "4"
    When I fill in "Speed of connection (in Mbps)" with "5"
    When I fill in "Number of access points" with "600"
    And I press "Submit"
    And the ".field-devices-required" element should contain "6"
    And the ".field-devices-capacity" element should contain "-1"
    And the ".field-bandwidth-capacity" element should contain "0.090909090909091 Mbps/student"
    And I should see the heading "Testing Capacity Check Results"
    And I should see the text "# of devices required"
    And I should see the text "devices capacity"
    And I should see the text "bandwidth capacity"
    And I should see the text "Devices Capacity Results"
    And I should see the text "Failed"
    And I should not see the text "Passed"
    And I should see the text "Instructions or next steps go here."
    And I should see the text "Number of students:"
    And I should see the text "Number of devices ready for assessment:"
    And I should see the text "Number of sittings per student:"
    And I should see the text "Number of days of testing:"
    And I should see the text "Number of test sessions per day:"
    And the ".field-name-field-number-of-students" element should contain "55"
    And the ".field-name-field-number-of-devices" element should contain "5"
    And the ".field-name-field-sittings-per-student" element should contain "4"
    And the ".field-name-field-number-testing-days" element should contain "10"
    And the ".field-name-field-number-of-sessions" element should contain "4"
    And I should not see the text "Good"
    And I should see the text "OK"
    And I should not see the text "Poor"
    And I should see the text "Provide explanation of what OK means and any next steps."
    And I should not see the text "Provide explanation of what poor means (will not be able to run successful assessment) and any next steps."

  Scenario: Complete a Capacity Check - Bandwidth OK
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT Capacity Check form
    And I am on "admin/structure/entity-type/prc_trt/capacity_check/add"
    When I fill in "Number of students" with "55"
    When I fill in "Number of devices ready for assessment" with "5"
    When I fill in "Number of days of testing" with "10"
    When I fill in "Number of test sessions per day" with "4"
    When I fill in "Number of sittings per student" with "4"
    When I fill in "Speed of connection (in Mbps)" with "5"
    When I fill in "Number of access points" with "600"
    And I press "Submit"
    And the ".field-devices-required" element should contain "6"
    And the ".field-devices-capacity" element should contain "-1"
    And the ".field-bandwidth-capacity" element should contain "0.090909090909091 Mbps/student"
    And I should see the heading "Testing Capacity Check Results"
    And I should see the text "# of devices required"
    And I should see the text "devices capacity"
    And I should see the text "bandwidth capacity"
    And I should see the text "Devices Capacity Results"
    And I should see the text "Failed"
    And I should not see the text "Passed"
    And I should see the text "Instructions or next steps go here."
    And I should see the text "Number of students:"
    And I should see the text "Number of devices ready for assessment:"
    And I should see the text "Number of sittings per student:"
    And I should see the text "Number of days of testing:"
    And I should see the text "Number of test sessions per day:"
    And the ".field-name-field-number-of-students" element should contain "55"
    And the ".field-name-field-number-of-devices" element should contain "5"
    And the ".field-name-field-sittings-per-student" element should contain "4"
    And the ".field-name-field-number-testing-days" element should contain "10"
    And the ".field-name-field-number-of-sessions" element should contain "4"
    And I should not see the text "Good"
    And I should see the text "OK"
    And I should not see the text "Poor"
    And I should see the text "Provide explanation of what OK means and any next steps."
    And I should not see the text "Provide explanation of what poor means (will not be able to run successful assessment) and any next steps."

  Scenario: Complete a Capacity Check - Bandwidth Poor
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT Capacity Check form
    And I am on "admin/structure/entity-type/prc_trt/capacity_check/add"
    When I fill in "Number of students" with "100"
    When I fill in "Number of devices ready for assessment" with "5"
    When I fill in "Number of days of testing" with "10"
    When I fill in "Number of test sessions per day" with "4"
    When I fill in "Number of sittings per student" with "4"
    When I fill in "Speed of connection (in Mbps)" with "4"
    When I fill in "Number of access points" with "600"
    And I press "Submit"
    And the ".field-devices-required" element should contain "11"
    And the ".field-devices-capacity" element should contain "-6"
    And the ".field-bandwidth-capacity" element should contain "0.04 Mbps/student"
    And I should see the heading "Testing Capacity Check Results"
    And I should see the text "# of devices required"
    And I should see the text "devices capacity"
    And I should see the text "bandwidth capacity"
    And I should see the text "Devices Capacity Results"
    And I should see the text "Failed"
    And I should not see the text "Passed"
    And I should see the text "Instructions or next steps go here."
    And I should see the text "Number of students:"
    And I should see the text "Number of devices ready for assessment:"
    And I should see the text "Number of sittings per student:"
    And I should see the text "Number of days of testing:"
    And I should see the text "Number of test sessions per day:"
    And the ".field-name-field-number-of-students" element should contain "100"
    And the ".field-name-field-number-of-devices" element should contain "5"
    And the ".field-name-field-sittings-per-student" element should contain "4"
    And the ".field-name-field-number-testing-days" element should contain "10"
    And the ".field-name-field-number-of-sessions" element should contain "4"
    And I should not see the text "Good"
    And I should not see the text "OK"
    And I should see the text "Poor"
    And I should not see the text "Provide explanation of what OK means and any next steps."
    And I should see the text "Provide explanation of what poor means \(will not be able to run successful assessment\) and any next steps."

