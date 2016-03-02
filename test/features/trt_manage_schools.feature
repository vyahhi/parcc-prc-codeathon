@api @trt @structured @school
Feature: PRC-828 Manage Schools
  As a District Admin,
  I want to ask schools in my district to run the readiness checks
  so I can understand if the schools are ready to run the PARCC assessment.

  Scenario: No schools added
    Given I am logged in as a user with the "District Admin" role
    And I have no "School" nodes
    And I have no "District" nodes
    And "District" nodes:
      | title              | uid         |
      | PRC-828 @timestamp | @currentuid |
    And I visit the last node created
    And I click "Manage Schools"
    Then I should see the heading "Manage Schools"
    And I should see the text "To add a single school, click \“Add School-form\”"
    And I should see the text "If you have a large number of schools, to save some time, you can upload your entire district roster via a .csv file. To add a school\(s\) using a .csv file, click \“Add School\(s\)-upload csv file\”"
    And I should see the text "Note: School names cannot be replicated and once submitted a school with check data cannot be deleted from this TRT during the data year."
    And I should see the text "Schools in the district can be edited from the table that appears on this page by clicking on the school name. Additionally, readiness check requests can be sent from this table."
    And I should see the text "Sort and filter schools based on checks run or not as well as school name. You can also request checks be run from all or select schools."
    And I should see the link "Add School - form"
    And I should see the link "Add School(s) - upload csv file"
    And I should see the text "No schools have been added to your district. Please click one of the Add School links above to add schools."

  Scenario: District has schools
    Given I am logged in as a user with the "District Admin" role
    And I have no "School" nodes
    And I have no "District" nodes
    And "District" nodes:
      | title              | uid         |
      | PRC-828 @timestamp | @currentuid |
    And "School" nodes:
      | title                 | field_ref_district       | field_contact_email     |
      | School 828 @timestamp | @nid[PRC-828 @timestamp] | e@timestamp@example.com |
    And I visit the first node created
    And I click "Manage Schools"
    Then I should see the heading "Manage Schools"
    And I should see the text "To add a single school, click \“Add School-form\”"
    And I should see the text "If you have a large number of schools, to save some time, you can upload your entire district roster via a .csv file. To add a school\(s\) using a .csv file, click \“Add School\(s\)-upload csv file\”"
    And I should see the text "Note: School names cannot be replicated and once submitted a school with check data cannot be deleted from this TRT during the data year."
    And I should see the text "Schools in the district can be edited from the table that appears on this page by clicking on the school name. Additionally, readiness check requests can be sent from this table."
    And I should see the text "Sort and filter schools based on checks run or not as well as school name. You can also request checks be run from all or select schools."
    And I should see the link "Add School - form"
    And I should see the link "Add School(s) - upload csv file"
    And I should not see the text "No schools have been added to your district. Please click one of the Add School links above to add schools."
    And I should see the text "School 828 @timestamp"
    And I should see the text "e@timestamp@example.com"
    And I should see a "Request Readiness Checks" button

  @flag
  Scenario: District has an upload
    Given I am logged in as a user with the "District Admin" role
    And I have no "School" nodes
    And I have no "District" nodes
    And "District" nodes:
      | title              | uid         |
      | PRC-828 @timestamp | @currentuid |
    And "School" nodes:
      | title                 | field_ref_district       | field_contact_email     |
      | School 828 @timestamp | @nid[PRC-828 @timestamp] | e@timestamp@example.com |
    And I flag "PRC-828 @timestamp" with "File Uploaded"
    And I visit the first node created
    And I click "Manage Schools"
    And I should see the text "To add a single school, click \“Add School-form\”"
    And I should see the text "If you have a large number of schools, to save some time, you can upload your entire district roster via a .csv file. To add a school\(s\) using a .csv file, click \“Add School\(s\)-upload csv file\”"
    And I should see the text "Note: School names cannot be replicated and once submitted a school with check data cannot be deleted from this TRT during the data year."
    And I should see the text "Schools in the district can be edited from the table that appears on this page by clicking on the school name. Additionally, readiness check requests can be sent from this table."
    And I should see the text "Sort and filter schools based on checks run or not as well as school name. You can also request checks be run from all or select schools."
    And I should see the link "Add School - form"
    And I should not see the link "Add School(s) - upload csv file"
    And I should not see the text "No schools have been added to your district. Please click one of the Add School links above to add schools."
    And I should see the text "School 828 @timestamp"
    And I should see the text "e@timestamp@example.com"
    And I should see a "Request Readiness Checks" button
