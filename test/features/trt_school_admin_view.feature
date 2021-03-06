@api @trt @structured @school @capacity_check @prc-757 @prc-1051 @prc-1000 @prc-999 @prc-802 @prc-1270
Feature: PRC-757 School Readiness - School Admin View
  As a School Admin,
  I want to be able to run structured readiness checks and see the results of the structured readiness checks I have run
  so that I can understand if my school is ready to run a PARCC assessment test.
#  Scenario 3: I have run a Testing Capacity Check
#  Number of students
#  Number of students: <number of students> above Testing capacity checks subhead
  # PRC-1270 changes Check - Result to Check: Result

  Scenario: Seeing my schools on the TRT Page
    Given I have no "School" nodes
    And users:
      | name                     | mail                     | pass   | field_first_name | field_last_name | status | roles                  |
      | a-@timestamp@example.com | a-@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
    And "School" nodes:
      | title        | field_contact_email      |
      | School One   | a-@timestamp@example.com |
      | School Two   | a-@timestamp@example.com |
      | School Three | a-@timestamp@example.com |
      | School Four  |                          |
#    And I am logged in as a user with the "School Admin" role
    And I am logged in as "a-@timestamp@example.com"
    When I visit "assessments/technology-readiness"
    Then I should see the link "School One"
    And I should see the link "School Two"
    And I should see the link "School Three"
    And I should not see the link "School Four"
    And I should see the text "Click the link above to access and manage school data and readiness reports. Also run testing capacity and system checks for this school."
    And I should see the text "For more information on the TRT, please refer to the online tutorial found in the professional learning section of this site."
    And I should see the text "Each year, after July 31, but before August 15, the checks and reports in this system will be retired and not accessible to users. Please download your reports for your archives before July 31 of each year."

  Scenario: School readiness page
    Given I have no "School" nodes
    And users:
      | name                     | mail                     | pass   | field_first_name | field_last_name | status | roles                  |
      | a-@timestamp@example.com | a-@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
    And "School" nodes:
      | title        | field_contact_email      |
      | School One   | a-@timestamp@example.com |
      | School Two   | a-@timestamp@example.com |
      | School Three | a-@timestamp@example.com |
    And I am logged in as "a-@timestamp@example.com"
    And I visit "assessments/technology-readiness"
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
    And users:
      | name                     | mail                     | pass   | field_first_name | field_last_name | status | roles                  |
      | a-@timestamp@example.com | a-@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
    And "School" nodes:
      | title      | field_contact_email      |
      | School One | a-@timestamp@example.com |
    And I am logged in as "a-@timestamp@example.com"
    And I visit "assessments/technology-readiness"
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
    And I should see the text "<bandwidth_result>: 0.5 Mbps/student"
    And I should see the text "Devices Capacity Results"
    And I should see the text "<device_result>"
    # PRC-999
    And I should see the link "run testing capacity check"
    And I should see the text "Number of students:"
    And I should see the text "100"
    # Change text for PRC-1051
  Examples:
    | students | devices | sittings | testing_days | sessions | connection_type | wired_speed | access_points | connection_speed | devices_required | devices_capacity | bandwidth_capacity | device_result | device_not_result | device_follow_up | device_not_follow_up                | bandwidth_result     | bandwidth_not_result1                       | bandwidth_not_result2 | bandwidth_text_result | bandwidth_text_not_result1                                                                        | bandwidth_text_not_result2                                                                                   |
    | 100      | 50      | 4        | 10           | 4        | Wired           | 100 Mbps    | 600           | 50               | 11               | 39               | 5                  | Passed        | Failed            |                  | Instructions or next steps go here. | Exceeds Requirements | Meets Minimum Requirements (for no Caching) | Requires Test Caching | Exceeds Requirements  | Provide explanation of what Meets Minimum Requirements (for no Caching) means and any next steps. | Provide explanation of what Requires Test Caching means (will not be able to run successful assessment) and any next steps. |

  Scenario: PRC-804 Structured form validation
    Given I have no "School" nodes
    And users:
      | name                     | mail                     | pass   | field_first_name | field_last_name | status | roles                  |
      | a-@timestamp@example.com | a-@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
    And "School" nodes:
      | title      | field_contact_email      |
      | School One | a-@timestamp@example.com |
    And I am logged in as "a-@timestamp@example.com"
    And I visit "assessments/technology-readiness"
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
    And users:
      | name                     | mail                     | pass   | field_first_name | field_last_name | status | roles                  |
      | a-@timestamp@example.com | a-@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
    And "School" nodes:
      | title      | field_contact_email      |
      | School One | a-@timestamp@example.com |
    And I am logged in as "a-@timestamp@example.com"
    And I visit "assessments/technology-readiness"
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
    And I select "At least 1.5 Ghz and under 2 Ghz" from "Processor speed"
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
    And I visit "assessments/technology-readiness"
    Then I should see the link "School 939 S1 @timestamp Readiness"
    And I should see the link "School 939 S2 @timestamp Readiness"
    And I should not see the text "School 939 S3 @timestamp Readiness"
  Examples:
    | user_name                          | second_user_name                      |
    | joe_prc_960a@timestamp@example.com | second_prc_960b@timestamp@example.com |
