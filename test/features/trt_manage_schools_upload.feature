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
    And I should see the text "Overview / instructional copy. Consider explaining that for each school, there must be two columns: one for school name and one for school contact email address; the first row is treated as a header and its contents are ignored; and that file must be .csv."
    And I should see the text "Note that user will be allowed only one upload per school."
    And I should see the text "\* indicates required field"
    And I should see the text "File Name \*"
    And I should see the text "File must have .csv extension and have two columns in this order: School Name, School Contact's Email Address. The first row is treated as a header and its contents are ignored, and the naming of the columns is ignored."
    And I should see an "Upload" button