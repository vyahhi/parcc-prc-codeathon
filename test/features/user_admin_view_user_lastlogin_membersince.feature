@api @d7 @user
Feature: PRC-785 Admin - Users Table: Member Since and Last Logged on
  As a PRC Admin
  I want to view a user's last logged on date and date of membership
  so that I know when the user last logged in and when the user became a member.

#  a column to the right of the "Active" column with the label "Last Logged on" in which the last logged on date for the respective user is displayed in the format MM/DD/YYYY
#  a column to the right of the "Last Logged on" column with the label "Member Since" in which the date of membership for the respective user is displayed in the format MM/DD/YYYY

  Scenario: AC4 - All fields are sortableexcept Role(s)
    Given I am logged in as a user with the "PRC Admin" role
    And I visit "/admin-users"
    Then I should see the link "Active"
    Then I should see the link "Last Logged on"

  Scenario: PRC-286 - Users with multiple roles appear once for each role
    Given users:
      | name     | mail                              | pass     | field_first_name | field_last_name | status |
      | Joe User | joe_prc_286@timestamp@example.com | xyz123   | Joe              | User            | 1      |
    And I am logged in as a user with the "PRC Admin" role
    Then I run drush "user-add-role" "'Educator' joe_prc_286@timestamp@example.com"
    Then I run drush "user-add-role" "'PRC Admin' joe_prc_286@timestamp@example.com"
    And I am at "admin-users"
    Then I click "User ID"
    Then I should see 1 "//a[text()='@uname[Joe User]']" elements

