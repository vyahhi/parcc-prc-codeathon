@api @trt @prc-1207 @prcadmin
Feature: PRC-1207 Technology Readiness - PRC Admin View
  As a PRC Admin,
  I want to be able to access technology readiness data for all schools in all districts in all states
  so that I can understand the readiness for these entities.

#  Given that I am logged in as a PRC Admin
#  When I click the Technology Readiness tab
#  Then I see Technology Readiness page that has:
#  Differences from Technology Readiness (PRC-836)
#  Subhead
#  PARCC Readiness [link]
#  Copy
#  Summary of what user can do here, for example: view readiness data by state, export state readiness check data, view readiness by district, export district readiness checks data, view school readiness data.

  Scenario Outline: PRC Admin TRT Page
    Given I am logged in as a user with the "<role>" role
    And I visit "assessments/technology-readiness"
    Then I should see the link "PARCC Readiness"
    And I should see the text "Click the link above to access the TRT reports available to you."
    And I should see the text "NOTE: Users will have access to reports only for their authorized level of access. Check your account settings to see your authorization. If there is a discrepancy in your account authorization, school based staff should contact the designated PRC admin for your district while district and state staff should contact the PARCC Inc. through the"
    And I should see the link "PRC helpdesk"
  Examples:
    | role          |
    | administrator |
    | PRC Admin     |

  Scenario Outline: Other users don't have it
    Given I am logged in as a user with the "<role>" role
    And I visit "assessments/technology-readiness"
    Then I should not see the link "PARCC Readiness"
    And I should not see the text "Click the link above to access the TRT reports available to you."
    And I should not see the text "NOTE: Users will have access to reports only for their authorized level of access. Check your account settings to see your authorization. If there is a discrepancy in your account authorization, school based staff should contact the designated PRC admin for your district while district and state staff should contact the PARCC Inc. through the"
    And I should not see the link "PRC helpdesk"
  Examples:
    | role                            |
    | State Admin                     |
    | District Admin                  |
    | School Admin                    |
    | Educator                        |
    | PARCC-Member Educator           |
    | Content Administrator (Curator) |
