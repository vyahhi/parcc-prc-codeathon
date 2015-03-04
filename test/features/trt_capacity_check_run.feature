@api @trt @capacity_check
Feature: PRC-806 Testing Capacity Check - Structured - View Results
  As a school admin
  I want to view the results page of a Testing Capacity Check
  so that I can determine whether my school has the number of ready devices needed to successfully run the PARCC assessment.

#  Acceptance Criteria
#  Given I am logged in as a school admin
#  And I am on my school Testing Capacity Check page
#  And my fields are valid
#  When I click the Submit button
#  Then the system performs calculations:
# # of devices required =[ (# of test-eligible students * # of sittings per student) / (# days of testing * # test sessions per day) ] *1.10
  devices capacity = # of devices ready for assessment - # of devices required
  bandwidth capacity = speed of connection / number of students in Mbps
  And I see the Testing Capacity Check Results page that has:
  Page headline
  Testing Capacity Check Results
  School
  School: <School name>
  Page subhead
  Devices Capacity Results
  Devices Capacity Results
  If number positive: Passed
  If number negative: Failed plus copy: "Instructions or next steps go here."
  Inputs from Testing Capacity Check form
  Number of students: <#>
  Number of devices ready for assessment: <#>
  Number of days of testing: <#>
  Number of test sessions per day: <#>
  Number of sittings per student: <#>
  Devices Capacity formula
  Number of assessment-ready devices <#> - Number of devices required = Devices Capacity <#>
  Page subhead
  Bandwidth Capacity Results
  Devices Capacity Results
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
    Then I should see the text "11"
    And I should see the text "39"
    And I should see the text "5 Mbps/student"
