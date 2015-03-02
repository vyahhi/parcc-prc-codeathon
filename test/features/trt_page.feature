@api @trt
Feature: PRC-836 Technology Readiness

  As a user, I want to view the Technology Readiness page, so that I can learn about the readiness checks, run unstructured checks, access my school, district or state readiness page and add my district.
  Acceptance Criteria
  Given that I am a user
  When I click the Technology Readiness tab
  Then I see the Technology Readiness page that has:
  Scenario 1: Common page elements
  Page Headline
  Technology Readiness
  Overview Copy
  Overview / instructional copy goes here. Consider explaining importance of testing prior to assessment to increase chances of successful assessment.
  Important Message
  Important: If you are a school administrator, please run these checks from your school readiness page. Contact your District Administrator to have the link to that page emailed to you.
  Subhead, linked
  System Check
  Copy
  Description of test and importance of running it: The system check assesses whether a device or similar configuration of devices meets the PARCC minimum requirements.
  Subhead, linked
  Testing Capacity Check
  Copy
  Description of test and importance of running it: The testing capacity check assesses whether your school has sufficient bandwidth and a sufficient number of devices that meet PARCC minimum requirement in order to run a successful assessment.
  Scenario 2: Logged in as School Admin with one school
  Subhead, linked
  <School Name> Readiness
  Copy
  Summary of what user can do here: view readiness by school, run readiness checks, view readiness check results.
  Scenario 3: Logged in as School Admin with more than one school
  For each school, listed in alphabetical order:
  Subhead, linked
  <School Name> Readiness
  Copy
  Summary of what user can do here: view readiness by school, run readiness checks, view readiness check results.
  Scenario 4: Logged in as District Admin and district name not added
  Subhead, linked
  Add District Name
  Copy
  Instructions to District Admin to add district, which will allow results generate by School Admin to be reported to the district.
  Scenario 5: Logged in as District Admin and district name added
  Subhead, linked
  <District Name> Readiness
  Copy
  Summary of what user can do here: add schools, request school admins to run checks, view readiness by schools in district.
  Scenario 6: Logged in as State Admin
  Subhead, linked
  <State Name> Readiness
  Copy
  Summary of what user can do here: export state readiness checks data, view readiness by district, export district readiness checks data view school readiness data.