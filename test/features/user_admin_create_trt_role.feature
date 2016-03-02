@api @user @trt @edit @prc-1562
Feature: PRC-1562 Create or Edit user should not allow TRT roles only

  Scenario: Every user except Admin should be in the view
    Given I am logged in as a user with the "PRC Admin" role
    And users:
      | name                                | mail                                | pass   | field_first_name | field_last_name | status | roles          |
      | joe_prc_1562a@timestamp@example.com | joe_prc_1562a@timestamp@example.com | xyz123 | Joe              | Auth User       | 1      |                |
      | joe_prc_1562b@timestamp@example.com | joe_prc_1562b@timestamp@example.com | xyz123 | Joe              | Admin           | 1      | administrator  |
      | joe_prc_1562c@timestamp@example.com | joe_prc_1562c@timestamp@example.com | xyz123 | Joe              | State Admin     | 1      | State Admin    |
      | joe_prc_1562d@timestamp@example.com | joe_prc_1562d@timestamp@example.com | xyz123 | Joe              | District Admin  | 1      | District Admin |
      | joe_prc_1562e@timestamp@example.com | joe_prc_1562e@timestamp@example.com | xyz123 | Joe              | School Admin    | 1      | School Admin   |
    When I am on "prc/admin/admin-users"
    Then I should see the text "joe_prc_1562a@timestamp@example.com"
    And I should see the text "joe_prc_1562c@timestamp@example.com"
    And I should see the text "joe_prc_1562d@timestamp@example.com"
    And I should see the text "joe_prc_1562e@timestamp@example.com"
    But I should not see the text "joe_prc_1562b@timestamp@example.com"

  Scenario: Edit a user
    Given I am logged in as a user with the "PRC Admin" role
    And users:
      | name                               | mail                               | pass   | field_first_name | field_last_name | status | roles                         |
      | roletest1562@timestamp@example.com | roletest1562@timestamp@example.com | xyz123 | Joe              | Contributor     | 1      | Educator, Content Contributor |
    And I am on "prc/admin/admin-users"
    When I click on the edit link for the user "roletest1562@timestamp@example.com"
    And I uncheck the box "Content Contributor"
    And I uncheck the box "Educator"
    And I check the box "State Admin"
    And I press "Save"
    Then I should see the error message containing "A non-TRT role is required."