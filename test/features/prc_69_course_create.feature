@api
Feature: PRC-69 Admin: Create a Course
  As a Content Administrator,
  I want to define all courses for the PRC website,
  so that these courses will be available for users as needed.

  Acceptance Criteria:
  AC1 A new tab Course Management shall be added to the top navigation bar for the following roles:
  Content Administrator (Curator)
  PRC Admin
  Tested in prc_348_curator_view_courses.feature


  AC2 After selecting the Add course link, the following attributes will be collected in the Create Course page:
  Course Title: Required, String(255)
  Course Objectives: Required - Extended text.
  Tags: Optional, Comma separated strings (each: String(255) , followed by a description, such as:
  Enter a comma-separated list of words to describe your content.
  Grade Level: Optional, Drop-down menu.
  Grade Drop-down options to be added. (Same as Digital Library options)
  Subject: Optional, Drop-down menu.
  Subject Drop-down options to be added. (Same as Digital Library options)
  Course Length: Optional, Drop-downs.
  Options for the first drop down include the following: 1-24
  Options for the second drop down include the following: Hour, Day, Week, Month,Year
  Course Audience/Permissions: Required, Radio button selection.
  Public
  PARCC Members ONLY
  Public: No restrictions; any anonymous user or logged in user with any role, including Educator role will see the content.
  PARCC Members ONLY: PRC Admin, Content Contributor, Content Administrator (Curator), PARCC-Member Educators shall see the content (not accessible to anonymous users or logged in users with Educator role).
  Published: Checkbox, Published checked by default. Allows a course to be available and on display.
  AC3. Validations: If a required field is NOT entered after the Save button is selected, The system will display the following feedback on the top of the form:
  <Field Name> field is required.
  AC4. The Save button will allow the user to save the entries for all the course information.
  AC5. Once Saved, the system will
  provide confirmation that the course information has been successfully saved.
  store the timestamp and the user ID of the user who saved it.
  6. If the user navigates away without saving changes, the system prompts the user to confirm by displaying the following:
  Stay On Page - this will keep the Admin UI on the "Create Course" page.
  Leave Page - this will direct the Admin UI to navigate away from the page.

  Scenario: AC2 Create course fields
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am on "admin-course"
    When I click "Add course"
    Then I should see the heading "Create Course" in the "content" region
