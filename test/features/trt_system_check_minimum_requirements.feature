@api @trt @system_check @prc-1058
Feature: PRC-1058 System Check - PARCC Minimum Technology Requirements link
  As a PRC user,
  I want to be able to access the PARCC Minimum Technology Requirements
  so that I can understand if my computer can run a PRC Practice Test.
#    Given that I am a PRC user
#    And I am on a System Check page (structured or unstructured)
#    When I click the [link]PARCC minimum technology requirements[/link] link in the overview copy
#    Then I'm taken to a new tab displaying: http://www.parcconline.org/sites/parcc/files/TechnologyGuidelines-PARCCAssessments-January2015.pdf

  Scenario: System Check form
    Given I am an anonymous user
    And I visit "technology-readiness"
    When I click "System Check"
    Then I should see the link "PARCC minimum technology requirements"
    And the "PARCC minimum technology requirements" link should point to "www.parcconline.org/sites/parcc/files/TechnologyGuidelines-PARCCAssessments-January2015.pdf"