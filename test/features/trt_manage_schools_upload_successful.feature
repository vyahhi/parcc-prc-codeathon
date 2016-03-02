@api @trt @structured @school @upload @prc-864 @prc-854
Feature: PRC-864 Manage Schools - Upload School - No Schools Exist - School(s) Added
  As a District Admin, I want to view the schools I added to my district by uploading a .csv file so that I can see that the schools were added and I can request that the schools run readiness checks.
  Acceptance Criteria
  Given that I am logged in as a District Admin
  And I am on my Upload Schools page
  And I have no schools added to my district
  And my fields are valid
  When I click the Upload
  Then the School Readiness page for any new school is created
  And I see the Manage Schools page that has the schools I added (see Manage Schools PRC-828)

  Scenario: Upload and create schools
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title        | uid         |
      | District 851 | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_valid.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "File Import Status"
    And I should not see the text "Some records could not be uploaded. Please select one of the actions below."
    And I should see the text "Upload Schools File"
    And I should see the text "trt_upload_schools_valid.csv"
    And I should see the text "Total records in file: 2"
    And I should see the text "Accepted Records: 2"
    And I should see the text "The Accepted records are the data rows in your file that meet the validation step, and are ready to be created in the System."
    And I should see the text "Rejected Records: 0"
    And I should see the text "Rejected records are the ones that could not be created due to a data error."
    And I should not see the text "Please select View Errors to view the"
    And I should not see the text "records that could not be uploaded."
    And I should see a "Create School Records" button
    And I should see a "Back to Re-upload" button
    And I should not see the link "View Errors"
    When I press "Create School Records"
    And I follow meta refresh
    And I should see the heading "Manage Schools"
    And I should see the link "First Uploaded School"
    And I should see the link "Second Uploaded School"
    And I should not see the link "Add School(s) - upload csv file"

  Scenario: Upload and create schools
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title                       | uid         |
      | District 851 - Three column | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_valid_extra_column.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "File Import Status"
    And I should not see the text "Some records could not be uploaded. Please select one of the actions below."
    And I should see the text "Upload Schools File"
    And I should see the text "trt_upload_schools_valid_extra_column.csv"
    And I should see the text "Total records in file: 2"
    And I should see the text "Accepted Records: 2"
    And I should see the text "The Accepted records are the data rows in your file that meet the validation step, and are ready to be created in the System."
    And I should see the text "Rejected Records: 0"
    And I should see the text "Rejected records are the ones that could not be created due to a data error."
    And I should not see the text "Please select View Errors to view the"
    And I should not see the text "records that could not be uploaded."
    And I should see a "Create School Records" button
    And I should see a "Back to Re-upload" button
    And I should not see the link "View Errors"
    When I press "Create School Records"
    And I follow meta refresh
    And I should see the heading "Manage Schools"
    And I should see the link "First Uploaded School"
    And I should see the link "Second Uploaded School"
    And I should not see the link "Add School(s) - upload csv file"

  Scenario: Upload schools, upload another clears form
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title        | uid         |
      | District 851 | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_valid.csv" to "edit-file-upload"
    And I press "edit-upload"
    And I follow meta refresh
    When I press "Create School Records"
    And I follow meta refresh
    And "District" nodes:
      | title          | uid         |
      | District 851-2 | @currentuid |
    And I visit the last node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    # PRC-854 changed this text // #PRC-1851 Updates this text
    And I should see the text "Use this upload tool to bulk enter school information."
    And I should see the text "To upload multiple schools, use Excel or another spreadsheet program and create a two-column .csv file. There must be two columns: the first for the school name and the second for the school contact email address; the first row of the spreadsheet is treated as a header and its contents are ignored. Make sure to save the file as a .csv. Lastly, upload your schools using this interface."
    And I should see the text "You also might be able to have your school’s student information system generate the .csv file for you and save even more time."
    And I should see the text "Note: School names must be unique within a district, and once submitted, a school with data cannot be deleted. The data will be checked by the TRT before being accepted."
