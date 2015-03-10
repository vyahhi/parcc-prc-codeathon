@api @trt @structured @school
Feature: PRC-876 School Readiness - Sort System Check Results
  As a School, District or State Admin,
  I want to sort the list of schools on my District Readiness page
  so that I can find the information that I want.

#  Given that I am logged in as a School, District or State Admin
#  And I am on a School Readiness page (see PRC-757)
#  When I click on the column headers in the System Checks table
#  Then I see:
#  Scenario 1: System Check column header
#  System Check Names in alphabetic order
#  System Check Names in reverse alphabetic order (second click)
#  Scenario 2: Date & Time column header
#  Date in chronological order
#  Date in reverse chronological order (second click, default is reverse chronological order)
#  Scenario 3: Number of Devices column header
#  Number from largest to smallest
#  Number from smallest to largest (second click)
#  Scenario 4: Results column header
#  Results in alphabetical order
#  Results in reverse alphabetical order (second click)

  # Also covers PRC-810

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
    Then "Check BB" should precede "Check AA" for the query ".views-field-field-name"
    Then "Check AA" should precede "Check CC" for the query ".views-field-field-name"

    When I click "Date & Time"
    Then "Check CC" should precede "Check AA" for the query ".views-field-field-name"
    Then "Check AA" should precede "Check BB" for the query ".views-field-field-name"
    When I click "Date & Time"
    Then "Check BB" should precede "Check AA" for the query ".views-field-field-name"
    Then "Check AA" should precede "Check CC" for the query ".views-field-field-name"

    When I click "System Check"
    Then "Check AA" should precede "Check BB" for the query ".views-field-field-name"
    Then "Check BB" should precede "Check CC" for the query ".views-field-field-name"
    When I click "System Check"
    Then "Check CC" should precede "Check BB" for the query ".views-field-field-name"
    Then "Check BB" should precede "Check AA" for the query ".views-field-field-name"

    When I click "Number of Devices"
    Then "Check BB" should precede "Check AA" for the query ".views-field-field-name"
    Then "Check AA" should precede "Check CC" for the query ".views-field-field-name"
    When I click "Number of Devices"
    Then "Check CC" should precede "Check AA" for the query ".views-field-field-name"
    Then "Check AA" should precede "Check BB" for the query ".views-field-field-name"

    When I click "Results"
    Then "Check BB" should precede "Check AA" for the query ".views-field-field-name"
    Then "Check BB" should precede "Check CC" for the query ".views-field-field-name"
    When I click "Results"
    Then "Check AA" should precede "Check BB" for the query ".views-field-field-name"
    Then "Check CC" should precede "Check BB" for the query ".views-field-field-name"
