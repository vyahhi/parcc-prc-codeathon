@api
Feature: PRC-346 Admin: Course Audience
  As a Content Admin,
  I want to manage the course enrollment process for anonymous and authenticated users,
  so that I can assign public or private rosters to any available courses as needed.

  # AC1 The Content Admin will select Course Management from the top navigation bar.
  # Tested in PRC-348

  # AC2 The Content Admin will selecting the Course ID link within the course table, and will be directed to the Edit Course Page.
  # Tested in PRC-349

  Scenario Outline: Course Audience does not exist for other node types
    Given I am logged in as a user with the "PRC Admin" role
    And I am viewing my "<type>" node with the title "PRC-346 <type>"
    And I click "Edit"
    Then I should not see the link "Course Audience"
  Examples:
    | type                    |
    | PD Module               |
    | Digital Library Content |
    | Favorites List          |
    | Quiz                    |

  Scenario: AC3 From the Edit Course page, the Content Admin will select the Course Audience tab, and will be directed to the "Course Audience" page.
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Module" node with the title "PD Module PRC-346 AC3"
    And I am viewing my "PD Course" node with the title "PD Course PRC-346 AC3"
    And I click "Edit"
    Then I click "Course Audience"
    # AC4 A course label and the following options will display on the "Course Audience" page:
    # Course Audience label
    Then I should see the heading "'PD Course PRC-346 AC3' Course Audience"
#    And I should see the text "Course Audience/Permissions"
#    And I should see the radio button "Public"
#    And I should see the radio button "PARCC members ONLY"
#  AC5 If the PARCC Members Only option is selected, the following options will display:
#  All PARCC Members This option is selected by default when the PARCC Members Only radio button is selected.
#  Select By State
#  Select By Rostering
#  AC6 The following will display when the Select By State option is selected:
#  A "Select By State" drop down menu
#  The State field is required if the "Select By State" option is selected.
#  AC7 The State drop down menu will contain the following options in alphabetical order:
#  Select a state (default- keeps (or resets value to: NULL)
#  Arkansas
#  Colorado
#  District of Columbia
#  Illinois
#  Louisiana
#  Maryland
#  Massachusetts
#  Mississippi
#  New Jersey
#  New Mexico
#  New York
#  Ohio
#  Rhode Island
#  AC8 Validations: The following validations will occur when the Select By State option is selected:
#  If the Admin does not select a State from the drop down , the system will provide feedback on the top of the form:
#  <State> is required
#  AC9 If Select By Rostering is selected, a text box for entering emails will appear:
#  The PRC Admin will only be able to view the E-mail text box in order to enter a list of emails for all individuals associated with the public roster.
#  The following instructions will display for the E-mail text box:
#  Input all email addresses of those you want to roster.
#  AC10 Validations: The following validations will occur when the Select By Rostering option is selected:
#  E-mail address must be in email format (built-in functionality on validating @ and dot within the string). If the user does not provide a valid format for all emails listed, the system provides feedback on the top of the form:
#  <wrong email format displayed here> is not a valid e-mail address
#  The E-mail address must be an existing E-mail associated with current users. If the entered E-mail does not exists, the system provides feedback on the top of the form:
#  <wrong email format displayed here> does not exist
#  AC11 A Save Audience button is provided at the end. Once selected, the system will:
#  Validate that all required fields contain valid values. If not, the system displays a red frame around the section or field text box, and provides feedback on the top of the form:
#  <Missing required> field is required.
