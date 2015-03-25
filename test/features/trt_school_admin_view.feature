@api @trt @structured @school @capacity_check
Feature: PRC-757 School Readiness - School Admin View
  As a School Admin,
  I want to be able to run structured readiness checks and see the results of the structured readiness checks I have run
  so that I can understand if my school is ready to run a PARCC assessment test.
#  Scenario 3: I have run a Testing Capacity Check
#  Number of students
#  Number of students: <number of students> above Testing capacity checks subhead

  Scenario: Seeing my schools on the TRT Page
    Given I have no "School" nodes
    And "School" nodes:
      | title        |
      | School One   |
      | School Two   |
      | School Three |
    And I am logged in as a user with the "School Admin" role
    When I follow "Technology Readiness"
    Then I should see the link "School One"
    And I should see the link "School Two"
    And I should see the link "School Three"
    And I should see the text "Summary of what user can do here view readiness by school, run readiness checks, view readiness check results."

  Scenario: School readiness page
    Given I have no "School" nodes
    And "School" nodes:
      | title        |
      | School One   |
      | School Two   |
      | School Three |
    And I am logged in as a user with the "School Admin" role
    And I follow "Technology Readiness"
    When I click "School One"
    Then I should see the heading "School One Readiness"
    And I should see the text "Testing capacity checks"
    And I should see the text "System checks"
    And I should see the text "no system checks have been run"
    And I should see the text "message explaining what the check does and the importance of running it."
    And I should see the link "run"
    And I should see the link "run system check"

  Scenario Outline: Run a capacity check
    Given I have no "School" nodes
    And "School" nodes:
      | title      |
      | School One |
    And I am logged in as a user with the "School Admin" role
    And I follow "Technology Readiness"
    When I click "School One"
    Then I should not see the text "Devices capacity"
    And I should not see the text "Bandwidth capacity"
    And I should not see the text "Number of students"
    When I click "run"
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
    When I visit the last node created
    # PRC-1000
    Then I should see the text "Bandwidth Capacity Results"
    And I should see the text "<bandwidth_result> - 0.5 Mbps/student"
    And I should see the text "Devices Capacity Results"
    And I should see the text "<device_result>"
    # PRC-999
    And I should see the link "run testing capacity check"
    And I should see the text "Number of students:"
    And I should see the text "100"
  Examples:
    | students | devices | sittings | testing_days | sessions | connection_type | wired_speed | access_points | connection_speed | devices_required | devices_capacity | bandwidth_capacity | device_result | device_not_result | device_follow_up | device_not_follow_up                | bandwidth_result | bandwidth_not_result1 | bandwidth_not_result2 | bandwidth_text_result | bandwidth_text_not_result1                               | bandwidth_text_not_result2                                                                                   |
    | 100      | 50      | 4        | 10           | 4        | Wired           | 100 Mbps    | 600           | 50               | 11               | 39               | 5                  | Passed        | Failed            |                  | Instructions or next steps go here. | Good             | OK                    | Poor                  | Good                  | Provide explanation of what OK means and any next steps. | Provide explanation of what poor means \(will not be able to run successful assessment\) and any next steps. |

  Scenario: PRC-804 Structured form validation
    Given I have no "School" nodes
    And "School" nodes:
      | title      |
      | School One |
    And I am logged in as a user with the "School Admin" role
    And I follow "Technology Readiness"
    When I click "School One"
    And I should see the text "System checks"
    And I should see the text "no system checks have been run"
    And I should see the text "message explaining what the check does and the importance of running it."
    When I click "run system check"
    # PRC-802
    And I should not see the text "Important:"
    And I press "Submit"
    # PRC-802
    Then I should see the error message containing "System check name field is required."

  Scenario: I have a system check
    Given I have no "School" nodes
    And "School" nodes:
      | title      |
      | School One |
    And I am logged in as a user with the "School Admin" role
    And I follow "Technology Readiness"
    When I click "School One"
    And I should see the text "System checks"
    And I should see the text "no system checks have been run"
    And I should see the text "message explaining what the check does and the importance of running it."
    When I click "run system check"
    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
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
    And I visit the last node created
    Then I should see the link "System Check"
    And I should see the link "Date & Time"
    And I should see the link "Number of Devices"
    And I should see the link "Results"

  Scenario Outline: PRC-939 School admin only sees own schools
    Given I am logged in as a user with the "District Admin" role
    And users:
      | name   | mail               | pass   | field_first_name | field_last_name | status | roles                  |
      | First  | <user_name>        | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
      | Second | <second_user_name> | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
    And "School" nodes:
      | title                    | field_contact_email | uid         |
      | School 939 S1 @timestamp | <user_name>         | @currentuid |
      | School 939 S2 @timestamp | <user_name>         | @currentuid |
      | School 939 S3 @timestamp | <second_user_name>  | @currentuid |
    And I am an anonymous user
    And I am logged in as "First"
    And I click "Technology Readiness"
    Then I should see the link "School 939 S1 @timestamp Readiness"
    And I should see the link "School 939 S2 @timestamp Readiness"
    And I should not see the text "School 939 S3 @timestamp Readiness"
  Examples:
    | user_name                          | second_user_name                      |
    | joe_prc_960a@timestamp@example.com | second_prc_960b@timestamp@example.com |
