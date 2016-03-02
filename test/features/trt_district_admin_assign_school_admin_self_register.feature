@api @trt @district @school
Feature: PRC-1171 Self-Registration - School, District and State Admins can access readiness pages
  As a School, District or State Admin,
  I want to have access to my readiness page if I don't register from the invitation
  so that I can access my readiness page.

#  Given that I have received a School, District or State Admin invite
#  And I didn't respond to the invite
#  When I self-register with the email associated with the invitation for the School, District or State Admin role
#  Then I have the role that would have been assigned to me had I not been a trouble maker and responded to the invitation
#  And I see the PRC home page

  Scenario: User self registers instead of following the invite
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title                 | uid         |
      | PRC-944 S1 @timestamp | @currentuid |
    And "School" nodes:
      | title                    | field_ref_district          | field_contact_email            | uid         |
      | School 944 S1 @timestamp | @nid[PRC-944 S1 @timestamp] | example1@timestamp@example.com | @currentuid |
    Then the email to "example1@timestamp@example.com" should contain "has sent you an invite!"
    # Now the invitation is generated. Accept it and verify the user.
    And I am an anonymous user
    And I am on the homepage
    And I follow "Create account"
    Then I fill in "example1@timestamp@example.com" for "E-mail"
    And I fill in "abc123" for "Password"
    And I fill in "abc123" for "Confirm password"
    And I fill in "First" for "First Name"
    And I fill in "Last" for "Last Name"
    And I fill in "Automated Test Robot" for "Profession"
    And I select "Wyoming" from "Where you teach"
    Then I check the box "I have read and agree with the Terms of Use and User Generated Content Disclaimer."
    Then I press the "Create new account" button
    Then I should see the message "Registration successful. You are now logged in."
    And the user "example1@timestamp@example.com" should have a role of "Educator"
    And the user "example1@timestamp@example.com" should have a role of "School Admin"
    Then I visit "assessments/technology-readiness"
    And I should see the link "School 944 S1 @timestamp Readiness"
    Then I delete the user with the email address "example1@timestamp@example.com"