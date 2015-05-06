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
    When I visit "technology-readiness"
    Then I should see the heading "Technology Readiness"
    And I should see the text "Overview / instructional copy goes here. Consider explaining importance of testing prior to assessment to increase chances of successful assessment."
    And I should see the text "Important: If you are a school administrator, please run these checks from your school readiness page. Contact your District Administrator to have the link to that page emailed to you."
    And I should see the link "System Check"
    # PRC-882 Changed the system check text
    And I should see the text "Description of test and importance of running it: The system check assesses whether a device or similar configuration of devices meets the PARCC minimum technology requirements."
    And I should see the link "Testing Capacity Check"
    And I should see the text "Description of test and importance of running it: The testing capacity check assesses whether your school has sufficient bandwidth and a sufficient number of devices that meet PARCC minimum requirement in order to run a successful assessment."
