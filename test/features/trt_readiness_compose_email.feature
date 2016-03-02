@api @trt @structured @school @readiness @vbo @prc-819 @prc-1170
Feature: PRC-819 Request Readiness Checks - Compose Email
  As a District Admin, I want to ask schools in my district to run the readiness checks so I can understand if the schools are ready to run the PARCC assessment.
  Acceptance Criteria
#  Given that I am logged in as District Admin
#  And I am on my Manage Schools page
#  And I select one or more schools
#  When I click the Request Readiness Checks button
#  Then I see the Request Readiness page that has:
#  Page Headline
  Request Readiness Checks
  Message Elements
  To:
  "All" If all schools selected
#  <School Name> for each school selected, in alphabetical order, if not all selected
#  Subject:
#  Subject goes here. For example: Please run readiness checks.
#  Message:
#  Message goes here explaining importance of running checks and how to run them, emphasizing that it is important that admins run the checks from the provided link or results won't be saved or reported to District.
#  Additional Comments (optional):
#  Text box
#  Next button
#  Cancel link

  # PRC-1170 puts school name in subject and link to school readiness page in email and takes TRT link out

  Scenario: Send email
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title              | uid         |
      | PRC-828 @timestamp | @currentuid |
    And "School" nodes:
      | title                   | field_ref_district       | field_contact_email      |
      | School 828-3 @timestamp | @nid[PRC-828 @timestamp] | e3@timestamp@example.com |
      | School 828-1 @timestamp | @nid[PRC-828 @timestamp] | e1@timestamp@example.com |
      | School 828-2 @timestamp | @nid[PRC-828 @timestamp] | e2@timestamp@example.com |
    And I visit the first node created
    And I click "Manage Schools"
    When I check the box "edit-views-bulk-operations-0"
    When I check the box "edit-views-bulk-operations-1"
    When I check the box "edit-views-bulk-operations-2"
    When I press "Request Readiness Checks"
    Then I should see the heading "Request Readiness Checks"
    And I should not see the link "Add School - form"
    Then I should see the text "To:"
    And I should see the text "School 828-1 @timestamp, School 828-2 @timestamp, School 828-3 @timestamp"
    And I should see the text "Subject:"
    And I should see the text "PARCC Assessments Technology Readiness Tool"
    And I should see the text "Message:"
    And I should see the text "Your PRC district admin has requested that you run system and/or testing capacity checks for your school. Please login to the PRC and run new or update your school testing capacity and/or system checks for this school year."
    And I should see the text "Thank you."
    And I should not see the text "\[message:field-comment\]"
    # PRC-1068 site:url token includes the trailing / so that replace was incorrect
    And I should not see the text "\[message"
    And I should see the text "Additional Comments \(optional\):"
    And I should see a "Next" button
    And I should see a "Cancel" link
    And I fill in "Additional Comments (optional):" with "Something @timestamp For Testing"
    When I press "Next"
    Then I should not see the link "Add School - form"
    And I should see the heading "You selected the following 3 items:"
    And I should see the text "School 828-1 @timestamp"
    And I should see the text "School 828-2 @timestamp"
    And I should see the text "School 828-3 @timestamp"
    Then I should see a "Confirm" button
    And I should see a "Cancel" link
    When I press "Confirm"
    And I follow meta refresh
    Then the email to "e1@timestamp@example.com" should contain "PARCC Assessments Technology Readiness Tool"
    And the email should contain "Your PRC district admin has requested that you run system and/or testing capacity checks for your school. Please login to the PRC and run new or update your school testing capacity and/or system checks for this school year."
    And the email should contain "Something @timestamp For Testing"
    Then the email to "e2@timestamp@example.com" should contain "PARCC Assessments Technology Readiness Tool"
    And the email should contain "Your PRC district admin has requested that you run system and/or testing capacity checks for your school. Please login to the PRC and run new or update your school testing capacity and/or system checks for this school year."
    And the email should contain "Something @timestamp For Testing"
    Then the email to "e3@timestamp@example.com" should contain "PARCC Assessments Technology Readiness Tool"
    And the email should contain "Your PRC district admin has requested that you run system and/or testing capacity checks for your school. Please login to the PRC and run new or update your school testing capacity and/or system checks for this school year."
    And the email should contain "Something @timestamp For Testing"
    And I should see the text "Performed Request Readiness Checks on 3 items."
    When I follow the link in the email
    Then I should see the heading "School 828-3 @timestamp Readiness"
    # We get a serialization error here because of the test mail system.
    # We don't get this during normal emailing.