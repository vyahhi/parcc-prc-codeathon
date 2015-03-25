@api @trt @structured @school @upload
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

  Scenario Outline: Upload file - File is not .csv
    Given I am logged in as a user with the "District Admin" role
    And I have no "State" nodes
    And I have no "District" nodes
    And I have no "School" nodes
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title        | uid         | field_ref_trt_state  |
      | District 851 | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/FireflyIpsum.docx" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "The specified file FireflyIpsum.docx could not be uploaded. Only files with the following extensions are allowed: csv."
  Examples:
    | user_state    | member_state   |
    | West Colorado | South Illinois |

  Scenario Outline: Upload file - Invalid email addresses
    Given I am logged in as a user with the "District Admin" role
    And I have no "State" nodes
    And I have no "District" nodes
    And I have no "School" nodes
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title        | uid         | field_ref_trt_state  |
      | District 851 | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_invalid_emails.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "File Import Status"
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
  Examples:
    | user_state    | member_state   |
    | West Colorado | South Illinois |

  Scenario Outline: Upload file - Empty file
    Given I am logged in as a user with the "District Admin" role
    And I have no "State" nodes
    And I have no "District" nodes
    And I have no "School" nodes
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title        | uid         | field_ref_trt_state  |
      | District 851 | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_invalid_empty.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "File Import Status"
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
  Examples:
    | user_state    | member_state   |
    | West Colorado | South Illinois |

  Scenario Outline: Upload file - One column
    Given I am logged in as a user with the "District Admin" role
    And I have no "State" nodes
    And I have no "District" nodes
    And I have no "School" nodes
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title        | uid         | field_ref_trt_state  |
      | District 851 | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_invalid_columns.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "File Import Status"
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
  Examples:
    | user_state    | member_state   |
    | West Colorado | South Illinois |

  Scenario Outline: Upload file - Missing schools
    Given I am logged in as a user with the "District Admin" role
    And I have no "State" nodes
    And I have no "District" nodes
    And I have no "School" nodes
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title        | uid         | field_ref_trt_state  |
      | District 851 | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_missing_school.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "File Import Status"
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
  Examples:
    | user_state    | member_state   |
    | West Colorado | South Illinois |

  Scenario Outline: File is required
    Given I am logged in as a user with the "District Admin" role
    And I have no "State" nodes
    And I have no "District" nodes
    And I have no "School" nodes
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title        | uid         | field_ref_trt_state  |
      | District 851 | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I press "edit-upload"
    Then I should see the error message containing "File Name field is required."
  Examples:
    | user_state    | member_state   |
    | West Colorado | South Illinois |

  Scenario Outline: Upload file - Some pass, some fail
    Given I am logged in as a user with the "District Admin" role
    And I have no "State" nodes
    And I have no "District" nodes
    And I have no "School" nodes
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title        | uid         | field_ref_trt_state  |
      | District 851 | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And I attach the file "testfiles/trt_upload_schools_mixed_valid_invalid.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "File Import Status"
    And I should see the text "Some records could not be uploaded. Please select one of the actions below."
    And I should see the text "Upload Schools File"
    And I should see the text "trt_upload_schools_mixed_valid_invalid.csv"
    And I should see the text "Total records in file: 5"
    And I should see the text "Accepted Records: 3"
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
    And I should see the text "First Failed School"
    And I should see the text "Contact E-mail: Required"
    And I should see the text "School Name: Required"
    And I should see the text "second@example.com"
  Examples:
    | user_state    | member_state   |
    | West Colorado | South Illinois |

  Scenario Outline: Upload file - Existing schools - case insensitive
    Given I am logged in as a user with the "District Admin" role
    And I have no "State" nodes
    And I have no "District" nodes
    And I have no "School" nodes
    And "User States" terms:
      | name         |
      | <user_state> |
    And "Member State" terms:
      | name           | field_state_code |
      | <member_state> | SOIL1            |
    And "State" nodes:
      | title          | field_user_state | field_member_state | uid         |
      | <member_state> | <user_state>     | <member_state>     | @currentuid |
    And "District" nodes:
      | title        | uid         | field_ref_trt_state  |
      | District 851 | @currentuid | @nid[<member_state>] |
    And I visit the last node created
    And I click "Manage Schools"
    When I click "Add School(s) - upload csv file"
    And "School" nodes:
      | title                 | field_ref_district |
      | first uploaded school | @nid[District 851] |
    And I attach the file "testfiles/trt_upload_schools_valid.csv" to "edit-file-upload"
    And I press "edit-upload"
    Then I should see the text "Processing Upload"
    And I follow meta refresh
    Then I should see the heading "File Import Status"
    And I should see the text "Some records could not be uploaded. Please select one of the actions below."
    And I should see the text "Upload Schools File"
    And I should see the text "trt_upload_schools_valid.csv"
    And I should see the text "Total records in file: 2"
    And I should see the text "Accepted Records: 1"
    And I should see the text "The Accepted records are the data rows in your file that meet the validation step, and are ready to be created in the System."
    And I should see the text "Rejected Records: 1"
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
    And I should see the text "example@example.com"
    And I should not see the text "Contact E-mail: Required"
    And I should see the text "School Name: First Uploaded School already exists"
    And I should not see the text "Second Uploaded School"
    And I should not see the text "example2@example.com"
  Examples:
    | user_state    | member_state   |
    | West Colorado | South Illinois |
