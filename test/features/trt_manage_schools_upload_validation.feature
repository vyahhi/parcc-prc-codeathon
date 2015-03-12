@api @trt @structured @school
Feature: PRC-852 Manage Schools - Upload School - File Validation
  As a District Admin, I want the system to check if the .csv file I selected to upload is valid so that I can correctly add schools to my district.
  Acceptance Criteria
  Given that I am logged in as a District Admin
  And I am on my Upload Schools page
  And I have selected a file
  When I click the Upload button the following file validation occurs:
  File must be .csv
  File must have two columns
  For each row both columns must be complete or both must be blank
  The email address in the second column must be valid
  File must have at least one valid row

  Scenario: Upload file - File is not .csv
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title        | uid         |
      | District 851 | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/FireflyIpsum.docx" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "The specified file FireflyIpsum.docx could not be uploaded. Only files with the following extensions are allowed: csv."

  Scenario: Upload file - Invalid email addresses
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title        | uid         |
      | District 851 | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_invalid_emails.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "Checking Data Status"
    And I should see the text "Some records could not be uploaded. Please select one of the actions below."
    And I should see the text "Upload Schools File"
    And I should see the text "trt_upload_schools_invalid_emails.csv"
    And I should see the text "Total records in file: 2"
    And I should see the text "Accepted Records: 0"
    And I should see the text "The Accepted records are the data rows in your file that meet the validation step, and are ready to be created in the System."
    And I should see the text "Rejected Records: 2"
    And I should see the text "Rejected records are the ones that could not be created due to a data error."
    And I should see the text "Please select View Errors to view the"
    And I should see the text "records that could not be uploaded."
    And I should not see the button "Create School Records"
    And I should see a "Back to Re-upload" button
    And I click "View Errors"
    Then I should see the heading "School File Rejected Records"
    And I should see the text "There are"
    And I should see the text "rejected records. Please correct the data and re-upload later."
    And I should see the text "School Name"
    And I should see the text "School Contact E-mail"
    And I should see the text "Error Message"
    And I should see the text "First Uploaded School"
    And I should see the text "exampleexample.com"
    And I should see the text "Contact E-mail: Invalid"
    And I should see the text "Second Uploaded School"
    And I should see the text "example2@examplecom"

  Scenario: Upload file - Empty file
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title        | uid         |
      | District 851 | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_invalid_empty.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "Checking Data Status"
    And I should see the text "Upload Schools File"
    And I should see the text "trt_upload_schools_invalid_empty.csv"
    And I should see the text "Total records in file: 0"
    And I should see the text "Accepted Records: 0"
    And I should see the text "The Accepted records are the data rows in your file that meet the validation step, and are ready to be created in the System."
    And I should see the text "Rejected Records: 0"
    And I should see the text "Rejected records are the ones that could not be created due to a data error."
    And I should not see the text "Please select View Errors to view the"
    And I should not see the text "records that could not be uploaded."
    And I should not see the button "Create School Records"
    And I should not see the button "View Errors"
    And I should see a "Back to Re-upload" button

  Scenario: Upload file - One column
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title        | uid         |
      | District 851 | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_invalid_columns.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "Checking Data Status"
    And I should see the text "Some records could not be uploaded. Please select one of the actions below."
    And I should see the text "Upload Schools File"
    And I should see the text "trt_upload_schools_invalid_columns.csv"
    And I should see the text "Total records in file: 2"
    And I should see the text "Accepted Records: 0"
    And I should see the text "The Accepted records are the data rows in your file that meet the validation step, and are ready to be created in the System."
    And I should see the text "Rejected Records: 2"
    And I should see the text "Rejected records are the ones that could not be created due to a data error."
    And I should see the text "Please select View Errors to view the"
    And I should see the text "records that could not be uploaded."
    And I should not see the button "Create School Records"
    And I should see a "Back to Re-upload" button
    And I click "View Errors"
    Then I should see the heading "School File Rejected Records"
    And I should see the text "There are"
    And I should see the text "rejected records. Please correct the data and re-upload later."
    And I should see the text "School Name"
    And I should see the text "School Contact E-mail"
    And I should see the text "Error Message"
    And I should see the text "First Uploaded School"
    And I should not see the text "exampleexample.com"
    And I should see the text "Contact E-mail: Required"
    And I should see the text "Second Uploaded School"
    And I should not see the text "example2@examplecom"

  Scenario: Upload file - Missing schools
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title        | uid         |
      | District 851 | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_missing_school.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "Checking Data Status"
    And I should see the text "Some records could not be uploaded. Please select one of the actions below."
    And I should see the text "Upload Schools File"
    And I should see the text "trt_upload_schools_missing_school.csv"
    And I should see the text "Total records in file: 2"
    And I should see the text "Accepted Records: 0"
    And I should see the text "The Accepted records are the data rows in your file that meet the validation step, and are ready to be created in the System."
    And I should see the text "Rejected Records: 2"
    And I should see the text "Rejected records are the ones that could not be created due to a data error."
    And I should see the text "Please select View Errors to view the"
    And I should see the text "records that could not be uploaded."
    And I should not see the button "Create School Records"
    And I should see a "Back to Re-upload" button
    And I click "View Errors"
    Then I should see the heading "School File Rejected Records"
    And I should see the text "There are"
    And I should see the text "rejected records. Please correct the data and re-upload later."
    And I should see the text "School Name"
    And I should see the text "School Contact E-mail"
    And I should see the text "Error Message"
    And I should not see the text "First Uploaded School"
    And I should see the text "example@example.com"
    And I should not see the text "Contact E-mail: Required"
    And I should see the text "School Name: Required"
    And I should not see the text "Second Uploaded School"
    And I should see the text "example2@example.com"

  Scenario: File is required
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title        | uid         |
      | District 851 | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I press "edit-upload"
    Then I should see the error message containing "File Name field is required."
