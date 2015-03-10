@api @trt @structured @school
Feature: PRC-877 School Readiness - View System Check Results
  As a School, District or State Admin,
  I want to view detailed results for a system check
  so I can learn more about the device that was checked.

#  Given that I am logged in as a School, District or State Admin
#  And I am on a school readiness page
#  When I click the system check name link
#  Then I see the System Check Results page (see PRC-803)


  Scenario: Create default entities and nodes
    Given I am logged in as a user with the "School Admin" role
    And I have no "School" nodes
    And I have no entities of type "prc_trt" and bundle "system_check"
    And "School" nodes:
      | title                 |
      | School One @timestamp |
    And entities of type "prc_trt" and bundle "system_check":
      | created    | field_name | field_number_of_devices | field_device_type | field_operating_system | field_monitor_size | field_processor_speed | field_ram | field_monitor_color_depth | field_browser | field_browser_version | field_browser_cookies_enabled | field_browser_javascript_enabled | field_browser_images_enabled | field_screen_resolution_width | field_screen_resolution_height | field_ref_school            |
      | 1415932389 | Check AA   | 10                      | laptop            | win7                   | 17                 | 1                     | 1         | 24                        | ff            | 34                    | 1                             | 1                                | 1                            | 1027                          | 768                            | @nid[School One @timestamp] |
      | 1429932389 | Check BB   | 30                      | laptop            | win7                   | 17                 | 0                     | 1         | 24                        | ff            | 34                    | 1                             | 1                                | 1                            | 1027                          | 768                            | @nid[School One @timestamp] |
      | 1411932389 | Check CC   | 5                       | laptop            | win7                   | 17                 | 1                     | 1         | 24                        | ff            | 34                    | 1                             | 1                                | 1                            | 1027                          | 768                            | @nid[School One @timestamp] |
    And I visit the last node created
    When I click "Check AA"
    Then the url should match "prc_trt/system_check/*"
    And I should see the text "Check AA"
    And I should not see the text "Check BB"
    And I should see the text "School One @timestamp"