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
#  Bandwidth Capacity Results
#  Bandwidth Capacity Results
#  • If result is .1+ Mbps/student, page displays "Good".
#  • If result is .050-.99 Mbps/student, page displays "OK" and copy: "Provide explanation of what OK means and any next steps."
#  • If result is under .05 Mbps/student, page displays "Poor" and copy: "Provide explanation of what poor means (will not be able to run successful assessment) and any next steps."
#  Inputs from Testing Capacity Check form
#  Network connection: <Wired or Wireless>
#  <Wired or Wireless> connection speed: <#>
#  Number of access points: <#>
#  Number of students: <#>
#  Speed of connection: <#>

  Scenario Outline: Complete a Capacity Check
    Given I am logged in as a user with the "Educator" role
# TODO: Replace with actual TRT Capacity Check form
    And I am on "admin/structure/entity-type/prc_trt/capacity_check/add"
    When I fill in "Number of students" with "<students>"
    When I fill in "Number of devices ready for assessment" with "<devices>"
    When I fill in "Number of days of testing" with "<testing_days>"
    When I fill in "Number of test sessions per day" with "<sessions>"
    When I fill in "Number of sittings per student" with "<sittings>"
    When I fill in "Speed of connection (in Mbps)" with "<connection_speed>"
    When I fill in "Number of access points" with "<access_points>"
    And I select "<connection_type>" from "Network connection"
    And I select "<wired_speed>" from "Wired connection speed"
    And I press "Submit"
    And the ".field-devices-required" element should contain "<devices_required>"
    And the ".field-devices-capacity" element should contain "<devices_capacity>"
    And the ".field-bandwidth-capacity" element should contain "<bandwidth_capacity> Mbps/student"
    And I should see the heading "Testing Capacity Check Results"
    And I should see the text "# of devices required"
    And I should see the text "devices capacity"
    And I should see the text "bandwidth capacity"
    And I should see the text "Devices Capacity Results"
    And I should not see the text "<device_not_result>"
    And I should see the text "<device_result>"
    And I should see the text "<device_follow_up>"
    And I should not see the text "<device_not_follow_up>"
    And I should see the text "Number of students:"
    And I should see the text "Number of devices ready for assessment:"
    And I should see the text "Number of sittings per student:"
    And I should see the text "Number of days of testing:"
    And I should see the text "Number of test sessions per day:"
    And I should see the text "Network connection:"
    And I should see the text "Wired connection speed:"
    And I should see the text "Number of access points:"
    And I should see the text "Speed of connection \(in Mbps\):"
    And the ".field-name-field-number-of-students" element should contain "<students>"
    And the ".field-name-field-number-of-devices" element should contain "<devices>"
    And the ".field-name-field-sittings-per-student" element should contain "<sittings>"
    And the ".field-name-field-number-testing-days" element should contain "<testing_days>"
    And the ".field-name-field-number-of-sessions" element should contain "<sessions>"
    And the ".field-name-field-network-connection-type" element should contain "<connection_type>"
    And the ".field-name-field-wired-connection-speed" element should contain "<wired_speed>"
    And the ".field-name-field-number-of-access-points" element should contain "<access_points>"
    And the ".field-name-field-speed-of-connection" element should contain "<connection_speed>"
    And I should see the text "<bandwidth_result>"
    And I should not see the text "<bandwidth_not_result1>"
    And I should not see the text "<bandwidth_not_result2>"
    And I should see the text "<bandwidth_text_result>"
    And I should not see the text "<bandwidth_text_not_result1>"
    And I should not see the text "<bandwidth_text_not_result2>"

  Examples:
    | students | devices | sittings | testing_days | sessions | connection_type | wired_speed | access_points | connection_speed | devices_required | devices_capacity | bandwidth_capacity | device_result | device_not_result | device_follow_up                    | device_not_follow_up                | bandwidth_result | bandwidth_not_result1 | bandwidth_not_result2 | bandwidth_text_result                                                                                        | bandwidth_text_not_result1                               | bandwidth_text_not_result2                                                                                   |
    | 100      | 50      | 4        | 10           | 4        | Wired           | 100 Mbps    | 600           | 50               | 11               | 39               | 5                  | Passed        | Failed            |                                     | Instructions or next steps go here. | Good             | OK                    | Poor                  | Good                                                                                                         | Provide explanation of what OK means and any next steps. | Provide explanation of what poor means \(will not be able to run successful assessment\) and any next steps. |
    | 100      | 5       | 4        | 10           | 4        | Wired           | 100 Mbps    | 600           | 500              | 11               | -6               | 5                  | Failed        | Passed            | Instructions or next steps go here. | Can't be blank                      | Good             | OK                    | Poor                  | Good                                                                                                         | Provide explanation of what OK means and any next steps. | Provide explanation of what poor means \(will not be able to run successful assessment\) and any next steps. |
    | 55       | 5       | 4        | 10           | 4        | Wired           | 100 Mbps    | 600           | 5                | 6                | -1               | 0.090909090909091  | Failed        | Passed            | Instructions or next steps go here. | Can't be blank                      | OK               | Good                  | Poor                  | Provide explanation of what OK means and any next steps.                                                     | Good                                                     | Provide explanation of what poor means \(will not be able to run successful assessment\) and any next steps. |
    | 100      | 5       | 4        | 10           | 4        | Wired           | 100 Mbps    | 600           | 4                | 11               | -6               | 0.04               | Failed        | Passed            | Instructions or next steps go here. | Can't be blank                      | Poor             | Good                  | OK                    | Provide explanation of what poor means \(will not be able to run successful assessment\) and any next steps. | Good                                                     | Provide explanation of what OK means and any next steps.                                                     |




