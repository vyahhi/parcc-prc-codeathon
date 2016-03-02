@api @parcc-released-item @permissions @prc-1777 @prc-1780 @prc-1779
Feature: PARCC Released Items - Permissions View Page
  As a user
  I want to be able to view resources on the PARCC Released Items page according to my user type / role
  so that I can see the resources available to me.

  Background:
    Given I have no "PARCC Released Item" nodes
    And parcc-released-item content:
      | resource name       | file                          | resource type | faux standard | faux subject | grade level | permissions  |
      | Public Resource | testfiles/TT_Rules_2015.pdf | Item Set  | Standard One      | Subject One      | 1st Grade   | public     |
      | Registered Resource | testfiles/TT_Rules_2015.pdf | Item  | Standard One      | Subject One      | 1st Grade   | registered     |
      | Members Resource | testfiles/TT_Rules_2015.pdf | Manual | Standard One      | Subject One      | 1st Grade   | members     |
      | Sample Student Resource | testfiles/TT_Rules_2015.pdf | Sample Student Responses | Standard One      | Subject One      | 1st Grade   | public |
      | Supplemental Document   | testfiles/TT_Rules_2015.pdf | Supplemental Documents | Standard One      | Subject One      | 1st Grade   | public |

  Scenario: 1 PARCC Released Items - Public Permissions View
    Given I am an anonymous user
    When I am on "assessments/parcc-released-items"
    Then I should see the link "Public Resource"
    And I should not see the link "Registered Resource"
    And I should not see the link "Members Resource"
    And I should not see the text "Actions"
    When I am on "system/files/TT_Rules_2015.pdf"
    Then the response Content-Type should be "application/pdf"
    When I am on "system/files/TT_Rules_2015_0.pdf"
    Then I should see the text "Access Denied"
    When I am on "system/files/TT_Rules_2015_1.pdf"
    Then I should see the text "Access Denied"
    # Todo - I'd also like to test the node view pages themselves, but 'visit the last node created' doesn't seem to be working for some reason.

  Scenario: 2 PARCC Released Items - Registered Permissions View
    When I am logged in as a user with the "Educator" role
    When I am on "assessments/parcc-released-items"
    Then I should see the link "Public Resource"
    And I should see the link "Registered Resource"
    And I should not see the link "Members Resource"
    And I should not see the text "Actions"
    When I am on "system/files/TT_Rules_2015.pdf"
    Then the response Content-Type should be "application/pdf"
    When I am on "system/files/TT_Rules_2015_0.pdf"
    Then the response Content-Type should be "application/pdf"
    When I am on "system/files/TT_Rules_2015_1.pdf"
    Then I should see the text "Access Denied"

  Scenario: 3 PARCC Released Items - Member Permissions View
    When I am logged in as a user with the "Content Contributor" role
    When I am on "assessments/parcc-released-items"
    Then I should see the link "Public Resource"
    And I should see the link "Registered Resource"
    And I should see the link "Members Resource"
    And I should not see the text "Actions"
    When I am on "system/files/TT_Rules_2015.pdf"
    Then the response Content-Type should be "application/pdf"
    When I am on "system/files/TT_Rules_2015_0.pdf"
    Then the response Content-Type should be "application/pdf"
    When I am on "system/files/TT_Rules_2015_1.pdf"
    Then the response Content-Type should be "application/pdf"

  Scenario: 4 PARCC Released Items - Item Author Permissions View
    When I am logged in as a user with the "PARCC Item Author" role
    When I am on "assessments/parcc-released-items"
    Then I should see the link "Public Resource"
    And I should see the link "Registered Resource"
    And I should see the link "Members Resource"
    And I should see the text "Actions"
    When I am on "system/files/TT_Rules_2015.pdf"
    Then the response Content-Type should be "application/pdf"
    When I am on "system/files/TT_Rules_2015_0.pdf"
    Then the response Content-Type should be "application/pdf"
    When I am on "system/files/TT_Rules_2015_1.pdf"
    Then the response Content-Type should be "application/pdf"

  Scenario: 5 PARCC Released Items - PRC Admin Permissions View
    When I am logged in as a user with the "PARCC Item Author" role
    When I am on "assessments/parcc-released-items"
    Then I should see the link "Public Resource"
    And I should see the link "Registered Resource"
    And I should see the link "Members Resource"
    And I should see the text "Actions"
    When I am on "system/files/TT_Rules_2015.pdf"
    Then the response Content-Type should be "application/pdf"
    When I am on "system/files/TT_Rules_2015_0.pdf"
    Then the response Content-Type should be "application/pdf"
    When I am on "system/files/TT_Rules_2015_1.pdf"
    Then the response Content-Type should be "application/pdf"