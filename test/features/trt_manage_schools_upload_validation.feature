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

  Scenario: Upload file
    Given I am logged in as a user with the "District Admin" role
    And "District" nodes:
      | title        | uid         |
      | District 851 | @currentuid |
    And I visit the first node created
    And I click "Manage Schools"
    And I click "Add School(s) - upload csv file"