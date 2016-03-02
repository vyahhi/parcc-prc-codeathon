@api @trt @structured @school @upload @prc-851 @prc-854
Feature: PRC-851 Manage Schools - Upload School
  As a District Admin, I want to add schools to my district by uploading a .csv file so that I don't have to key in school information.

  # PRC-854 Changes this copy.

  Scenario: Upload file
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title        | uid         |
      | District 851 | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    And I click "Add School(s) - upload csv file"
    Then I should see the heading "Upload Schools"
    And I should see the text "Use this upload tool to bulk enter school information."
    And I should see the text "To upload multiple schools, use Excel or another spreadsheet program and create a two-column .csv file. There must be two columns: the first for the school name and the second for the school contact email address; the first row of the spreadsheet is treated as a header and its contents are ignored. Make sure to save the file as a .csv. Lastly, upload your schools using this interface."
    And I should see the text "You also might be able to have your school’s student information system generate the .csv file for you and save even more time."
    And I should see the text "Note: School names must be unique within a district, and once submitted, a school with data cannot be deleted. The data will be checked by the TRT before being accepted."
    And I should see the text "\* indicates required field"
    And I should see the text "File Name \*"
    And I should see the text "File must have .csv extension and have two columns in this order: School Name, School Contact's Email Address. The first row is treated as a header and its contents are ignored, and the naming of the columns is ignored."
    And I should see an "Upload" button