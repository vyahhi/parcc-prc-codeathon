@api @trt @navigation @structured @prc-815
Feature: PRC-815 Navigation - Breadcrumbs - Structured User
  As structured user,
  I want to navigate backwards through the structured pages
  so that I can quickly run to a higher-level page.


  Scenario Outline: State Admin on District Readiness page
    Given I am logged in as a user with the "State Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title                    | field_ref_district    | field_contact_email            | uid         |
      | School 944 S1 @timestamp | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And I visit the first node created
    Then I should see the heading "<member_state> Readiness"
    When I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
    Then I should see the link "<member_state> Readiness"
    When I click "<member_state> Readiness"
    Then I should see the heading "<member_state> Readiness"
  Examples:
    | user_state    | member_state   | district_name       |
    | West Colorado | South Illinois | District @timestamp |

  Scenario Outline: State Admin on School Readiness page
    Given I am logged in as a user with the "State Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And I visit the last node created
    Then I should see the heading "<school_name> Readiness"
    Then I should see the link "<member_state> Readiness"
    And I should see the link "<district_name> Readiness"
    When I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
    And I visit the last node created
    When I click "<member_state> Readiness"
    Then I should see the heading "<member_state> Readiness"
  Examples:
    | user_state    | member_state   | district_name       | school_name       |
    | West Colorado | South Illinois | District @timestamp | School @timestamp |

  Scenario Outline: State Admin on a school's View System Check Results page
    Given I am logged in as a user with the "State Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And the school "<school_name>" has run a system check
    And I visit the last node created
    And I click "Fakey Check"
    Then I should see the link "<member_state> Readiness"
    And I should see the link "<district_name> Readiness"
    And I should see the link "<school_name> Readiness"
  Examples:
    | user_state    | member_state   | district_name       | school_name       |
    | West Colorado | South Illinois | District @timestamp | School @timestamp |

  Scenario Outline: District Admin on District Name Add / Edit
    Given I am logged in as a user with the "District Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Edit district name"
    Then I should not see the link "<member_state> Readiness"
    And I should see the link "<district_name> Readiness"
  Examples:
    | user_state    | member_state   | district_name       |
    | West Colorado | South Illinois | District @timestamp |

  Scenario Outline: District Admin on Manage Schools
    Given I am logged in as a user with the "District Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Manage Schools"
    Then I should not see the link "<member_state> Readiness"
    And I should see the link "<district_name> Readiness"
  Examples:
    | user_state    | member_state   | district_name       |
    | West Colorado | South Illinois | District @timestamp |

  Scenario Outline: District Admin on School Readiness
    Given I am logged in as a user with the "District Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And I visit the last node created
    Then I should see the heading "<school_name> Readiness"
    Then I should not see the link "<member_state> Readiness"
    But I should see the link "<district_name> Readiness"
    When I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
  Examples:
    | user_state    | member_state   | district_name       | school_name       |
    | West Colorado | South Illinois | District @timestamp | School @timestamp |

  Scenario Outline: District Admin on School Add/Edit form
    Given I am logged in as a user with the "District Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Manage Schools"
    When I click "Add School - form"
    Then I should not see the link "<member_state> Readiness"
    But I should see the link "<district_name> Readiness"
    And I should see the link "Manage Schools"
    When I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
  Examples:
    | user_state    | member_state   | district_name       |
    | West Colorado | South Illinois | District @timestamp |

  Scenario Outline: District Admin on School Upload
    Given I am logged in as a user with the "District Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    Then I should not see the link "<member_state> Readiness"
    But I should see the link "<district_name> Readiness"
    And I should see the link "Manage Schools"
    When I click "<district_name>"
    Then I should see the heading "<district_name> Readiness"
  Examples:
    | user_state    | member_state   | district_name       |
    | West Colorado | South Illinois | District @timestamp |

    #
#  <District Name> Readiness (links to District Readiness (PRC-706))
#  Manage Schools (links to Manage Schools (PRC-828))
  Scenario Outline: District Admin on Request Readiness Checks
    Given I am logged in as a user with the "District Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And I visit the first node created
    And I click "<district_name> Readiness"
    And I click "Manage Schools"
    When I check the box "edit-views-bulk-operations-0"
    When I press "Request Readiness Checks"
    Then I should not see the link "<member_state> Readiness"
    But I should see the link "<district_name> Readiness"
    And I should see the link "Manage Schools"
  Examples:
    | user_state    | member_state   | district_name       | school_name       |
    | West Colorado | South Illinois | District @timestamp | School @timestamp |

  Scenario Outline: District Admin on System Check Results page:
    Given I am logged in as a user with the "District Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And the school "<school_name>" has run a system check
    And I visit the last node created
    And I click "Fakey Check"
    Then I should not see the link "<member_state> Readiness"
    And I should see the link "<district_name> Readiness"
    And I should see the link "<school_name> Readiness"
  Examples:
    | user_state    | member_state   | district_name       | school_name       |
    | West Colorado | South Illinois | District @timestamp | School @timestamp |

  Scenario Outline: School Admin on System Check - Structured - Form and View Results Page
    Given I am logged in as a user with the "School Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And I visit the last node created
    And I click "run system check"
    Then I should not see the link "<member_state> Readiness"
    And I should not see the link "<district_name> Readiness"
    But I should see the link "<school_name> Readiness"

    And I fill in "System check name" with "Check 2"
    And I fill in "Number of devices" with "23"
    And I select "Desktop" from "Device type"
    And I select "Windows 7" from "Operating system"
    And I fill in "Monitor size (in inches)" with "17"
    And I select "At least 2 Ghz and under 2.5 Ghz" from "Processor speed"
    And I select "At least 512 and under 1 GB" from "RAM"
    And I fill in the hidden field "faux_browser" with "ff 33"
    And I fill in the hidden field "faux_javascript" with "true"
    And I fill in the hidden field "faux_jre_version" with "1.6.0_65"
    And I fill in the hidden field "faux_cookies" with "true"
    And I fill in the hidden field "faux_images" with "true"
    And I fill in the hidden field "faux_monitor_color_depth" with "16"
    And I fill in the hidden field "faux_screen_resolution_width" with "1024"
    And I fill in the hidden field "faux_screen_resolution_height" with "768"
    When I press "Submit"

    Then I should not see the link "<member_state> Readiness"
    And I should not see the link "<district_name> Readiness"
    But I should see the link "<school_name> Readiness"
  Examples:
    | user_state    | member_state   | district_name       | school_name       |
    | West Colorado | South Illinois | District @timestamp | School @timestamp |

  Scenario Outline: School Admin on Testing Capacity Check - Structured - Form and View Results Page
    Given I am logged in as a user with the "School Admin" role
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title           | uid         | field_ref_trt_state  |
      | <district_name> | @currentuid | @nid[<member_state>] |
    And "School" nodes:
      | title         | field_ref_district    | field_contact_email            | uid         |
      | <school_name> | @nid[<district_name>] | example1@timestamp@example.com | @currentuid |
    And I visit the last node created
    And I click "run testing capacity check"
    Then I should not see the link "<member_state> Readiness"
    And I should not see the link "<district_name> Readiness"
    And I should not see the link "Manage Schools"
    But I should see the link "<school_name> Readiness"

    When I fill in "Number of students" with "100"
    When I fill in "Number of devices ready for assessment" with "50"
    When I fill in "Number of days of testing" with "5"
    When I fill in "Number of test sessions per day" with "5"
    When I fill in "Number of sittings per student" with "5"
    When I fill in "Speed of connection (in Mbps)" with "12"
    And I press "Submit"

    Then I should not see the link "<member_state> Readiness"
    And I should not see the link "<district_name> Readiness"
    And I should not see the link "Manage Schools"
    But I should see the link "<school_name> Readiness"
  Examples:
    | user_state    | member_state   | district_name       | school_name       |
    | West Colorado | South Illinois | District @timestamp | School @timestamp |
