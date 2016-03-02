@api @prc-1695 @styleguide @javascript
Feature: Test Website Users responsive design and table overflow (PRC-1965)
  @javascript @1965 @api
  Scenario: Viewing Website Users table on prc/admin/admin-users page on a phone
    Given users:
      | name     | mail                | pass     | field_first_name | field_last_name | status |
      | Joe User | jmoreBacon_please@example.com | xyz123   | Joephahara              | Baconatoraty            | 1      |
    When I am logged in as a user with the "PRC Admin" role
    And I am browsing using a "phone"
    And I am on "/prc/admin/admin-users"
    Then I should see "User Id"
    And I should see "First Name"
    And I should see "Last Name"
    And I should see "E-mail"
    And I should not see "State"
    And I should not see "Roles"
    And I should not see "Profession" in the ".views-table" element
    And I should not see "Active" in the ".views-table" element
    And I should not see "Last Logged on" in the ".views-table" element
    And I should not see "Member Since" in the ".views-table" element

  @javascript @1965 @api
  Scenario: Viewing Website Users table on prc/admin/admin-users page on a tablet
    Given users:
      | name     | mail                | pass     | field_first_name | field_last_name | status |
      | Joe User | jmoreBacon_please@example.com | xyz123   | Joephahara              | Baconatoraty| 1      |
    When I am logged in as a user with the "PRC Admin" role
    And I am browsing using a "tablet"
    And I am on "/prc/admin/admin-users"
    Then I should see "User Id"
    And I should see "First Name"
    And I should see "Last Name"
    And I should see "E-mail"
    And I should see "Member Organization"
    And I should see "Roles"
    And I should not see "Profession" in the ".views-table" element
    And I should not see "Active" in the ".views-table" element
    And I should not see "Last Logged on" in the ".views-table" element
    And I should not see "Member Since" in the ".views-table" element




  @javascript @1965
  Scenario: Viewing Website Users table on prc/admin/admin-users page on a desktop
    Given users:
      | name     | mail                | pass     | field_first_name | field_last_name | status |
      | Joe User | jmoreBacon_please@example.com | xyz123   | Joephahara              | Baconatoraty| 1      |
    When I am logged in as a user with the "PRC Admin" role
    And I am browsing using a "Desktop"
    And I am on "/prc/admin/admin-users"
    Then I should see "User Id"
    And I should see "First Name"
    And I should see "Last Name"
    And I should see "E-mail"
    And I should see "Member Organization"
    And I should see "Roles"
    And I should not see "Profession" in the ".views-table" element
    And I should not see "Active" in the ".views-table" element
    And I should not see "Last Logged on" in the ".views-table" element
    And I should not see "Member Since" in the ".views-table" element