@api @trt @structured @school @capacity_check @prc-805 @prc-1051
Feature: PRC-805 Testing Capacity Check - Structured - Form
  As a school admin
  I want to run a Testing Capacity check
  so that I can determine whether my school has the number of ready devices needed to successfully run the PARCC assessment.

#  Acceptance Criteria
#  Given I am logged in as a school admin
#  And I am on my School Readiness page
#  When I click the Run Testing Capacity Check link
#  Then I see the Testing Capacity Check page that has:
#  Differences from Testing Capacity Check - Unstructured - Form (PRC-761)
#  Important Message does not display
#  Number of students text field is prepopulated if a previous testing capacity check has been successfully run for school

  Scenario: Important message does not display
    Given users:
      | name                    | mail                   | pass    | field_first_name | field_last_name | status | roles                  |
      | schooladmin@example.com | schooladmin@example.com | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
    And I am logged in as "schooladmin@example.com"
    And I have no "School" nodes
    And I have no entities of type "prc_trt" and bundle "system_check"
    And "School" nodes:
      | title                 | field_contact_email     |
      | School One @timestamp | schooladmin@example.com |
    And I visit the last node created
    And I click "run system check"
    And I should not see the text "Important"

    @javascript
  Scenario Outline: Number of students is pre-populated
    Given users:
      | name                    | mail                   | pass    | field_first_name | field_last_name | status | roles                  |
      | schooladmin@example.com | schooladmin@example.com | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
    And I am logged in as "schooladmin@example.com"
    And I have no "School" nodes
    And I have no entities of type "prc_trt" and bundle "system_check"
    And "School" nodes:
      | title                 | field_number_of_students | field_contact_email     |
      | School One @timestamp | <students>               | schooladmin@example.com |
    And I visit the last node created
    And I click "run testing capacity check"
    # PRC-953
    Then I should see the text "To prepare school for a successful assessment implementation, a TRT School admin can run a testing capacity check to make sure the device or devices meets"
    And I should see the link "PARCC minimum technology requirements"
    Then I should not see the text "Important: If you are a school administrator, please run this check from your school readiness page. Contact your District Administrator to have the link to that page emailed to you."
    And I should see the text "\* indicates required field"
    Then the "Number of students" field should contain "<students>"
    When I fill in "Number of students" with "<devices>"
    When I fill in "Number of devices ready for assessment" with "<devices>"
    When I fill in "Number of days of testing" with "<testing_days>"
    When I fill in "Number of test sessions per day" with "<sessions>"
    When I fill in "Number of sittings per student" with "<sittings>"
    When I fill in "Speed of connection (in Mbps)" with "<connection_speed>"
    When I fill in "Number of access points" with "<access_points>"
    And I select "<connection_type>" from "Network connection"
    And I select "<wired_speed>" from "Wired connection speed"
    And I press "Submit"
    # PRC-806
    Then I should see the text "School:"
    And I should see the text "School One @timestamp"
    And I visit the last node created
    And I click "run testing capacity check"
    Then the "Number of students" field should contain "<devices>"
    # Change text for PRC-1051
  Examples:
    | students | devices | sittings | testing_days | sessions | connection_type | wired_speed | access_points | connection_speed | devices_required | devices_capacity | bandwidth_capacity | device_result | device_not_result | device_follow_up | device_not_follow_up                | bandwidth_result     | bandwidth_not_result1                       | bandwidth_not_result2 | bandwidth_text_result | bandwidth_text_not_result1                                                                        | bandwidth_text_not_result2                                                                                                  |
    | 100      | 50      | 4        | 10           | 4        | Wired           | 100 Mbps    | 600           | 50               | 11               | 39               | 5                  | Passed        | Failed            |                  | Instructions or next steps go here. | Exceeds Requirements | Meets Minimum Requirements (for no Caching) | Requires Test Caching | Exceeds Requirements  | Provide explanation of what Meets Minimum Requirements (for no Caching) means and any next steps. | Provide explanation of what Requires Test Caching means (will not be able to run successful assessment) and any next steps. |
