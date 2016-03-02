@api @sso @prc-1881
Feature: PRC-1881 SSO - Updating User Attributes in PRC Should Update Attributes in LDAP
  As a user, I want my updated account information to be updated in LDAP / SSP IdP so that I can log in using SSO.

#  Scenario: 1 Account updated in PRC via My Account
#    Given that I have an account on PRC
#    And my account was updated in PRC My Account
#    When I change one or more of these attributes:
#  Password
#  PRC role
#  Full name
#  First name
#  Email address
#  Last name
#    Then these attributes of my account are updated in LDAP
#  Scenario: 2 Account updated in PRC via admin
#    Given that I have an account on PRC
#    And my account was updated in PRC via admin
#    When the admin changes one or more of the attributes in Scenario 1
#    Then these attributes of my account are updated in LDAP
#  Scenario: 3 Account updated in PRC via a District Admin assigning me to a school
#    Given that I have an account on PRC
#    And I am not already a School Admin
#    When a District Admin assigns me to a school [associates my email address with a school in that district]
#    Then my PRC role is updated in LDP
#  Scenario: 4 Account updated in PRC via a District Admin removing me from a school
#    Given that I have an account on PRC
#    And I am a School Admin for only one school
#    When a District Admin removes me from a school [changes the email associated with a school from my email to another email address]
#    Then my PRC role is updated in LDP
#  Scenario: 5 Account updated in PRC via a District Admin deleting my school
#    Given that I have an account on PRC
#    And I am a School Admin for only one school
#    When a District Admin deletes my school
#    Then my PRC role is updated in LDP
#  Original Story
#  If a user updates their email address, password, or possibly other attributes these changes should be reflected in LDAP.
#  Notes:
#  What attributes do we want to sync outside of PRC?
#  If we don't do this, then we'll need to disable the ability for users to change their usernames and passwords.
#
  Scenario: User property update updates LDAP
    Given I am on the homepage
#    And I click "Log in"
#    And I follow "Create new account"
    And I am on "user/register"
    Then I fill in "@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First @timestamp" for "First Name"
    And I fill in "Last @timestamp" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    And I select "Wyoming" from "Where you teach"
    Then I check the box "I have read and agree with the Terms of Use and User Generated Content Disclaimer."
    Then I press the "Create new account" button
    Then I should see the message "Registration successful. You are now logged in."

    Then the LDAP user with "@timestamp@example.com" should have a "givenName" attribute of "First @timestamp"
    Then the LDAP user with "@timestamp@example.com" should have a "sn" attribute of "Last @timestamp"

    Then I click "My account"
    And I click "Edit"
    And I fill in "First Name" for "First Name"
    And I fill in "Last Name" for "Last Name"
    And I press "Save"
    Then the LDAP user with "@timestamp@example.com" should have a "givenName" attribute of "First Name"
    Then the LDAP user with "@timestamp@example.com" should have a "sn" attribute of "Last Name"

    Then I delete the LDAP user "@timestamp@example.com"