@api @trt @structured @school
Feature: PRC-851 Manage Schools - Upload School
  As a District Admin, I want to add schools to my district by uploading a .csv file so that I don't have to key in school information.
  Acceptance Criteria
#  Given that I am logged in as a District Admin
#  And I am on my Manage Schools page
#  And I have no schools added to my district
#  And no district admin has uploaded any schools to my district
#  When I click the Add School(s) - upload .csv file link
#  Then I see the Upload Schools page that has:
#  Page header
#  Upload Schools
#  Overview copy
#  "Overview / instructional copy. Consider explaining that for each school, there must be two columns: one for school name and one for school contact email address and that file must be .csv."
#  "Note that user will be allowed only one upload per school. "
#  Required field notation
#  "* indicates required field"
#  Form fields
#  Label: File Name
#  Type: File upload field
#  Instructions: "File must have .csv extension and have the following columns in this order: School Name, School Contact's Email Address"
#  Required: Yes
#  Browse button
#  Upload button

  Scenario: Upload file
    Given I am logged in as a user wi to th the "District Admin" role
    And "District" nodes:
      | title        | uid         |
      | District 851 | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    And I click "Add School(s) - upload csv file"
    Then I should see the heading "Upload Schools"
    And I should see the text "Overview / instructional copy. Consider explaining that for each school, there must be two columns: one for school name and one for school contact email address and that file must be .csv."
    And I should see the text "Note that user will be allowed only one upload per school."
    And I should see the text "\* indicates required field"
    And I should see the text "File Name \*"
    And I should see the text "File must have .csv extension and have the following columns in this order: School Name, School Contact's Email Address"
    And I should see an "Upload" button