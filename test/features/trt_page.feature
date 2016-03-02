@api @trt @prc-836 @prc-882
Feature: PRC-836 Technology Readiness
  As a user,
  I want to view the Technology Readiness page,
  so that I can learn about the readiness checks and run unstructured checks, access my school, district or state readiness page and add my district.

#  Acceptance Criteria
#  Given that I am a user
#  When I click the Technology Readiness tab
#  Then I see the Technology Readiness page that has:
#  Page Headline
#  Technology Readiness
#  Overview Copy
#  Overview / instructional copy goes here. Consider explaining importance of testing prior to assessment to increase chances of successful assessment.
#  Important Message
#  Important: If you are a school administrator, please run these checks from your school readiness page. Contact your District Administrator to have the link to that page emailed to you.
#  Subhead, linked
#  System Check
#  Copy
#  Description of test and importance of running it: The system check assesses whether a device or similar configuration of devices meets the PARCC minimum requirements.
#  Subhead, linked
#  Testing Capacity Check
#  Copy
#  Description of test and importance of running it: The testing capacity check assesses whether your school has sufficient bandwidth and a sufficient number of devices that meet PARCC minimum requirement in order to run a successful assessment.

  Scenario: Unstructured TRT Page
    Given I am logged in as a user with the "Educator" role
    When I visit "assessments/technology-readiness"
    Then I should see the heading "Technology Readiness"
    And I should see the text "In order to have a successful computer based assessment experience for you, your school, your district, and most importantly the students in your school\(s\), PARCC recommends that the appropriate school, district, and state staff and administrators register to use this Technology Readiness Tool \(TRT\). District and State TRT Administrators contact PARCC Inc. support at"
    And I should see the link "questions@parcconline.org"
    And I should see the text "for assistance. This tool will help you gauge the overall readiness of the platform\(s\) and network for the number of students and number of testing sessions."
    And I should see the text "NOTE: From this page, you can use this tool to perform \“ad hoc\” system and capacity checks. When running an \“ad hoc\” check the TRT does not record the results."
    And I should see the text "For more information on the technology requirements used to evaluate platforms and networks please download the"
    And I should see the link "PARCC minimum technology requirements"
    And I should not see the text "Coming soon! Parcc Inc. is updating the Technology Readiness Tool with the ability to run and save checks for schools and create school, district, and state readiness reports. Return here in October, 2015 for instructions on how to access this new service."
    And I should see the link "System Check"
    # PRC-882 Changed the system check text
    And I should see the text "Run this check to determine if the platform you are using is ready to deliver PARCC assessments."
    And I should see the link "Testing Capacity Check"
    And I should see the text "Run this check to determine your network’s capacity to deliver PARCC assessments."

    # For PRC Admin View of assessments/technology-readiness see trt_prc_admin.feature
    # For District Admin view of assessments/technology-readiness see trt_district_admin_page.feature
    # For School Admin View of assessments/technology-readiness see trt_school_admin_view.feature

  Scenario Outline: PRC-939 School admin only sees own schools
    Given I am logged in as a user with the "State Admin" role
    And users:
      | name   | mail               | pass   | field_first_name | field_last_name | status | roles                  |
      | First  | <user_name>        | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
      | Second | <second_user_name> | xyz123 | Joe              | Educator        | 1      | Educator, School Admin |
    And "School" nodes:
      | title                    | field_contact_email | uid         |
      | School 939 S1 @timestamp | <user_name>         | @currentuid |
      | School 939 S2 @timestamp | <user_name>         | @currentuid |
      | School 939 S3 @timestamp | <second_user_name>  | @currentuid |
    And I am an anonymous user
    And I am logged in as "First"
    And I visit "assessments/technology-readiness"
    Then I should see the link "School 939 S1 @timestamp Readiness"
    And I should see the link "School 939 S2 @timestamp Readiness"
    And I should not see the text "School 939 S3 @timestamp Readiness"
    Examples:
      | user_name                          | second_user_name                      |
      | joe_prc_960a@timestamp@example.com | second_prc_960b@timestamp@example.com |