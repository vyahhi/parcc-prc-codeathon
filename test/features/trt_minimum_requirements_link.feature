@api @trt @prc-882
Feature: PRC-882 Technology Readiness - PARCC Minimum Technology Requirements link
  As a PRC user,
  I want to be able to access the PARCC Minimum Technology Requirements
  so that I can understand if my computer can run a PRC Practice Test.

#    Given that I am a user
#    And I am on the Technology Readiness page (see PRC-836)
#    When I click the [link]PARCC minimum technology requirements[/link] link in the copy associated with the System Check (below the System Check subhead)
#    Then I see the page at http://www.parcconline.org/sites/parcc/files/TechnologyGuidelines-PARCCAssessments-January2015.pdf

  Scenario: Show link on TRT page
    Given I am an anonymous user
    When I click "Technology Readiness"
    Then I should see the link "PARCC minimum technology requirements"
    And the "PARCC minimum technology requirements" link should point to "www.parcconline.org/sites/parcc/files/TechnologyGuidelines-PARCCAssessments-January2015.pdf"