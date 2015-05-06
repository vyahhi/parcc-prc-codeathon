@api @course
Feature: PRC-353 Admin: PD Course Reports
  As a Content Administrator (Curator), I want to see some basic reporting on the existing PD courses, so that I can monitor the utilization of the courses.
# AC1 Given that I'm a Content Administrator (Curator), a tab, Reporting, is displayed for all PD course pages.
# AC2 When I select the Reporting tab, a table shall be displayed that contains entries for each student enrollment
#  a Name is a sortable column and will contain the student's first and last name
#  b E-mail is a column that will contain the student's email address
#    - When the user clicks on an email address, the email address will load into a new message in the user's default mail client.
#  c Date Started is a sortable column and will display the local date and time of the current user's system time of the course enrollment.
#    - 12/31/2016 - 13:30
#  d Date Completed is a sortable (default) column and will display the local date and time of the current user's system time of the course completion. If the course is not completed, this cell will be left blank.
#    - 12/31/2016 - 13:30
#  e Status is a sortable column
#    - Status will display "Completed" if the student has completed the course.
#    - Status will display current module name if the student has not completed the course.

  Scenario: Course Report
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Module" node with the title "PD Module PRC-353 No1"
    And I am viewing my "PD Module" node with the title "PD Module PRC-353 No2"
    And I am viewing my "PD Module" node with the title "PD Module PRC-353 No3"
    And I am viewing my "PD Course" node with the title "PD Course PRC-353"
    And I click "Edit"
    And I fill in "Course Objectives" with "Nonsense"
    And I select the radio button "Public"
    And I check the box "Published"
    And I press "Save"

    And I follow "Course outline"

    And I select "Module" from "edit-more-object-type"
    And I press "Add object"
    And I click "Edit Settings"
    And I select "PD Module PRC-353 No1" from "Existing node"
    And I check the box "Use existing content's title"
    And I press "Update"

    And I select "Module" from "edit-more-object-type"
    And I press "Add object"
    And I follow "Edit Settings" number "1"
    And I select "PD Module PRC-353 No2" from "Existing node"
    And I check the box "Use existing content's title"
    And I press "Update"

    And I select "Module" from "edit-more-object-type"
    And I press "Add object"
    And I follow "Edit Settings" number "2"
    And I select "PD Module PRC-353 No3" from "Existing node"
    And I check the box "Use existing content's title"
    And I press "Update"

    Then I press "Save outline"

    # PRC-913 Course Reports tab rename to Reporting
    When I click "Reporting"
    Then I should see the text "Sorry, there is no course data to report on."

    Then I click "View"
    And I click "Take course"
    And I click "PD Module PRC-353 No1"
    Then I click "Professional Learning"
    And I click "PD Course PRC-353"
    When I click "Reporting"
    Then I should see the link "PD Course PRC-353"
    # Status shows the next module
    And I should see the text "PD Module PRC-353 No2"
    Then I should see the link "Name"
    And I should see the link "E-mail"
    And I should see the link "Date Started"
    And I should see the link "Date Completed"
    And I should see the link "Status"

    # PRC-914 Admin: PD Course Reports: Filtering- Invalid Input message is not complete
    Then I click "Reporting"
    And I fill in "edit-date-completed-min" with "1234"
    And I fill in "edit-date-completed-max" with "4321"
    When I press "Apply"
    Then I should see the text "Sorry, there is no course data to report on. Please check that both date fields are filled in with valid dates."

    # PRC-915 Admin: PD Course Reports: Course Object Reporting- Table Headers not as specified
    When I click "Course objects"
    And I follow "Overview" number "1"
    Then I should see the text "Name"
    Then I should see the text "Date Started"
    Then I should see the text "Date Completed"
    Then I should see the text "Grade"
