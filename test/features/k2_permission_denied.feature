@api @k2 @fit @permissions @prc-1523 @prc-1524 @prc-1779
Feature: PRC-1523 Formative Instructional Tasks - New Permissions
  As an authenticated user, I want to be able to view Formative Instructional Tasks resources.


#  Scenario: 1 Educator
#    Given that I am logged in as an Educator
#    When I am on the Formative Instructional Tasks page
#    Then I see Formative Instructional Tasks resources with permissions set to "Authenticated User"
#  Scenario: 2 PRC Admin, Content Curator, Content Contributor and PARCC-member Educator
#    Given I am logged in as an Admin, Content Curator, Content Contributor or PARCC-member Educator
#    When I am on the Formative Instructional Tasks page
#    Then I see Formative Instructional Tasks resources with permissions set to "Authenticated User"
#    And I see Formative Instructional Tasks resources with permissions set to "PARCC members ONLY"
#  Note:
#  With existing functionality, PARCC-member Educator and PRC Admin only can access page.

  Scenario: Anonymous user can't view public K2
    Given formative instructional task content:
      | resource name       | resource type                 | file                          | faux standard | faux subject | grade level | permissions  |
      | PRC-1524 | Task | testfiles/TT_Rules_2015.pdf | Standard      | Subject      | 1st Grade   | public                                          |
    And I am an anonymous user
    When I am viewing my "Formative Instructional Task" node with the title "PRC-1524"
    Then I should see the text "Access Denied"
    When I am on "system/files/TT_Rules_2015.pdf"
    Then I should see the text "Access Denied"

  Scenario: Educator can view public K2
    Given formative instructional task content:
      | resource name       | resource type                 | file                          | faux standard | faux subject | grade level | permissions  |
      | PRC-1524 | Task | testfiles/TT_Rules_2015.pdf | Standard      | Subject      | 1st Grade   | public                                          |
    And I am logged in as a user with the "Educator" role
    When I am viewing my "Formative Instructional Task" node with the title "PRC-1524"
    Then I should not see the text "Access Denied"
    When I am on "system/files/TT_Rules_2015.pdf"
    Then the response Content-Type should be "application/pdf"

  Scenario: Member Educator can view public K2
    Given formative instructional task content:
      | resource name       | resource type                 | file                          | faux standard | faux subject | grade level | permissions  |
      | PRC-1524 | Task | testfiles/TT_Rules_2015.pdf | Standard      | Subject      | 1st Grade   | public                                          |
    And I am logged in as a user with the "PARCC-Member Educator" role
    When I am viewing my "Formative Instructional Task" node with the title "PRC-1524"
    Then I should not see the text "Access Denied"
    When I am on "system/files/TT_Rules_2015.pdf"
    Then the response Content-Type should be "application/pdf"

  Scenario: Member Educator can view private K2
    Given formative instructional task content:
      | resource name       | resource type                 | file                          | faux standard | faux subject | grade level | permissions  |
      | PRC-1524 | Task | testfiles/TT_Rules_2015.pdf | Standard      | Subject      | 1st Grade   | members                                          |
    And I am logged in as a user with the "PARCC-Member Educator" role
    When I am viewing my "Formative Instructional Task" node with the title "PRC-1524"
    Then I should not see the text "Access Denied"
    When I am on "system/files/TT_Rules_2015.pdf"
    Then the response Content-Type should be "application/pdf"

  Scenario: Educator can't view private K2
    Given I am logged in as a user with the "Educator" role
    And "Formative Instructional Task" nodes:
      | title    | body           | field_permissions | uid | status |
      | PRC-1524 | This is public | members           | 1   | 1      |
    Given formative instructional task content:
      | resource name       | resource type                 | file                          | faux standard | faux subject | grade level | permissions  |
      | PRC-1524 | Task | testfiles/TT_Rules_2015.pdf | Standard      | Subject      | 1st Grade   | members
    When I visit the last node created
    Then I should see the text "Access Denied"
    When I am on "system/files/TT_Rules_2015.pdf"
    Then I should see the text "Access Denied"